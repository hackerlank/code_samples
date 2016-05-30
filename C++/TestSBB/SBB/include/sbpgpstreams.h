#ifndef __INC_SBPGPSTREAMS
#define __INC_SBPGPSTREAMS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbpgpkeys.h"
#include "sbpgpentities.h"
#include "sbpgpconstants.h"
#include "sbzlib.h"
#include "sbbzip2.h"
#include "sbsymmetriccrypto.h"
#include "sbhashfunction.h"
#include "sbpgputils.h"
#include "sbpgpmd.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPGPStreamHandle;

typedef TElPGPStreamHandle ElPGPStreamHandle;

typedef TElClassHandle TElPGPArmoringStreamHandle;

typedef TElPGPArmoringStreamHandle ElPGPArmoringStreamHandle;

typedef TElClassHandle TElPGPDearmoringStreamHandle;

typedef TElPGPDearmoringStreamHandle ElPGPDearmoringStreamHandle;

typedef TElClassHandle TElPGPEnvelopingStreamHandle;

typedef TElPGPEnvelopingStreamHandle ElPGPEnvelopingStreamHandle;

typedef TElClassHandle TElPGPUnenvelopingStreamHandle;

typedef TElPGPUnenvelopingStreamHandle ElPGPUnenvelopingStreamHandle;

typedef TElClassHandle TElPGPEncryptingStreamHandle;

typedef TElPGPEncryptingStreamHandle ElPGPEncryptingStreamHandle;

typedef TElClassHandle TElPGPDecryptingStreamHandle;

typedef TElPGPDecryptingStreamHandle ElPGPDecryptingStreamHandle;

typedef TElClassHandle TElPGPCompressingStreamHandle;

typedef TElPGPCompressingStreamHandle ElPGPCompressingStreamHandle;

typedef TElClassHandle TElPGPDecompressingStreamHandle;

typedef TElPGPDecompressingStreamHandle ElPGPDecompressingStreamHandle;

typedef TElClassHandle TElPGPSigningStreamHandle;

typedef TElPGPSigningStreamHandle ElPGPSigningStreamHandle;

typedef TElClassHandle TElPGPClearTextVerifyingStreamHandle;

typedef TElPGPClearTextVerifyingStreamHandle ElPGPClearTextVerifyingStreamHandle;

typedef TElClassHandle TElPGPEntityStreamHandle;

typedef TElPGPEntityStreamHandle ElPGPEntityStreamHandle;

typedef uint8_t TSBPGPSignatureValidityRaw;

typedef enum
{
	svValid = 0,
	svCorrupted = 1,
	svUnknownAlgorithm = 2,
	svNoKey = 3,
	svUnknown = 4
} TSBPGPSignatureValidity;

typedef void (SB_CALLBACK *TSBOutputFunc)(void * _ObjectData, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBInputFunc)(void * _ObjectData, void * Buffer, int32_t Size, int8_t * Last, int32_t * OutResult);

typedef void (SB_CALLBACK *TSBPGPPassphraseEvent)(void * _ObjectData, TObjectHandle Sender, char * pcPassphrase, int32_t * szPassphrase, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBPGPKeyPassphraseEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPCustomSecretKeyHandle Key, char * pcPassphrase, int32_t * szPassphrase, int8_t * Cancel);

typedef void (SB_CALLBACK *TSBPGPSignaturesEvent)(void * _ObjectData, TObjectHandle Sender, const TElPGPSignatureHandle pSignatures[], int32_t szSignatures, const TSBPGPSignatureValidityRaw pValidities[], int32_t szValidities);

typedef void (SB_CALLBACK *TSBPGPKeyIDsEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pKeyIDs[][8], int32_t szKeyIDs);

typedef TElClassHandle TElPGPStreamClassHandle;

typedef TElPGPStreamClassHandle ElPGPStreamClassHandle;

#ifdef SB_USE_CLASS_TELPGPSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_DataAvailable(TElPGPStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_Process(TElPGPStreamHandle _Handle, void * AReadUserData, void * AWriteUserData);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_ProcessStream(TElPGPStreamHandle _Handle, TStreamHandle AInputStream, TStreamHandle AOutputStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_PassTo(TElPGPStreamHandle _Handle, TElPGPStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_PassTo(TElPGPStreamHandle _Handle, TElPGPStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_UseOldPackets(TElPGPStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_UseOldPackets(TElPGPStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_ProcessedLength(TElPGPStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_IgnoreDataPacketLengthTag(TElPGPStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_IgnoreDataPacketLengthTag(TElPGPStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_OnRead(TElPGPStreamHandle _Handle, TSBPGPReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_OnRead(TElPGPStreamHandle _Handle, TSBPGPReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_OnWrite(TElPGPStreamHandle _Handle, TSBPGPWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_OnWrite(TElPGPStreamHandle _Handle, TSBPGPWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_OnFinish(TElPGPStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_OnFinish(TElPGPStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_get_OnTemporaryStream(TElPGPStreamHandle _Handle, TSBPGPTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_set_OnTemporaryStream(TElPGPStreamHandle _Handle, TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPStream_Create(TElPGPStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSTREAM */

#ifdef SB_USE_CLASS_TELPGPARMORINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_DataAvailable(TElPGPArmoringStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_get_LineLength(TElPGPArmoringStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_set_LineLength(TElPGPArmoringStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_get_Boundary(TElPGPArmoringStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_set_Boundary(TElPGPArmoringStreamHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_get_Headers(TElPGPArmoringStreamHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPArmoringStream_Create(TElPGPArmoringStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDEARMORINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_DataAvailable(TElPGPDearmoringStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_get_Boundary(TElPGPDearmoringStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_get_Headers(TElPGPDearmoringStreamHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_get_MultiPart(TElPGPDearmoringStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_set_MultiPart(TElPGPDearmoringStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_get_InputEncoding(TElPGPDearmoringStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_set_InputEncoding(TElPGPDearmoringStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_get_OnInfo(TElPGPDearmoringStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_set_OnInfo(TElPGPDearmoringStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDearmoringStream_Create(TElPGPDearmoringStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPDEARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENVELOPINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_DataAvailable(TElPGPEnvelopingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_AddSignature(TElPGPEnvelopingStreamHandle _Handle, TElPGPSignatureHandle Signature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_RemoveSignature(TElPGPEnvelopingStreamHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_ClearSignatures(TElPGPEnvelopingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_Filename(TElPGPEnvelopingStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_set_Filename(TElPGPEnvelopingStreamHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_Timestamp(TElPGPEnvelopingStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_set_Timestamp(TElPGPEnvelopingStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_TextMode(TElPGPEnvelopingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_set_TextMode(TElPGPEnvelopingStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_Signatures(TElPGPEnvelopingStreamHandle _Handle, int32_t Index, TElPGPSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_SignatureCount(TElPGPEnvelopingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_get_UseOnePassSignatures(TElPGPEnvelopingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_set_UseOnePassSignatures(TElPGPEnvelopingStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEnvelopingStream_Create(TElPGPEnvelopingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_DataAvailable(TElPGPUnenvelopingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_DataCompleted(TElPGPUnenvelopingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_Filename(TElPGPUnenvelopingStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_Timestamp(TElPGPUnenvelopingStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_set_Timestamp(TElPGPUnenvelopingStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_HashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_set_HashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_TextHashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_set_TextHashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_BuggyTextHashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_set_BuggyTextHashingPool(TElPGPUnenvelopingStreamHandle _Handle, TElPGPHashingPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_get_OnInfo(TElPGPUnenvelopingStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_set_OnInfo(TElPGPUnenvelopingStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUnenvelopingStream_Create(TElPGPUnenvelopingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENCRYPTINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_DataAvailable(TElPGPEncryptingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_Keyring(TElPGPEncryptingStreamHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_set_Keyring(TElPGPEncryptingStreamHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_Passphrases(TElPGPEncryptingStreamHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_IntegrityProtected(TElPGPEncryptingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_set_IntegrityProtected(TElPGPEncryptingStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_Algorithm(TElPGPEncryptingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_set_Algorithm(TElPGPEncryptingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_PassphraseAlgorithm(TElPGPEncryptingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_set_PassphraseAlgorithm(TElPGPEncryptingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_get_Protection(TElPGPEncryptingStreamHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_set_Protection(TElPGPEncryptingStreamHandle _Handle, TSBPGPProtectionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEncryptingStream_Create(TElPGPEncryptingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECRYPTINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_DataAvailable(TElPGPDecryptingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_Keyring(TElPGPDecryptingStreamHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_set_Keyring(TElPGPDecryptingStreamHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_IntegrityProtected(TElPGPDecryptingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_Algorithm(TElPGPDecryptingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_Protection(TElPGPDecryptingStreamHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_SymmetricallyEncrypted(TElPGPDecryptingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_OnPassphrase(TElPGPDecryptingStreamHandle _Handle, TSBPGPPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_set_OnPassphrase(TElPGPDecryptingStreamHandle _Handle, TSBPGPPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_OnKeyPassphrase(TElPGPDecryptingStreamHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_set_OnKeyPassphrase(TElPGPDecryptingStreamHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_OnKeyIDs(TElPGPDecryptingStreamHandle _Handle, TSBPGPKeyIDsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_set_OnKeyIDs(TElPGPDecryptingStreamHandle _Handle, TSBPGPKeyIDsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_get_OnDecryptionStart(TElPGPDecryptingStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_set_OnDecryptionStart(TElPGPDecryptingStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecryptingStream_Create(TElPGPDecryptingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPDECRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_DataAvailable(TElPGPCompressingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_get_Algorithm(TElPGPCompressingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_set_Algorithm(TElPGPCompressingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_get_CompressionLevel(TElPGPCompressingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_set_CompressionLevel(TElPGPCompressingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCompressingStream_Create(TElPGPCompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_DataAvailable(TElPGPDecompressingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_get_Algorithm(TElPGPDecompressingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_get_OnDecompressionStart(TElPGPDecompressingStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_set_OnDecompressionStart(TElPGPDecompressingStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPDecompressingStream_Create(TElPGPDecompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPSIGNINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_DataAvailable(TElPGPSigningStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_get_HashAlgorithm(TElPGPSigningStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_set_HashAlgorithm(TElPGPSigningStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_get_Keyring(TElPGPSigningStreamHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_set_Keyring(TElPGPSigningStreamHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_get_Headers(TElPGPSigningStreamHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_get_OnKeyPassphrase(TElPGPSigningStreamHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_set_OnKeyPassphrase(TElPGPSigningStreamHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSigningStream_Create(TElPGPSigningStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSIGNINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_DataAvailable(TElPGPClearTextVerifyingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_get_Keyring(TElPGPClearTextVerifyingStreamHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_set_Keyring(TElPGPClearTextVerifyingStreamHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_get_InputEncoding(TElPGPClearTextVerifyingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_set_InputEncoding(TElPGPClearTextVerifyingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_get_OnKeyIDs(TElPGPClearTextVerifyingStreamHandle _Handle, TSBPGPKeyIDsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_set_OnKeyIDs(TElPGPClearTextVerifyingStreamHandle _Handle, TSBPGPKeyIDsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_get_OnSignatures(TElPGPClearTextVerifyingStreamHandle _Handle, TSBPGPSignaturesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_set_OnSignatures(TElPGPClearTextVerifyingStreamHandle _Handle, TSBPGPSignaturesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPClearTextVerifyingStream_Create(TElPGPClearTextVerifyingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENTITYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElPGPEntityStream_DataAvailable(TElPGPEntityStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEntityStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEntityStream_get_Entity(TElPGPEntityStreamHandle _Handle, TElPGPEntityHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEntityStream_Create(TElPGPEntityStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPEntityStream_Create_1(uint8_t PktType, TElPGPEntityStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPENTITYSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPGPStream;
typedef TElPGPStream ElPGPStream;
class TElPGPArmoringStream;
typedef TElPGPArmoringStream ElPGPArmoringStream;
class TElPGPDearmoringStream;
typedef TElPGPDearmoringStream ElPGPDearmoringStream;
class TElPGPEnvelopingStream;
typedef TElPGPEnvelopingStream ElPGPEnvelopingStream;
class TElPGPUnenvelopingStream;
typedef TElPGPUnenvelopingStream ElPGPUnenvelopingStream;
class TElPGPEncryptingStream;
typedef TElPGPEncryptingStream ElPGPEncryptingStream;
class TElPGPDecryptingStream;
typedef TElPGPDecryptingStream ElPGPDecryptingStream;
class TElPGPCompressingStream;
typedef TElPGPCompressingStream ElPGPCompressingStream;
class TElPGPDecompressingStream;
typedef TElPGPDecompressingStream ElPGPDecompressingStream;
class TElPGPSigningStream;
typedef TElPGPSigningStream ElPGPSigningStream;
class TElPGPClearTextVerifyingStream;
typedef TElPGPClearTextVerifyingStream ElPGPClearTextVerifyingStream;
class TElPGPEntityStream;
typedef TElPGPEntityStream ElPGPEntityStream;

#ifdef SB_USE_CLASS_TELPGPSTREAM
class TElPGPStream: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPStream)
		TElPGPStream* _Inst_PassTo;

		void initInstances();

	public:
		virtual void DataAvailable();

		void Process(void * AReadUserData, void * AWriteUserData);

#ifdef SB_USE_CLASS_TSTREAM
		void ProcessStream(TStream &AInputStream, TStream &AOutputStream, int32_t Count);

		void ProcessStream(TStream *AInputStream, TStream *AOutputStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		static TClassHandle ClassType();

		virtual TElPGPStream* get_PassTo();

		virtual void set_PassTo(TElPGPStream &Value);

		virtual void set_PassTo(TElPGPStream *Value);

		SB_DECLARE_PROPERTY(TElPGPStream*, get_PassTo, set_PassTo, TElPGPStream, PassTo);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElPGPStream, UseOldPackets);

		virtual int64_t get_ProcessedLength();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ProcessedLength, TElPGPStream, ProcessedLength);

		virtual bool get_IgnoreDataPacketLengthTag();

		virtual void set_IgnoreDataPacketLengthTag(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreDataPacketLengthTag, set_IgnoreDataPacketLengthTag, TElPGPStream, IgnoreDataPacketLengthTag);

		virtual void get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue);

		TElPGPStream(TElPGPStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPStream();

		virtual ~TElPGPStream();

};
#endif /* SB_USE_CLASS_TELPGPSTREAM */

#ifdef SB_USE_CLASS_TELPGPARMORINGSTREAM
class TElPGPArmoringStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPArmoringStream)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

		virtual int32_t get_LineLength();

		virtual void set_LineLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_LineLength, set_LineLength, TElPGPArmoringStream, LineLength);

		virtual void get_Boundary(std::string &OutResult);

		virtual void set_Boundary(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Headers, TElPGPArmoringStream, Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		TElPGPArmoringStream(TElPGPArmoringStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPArmoringStream();

		virtual ~TElPGPArmoringStream();

};
#endif /* SB_USE_CLASS_TELPGPARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDEARMORINGSTREAM
class TElPGPDearmoringStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPDearmoringStream)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

		virtual void get_Boundary(std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Headers, TElPGPDearmoringStream, Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual bool get_MultiPart();

		virtual void set_MultiPart(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MultiPart, set_MultiPart, TElPGPDearmoringStream, MultiPart);

		virtual int32_t get_InputEncoding();

		virtual void set_InputEncoding(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_InputEncoding, set_InputEncoding, TElPGPDearmoringStream, InputEncoding);

		virtual void get_OnInfo(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInfo(TNotifyEvent pMethodValue, void * pDataValue);

		TElPGPDearmoringStream(TElPGPDearmoringStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPDearmoringStream();

		virtual ~TElPGPDearmoringStream();

};
#endif /* SB_USE_CLASS_TELPGPDEARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENVELOPINGSTREAM
class TElPGPEnvelopingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPEnvelopingStream)
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		TElPGPSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void initInstances();

	public:
		virtual void DataAvailable();

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		int32_t AddSignature(TElPGPSignature &Signature);

		int32_t AddSignature(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void RemoveSignature(int32_t Index);

		void ClearSignatures();

		static TClassHandle ClassType();

		virtual void get_Filename(std::string &OutResult);

		virtual void set_Filename(const std::string &Value);

		virtual int64_t get_Timestamp();

		virtual void set_Timestamp(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Timestamp, set_Timestamp, TElPGPEnvelopingStream, Timestamp);

		virtual bool get_TextMode();

		virtual void set_TextMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TextMode, set_TextMode, TElPGPEnvelopingStream, TextMode);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		virtual TElPGPSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElPGPEnvelopingStream, SignatureCount);

		virtual bool get_UseOnePassSignatures();

		virtual void set_UseOnePassSignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOnePassSignatures, set_UseOnePassSignatures, TElPGPEnvelopingStream, UseOnePassSignatures);

		TElPGPEnvelopingStream(TElPGPEnvelopingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPEnvelopingStream();

		virtual ~TElPGPEnvelopingStream();

};
#endif /* SB_USE_CLASS_TELPGPENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM
class TElPGPUnenvelopingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPUnenvelopingStream)
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		TElPGPHashingPool* _Inst_HashingPool;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		TElPGPHashingPool* _Inst_TextHashingPool;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		TElPGPHashingPool* _Inst_BuggyTextHashingPool;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

		void initInstances();

	public:
		virtual void DataAvailable();

		bool DataCompleted();

		static TClassHandle ClassType();

		virtual void get_Filename(std::string &OutResult);

		virtual int64_t get_Timestamp();

		virtual void set_Timestamp(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Timestamp, set_Timestamp, TElPGPUnenvelopingStream, Timestamp);

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		virtual TElPGPHashingPool* get_HashingPool();

		virtual void set_HashingPool(TElPGPHashingPool &Value);

		virtual void set_HashingPool(TElPGPHashingPool *Value);

		SB_DECLARE_PROPERTY(TElPGPHashingPool*, get_HashingPool, set_HashingPool, TElPGPUnenvelopingStream, HashingPool);
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		virtual TElPGPHashingPool* get_TextHashingPool();

		virtual void set_TextHashingPool(TElPGPHashingPool &Value);

		virtual void set_TextHashingPool(TElPGPHashingPool *Value);

		SB_DECLARE_PROPERTY(TElPGPHashingPool*, get_TextHashingPool, set_TextHashingPool, TElPGPUnenvelopingStream, TextHashingPool);
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
		virtual TElPGPHashingPool* get_BuggyTextHashingPool();

		virtual void set_BuggyTextHashingPool(TElPGPHashingPool &Value);

		virtual void set_BuggyTextHashingPool(TElPGPHashingPool *Value);

		SB_DECLARE_PROPERTY(TElPGPHashingPool*, get_BuggyTextHashingPool, set_BuggyTextHashingPool, TElPGPUnenvelopingStream, BuggyTextHashingPool);
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

		virtual void get_OnInfo(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnInfo(TNotifyEvent pMethodValue, void * pDataValue);

		TElPGPUnenvelopingStream(TElPGPUnenvelopingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPUnenvelopingStream();

		virtual ~TElPGPUnenvelopingStream();

};
#endif /* SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENCRYPTINGSTREAM
class TElPGPEncryptingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPEncryptingStream)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keyring;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keyring();

		virtual void set_Keyring(TElPGPKeyring &Value);

		virtual void set_Keyring(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_Keyring, set_Keyring, TElPGPEncryptingStream, Keyring);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Passphrases();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Passphrases, TElPGPEncryptingStream, Passphrases);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual bool get_IntegrityProtected();

		virtual void set_IntegrityProtected(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IntegrityProtected, set_IntegrityProtected, TElPGPEncryptingStream, IntegrityProtected);

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElPGPEncryptingStream, Algorithm);

		virtual int32_t get_PassphraseAlgorithm();

		virtual void set_PassphraseAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PassphraseAlgorithm, set_PassphraseAlgorithm, TElPGPEncryptingStream, PassphraseAlgorithm);

		virtual TSBPGPProtectionType get_Protection();

		virtual void set_Protection(TSBPGPProtectionType Value);

		SB_DECLARE_PROPERTY(TSBPGPProtectionType, get_Protection, set_Protection, TElPGPEncryptingStream, Protection);

		TElPGPEncryptingStream(TElPGPEncryptingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPEncryptingStream();

		virtual ~TElPGPEncryptingStream();

};
#endif /* SB_USE_CLASS_TELPGPENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECRYPTINGSTREAM
class TElPGPDecryptingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPDecryptingStream)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keyring;
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keyring();

		virtual void set_Keyring(TElPGPKeyring &Value);

		virtual void set_Keyring(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_Keyring, set_Keyring, TElPGPDecryptingStream, Keyring);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual bool get_IntegrityProtected();

		SB_DECLARE_PROPERTY_GET(bool, get_IntegrityProtected, TElPGPDecryptingStream, IntegrityProtected);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElPGPDecryptingStream, Algorithm);

		virtual TSBPGPProtectionType get_Protection();

		SB_DECLARE_PROPERTY_GET(TSBPGPProtectionType, get_Protection, TElPGPDecryptingStream, Protection);

		virtual bool get_SymmetricallyEncrypted();

		SB_DECLARE_PROPERTY_GET(bool, get_SymmetricallyEncrypted, TElPGPDecryptingStream, SymmetricallyEncrypted);

		virtual void get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyIDs(TSBPGPKeyIDsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyIDs(TSBPGPKeyIDsEvent pMethodValue, void * pDataValue);

		virtual void get_OnDecryptionStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecryptionStart(TNotifyEvent pMethodValue, void * pDataValue);

		TElPGPDecryptingStream(TElPGPDecryptingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPDecryptingStream();

		virtual ~TElPGPDecryptingStream();

};
#endif /* SB_USE_CLASS_TELPGPDECRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM
class TElPGPCompressingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPCompressingStream)
	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElPGPCompressingStream, Algorithm);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElPGPCompressingStream, CompressionLevel);

		TElPGPCompressingStream(TElPGPCompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPCompressingStream();

};
#endif /* SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM
class TElPGPDecompressingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPDecompressingStream)
	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElPGPDecompressingStream, Algorithm);

		virtual void get_OnDecompressionStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDecompressionStart(TNotifyEvent pMethodValue, void * pDataValue);

		TElPGPDecompressingStream(TElPGPDecompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPDecompressingStream();

};
#endif /* SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPSIGNINGSTREAM
class TElPGPSigningStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPSigningStream)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keyring;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElPGPSigningStream, HashAlgorithm);

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keyring();

		virtual void set_Keyring(TElPGPKeyring &Value);

		virtual void set_Keyring(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_Keyring, set_Keyring, TElPGPSigningStream, Keyring);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Headers, TElPGPSigningStream, Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		TElPGPSigningStream(TElPGPSigningStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPSigningStream();

		virtual ~TElPGPSigningStream();

};
#endif /* SB_USE_CLASS_TELPGPSIGNINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM
class TElPGPClearTextVerifyingStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPClearTextVerifyingStream)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keyring;
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keyring();

		virtual void set_Keyring(TElPGPKeyring &Value);

		virtual void set_Keyring(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_Keyring, set_Keyring, TElPGPClearTextVerifyingStream, Keyring);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual int32_t get_InputEncoding();

		virtual void set_InputEncoding(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_InputEncoding, set_InputEncoding, TElPGPClearTextVerifyingStream, InputEncoding);

		virtual void get_OnKeyIDs(TSBPGPKeyIDsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyIDs(TSBPGPKeyIDsEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue);

		TElPGPClearTextVerifyingStream(TElPGPClearTextVerifyingStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPClearTextVerifyingStream();

		virtual ~TElPGPClearTextVerifyingStream();

};
#endif /* SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENTITYSTREAM
class TElPGPEntityStream: public TElPGPStream
{
	private:
		SB_DISABLE_COPY(TElPGPEntityStream)
#ifdef SB_USE_CLASS_TELPGPENTITY
		TElPGPEntity* _Inst_Entity;
#endif /* SB_USE_CLASS_TELPGPENTITY */

		void initInstances();

	public:
		virtual void DataAvailable();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPGPENTITY
		virtual TElPGPEntity* get_Entity();

		SB_DECLARE_PROPERTY_GET(TElPGPEntity*, get_Entity, TElPGPEntityStream, Entity);
#endif /* SB_USE_CLASS_TELPGPENTITY */

		TElPGPEntityStream(TElPGPEntityStreamHandle handle, TElOwnHandle ownHandle);

		TElPGPEntityStream();

		explicit TElPGPEntityStream(uint8_t PktType);

		virtual ~TElPGPEntityStream();

};
#endif /* SB_USE_CLASS_TELPGPENTITYSTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPSTREAMS */

