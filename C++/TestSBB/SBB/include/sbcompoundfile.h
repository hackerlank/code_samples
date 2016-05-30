#ifndef __INC_SBCOMPOUNDFILE
#define __INC_SBCOMPOUNDFILE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcompoundfilebase.h"
#include "sbcompoundfileresources.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCompoundFileStorageHandle;

typedef TElClassHandle TElCompoundFileStreamEntryHandle;

typedef TElClassHandle TElCompoundFileStorageEntryHandle;

typedef TElClassHandle TElCompoundFileVirtualStreamHandle;

typedef TElClassHandle TElCompoundFileTableStreamHandle;

typedef TElClassHandle TElCompoundFileDirectoryStreamHandle;

typedef TElClassHandle TElCompoundFileCustomEntryHandle;

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_CreateNew(TElCompoundFileStorageHandle _Handle, const char * pcFileName, int32_t szFileName, int32_t Version);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_CreateNew_1(TElCompoundFileStorageHandle _Handle, TStreamHandle Stream, int32_t Version);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_CreateNew_2(TElCompoundFileStorageHandle _Handle, TStreamHandle Stream, int32_t Version, int8_t OwnStream);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Open(TElCompoundFileStorageHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Open_1(TElCompoundFileStorageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Open_2(TElCompoundFileStorageHandle _Handle, TStreamHandle Stream, int8_t OwnStream);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Open_3(TElCompoundFileStorageHandle _Handle, TStreamHandle Stream, int8_t OwnStream, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Close(TElCompoundFileStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Flush(TElCompoundFileStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_FileVersion(TElCompoundFileStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_IsReadOnly(TElCompoundFileStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_SectorSize(TElCompoundFileStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_MiniSectorSize(TElCompoundFileStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_MiniSectorCutoffSize(TElCompoundFileStorageHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_get_RootEntry(TElCompoundFileStorageHandle _Handle, TElCompoundFileStorageEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorage_Create(TElCompoundFileStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileCustomEntry_get_Name(TElCompoundFileCustomEntryHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileCustomEntry_set_Name(TElCompoundFileCustomEntryHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileCustomEntry_get_Parent(TElCompoundFileCustomEntryHandle _Handle, TElCompoundFileStorageEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileCustomEntry_get_Storage(TElCompoundFileCustomEntryHandle _Handle, TElCompoundFileStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileCustomEntry_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_CreateStream(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStreamName, int32_t szStreamName, TElCompoundFileStreamEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_CreateSubStorage(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStorageName, int32_t szStorageName, TElCompoundFileStorageEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_DeleteStream(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStreamName, int32_t szStreamName);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_DeleteSubStorage(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStorageName, int32_t szStorageName);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_GetStream(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStreamName, int32_t szStreamName, TElCompoundFileStreamEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_GetSubStorage(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStorageName, int32_t szStorageName, TElCompoundFileStorageEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_FindEntryByName(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcEntryName, int32_t szEntryName, TElCompoundFileCustomEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_StreamExists(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStreamName, int32_t szStreamName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_SubStorageExists(TElCompoundFileStorageEntryHandle _Handle, const sb_char16_t * pcStorageName, int32_t szStorageName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_GetFirstChild(TElCompoundFileStorageEntryHandle _Handle, TElCompoundFileCustomEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_GetNextEntry(TElCompoundFileStorageEntryHandle _Handle, TElCompoundFileCustomEntryHandle Last, TElCompoundFileCustomEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_get_CLSID(TElCompoundFileStorageEntryHandle _Handle, TGuid * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_set_CLSID(TElCompoundFileStorageEntryHandle _Handle, TGuid * Value);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_get_CreationTime(TElCompoundFileStorageEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_set_CreationTime(TElCompoundFileStorageEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_get_ModifiedTime(TElCompoundFileStorageEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_set_ModifiedTime(TElCompoundFileStorageEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStorageEntry_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Flush(TElCompoundFileVirtualStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Close(TElCompoundFileVirtualStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Close_1(TElCompoundFileVirtualStreamHandle _Handle, int8_t FlushData);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Read(TElCompoundFileVirtualStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Write(TElCompoundFileVirtualStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Seek(TElCompoundFileVirtualStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Seek_1(TElCompoundFileVirtualStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_get_IsMiniStream(TElCompoundFileVirtualStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Create(TElCompoundFileStorageHandle Storage, TElCompoundFileVirtualStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileVirtualStream_Create_1(TElCompoundFileStorageHandle Storage, TElCompoundFileStreamEntryHandle StreamEntry, TElCompoundFileVirtualStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileTableStream_Read(TElCompoundFileTableStreamHandle _Handle, uint32_t * Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileTableStream_Write(TElCompoundFileTableStreamHandle _Handle, uint32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileTableStream_Create(TElCompoundFileStorageHandle Storage, TElCompoundFileVirtualStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileTableStream_Create_1(TElCompoundFileStorageHandle Storage, TElCompoundFileStreamEntryHandle StreamEntry, TElCompoundFileVirtualStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileDirectoryStream_Read(TElCompoundFileDirectoryStreamHandle _Handle, TSBCompoundFileDirectoryEntry * Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileDirectoryStream_Write(TElCompoundFileDirectoryStreamHandle _Handle, const TSBCompoundFileDirectoryEntry * Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileDirectoryStream_Create(TElCompoundFileStorageHandle Storage, TElCompoundFileVirtualStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileDirectoryStream_Create_1(TElCompoundFileStorageHandle Storage, TElCompoundFileStreamEntryHandle StreamEntry, TElCompoundFileVirtualStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStreamEntry_get_Stream(TElCompoundFileStreamEntryHandle _Handle, TElCompoundFileVirtualStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCompoundFileStreamEntry_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCompoundFileStorage;
class TElCompoundFileStreamEntry;
class TElCompoundFileStorageEntry;
class TElCompoundFileVirtualStream;
class TElCompoundFileTableStream;
class TElCompoundFileDirectoryStream;
class TElCompoundFileCustomEntry;

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
class TElCompoundFileStorage: public TObject
{
	private:
		SB_DISABLE_COPY(TElCompoundFileStorage)
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
		TElCompoundFileStorageEntry* _Inst_RootEntry;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

		void initInstances();

	public:
		void CreateNew(const std::string &FileName, int32_t Version);

#ifdef SB_USE_CLASS_TSTREAM
		void CreateNew(TStream &Stream, int32_t Version);

		void CreateNew(TStream *Stream, int32_t Version);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void CreateNew(TStream &Stream, int32_t Version, bool OwnStream);

		void CreateNew(TStream *Stream, int32_t Version, bool OwnStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream);

		void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream);

		void Open(TStream *Stream, bool OwnStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream, bool ReadOnly);

		void Open(TStream *Stream, bool OwnStream, bool ReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

		void Close();

		void Flush();

		virtual int32_t get_FileVersion();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FileVersion, TElCompoundFileStorage, FileVersion);

		virtual bool get_IsReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_IsReadOnly, TElCompoundFileStorage, IsReadOnly);

		virtual int32_t get_SectorSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SectorSize, TElCompoundFileStorage, SectorSize);

		virtual int32_t get_MiniSectorSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MiniSectorSize, TElCompoundFileStorage, MiniSectorSize);

		virtual uint32_t get_MiniSectorCutoffSize();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_MiniSectorCutoffSize, TElCompoundFileStorage, MiniSectorCutoffSize);

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
		virtual TElCompoundFileStorageEntry* get_RootEntry();

		SB_DECLARE_PROPERTY_GET(TElCompoundFileStorageEntry*, get_RootEntry, TElCompoundFileStorage, RootEntry);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

		TElCompoundFileStorage(TElCompoundFileStorageHandle handle, TElOwnHandle ownHandle);

		TElCompoundFileStorage();

		virtual ~TElCompoundFileStorage();

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY
class TElCompoundFileCustomEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElCompoundFileCustomEntry)
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
		TElCompoundFileStorageEntry* _Inst_Parent;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
		TElCompoundFileStorage* _Inst_Storage;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

		void initInstances();

	public:
		virtual void get_Name(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Name(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Name(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Name(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
		virtual TElCompoundFileStorageEntry* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElCompoundFileStorageEntry*, get_Parent, TElCompoundFileCustomEntry, Parent);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
		virtual TElCompoundFileStorage* get_Storage();

		SB_DECLARE_PROPERTY_GET(TElCompoundFileStorage*, get_Storage, TElCompoundFileCustomEntry, Storage);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

		TElCompoundFileCustomEntry(TElCompoundFileCustomEntryHandle handle, TElOwnHandle ownHandle);

		TElCompoundFileCustomEntry();

		virtual ~TElCompoundFileCustomEntry();

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILECUSTOMENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
class TElCompoundFileStorageEntry: public TElCompoundFileCustomEntry
{
	private:
		SB_DISABLE_COPY(TElCompoundFileStorageEntry)
	public:
#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
		TElCompoundFileStreamEntryHandle CreateStream(const sb_u16string &StreamName);
#ifdef SB_U16STRING_USED
		TElCompoundFileStreamEntryHandle CreateStream(const std::wstring &StreamName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

		TElCompoundFileStorageEntryHandle CreateSubStorage(const sb_u16string &StorageName);
#ifdef SB_U16STRING_USED
		TElCompoundFileStorageEntryHandle CreateSubStorage(const std::wstring &StorageName);
#endif /* SB_U16STRING_USED */

		void DeleteStream(const sb_u16string &StreamName);
#ifdef SB_U16STRING_USED
		void DeleteStream(const std::wstring &StreamName);
#endif /* SB_U16STRING_USED */

		void DeleteSubStorage(const sb_u16string &StorageName);
#ifdef SB_U16STRING_USED
		void DeleteSubStorage(const std::wstring &StorageName);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
		TElCompoundFileStreamEntryHandle GetStream(const sb_u16string &StreamName);
#ifdef SB_U16STRING_USED
		TElCompoundFileStreamEntryHandle GetStream(const std::wstring &StreamName);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

		TElCompoundFileStorageEntryHandle GetSubStorage(const sb_u16string &StorageName);
#ifdef SB_U16STRING_USED
		TElCompoundFileStorageEntryHandle GetSubStorage(const std::wstring &StorageName);
#endif /* SB_U16STRING_USED */

		TElCompoundFileCustomEntryHandle FindEntryByName(const sb_u16string &EntryName);
#ifdef SB_U16STRING_USED
		TElCompoundFileCustomEntryHandle FindEntryByName(const std::wstring &EntryName);
#endif /* SB_U16STRING_USED */

		bool StreamExists(const sb_u16string &StreamName);
#ifdef SB_U16STRING_USED
		bool StreamExists(const std::wstring &StreamName);
#endif /* SB_U16STRING_USED */

		bool SubStorageExists(const sb_u16string &StorageName);
#ifdef SB_U16STRING_USED
		bool SubStorageExists(const std::wstring &StorageName);
#endif /* SB_U16STRING_USED */

		TElCompoundFileCustomEntryHandle GetFirstChild();

		TElCompoundFileCustomEntryHandle GetNextEntry(TElCompoundFileCustomEntry &Last);

		TElCompoundFileCustomEntryHandle GetNextEntry(TElCompoundFileCustomEntry *Last);

		virtual void get_CLSID(TGuid &OutResult);

		virtual void set_CLSID(TGuid &Value);

		virtual int64_t get_CreationTime();

		virtual void set_CreationTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreationTime, set_CreationTime, TElCompoundFileStorageEntry, CreationTime);

		virtual int64_t get_ModifiedTime();

		virtual void set_ModifiedTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModifiedTime, set_ModifiedTime, TElCompoundFileStorageEntry, ModifiedTime);

		TElCompoundFileStorageEntry(TElCompoundFileStorageEntryHandle handle, TElOwnHandle ownHandle);

		TElCompoundFileStorageEntry();

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
class TElCompoundFileVirtualStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElCompoundFileVirtualStream)
	public:
		void Flush();

		void Close();

		void Close(bool FlushData);

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual bool get_IsMiniStream();

		SB_DECLARE_PROPERTY_GET(bool, get_IsMiniStream, TElCompoundFileVirtualStream, IsMiniStream);

		TElCompoundFileVirtualStream(TElCompoundFileVirtualStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
		explicit TElCompoundFileVirtualStream(TElCompoundFileStorage &Storage);

		explicit TElCompoundFileVirtualStream(TElCompoundFileStorage *Storage);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
		TElCompoundFileVirtualStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry);

		TElCompoundFileVirtualStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry);
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM
class TElCompoundFileTableStream: public TElCompoundFileVirtualStream
{
	private:
		SB_DISABLE_COPY(TElCompoundFileTableStream)
	public:
		int32_t Read(uint32_t &Value);

		int32_t Write(uint32_t Value);

		TElCompoundFileTableStream(TElCompoundFileTableStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
		explicit TElCompoundFileTableStream(TElCompoundFileStorage &Storage);

		explicit TElCompoundFileTableStream(TElCompoundFileStorage *Storage);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
		TElCompoundFileTableStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry);

		TElCompoundFileTableStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry);
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILETABLESTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM
class TElCompoundFileDirectoryStream: public TElCompoundFileVirtualStream
{
	private:
		SB_DISABLE_COPY(TElCompoundFileDirectoryStream)
	public:
		int32_t Read(TSBCompoundFileDirectoryEntry &Value);

		int32_t Write(const TSBCompoundFileDirectoryEntry &Value);

		TElCompoundFileDirectoryStream(TElCompoundFileDirectoryStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGE
		explicit TElCompoundFileDirectoryStream(TElCompoundFileStorage &Storage);

		explicit TElCompoundFileDirectoryStream(TElCompoundFileStorage *Storage);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGE */

#ifdef SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY
		TElCompoundFileDirectoryStream(TElCompoundFileStorage &Storage, TElCompoundFileStreamEntry &StreamEntry);

		TElCompoundFileDirectoryStream(TElCompoundFileStorage *Storage, TElCompoundFileStreamEntry *StreamEntry);
#endif /* SB_USE_CLASSES_TELCOMPOUNDFILESTORAGE_AND_TELCOMPOUNDFILESTREAMENTRY */

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEDIRECTORYSTREAM */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY
class TElCompoundFileStreamEntry: public TElCompoundFileCustomEntry
{
	private:
		SB_DISABLE_COPY(TElCompoundFileStreamEntry)
#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
		TElCompoundFileVirtualStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM
		virtual TElCompoundFileVirtualStream* get_Stream();

		SB_DECLARE_PROPERTY_GET(TElCompoundFileVirtualStream*, get_Stream, TElCompoundFileStreamEntry, Stream);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILEVIRTUALSTREAM */

		TElCompoundFileStreamEntry(TElCompoundFileStreamEntryHandle handle, TElOwnHandle ownHandle);

		TElCompoundFileStreamEntry();

		virtual ~TElCompoundFileStreamEntry();

};
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTREAMENTRY */

#ifdef SB_USE_GLOBAL_PROCS_COMPOUNDFILE

bool IsValidDirectoryEntryName(const sb_u16string &EntryName);
#ifdef SB_U16STRING_USED
bool IsValidDirectoryEntryName(const std::wstring &EntryName);
#endif /* SB_U16STRING_USED */

int32_t CompareDirectoryEntryNames(const sb_u16string &X, const sb_u16string &Y);
#ifdef SB_U16STRING_USED
int32_t CompareDirectoryEntryNames(const std::wstring &X, const std::wstring &Y);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY
void CopyStorage(TElCompoundFileStorageEntry &SourceStorage, TElCompoundFileStorageEntry &DestStorage);
void CopyStorage(TElCompoundFileStorageEntry *SourceStorage, TElCompoundFileStorageEntry *DestStorage);
#endif /* SB_USE_CLASS_TELCOMPOUNDFILESTORAGEENTRY */

#endif /* SB_USE_GLOBAL_PROCS_COMPOUNDFILE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_COMPOUNDFILE
SB_IMPORT uint32_t SB_APIENTRY SBCompoundFile_IsValidDirectoryEntryName(const sb_char16_t * pcEntryName, int32_t szEntryName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCompoundFile_CompareDirectoryEntryNames(const sb_char16_t * pcX, int32_t szX, const sb_char16_t * pcY, int32_t szY, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCompoundFile_CopyStorage(TElCompoundFileStorageEntryHandle SourceStorage, TElCompoundFileStorageEntryHandle DestStorage);
#endif /* SB_USE_GLOBAL_PROCS_COMPOUNDFILE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCOMPOUNDFILE */

