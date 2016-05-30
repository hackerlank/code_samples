#ifndef __INC_SBARCZIP
#define __INC_SBARCZIP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbdictionary.h"
#include "sbstrutils.h"
#include "sbchsconv.h"
#include "sbstreams.h"
#include "sbarcbase.h"
#include "sbzlib.h"
#include "sbbzip2.h"
#include "sbasn1tree.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbpublickeycrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbcrc.h"
#include "sbhashfunction.h"
#include "sbsymmetriccrypto.h"
#include "sbzipentities.h"
#include "sbziputils.h"
#include "sbalgorithmidentifier.h"
#include "sbcustomfsadapter.h"
#include "sbdiskfsadapter.h"
#ifndef SB_WINCE_OR_NOT_WINDOWS
#include "sbzipsfxmaker.h"
#endif
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_ZIP 	122880
#define SB_ERROR_ZIP_ERROR_FLAG 	2048
#define SB_ZIP_ERROR_BASE 	124928
#define SB_ZIP_ERROR_INTERNAL_ERROR 	124929
#define SB_ZIP_ERROR_NO_OUTPUT_STREAM 	124930
#define SB_ZIP_ERROR_INVALID_PROPERTY_VALUE 	124931
#define SB_ZIP_ERROR_ENC_METHOD_NOT_SUPPORTED 	124932
#define SB_ZIP_ERROR_COMP_ALG_NOT_SUPPORTED 	124933
#define SB_ZIP_ERROR_INVALID_STRUCTURE 	124934
#define SB_ZIP_ERROR_NO_INPUT 	124935
#define SB_ZIP_ERROR_INVALID_PATH 	124936
#define SB_ZIP_ERROR_INVALID_PASSWORD 	124937
#define SB_ZIP_ERROR_INVALID_RECIPIENT_KEY 	124938
#define SB_ZIP_ERROR_NO_ENC_INFO 	124939
#define SB_ZIP_ERROR_NO_DEC_PASSWORD 	124940
#define SB_ZIP_ERROR_NO_DEC_CERT 	124941
#define SB_ZIP_ERROR_INV_KEY_SIZE 	124942
#define SB_ZIP_ERROR_DEC_FAILED 	124943
#define SB_ZIP_ERROR_INVALID_PARAMS 	124944
#define SB_ZIP_ERROR_INVALID_ACTION 	124945
#define SB_ZIP_ERROR_FILE_EXISTS 	124946
#define SB_ZIP_ERROR_CANT_CREATE_FILE 	124947
#define SB_ZIP_ERROR_INVALID_MAC 	124948
#define SB_ZIP_ERROR_NO_SIGNER_CERT 	124949
#define SB_ZIP_ERROR_INVALID_INDEX 	124950
#define SB_ZIP_ERROR_DIRECTORY_EXISTS 	124951
#define SB_ZIP_ERROR_ARCHIVE_NOT_OPENED 	124952
#define SB_ZIP_ERROR_FILE_ALREADY_IN_ARCHIVE 	124953
#define SB_ZIP_ERROR_PARENT_NOT_DIRECTORY 	124954
#define SB_ZIP_ERROR_INVALID_METHOD_SEQUENCE 	124955
#define SB_ZIP_ERROR_NO_OLD_ENC_IN_FIPS 	124956
#define SB_ZIP_ERROR_INVALID_PARAMETER 	124957
#define SB_ZIP_ERROR_CANT_ADD_MIME_ENTRY 	124958
#define SB_ZIP_ERROR_INVALID_SIGNATURE_DATA 	124959
#define SB_ZIP_ERROR_INVALID_ENCRYPTED_DATA 	124960
#define SB_ZIP_ERROR_OPERATION_CANCELLED 	124968
#define SB_ZIP_EVENT_EXTRACTION_FAILED 	4097
#define SB_ZIP_EVENT_CRC_MISMATCH 	4098
#define SB_ZIP_EVENT_INVALID_PASSWORD 	4099
#define SB_ZIP_EVENT_FILE_ALREADY_EXISTS 	4100
#define SB_ZIP_EVENT_CANNOT_CREATE_FILE 	4101
#define SB_ZIP_EVENT_DIR_ALREADY_EXISTS 	4102
#define SB_ZIP_EVENT_FILE_ALREADY_ADDED 	4103
#define SB_ZIP_ACTION_IGNORE 	4097
#define SB_ZIP_ACTION_ABORT 	4098
#define SB_ZIP_ACTION_RETRY 	4099
#define SB_ZIP_ACTION_SKIP 	4100

typedef TElClassHandle TElZipArchiveDirectoryEntryHandle;

typedef TElClassHandle TElZipDosFileAttributesHandle;

typedef TElZipDosFileAttributesHandle ElZipDosFileAttributesHandle;

typedef TElClassHandle TElZipUnixFileAttributesHandle;

typedef TElClassHandle TElZipStrongEncryptionInfoHandle;

typedef TElZipStrongEncryptionInfoHandle ElZipStrongEncryptionInfoHandle;

typedef TElClassHandle TElZipStrongEncryptionSignatureInfoHandle;

typedef TElZipStrongEncryptionSignatureInfoHandle ElZipStrongEncryptionSignatureInfoHandle;

typedef TElZipArchiveDirectoryEntryHandle ElZipArchiveDirectoryEntryHandle;

typedef TElClassHandle TElZipProcessingUnitHandle;

typedef TElZipProcessingUnitHandle ElZipProcessingUnitHandle;

typedef TElClassHandle TElZipStoredProcessingUnitHandle;

typedef TElZipStoredProcessingUnitHandle ElZipStoredProcessingUnitHandle;

typedef TElClassHandle TElZipDeflateDecompressingUnitHandle;

typedef TElZipDeflateDecompressingUnitHandle ElZipDeflateDecompressingUnitHandle;

typedef TElClassHandle TElZipDeflateCompressingUnitHandle;

typedef TElZipDeflateCompressingUnitHandle ElZipDeflateCompressingUnitHandle;

typedef TElClassHandle TElZipBZip2DecompressingUnitHandle;

typedef TElZipBZip2DecompressingUnitHandle ElZipBZip2DecompressingUnitHandle;

typedef TElClassHandle TElZipBZip2CompressingUnitHandle;

typedef TElZipBZip2CompressingUnitHandle ElZipBZip2CompressingUnitHandle;

typedef TElClassHandle TElZipOldStyleEncryptingUnitHandle;

typedef TElZipOldStyleEncryptingUnitHandle ElZipOldStyleEncryptingUnitHandle;

typedef TElClassHandle TElZipOldStyleDecryptingUnitHandle;

typedef TElZipOldStyleDecryptingUnitHandle ElZipOldStyleDecryptingUnitHandle;

typedef TElClassHandle TElZipStrongEncryptionBaseUnitHandle;

typedef TElZipStrongEncryptionBaseUnitHandle ElZipStrongEncryptionBaseUnitHandle;

typedef TElClassHandle TElZipStrongEncryptionEncryptingUnitHandle;

typedef TElZipStrongEncryptionEncryptingUnitHandle ElZipStrongEncryptionEncryptingUnitHandle;

typedef TElClassHandle TElZipStrongEncryptionDecryptingUnitHandle;

typedef TElZipStrongEncryptionDecryptingUnitHandle ElZipStrongEncryptionDecryptingUnitHandle;

typedef TElClassHandle TElZipStrongEncryptionHashingUnitHandle;

typedef TElZipStrongEncryptionHashingUnitHandle ElZipStrongEncryptionHashingUnitHandle;

typedef TElClassHandle TElZipWinZipAesBaseUnitHandle;

typedef TElZipWinZipAesBaseUnitHandle ElZipWinZipAesBaseUnitHandle;

typedef TElClassHandle TElZipWinZipAesDecryptingUnitHandle;

typedef TElZipWinZipAesDecryptingUnitHandle ElZipWinZipAesDecryptingUnitHandle;

typedef TElClassHandle TElZipWinZipAesEncryptingUnitHandle;

typedef TElZipWinZipAesEncryptingUnitHandle ElZipWinZipAesEncryptingUnitHandle;

typedef TElClassHandle TElZipReaderHandle;

typedef TElZipReaderHandle ElZipReaderHandle;

typedef TElClassHandle TElZipWriterHandle;

typedef TElZipWriterHandle ElZipWriterHandle;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef uint8_t TSBZIPStubSourceRaw;

typedef enum
{
	_ssStream = 0,
	_ssFile = 1,
	_ssResource = 2
} TSBZIPStubSource;

typedef void (SB_CALLBACK *TSBZIPGetStubStreamEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream, int8_t * FreeStub);
#endif

typedef void (SB_CALLBACK *TSBZipExtractionFinishedEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry);

typedef void (SB_CALLBACK *TSBZipExtractionMakeDirectoryEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry);

typedef void (SB_CALLBACK *TSBZipPrivateKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, void * Param, TElX509CertificateHandle Certificate);

typedef void (SB_CALLBACK *TSBZipPasswordNeededEvent)(void * _ObjectData, TObjectHandle Sender, void * Param, char * pcPassword, int32_t * szPassword, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBZipProgressEvent)(void * _ObjectData, TObjectHandle Sender, uint64_t Processed, uint64_t Total, uint64_t OverallProcessed, uint64_t OverallTotal, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBZipExtractionStartEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry, int8_t * Extract);

typedef void (SB_CALLBACK *TSBZipUserActionNeededEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ForEvent, const char * pcDescription, int32_t szDescription, void * Param, int32_t * UserAction);

typedef void (SB_CALLBACK *TSBZipExtractionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBZipCompressionStartEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry, int8_t * Compress);

typedef void (SB_CALLBACK *TSBZipCompressionStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBZipCompressionFinishedEvent)(void * _ObjectData, TObjectHandle Sender, TElZipArchiveDirectoryEntryHandle Entry);

typedef uint8_t TSBZipUnixFileTypeRaw;

typedef enum
{
	uftNamedPipe = 0,
	uftCharacterSpecial = 1,
	uftDirectory = 2,
	uftBlockSpecial = 3,
	uftRegularFile = 4,
	uftSymbolicLink = 5,
	uftSocket = 6
} TSBZipUnixFileType;

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_Clear(TElZipArchiveDirectoryEntryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_AddEntry(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_AddNewEntry(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_RemoveEntry(TElZipArchiveDirectoryEntryHandle _Handle, TElZipArchiveDirectoryEntryHandle Entry, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_RemoveEntry_1(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_RemoveEntry_2(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t CaseSensitive, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_ClearEntries(TElZipArchiveDirectoryEntryHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_RemoveEntries(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcFilter, int32_t szFilter, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_EntryWithName(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAName, int32_t szAName, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_EntryWithName_1(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAName, int32_t szAName, int8_t CaseSensitive, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_EntryWithPath(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_EntryWithPath_1(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcAPath, int32_t szAPath, int8_t CaseSensitive, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_LocalHeaderLoaded(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_CentralHeaderLoaded(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_StrongEncryptionInfoLoaded(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_StrongEncryptionInfoLoaded(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Parent(TElZipArchiveDirectoryEntryHandle _Handle, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Entries(TElZipArchiveDirectoryEntryHandle _Handle, int32_t Index, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Path(TElZipArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Flags(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_Flags(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_CompressionMethod(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_CompressionMethod(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_CompressionLevel(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_CompressionLevel(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_CRC32(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_CRC32(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_VersionToExtract(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_VersionToExtract(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_VersionMadeBy(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_VersionMadeBy(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_FileAttributesCompatibility(TElZipArchiveDirectoryEntryHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_FileAttributesCompatibility(TElZipArchiveDirectoryEntryHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Encrypted(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_Encrypted(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Signed(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_StrongEncryption(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_StrongEncryption(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_WinZipEncryption(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_WinZipEncryption(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_WinZipEncryptionVersion(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_WinZipEncryptionVersion(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_WinZipAesKeySize(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_WinZipAesKeySize(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_LocalHeaderMasked(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_LocalHeaderMasked(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_LocalHeaderOffset(TElZipArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_LocalHeaderOffset(TElZipArchiveDirectoryEntryHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_DataOffset(TElZipArchiveDirectoryEntryHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_DiskNumberStart(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_DiskNumberStart(TElZipArchiveDirectoryEntryHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_StrongEncryptionInfo(TElZipArchiveDirectoryEntryHandle _Handle, TElZipStrongEncryptionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_SignatureCount(TElZipArchiveDirectoryEntryHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Signatures(TElZipArchiveDirectoryEntryHandle _Handle, int32_t Index, TElZipStrongEncryptionSignatureInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Process(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_Process(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_Attributes(TElZipArchiveDirectoryEntryHandle _Handle, TElZipDosFileAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_UnixAttributes(TElZipArchiveDirectoryEntryHandle _Handle, TElZipUnixFileAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_ExtractionPath(TElZipArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_ExtractionPath(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_ExtractionStream(TElZipArchiveDirectoryEntryHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_ExtractionStream(TElZipArchiveDirectoryEntryHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_InputPath(TElZipArchiveDirectoryEntryHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_InputPath(TElZipArchiveDirectoryEntryHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_InputStream(TElZipArchiveDirectoryEntryHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_InputStream(TElZipArchiveDirectoryEntryHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_InputData(TElZipArchiveDirectoryEntryHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_InputData(TElZipArchiveDirectoryEntryHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_get_FreeInputStream(TElZipArchiveDirectoryEntryHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_set_FreeInputStream(TElZipArchiveDirectoryEntryHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_Create(TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipArchiveDirectoryEntry_Create_1(TElBaseArchiveHandle Owner, TElZipArchiveDirectoryEntryHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_RawAttributes(TElZipDosFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_RawAttributes(TElZipDosFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_RawLastModTime(TElZipDosFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_RawLastModTime(TElZipDosFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_RawLastModDate(TElZipDosFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_RawLastModDate(TElZipDosFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_ReadOnly(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_ReadOnly(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_Hidden(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_Hidden(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_System(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_System(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_VolumeLabel(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_VolumeLabel(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_Directory(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_Directory(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_Archive(TElZipDosFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_Archive(TElZipDosFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_get_ModTime(TElZipDosFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_set_ModTime(TElZipDosFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDosFileAttributes_Create(TElZipDosFileAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_RawAttributes(TElZipUnixFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_RawAttributes(TElZipUnixFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_FileType(TElZipUnixFileAttributesHandle _Handle, TSBZipUnixFileTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_FileType(TElZipUnixFileAttributesHandle _Handle, TSBZipUnixFileTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_SUID(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_SUID(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_SGID(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_SGID(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_StickyBit(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_StickyBit(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OwnerRead(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OwnerRead(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OwnerWrite(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OwnerWrite(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OwnerExecute(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OwnerExecute(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_GroupRead(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_GroupRead(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_GroupWrite(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_GroupWrite(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_GroupExecute(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_GroupExecute(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OtherRead(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OtherRead(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OtherWrite(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OtherWrite(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_OtherExecute(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_OtherExecute(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_Permissions(TElZipUnixFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_Permissions(TElZipUnixFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_DOSAttributes(TElZipUnixFileAttributesHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_DOSAttributes(TElZipUnixFileAttributesHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_UIDAndGIDAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_UIDAndGIDAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_UID(TElZipUnixFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_UID(TElZipUnixFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_GID(TElZipUnixFileAttributesHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_GID(TElZipUnixFileAttributesHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_ModifyTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_ModifyTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_CreateTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_CreateTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_AccessTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_AccessTimeAvailable(TElZipUnixFileAttributesHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_ModifyTime(TElZipUnixFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_ModifyTime(TElZipUnixFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_CreateTime(TElZipUnixFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_CreateTime(TElZipUnixFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_get_AccessTime(TElZipUnixFileAttributesHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_set_AccessTime(TElZipUnixFileAttributesHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipUnixFileAttributes_Create(TElZipUnixFileAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_Assign(TElZipStrongEncryptionInfoHandle _Handle, TElZipStrongEncryptionInfoHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_EncryptionAlgorithm(TElZipStrongEncryptionInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_EncryptionAlgorithm(TElZipStrongEncryptionInfoHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_KeyLength(TElZipStrongEncryptionInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_KeyLength(TElZipStrongEncryptionInfoHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_UsePassword(TElZipStrongEncryptionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_UsePassword(TElZipStrongEncryptionInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_UseCertificates(TElZipStrongEncryptionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_UseCertificates(TElZipStrongEncryptionInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_UseOAEP(TElZipStrongEncryptionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_UseOAEP(TElZipStrongEncryptionInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_get_Use3DES(TElZipStrongEncryptionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_set_Use3DES(TElZipStrongEncryptionInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionInfo_Create(TElZipStrongEncryptionInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_Issuer(TElZipStrongEncryptionSignatureInfoHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_SerialNumber(TElZipStrongEncryptionSignatureInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_SignatureData(TElZipStrongEncryptionSignatureInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_HashAlgorithm(TElZipStrongEncryptionSignatureInfoHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_ContentHash(TElZipStrongEncryptionSignatureInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_set_ContentHash(TElZipStrongEncryptionSignatureInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_get_SigningCertificate(TElZipStrongEncryptionSignatureInfoHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_set_SigningCertificate(TElZipStrongEncryptionSignatureInfoHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionSignatureInfo_Create(TElZipStrongEncryptionSignatureInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELZIPPROCESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_InitializeProcessing(TElZipProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_FinalizeProcessing(TElZipProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_get_CryptoProviderManager(TElZipProcessingUnitHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_set_CryptoProviderManager(TElZipProcessingUnitHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_get_ProcessingEntry(TElZipProcessingUnitHandle _Handle, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_set_ProcessingEntry(TElZipProcessingUnitHandle _Handle, TElZipArchiveDirectoryEntryHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_get_CRC32(TElZipProcessingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipProcessingUnit_Create(TElZipProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipStoredProcessingUnit_InitializeProcessing(TElZipStoredProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStoredProcessingUnit_ProcessBlock(TElZipStoredProcessingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipStoredProcessingUnit_FinalizeProcessing(TElZipStoredProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStoredProcessingUnit_Create(TElZipStoredProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_InitializeProcessing(TElZipDeflateDecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_ProcessBlock(TElZipDeflateDecompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_FinalizeProcessing(TElZipDeflateDecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_get_Deflate64(TElZipDeflateDecompressingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_set_Deflate64(TElZipDeflateDecompressingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateDecompressingUnit_Create(TElZipDeflateDecompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_InitializeProcessing(TElZipDeflateCompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_ProcessBlock(TElZipDeflateCompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_FinalizeProcessing(TElZipDeflateCompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_get_CompressionLevel(TElZipDeflateCompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_set_CompressionLevel(TElZipDeflateCompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_get_Deflate64(TElZipDeflateCompressingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_set_Deflate64(TElZipDeflateCompressingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipDeflateCompressingUnit_Create(TElZipDeflateCompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2DecompressingUnit_InitializeProcessing(TElZipBZip2DecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2DecompressingUnit_ProcessBlock(TElZipBZip2DecompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2DecompressingUnit_FinalizeProcessing(TElZipBZip2DecompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2DecompressingUnit_Create(TElZipBZip2DecompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_InitializeProcessing(TElZipBZip2CompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_ProcessBlock(TElZipBZip2CompressingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_FinalizeProcessing(TElZipBZip2CompressingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_get_CompressionLevel(TElZipBZip2CompressingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_set_CompressionLevel(TElZipBZip2CompressingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipBZip2CompressingUnit_Create(TElZipBZip2CompressingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_InitializeProcessing(TElZipOldStyleEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_ProcessBlock(TElZipOldStyleEncryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_FinalizeProcessing(TElZipOldStyleEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_get_Password(TElZipOldStyleEncryptingUnitHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_set_Password(TElZipOldStyleEncryptingUnitHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_get_OnPasswordNeeded(TElZipOldStyleEncryptingUnitHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_set_OnPasswordNeeded(TElZipOldStyleEncryptingUnitHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleEncryptingUnit_Create(TElZipOldStyleEncryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_InitializeProcessing(TElZipOldStyleDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_ProcessBlock(TElZipOldStyleDecryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_FinalizeProcessing(TElZipOldStyleDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_get_Password(TElZipOldStyleDecryptingUnitHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_set_Password(TElZipOldStyleDecryptingUnitHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_get_HeaderRead(TElZipOldStyleDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_get_IgnorePasswordCheck(TElZipOldStyleDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_set_IgnorePasswordCheck(TElZipOldStyleDecryptingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_get_OnPasswordNeeded(TElZipOldStyleDecryptingUnitHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_set_OnPasswordNeeded(TElZipOldStyleDecryptingUnitHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipOldStyleDecryptingUnit_Create(TElZipOldStyleDecryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionBaseUnit_get_OnPasswordNeeded(TElZipStrongEncryptionBaseUnitHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionBaseUnit_set_OnPasswordNeeded(TElZipStrongEncryptionBaseUnitHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionBaseUnit_Create(TElZipProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_InitializeProcessing(TElZipStrongEncryptionEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_ProcessBlock(TElZipStrongEncryptionEncryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_FinalizeProcessing(TElZipStrongEncryptionEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_get_EncryptionAlgorithm(TElZipStrongEncryptionEncryptingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_set_EncryptionAlgorithm(TElZipStrongEncryptionEncryptingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_get_EncryptionKeySize(TElZipStrongEncryptionEncryptingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_set_EncryptionKeySize(TElZipStrongEncryptionEncryptingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_get_Password(TElZipStrongEncryptionEncryptingUnitHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_set_Password(TElZipStrongEncryptionEncryptingUnitHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_get_UseTripleDES(TElZipStrongEncryptionEncryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_set_UseTripleDES(TElZipStrongEncryptionEncryptingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionEncryptingUnit_Create(TElZipStrongEncryptionEncryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_InitializeProcessing(TElZipStrongEncryptionDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_ProcessBlock(TElZipStrongEncryptionDecryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_FinalizeProcessing(TElZipStrongEncryptionDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_FileCRC32(TElZipStrongEncryptionDecryptingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_set_FileCRC32(TElZipStrongEncryptionDecryptingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_FileSize(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_set_FileSize(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_Password(TElZipStrongEncryptionDecryptingUnitHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_set_Password(TElZipStrongEncryptionDecryptingUnitHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_OAEPUsed(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_TripleDESUsed(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_PasswordUsed(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_PublicKeyUsed(TElZipStrongEncryptionDecryptingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_Recipient(TElZipStrongEncryptionDecryptingUnitHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_set_Recipient(TElZipStrongEncryptionDecryptingUnitHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_get_OnPrivateKeyNeeded(TElZipStrongEncryptionDecryptingUnitHandle _Handle, TSBZipPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_set_OnPrivateKeyNeeded(TElZipStrongEncryptionDecryptingUnitHandle _Handle, TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionDecryptingUnit_Create(TElZipStrongEncryptionDecryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_ClearHashFunctions(TElZipStrongEncryptionHashingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_InitializeProcessing(TElZipStrongEncryptionHashingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_ProcessBlock(TElZipStrongEncryptionHashingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_FinalizeProcessing(TElZipStrongEncryptionHashingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_get_HashAlgorithm(TElZipStrongEncryptionHashingUnitHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_set_HashAlgorithm(TElZipStrongEncryptionHashingUnitHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_get_Hash(TElZipStrongEncryptionHashingUnitHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipStrongEncryptionHashingUnit_Create(TElZipStrongEncryptionHashingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_InitializeProcessing(TElZipWinZipAesBaseUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_get_Password(TElZipWinZipAesBaseUnitHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_set_Password(TElZipWinZipAesBaseUnitHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_get_OnPasswordNeeded(TElZipWinZipAesBaseUnitHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_set_OnPasswordNeeded(TElZipWinZipAesBaseUnitHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesBaseUnit_Create(TElZipWinZipAesBaseUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesDecryptingUnit_InitializeProcessing(TElZipWinZipAesDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesDecryptingUnit_ProcessBlock(TElZipWinZipAesDecryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesDecryptingUnit_FinalizeProcessing(TElZipWinZipAesDecryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesDecryptingUnit_Create(TElZipWinZipAesDecryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesEncryptingUnit_InitializeProcessing(TElZipWinZipAesEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesEncryptingUnit_ProcessBlock(TElZipWinZipAesEncryptingUnitHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesEncryptingUnit_FinalizeProcessing(TElZipWinZipAesEncryptingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWinZipAesEncryptingUnit_Create(TElZipWinZipAesEncryptingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPREADER
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Open(TElZipReaderHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Open_1(TElZipReaderHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Close(TElZipReaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Extract(TElZipReaderHandle _Handle, TElZipArchiveDirectoryEntryHandle Entry, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Extract_1(TElZipReaderHandle _Handle, TListHandle Entries, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Extract_2(TElZipReaderHandle _Handle, const char * pcMask, int32_t szMask, const char * pcOutputPath, int32_t szOutputPath);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_ExtractContents(TElZipReaderHandle _Handle, TElZipArchiveDirectoryEntryHandle Entry, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_ValidateSignature(TElZipReaderHandle _Handle, TElZipArchiveDirectoryEntryHandle Entry, int32_t SignatureIndex, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_ValidateDirectorySignature(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_CheckEntry(TElZipReaderHandle _Handle, TElZipArchiveDirectoryEntryHandle Entry, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_CheckArchive(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_DirectoryCompressed(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_DirectoryCompressed(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_DirectoryEncrypted(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_DirectoryEncrypted(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_Directory(TElZipReaderHandle _Handle, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_Password(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_Password(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_ArchiveComment(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_ArchiveComment(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_SigningCertificates(TElZipReaderHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_EncryptingCertificates(TElZipReaderHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_IgnorePasswordCheck(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_IgnorePasswordCheck(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_RestoreAttributes(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_RestoreAttributes(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_FilenamesCharset(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_FilenamesCharset(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_IgnoreArchiveErrors(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_IgnoreArchiveErrors(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_CaseSensitiveFilenames(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_CaseSensitiveFilenames(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_MimeType(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_SFXCopyright(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_SFXCopyright(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_SFXEnabled(TElZipReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_SFXEnabled(TElZipReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_SFXTitle(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_SFXTitle(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_StubName(TElZipReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_StubName(TElZipReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_StubSource(TElZipReaderHandle _Handle, TSBZIPStubSourceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_StubSource(TElZipReaderHandle _Handle, TSBZIPStubSourceRaw Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_FileSystemAdapter(TElZipReaderHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_FileSystemAdapter(TElZipReaderHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_CryptoProviderManager(TElZipReaderHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_CryptoProviderManager(TElZipReaderHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnExtractionStreamNeeded(TElZipReaderHandle _Handle, TSBZipExtractionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnExtractionStreamNeeded(TElZipReaderHandle _Handle, TSBZipExtractionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnExtractionMakeDirectory(TElZipReaderHandle _Handle, TSBZipExtractionMakeDirectoryEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnExtractionMakeDirectory(TElZipReaderHandle _Handle, TSBZipExtractionMakeDirectoryEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnProgress(TElZipReaderHandle _Handle, TSBZipProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnProgress(TElZipReaderHandle _Handle, TSBZipProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnExtractionStart(TElZipReaderHandle _Handle, TSBZipExtractionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnExtractionStart(TElZipReaderHandle _Handle, TSBZipExtractionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnExtractionFinished(TElZipReaderHandle _Handle, TSBZipExtractionFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnExtractionFinished(TElZipReaderHandle _Handle, TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnUserActionNeeded(TElZipReaderHandle _Handle, TSBZipUserActionNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnUserActionNeeded(TElZipReaderHandle _Handle, TSBZipUserActionNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnPasswordNeeded(TElZipReaderHandle _Handle, TSBZipPasswordNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnPasswordNeeded(TElZipReaderHandle _Handle, TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnPrivateKeyNeeded(TElZipReaderHandle _Handle, TSBZipPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnPrivateKeyNeeded(TElZipReaderHandle _Handle, TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_get_OnArchiveError(TElZipReaderHandle _Handle, TSBZipArchiveErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_set_OnArchiveError(TElZipReaderHandle _Handle, TSBZipArchiveErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipReader_Create(TComponentHandle AOwner, TElZipReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPREADER */

#ifdef SB_USE_CLASS_TELZIPWRITER
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_CreateArchive(TElZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_1(TElZipWriterHandle _Handle, const char * pcPath, int32_t szPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_2(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, TStreamHandle Stream, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_3(TElZipWriterHandle _Handle, TStreamHandle Stream, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_4(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_5(TElZipWriterHandle _Handle, TStreamHandle Stream, const char * pcFileName, int32_t szFileName, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_6(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, const uint8_t pBuf[], int32_t szBuf, int32_t StartIndex, int32_t Count, const char * pcFileName, int32_t szFileName, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Add_7(TElZipWriterHandle _Handle, const uint8_t pBuf[], int32_t szBuf, int32_t StartIndex, int32_t Count, const char * pcFileName, int32_t szFileName, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_AddDirContents(TElZipWriterHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_AddDirContents_1(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_AddDirContents_2(TElZipWriterHandle _Handle, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_AddDirContents_3(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_MakeDir(TElZipWriterHandle _Handle, const char * pcPath, int32_t szPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_MakeDir_1(TElZipWriterHandle _Handle, TElZipArchiveDirectoryEntryHandle Parent, const char * pcPath, int32_t szPath, TElZipArchiveDirectoryEntryHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Remove(TElZipWriterHandle _Handle, const char * pcMask, int32_t szMask);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_BeginCompression(TElZipWriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_BeginCompression_1(TElZipWriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_UpdateCompression(TElZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_EndCompression(TElZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Compress(TElZipWriterHandle _Handle, TStreamHandle Destination);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Compress_1(TElZipWriterHandle _Handle, const char * pcDestination, int32_t szDestination);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Compress_2(TElZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Close(TElZipWriterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_ReplaceMode(TElZipWriterHandle _Handle, TSBArcReplaceModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_ReplaceMode(TElZipWriterHandle _Handle, TSBArcReplaceModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_NewArchive(TElZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_CompressionAlgorithm(TElZipWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_CompressionAlgorithm(TElZipWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_CompressionLevel(TElZipWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_CompressionLevel(TElZipWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_Encrypt(TElZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_Encrypt(TElZipWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_StrongEncryption(TElZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_StrongEncryption(TElZipWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_WinZipEncryption(TElZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_WinZipEncryption(TElZipWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_WinZipAesKeySize(TElZipWriterHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_WinZipAesKeySize(TElZipWriterHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_StrongEncryptionInfo(TElZipWriterHandle _Handle, TElZipStrongEncryptionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_UseUTF8Filenames(TElZipWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_UseUTF8Filenames(TElZipWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_MimeType(TElZipWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_MimeType(TElZipWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_OnCompressionStreamNeeded(TElZipWriterHandle _Handle, TSBZipCompressionStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_OnCompressionStreamNeeded(TElZipWriterHandle _Handle, TSBZipCompressionStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_OnCompressionStart(TElZipWriterHandle _Handle, TSBZipCompressionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_OnCompressionStart(TElZipWriterHandle _Handle, TSBZipCompressionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_OnCompressionFinished(TElZipWriterHandle _Handle, TSBZipCompressionFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_OnCompressionFinished(TElZipWriterHandle _Handle, TSBZipCompressionFinishedEvent pMethodValue, void * pDataValue);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_get_OnGetStubStream(TElZipWriterHandle _Handle, TSBZIPGetStubStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_set_OnGetStubStream(TElZipWriterHandle _Handle, TSBZIPGetStubStreamEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElZipWriter_Create(TComponentHandle AOwner, TElZipWriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELZIPWRITER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElZipArchiveDirectoryEntry;
class TElZipDosFileAttributes;
typedef TElZipDosFileAttributes ElZipDosFileAttributes;
class TElZipUnixFileAttributes;
class TElZipStrongEncryptionInfo;
typedef TElZipStrongEncryptionInfo ElZipStrongEncryptionInfo;
class TElZipStrongEncryptionSignatureInfo;
typedef TElZipStrongEncryptionSignatureInfo ElZipStrongEncryptionSignatureInfo;
typedef TElZipArchiveDirectoryEntry ElZipArchiveDirectoryEntry;
class TElZipProcessingUnit;
typedef TElZipProcessingUnit ElZipProcessingUnit;
class TElZipStoredProcessingUnit;
typedef TElZipStoredProcessingUnit ElZipStoredProcessingUnit;
class TElZipDeflateDecompressingUnit;
typedef TElZipDeflateDecompressingUnit ElZipDeflateDecompressingUnit;
class TElZipDeflateCompressingUnit;
typedef TElZipDeflateCompressingUnit ElZipDeflateCompressingUnit;
class TElZipBZip2DecompressingUnit;
typedef TElZipBZip2DecompressingUnit ElZipBZip2DecompressingUnit;
class TElZipBZip2CompressingUnit;
typedef TElZipBZip2CompressingUnit ElZipBZip2CompressingUnit;
class TElZipOldStyleEncryptingUnit;
typedef TElZipOldStyleEncryptingUnit ElZipOldStyleEncryptingUnit;
class TElZipOldStyleDecryptingUnit;
typedef TElZipOldStyleDecryptingUnit ElZipOldStyleDecryptingUnit;
class TElZipStrongEncryptionBaseUnit;
typedef TElZipStrongEncryptionBaseUnit ElZipStrongEncryptionBaseUnit;
class TElZipStrongEncryptionEncryptingUnit;
typedef TElZipStrongEncryptionEncryptingUnit ElZipStrongEncryptionEncryptingUnit;
class TElZipStrongEncryptionDecryptingUnit;
typedef TElZipStrongEncryptionDecryptingUnit ElZipStrongEncryptionDecryptingUnit;
class TElZipStrongEncryptionHashingUnit;
typedef TElZipStrongEncryptionHashingUnit ElZipStrongEncryptionHashingUnit;
class TElZipWinZipAesBaseUnit;
typedef TElZipWinZipAesBaseUnit ElZipWinZipAesBaseUnit;
class TElZipWinZipAesDecryptingUnit;
typedef TElZipWinZipAesDecryptingUnit ElZipWinZipAesDecryptingUnit;
class TElZipWinZipAesEncryptingUnit;
typedef TElZipWinZipAesEncryptingUnit ElZipWinZipAesEncryptingUnit;
class TElZipReader;
typedef TElZipReader ElZipReader;
class TElZipWriter;
typedef TElZipWriter ElZipWriter;

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
class TElZipArchiveDirectoryEntry: public TElArchiveDirectoryEntry
{
	private:
		SB_DISABLE_COPY(TElZipArchiveDirectoryEntry)
		TElZipArchiveDirectoryEntry* _Inst_Parent;
		TElZipArchiveDirectoryEntry* _Inst_Entries;
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
		TElZipStrongEncryptionInfo* _Inst_StrongEncryptionInfo;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
		TElZipStrongEncryptionSignatureInfo* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */
#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
		TElZipDosFileAttributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
		TElZipUnixFileAttributes* _Inst_UnixAttributes;
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_ExtractionStream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_InputStream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void Clear();

		TElZipArchiveDirectoryEntryHandle AddEntry(const std::string &APath);

		TElZipArchiveDirectoryEntryHandle AddNewEntry(const std::string &APath);

		bool RemoveEntry(TElZipArchiveDirectoryEntry &Entry);

		bool RemoveEntry(TElZipArchiveDirectoryEntry *Entry);

		bool RemoveEntry(const std::string &APath);

		bool RemoveEntry(const std::string &APath, bool CaseSensitive);

		virtual void ClearEntries();

		int32_t RemoveEntries(const std::string &Filter);

		TElZipArchiveDirectoryEntryHandle EntryWithName(const std::string &AName);

		TElZipArchiveDirectoryEntryHandle EntryWithName(const std::string &AName, bool CaseSensitive);

		TElZipArchiveDirectoryEntryHandle EntryWithPath(const std::string &APath);

		TElZipArchiveDirectoryEntryHandle EntryWithPath(const std::string &APath, bool CaseSensitive);

		virtual bool get_LocalHeaderLoaded();

		SB_DECLARE_PROPERTY_GET(bool, get_LocalHeaderLoaded, TElZipArchiveDirectoryEntry, LocalHeaderLoaded);

		virtual bool get_CentralHeaderLoaded();

		SB_DECLARE_PROPERTY_GET(bool, get_CentralHeaderLoaded, TElZipArchiveDirectoryEntry, CentralHeaderLoaded);

		virtual bool get_StrongEncryptionInfoLoaded();

		virtual void set_StrongEncryptionInfoLoaded(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrongEncryptionInfoLoaded, set_StrongEncryptionInfoLoaded, TElZipArchiveDirectoryEntry, StrongEncryptionInfoLoaded);

		virtual TElZipArchiveDirectoryEntry* get_Parent();

		SB_DECLARE_PROPERTY_GET(TElZipArchiveDirectoryEntry*, get_Parent, TElZipArchiveDirectoryEntry, Parent);

		virtual TElZipArchiveDirectoryEntry* get_Entries(int32_t Index);

		virtual void get_Path(std::string &OutResult);

		virtual uint32_t get_Flags();

		virtual void set_Flags(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Flags, set_Flags, TElZipArchiveDirectoryEntry, Flags);

		virtual uint32_t get_CompressionMethod();

		virtual void set_CompressionMethod(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionMethod, set_CompressionMethod, TElZipArchiveDirectoryEntry, CompressionMethod);

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElZipArchiveDirectoryEntry, CompressionLevel);

		virtual uint32_t get_CRC32();

		virtual void set_CRC32(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CRC32, set_CRC32, TElZipArchiveDirectoryEntry, CRC32);

		virtual uint32_t get_VersionToExtract();

		virtual void set_VersionToExtract(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_VersionToExtract, set_VersionToExtract, TElZipArchiveDirectoryEntry, VersionToExtract);

		virtual uint32_t get_VersionMadeBy();

		virtual void set_VersionMadeBy(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_VersionMadeBy, set_VersionMadeBy, TElZipArchiveDirectoryEntry, VersionMadeBy);

		virtual uint8_t get_FileAttributesCompatibility();

		virtual void set_FileAttributesCompatibility(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_FileAttributesCompatibility, set_FileAttributesCompatibility, TElZipArchiveDirectoryEntry, FileAttributesCompatibility);

		virtual bool get_Encrypted();

		virtual void set_Encrypted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Encrypted, set_Encrypted, TElZipArchiveDirectoryEntry, Encrypted);

		virtual bool get_Signed();

		SB_DECLARE_PROPERTY_GET(bool, get_Signed, TElZipArchiveDirectoryEntry, Signed);

		virtual bool get_StrongEncryption();

		virtual void set_StrongEncryption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrongEncryption, set_StrongEncryption, TElZipArchiveDirectoryEntry, StrongEncryption);

		virtual bool get_WinZipEncryption();

		virtual void set_WinZipEncryption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WinZipEncryption, set_WinZipEncryption, TElZipArchiveDirectoryEntry, WinZipEncryption);

		virtual uint32_t get_WinZipEncryptionVersion();

		virtual void set_WinZipEncryptionVersion(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WinZipEncryptionVersion, set_WinZipEncryptionVersion, TElZipArchiveDirectoryEntry, WinZipEncryptionVersion);

		virtual uint32_t get_WinZipAesKeySize();

		virtual void set_WinZipAesKeySize(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WinZipAesKeySize, set_WinZipAesKeySize, TElZipArchiveDirectoryEntry, WinZipAesKeySize);

		virtual bool get_LocalHeaderMasked();

		virtual void set_LocalHeaderMasked(bool Value);

		SB_DECLARE_PROPERTY(bool, get_LocalHeaderMasked, set_LocalHeaderMasked, TElZipArchiveDirectoryEntry, LocalHeaderMasked);

		virtual int64_t get_LocalHeaderOffset();

		virtual void set_LocalHeaderOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_LocalHeaderOffset, set_LocalHeaderOffset, TElZipArchiveDirectoryEntry, LocalHeaderOffset);

		virtual int64_t get_DataOffset();

		SB_DECLARE_PROPERTY_GET(int64_t, get_DataOffset, TElZipArchiveDirectoryEntry, DataOffset);

		virtual uint32_t get_DiskNumberStart();

		virtual void set_DiskNumberStart(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_DiskNumberStart, set_DiskNumberStart, TElZipArchiveDirectoryEntry, DiskNumberStart);

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
		virtual TElZipStrongEncryptionInfo* get_StrongEncryptionInfo();

		SB_DECLARE_PROPERTY_GET(TElZipStrongEncryptionInfo*, get_StrongEncryptionInfo, TElZipArchiveDirectoryEntry, StrongEncryptionInfo);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElZipArchiveDirectoryEntry, SignatureCount);

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
		virtual TElZipStrongEncryptionSignatureInfo* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */

		virtual bool get_Process();

		virtual void set_Process(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Process, set_Process, TElZipArchiveDirectoryEntry, Process);

#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
		virtual TElZipDosFileAttributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElZipDosFileAttributes*, get_Attributes, TElZipArchiveDirectoryEntry, Attributes);
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
		virtual TElZipUnixFileAttributes* get_UnixAttributes();

		SB_DECLARE_PROPERTY_GET(TElZipUnixFileAttributes*, get_UnixAttributes, TElZipArchiveDirectoryEntry, UnixAttributes);
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */

		virtual void get_ExtractionPath(std::string &OutResult);

		virtual void set_ExtractionPath(const std::string &Value);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_ExtractionStream();

		virtual void set_ExtractionStream(TStream &Value);

		virtual void set_ExtractionStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_ExtractionStream, set_ExtractionStream, TElZipArchiveDirectoryEntry, ExtractionStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_InputPath(std::string &OutResult);

		virtual void set_InputPath(const std::string &Value);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_InputStream();

		virtual void set_InputStream(TStream &Value);

		virtual void set_InputStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_InputStream, set_InputStream, TElZipArchiveDirectoryEntry, InputStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_InputData(std::vector<uint8_t> &OutResult);

		virtual void set_InputData(const std::vector<uint8_t> &Value);

		virtual bool get_FreeInputStream();

		virtual void set_FreeInputStream(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FreeInputStream, set_FreeInputStream, TElZipArchiveDirectoryEntry, FreeInputStream);

		TElZipArchiveDirectoryEntry(TElZipArchiveDirectoryEntryHandle handle, TElOwnHandle ownHandle);

		TElZipArchiveDirectoryEntry();

#ifdef SB_USE_CLASS_TELBASEARCHIVE
		explicit TElZipArchiveDirectoryEntry(TElBaseArchive &Owner);

		explicit TElZipArchiveDirectoryEntry(TElBaseArchive *Owner);
#endif /* SB_USE_CLASS_TELBASEARCHIVE */

		virtual ~TElZipArchiveDirectoryEntry();

};
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES
class TElZipDosFileAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElZipDosFileAttributes)
	public:
		virtual uint8_t get_RawAttributes();

		virtual void set_RawAttributes(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_RawAttributes, set_RawAttributes, TElZipDosFileAttributes, RawAttributes);

		virtual uint32_t get_RawLastModTime();

		virtual void set_RawLastModTime(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RawLastModTime, set_RawLastModTime, TElZipDosFileAttributes, RawLastModTime);

		virtual uint32_t get_RawLastModDate();

		virtual void set_RawLastModDate(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RawLastModDate, set_RawLastModDate, TElZipDosFileAttributes, RawLastModDate);

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElZipDosFileAttributes, ReadOnly);

		virtual bool get_Hidden();

		virtual void set_Hidden(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Hidden, set_Hidden, TElZipDosFileAttributes, Hidden);

		virtual bool get_System();

		virtual void set_System(bool Value);

		SB_DECLARE_PROPERTY(bool, get_System, set_System, TElZipDosFileAttributes, System);

		virtual bool get_VolumeLabel();

		virtual void set_VolumeLabel(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VolumeLabel, set_VolumeLabel, TElZipDosFileAttributes, VolumeLabel);

		virtual bool get_Directory();

		virtual void set_Directory(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Directory, set_Directory, TElZipDosFileAttributes, Directory);

		virtual bool get_Archive();

		virtual void set_Archive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Archive, set_Archive, TElZipDosFileAttributes, Archive);

		virtual int64_t get_ModTime();

		virtual void set_ModTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModTime, set_ModTime, TElZipDosFileAttributes, ModTime);

		TElZipDosFileAttributes(TElZipDosFileAttributesHandle handle, TElOwnHandle ownHandle);

		TElZipDosFileAttributes();

};
#endif /* SB_USE_CLASS_TELZIPDOSFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES
class TElZipUnixFileAttributes: public TObject
{
	private:
		SB_DISABLE_COPY(TElZipUnixFileAttributes)
	public:
		virtual uint32_t get_RawAttributes();

		virtual void set_RawAttributes(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RawAttributes, set_RawAttributes, TElZipUnixFileAttributes, RawAttributes);

		virtual TSBZipUnixFileType get_FileType();

		virtual void set_FileType(TSBZipUnixFileType Value);

		SB_DECLARE_PROPERTY(TSBZipUnixFileType, get_FileType, set_FileType, TElZipUnixFileAttributes, FileType);

		virtual bool get_SUID();

		virtual void set_SUID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SUID, set_SUID, TElZipUnixFileAttributes, SUID);

		virtual bool get_SGID();

		virtual void set_SGID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SGID, set_SGID, TElZipUnixFileAttributes, SGID);

		virtual bool get_StickyBit();

		virtual void set_StickyBit(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StickyBit, set_StickyBit, TElZipUnixFileAttributes, StickyBit);

		virtual bool get_OwnerRead();

		virtual void set_OwnerRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerRead, set_OwnerRead, TElZipUnixFileAttributes, OwnerRead);

		virtual bool get_OwnerWrite();

		virtual void set_OwnerWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerWrite, set_OwnerWrite, TElZipUnixFileAttributes, OwnerWrite);

		virtual bool get_OwnerExecute();

		virtual void set_OwnerExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnerExecute, set_OwnerExecute, TElZipUnixFileAttributes, OwnerExecute);

		virtual bool get_GroupRead();

		virtual void set_GroupRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupRead, set_GroupRead, TElZipUnixFileAttributes, GroupRead);

		virtual bool get_GroupWrite();

		virtual void set_GroupWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupWrite, set_GroupWrite, TElZipUnixFileAttributes, GroupWrite);

		virtual bool get_GroupExecute();

		virtual void set_GroupExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GroupExecute, set_GroupExecute, TElZipUnixFileAttributes, GroupExecute);

		virtual bool get_OtherRead();

		virtual void set_OtherRead(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherRead, set_OtherRead, TElZipUnixFileAttributes, OtherRead);

		virtual bool get_OtherWrite();

		virtual void set_OtherWrite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherWrite, set_OtherWrite, TElZipUnixFileAttributes, OtherWrite);

		virtual bool get_OtherExecute();

		virtual void set_OtherExecute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OtherExecute, set_OtherExecute, TElZipUnixFileAttributes, OtherExecute);

		virtual uint32_t get_Permissions();

		virtual void set_Permissions(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Permissions, set_Permissions, TElZipUnixFileAttributes, Permissions);

		virtual uint8_t get_DOSAttributes();

		virtual void set_DOSAttributes(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_DOSAttributes, set_DOSAttributes, TElZipUnixFileAttributes, DOSAttributes);

		virtual bool get_UIDAndGIDAvailable();

		virtual void set_UIDAndGIDAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UIDAndGIDAvailable, set_UIDAndGIDAvailable, TElZipUnixFileAttributes, UIDAndGIDAvailable);

		virtual uint32_t get_UID();

		virtual void set_UID(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_UID, set_UID, TElZipUnixFileAttributes, UID);

		virtual uint32_t get_GID();

		virtual void set_GID(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_GID, set_GID, TElZipUnixFileAttributes, GID);

		virtual bool get_ModifyTimeAvailable();

		virtual void set_ModifyTimeAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ModifyTimeAvailable, set_ModifyTimeAvailable, TElZipUnixFileAttributes, ModifyTimeAvailable);

		virtual bool get_CreateTimeAvailable();

		virtual void set_CreateTimeAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CreateTimeAvailable, set_CreateTimeAvailable, TElZipUnixFileAttributes, CreateTimeAvailable);

		virtual bool get_AccessTimeAvailable();

		virtual void set_AccessTimeAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AccessTimeAvailable, set_AccessTimeAvailable, TElZipUnixFileAttributes, AccessTimeAvailable);

		virtual int64_t get_ModifyTime();

		virtual void set_ModifyTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ModifyTime, set_ModifyTime, TElZipUnixFileAttributes, ModifyTime);

		virtual int64_t get_CreateTime();

		virtual void set_CreateTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreateTime, set_CreateTime, TElZipUnixFileAttributes, CreateTime);

		virtual int64_t get_AccessTime();

		virtual void set_AccessTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AccessTime, set_AccessTime, TElZipUnixFileAttributes, AccessTime);

		TElZipUnixFileAttributes(TElZipUnixFileAttributesHandle handle, TElOwnHandle ownHandle);

		TElZipUnixFileAttributes();

};
#endif /* SB_USE_CLASS_TELZIPUNIXFILEATTRIBUTES */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
class TElZipStrongEncryptionInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionInfo)
	public:
		void Assign(TElZipStrongEncryptionInfo &Source);

		void Assign(TElZipStrongEncryptionInfo *Source);

		virtual uint32_t get_EncryptionAlgorithm();

		virtual void set_EncryptionAlgorithm(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_EncryptionAlgorithm, set_EncryptionAlgorithm, TElZipStrongEncryptionInfo, EncryptionAlgorithm);

		virtual uint32_t get_KeyLength();

		virtual void set_KeyLength(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_KeyLength, set_KeyLength, TElZipStrongEncryptionInfo, KeyLength);

		virtual bool get_UsePassword();

		virtual void set_UsePassword(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePassword, set_UsePassword, TElZipStrongEncryptionInfo, UsePassword);

		virtual bool get_UseCertificates();

		virtual void set_UseCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCertificates, set_UseCertificates, TElZipStrongEncryptionInfo, UseCertificates);

		virtual bool get_UseOAEP();

		virtual void set_UseOAEP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOAEP, set_UseOAEP, TElZipStrongEncryptionInfo, UseOAEP);

		virtual bool get_Use3DES();

		virtual void set_Use3DES(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Use3DES, set_Use3DES, TElZipStrongEncryptionInfo, Use3DES);

		TElZipStrongEncryptionInfo(TElZipStrongEncryptionInfoHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionInfo();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO
class TElZipStrongEncryptionSignatureInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionSignatureInfo)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Issuer, TElZipStrongEncryptionSignatureInfo, Issuer);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void get_SignatureData(std::vector<uint8_t> &OutResult);

		virtual uint32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_HashAlgorithm, TElZipStrongEncryptionSignatureInfo, HashAlgorithm);

		virtual void get_ContentHash(std::vector<uint8_t> &OutResult);

		virtual void set_ContentHash(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_SigningCertificate();

		virtual void set_SigningCertificate(TElX509Certificate &Value);

		virtual void set_SigningCertificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_SigningCertificate, set_SigningCertificate, TElZipStrongEncryptionSignatureInfo, SigningCertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		TElZipStrongEncryptionSignatureInfo(TElZipStrongEncryptionSignatureInfoHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionSignatureInfo();

		virtual ~TElZipStrongEncryptionSignatureInfo();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONSIGNATUREINFO */

#ifdef SB_USE_CLASS_TELZIPPROCESSINGUNIT
class TElZipProcessingUnit: public TElArcProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipProcessingUnit)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntry* _Inst_ProcessingEntry;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		void initInstances();

	public:
		virtual void InitializeProcessing();

		virtual void FinalizeProcessing();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElZipProcessingUnit, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		virtual TElZipArchiveDirectoryEntry* get_ProcessingEntry();

		virtual void set_ProcessingEntry(TElZipArchiveDirectoryEntry &Value);

		virtual void set_ProcessingEntry(TElZipArchiveDirectoryEntry *Value);

		SB_DECLARE_PROPERTY(TElZipArchiveDirectoryEntry*, get_ProcessingEntry, set_ProcessingEntry, TElZipProcessingUnit, ProcessingEntry);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		virtual uint32_t get_CRC32();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_CRC32, TElZipProcessingUnit, CRC32);

		TElZipProcessingUnit(TElZipProcessingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipProcessingUnit();

		virtual ~TElZipProcessingUnit();

};
#endif /* SB_USE_CLASS_TELZIPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT
class TElZipStoredProcessingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipStoredProcessingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		TElZipStoredProcessingUnit(TElZipStoredProcessingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipStoredProcessingUnit();

};
#endif /* SB_USE_CLASS_TELZIPSTOREDPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT
class TElZipDeflateDecompressingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipDeflateDecompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual bool get_Deflate64();

		virtual void set_Deflate64(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Deflate64, set_Deflate64, TElZipDeflateDecompressingUnit, Deflate64);

		TElZipDeflateDecompressingUnit(TElZipDeflateDecompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipDeflateDecompressingUnit();

};
#endif /* SB_USE_CLASS_TELZIPDEFLATEDECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT
class TElZipDeflateCompressingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipDeflateCompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElZipDeflateCompressingUnit, CompressionLevel);

		virtual bool get_Deflate64();

		virtual void set_Deflate64(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Deflate64, set_Deflate64, TElZipDeflateCompressingUnit, Deflate64);

		TElZipDeflateCompressingUnit(TElZipDeflateCompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipDeflateCompressingUnit();

};
#endif /* SB_USE_CLASS_TELZIPDEFLATECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT
class TElZipBZip2DecompressingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipBZip2DecompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		TElZipBZip2DecompressingUnit(TElZipBZip2DecompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipBZip2DecompressingUnit();

};
#endif /* SB_USE_CLASS_TELZIPBZIP2DECOMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT
class TElZipBZip2CompressingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipBZip2CompressingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElZipBZip2CompressingUnit, CompressionLevel);

		TElZipBZip2CompressingUnit(TElZipBZip2CompressingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipBZip2CompressingUnit();

};
#endif /* SB_USE_CLASS_TELZIPBZIP2COMPRESSINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT
class TElZipOldStyleEncryptingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipOldStyleEncryptingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		TElZipOldStyleEncryptingUnit(TElZipOldStyleEncryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipOldStyleEncryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPOLDSTYLEENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT
class TElZipOldStyleDecryptingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipOldStyleDecryptingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual bool get_HeaderRead();

		SB_DECLARE_PROPERTY_GET(bool, get_HeaderRead, TElZipOldStyleDecryptingUnit, HeaderRead);

		virtual bool get_IgnorePasswordCheck();

		virtual void set_IgnorePasswordCheck(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnorePasswordCheck, set_IgnorePasswordCheck, TElZipOldStyleDecryptingUnit, IgnorePasswordCheck);

		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		TElZipOldStyleDecryptingUnit(TElZipOldStyleDecryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipOldStyleDecryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPOLDSTYLEDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT
class TElZipStrongEncryptionBaseUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionBaseUnit)
	public:
		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		TElZipStrongEncryptionBaseUnit(TElZipStrongEncryptionBaseUnitHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionBaseUnit();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT
class TElZipStrongEncryptionEncryptingUnit: public TElZipStrongEncryptionBaseUnit
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionEncryptingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_EncryptionAlgorithm();

		virtual void set_EncryptionAlgorithm(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_EncryptionAlgorithm, set_EncryptionAlgorithm, TElZipStrongEncryptionEncryptingUnit, EncryptionAlgorithm);

		virtual uint32_t get_EncryptionKeySize();

		virtual void set_EncryptionKeySize(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_EncryptionKeySize, set_EncryptionKeySize, TElZipStrongEncryptionEncryptingUnit, EncryptionKeySize);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual bool get_UseTripleDES();

		virtual void set_UseTripleDES(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseTripleDES, set_UseTripleDES, TElZipStrongEncryptionEncryptingUnit, UseTripleDES);

		TElZipStrongEncryptionEncryptingUnit(TElZipStrongEncryptionEncryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionEncryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT
class TElZipStrongEncryptionDecryptingUnit: public TElZipStrongEncryptionBaseUnit
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionDecryptingUnit)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Recipient;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_FileCRC32();

		virtual void set_FileCRC32(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_FileCRC32, set_FileCRC32, TElZipStrongEncryptionDecryptingUnit, FileCRC32);

		virtual int64_t get_FileSize();

		virtual void set_FileSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_FileSize, set_FileSize, TElZipStrongEncryptionDecryptingUnit, FileSize);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual bool get_OAEPUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_OAEPUsed, TElZipStrongEncryptionDecryptingUnit, OAEPUsed);

		virtual bool get_TripleDESUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_TripleDESUsed, TElZipStrongEncryptionDecryptingUnit, TripleDESUsed);

		virtual bool get_PasswordUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_PasswordUsed, TElZipStrongEncryptionDecryptingUnit, PasswordUsed);

		virtual bool get_PublicKeyUsed();

		SB_DECLARE_PROPERTY_GET(bool, get_PublicKeyUsed, TElZipStrongEncryptionDecryptingUnit, PublicKeyUsed);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Recipient();

		virtual void set_Recipient(TElX509Certificate &Value);

		virtual void set_Recipient(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_Recipient, set_Recipient, TElZipStrongEncryptionDecryptingUnit, Recipient);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void get_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		TElZipStrongEncryptionDecryptingUnit(TElZipStrongEncryptionDecryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionDecryptingUnit();

		virtual ~TElZipStrongEncryptionDecryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT
class TElZipStrongEncryptionHashingUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipStrongEncryptionHashingUnit)
	public:
		void ClearHashFunctions();

		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		virtual uint32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_HashAlgorithm, set_HashAlgorithm, TElZipStrongEncryptionHashingUnit, HashAlgorithm);

		virtual void get_Hash(std::vector<uint8_t> &OutResult);

		TElZipStrongEncryptionHashingUnit(TElZipStrongEncryptionHashingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipStrongEncryptionHashingUnit();

};
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONHASHINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT
class TElZipWinZipAesBaseUnit: public TElZipProcessingUnit
{
	private:
		SB_DISABLE_COPY(TElZipWinZipAesBaseUnit)
	public:
		virtual void InitializeProcessing();

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		TElZipWinZipAesBaseUnit(TElZipWinZipAesBaseUnitHandle handle, TElOwnHandle ownHandle);

		TElZipWinZipAesBaseUnit();

};
#endif /* SB_USE_CLASS_TELZIPWINZIPAESBASEUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT
class TElZipWinZipAesDecryptingUnit: public TElZipWinZipAesBaseUnit
{
	private:
		SB_DISABLE_COPY(TElZipWinZipAesDecryptingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		TElZipWinZipAesDecryptingUnit(TElZipWinZipAesDecryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipWinZipAesDecryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPWINZIPAESDECRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT
class TElZipWinZipAesEncryptingUnit: public TElZipWinZipAesBaseUnit
{
	private:
		SB_DISABLE_COPY(TElZipWinZipAesEncryptingUnit)
	public:
		virtual void InitializeProcessing();

		virtual void ProcessBlock(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

		virtual void FinalizeProcessing();

		TElZipWinZipAesEncryptingUnit(TElZipWinZipAesEncryptingUnitHandle handle, TElOwnHandle ownHandle);

		TElZipWinZipAesEncryptingUnit();

};
#endif /* SB_USE_CLASS_TELZIPWINZIPAESENCRYPTINGUNIT */

#ifdef SB_USE_CLASS_TELZIPREADER
class TElZipReader: public TElBaseArchive
{
	private:
		SB_DISABLE_COPY(TElZipReader)
#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntry* _Inst_Directory;
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SigningCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncryptingCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void Open(const std::string &FileName, bool ReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Open(TStream &Stream);

		virtual void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Close();

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		void Extract(TElZipArchiveDirectoryEntry &Entry, const std::string &OutputPath);

		void Extract(TElZipArchiveDirectoryEntry *Entry, const std::string &OutputPath);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TLIST
		void Extract(TList &Entries, const std::string &OutputPath);

		void Extract(TList *Entries, const std::string &OutputPath);
#endif /* SB_USE_CLASS_TLIST */

		void Extract(const std::string &Mask, const std::string &OutputPath);

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		void ExtractContents(TElZipArchiveDirectoryEntry &Entry, std::vector<uint8_t> &OutResult);

		void ExtractContents(TElZipArchiveDirectoryEntry *Entry, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		bool ValidateSignature(TElZipArchiveDirectoryEntry &Entry, int32_t SignatureIndex);

		bool ValidateSignature(TElZipArchiveDirectoryEntry *Entry, int32_t SignatureIndex);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		bool ValidateDirectorySignature();

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		bool CheckEntry(TElZipArchiveDirectoryEntry &Entry);

		bool CheckEntry(TElZipArchiveDirectoryEntry *Entry);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		bool CheckArchive();

		virtual bool get_DirectoryCompressed();

		virtual void set_DirectoryCompressed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DirectoryCompressed, set_DirectoryCompressed, TElZipReader, DirectoryCompressed);

		virtual bool get_DirectoryEncrypted();

		virtual void set_DirectoryEncrypted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DirectoryEncrypted, set_DirectoryEncrypted, TElZipReader, DirectoryEncrypted);

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		virtual TElZipArchiveDirectoryEntry* get_Directory();

		SB_DECLARE_PROPERTY_GET(TElZipArchiveDirectoryEntry*, get_Directory, TElZipReader, Directory);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

		virtual void get_ArchiveComment(std::string &OutResult);

		virtual void set_ArchiveComment(const std::string &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SigningCertificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_SigningCertificates, TElZipReader, SigningCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncryptingCertificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_EncryptingCertificates, TElZipReader, EncryptingCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_IgnorePasswordCheck();

		virtual void set_IgnorePasswordCheck(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnorePasswordCheck, set_IgnorePasswordCheck, TElZipReader, IgnorePasswordCheck);

		virtual bool get_RestoreAttributes();

		virtual void set_RestoreAttributes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RestoreAttributes, set_RestoreAttributes, TElZipReader, RestoreAttributes);

		virtual void get_FilenamesCharset(std::string &OutResult);

		virtual void set_FilenamesCharset(const std::string &Value);

		virtual bool get_IgnoreArchiveErrors();

		virtual void set_IgnoreArchiveErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreArchiveErrors, set_IgnoreArchiveErrors, TElZipReader, IgnoreArchiveErrors);

		virtual bool get_CaseSensitiveFilenames();

		virtual void set_CaseSensitiveFilenames(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CaseSensitiveFilenames, set_CaseSensitiveFilenames, TElZipReader, CaseSensitiveFilenames);

		virtual void get_MimeType(std::string &OutResult);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_SFXCopyright(std::string &OutResult);

		virtual void set_SFXCopyright(const std::string &Value);

		virtual bool get_SFXEnabled();

		virtual void set_SFXEnabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SFXEnabled, set_SFXEnabled, TElZipReader, SFXEnabled);

		virtual void get_SFXTitle(std::string &OutResult);

		virtual void set_SFXTitle(const std::string &Value);

		virtual void get_StubName(std::string &OutResult);

		virtual void set_StubName(const std::string &Value);

		virtual TSBZIPStubSource get_StubSource();

		virtual void set_StubSource(TSBZIPStubSource Value);

		SB_DECLARE_PROPERTY(TSBZIPStubSource, get_StubSource, set_StubSource, TElZipReader, StubSource);
#endif

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElZipReader, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElZipReader, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual void get_OnExtractionStreamNeeded(TSBZipExtractionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStreamNeeded(TSBZipExtractionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionMakeDirectory(TSBZipExtractionMakeDirectoryEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionMakeDirectory(TSBZipExtractionMakeDirectoryEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBZipProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBZipProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionStart(TSBZipExtractionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionStart(TSBZipExtractionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtractionFinished(TSBZipExtractionFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtractionFinished(TSBZipExtractionFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnUserActionNeeded(TSBZipUserActionNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnUserActionNeeded(TSBZipUserActionNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordNeeded(TSBZipPasswordNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordNeeded(TSBZipPasswordNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSBZipPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnArchiveError(TSBZipArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArchiveError(TSBZipArchiveErrorEvent pMethodValue, void * pDataValue);

		TElZipReader(TElZipReaderHandle handle, TElOwnHandle ownHandle);

		explicit TElZipReader(TComponent &AOwner);

		explicit TElZipReader(TComponent *AOwner);

		virtual ~TElZipReader();

};
#endif /* SB_USE_CLASS_TELZIPREADER */

#ifdef SB_USE_CLASS_TELZIPWRITER
class TElZipWriter: public TElZipReader
{
	private:
		SB_DISABLE_COPY(TElZipWriter)
#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
		TElZipStrongEncryptionInfo* _Inst_StrongEncryptionInfo;
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

		void initInstances();

	public:
		virtual void CreateArchive();

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry &Parent, const std::string &Path);

		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry *Parent, const std::string &Path);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle Add(const std::string &Path);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry &Parent, TStream &Stream);

		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry *Parent, TStream *Stream);
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
		TElZipArchiveDirectoryEntryHandle Add(TStream &Stream);

		TElZipArchiveDirectoryEntryHandle Add(TStream *Stream);
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry &Parent, TStream &Stream, const std::string &FileName);

		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry *Parent, TStream *Stream, const std::string &FileName);
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM
		TElZipArchiveDirectoryEntryHandle Add(TStream &Stream, const std::string &FileName);

		TElZipArchiveDirectoryEntryHandle Add(TStream *Stream, const std::string &FileName);
#endif /* SB_USE_CLASSES_TELZIPARCHIVEDIRECTORYENTRY_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry &Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName);

		TElZipArchiveDirectoryEntryHandle Add(TElZipArchiveDirectoryEntry *Parent, const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle Add(const std::vector<uint8_t> &Buf, int32_t StartIndex, int32_t Count, const std::string &FileName);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		void AddDirContents(const std::string &Path);

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		void AddDirContents(TElZipArchiveDirectoryEntry &Parent, const std::string &Path);

		void AddDirContents(TElZipArchiveDirectoryEntry *Parent, const std::string &Path);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

		void AddDirContents(const std::string &Path, const std::string &Mask);

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		void AddDirContents(TElZipArchiveDirectoryEntry &Parent, const std::string &Path, const std::string &Mask);

		void AddDirContents(TElZipArchiveDirectoryEntry *Parent, const std::string &Path, const std::string &Mask);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle MakeDir(const std::string &Path);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY
		TElZipArchiveDirectoryEntryHandle MakeDir(TElZipArchiveDirectoryEntry &Parent, const std::string &Path);

		TElZipArchiveDirectoryEntryHandle MakeDir(TElZipArchiveDirectoryEntry *Parent, const std::string &Path);
#endif /* SB_USE_CLASS_TELZIPARCHIVEDIRECTORYENTRY */

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

		virtual TSBArcReplaceMode get_ReplaceMode();

		virtual void set_ReplaceMode(TSBArcReplaceMode Value);

		SB_DECLARE_PROPERTY(TSBArcReplaceMode, get_ReplaceMode, set_ReplaceMode, TElZipWriter, ReplaceMode);

		virtual bool get_NewArchive();

		SB_DECLARE_PROPERTY_GET(bool, get_NewArchive, TElZipWriter, NewArchive);

		virtual uint32_t get_CompressionAlgorithm();

		virtual void set_CompressionAlgorithm(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionAlgorithm, set_CompressionAlgorithm, TElZipWriter, CompressionAlgorithm);

		virtual uint32_t get_CompressionLevel();

		virtual void set_CompressionLevel(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_CompressionLevel, set_CompressionLevel, TElZipWriter, CompressionLevel);

		virtual bool get_Encrypt();

		virtual void set_Encrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Encrypt, set_Encrypt, TElZipWriter, Encrypt);

		virtual bool get_StrongEncryption();

		virtual void set_StrongEncryption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrongEncryption, set_StrongEncryption, TElZipWriter, StrongEncryption);

		virtual bool get_WinZipEncryption();

		virtual void set_WinZipEncryption(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WinZipEncryption, set_WinZipEncryption, TElZipWriter, WinZipEncryption);

		virtual uint32_t get_WinZipAesKeySize();

		virtual void set_WinZipAesKeySize(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_WinZipAesKeySize, set_WinZipAesKeySize, TElZipWriter, WinZipAesKeySize);

#ifdef SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO
		virtual TElZipStrongEncryptionInfo* get_StrongEncryptionInfo();

		SB_DECLARE_PROPERTY_GET(TElZipStrongEncryptionInfo*, get_StrongEncryptionInfo, TElZipWriter, StrongEncryptionInfo);
#endif /* SB_USE_CLASS_TELZIPSTRONGENCRYPTIONINFO */

		virtual bool get_UseUTF8Filenames();

		virtual void set_UseUTF8Filenames(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8Filenames, set_UseUTF8Filenames, TElZipWriter, UseUTF8Filenames);

		virtual void get_MimeType(std::string &OutResult);

		virtual void set_MimeType(const std::string &Value);

		virtual void get_OnCompressionStreamNeeded(TSBZipCompressionStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStreamNeeded(TSBZipCompressionStreamNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionStart(TSBZipCompressionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionStart(TSBZipCompressionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressionFinished(TSBZipCompressionFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressionFinished(TSBZipCompressionFinishedEvent pMethodValue, void * pDataValue);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnGetStubStream(TSBZIPGetStubStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetStubStream(TSBZIPGetStubStreamEvent pMethodValue, void * pDataValue);
#endif

		TElZipWriter(TElZipWriterHandle handle, TElOwnHandle ownHandle);

		explicit TElZipWriter(TComponent &AOwner);

		explicit TElZipWriter(TComponent *AOwner);

		virtual ~TElZipWriter();

};
#endif /* SB_USE_CLASS_TELZIPWRITER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBARCZIP */
