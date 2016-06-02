#ifndef __INC_SBARCGZIP
#define __INC_SBARCGZIP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbstrutils.h"
#include "sbcrc.h"
#include "sbarcbase.h"
#include "sbziputils.h"
#include "sbzlib.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_GZIP_BUFFER_SIZE 	65536
#define SB_GZIP_EVENT_EXTRACTION_FAILED 	4097
#define SB_GZIP_EVENT_FILE_ALREADY_EXISTS 	4098
#define SB_GZIP_EVENT_CANNOT_CREATE_FILE 	4099
#define SB_GZIP_EVENT_DIR_ALREADY_EXISTS 	4100
#define SB_GZIP_EVENT_FILE_ALREADY_ADDED 	4101
#define SB_GZIP_EVENT_CRC_MISMATCH 	4102
#define SB_GZIP_ACTION_IGNORE 	4097
#define SB_GZIP_ACTION_ABORT 	4098
#define SB_GZIP_ACTION_RETRY 	4099
#define SB_GZIP_ACTION_SKIP 	4100
#define SB_SErrorCorrupted 	"Corrupted data"
#define SB_SInvalidPath 	"Invalid path"
#define SB_SInvalidTypeCast 	"Invalid type cast"
#ifndef SB_SInvalidHeader
#define SB_SInvalidHeader 	"Invalid gzip header"
#endif
#define SB_SFileAlreadyExists 	"File already exists"
#define SB_SCannotCreateFile 	"Cannot create file"
#define SB_SCRCMismatch 	"CRC mismatch"
#define SB_SNotExtractNewArchive 	"Can\'t extract from new archive"
#define SB_SInvalidActionRequested 	"Invalid action requested"
#define SB_SInvalidOutputFile 	"Not correctly set output file"
#define SB_SNoOutputStream 	"No output stream"
#define SB_SInvalidCompressionLevel 	"Invalid compression level"
#define SB_SInvalidWorkFactor 	"Invalid work factor"
#define SB_SArchiveAlreadyHaveFile 	"Archive already contain a file"
#define SB_SNoInputForCompression 	"No input for compression"
#define SB_SArchiveNotOpened 	"Archive is not opened"
#define SB_SArchiveNotAssign 	"For the new archive must be specified file or stream"

typedef TElClassHandle TElGZipDecompressingUnitHandle;

typedef TElGZipDecompressingUnitHandle ElGZipDecompressingUnitHandle;

typedef TElClassHandle TElGZipCompressingUnitHandle;

typedef TElGZipCompressingUnitHandle ElGZipCompressingUnitHandle;

typedef TElClassHandle TElGZipFileAttributesHandle;

typedef TElClassHandle TElGZipReaderHandle;

typedef TElGZipReaderHandle ElGZipReaderHandle;

typedef TElClassHandle TElGZipWriterHandle;

typedef TElGZipWriterHandle ElGZipWriterHandle;

typedef void (SB_CALLBACK *TSBGZipProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Processed, int64_t Total, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBGZipUserActionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ForEvent, const char * pcDescription, int32_t szDescription, int32_t * UserAction);

typedef void (SB_CALLBACK *TSBGZipExtractionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBGZipCompressionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBGZipArchiveErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcErrorMessage, int32_t szErrorMessage, int8_t * TryContinue);

typedef uint8_t TSBGZipFileSystemRaw;

typedef enum
{
	fsFAT = 0,
	fsAmiga = 1,
	fsVMS = 2,
	fsUnix = 3,
	fmVMCMS = 4,
	fsAtariTOS = 5,
	fsHPFS = 6,
	fsMacintosh = 7,
	fdZSystem = 8,
	fsCPM = 9,
	fsTOPS20 = 10,
	fsNTFS = 11,
	fsQDOS = 12,
	fsAcornRISCOS = 13,
	fsUnknown = 14
} TSBGZipFileSystem;

#ifdef SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElGZipDecompressingUnit_InitializeProcessing(TElGZipDecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipDecompressingUnit_ProcessBlock(TElGZipDecompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGZipDecompressingUnit_FinalizeProcessing(TElGZipDecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipDecompressingUnit_get_CRC32(TElGZipDecompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipDecompressingUnit_Create(TElGZipDecompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_InitializeProcessing(TElGZipCompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_ProcessBlock(TElGZipCompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_FinalizeProcessing(TElGZipCompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_get_CompressionLevel(TElGZipCompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_set_CompressionLevel(TElGZipCompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_get_CRC32(TElGZipCompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipCompressingUnit_Create(TElGZipCompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_Assign(TElGZipFileAttributesHandle _Handle, TElGZipFileAttributesHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_AssignTo(TElGZipFileAttributesHandle _Handle, TElGZipFileAttributesHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_FileName(TElGZipFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_FileName(TElGZipFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_ModifyTime(TElGZipFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_ModifyTime(TElGZipFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_FileSize(TElGZipFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_FileSize(TElGZipFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_Flag(TElGZipFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_Flag(TElGZipFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_ExtraFlag(TElGZipFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_ExtraFlag(TElGZipFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_CRC16(TElGZipFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_CRC16(TElGZipFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_CRC32(TElGZipFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_CRC32(TElGZipFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_ExtraField(TElGZipFileAttributesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_ExtraField(TElGZipFileAttributesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_Comment(TElGZipFileAttributesHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_Comment(TElGZipFileAttributesHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_FileSystem(TElGZipFileAttributesHandle _Handle, TSBGZipFileSystemRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_FileSystem(TElGZipFileAttributesHandle _Handle, TSBGZipFileSystemRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_FileSystemCode(TElGZipFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_FileSystemCode(TElGZipFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_HasText(TElGZipFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_HasText(TElGZipFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_HasCRC(TElGZipFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_HasCRC(TElGZipFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_HasExtra(TElGZipFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_HasExtra(TElGZipFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_HasName(TElGZipFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_HasName(TElGZipFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_get_HasComment(TElGZipFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_set_HasComment(TElGZipFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipFileAttributes_Create(TElGZipFileAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELGZIPREADER
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Open(TElGZipReaderHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Open_1(TElGZipReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Close(TElGZipReaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Extract(TElGZipReaderHandle _Handle, const char * pcOutputPath, int32_t szOutputPath, const char * pcOutputFile, int32_t szOutputFile);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Extract_1(TElGZipReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_CheckArchive(TElGZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_CompressedSize(TElGZipReaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_Attributes(TElGZipReaderHandle _Handle, TElGZipFileAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_IgnoreArchiveErrors(TElGZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_IgnoreArchiveErrors(TElGZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_FilenamesCharset(TElGZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_FilenamesCharset(TElGZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_FileSystemAdapter(TElGZipReaderHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_FileSystemAdapter(TElGZipReaderHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_OnExtractionStreamNeeded(TElGZipReaderHandle _Handle, TSBGZipExtractionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_OnExtractionStreamNeeded(TElGZipReaderHandle _Handle, TSBGZipExtractionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_OnProgress(TElGZipReaderHandle _Handle, TSBGZipProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_OnProgress(TElGZipReaderHandle _Handle, TSBGZipProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_OnUserActionNeeded(TElGZipReaderHandle _Handle, TSBGZipUserActionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_OnUserActionNeeded(TElGZipReaderHandle _Handle, TSBGZipUserActionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_get_OnArchiveError(TElGZipReaderHandle _Handle, TSBGZipArchiveErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_set_OnArchiveError(TElGZipReaderHandle _Handle, TSBGZipArchiveErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipReader_Create(TComponentHandle AOwner, TElGZipReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELGZIPREADER */

#ifdef SB_USE_CLASS_TELGZIPWRITER
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_CreateArchive(TElGZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Open(TElGZipWriterHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Open_1(TElGZipWriterHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Add(TElGZipWriterHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Add_1(TElGZipWriterHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Compress(TElGZipWriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Compress_1(TElGZipWriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Compress_2(TElGZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Close(TElGZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_get_NewArchive(TElGZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_get_FileSize(TElGZipWriterHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_get_CompressionLevel(TElGZipWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_set_CompressionLevel(TElGZipWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_get_WorkFactor(TElGZipWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_set_WorkFactor(TElGZipWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_get_OnCompressionStreamNeeded(TElGZipWriterHandle _Handle, TSBGZipCompressionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_set_OnCompressionStreamNeeded(TElGZipWriterHandle _Handle, TSBGZipCompressionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElGZipWriter_Create(TComponentHandle AOwner, TElGZipWriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELGZIPWRITER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElGZipDecompressingUnit;
typedef TElGZipDecompressingUnit ElGZipDecompressingUnit;
class TElGZipCompressingUnit;
typedef TElGZipCompressingUnit ElGZipCompressingUnit;
class TElGZipFileAttributes;
class TElGZipReader;
typedef TElGZipReader ElGZipReader;
class TElGZipWriter;
typedef TElGZipWriter ElGZipWriter;

#ifdef SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT
class TElGZipDecompressingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElGZipDecompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_CRC32();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_CRC32, TElGZipDecompressingUnit, CRC32);

		TElGZipDecompressingUnit(TElGZipDecompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElGZipDecompressingUnit();

};
#endif /* SB_USE_CLASS_TELGZIPDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT
class TElGZipCompressingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElGZipCompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElGZipCompressingUnit, CompressionLevel);

		virtual uint32_t get_CRC32();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_CRC32, TElGZipCompressingUnit, CRC32);

		TElGZipCompressingUnit(TElGZipCompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElGZipCompressingUnit();

};
#endif /* SB_USE_CLASS_TELGZIPCOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
class TElGZipFileAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElGZipFileAttributes)
	public:
		void Assign(TElGZipFileAttributes &Source);

		void Assign(TElGZipFileAttributes *Source);

		void AssignTo(TElGZipFileAttributes &Dest);

		void AssignTo(TElGZipFileAttributes *Dest);

		virtual void get_FileName(std::string &OutResult);

		virtual void set_FileName(const std::string &Value);

		virtual int64_t get_ModifyTime();

		virtual void set_ModifyTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModifyTime, set_ModifyTime, TElGZipFileAttributes, ModifyTime);

		virtual int64_t get_FileSize();

		virtual void set_FileSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileSize, set_FileSize, TElGZipFileAttributes, FileSize);

		virtual uint8_t get_Flag();

		virtual void set_Flag(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Flag, set_Flag, TElGZipFileAttributes, Flag);

		virtual uint8_t get_ExtraFlag();

		virtual void set_ExtraFlag(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_ExtraFlag, set_ExtraFlag, TElGZipFileAttributes, ExtraFlag);

		virtual uint32_t get_CRC16();

		virtual void set_CRC16(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CRC16, set_CRC16, TElGZipFileAttributes, CRC16);

		virtual uint32_t get_CRC32();

		virtual void set_CRC32(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CRC32, set_CRC32, TElGZipFileAttributes, CRC32);

		virtual void get_ExtraField(std::vector<uint8_t> &OutResult);

		virtual void set_ExtraField(const std::vector<uint8_t> &Value);

		virtual void get_Comment(std::string &OutResult);

		virtual void set_Comment(const std::string &Value);

		virtual TSBGZipFileSystem get_FileSystem();

		virtual void set_FileSystem(TSBGZipFileSystem Value);

		SB_DECLARE_PROPERTY(TSBGZipFileSystem, get_FileSystem, set_FileSystem, TElGZipFileAttributes, FileSystem);

		virtual uint8_t get_FileSystemCode();

		virtual void set_FileSystemCode(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_FileSystemCode, set_FileSystemCode, TElGZipFileAttributes, FileSystemCode);

		virtual bool get_HasText();

		virtual void set_HasText(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasText, set_HasText, TElGZipFileAttributes, HasText);

		virtual bool get_HasCRC();

		virtual void set_HasCRC(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasCRC, set_HasCRC, TElGZipFileAttributes, HasCRC);

		virtual bool get_HasExtra();

		virtual void set_HasExtra(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasExtra, set_HasExtra, TElGZipFileAttributes, HasExtra);

		virtual bool get_HasName();

		virtual void set_HasName(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasName, set_HasName, TElGZipFileAttributes, HasName);

		virtual bool get_HasComment();

		virtual void set_HasComment(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasComment, set_HasComment, TElGZipFileAttributes, HasComment);

		TElGZipFileAttributes(TElGZipFileAttributesHandle handle, TElOwnHandle ownHandle);

		TElGZipFileAttributes();

};
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELGZIPREADER
class TElGZipReader: public TElBaseArchive
{
	private:
		SB_DISABLE_COPY(TElGZipReader)
#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
		TElGZipFileAttributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */
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

		void Extract(const std::string &OutputPath, const std::string &OutputFile);

#ifdef SB_USE_CLASS_TSTREAM
		void Extract(TStream &Stream);

		void Extract(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool CheckArchive();

		virtual int64_t get_CompressedSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CompressedSize, TElGZipReader, CompressedSize);

#ifdef SB_USE_CLASS_TELGZIPFILEATTRIBUTES
		virtual TElGZipFileAttributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElGZipFileAttributes*, get_Attributes, TElGZipReader, Attributes);
#endif /* SB_USE_CLASS_TELGZIPFILEATTRIBUTES */

		virtual bool get_IgnoreArchiveErrors();

		virtual void set_IgnoreArchiveErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreArchiveErrors, set_IgnoreArchiveErrors, TElGZipReader, IgnoreArchiveErrors);

		virtual void get_FilenamesCharset(std::string &OutResult);

		virtual void set_FilenamesCharset(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElGZipReader, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual void get_OnExtractionStreamNeeded(TSBGZipExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStreamNeeded(TSBGZipExtractionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBGZipProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBGZipProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnUserActionNeeded(TSBGZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUserActionNeeded(TSBGZipUserActionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnArchiveError(TSBGZipArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArchiveError(TSBGZipArchiveErrorEvent pMethodValue, void * pDataValue);

		TElGZipReader(TElGZipReaderHandle handle, TElOwnHandle ownHandle);

		explicit TElGZipReader(TComponent &AOwner);

		explicit TElGZipReader(TComponent *AOwner);

		virtual ~TElGZipReader();

};
#endif /* SB_USE_CLASS_TELGZIPREADER */

#ifdef SB_USE_CLASS_TELGZIPWRITER
class TElGZipWriter: public TElGZipReader
{
	private:
		SB_DISABLE_COPY(TElGZipWriter)
	public:
		void CreateArchive();

		virtual void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Open(TStream &Stream);

		virtual void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool Add(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		bool Add(TStream &Stream, const std::string &FileName);

		bool Add(TStream *Stream, const std::string &FileName);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Compress(TStream &Destination);

		virtual void Compress(TStream *Destination);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Compress(const std::string &Destination);

		virtual void Compress();

		virtual void Close();

		virtual bool get_NewArchive();

		SB_DECLARE_PROPERTY_GET(bool, get_NewArchive, TElGZipWriter, NewArchive);

		virtual int64_t get_FileSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_FileSize, TElGZipWriter, FileSize);

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElGZipWriter, CompressionLevel);

		virtual uint32_t get_WorkFactor();

		virtual void set_WorkFactor(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WorkFactor, set_WorkFactor, TElGZipWriter, WorkFactor);

		virtual void get_OnCompressionStreamNeeded(TSBGZipCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStreamNeeded(TSBGZipCompressionStreamNeededEvent pMethodValue, void * pDataValue);

		TElGZipWriter(TElGZipWriterHandle handle, TElOwnHandle ownHandle);

		explicit TElGZipWriter(TComponent &AOwner);

		explicit TElGZipWriter(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELGZIPWRITER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBARCGZIP */

