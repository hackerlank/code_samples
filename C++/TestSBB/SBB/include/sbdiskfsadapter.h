#ifndef __INC_SBDISKFSADAPTER
#define __INC_SBDISKFSADAPTER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbconstants.h"
#include "sbstringlist.h"
#include "sbcustomfsadapter.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDiskFileSystemAdapterHandle;

typedef void (SB_CALLBACK *TElVFSWriteFileTagEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, const char * pcTagValue, int32_t szTagValue, int32_t * ResultCode);

typedef void (SB_CALLBACK *TElVFSReadFileTagEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, char * pcTagValue, int32_t * szTagValue, int32_t * ResultCode);

typedef void (SB_CALLBACK *TElVFSDeleteFileTagEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, int32_t * ResultCode);

#ifdef SB_USE_CLASS_TELDISKFILESYSTEMADAPTER
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_AdjustPath(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_Clone(TElDiskFileSystemAdapterHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_GetFileStream(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, uint32_t OpenMode, TSBFileShareModeRaw ShareMode, TStreamHandle * FileStream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileExists(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_DirectoryExists(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileDelete(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileMove(TElDiskFileSystemAdapterHandle _Handle, const char * pcFromName, int32_t szFromName, const char * pcToName, int32_t szToName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_DirectoryRemove(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_DirectoryMake(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileRead(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileWrite(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileSeek(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t Position, TSBFileSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileSetSize(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t NewSize);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileGetSize(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileGetPosition(TElDiskFileSystemAdapterHandle _Handle, TObjectHandle FileHandle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_WriteFileTag(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, const char * pcTagValue, int32_t szTagValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_ReadFileTag(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, char * pcTagValue, int32_t * szTagValue, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_DeleteFileTag(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcTagName, int32_t szTagName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_FileGetTimes(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, int64_t * CreationTime, int64_t * ModificationTime, int64_t * LastAccessTime, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_GetEntryInformation(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, TElVFSEntryInformationHandle EntryInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_SetEntryInformation(TElDiskFileSystemAdapterHandle _Handle, const char * pcPath, int32_t szPath, TElVFSEntryInformationHandle EntryInfo, int32_t InfoFlags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_get_OnWriteFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSWriteFileTagEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_set_OnWriteFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSWriteFileTagEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_get_OnReadFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSReadFileTagEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_set_OnReadFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSReadFileTagEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_get_OnDeleteFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSDeleteFileTagEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_set_OnDeleteFileTag(TElDiskFileSystemAdapterHandle _Handle, TElVFSDeleteFileTagEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElDiskFileSystemAdapter_Create(TComponentHandle AOwner, TElCustomFileSystemAdapterHandle * OutResult);
#endif /* SB_USE_CLASS_TELDISKFILESYSTEMADAPTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDiskFileSystemAdapter;

#ifdef SB_USE_CLASS_TELDISKFILESYSTEMADAPTER
class TElDiskFileSystemAdapter: public TElCustomFileSystemAdapter
{
	private:
		SB_DISABLE_COPY(TElDiskFileSystemAdapter)
	public:
		virtual void AdjustPath(const std::string &Path, std::string &OutResult);

		virtual TElCustomFileSystemAdapterHandle Clone();

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t GetFileStream(const std::string &Path, uint32_t OpenMode, TSBFileShareMode ShareMode, TStream &FileStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool FileExists(const std::string &Path);

		virtual bool DirectoryExists(const std::string &Path);

		virtual int32_t FileDelete(const std::string &Path);

		virtual int32_t FileMove(const std::string &FromName, const std::string &ToName);

		virtual int32_t DirectoryRemove(const std::string &Path);

		virtual int32_t DirectoryMake(const std::string &Path);

		virtual int32_t FileRead(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileRead(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileWrite(TObject &FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int32_t FileWrite(TObject *FileHandle, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual int64_t FileSeek(TObject &FileHandle, int64_t Position, TSBFileSeekOrigin Origin);

		virtual int64_t FileSeek(TObject *FileHandle, int64_t Position, TSBFileSeekOrigin Origin);

		virtual void FileSetSize(TObject &FileHandle, int64_t NewSize);

		virtual void FileSetSize(TObject *FileHandle, int64_t NewSize);

		virtual int64_t FileGetSize(TObject &FileHandle);

		virtual int64_t FileGetSize(TObject *FileHandle);

		virtual int64_t FileGetPosition(TObject &FileHandle);

		virtual int64_t FileGetPosition(TObject *FileHandle);

		virtual int32_t WriteFileTag(const std::string &Path, const std::string &TagName, const std::string &TagValue);

		virtual int32_t ReadFileTag(const std::string &Path, const std::string &TagName, std::string &TagValue);

		virtual int32_t DeleteFileTag(const std::string &Path, const std::string &TagName);

		virtual int32_t FileGetTimes(const std::string &Path, int64_t &CreationTime, int64_t &ModificationTime, int64_t &LastAccessTime);

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		virtual int32_t GetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo);

		virtual int32_t GetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

#ifdef SB_USE_CLASS_TELVFSENTRYINFORMATION
		virtual int32_t SetEntryInformation(const std::string &Path, TElVFSEntryInformation &EntryInfo, int32_t InfoFlags);

		virtual int32_t SetEntryInformation(const std::string &Path, TElVFSEntryInformation *EntryInfo, int32_t InfoFlags);
#endif /* SB_USE_CLASS_TELVFSENTRYINFORMATION */

		virtual void get_OnWriteFileTag(TElVFSWriteFileTagEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWriteFileTag(TElVFSWriteFileTagEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadFileTag(TElVFSReadFileTagEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadFileTag(TElVFSReadFileTagEvent pMethodValue, void * pDataValue);

		virtual void get_OnDeleteFileTag(TElVFSDeleteFileTagEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDeleteFileTag(TElVFSDeleteFileTagEvent pMethodValue, void * pDataValue);

		TElDiskFileSystemAdapter(TElDiskFileSystemAdapterHandle handle, TElOwnHandle ownHandle);

		explicit TElDiskFileSystemAdapter(TComponent &AOwner);

		explicit TElDiskFileSystemAdapter(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELDISKFILESYSTEMADAPTER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDISKFSADAPTER */

