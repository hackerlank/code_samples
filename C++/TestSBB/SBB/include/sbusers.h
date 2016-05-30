#ifndef __INC_SBUSERS
#define __INC_SBUSERS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsharedresource.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbmd.h"
#include "sbrandom.h"
#include "sbsha.h"
#include "sbrc4.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SUserExists 	"User already exists"
#define SB_SCannotCreateNewUser 	"Can not create new user. Use OnCreateNewUser to create proper user class"
#define SB_SCanNotLoadUsers 	"Can not load users data. FilePassword not set"
#define SB_SInvalidUserFile 	"Invalid users file"
#define SB_SCanNotSaveUsers 	"Can not save users data. FilePassword not set"
#define SB_rsCannotCreateFile 	"Cannot create file \"%s\""
#define SB_rsCannotOpenFile 	"Cannot open file \"%s\""
#define SB_SCannotEditUser 	"Lock user with TElUsers.LockUser before editing"

typedef TElClassHandle TElUsersHandle;

typedef TElClassHandle TElCustomUserHandle;

typedef TElClassHandle TElCustomUserClassHandle;

typedef void (SB_CALLBACK *TSBOnCreateNewUserEvent)(void * _ObjectData, TElCustomUserHandle * OutResult);

#ifdef SB_USE_CLASS_TELUSERS
SB_IMPORT uint32_t SB_APIENTRY TElUsers_AddUser(TElUsersHandle _Handle, TElCustomUserHandle User);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Clear(TElUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_DeleteUser(TElUsersHandle _Handle, const char * pcUserName, int32_t szUserName);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_FindUser(TElUsersHandle _Handle, const char * pcUserName, int32_t szUserName, TElCustomUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_IsValidPassword(TElUsersHandle _Handle, const char * pcAUserName, int32_t szAUserName, const char * pcAPassword, int32_t szAPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Lock(TElUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Unlock(TElUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_LockUser(TElUsersHandle _Handle, TElCustomUserHandle User);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_UnlockUser(TElUsersHandle _Handle, TElCustomUserHandle User);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Load(TElUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Load_1(TElUsersHandle _Handle, const char * pcAFileName, int32_t szAFileName, const char * pcAPassword, int32_t szAPassword);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Save(TElUsersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Save_1(TElUsersHandle _Handle, const char * pcAFileName, int32_t szAFileName, const char * pcAPassword, int32_t szAPassword);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_LoadFromStream(TElUsersHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_LoadFromStream_1(TElUsersHandle _Handle, TStreamHandle Stream, const char * pcAPassword, int32_t szAPassword);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_SaveToStream(TElUsersHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_SaveToStream_1(TElUsersHandle _Handle, TStreamHandle Stream, const char * pcAPassword, int32_t szAPassword);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_get_Users(TElUsersHandle _Handle, int32_t Index, TElCustomUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_get_Count(TElUsersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_get_FileName(TElUsersHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_set_FileName(TElUsersHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_get_FilePassword(TElUsersHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_set_FilePassword(TElUsersHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_get_OnCreateNewUser(TElUsersHandle _Handle, TSBOnCreateNewUserEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_set_OnCreateNewUser(TElUsersHandle _Handle, TSBOnCreateNewUserEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElUsers_Create(TComponentHandle AOwner, TElUsersHandle * OutResult);
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_GetData(TElCustomUserHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_SetData(TElCustomUserHandle _Handle, const uint8_t pValue[], int32_t szValue, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_IsValidPassword(TElCustomUserHandle _Handle, const char * pcAPassword, int32_t szAPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_get_Name(TElCustomUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_get_Password(TElCustomUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_set_Password(TElCustomUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomUser_Create(const char * pcUserName, int32_t szUserName, TElCustomUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElUsers;
class TElCustomUser;

#ifdef SB_USE_CLASS_TELUSERS
class TElUsers: public TComponent
{
	private:
		SB_DISABLE_COPY(TElUsers)
#ifdef SB_USE_CLASS_TELCUSTOMUSER
		TElCustomUser* _Inst_Users;
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMUSER
		void AddUser(TElCustomUser &User);

		void AddUser(TElCustomUser *User);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

		void Clear();

		void DeleteUser(const std::string &UserName);

#ifdef SB_USE_CLASS_TELCUSTOMUSER
		TElCustomUserHandle FindUser(const std::string &UserName);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

		bool IsValidPassword(const std::string &AUserName, const std::string &APassword);

		void Lock();

		void Unlock();

#ifdef SB_USE_CLASS_TELCUSTOMUSER
		void LockUser(TElCustomUser &User);

		void LockUser(TElCustomUser *User);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
		void UnlockUser(TElCustomUser &User);

		void UnlockUser(TElCustomUser *User);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

		void Load();

		void Load(const std::string &AFileName, const std::string &APassword);

		void Save();

		void Save(const std::string &AFileName, const std::string &APassword);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream, const std::string &APassword);

		void LoadFromStream(TStream *Stream, const std::string &APassword);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream, const std::string &APassword);

		void SaveToStream(TStream *Stream, const std::string &APassword);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
		virtual TElCustomUser* get_Users(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElUsers, Count);

		virtual void get_FileName(std::string &OutResult);

		virtual void set_FileName(const std::string &Value);

		virtual void get_FilePassword(std::string &OutResult);

		virtual void set_FilePassword(const std::string &Value);

		virtual void get_OnCreateNewUser(TSBOnCreateNewUserEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateNewUser(TSBOnCreateNewUserEvent pMethodValue, void * pDataValue);

		TElUsers(TElUsersHandle handle, TElOwnHandle ownHandle);

		explicit TElUsers(TComponent &AOwner);

		explicit TElUsers(TComponent *AOwner);

		virtual ~TElUsers();

};
#endif /* SB_USE_CLASS_TELUSERS */

#ifdef SB_USE_CLASS_TELCUSTOMUSER
class TElCustomUser: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomUser)
	public:
		virtual void GetData(std::vector<uint8_t> &Buffer, int32_t &Size);

		virtual void SetData(const std::vector<uint8_t> &Value, int32_t Size);

		bool IsValidPassword(const std::string &APassword);

		static TClassHandle ClassType();

		virtual void get_Name(std::string &OutResult);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		TElCustomUser(TElCustomUserHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomUser(const std::string &UserName);

};
#endif /* SB_USE_CLASS_TELCUSTOMUSER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBUSERS */

