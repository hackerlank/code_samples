#include "sbusers.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELUSERS

#ifdef SB_USE_CLASS_TELCUSTOMUSER
SB_INLINE void TElUsers::AddUser(TElCustomUser &User)
{
	SBCheckError(TElUsers_AddUser(_Handle, User.getHandle()));
}

SB_INLINE void TElUsers::AddUser(TElCustomUser *User)
{
	SBCheckError(TElUsers_AddUser(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

SB_INLINE void TElUsers::Clear()
{
	SBCheckError(TElUsers_Clear(_Handle));
}

SB_INLINE void TElUsers::DeleteUser(const std::string &UserName)
{
	SBCheckError(TElUsers_DeleteUser(_Handle, UserName.data(), (int32_t)UserName.length()));
}

#ifdef SB_USE_CLASS_TELCUSTOMUSER
SB_INLINE TElCustomUserHandle TElUsers::FindUser(const std::string &UserName)
{
	TElCustomUserHandle OutResult;
	SBCheckError(TElUsers_FindUser(_Handle, UserName.data(), (int32_t)UserName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

bool TElUsers::IsValidPassword(const std::string &AUserName, const std::string &APassword)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElUsers_IsValidPassword(_Handle, AUserName.data(), (int32_t)AUserName.length(), APassword.data(), (int32_t)APassword.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElUsers::Lock()
{
	SBCheckError(TElUsers_Lock(_Handle));
}

SB_INLINE void TElUsers::Unlock()
{
	SBCheckError(TElUsers_Unlock(_Handle));
}

#ifdef SB_USE_CLASS_TELCUSTOMUSER
SB_INLINE void TElUsers::LockUser(TElCustomUser &User)
{
	SBCheckError(TElUsers_LockUser(_Handle, User.getHandle()));
}

SB_INLINE void TElUsers::LockUser(TElCustomUser *User)
{
	SBCheckError(TElUsers_LockUser(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
SB_INLINE void TElUsers::UnlockUser(TElCustomUser &User)
{
	SBCheckError(TElUsers_UnlockUser(_Handle, User.getHandle()));
}

SB_INLINE void TElUsers::UnlockUser(TElCustomUser *User)
{
	SBCheckError(TElUsers_UnlockUser(_Handle, (User != NULL) ? User->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

SB_INLINE void TElUsers::Load()
{
	SBCheckError(TElUsers_Load(_Handle));
}

SB_INLINE void TElUsers::Load(const std::string &AFileName, const std::string &APassword)
{
	SBCheckError(TElUsers_Load_1(_Handle, AFileName.data(), (int32_t)AFileName.length(), APassword.data(), (int32_t)APassword.length()));
}

SB_INLINE void TElUsers::Save()
{
	SBCheckError(TElUsers_Save(_Handle));
}

SB_INLINE void TElUsers::Save(const std::string &AFileName, const std::string &APassword)
{
	SBCheckError(TElUsers_Save_1(_Handle, AFileName.data(), (int32_t)AFileName.length(), APassword.data(), (int32_t)APassword.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElUsers::LoadFromStream(TStream &Stream)
{
	SBCheckError(TElUsers_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElUsers::LoadFromStream(TStream *Stream)
{
	SBCheckError(TElUsers_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElUsers::LoadFromStream(TStream &Stream, const std::string &APassword)
{
	SBCheckError(TElUsers_LoadFromStream_1(_Handle, Stream.getHandle(), APassword.data(), (int32_t)APassword.length()));
}

SB_INLINE void TElUsers::LoadFromStream(TStream *Stream, const std::string &APassword)
{
	SBCheckError(TElUsers_LoadFromStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, APassword.data(), (int32_t)APassword.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElUsers::SaveToStream(TStream &Stream)
{
	SBCheckError(TElUsers_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElUsers::SaveToStream(TStream *Stream)
{
	SBCheckError(TElUsers_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElUsers::SaveToStream(TStream &Stream, const std::string &APassword)
{
	SBCheckError(TElUsers_SaveToStream_1(_Handle, Stream.getHandle(), APassword.data(), (int32_t)APassword.length()));
}

SB_INLINE void TElUsers::SaveToStream(TStream *Stream, const std::string &APassword)
{
	SBCheckError(TElUsers_SaveToStream_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, APassword.data(), (int32_t)APassword.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
TElCustomUser* TElUsers::get_Users(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElUsers_get_Users(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Users)
		this->_Inst_Users = new TElCustomUser(hOutResult, ohFalse);
	else
		this->_Inst_Users->updateHandle(hOutResult);
	return this->_Inst_Users;
}
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

SB_INLINE int32_t TElUsers::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElUsers_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElUsers::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUsers_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1584925678, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUsers::set_FileName(const std::string &Value)
{
	SBCheckError(TElUsers_set_FileName(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElUsers::get_FilePassword(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUsers_get_FilePassword(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1070182089, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElUsers::set_FilePassword(const std::string &Value)
{
	SBCheckError(TElUsers_set_FilePassword(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElUsers::get_OnCreateNewUser(TSBOnCreateNewUserEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElUsers_get_OnCreateNewUser(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElUsers::set_OnCreateNewUser(TSBOnCreateNewUserEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElUsers_set_OnCreateNewUser(_Handle, pMethodValue, pDataValue));
}

void TElUsers::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMUSER
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMUSER */
}

TElUsers::TElUsers(TElUsersHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
	initInstances();
}

TElUsers::TElUsers(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElUsers_Create(AOwner.getHandle(), &_Handle));
}

TElUsers::TElUsers(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElUsers_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElUsers::~TElUsers()
{
#ifdef SB_USE_CLASS_TELCUSTOMUSER
	delete this->_Inst_Users;
	this->_Inst_Users = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMUSER */
}
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMUSER

void TElCustomUser::GetData(std::vector<uint8_t> &Buffer, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = TElCustomUser_GetData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Size);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-2135880145, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE void TElCustomUser::SetData(const std::vector<uint8_t> &Value, int32_t Size)
{
	SBCheckError(TElCustomUser_SetData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Size));
}

bool TElCustomUser::IsValidPassword(const std::string &APassword)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomUser_IsValidPassword(_Handle, APassword.data(), (int32_t)APassword.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElCustomUser::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElCustomUser_ClassType(&OutResult));
	return OutResult;
}

void TElCustomUser::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomUser_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(192092321, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElCustomUser::get_Password(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElCustomUser_get_Password(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(702216136, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomUser::set_Password(const std::string &Value)
{
	SBCheckError(TElCustomUser_set_Password(_Handle, Value.data(), (int32_t)Value.length()));
}

TElCustomUser::TElCustomUser(TElCustomUserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElCustomUser::TElCustomUser(const std::string &UserName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElCustomUser_Create(UserName.data(), (int32_t)UserName.length(), &_Handle));
}

#endif /* SB_USE_CLASS_TELCUSTOMUSER */

};	/* namespace SecureBlackbox */

