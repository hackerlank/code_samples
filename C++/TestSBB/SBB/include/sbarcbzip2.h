#ifndef __INC_SBARCBZIP2
#define __INC_SBARCBZIP2

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#include "sbstrutils.h"
#include "sbarcbase.h"
#include "sbbzip2.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_BZIP2_BUFFER_SIZE 	65536
#define SB_BZIP_EVENT_EXTRACTION_FAILED 	4097
#define SB_BZIP_EVENT_FILE_ALREADY_EXISTS 	4098
#define SB_BZIP_EVENT_CANNOT_CREATE_FILE 	4099
#define SB_BZIP_EVENT_DIR_ALREADY_EXISTS 	4100
#define SB_BZIP_EVENT_FILE_ALREADY_ADDED 	4101
#define SB_BZIP_EVENT_CRC_MISMATCH 	4102
#define SB_BZIP_ACTION_IGNORE 	4097
#define SB_BZIP_ACTION_ABORT 	4098
#define SB_BZIP_ACTION_RETRY 	4099
#define SB_BZIP_ACTION_SKIP 	4100
#define SB_SFileAlreadyExists 	"File already exists"
#define SB_SInvalidPath 	"Invalid path"
#define SB_SNotExtractNewArchive 	"Can\'t extract from new archive"
#define SB_SCannotCreateFile 	"Cannot create file"
#define SB_SInvalidActionRequested 	"Invalid action requested"
#define SB_SInvalidOutputFile 	"Not correctly set output file"
#define SB_SNoOutputStream 	"No output stream"
#define SB_SInvalidCompressionLevel 	"Invalid compression level"
#define SB_SInvalidWorkFactor 	"Invalid work factor"
#define SB_SArchiveAlreadyHaveFile 	"Archive already contain a file"
#define SB_SNoInputForCompression 	"No input for compression"
#define SB_SArchiveNotOpened 	"Archive is not opened"
#define SB_SArchiveNotAssign 	"For the new archive must be specified file or stream"

typedef TElClassHandle TElBZip2DecompressingUnitHandle;

typedef TElBZip2DecompressingUnitHandle ElBZip2DecompressingUnitHandle;

typedef TElClassHandle TElBZip2CompressingUnitHandle;

typedef TElBZip2CompressingUnitHandle ElBZip2CompressingUnitHandle;

typedef TElClassHandle TElBZip2ReaderHandle;

typedef TElBZip2ReaderHandle ElBZip2ReaderHandle;

typedef TElClassHandle TElBZip2WriterHandle;

typedef TElBZip2WriterHandle ElBZip2WriterHandle;

typedef void (SB_CALLBACK *TSBBzip2ProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Processed, int64_t Total, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBBzip2UserActionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ForEvent, const char * pcDescription, int32_t szDescription, int32_t * UserAction);

typedef void (SB_CALLBACK *TSBBZip2ExtractionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBBZip2CompressionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBBZip2ArchiveErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, const char * pcErrorMessage, int32_t szErrorMessage, int8_t * TryContinue);

#ifdef SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_InitializeProcessing(TElBZip2DecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_ProcessBlock(TElBZip2DecompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_FinalizeProcessing(TElBZip2DecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_get_Verbosity(TElBZip2DecompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_set_Verbosity(TElBZip2DecompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_get_Small(TElBZip2DecompressingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_set_Small(TElBZip2DecompressingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2DecompressingUnit_Create(TElBZip2DecompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_InitializeProcessing(TElBZip2CompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_ProcessBlock(TElBZip2CompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_FinalizeProcessing(TElBZip2CompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_get_CompressionLevel(TElBZip2CompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_set_CompressionLevel(TElBZip2CompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_get_Verbosity(TElBZip2CompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_set_Verbosity(TElBZip2CompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_get_WorkFactor(TElBZip2CompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_set_WorkFactor(TElBZip2CompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2CompressingUnit_Create(TElBZip2CompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2READER
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Open(TElBZip2ReaderHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Open_1(TElBZip2ReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Close(TElBZip2ReaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Extract(TElBZip2ReaderHandle _Handle, const char * pcOutputFile, int32_t szOutputFile);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Extract_1(TElBZip2ReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_CompressedSize(TElBZip2ReaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_Small(TElBZip2ReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_Small(TElBZip2ReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_IgnoreArchiveErrors(TElBZip2ReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_IgnoreArchiveErrors(TElBZip2ReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_FileSystemAdapter(TElBZip2ReaderHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_FileSystemAdapter(TElBZip2ReaderHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_OnExtractionStreamNeeded(TElBZip2ReaderHandle _Handle, TSBBZip2ExtractionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_OnExtractionStreamNeeded(TElBZip2ReaderHandle _Handle, TSBBZip2ExtractionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_OnProgress(TElBZip2ReaderHandle _Handle, TSBBzip2ProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_OnProgress(TElBZip2ReaderHandle _Handle, TSBBzip2ProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_OnUserActionNeeded(TElBZip2ReaderHandle _Handle, TSBBzip2UserActionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_OnUserActionNeeded(TElBZip2ReaderHandle _Handle, TSBBzip2UserActionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_get_OnArchiveError(TElBZip2ReaderHandle _Handle, TSBBZip2ArchiveErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_set_OnArchiveError(TElBZip2ReaderHandle _Handle, TSBBZip2ArchiveErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Reader_Create(TComponentHandle AOwner, TElBZip2ReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELBZIP2READER */

#ifdef SB_USE_CLASS_TELBZIP2WRITER
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_CreateArchive(TElBZip2WriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Open(TElBZip2WriterHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Open_1(TElBZip2WriterHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Add(TElBZip2WriterHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Add_1(TElBZip2WriterHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Compress(TElBZip2WriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Compress_1(TElBZip2WriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Compress_2(TElBZip2WriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Close(TElBZip2WriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_get_NewArchive(TElBZip2WriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_get_FileSize(TElBZip2WriterHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_get_CompressionLevel(TElBZip2WriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_set_CompressionLevel(TElBZip2WriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_get_WorkFactor(TElBZip2WriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_set_WorkFactor(TElBZip2WriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_get_OnCompressionStreamNeeded(TElBZip2WriterHandle _Handle, TSBBZip2CompressionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_set_OnCompressionStreamNeeded(TElBZip2WriterHandle _Handle, TSBBZip2CompressionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElBZip2Writer_Create(TComponentHandle AOwner, TElBZip2WriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELBZIP2WRITER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBZip2DecompressingUnit;
typedef TElBZip2DecompressingUnit ElBZip2DecompressingUnit;
class TElBZip2CompressingUnit;
typedef TElBZip2CompressingUnit ElBZip2CompressingUnit;
class TElBZip2Reader;
typedef TElBZip2Reader ElBZip2Reader;
class TElBZip2Writer;
typedef TElBZip2Writer ElBZip2Writer;

#ifdef SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT
class TElBZip2DecompressingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElBZip2DecompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_Verbosity();

		virtual void set_Verbosity(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Verbosity, set_Verbosity, TElBZip2DecompressingUnit, Verbosity);

		virtual bool get_Small();

		virtual void set_Small(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Small, set_Small, TElBZip2DecompressingUnit, Small);

		TElBZip2DecompressingUnit(TElBZip2DecompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElBZip2DecompressingUnit();

};
#endif /* SB_USE_CLASS_TELBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT
class TElBZip2CompressingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElBZip2CompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElBZip2CompressingUnit, CompressionLevel);

		virtual uint32_t get_Verbosity();

		virtual void set_Verbosity(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Verbosity, set_Verbosity, TElBZip2CompressingUnit, Verbosity);

		virtual uint32_t get_WorkFactor();

		virtual void set_WorkFactor(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WorkFactor, set_WorkFactor, TElBZip2CompressingUnit, WorkFactor);

		TElBZip2CompressingUnit(TElBZip2CompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElBZip2CompressingUnit();

};
#endif /* SB_USE_CLASS_TELBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELBZIP2READER
class TElBZip2Reader: public TElBaseArchive
{
	private:
		SB_DISABLE_COPY(TElBZip2Reader)
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

		void Extract(const std::string &OutputFile);

#ifdef SB_USE_CLASS_TSTREAM
		void Extract(TStream &Stream);

		void Extract(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int64_t get_CompressedSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_CompressedSize, TElBZip2Reader, CompressedSize);

		virtual bool get_Small();

		virtual void set_Small(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Small, set_Small, TElBZip2Reader, Small);

		virtual bool get_IgnoreArchiveErrors();

		virtual void set_IgnoreArchiveErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreArchiveErrors, set_IgnoreArchiveErrors, TElBZip2Reader, IgnoreArchiveErrors);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElBZip2Reader, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual void get_OnExtractionStreamNeeded(TSBBZip2ExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStreamNeeded(TSBBZip2ExtractionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBBzip2ProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBBzip2ProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnUserActionNeeded(TSBBzip2UserActionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUserActionNeeded(TSBBzip2UserActionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnArchiveError(TSBBZip2ArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArchiveError(TSBBZip2ArchiveErrorEvent pMethodValue, void * pDataValue);

		TElBZip2Reader(TElBZip2ReaderHandle handle, TElOwnHandle ownHandle);

		explicit TElBZip2Reader(TComponent &AOwner);

		explicit TElBZip2Reader(TComponent *AOwner);

		virtual ~TElBZip2Reader();

};
#endif /* SB_USE_CLASS_TELBZIP2READER */

#ifdef SB_USE_CLASS_TELBZIP2WRITER
class TElBZip2Writer: public TElBZip2Reader
{
	private:
		SB_DISABLE_COPY(TElBZip2Writer)
	public:
		void CreateArchive();

		virtual void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Open(TStream &Stream);

		virtual void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool Add(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		bool Add(TStream &Stream);

		bool Add(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Compress(TStream &Destination);

		virtual void Compress(TStream *Destination);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Compress(const std::string &Destination);

		virtual void Compress();

		virtual void Close();

		virtual bool get_NewArchive();

		SB_DECLARE_PROPERTY_GET(bool, get_NewArchive, TElBZip2Writer, NewArchive);

		virtual int64_t get_FileSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_FileSize, TElBZip2Writer, FileSize);

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElBZip2Writer, CompressionLevel);

		virtual uint32_t get_WorkFactor();

		virtual void set_WorkFactor(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WorkFactor, set_WorkFactor, TElBZip2Writer, WorkFactor);

		virtual void get_OnCompressionStreamNeeded(TSBBZip2CompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStreamNeeded(TSBBZip2CompressionStreamNeededEvent pMethodValue, void * pDataValue);

		TElBZip2Writer(TElBZip2WriterHandle handle, TElOwnHandle ownHandle);

		explicit TElBZip2Writer(TComponent &AOwner);

		explicit TElBZip2Writer(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELBZIP2WRITER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBARCBZIP2 */

