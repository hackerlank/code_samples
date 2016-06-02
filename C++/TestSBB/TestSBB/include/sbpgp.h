#ifndef __INC_SBPGP
#define __INC_SBPGP

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbtar.h"
#include "sbpgpkeys.h"
#include "sbpgpstreams.h"
#include "sbpgpconstants.h"
#include "sbpgpentities.h"
#include "sbpgputils.h"
#include "sbpgpmd.h"
#include "sbhashfunction.h"
#include "sbdiskfsadapter.h"
#include "sbcustomfsadapter.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPGPWriterHandle;

typedef TElPGPWriterHandle ElPGPWriterHandle;

typedef TElClassHandle TElPGPProcessingUnitHandle;

typedef TElPGPProcessingUnitHandle ElPGPProcessingUnitHandle;

typedef TElClassHandle TElPGPReaderHandle;

typedef TElPGPReaderHandle ElPGPReaderHandle;

typedef uint8_t TSBPGPEncryptionTypeRaw;

typedef enum
{
	etPublicKey = 0,
	etPassphrase = 1,
	etBoth = 2
} TSBPGPEncryptionType;

typedef uint8_t TSBPGPProcessingUnitStateRaw;

typedef enum
{
	usPreSignaturePackets = 0,
	usData = 1,
	usPostSignaturePackets = 2
} TSBPGPProcessingUnitState;

typedef void (SB_CALLBACK *TSBPGPProgressEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Processed, int64_t Total, int8_t * Cancel);

typedef uint8_t TSBPGPSignBufferingMethodRaw;

typedef enum
{
	sbmTemporaryStream = 0,
	sbmRewind = 1
} TSBPGPSignBufferingMethod;

typedef uint8_t TSBPGPMemoryConsumptionStrategyRaw;

typedef enum
{
	mcsDefault = 0,
	mcsGreedy = 1
} TSBPGPMemoryConsumptionStrategy;

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef uint8_t TSBPGPStubSourceRaw;

typedef enum
{
	ssStream = 0,
	ssFile = 1,
	ssResource = 2
} TSBPGPStubSource;
#endif

typedef void (SB_CALLBACK *TSBPGPNewStreamEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPStreamHandle Stream, int8_t * Atomic);

typedef void (SB_CALLBACK *TSBPGPSignatureEntityEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPSignatureEntityHandle Sig);

typedef void (SB_CALLBACK *TSBPGPHashAlgorithmEvent)(void * _ObjectData, TObjectHandle Sender, int32_t HashAlg, int32_t SigClass);

#ifndef SB_WINCE_OR_NOT_WINDOWS
typedef void (SB_CALLBACK *TSBPGPGetStubStreamEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream, int8_t * FreeStub);
#endif

typedef void (SB_CALLBACK *TSBPGPMultipleFilesFoundEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcTarFilename, int32_t szTarFilename, int8_t * ExtractFiles);

typedef void (SB_CALLBACK *TSBPGPRequestOutputFileEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFilename, int32_t szFilename, int64_t TimeStamp, char * pcPath, int32_t * szPath);

typedef void (SB_CALLBACK *TSBPGPCreateOutputStreamEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFilename, int32_t szFilename, int64_t TimeStamp, TStreamHandle * Stream, int8_t * FreeOnExit);

typedef void (SB_CALLBACK *TSBPGPFileExtractionStartEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcFilename, int32_t szFilename, int64_t TimeStamp);

typedef void (SB_CALLBACK *TSBPGPEncryptedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pKeyIDs[][8], int32_t szKeyIDs, int8_t IntegrityProtected, int8_t PassphraseUsed);

typedef TNotifyEvent TSBPGPCompressedEvent;

typedef void (SB_CALLBACK *TSBPGPArmoredEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcBoundary, int32_t szBoundary, TStringListHandle Headers);

typedef void (SB_CALLBACK *TSBPGPSignedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pKeyIDs[][8], int32_t szKeyIDs, TSBPGPSignatureTypeRaw SignatureType);

#ifdef SB_USE_CLASS_TELPGPWRITER
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_EncryptFile(TElPGPWriterHandle _Handle, const char * pcASourceFile, int32_t szASourceFile, const char * pcADestFile, int32_t szADestFile);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_SignFile(TElPGPWriterHandle _Handle, const char * pcASourceFile, int32_t szASourceFile, const char * pcADestFile, int32_t szADestFile, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_EncryptAndSignFile(TElPGPWriterHandle _Handle, const char * pcASourceFile, int32_t szASourceFile, const char * pcADestFile, int32_t szADestFile);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_ClearTextSignFile(TElPGPWriterHandle _Handle, const char * pcASourceFile, int32_t szASourceFile, const char * pcADestFile, int32_t szADestFile);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_Encrypt(TElPGPWriterHandle _Handle, TStreamHandle ASourceStream, TStreamHandle ADestStream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_Sign(TElPGPWriterHandle _Handle, TStreamHandle ASourceStream, TStreamHandle ADestStream, int8_t Detached, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_EncryptAndSign(TElPGPWriterHandle _Handle, TStreamHandle ASourceStream, TStreamHandle ADestStream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_ClearTextSign(TElPGPWriterHandle _Handle, TStreamHandle ASourceStream, TStreamHandle ADestStream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_EncryptFiles(TElPGPWriterHandle _Handle, TStringListHandle SourceFileNames, TListHandle SourceStreams, const char * pcADestFileName, int32_t szADestFileName, TStreamHandle ADestStream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_SignFiles(TElPGPWriterHandle _Handle, TStringListHandle SourceFileNames, TListHandle SourceStreams, const char * pcADestFileName, int32_t szADestFileName, TStreamHandle ADestStream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_EncryptAndSignFiles(TElPGPWriterHandle _Handle, TStringListHandle SourceFileNames, TListHandle SourceStreams, const char * pcADestFileName, int32_t szADestFileName, TStreamHandle ADestStream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Timestamp(TElPGPWriterHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_Timestamp(TElPGPWriterHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Armor(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_Armor(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_EncryptionType(TElPGPWriterHandle _Handle, TSBPGPEncryptionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_EncryptionType(TElPGPWriterHandle _Handle, TSBPGPEncryptionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Compress(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_Compress(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_CompressionAlgorithm(TElPGPWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_CompressionAlgorithm(TElPGPWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_CompressionLevel(TElPGPWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_CompressionLevel(TElPGPWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_ArmorBoundary(TElPGPWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_ArmorBoundary(TElPGPWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_ArmorHeaders(TElPGPWriterHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Filename(TElPGPWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_Filename(TElPGPWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SigningKeys(TElPGPWriterHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SigningKeys(TElPGPWriterHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_EncryptingKeys(TElPGPWriterHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_EncryptingKeys(TElPGPWriterHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_HashAlgorithm(TElPGPWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_HashAlgorithm(TElPGPWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Passphrases(TElPGPWriterHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_Protection(TElPGPWriterHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_Protection(TElPGPWriterHandle _Handle, TSBPGPProtectionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SymmetricKeyAlgorithm(TElPGPWriterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SymmetricKeyAlgorithm(TElPGPWriterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SignBufferingMethod(TElPGPWriterHandle _Handle, TSBPGPSignBufferingMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SignBufferingMethod(TElPGPWriterHandle _Handle, TSBPGPSignBufferingMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_UseOldPackets(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_UseOldPackets(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_UseNewFeatures(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_UseNewFeatures(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_InputIsText(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_InputIsText(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_TextCompatibilityMode(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_TextCompatibilityMode(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_UndefInputLength(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_UndefInputLength(TElPGPWriterHandle _Handle, int8_t Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SFXCopyright(TElPGPWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SFXCopyright(TElPGPWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SFXEnabled(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SFXEnabled(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_SFXTitle(TElPGPWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_SFXTitle(TElPGPWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_StubName(TElPGPWriterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_StubName(TElPGPWriterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_StubSource(TElPGPWriterHandle _Handle, TSBPGPStubSourceRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_StubSource(TElPGPWriterHandle _Handle, TSBPGPStubSourceRaw Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_PreserveFilePaths(TElPGPWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_PreserveFilePaths(TElPGPWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_FileSystemAdapter(TElPGPWriterHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_FileSystemAdapter(TElPGPWriterHandle _Handle, TElCustomFileSystemAdapterHandle Value);
#ifndef SB_WINCE_OR_NOT_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_OnGetStubStream(TElPGPWriterHandle _Handle, TSBPGPGetStubStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_OnGetStubStream(TElPGPWriterHandle _Handle, TSBPGPGetStubStreamEvent pMethodValue, void * pDataValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_OnKeyPassphrase(TElPGPWriterHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_OnKeyPassphrase(TElPGPWriterHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_OnProgress(TElPGPWriterHandle _Handle, TSBPGPProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_OnProgress(TElPGPWriterHandle _Handle, TSBPGPProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_get_OnTemporaryStream(TElPGPWriterHandle _Handle, TSBPGPTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_set_OnTemporaryStream(TElPGPWriterHandle _Handle, TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPWriter_Create(TComponentHandle AOwner, TElPGPWriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPWRITER */

#ifdef SB_USE_CLASS_TELPGPPROCESSINGUNIT
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_Read(TElPGPProcessingUnitHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_Write(TElPGPProcessingUnitHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_NFinalize(TElPGPProcessingUnitHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_Atomic(TElPGPProcessingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_Finished(TElPGPProcessingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_Stream(TElPGPProcessingUnitHandle _Handle, TElPGPStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_Prev(TElPGPProcessingUnitHandle _Handle, TElPGPProcessingUnitHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_SkippedLength(TElPGPProcessingUnitHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_ProcessedLength(TElPGPProcessingUnitHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_InputEncoding(TElPGPProcessingUnitHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_InputEncoding(TElPGPProcessingUnitHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_IgnoreDataPacketLengths(TElPGPProcessingUnitHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_IgnoreDataPacketLengths(TElPGPProcessingUnitHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_OnNewStream(TElPGPProcessingUnitHandle _Handle, TSBPGPNewStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_OnNewStream(TElPGPProcessingUnitHandle _Handle, TSBPGPNewStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_OnFinish(TElPGPProcessingUnitHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_OnFinish(TElPGPProcessingUnitHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_OnSignature(TElPGPProcessingUnitHandle _Handle, TSBPGPSignatureEntityEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_OnSignature(TElPGPProcessingUnitHandle _Handle, TSBPGPSignatureEntityEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_get_OnHashAlgorithm(TElPGPProcessingUnitHandle _Handle, TSBPGPHashAlgorithmEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_set_OnHashAlgorithm(TElPGPProcessingUnitHandle _Handle, TSBPGPHashAlgorithmEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPProcessingUnit_Create(TElPGPProcessingUnitHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELPGPREADER
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_DecryptAndVerifyFile(TElPGPReaderHandle _Handle, const char * pcASourceFile, int32_t szASourceFile);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_VerifyDetachedFile(TElPGPReaderHandle _Handle, const char * pcASourceFile, int32_t szASourceFile, const char * pcASignatureFile, int32_t szASignatureFile);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_DecryptAndVerify(TElPGPReaderHandle _Handle, TStreamHandle ASourceStream, int64_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_VerifyDetached(TElPGPReaderHandle _Handle, TStreamHandle ASourceStream, TStreamHandle ASignatureStream, int64_t SourceStreamCount, int64_t SignatureStreamCount);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_EncryptionAlgorithm(TElPGPReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_CompressionAlgorithm(TElPGPReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_Protection(TElPGPReaderHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_ProcessedLength(TElPGPReaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OutputStream(TElPGPReaderHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OutputStream(TElPGPReaderHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_DecryptingKeys(TElPGPReaderHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_DecryptingKeys(TElPGPReaderHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_VerifyingKeys(TElPGPReaderHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_VerifyingKeys(TElPGPReaderHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OutputFile(TElPGPReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OutputFile(TElPGPReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_Passphrase(TElPGPReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_Passphrase(TElPGPReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_KeyPassphrase(TElPGPReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_KeyPassphrase(TElPGPReaderHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_MemoryConsumptionStrategy(TElPGPReaderHandle _Handle, TSBPGPMemoryConsumptionStrategyRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_MemoryConsumptionStrategy(TElPGPReaderHandle _Handle, TSBPGPMemoryConsumptionStrategyRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_FileSystemAdapter(TElPGPReaderHandle _Handle, TElCustomFileSystemAdapterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_FileSystemAdapter(TElPGPReaderHandle _Handle, TElCustomFileSystemAdapterHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_IgnoreDataPacketLengths(TElPGPReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_IgnoreDataPacketLengths(TElPGPReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_UndefInputLength(TElPGPReaderHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_UndefInputLength(TElPGPReaderHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnArmored(TElPGPReaderHandle _Handle, TSBPGPArmoredEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnArmored(TElPGPReaderHandle _Handle, TSBPGPArmoredEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnCompressed(TElPGPReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnCompressed(TElPGPReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnEncrypted(TElPGPReaderHandle _Handle, TSBPGPEncryptedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnEncrypted(TElPGPReaderHandle _Handle, TSBPGPEncryptedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnCreateOutputStream(TElPGPReaderHandle _Handle, TSBPGPCreateOutputStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnCreateOutputStream(TElPGPReaderHandle _Handle, TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnRequestOutputFile(TElPGPReaderHandle _Handle, TSBPGPRequestOutputFileEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnRequestOutputFile(TElPGPReaderHandle _Handle, TSBPGPRequestOutputFileEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnKeyPassphrase(TElPGPReaderHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnKeyPassphrase(TElPGPReaderHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnPassphrase(TElPGPReaderHandle _Handle, TSBPGPPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnPassphrase(TElPGPReaderHandle _Handle, TSBPGPPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnProgress(TElPGPReaderHandle _Handle, TSBPGPProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnProgress(TElPGPReaderHandle _Handle, TSBPGPProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnSigned(TElPGPReaderHandle _Handle, TSBPGPSignedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnSigned(TElPGPReaderHandle _Handle, TSBPGPSignedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnSignatures(TElPGPReaderHandle _Handle, TSBPGPSignaturesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnSignatures(TElPGPReaderHandle _Handle, TSBPGPSignaturesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnFileExtractionStart(TElPGPReaderHandle _Handle, TSBPGPFileExtractionStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnFileExtractionStart(TElPGPReaderHandle _Handle, TSBPGPFileExtractionStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnMultipleFilesFound(TElPGPReaderHandle _Handle, TSBPGPMultipleFilesFoundEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnMultipleFilesFound(TElPGPReaderHandle _Handle, TSBPGPMultipleFilesFoundEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_get_OnTemporaryStream(TElPGPReaderHandle _Handle, TSBPGPTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_set_OnTemporaryStream(TElPGPReaderHandle _Handle, TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPReader_Create(TComponentHandle AOwner, TElPGPReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPREADER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPGPWriter;
typedef TElPGPWriter ElPGPWriter;
class TElPGPProcessingUnit;
typedef TElPGPProcessingUnit ElPGPProcessingUnit;
class TElPGPReader;
typedef TElPGPReader ElPGPReader;

#ifdef SB_USE_CLASS_TELPGPWRITER
class TElPGPWriter: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPGPWriter)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_SigningKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_EncryptingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
		void EncryptFile(const std::string &ASourceFile, const std::string &ADestFile);

		void SignFile(const std::string &ASourceFile, const std::string &ADestFile, bool Detached);

		void EncryptAndSignFile(const std::string &ASourceFile, const std::string &ADestFile);

		void ClearTextSignFile(const std::string &ASourceFile, const std::string &ADestFile);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &ASourceStream, TStream &ADestStream, int64_t Count);

		void Encrypt(TStream *ASourceStream, TStream *ADestStream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Sign(TStream &ASourceStream, TStream &ADestStream, bool Detached, int64_t Count);

		void Sign(TStream *ASourceStream, TStream *ADestStream, bool Detached, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void EncryptAndSign(TStream &ASourceStream, TStream &ADestStream, int64_t Count);

		void EncryptAndSign(TStream *ASourceStream, TStream *ADestStream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void ClearTextSign(TStream &ASourceStream, TStream &ADestStream, int64_t Count);

		void ClearTextSign(TStream *ASourceStream, TStream *ADestStream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
		void EncryptFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream);

		void EncryptFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream);
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
		void SignFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream);

		void SignFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream);
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST
		void EncryptAndSignFiles(TStringList &SourceFileNames, TList &SourceStreams, const std::string &ADestFileName, TStream &ADestStream);

		void EncryptAndSignFiles(TStringList *SourceFileNames, TList *SourceStreams, const std::string &ADestFileName, TStream *ADestStream);
#endif /* SB_USE_CLASSES_TLIST_AND_TSTREAM_AND_TSTRINGLIST */

		virtual int64_t get_Timestamp();

		virtual void set_Timestamp(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Timestamp, set_Timestamp, TElPGPWriter, Timestamp);

		virtual bool get_Armor();

		virtual void set_Armor(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Armor, set_Armor, TElPGPWriter, Armor);

		virtual TSBPGPEncryptionType get_EncryptionType();

		virtual void set_EncryptionType(TSBPGPEncryptionType Value);

		SB_DECLARE_PROPERTY(TSBPGPEncryptionType, get_EncryptionType, set_EncryptionType, TElPGPWriter, EncryptionType);

		virtual bool get_Compress();

		virtual void set_Compress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Compress, set_Compress, TElPGPWriter, Compress);

		virtual int32_t get_CompressionAlgorithm();

		virtual void set_CompressionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionAlgorithm, set_CompressionAlgorithm, TElPGPWriter, CompressionAlgorithm);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElPGPWriter, CompressionLevel);

		virtual void get_ArmorBoundary(std::string &OutResult);

		virtual void set_ArmorBoundary(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ArmorHeaders, TElPGPWriter, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void get_Filename(std::string &OutResult);

		virtual void set_Filename(const std::string &Value);

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_SigningKeys();

		virtual void set_SigningKeys(TElPGPKeyring &Value);

		virtual void set_SigningKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_SigningKeys, set_SigningKeys, TElPGPWriter, SigningKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_EncryptingKeys();

		virtual void set_EncryptingKeys(TElPGPKeyring &Value);

		virtual void set_EncryptingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_EncryptingKeys, set_EncryptingKeys, TElPGPWriter, EncryptingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElPGPWriter, HashAlgorithm);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Passphrases();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Passphrases, TElPGPWriter, Passphrases);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual TSBPGPProtectionType get_Protection();

		virtual void set_Protection(TSBPGPProtectionType Value);

		SB_DECLARE_PROPERTY(TSBPGPProtectionType, get_Protection, set_Protection, TElPGPWriter, Protection);

		virtual int32_t get_SymmetricKeyAlgorithm();

		virtual void set_SymmetricKeyAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SymmetricKeyAlgorithm, set_SymmetricKeyAlgorithm, TElPGPWriter, SymmetricKeyAlgorithm);

		virtual TSBPGPSignBufferingMethod get_SignBufferingMethod();

		virtual void set_SignBufferingMethod(TSBPGPSignBufferingMethod Value);

		SB_DECLARE_PROPERTY(TSBPGPSignBufferingMethod, get_SignBufferingMethod, set_SignBufferingMethod, TElPGPWriter, SignBufferingMethod);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElPGPWriter, UseOldPackets);

		virtual bool get_UseNewFeatures();

		virtual void set_UseNewFeatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNewFeatures, set_UseNewFeatures, TElPGPWriter, UseNewFeatures);

		virtual bool get_InputIsText();

		virtual void set_InputIsText(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InputIsText, set_InputIsText, TElPGPWriter, InputIsText);

		virtual bool get_TextCompatibilityMode();

		virtual void set_TextCompatibilityMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TextCompatibilityMode, set_TextCompatibilityMode, TElPGPWriter, TextCompatibilityMode);

		virtual bool get_UndefInputLength();

		virtual void set_UndefInputLength(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UndefInputLength, set_UndefInputLength, TElPGPWriter, UndefInputLength);

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_SFXCopyright(std::string &OutResult);

		virtual void set_SFXCopyright(const std::string &Value);

		virtual bool get_SFXEnabled();

		virtual void set_SFXEnabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SFXEnabled, set_SFXEnabled, TElPGPWriter, SFXEnabled);

		virtual void get_SFXTitle(std::string &OutResult);

		virtual void set_SFXTitle(const std::string &Value);

		virtual void get_StubName(std::string &OutResult);

		virtual void set_StubName(const std::string &Value);

		virtual TSBPGPStubSource get_StubSource();

		virtual void set_StubSource(TSBPGPStubSource Value);

		SB_DECLARE_PROPERTY(TSBPGPStubSource, get_StubSource, set_StubSource, TElPGPWriter, StubSource);
#endif

		virtual bool get_PreserveFilePaths();

		virtual void set_PreserveFilePaths(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveFilePaths, set_PreserveFilePaths, TElPGPWriter, PreserveFilePaths);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElPGPWriter, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

#ifndef SB_WINCE_OR_NOT_WINDOWS
		virtual void get_OnGetStubStream(TSBPGPGetStubStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetStubStream(TSBPGPGetStubStreamEvent pMethodValue, void * pDataValue);
#endif

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);

		TElPGPWriter(TElPGPWriterHandle handle, TElOwnHandle ownHandle);

		explicit TElPGPWriter(TComponent &AOwner);

		explicit TElPGPWriter(TComponent *AOwner);

		virtual ~TElPGPWriter();

};
#endif /* SB_USE_CLASS_TELPGPWRITER */

#ifdef SB_USE_CLASS_TELPGPPROCESSINGUNIT
class TElPGPProcessingUnit: public TObject
{
	private:
		SB_DISABLE_COPY(TElPGPProcessingUnit)
#ifdef SB_USE_CLASS_TELPGPSTREAM
		TElPGPStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TELPGPSTREAM */
		TElPGPProcessingUnit* _Inst_Prev;

		void initInstances();

	public:
		int32_t Read(void * Buffer, int32_t Size);

		void Write(void * Buffer, int32_t Size);

		void NFinalize();

		virtual bool get_Atomic();

		SB_DECLARE_PROPERTY_GET(bool, get_Atomic, TElPGPProcessingUnit, Atomic);

		virtual bool get_Finished();

		SB_DECLARE_PROPERTY_GET(bool, get_Finished, TElPGPProcessingUnit, Finished);

#ifdef SB_USE_CLASS_TELPGPSTREAM
		virtual TElPGPStream* get_Stream();

		SB_DECLARE_PROPERTY_GET(TElPGPStream*, get_Stream, TElPGPProcessingUnit, Stream);
#endif /* SB_USE_CLASS_TELPGPSTREAM */

		virtual TElPGPProcessingUnit* get_Prev();

		SB_DECLARE_PROPERTY_GET(TElPGPProcessingUnit*, get_Prev, TElPGPProcessingUnit, Prev);

		virtual int64_t get_SkippedLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_SkippedLength, TElPGPProcessingUnit, SkippedLength);

		virtual int64_t get_ProcessedLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ProcessedLength, TElPGPProcessingUnit, ProcessedLength);

		virtual int32_t get_InputEncoding();

		virtual void set_InputEncoding(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_InputEncoding, set_InputEncoding, TElPGPProcessingUnit, InputEncoding);

		virtual bool get_IgnoreDataPacketLengths();

		virtual void set_IgnoreDataPacketLengths(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreDataPacketLengths, set_IgnoreDataPacketLengths, TElPGPProcessingUnit, IgnoreDataPacketLengths);

		virtual void get_OnNewStream(TSBPGPNewStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnNewStream(TSBPGPNewStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignature(TSBPGPSignatureEntityEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignature(TSBPGPSignatureEntityEvent pMethodValue, void * pDataValue);

		virtual void get_OnHashAlgorithm(TSBPGPHashAlgorithmEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHashAlgorithm(TSBPGPHashAlgorithmEvent pMethodValue, void * pDataValue);

		TElPGPProcessingUnit(TElPGPProcessingUnitHandle handle, TElOwnHandle ownHandle);

		TElPGPProcessingUnit();

		virtual ~TElPGPProcessingUnit();

};
#endif /* SB_USE_CLASS_TELPGPPROCESSINGUNIT */

#ifdef SB_USE_CLASS_TELPGPREADER
class TElPGPReader: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPGPReader)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_OutputStream;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_DecryptingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_VerifyingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		TElCustomFileSystemAdapter* _Inst_FileSystemAdapter;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		void initInstances();

	public:
		void DecryptAndVerifyFile(const std::string &ASourceFile);

		void VerifyDetachedFile(const std::string &ASourceFile, const std::string &ASignatureFile);

#ifdef SB_USE_CLASS_TSTREAM
		void DecryptAndVerify(TStream &ASourceStream, int64_t Count);

		void DecryptAndVerify(TStream *ASourceStream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void VerifyDetached(TStream &ASourceStream, TStream &ASignatureStream, int64_t SourceStreamCount, int64_t SignatureStreamCount);

		void VerifyDetached(TStream *ASourceStream, TStream *ASignatureStream, int64_t SourceStreamCount, int64_t SignatureStreamCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t get_EncryptionAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EncryptionAlgorithm, TElPGPReader, EncryptionAlgorithm);

		virtual int32_t get_CompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CompressionAlgorithm, TElPGPReader, CompressionAlgorithm);

		virtual TSBPGPProtectionType get_Protection();

		SB_DECLARE_PROPERTY_GET(TSBPGPProtectionType, get_Protection, TElPGPReader, Protection);

		virtual int64_t get_ProcessedLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ProcessedLength, TElPGPReader, ProcessedLength);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_OutputStream();

		virtual void set_OutputStream(TStream &Value);

		virtual void set_OutputStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_OutputStream, set_OutputStream, TElPGPReader, OutputStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_DecryptingKeys();

		virtual void set_DecryptingKeys(TElPGPKeyring &Value);

		virtual void set_DecryptingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_DecryptingKeys, set_DecryptingKeys, TElPGPReader, DecryptingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_VerifyingKeys();

		virtual void set_VerifyingKeys(TElPGPKeyring &Value);

		virtual void set_VerifyingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_VerifyingKeys, set_VerifyingKeys, TElPGPReader, VerifyingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual void get_OutputFile(std::string &OutResult);

		virtual void set_OutputFile(const std::string &Value);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual void get_KeyPassphrase(std::string &OutResult);

		virtual void set_KeyPassphrase(const std::string &Value);

		virtual TSBPGPMemoryConsumptionStrategy get_MemoryConsumptionStrategy();

		virtual void set_MemoryConsumptionStrategy(TSBPGPMemoryConsumptionStrategy Value);

		SB_DECLARE_PROPERTY(TSBPGPMemoryConsumptionStrategy, get_MemoryConsumptionStrategy, set_MemoryConsumptionStrategy, TElPGPReader, MemoryConsumptionStrategy);

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
		virtual TElCustomFileSystemAdapter* get_FileSystemAdapter();

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter &Value);

		virtual void set_FileSystemAdapter(TElCustomFileSystemAdapter *Value);

		SB_DECLARE_PROPERTY(TElCustomFileSystemAdapter*, get_FileSystemAdapter, set_FileSystemAdapter, TElPGPReader, FileSystemAdapter);
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

		virtual bool get_IgnoreDataPacketLengths();

		virtual void set_IgnoreDataPacketLengths(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreDataPacketLengths, set_IgnoreDataPacketLengths, TElPGPReader, IgnoreDataPacketLengths);

		virtual bool get_UndefInputLength();

		virtual void set_UndefInputLength(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UndefInputLength, set_UndefInputLength, TElPGPReader, UndefInputLength);

		virtual void get_OnArmored(TSBPGPArmoredEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnArmored(TSBPGPArmoredEvent pMethodValue, void * pDataValue);

		virtual void get_OnCompressed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCompressed(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCreateOutputStream(TSBPGPCreateOutputStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateOutputStream(TSBPGPCreateOutputStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnRequestOutputFile(TSBPGPRequestOutputFileEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRequestOutputFile(TSBPGPRequestOutputFileEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBPGPProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBPGPProgressEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue);

		virtual void get_OnFileExtractionStart(TSBPGPFileExtractionStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFileExtractionStart(TSBPGPFileExtractionStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnMultipleFilesFound(TSBPGPMultipleFilesFoundEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMultipleFilesFound(TSBPGPMultipleFilesFoundEvent pMethodValue, void * pDataValue);

		virtual void get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);

		TElPGPReader(TElPGPReaderHandle handle, TElOwnHandle ownHandle);

		explicit TElPGPReader(TComponent &AOwner);

		explicit TElPGPReader(TComponent *AOwner);

		virtual ~TElPGPReader();

};
#endif /* SB_USE_CLASS_TELPGPREADER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGP */
