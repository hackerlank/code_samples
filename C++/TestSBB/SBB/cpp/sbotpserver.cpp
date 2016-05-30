#include "sbotpserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOTPUSER

SB_INLINE void TElOTPUser::Assign(TElOTPUser &Source)
{
	SBCheckError(TElOTPUser_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElOTPUser::Assign(TElOTPUser *Source)
{
	SBCheckError(TElOTPUser_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElOTPUser::Clear()
{
	SBCheckError(TElOTPUser_Clear(_Handle));
}

SB_INLINE TElOTPUserHandle TElOTPUser::Clone()
{
	TElOTPUserHandle OutResult;
	SBCheckError(TElOTPUser_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TElOTPUserHandle TElOTPUser::CreateInstance()
{
	TElOTPUserHandle OutResult;
	SBCheckError(TElOTPUser_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOTPUser::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOTPUser_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOTPUser::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOTPUser_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOTPUser::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOTPUser_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOTPUser::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOTPUser_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TClassHandle TElOTPUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElOTPUser_ClassType(&OutResult));
	return OutResult;
}

void TElOTPUser::get_UserID(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOTPUser_get_UserID(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2041745588, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOTPUser::set_UserID(const std::string &Value)
{
	SBCheckError(TElOTPUser_set_UserID(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElOTPUser::get_KeySecret(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElOTPUser_get_KeySecret(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(9665658, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOTPUser::set_KeySecret(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElOTPUser_set_KeySecret(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElOTPUser::get_PasswordLen()
{
	int32_t OutResult;
	SBCheckError(TElOTPUser_get_PasswordLen(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOTPUser::set_PasswordLen(int32_t Value)
{
	SBCheckError(TElOTPUser_set_PasswordLen(_Handle, Value));
}

TElOTPUser::TElOTPUser(TElOTPUserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOTPUser::TElOTPUser() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOTPUser_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOTPUSER */

#ifdef SB_USE_CLASS_TELHOTPUSER

SB_INLINE void TElHOTPUser::Assign(TElOTPUser &Source)
{
	SBCheckError(TElHOTPUser_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElHOTPUser::Assign(TElOTPUser *Source)
{
	SBCheckError(TElHOTPUser_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElHOTPUser::Clear()
{
	SBCheckError(TElHOTPUser_Clear(_Handle));
}

SB_INLINE TElOTPUserHandle TElHOTPUser::CreateInstance()
{
	TElOTPUserHandle OutResult;
	SBCheckError(TElHOTPUser_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElHOTPUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElHOTPUser_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElHOTPUser::get_Counter()
{
	int32_t OutResult;
	SBCheckError(TElHOTPUser_get_Counter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElHOTPUser::set_Counter(int32_t Value)
{
	SBCheckError(TElHOTPUser_set_Counter(_Handle, Value));
}

TElHOTPUser::TElHOTPUser(TElHOTPUserHandle handle, TElOwnHandle ownHandle) : TElOTPUser(handle, ownHandle)
{
}

TElHOTPUser::TElHOTPUser() : TElOTPUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHOTPUser_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELHOTPUSER */

#ifdef SB_USE_CLASS_TELTOTPUSER

SB_INLINE void TElTOTPUser::Assign(TElOTPUser &Source)
{
	SBCheckError(TElTOTPUser_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElTOTPUser::Assign(TElOTPUser *Source)
{
	SBCheckError(TElTOTPUser_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElTOTPUser::Clear()
{
	SBCheckError(TElTOTPUser_Clear(_Handle));
}

SB_INLINE TElOTPUserHandle TElTOTPUser::CreateInstance()
{
	TElOTPUserHandle OutResult;
	SBCheckError(TElTOTPUser_CreateInstance(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TElTOTPUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElTOTPUser_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElTOTPUser::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElTOTPUser_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPUser::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElTOTPUser_set_HashAlgorithm(_Handle, Value));
}

SB_INLINE int32_t TElTOTPUser::get_TimeInterval()
{
	int32_t OutResult;
	SBCheckError(TElTOTPUser_get_TimeInterval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTOTPUser::set_TimeInterval(int32_t Value)
{
	SBCheckError(TElTOTPUser_set_TimeInterval(_Handle, Value));
}

TElTOTPUser::TElTOTPUser(TElTOTPUserHandle handle, TElOwnHandle ownHandle) : TElOTPUser(handle, ownHandle)
{
}

TElTOTPUser::TElTOTPUser() : TElOTPUser(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTOTPUser_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELTOTPUSER */

#ifdef SB_USE_CLASS_TELOTPUSERFACTORY

SB_INLINE void TElOTPUserFactory::RegisterClass(TElOTPUserClassHandle cls)
{
	SBCheckError(TElOTPUserFactory_RegisterClass(_Handle, cls));
}

#ifdef SB_USE_CLASS_TELOTPUSER
SB_INLINE TElOTPUserHandle TElOTPUserFactory::CreateInstance(const std::string &Name)
{
	TElOTPUserHandle OutResult;
	SBCheckError(TElOTPUserFactory_CreateInstance(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOTPUSER */

SB_INLINE TElOTPUserClassHandle TElOTPUserFactory::get_RegisteredClasses(int32_t Index)
{
	TElOTPUserClassHandle OutResult;
	SBCheckError(TElOTPUserFactory_get_RegisteredClasses(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOTPUserFactory::get_RegisteredClassCount()
{
	int32_t OutResult;
	SBCheckError(TElOTPUserFactory_get_RegisteredClassCount(_Handle, &OutResult));
	return OutResult;
}

TElOTPUserFactory::TElOTPUserFactory(TElOTPUserFactoryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElOTPUserFactory::TElOTPUserFactory() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElOTPUserFactory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELOTPUSERFACTORY */

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE

#ifdef SB_USE_CLASS_TELOTPUSER
SB_INLINE void TElOTPUserStorage::Add(TElOTPUser &User)
{
	SBCheckError(TElOTPUserStorage_Add(_Handle, User.getHandle()));
}

SB_INLINE void TElOTPUserStorage::Add(TElOTPUser *User)
{
	SBCheckError(TElOTPUserStorage_Add(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOTPUSER */

SB_INLINE void TElOTPUserStorage::Remove(int32_t Index)
{
	SBCheckError(TElOTPUserStorage_Remove(_Handle, Index));
}

SB_INLINE void TElOTPUserStorage::Clear()
{
	SBCheckError(TElOTPUserStorage_Clear(_Handle));
}

#ifdef SB_USE_CLASS_TELOTPUSER
SB_INLINE int32_t TElOTPUserStorage::IndexOf(TElOTPUser &User)
{
	int32_t OutResult;
	SBCheckError(TElOTPUserStorage_IndexOf(_Handle, User.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOTPUserStorage::IndexOf(TElOTPUser *User)
{
	int32_t OutResult;
	SBCheckError(TElOTPUserStorage_IndexOf(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOTPUSER */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOTPUserStorage::SaveToStream(TStream &Stream)
{
	SBCheckError(TElOTPUserStorage_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOTPUserStorage::SaveToStream(TStream *Stream)
{
	SBCheckError(TElOTPUserStorage_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOTPUserStorage::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElOTPUserStorage_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOTPUserStorage::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElOTPUserStorage_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOTPUSER
TElOTPUser* TElOTPUserStorage::get_Users(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOTPUserStorage_get_Users(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Users)
		this->_Inst_Users = new TElOTPUser(hOutResult, ohFalse);
	else
		this->_Inst_Users->updateHandle(hOutResult);
	return this->_Inst_Users;
}
#endif /* SB_USE_CLASS_TELOTPUSER */

SB_INLINE int32_t TElOTPUserStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOTPUserStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElOTPUserStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELOTPUSER
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELOTPUSER */
}

TElOTPUserStorage::TElOTPUserStorage(TElOTPUserStorageHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElOTPUserStorage::TElOTPUserStorage(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOTPUserStorage_Create(AOwner.getHandle(), &_Handle));
}

TElOTPUserStorage::TElOTPUserStorage(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOTPUserStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElOTPUserStorage::~TElOTPUserStorage()
{
#ifdef SB_USE_CLASS_TELOTPUSER
	delete this->_Inst_Users;
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELOTPUSER */
}
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

#ifdef SB_USE_CLASS_TELOTPSERVER

SB_INLINE int32_t TElOTPServer::get_Delta()
{
	int32_t OutResult;
	SBCheckError(TElOTPServer_get_Delta(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOTPServer::set_Delta(int32_t Value)
{
	SBCheckError(TElOTPServer_set_Delta(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
TElOTPUserStorage* TElOTPServer::get_OTPUserStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOTPServer_get_OTPUserStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_OTPUserStorage)
		this->_Inst_OTPUserStorage = new TElOTPUserStorage(hOutResult, ohFalse);
	else
		this->_Inst_OTPUserStorage->updateHandle(hOutResult);
	return this->_Inst_OTPUserStorage;
}

SB_INLINE void TElOTPServer::set_OTPUserStorage(TElOTPUserStorage &Value)
{
	SBCheckError(TElOTPServer_set_OTPUserStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElOTPServer::set_OTPUserStorage(TElOTPUserStorage *Value)
{
	SBCheckError(TElOTPServer_set_OTPUserStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

void TElOTPServer::initInstances()
{
#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
	this->_Inst_OTPUserStorage = NULL;
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */
}

TElOTPServer::TElOTPServer(TElOTPServerHandle handle, TElOwnHandle ownHandle) : TElOTPClass(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
TElOTPServer::TElOTPServer(TElOTPUserStorage &OTPUserStorage) : TElOTPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOTPServer_Create(OTPUserStorage.getHandle(), &_Handle));
}

TElOTPServer::TElOTPServer(TElOTPUserStorage *OTPUserStorage) : TElOTPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOTPServer_Create((OTPUserStorage != NULL) ? OTPUserStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

TElOTPServer::~TElOTPServer()
{
#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
	delete this->_Inst_OTPUserStorage;
	this->_Inst_OTPUserStorage = NULL;
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */
}
#endif /* SB_USE_CLASS_TELOTPSERVER */

#ifdef SB_USE_CLASS_TELHOTPSERVER

bool TElHOTPServer::IsPasswordValid(const std::string &UserId, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHOTPServer_IsPasswordValid(_Handle, UserId.data(), (int32_t)UserId.length(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELHOTPUSER
bool TElHOTPServer::IsPasswordValid(TElHOTPUser &User, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHOTPServer_IsPasswordValid_1(_Handle, User.getHandle(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElHOTPServer::IsPasswordValid(TElHOTPUser *User, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElHOTPServer_IsPasswordValid_1(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELHOTPUSER */

TElHOTPServer::TElHOTPServer(TElHOTPServerHandle handle, TElOwnHandle ownHandle) : TElOTPServer(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
TElHOTPServer::TElHOTPServer(TElOTPUserStorage &OTPUserStorage) : TElOTPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHOTPServer_Create(OTPUserStorage.getHandle(), &_Handle));
}

TElHOTPServer::TElHOTPServer(TElOTPUserStorage *OTPUserStorage) : TElOTPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElHOTPServer_Create((OTPUserStorage != NULL) ? OTPUserStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

#endif /* SB_USE_CLASS_TELHOTPSERVER */

#ifdef SB_USE_CLASS_TELTOTPSERVER

bool TElTOTPServer::IsPasswordValid(const std::string &UserId, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid(_Handle, UserId.data(), (int32_t)UserId.length(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTOTPServer::IsPasswordValid(const std::string &UserId, const std::string &Password, int64_t Time)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid_1(_Handle, UserId.data(), (int32_t)UserId.length(), Password.data(), (int32_t)Password.length(), Time, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELTOTPUSER
bool TElTOTPServer::IsPasswordValid(TElTOTPUser &User, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid_2(_Handle, User.getHandle(), Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTOTPServer::IsPasswordValid(TElTOTPUser *User, const std::string &Password)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid_2(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELTOTPUSER */

#ifdef SB_USE_CLASS_TELTOTPUSER
bool TElTOTPServer::IsPasswordValid(TElTOTPUser &User, const std::string &Password, int64_t Time)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid_3(_Handle, User.getHandle(), Password.data(), (int32_t)Password.length(), Time, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElTOTPServer::IsPasswordValid(TElTOTPUser *User, const std::string &Password, int64_t Time)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTOTPServer_IsPasswordValid_3(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE, Password.data(), (int32_t)Password.length(), Time, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELTOTPUSER */

TElTOTPServer::TElTOTPServer(TElTOTPServerHandle handle, TElOwnHandle ownHandle) : TElOTPServer(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
TElTOTPServer::TElTOTPServer(TElOTPUserStorage &OTPUserStorage) : TElOTPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTOTPServer_Create(OTPUserStorage.getHandle(), &_Handle));
}

TElTOTPServer::TElTOTPServer(TElOTPUserStorage *OTPUserStorage) : TElOTPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTOTPServer_Create((OTPUserStorage != NULL) ? OTPUserStorage->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

#endif /* SB_USE_CLASS_TELTOTPSERVER */

};	/* namespace SecureBlackbox */

