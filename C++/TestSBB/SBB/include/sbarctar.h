#ifndef __INC_SBARCTAR
#define __INC_SBARCTAR

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbdictionary.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbarcbase.h"
#include "sbtarentities.h"
#include "sbtarutils.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbconstants.h"
#include "sbarcgzip.h"
#include "sbziputils.h"
#include "sbarcbzip2.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_TAR_EVENT_EXTRACTION_FAILED 	4097
#define SB_TAR_EVENT_FILE_ALREADY_EXISTS 	4098
#define SB_TAR_EVENT_CANNOT_CREATE_FILE 	4099
#define SB_TAR_EVENT_DIR_ALREADY_EXISTS 	4100
#define SB_TAR_EVENT_FILE_ALREADY_ADDED 	4101
#define SB_TAR_EVENT_CRC_MISMATCH 	4102
#define SB_TAR_ACTION_IGNORE 	4097
#define SB_TAR_ACTION_ABORT 	4098
#define SB_TAR_ACTION_RETRY 	4099
#define SB_TAR_ACTION_SKIP 	4100

typedef TElClassHandle TElTarArchiveDirectoryEntryHandle;

typedef TElClassHandle TElTarFileAttributesHandle;

typedef TElTarArchiveDirectoryEntryHandle ElTarArchiveDirectoryEntryHandle;

typedef TElClassHandle TElTarProcessingUnitHandle;

typedef TElTarProcessingUnitHandle ElTarProcessingUnitHandle;

typedef TElClassHandle TElTarReaderHandle;

typedef TElTarReaderHandle ElTarReaderHandle;

typedef TElClassHandle TElTarWriterHandle;

typedef TElTarWriterHandle ElTarWriterHandle;

typedef void (SB_CALLBACK *TSBTarExtractionFinishedEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry);

typedef void (SB_CALLBACK *TSBTarExtractionMakeDirectoryEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry);

typedef void (SB_CALLBACK *TSBTarProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Processed, int64_t Total, int64_t OverallProcessed, int64_t OverallTotal, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBTarExtractionStartEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry, int8_t * Extract);

typedef void (SB_CALLBACK *TSBTarUserActionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ForEvent, const char * pcDescription, int32_t szDescription, void * Param, int32_t * UserAction);

typedef void (SB_CALLBACK *TSBTarExtractionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBTarCompressionStartEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry, int8_t * Compress);

typedef void (SB_CALLBACK *TSBTarCompressionTarToGZipStartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Compress);

typedef void (SB_CALLBACK *TSBTarCompressionTarToBZip2StartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Compress);

typedef void (SB_CALLBACK *TSBTarUnCompressionTarFromGZipStartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Compress);

typedef void (SB_CALLBACK *TSBTarUnCompressionTarFromBZip2StartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Compress);

typedef void (SB_CALLBACK *TSBTarCompressionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBTarCompressionFinishedEvent)(void * _ObjectData, TObjectHandle Sender, TElTarArchiveDirectoryEntryHandle Entry);

typedef void (SB_CALLBACK *TSBTarCompressionTarToGZipFinishedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBTarCompressionTarToBZip2FinishedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBTarUnCompressionTarFromGZipFinishedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBTarUnCompressionTarFromBZip2FinishedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef uint8_t TSBTarFileTypeRaw;

typedef enum
{
	uftFIFOSpecial = 0,
	_uftCharacterSpecial = 1,
	_uftDirectory = 2,
	_uftBlockSpecial = 3,
	_uftRegularFile = 4,
	_uftSymbolicLink = 5
} TSBTarFileType;

typedef uint8_t TSBTarCompressMethodRaw;

typedef enum
{
	cmNone = 0,
	cmGZip = 1,
	cmBZip2 = 2
} TSBTarCompressMethod;

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_Clear(TElTarArchiveDirectoryEntryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_AddEntry(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_AddNewEntry(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_RemoveEntry(TElTarArchiveDirectoryEntryHandle _Handle, TElTarArchiveDirectoryEntryHandle Entry, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_RemoveEntry_1(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_RemoveEntry_2(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t CaseSensitive, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_ClearEntries(TElTarArchiveDirectoryEntryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_EntryWithName(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAName, int32_t szAName, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_EntryWithName_1(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAName, int32_t szAName, int8_t CaseSensitive, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_EntryWithPath(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_EntryWithPath_1(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t CaseSensitive, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_Parent(TElTarArchiveDirectoryEntryHandle _Handle, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_Entries(TElTarArchiveDirectoryEntryHandle _Handle, int32_t Index, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_Path(TElTarArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_LocalHeaderOffset(TElTarArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_set_LocalHeaderOffset(TElTarArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_Attributes(TElTarArchiveDirectoryEntryHandle _Handle, TElTarFileAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_CheckSum(TElTarArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_Process(TElTarArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_set_Process(TElTarArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_ExtractionPath(TElTarArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_set_ExtractionPath(TElTarArchiveDirectoryEntryHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_ExtractionStream(TElTarArchiveDirectoryEntryHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_set_ExtractionStream(TElTarArchiveDirectoryEntryHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_get_InputStream(TElTarArchiveDirectoryEntryHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_set_InputStream(TElTarArchiveDirectoryEntryHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_Create(TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarArchiveDirectoryEntry_Create_1(TElBaseArchiveHandle Owner, TElTarArchiveDirectoryEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_Assign(TElTarFileAttributesHandle _Handle, TElTarFileAttributesHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_AssignTo(TElTarFileAttributesHandle _Handle, TElTarFileAttributesHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_Mode(TElTarFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_Mode(TElTarFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_FileSize(TElTarFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_FileSize(TElTarFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_FileType(TElTarFileAttributesHandle _Handle, TSBTarFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_FileType(TElTarFileAttributesHandle _Handle, TSBTarFileTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_FileTypeCode(TElTarFileAttributesHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_FileTypeCode(TElTarFileAttributesHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_ModifyTimeAvailable(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_ModifyTimeAvailable(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_ModifyTime(TElTarFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_ModifyTime(TElTarFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_LinkName(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_LinkName(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_SUID(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_SUID(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_SGID(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_SGID(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OwnerRead(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OwnerRead(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OwnerWrite(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OwnerWrite(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OwnerExecute(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OwnerExecute(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_GroupRead(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_GroupRead(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_GroupWrite(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_GroupWrite(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_GroupExecute(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_GroupExecute(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OtherRead(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OtherRead(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OtherWrite(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OtherWrite(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_OtherExecute(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_OtherExecute(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_UIDAndGIDAvailable(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_UIDAndGIDAvailable(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_UID(TElTarFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_UID(TElTarFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_GID(TElTarFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_GID(TElTarFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_HasUStar(TElTarFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_HasUStar(TElTarFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_UName(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_UName(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_GName(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_GName(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_DevMajor(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_DevMajor(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_DevMinor(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_DevMinor(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_get_Prefix(TElTarFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_set_Prefix(TElTarFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarFileAttributes_Create(TElTarFileAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELTARPROCESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_InitializeProcessing(TElTarProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_ProcessBlock(TElTarProcessingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_FinalizeProcessing(TElTarProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_get_ProcessingEntry(TElTarProcessingUnitHandle _Handle, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_set_ProcessingEntry(TElTarProcessingUnitHandle _Handle, TElTarArchiveDirectoryEntryHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarProcessingUnit_Create(TElTarProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELTARREADER
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Open(TElTarReaderHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Open_1(TElTarReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Close(TElTarReaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Extract(TElTarReaderHandle _Handle, TElTarArchiveDirectoryEntryHandle Entry, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Extract_1(TElTarReaderHandle _Handle, TListHandle Entries, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Extract_2(TElTarReaderHandle _Handle, const char * pcMask, int32_t szMask, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_ExtractContents(TElTarReaderHandle _Handle, TElTarArchiveDirectoryEntryHandle Entry, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_Directory(TElTarReaderHandle _Handle, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_IgnoreArchiveErrors(TElTarReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_IgnoreArchiveErrors(TElTarReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_CaseSensitiveFilenames(TElTarReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_CaseSensitiveFilenames(TElTarReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_FilenamesCharset(TElTarReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_FilenamesCharset(TElTarReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_FileSystemAdapter(TElTarReaderHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_FileSystemAdapter(TElTarReaderHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_CompressionMethod(TElTarReaderHandle _Handle, TSBTarCompressMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_CompressionMethod(TElTarReaderHandle _Handle, TSBTarCompressMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnExtractionStreamNeeded(TElTarReaderHandle _Handle, TSBTarExtractionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnExtractionStreamNeeded(TElTarReaderHandle _Handle, TSBTarExtractionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnExtractionMakeDirectory(TElTarReaderHandle _Handle, TSBTarExtractionMakeDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnExtractionMakeDirectory(TElTarReaderHandle _Handle, TSBTarExtractionMakeDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnProgress(TElTarReaderHandle _Handle, TSBTarProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnProgress(TElTarReaderHandle _Handle, TSBTarProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnExtractionStart(TElTarReaderHandle _Handle, TSBTarExtractionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnExtractionStart(TElTarReaderHandle _Handle, TSBTarExtractionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnExtractionFinished(TElTarReaderHandle _Handle, TSBTarExtractionFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnExtractionFinished(TElTarReaderHandle _Handle, TSBTarExtractionFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnUserActionNeeded(TElTarReaderHandle _Handle, TSBTarUserActionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnUserActionNeeded(TElTarReaderHandle _Handle, TSBTarUserActionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnArchiveError(TElTarReaderHandle _Handle, TSBTarArchiveErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnArchiveError(TElTarReaderHandle _Handle, TSBTarArchiveErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnUnCompressionTarFromGZipStart(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromGZipStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnUnCompressionTarFromGZipStart(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromGZipStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnUnCompressionTarFromGZipFinished(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromGZipFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnUnCompressionTarFromGZipFinished(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromGZipFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnUnCompressionTarFromBZip2Start(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromBZip2StartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnUnCompressionTarFromBZip2Start(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromBZip2StartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_get_OnUnCompressionTarFromBZip2Finished(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromBZip2FinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_set_OnUnCompressionTarFromBZip2Finished(TElTarReaderHandle _Handle, TSBTarUnCompressionTarFromBZip2FinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarReader_Create(TComponentHandle AOwner, TElTarReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARREADER */

#ifdef SB_USE_CLASS_TELTARWRITER
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_CreateArchive(TElTarWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_1(TElTarWriterHandle _Handle, const char * pcPath, int32_t szPath, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_2(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_3(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, TStreamHandle Stream, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_4(TElTarWriterHandle _Handle, TStreamHandle Stream, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_5(TElTarWriterHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_6(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, const uint8_t pBuf[], int32_t szBuf, int32_t StartIndex, int32_t Count, const char * pcFileName, int32_t szFileName, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Add_7(TElTarWriterHandle _Handle, const uint8_t pBuf[], int32_t szBuf, int32_t StartIndex, int32_t Count, const char * pcFileName, int32_t szFileName, int32_t Mode, TElUStarTarHeaderHandle USTAR, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_AddDirContents(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, int32_t Mode, TElUStarTarHeaderHandle USTAR);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_AddDirContents_1(TElTarWriterHandle _Handle, const char * pcPath, int32_t szPath, int32_t Mode, TElUStarTarHeaderHandle USTAR);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_AddDirContents_2(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int32_t Mode, TElUStarTarHeaderHandle USTAR);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_AddDirContents_3(TElTarWriterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int32_t Mode, TElUStarTarHeaderHandle USTAR);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_MakeDir(TElTarWriterHandle _Handle, const char * pcPath, int32_t szPath, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_MakeDir_1(TElTarWriterHandle _Handle, TElTarArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, TElTarArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Remove(TElTarWriterHandle _Handle, const char * pcMask, int32_t szMask);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_BeginCompression(TElTarWriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_BeginCompression_1(TElTarWriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_UpdateCompression(TElTarWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_EndCompression(TElTarWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Compress(TElTarWriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Compress_1(TElTarWriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Compress_2(TElTarWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Close(TElTarWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_UID(TElTarWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_UID(TElTarWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_GID(TElTarWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_GID(TElTarWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_ReplaceMode(TElTarWriterHandle _Handle, TSBArcReplaceModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_ReplaceMode(TElTarWriterHandle _Handle, TSBArcReplaceModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_NewArchive(TElTarWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_CompressionLevel(TElTarWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_CompressionLevel(TElTarWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionStreamNeeded(TElTarWriterHandle _Handle, TSBTarCompressionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionStreamNeeded(TElTarWriterHandle _Handle, TSBTarCompressionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionStart(TElTarWriterHandle _Handle, TSBTarCompressionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionStart(TElTarWriterHandle _Handle, TSBTarCompressionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionFinished(TElTarWriterHandle _Handle, TSBTarCompressionFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionFinished(TElTarWriterHandle _Handle, TSBTarCompressionFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionTarToGZipStart(TElTarWriterHandle _Handle, TSBTarCompressionTarToGZipStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionTarToGZipStart(TElTarWriterHandle _Handle, TSBTarCompressionTarToGZipStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionTarToGZipFinished(TElTarWriterHandle _Handle, TSBTarCompressionTarToGZipFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionTarToGZipFinished(TElTarWriterHandle _Handle, TSBTarCompressionTarToGZipFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionTarToBZip2Start(TElTarWriterHandle _Handle, TSBTarCompressionTarToBZip2StartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionTarToBZip2Start(TElTarWriterHandle _Handle, TSBTarCompressionTarToBZip2StartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_get_OnCompressionTarToBZip2Finished(TElTarWriterHandle _Handle, TSBTarCompressionTarToBZip2FinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_set_OnCompressionTarToBZip2Finished(TElTarWriterHandle _Handle, TSBTarCompressionTarToBZip2FinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTarWriter_Create(TComponentHandle AOwner, TElTarWriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELTARWRITER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElTarArchiveDirectoryEntry;
class TElTarFileAttributes;
typedef TElTarArchiveDirectoryEntry ElTarArchiveDirectoryEntry;
class TElTarProcessingUnit;
typedef TElTarProcessingUnit ElTarProcessingUnit;
class TElTarReader;
typedef TElTarReader ElTarReader;
class TElTarWriter;
typedef TElTarWriter ElTarWriter;

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
class TElTarArchiveDirectoryEntry: public TElArchiveDirectoryEntry
{
	private:
		SB_DISABLE_COPY(TElTarArchiveDirectoryEntry)
		TElTarArchiveDirectoryEntry* _Inst_Parent;
		TElTarArchiveDirectoryEntry* _Inst_Entries;
#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
		TElTarFileAttributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_ExtractionStream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_InputStream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void Clear();

		TElTarArchiveDirectoryEntryHandle AddEntry(const std::string &APath);

		TElTarArchiveDirectoryEntryHandle AddNewEntry(const std::string &APath);

		bool RemoveEntry(TElTarArchiveDirectoryEntry &Entry);

		bool RemoveEntry(TElTarArchiveDirectoryEntry *Entry);

		bool RemoveEntry(const std::string &APath);

		bool RemoveEntry(const std::string &APath, bool CaseSensitive);

		virtual void ClearEntries();

		TElTarArchiveDirectoryEntryHandle EntryWithName(const std::string &AName);

		TElTarArchiveDirectoryEntryHandle EntryWithName(const std::string &AName, bool CaseSensitive);

		TElTarArchiveDirectoryEntryHandle EntryWithPath(const std::string &APath);

		TElTarArchiveDirectoryEntryHandle EntryWithPath(const std::string &APath, bool CaseSensitive);

		virtual TElTarArchiveDirectoryEntry* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElTarArchiveDirectoryEntry*, get_Parent, TElTarArchiveDirectoryEntry, Parent);

		virtual TElTarArchiveDirectoryEntry* get_Entries(int32_t Index);

		virtual void get_Path(std::string &OutResult);

		virtual int64_t get_LocalHeaderOffset();

		virtual void set_LocalHeaderOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_LocalHeaderOffset, set_LocalHeaderOffset, TElTarArchiveDirectoryEntry, LocalHeaderOffset);

#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
		virtual TElTarFileAttributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElTarFileAttributes*, get_Attributes, TElTarArchiveDirectoryEntry, Attributes);
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */

		virtual uint32_t get_CheckSum();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_CheckSum, TElTarArchiveDirectoryEntry, CheckSum);

		virtual bool get_Process();

		virtual void set_Process(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Process, set_Process, TElTarArchiveDirectoryEntry, Process);

		virtual void get_ExtractionPath(std::string &OutResult);

		virtual void set_ExtractionPath(const std::string &Value);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_ExtractionStream();

		virtual void set_ExtractionStream(TStream &Value);

		virtual void set_ExtractionStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_ExtractionStream, set_ExtractionStream, TElTarArchiveDirectoryEntry, ExtractionStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_InputStream();

		virtual void set_InputStream(TStream &Value);

		virtual void set_InputStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_InputStream, set_InputStream, TElTarArchiveDirectoryEntry, InputStream);
#endif /* SB_USE_CLASS_TSTREAM */

		TElTarArchiveDirectoryEntry(TElTarArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle);

		TElTarArchiveDirectoryEntry();

#ifdef SB_USE_CLASS_TELBASEARCHIVE
		explicit TElTarArchiveDirectoryEntry(TElBaseArchive &Owner);

		explicit TElTarArchiveDirectoryEntry(TElBaseArchive *Owner);
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

		virtual ~TElTarArchiveDirectoryEntry();

};
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARFILEATTRIBUTES
class TElTarFileAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElTarFileAttributes)
	public:
		void Assign(TElTarFileAttributes &Source);

		void Assign(TElTarFileAttributes *Source);

		void AssignTo(TElTarFileAttributes &Dest);

		void AssignTo(TElTarFileAttributes *Dest);

		virtual uint32_t get_Mode();

		virtual void set_Mode(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Mode, set_Mode, TElTarFileAttributes, Mode);

		virtual int64_t get_FileSize();

		virtual void set_FileSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileSize, set_FileSize, TElTarFileAttributes, FileSize);

		virtual TSBTarFileType get_FileType();

		virtual void set_FileType(TSBTarFileType Value);

		SB_DECLARE_PROPERTY(TSBTarFileType, get_FileType, set_FileType, TElTarFileAttributes, FileType);

		virtual char get_FileTypeCode();

		virtual void set_FileTypeCode(char Value);

		SB_DECLARE_PROPERTY(char, get_FileTypeCode, set_FileTypeCode, TElTarFileAttributes, FileTypeCode);

		virtual bool get_ModifyTimeAvailable();

		virtual void set_ModifyTimeAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ModifyTimeAvailable, set_ModifyTimeAvailable, TElTarFileAttributes, ModifyTimeAvailable);

		virtual int64_t get_ModifyTime();

		virtual void set_ModifyTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModifyTime, set_ModifyTime, TElTarFileAttributes, ModifyTime);

		virtual void get_LinkName(std::string &OutResult);

		virtual void set_LinkName(const std::string &Value);

		virtual bool get_SUID();

		virtual void set_SUID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SUID, set_SUID, TElTarFileAttributes, SUID);

		virtual bool get_SGID();

		virtual void set_SGID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SGID, set_SGID, TElTarFileAttributes, SGID);

		virtual bool get_OwnerRead();

		virtual void set_OwnerRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerRead, set_OwnerRead, TElTarFileAttributes, OwnerRead);

		virtual bool get_OwnerWrite();

		virtual void set_OwnerWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerWrite, set_OwnerWrite, TElTarFileAttributes, OwnerWrite);

		virtual bool get_OwnerExecute();

		virtual void set_OwnerExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerExecute, set_OwnerExecute, TElTarFileAttributes, OwnerExecute);

		virtual bool get_GroupRead();

		virtual void set_GroupRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupRead, set_GroupRead, TElTarFileAttributes, GroupRead);

		virtual bool get_GroupWrite();

		virtual void set_GroupWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupWrite, set_GroupWrite, TElTarFileAttributes, GroupWrite);

		virtual bool get_GroupExecute();

		virtual void set_GroupExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupExecute, set_GroupExecute, TElTarFileAttributes, GroupExecute);

		virtual bool get_OtherRead();

		virtual void set_OtherRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherRead, set_OtherRead, TElTarFileAttributes, OtherRead);

		virtual bool get_OtherWrite();

		virtual void set_OtherWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherWrite, set_OtherWrite, TElTarFileAttributes, OtherWrite);

		virtual bool get_OtherExecute();

		virtual void set_OtherExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherExecute, set_OtherExecute, TElTarFileAttributes, OtherExecute);

		virtual bool get_UIDAndGIDAvailable();

		virtual void set_UIDAndGIDAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UIDAndGIDAvailable, set_UIDAndGIDAvailable, TElTarFileAttributes, UIDAndGIDAvailable);

		virtual uint32_t get_UID();

		virtual void set_UID(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_UID, set_UID, TElTarFileAttributes, UID);

		virtual uint32_t get_GID();

		virtual void set_GID(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_GID, set_GID, TElTarFileAttributes, GID);

		virtual bool get_HasUStar();

		virtual void set_HasUStar(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasUStar, set_HasUStar, TElTarFileAttributes, HasUStar);

		virtual void get_UName(std::string &OutResult);

		virtual void set_UName(const std::string &Value);

		virtual void get_GName(std::string &OutResult);

		virtual void set_GName(const std::string &Value);

		virtual void get_DevMajor(std::string &OutResult);

		virtual void set_DevMajor(const std::string &Value);

		virtual void get_DevMinor(std::string &OutResult);

		virtual void set_DevMinor(const std::string &Value);

		virtual void get_Prefix(std::string &OutResult);

		virtual void set_Prefix(const std::string &Value);

		TElTarFileAttributes(TElTarFileAttributesHandle handle, TElOwnHandle ownHandle);

		TElTarFileAttributes();

};
#endif /* SB_USE_CLASS_TELTARFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELTARPROCESSINGUNIT
class TElTarProcessingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElTarProcessingUnit)
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		TElTarArchiveDirectoryEntry* _Inst_ProcessingEntry;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

		void initInstances();

	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		virtual TElTarArchiveDirectoryEntry* get_ProcessingEntry();

		virtual void set_ProcessingEntry(TElTarArchiveDirectoryEntry &Value);

		virtual void set_ProcessingEntry(TElTarArchiveDirectoryEntry *Value);

		SB_DECLARE_PROPERTY(TElTarArchiveDirectoryEntry*, get_ProcessingEntry, set_ProcessingEntry, TElTarProcessingUnit, ProcessingEntry);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

		TElTarProcessingUnit(TElTarProcessingUnitHandle handle, TElOwnHandle ownHandle);

		TElTarProcessingUnit();

		virtual ~TElTarProcessingUnit();

};
#endif /* SB_USE_CLASS_TELTARPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELTARREADER
class TElTarReader: public TElBaseArchive
{
	private:
		SB_DISABLE_COPY(TElTarReader)
#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		TElTarArchiveDirectoryEntry* _Inst_Directory;
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
		virtual void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Open(TStream &Stream);

		virtual void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Close();

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		void Extract(TElTarArchiveDirectoryEntry &Entry, const std::string &OutputPath);

		void Extract(TElTarArchiveDirectoryEntry *Entry, const std::string &OutputPath);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TLIST
		void Extract(TList &Entries, const std::string &OutputPath);

		void Extract(TList *Entries, const std::string &OutputPath);
#endif /* SB_USE_CLASS_TLIST */

		void Extract(const std::string &Mask, const std::string &OutputPath);

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		void ExtractContents(TElTarArchiveDirectoryEntry &Entry, std::vector<uint8_t> &OutResult);

		void ExtractContents(TElTarArchiveDirectoryEntry *Entry, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		virtual TElTarArchiveDirectoryEntry* get_Directory();

		SB_DECLARE_PROPERTY_GET(TElTarArchiveDirectoryEntry*, get_Directory, TElTarReader, Directory);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

		virtual bool get_IgnoreArchiveErrors();

		virtual void set_IgnoreArchiveErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreArchiveErrors, set_IgnoreArchiveErrors, TElTarReader, IgnoreArchiveErrors);

		virtual bool get_CaseSensitiveFilenames();

		virtual void set_CaseSensitiveFilenames(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CaseSensitiveFilenames, set_CaseSensitiveFilenames, TElTarReader, CaseSensitiveFilenames);

		virtual void get_FilenamesCharset(std::string &OutResult);

		virtual void set_FilenamesCharset(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElTarReader, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual TSBTarCompressMethod get_CompressionMethod();

		virtual void set_CompressionMethod(TSBTarCompressMethod Value);

		SB_DECLARE_PROPERTY(TSBTarCompressMethod, get_CompressionMethod, set_CompressionMethod, TElTarReader, CompressionMethod);

		virtual void get_OnExtractionStreamNeeded(TSBTarExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStreamNeeded(TSBTarExtractionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionMakeDirectory(TSBTarExtractionMakeDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionMakeDirectory(TSBTarExtractionMakeDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBTarProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBTarProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionStart(TSBTarExtractionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStart(TSBTarExtractionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionFinished(TSBTarExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionFinished(TSBTarExtractionFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnUserActionNeeded(TSBTarUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUserActionNeeded(TSBTarUserActionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnArchiveError(TSBTarArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArchiveError(TSBTarArchiveErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnCompressionTarFromGZipStart(TSBTarUnCompressionTarFromGZipStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnCompressionTarFromGZipStart(TSBTarUnCompressionTarFromGZipStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnCompressionTarFromGZipFinished(TSBTarUnCompressionTarFromGZipFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnCompressionTarFromGZipFinished(TSBTarUnCompressionTarFromGZipFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnCompressionTarFromBZip2Start(TSBTarUnCompressionTarFromBZip2StartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnCompressionTarFromBZip2Start(TSBTarUnCompressionTarFromBZip2StartEvent pMethodValue, void * pDataValue);

		virtual void get_OnUnCompressionTarFromBZip2Finished(TSBTarUnCompressionTarFromBZip2FinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUnCompressionTarFromBZip2Finished(TSBTarUnCompressionTarFromBZip2FinishedEvent pMethodValue, void * pDataValue);

		TElTarReader(TElTarReaderHandle handle, TElOwnHandle ownHandle);

		explicit TElTarReader(TComponent &AOwner);

		explicit TElTarReader(TComponent *AOwner);

		virtual ~TElTarReader();

};
#endif /* SB_USE_CLASS_TELTARREADER */

#ifdef SB_USE_CLASS_TELTARWRITER
class TElTarWriter: public TElTarReader
{
	private:
		SB_DISABLE_COPY(TElTarWriter)
	public:
		virtual void CreateArchive();

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		TElTarArchiveDirectoryEntryHandle Add(const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry &Parent, TStream &Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry *Parent, TStream *Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry &Parent, TStream &Stream, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry *Parent, TStream *Stream, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
		TElTarArchiveDirectoryEntryHandle Add(TStream &Stream, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TStream *Stream, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM
		TElTarArchiveDirectoryEntryHandle Add(TStream &Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TStream *Stream, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry &Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(TElTarArchiveDirectoryEntry *Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		TElTarArchiveDirectoryEntryHandle Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader &USTAR);

		TElTarArchiveDirectoryEntryHandle Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		void AddDirContents(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR);

		void AddDirContents(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
		void AddDirContents(const std::string &Path, int32_t Mode, TElUStarTarHeader &USTAR);

		void AddDirContents(const std::string &Path, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER
		void AddDirContents(TElTarArchiveDirectoryEntry &Parent, const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader &USTAR);

		void AddDirContents(TElTarArchiveDirectoryEntry *Parent, const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASSES_TELTARARCHIVEDIRECTORYENTRY_AND_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELUSTARTARHEADER
		void AddDirContents(const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader &USTAR);

		void AddDirContents(const std::string &Path, const std::string &Mask, int32_t Mode, TElUStarTarHeader *USTAR);
#endif /* SB_USE_CLASS_TELUSTARTARHEADER */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		TElTarArchiveDirectoryEntryHandle MakeDir(const std::string &Path);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY
		TElTarArchiveDirectoryEntryHandle MakeDir(TElTarArchiveDirectoryEntry &Parent, const std::string &Path);

		TElTarArchiveDirectoryEntryHandle MakeDir(TElTarArchiveDirectoryEntry *Parent, const std::string &Path);
#endif /* SB_USE_CLASS_TELTARARCHIVEDIRECTORYENTRY */

		void Remove(const std::string &Mask);

#ifdef SB_USE_CLASS_TSTREAM
		void BeginCompression(TStream &Destination);

		void BeginCompression(TStream *Destination);
#endif /* SB_USE_CLASS_TSTREAM */

		void BeginCompression(const std::string &Destination);

		void UpdateCompression();

		void EndCompression();

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Compress(TStream &Destination);

		virtual void Compress(TStream *Destination);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Compress(const std::string &Destination);

		virtual void Compress();

		virtual void Close();

		virtual int32_t get_UID();

		virtual void set_UID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_UID, set_UID, TElTarWriter, UID);

		virtual int32_t get_GID();

		virtual void set_GID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_GID, set_GID, TElTarWriter, GID);

		virtual TSBArcReplaceMode get_ReplaceMode();

		virtual void set_ReplaceMode(TSBArcReplaceMode Value);

		SB_DECLARE_PROPERTY(TSBArcReplaceMode, get_ReplaceMode, set_ReplaceMode, TElTarWriter, ReplaceMode);

		virtual bool get_NewArchive();

		SB_DECLARE_PROPERTY_GET(bool, get_NewArchive, TElTarWriter, NewArchive);

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElTarWriter, CompressionLevel);

		virtual void get_OnCompressionStreamNeeded(TSBTarCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStreamNeeded(TSBTarCompressionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionStart(TSBTarCompressionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStart(TSBTarCompressionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionFinished(TSBTarCompressionFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionFinished(TSBTarCompressionFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionTarToGZipStart(TSBTarCompressionTarToGZipStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionTarToGZipStart(TSBTarCompressionTarToGZipStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionTarToGZipFinished(TSBTarCompressionTarToGZipFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionTarToGZipFinished(TSBTarCompressionTarToGZipFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionTarToBZip2Start(TSBTarCompressionTarToBZip2StartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionTarToBZip2Start(TSBTarCompressionTarToBZip2StartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionTarToBZip2Finished(TSBTarCompressionTarToBZip2FinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionTarToBZip2Finished(TSBTarCompressionTarToBZip2FinishedEvent pMethodValue, void * pDataValue);

		TElTarWriter(TElTarWriterHandle handle, TElOwnHandle ownHandle);

		explicit TElTarWriter(TComponent &AOwner);

		explicit TElTarWriter(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELTARWRITER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBARCTAR */

