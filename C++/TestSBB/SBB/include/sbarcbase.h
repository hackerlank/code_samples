#ifndef __INC_SBARCBASE
#define __INC_SBARCBASE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElBaseArchiveHandle;

typedef TElClassHandle TElArchiveDirectoryEntryHandle;

typedef TElClassHandle TElArcProcessingUnitHandle;

typedef uint8_t TSBArcReplaceModeRaw;

typedef enum
{
	armAlways = 0,
	armNever = 1,
	armNewer = 2,
	armReportError = 3
} TSBArcReplaceMode;

typedef void (SB_CALLBACK *TSBArcReadEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t pBuffer[], int32_t * szBuffer, int32_t Index, int32_t * Written, int8_t * Last);

typedef void (SB_CALLBACK *TSBArcWriteEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);

#ifdef SB_USE_CLASS_TELBASEARCHIVE
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_Open(TElBaseArchiveHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_Open_1(TElBaseArchiveHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_Close(TElBaseArchiveHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_get_Opened(TElBaseArchiveHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_get_IsReadOnly(TElBaseArchiveHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_get_OnProgress(TElBaseArchiveHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_set_OnProgress(TElBaseArchiveHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBaseArchive_Create(TComponentHandle AOwner, TElBaseArchiveHandle * OutResult);
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

#ifdef SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_FileName(TElArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_FileName(TElArchiveDirectoryEntryHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_FileSize(TElArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_FileSize(TElArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_FileDateCreated(TElArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_FileDateCreated(TElArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_FileDateModified(TElArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_FileDateModified(TElArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_FileDateAccessed(TElArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_FileDateAccessed(TElArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_CompressedSize(TElArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_CompressedSize(TElArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_IsDirectory(TElArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_set_IsDirectory(TElArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_get_EntriesCount(TElArchiveDirectoryEntryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_Create(TElArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArchiveDirectoryEntry_Create_1(TElBaseArchiveHandle Owner, TElArchiveDirectoryEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELARCPROCESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_InitializeProcessing(TElArcProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_ProcessBlock(TElArcProcessingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_FinalizeProcessing(TElArcProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_get_OutputStream(TElArcProcessingUnitHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_set_OutputStream(TElArcProcessingUnitHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_get_OutputProcessingUnit(TElArcProcessingUnitHandle _Handle, TElArcProcessingUnitHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_set_OutputProcessingUnit(TElArcProcessingUnitHandle _Handle, TElArcProcessingUnitHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_get_ProcessedData(TElArcProcessingUnitHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_set_ProcessedData(TElArcProcessingUnitHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_get_WrittenData(TElArcProcessingUnitHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_set_WrittenData(TElArcProcessingUnitHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_get_OutputEvent(TElArcProcessingUnitHandle _Handle, TSBArcWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_set_OutputEvent(TElArcProcessingUnitHandle _Handle, TSBArcWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElArcProcessingUnit_Create(TElArcProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELARCPROCESSINGUNIT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBaseArchive;
class TElArchiveDirectoryEntry;
class TElArcProcessingUnit;

#ifdef SB_USE_CLASS_TELBASEARCHIVE
class TElBaseArchive: public TComponent
{
	private:
		SB_DISABLE_COPY(TElBaseArchive)
	public:
		virtual void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Open(TStream &Stream);

		virtual void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Close();

		virtual bool get_Opened();

		SB_DECLARE_PROPERTY_GET(bool, get_Opened, TElBaseArchive, Opened);

		virtual bool get_IsReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_IsReadOnly, TElBaseArchive, IsReadOnly);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElBaseArchive(TElBaseArchiveHandle handle, TElOwnHandle ownHandle);

		explicit TElBaseArchive(TComponent &AOwner);

		explicit TElBaseArchive(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

#ifdef SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY
class TElArchiveDirectoryEntry: public TObject
{
	private:
		SB_DISABLE_COPY(TElArchiveDirectoryEntry)
	public:
		virtual void get_FileName(std::string &OutResult);

		virtual void set_FileName(const std::string &Value);

		virtual int64_t get_FileSize();

		virtual void set_FileSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileSize, set_FileSize, TElArchiveDirectoryEntry, FileSize);

		virtual int64_t get_FileDateCreated();

		virtual void set_FileDateCreated(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileDateCreated, set_FileDateCreated, TElArchiveDirectoryEntry, FileDateCreated);

		virtual int64_t get_FileDateModified();

		virtual void set_FileDateModified(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileDateModified, set_FileDateModified, TElArchiveDirectoryEntry, FileDateModified);

		virtual int64_t get_FileDateAccessed();

		virtual void set_FileDateAccessed(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileDateAccessed, set_FileDateAccessed, TElArchiveDirectoryEntry, FileDateAccessed);

		virtual int64_t get_CompressedSize();

		virtual void set_CompressedSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CompressedSize, set_CompressedSize, TElArchiveDirectoryEntry, CompressedSize);

		virtual bool get_IsDirectory();

		virtual void set_IsDirectory(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IsDirectory, set_IsDirectory, TElArchiveDirectoryEntry, IsDirectory);

		virtual int32_t get_EntriesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EntriesCount, TElArchiveDirectoryEntry, EntriesCount);

		TElArchiveDirectoryEntry(TElArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle);

		TElArchiveDirectoryEntry();

#ifdef SB_USE_CLASS_TELBASEARCHIVE
		explicit TElArchiveDirectoryEntry(TElBaseArchive &Owner);

		explicit TElArchiveDirectoryEntry(TElBaseArchive *Owner);
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

};
#endif /* SB_USE_CLASS_TELARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELARCPROCESSINGUNIT
class TElArcProcessingUnit: public TObject
{
	private:
		SB_DISABLE_COPY(TElArcProcessingUnit)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_OutputStream;
#endif /* SB_USE_CLASS_TSTREAM */
		TElArcProcessingUnit* _Inst_OutputProcessingUnit;

		void initInstances();

	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_OutputStream();

		virtual void set_OutputStream(TStream &Value);

		virtual void set_OutputStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_OutputStream, set_OutputStream, TElArcProcessingUnit, OutputStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual TElArcProcessingUnit* get_OutputProcessingUnit();

		virtual void set_OutputProcessingUnit(TElArcProcessingUnit &Value);

		virtual void set_OutputProcessingUnit(TElArcProcessingUnit *Value);

		SB_DECLARE_PROPERTY(TElArcProcessingUnit*, get_OutputProcessingUnit, set_OutputProcessingUnit, TElArcProcessingUnit, OutputProcessingUnit);

		virtual int64_t get_ProcessedData();

		virtual void set_ProcessedData(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ProcessedData, set_ProcessedData, TElArcProcessingUnit, ProcessedData);

		virtual int64_t get_WrittenData();

		virtual void set_WrittenData(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_WrittenData, set_WrittenData, TElArcProcessingUnit, WrittenData);

		virtual void get_OutputEvent(TSBArcWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OutputEvent(TSBArcWriteEvent pMethodValue, void * pDataValue);

		TElArcProcessingUnit(TElArcProcessingUnitHandle handle, TElOwnHandle ownHandle);

		TElArcProcessingUnit();

		virtual ~TElArcProcessingUnit();

};
#endif /* SB_USE_CLASS_TELARCPROCESSINGUNIT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBARCBASE */

