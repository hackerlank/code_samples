#ifndef __INC_SBCUSTOMFSADAPTER
#define __INC_SBCUSTOMFSADAPTER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstringlist.h"
#include "sbconstants.h"
#include "sbsharedresource.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_fileOpenRead 	1
#define SB_fileOpenWrite 	2
#define SB_fileOpenCreate 	4
#define SB_fileOpenAppend 	8
#define SB_fileOpenTruncate 	16
#define SB_fileAttributeReadonly 	1
#define SB_fileAttributeHidden 	2
#define SB_fileAttributeSystem 	4
#define SB_fileAttributeArchive 	32
#define SB_fileAttributeSymlink 	64
#define SB_entryInfoAttributes 	1
#define SB_entryInfoModifyDate 	2
#define SB_entryInfoCreateDate 	4
#define SB_entryInfoAccessDate 	8
#define SB_entryInfoAllFileDate 	14
#define SB_ERROR_FACILITY_VFS 	102400
#define SB_ERROR_VFS_ERROR_FLAG 	1024
#define SB_ERROR_VFS_CUSTOM_ERROR_FLAG 	2048
#define SB_VFS_ERROR_NO_ERROR 	0
#define SB_VFS_ERROR_FILE_NOT_FOUND 	103426
#define SB_VFS_ERROR_PATH_NOT_FOUND 	103427
#define SB_VFS_ERROR_ACCESS_DENIED 	103429
#define SB_VFS_ERROR_WRITE_PROTECT 	103443
#define SB_VFS_ERROR_ERROR_CRC 	103447
#define SB_VFS_ERROR_NOT_SUPPORTED 	103474
#define SB_VFS_ERROR_INVALID_PARAMETER 	103511
#define SB_VFS_ERROR_NO_MEDIA 	104536
#define SB_VFS_UNSPECIFIED_ERROR 	104448
#define SB_SFileSystemOperationFailed 	"File system operation failed with error. Requested path is "

typedef TObjectHandle TElVFSHandleHandle;

typedef TElClassHandle TElVFSEntryInformationHandle;

typedef TElClassHandle TElVFSEntryInformationListHandle;

typedef TElClassHandle TElCustomFileSystemAdapterHandle;

typedef uint8_t TSBFileShareModeRaw;

typedef enum
{
	ssmExclusive = 0,
	ssmDenyRead = 1,
	ssmDenyWrite = 2,
	ssmNone = 3
} TSBFileShareMode;

typedef uint8_t TSBFileTypeRaw;

typedef enum
{
	sftUnknown = 0,
	sftFile = 1,
	sftDirectory = 2,
	sftSymLink = 3
} TSBFileType;

typedef uint8_t TSBFileSeekOriginRaw;

typedef enum
{
	sfsoBegin = 0,
	sfsoCurrent = 1,
	sfsoEnd = 2
} TSBFileSeekOrigin;

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_Assign(TElVFSEntryInformationHandle _Handle, TElVFSEntryInformationHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_AccessMode(TElVFSEntryInformationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_AccessMode(TElVFSEntryInformationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_Attributes(TElVFSEntryInformationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_Attributes(TElVFSEntryInformationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_DateAccessed(TElVFSEntryInformationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_DateAccessed(TElVFSEntryInformationHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_DateCreated(TElVFSEntryInformationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_DateCreated(TElVFSEntryInformationHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_DateModified(TElVFSEntryInformationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_DateModified(TElVFSEntryInformationHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_FileType(TElVFSEntryInformationHandle _Handle, TSBFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_FileType(TElVFSEntryInformationHandle _Handle, TSBFileTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_Name(TElVFSEntryInformationHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_Name(TElVFSEntryInformationHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_FullName(TElVFSEntryInformationHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_FullName(TElVFSEntryInformationHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_OwnerName(TElVFSEntryInformationHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_OwnerName(TElVFSEntryInformationHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_get_Size(TElVFSEntryInformationHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_set_Size(TElVFSEntryInformationHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformation_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformationList_Add(TElVFSEntryInformationListHandle _Handle, TElVFSEntryInformationHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformationList_Remove(TElVFSEntryInformationListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformationList_get_Count(TElVFSEntryInformationListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformationList_get_Item(TElVFSEntryInformationListHandle _Handle, int32_t index, TElVFSEntryInformationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElVFSEntryInformationList_Create(TElVFSEntryInformationListHandle * OutResult);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_Clone(TElCustomFileSystemAdapterHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_NameMatchesMask(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_GetFileStream(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, uint32_t OpenMode, TSBFileShareModeRaw ShareMode, TStreamHandle * FileStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileOpen(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, uint32_t OpenMode, TSBFileShareModeRaw ShareMode, TObjectHandle * FileHandle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileClose(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_CloseAllFiles(TElCustomFileSystemAdapterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileExists(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_DirectoryExists(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileRead(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileWrite(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileGetSize(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileSetSize(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t NewSize);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileGetPosition(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileSeek(TElCustomFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t Position, TSBFileSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileGetTimes(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int64_t * CreationTime, int64_t * ModificationTime, int64_t * LastAccessTime, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileSetTimes(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int64_t CreationTime, int64_t ModificationTime, int64_t LastAccessTime, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileDelete(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileMove(TElCustomFileSystemAdapterHandle _Handle, const char * pcFromName, int32_t szFromName, const char * pcToName, int32_t szToName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_FileCopy(TElCustomFileSystemAdapterHandle _Handle, const char * pcFromName, int32_t szFromName, const char * pcToName, int32_t szToName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_WriteFileTag(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, const char * pcTagValue, int32_t szTagValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_ReadFileTag(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, char * pcTagValue, int32_t * szTagValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_DeleteFileTag(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_DirectoryMake(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_DirectoryRemove(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_EnumDirectoryEntries(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t Recursive, TElVFSEntryInformationListHandle * EntryInfos, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_GetEntryInformation(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, TElVFSEntryInformationHandle EntryInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_SetEntryInformation(TElCustomFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, TElVFSEntryInformationHandle EntryInfo, int32_t InfoFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_IsAccessible(TElCustomFileSystemAdapterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_get_CaseSensitive(TElCustomFileSystemAdapterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_set_CaseSensitive(TElCustomFileSystemAdapterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_get_BasePath(TElCustomFileSystemAdapterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_set_BasePath(TElCustomFileSystemAdapterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_get_PathSeparator(TElCustomFileSystemAdapterHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_set_PathSeparator(TElCustomFileSystemAdapterHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_get_PathSeparator2(TElCustomFileSystemAdapterHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_set_PathSeparator2(TElCustomFileSystemAdapterHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomFileSystemAdapter_Create(TComponentHandle AOwner, TElCustomFileSystemAdapterHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TObject TElVFSHandle;
class TElVFSEntryInformation;
class TElVFSEntryInformationList;
class TElCustomFileSystemAdapter;

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
class TElVFSEntryInformation: public TObject
{
	private:
		SB_DISABLE_COPY(TElVFSEntryInformation)
	public:
		void Assign(TElVFSEntryInformation &Source);

		void Assign(TElVFSEntryInformation *Source);

		virtual int32_t get_AccessMode();

		virtual void set_AccessMode(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AccessMode, set_AccessMode, TElVFSEntryInformation, AccessMode);

		virtual int32_t get_Attributes();

		virtual void set_Attributes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Attributes, set_Attributes, TElVFSEntryInformation, Attributes);

		virtual int64_t get_DateAccessed();

		virtual void set_DateAccessed(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DateAccessed, set_DateAccessed, TElVFSEntryInformation, DateAccessed);

		virtual int64_t get_DateCreated();

		virtual void set_DateCreated(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DateCreated, set_DateCreated, TElVFSEntryInformation, DateCreated);

		virtual int64_t get_DateModified();

		virtual void set_DateModified(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_DateModified, set_DateModified, TElVFSEntryInformation, DateModified);

		virtual TSBFileType get_FileType();

		virtual void set_FileType(TSBFileType Value);

		SB_DECLARE_PROPERTY(TSBFileType, get_FileType, set_FileType, TElVFSEntryInformation, FileType);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual void get_FullName(std::string &OutResult);

		virtual void set_FullName(const std::string &Value);

		virtual void get_OwnerName(std::string &OutResult);

		virtual void set_OwnerName(const std::string &Value);

		virtual int64_t get_Size();

		virtual void set_Size(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size, set_Size, TElVFSEntryInformation, Size);

		TElVFSEntryInformation(TElVFSEntryInformationHandle handle, TElOwnHandle ownHandle);

		TElVFSEntryInformation();

};
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
class TElVFSEntryInformationList: public TObject
{
	private:
		SB_DISABLE_COPY(TElVFSEntryInformationList)
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		TElVFSEntryInformation* _Inst_Item;
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		void Add(TElVFSEntryInformation &Item);

		void Add(TElVFSEntryInformation *Item);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

		void Remove(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElVFSEntryInformationList, Count);

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		virtual TElVFSEntryInformation* get_Item(int32_t index);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

		TElVFSEntryInformationList(TElVFSEntryInformationListHandle handle, TElOwnHandle ownHandle);

		TElVFSEntryInformationList();

		virtual ~TElVFSEntryInformationList();

};
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
class TElCustomFileSystemAdapter: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomFileSystemAdapter)
	public:
		virtual TElCustomFileSystemAdapterHandle Clone();

		virtual bool NameMatchesMask(const std::string &Path, const std::string &Mask);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t GetFileStream(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TStream &FileStream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t FileOpen(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TObject &FileHandle);

		void FileClose(TObject &FileHandle);

		void FileClose(TObject *FileHandle);

		void CloseAllFiles();

		virtual bool FileExists(const std::string &Path);

		virtual bool DirectoryExists(const std::string &Path);

		virtual int32_t FileRead(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileRead(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileWrite(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileWrite(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int64_t FileGetSize(TObject &FileHandle);

		virtual int64_t FileGetSize(TObject *FileHandle);

		virtual void FileSetSize(TObject &FileHandle, int64_t NewSize);

		virtual void FileSetSize(TObject *FileHandle, int64_t NewSize);

		virtual int64_t FileGetPosition(TObject &FileHandle);

		virtual int64_t FileGetPosition(TObject *FileHandle);

		virtual int64_t FileSeek(TObject &FileHandle, int64_t Position, TSBFileSeekOrigin Origin);

		virtual int64_t FileSeek(TObject *FileHandle, int64_t Position, TSBFileSeekOrigin Origin);

		virtual int32_t FileGetTimes(const std::string &Path, int64_t &CreationTime, int64_t &ModificationTime, int64_t &LastAccessTime);

		virtual int32_t FileSetTimes(const std::string &Path, int64_t CreationTime, int64_t ModificationTime, int64_t LastAccessTime);

		virtual int32_t FileDelete(const std::string &Path);

		virtual int32_t FileMove(const std::string &FromName, const std::string &ToName);

		virtual int32_t FileCopy(const std::string &FromName, const std::string &ToName);

		virtual int32_t WriteFileTag(const std::string &Path, const std::string &TagName, const std::string &TagValue);

		virtual int32_t ReadFileTag(const std::string &Path, const std::string &TagName, std::string &TagValue);

		virtual int32_t DeleteFileTag(const std::string &Path, const std::string &TagName);

		virtual int32_t DirectoryMake(const std::string &Path);

		virtual int32_t DirectoryRemove(const std::string &Path);

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST
		virtual int32_t EnumDirectoryEntries(const std::string &Path, const std::string &Mask, bool Recursive, TElVFSEntryInformationList &EntryInfos);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATIONLIST */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		virtual int32_t GetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo);

		virtual int32_t GetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		virtual int32_t SetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo, int32_t InfoFlags);

		virtual int32_t SetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo, int32_t InfoFlags);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

		virtual bool IsAccessible();

		virtual bool get_CaseSensitive();

		virtual void set_CaseSensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CaseSensitive, set_CaseSensitive, TElCustomFileSystemAdapter, CaseSensitive);

		virtual void get_BasePath(std::string &OutResult);

		virtual void set_BasePath(const std::string &Value);

		virtual char get_PathSeparator();

		virtual void set_PathSeparator(char Value);

		SB_DECLARE_PROPERTY(char, get_PathSeparator, set_PathSeparator, TElCustomFileSystemAdapter, PathSeparator);

		virtual char get_PathSeparator2();

		virtual void set_PathSeparator2(char Value);

		SB_DECLARE_PROPERTY(char, get_PathSeparator2, set_PathSeparator2, TElCustomFileSystemAdapter, PathSeparator2);

		TElCustomFileSystemAdapter(TElCustomFileSystemAdapterHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomFileSystemAdapter(TComponent &AOwner);

		explicit TElCustomFileSystemAdapter(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER

void RaiseVFSAdapterError(int32_t ErrorCode, const std::string &FileName);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
void RaiseVFSAdapterErrorEx(TElCustomFileSystemAdapter &Adapter, int32_t ErrorCode, const std::string &FileName);
void RaiseVFSAdapterErrorEx(TElCustomFileSystemAdapter *Adapter, int32_t ErrorCode, const std::string &FileName);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#endif /* SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER
SB_IMPORT uint32_t SB_APIENTRY SBCustomFSAdapter_RaiseVFSAdapterError(int32_t ErrorCode, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY SBCustomFSAdapter_RaiseVFSAdapterErrorEx(TElCustomFileSystemAdapterHandle Adapter, int32_t ErrorCode, const char * pcFileName, int32_t szFileName);
#endif /* SB_USE_GLOBAL_PROCS_CUSTOMFSADAPTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCUSTOMFSADAPTER */

