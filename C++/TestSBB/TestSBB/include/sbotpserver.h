#ifndef __INC_SBOTPSERVER
#define __INC_SBOTPSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbxmlcore.h"
#include "sbconstants.h"
#include "sbotpcommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OTPUser 	"OTPUser"
#define SB_HOTPUser 	"HOTPUser"
#define SB_TOTPUser 	"TOTPUser"

typedef TElClassHandle TElOTPUserHandle;

typedef TElOTPUserHandle ElOTPUserHandle;

typedef TElClassHandle TElHOTPUserHandle;

typedef TElHOTPUserHandle ElHOTPUserHandle;

typedef TElClassHandle TElTOTPUserHandle;

typedef TElTOTPUserHandle ElTOTPUserHandle;

typedef TElClassHandle TElOTPUserFactoryHandle;

typedef TElOTPUserFactoryHandle ElOTPUserFactoryHandle;

typedef TElClassHandle TElOTPUserStorageHandle;

typedef TElOTPUserStorageHandle ElOTPUserStorageHandle;

typedef TElClassHandle TElOTPServerHandle;

typedef TElOTPServerHandle ElOTPServerHandle;

typedef TElClassHandle TElHOTPServerHandle;

typedef TElHOTPServerHandle ElHOTPServerHandle;

typedef TElClassHandle TElTOTPServerHandle;

typedef TElTOTPServerHandle ElTOTPServerHandle;

typedef TElClassHandle TElOTPUserClassHandle;

#ifdef SB_USE_CLASS_TELOTPUSER
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_Assign(TElOTPUserHandle _Handle, TElOTPUserHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_Clear(TElOTPUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_Clone(TElOTPUserHandle _Handle, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_CreateInstance(TElOTPUserHandle _Handle, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_LoadFromStream(TElOTPUserHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_SaveToStream(TElOTPUserHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_get_UserID(TElOTPUserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_set_UserID(TElOTPUserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_get_KeySecret(TElOTPUserHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_set_KeySecret(TElOTPUserHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_get_PasswordLen(TElOTPUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_set_PasswordLen(TElOTPUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUser_Create(TElOTPUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPUSER */

#ifdef SB_USE_CLASS_TELHOTPUSER
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_Assign(TElHOTPUserHandle _Handle, TElOTPUserHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_Clear(TElHOTPUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_CreateInstance(TElHOTPUserHandle _Handle, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_get_Counter(TElHOTPUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_set_Counter(TElHOTPUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPUser_Create(TElHOTPUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELHOTPUSER */

#ifdef SB_USE_CLASS_TELTOTPUSER
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_Assign(TElTOTPUserHandle _Handle, TElOTPUserHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_Clear(TElTOTPUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_CreateInstance(TElTOTPUserHandle _Handle, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_get_HashAlgorithm(TElTOTPUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_set_HashAlgorithm(TElTOTPUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_get_TimeInterval(TElTOTPUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_set_TimeInterval(TElTOTPUserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPUser_Create(TElTOTPUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELTOTPUSER */

#ifdef SB_USE_CLASS_TELOTPUSERFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserFactory_RegisterClass(TElOTPUserFactoryHandle _Handle, TElOTPUserClassHandle cls);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserFactory_CreateInstance(TElOTPUserFactoryHandle _Handle, const char * pcName, int32_t szName, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserFactory_get_RegisteredClasses(TElOTPUserFactoryHandle _Handle, int32_t Index, TElOTPUserClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserFactory_get_RegisteredClassCount(TElOTPUserFactoryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserFactory_Create(TElOTPUserFactoryHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPUSERFACTORY */

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_Add(TElOTPUserStorageHandle _Handle, TElOTPUserHandle User);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_Remove(TElOTPUserStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_Clear(TElOTPUserStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_IndexOf(TElOTPUserStorageHandle _Handle, TElOTPUserHandle User, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_SaveToStream(TElOTPUserStorageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_LoadFromStream(TElOTPUserStorageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_get_Users(TElOTPUserStorageHandle _Handle, int32_t Index, TElOTPUserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_get_Count(TElOTPUserStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPUserStorage_Create(TComponentHandle AOwner, TElOTPUserStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

#ifdef SB_USE_CLASS_TELOTPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElOTPServer_get_Delta(TElOTPServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPServer_set_Delta(TElOTPServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOTPServer_get_OTPUserStorage(TElOTPServerHandle _Handle, TElOTPUserStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOTPServer_set_OTPUserStorage(TElOTPServerHandle _Handle, TElOTPUserStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOTPServer_Create(TElOTPUserStorageHandle OTPUserStorage, TElOTPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTPSERVER */

#ifdef SB_USE_CLASS_TELHOTPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElHOTPServer_IsPasswordValid(TElHOTPServerHandle _Handle, const char * pcUserId, int32_t szUserId, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPServer_IsPasswordValid_1(TElHOTPServerHandle _Handle, TElHOTPUserHandle User, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHOTPServer_Create(TElOTPUserStorageHandle OTPUserStorage, TElHOTPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELHOTPSERVER */

#ifdef SB_USE_CLASS_TELTOTPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElTOTPServer_IsPasswordValid(TElTOTPServerHandle _Handle, const char * pcUserId, int32_t szUserId, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPServer_IsPasswordValid_1(TElTOTPServerHandle _Handle, const char * pcUserId, int32_t szUserId, const char * pcPassword, int32_t szPassword, int64_t Time, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPServer_IsPasswordValid_2(TElTOTPServerHandle _Handle, TElTOTPUserHandle User, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPServer_IsPasswordValid_3(TElTOTPServerHandle _Handle, TElTOTPUserHandle User, const char * pcPassword, int32_t szPassword, int64_t Time, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTOTPServer_Create(TElOTPUserStorageHandle OTPUserStorage, TElTOTPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELTOTPSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOTPUser;
typedef TElOTPUser ElOTPUser;
class TElHOTPUser;
typedef TElHOTPUser ElHOTPUser;
class TElTOTPUser;
typedef TElTOTPUser ElTOTPUser;
class TElOTPUserFactory;
typedef TElOTPUserFactory ElOTPUserFactory;
class TElOTPUserStorage;
typedef TElOTPUserStorage ElOTPUserStorage;
class TElOTPServer;
typedef TElOTPServer ElOTPServer;
class TElHOTPServer;
typedef TElHOTPServer ElHOTPServer;
class TElTOTPServer;
typedef TElTOTPServer ElTOTPServer;

#ifdef SB_USE_CLASS_TELOTPUSER
class TElOTPUser: public TObject
{
	private:
		SB_DISABLE_COPY(TElOTPUser)
	public:
		virtual void Assign(TElOTPUser &Source);

		virtual void Assign(TElOTPUser *Source);

		virtual void Clear();

		virtual TElOTPUserHandle Clone();

		virtual TElOTPUserHandle CreateInstance();

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		static TClassHandle ClassType();

		virtual void get_UserID(std::string &OutResult);

		virtual void set_UserID(const std::string &Value);

		virtual void get_KeySecret(std::vector<uint8_t> &OutResult);

		virtual void set_KeySecret(const std::vector<uint8_t> &Value);

		virtual int32_t get_PasswordLen();

		virtual void set_PasswordLen(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PasswordLen, set_PasswordLen, TElOTPUser, PasswordLen);

		TElOTPUser(TElOTPUserHandle handle, TElOwnHandle ownHandle);

		TElOTPUser();

};
#endif /* SB_USE_CLASS_TELOTPUSER */

#ifdef SB_USE_CLASS_TELHOTPUSER
class TElHOTPUser: public TElOTPUser
{
	private:
		SB_DISABLE_COPY(TElHOTPUser)
	public:
		virtual void Assign(TElOTPUser &Source);

		virtual void Assign(TElOTPUser *Source);

		virtual void Clear();

		virtual TElOTPUserHandle CreateInstance();

		static TClassHandle ClassType();

		virtual int32_t get_Counter();

		virtual void set_Counter(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Counter, set_Counter, TElHOTPUser, Counter);

		TElHOTPUser(TElHOTPUserHandle handle, TElOwnHandle ownHandle);

		TElHOTPUser();

};
#endif /* SB_USE_CLASS_TELHOTPUSER */

#ifdef SB_USE_CLASS_TELTOTPUSER
class TElTOTPUser: public TElOTPUser
{
	private:
		SB_DISABLE_COPY(TElTOTPUser)
	public:
		virtual void Assign(TElOTPUser &Source);

		virtual void Assign(TElOTPUser *Source);

		virtual void Clear();

		virtual TElOTPUserHandle CreateInstance();

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElTOTPUser, HashAlgorithm);

		virtual int32_t get_TimeInterval();

		virtual void set_TimeInterval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimeInterval, set_TimeInterval, TElTOTPUser, TimeInterval);

		TElTOTPUser(TElTOTPUserHandle handle, TElOwnHandle ownHandle);

		TElTOTPUser();

};
#endif /* SB_USE_CLASS_TELTOTPUSER */

#ifdef SB_USE_CLASS_TELOTPUSERFACTORY
class TElOTPUserFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElOTPUserFactory)
	public:
		void RegisterClass(TElOTPUserClassHandle cls);

#ifdef SB_USE_CLASS_TELOTPUSER
		TElOTPUserHandle CreateInstance(const std::string &Name);
#endif /* SB_USE_CLASS_TELOTPUSER */

		virtual TElOTPUserClassHandle get_RegisteredClasses(int32_t Index);

		virtual int32_t get_RegisteredClassCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RegisteredClassCount, TElOTPUserFactory, RegisteredClassCount);

		TElOTPUserFactory(TElOTPUserFactoryHandle handle, TElOwnHandle ownHandle);

		TElOTPUserFactory();

};
#endif /* SB_USE_CLASS_TELOTPUSERFACTORY */

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
class TElOTPUserStorage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElOTPUserStorage)
#ifdef SB_USE_CLASS_TELOTPUSER
		TElOTPUser* _Inst_Users;
#endif /* SB_USE_CLASS_TELOTPUSER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELOTPUSER
		void Add(TElOTPUser &User);

		void Add(TElOTPUser *User);
#endif /* SB_USE_CLASS_TELOTPUSER */

		void Remove(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TELOTPUSER
		int32_t IndexOf(TElOTPUser &User);

		int32_t IndexOf(TElOTPUser *User);
#endif /* SB_USE_CLASS_TELOTPUSER */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELOTPUSER
		virtual TElOTPUser* get_Users(int32_t Index);
#endif /* SB_USE_CLASS_TELOTPUSER */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElOTPUserStorage, Count);

		TElOTPUserStorage(TElOTPUserStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElOTPUserStorage(TComponent &AOwner);

		explicit TElOTPUserStorage(TComponent *AOwner);

		virtual ~TElOTPUserStorage();

};
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

#ifdef SB_USE_CLASS_TELOTPSERVER
class TElOTPServer: public TElOTPClass
{
	private:
		SB_DISABLE_COPY(TElOTPServer)
#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
		TElOTPUserStorage* _Inst_OTPUserStorage;
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

		void initInstances();

	public:
		virtual int32_t get_Delta();

		virtual void set_Delta(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Delta, set_Delta, TElOTPServer, Delta);

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
		virtual TElOTPUserStorage* get_OTPUserStorage();

		virtual void set_OTPUserStorage(TElOTPUserStorage &Value);

		virtual void set_OTPUserStorage(TElOTPUserStorage *Value);

		SB_DECLARE_PROPERTY(TElOTPUserStorage*, get_OTPUserStorage, set_OTPUserStorage, TElOTPServer, OTPUserStorage);
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

		TElOTPServer(TElOTPServerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
		explicit TElOTPServer(TElOTPUserStorage &OTPUserStorage);

		explicit TElOTPServer(TElOTPUserStorage *OTPUserStorage);
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

		virtual ~TElOTPServer();

};
#endif /* SB_USE_CLASS_TELOTPSERVER */

#ifdef SB_USE_CLASS_TELHOTPSERVER
class TElHOTPServer: public TElOTPServer
{
	private:
		SB_DISABLE_COPY(TElHOTPServer)
	public:
		bool IsPasswordValid(const std::string &UserId, const std::string &Password);

#ifdef SB_USE_CLASS_TELHOTPUSER
		bool IsPasswordValid(TElHOTPUser &User, const std::string &Password);

		bool IsPasswordValid(TElHOTPUser *User, const std::string &Password);
#endif /* SB_USE_CLASS_TELHOTPUSER */

		TElHOTPServer(TElHOTPServerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
		explicit TElHOTPServer(TElOTPUserStorage &OTPUserStorage);

		explicit TElHOTPServer(TElOTPUserStorage *OTPUserStorage);
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

};
#endif /* SB_USE_CLASS_TELHOTPSERVER */

#ifdef SB_USE_CLASS_TELTOTPSERVER
class TElTOTPServer: public TElOTPServer
{
	private:
		SB_DISABLE_COPY(TElTOTPServer)
	public:
		bool IsPasswordValid(const std::string &UserId, const std::string &Password);

		bool IsPasswordValid(const std::string &UserId, const std::string &Password, int64_t Time);

#ifdef SB_USE_CLASS_TELTOTPUSER
		bool IsPasswordValid(TElTOTPUser &User, const std::string &Password);

		bool IsPasswordValid(TElTOTPUser *User, const std::string &Password);
#endif /* SB_USE_CLASS_TELTOTPUSER */

#ifdef SB_USE_CLASS_TELTOTPUSER
		bool IsPasswordValid(TElTOTPUser &User, const std::string &Password, int64_t Time);

		bool IsPasswordValid(TElTOTPUser *User, const std::string &Password, int64_t Time);
#endif /* SB_USE_CLASS_TELTOTPUSER */

		TElTOTPServer(TElTOTPServerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELOTPUSERSTORAGE
		explicit TElTOTPServer(TElOTPUserStorage &OTPUserStorage);

		explicit TElTOTPServer(TElOTPUserStorage *OTPUserStorage);
#endif /* SB_USE_CLASS_TELOTPUSERSTORAGE */

};
#endif /* SB_USE_CLASS_TELTOTPSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOTPSERVER */

