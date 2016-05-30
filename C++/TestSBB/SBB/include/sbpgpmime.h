#ifndef __INC_SBPGPMIME
#define __INC_SBPGPMIME

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbmime.h"
#include "sbmimestream.h"
#include "sbsimplemime.h"
#include "sbpgpconstants.h"
#include "sbpgpkeys.h"
#include "sbpgp.h"
#include "sbpgpentities.h"
#include "sbpgputils.h"
#include "sbpgpstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElMessagePartHandlerPGPMimeHandle;

typedef TElClassHandle TElMessagePartHandlerPGPKeysHandle;

typedef TElClassHandle TElSimplePGPMIMEOptionsHandle;

typedef TElClassHandle TElSimplePGPMIMEMessageHandle;

typedef TElMessagePartHandlerPGPMimeHandle ElMessagePartHandlerPGPMimeHandle;

typedef TElMessagePartHandlerPGPKeysHandle ElMessagePartHandlerPGPKeysHandle;

typedef TElSimplePGPMIMEOptionsHandle ElSimplePGPMIMEOptionsHandle;

typedef TElSimplePGPMIMEMessageHandle ElSimplePGPMIMEMessageHandle;

typedef uint8_t TSBPGPMIMETypeRaw;

typedef enum
{
	pmtUnknown = 0,
	pmtSigned = 1,
	pmtEncrypted = 2,
	pmtSignedEncrypted = 3
} TSBPGPMIMEType;

typedef uint8_t TSBPGPMIMEErrorRaw;

typedef enum
{
	pmeUnknown = 0,
	pmePGPPartNotFound = 1,
	pmeInvalidSignature = 2,
	pmeUnverifiableSignature = 3,
	pmeRecipientKeyNotFound = 4,
	pmeSenderKeyNotFound = 5,
	pmeNoRecipients = 6,
	pmeNoSigners = 7,
	pmeActionNotSelected = 8
} TSBPGPMIMEError;

typedef uint32_t TSBPGPMIMEErrorsRaw;

typedef enum 
{
	f_pmeUnknown = 1,
	f_pmePGPPartNotFound = 2,
	f_pmeInvalidSignature = 4,
	f_pmeUnverifiableSignature = 8,
	f_pmeRecipientKeyNotFound = 16,
	f_pmeSenderKeyNotFound = 32,
	f_pmeNoRecipients = 64,
	f_pmeNoSigners = 128,
	f_pmeActionNotSelected = 256
} TSBPGPMIMEErrors;

typedef uint8_t TSBPGPKeysErrorRaw;

typedef enum
{
	pkeUnknown = 0,
	pkeKeysPartNotFound = 1,
	pkeNoPublicKeys = 2
} TSBPGPKeysError;

typedef uint32_t TSBPGPKeysErrorsRaw;

typedef enum 
{
	f_pkeUnknown = 1,
	f_pkeKeysPartNotFound = 2,
	f_pkeNoPublicKeys = 4
} TSBPGPKeysErrors;

typedef void (SB_CALLBACK *TSBPGPKeyNotFoundEvent)(void * _ObjectData, TObjectHandle Sender, TElMailAddressHandle Address, int8_t * ExcludeFromList);

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_GetDescription(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_GetDescription_1(TElMessagePartHandlerPGPMimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_IsSigned(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_IsEncrypted(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Errors(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPMIMEErrorsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Encrypt(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Encrypt(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Sign(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Sign(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Compress(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Compress(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_IgnoreHeaderRecipients(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_IgnoreHeaderRecipients(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_IgnoreHeaderSigners(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_IgnoreHeaderSigners(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_DecryptingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_DecryptingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_VerifyingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_VerifyingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_EncryptingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_EncryptingKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_SigningKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_SigningKeys(TElMessagePartHandlerPGPMimeHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_EncryptionType(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPEncryptionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_EncryptionType(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPEncryptionTypeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Passphrases(TElMessagePartHandlerPGPMimeHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Passphrases(TElMessagePartHandlerPGPMimeHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Passphrases(TElMessagePartHandlerPGPMimeHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Passphrases(TElMessagePartHandlerPGPMimeHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_Protection(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_Protection(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPProtectionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_CompressionAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_CompressionAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_CompressionLevel(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_CompressionLevel(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_HashAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_HashAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_SymmetricKeyAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_SymmetricKeyAlgorithm(TElMessagePartHandlerPGPMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_UseNewFeatures(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_UseNewFeatures(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_UseOldPackets(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_UseOldPackets(TElMessagePartHandlerPGPMimeHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_ArmorHeaders(TElMessagePartHandlerPGPMimeHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_ArmorHeaders(TElMessagePartHandlerPGPMimeHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_ArmorHeaders(TElMessagePartHandlerPGPMimeHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_ArmorHeaders(TElMessagePartHandlerPGPMimeHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnEncrypted(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPEncryptedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnEncrypted(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPEncryptedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnSigned(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPSignedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnSigned(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPSignedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnKeyPassphrase(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnKeyPassphrase(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnPassphrase(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnPassphrase(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnSignatures(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPSignaturesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnSignatures(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPSignaturesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnEncryptingKeyNotFound(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyNotFoundEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnEncryptingKeyNotFound(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_get_OnSigningKeyNotFound(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyNotFoundEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_set_OnSigningKeyNotFound(TElMessagePartHandlerPGPMimeHandle _Handle, TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPMime_Create(TObjectHandle aParams, TElMessagePartHandlerPGPMimeHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPKeys_GetDescription(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPKeys_GetDescription_1(TElMessagePartHandlerPGPKeysHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPKeys_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPKeys_get_Keys(TElMessagePartHandlerPGPKeysHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerPGPKeys_Create(TObjectHandle aParams, TElMessagePartHandlerPGPKeysHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_Assign(TElSimplePGPMIMEOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_EncryptionType(TElSimplePGPMIMEOptionsHandle _Handle, TSBPGPEncryptionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_EncryptionType(TElSimplePGPMIMEOptionsHandle _Handle, TSBPGPEncryptionTypeRaw Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_Passphrases(TElSimplePGPMIMEOptionsHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_Passphrases(TElSimplePGPMIMEOptionsHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_Passphrases(TElSimplePGPMIMEOptionsHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_Passphrases(TElSimplePGPMIMEOptionsHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_Protection(TElSimplePGPMIMEOptionsHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_Protection(TElSimplePGPMIMEOptionsHandle _Handle, TSBPGPProtectionTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_HashAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_HashAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_CompressionAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_CompressionAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_CompressionLevel(TElSimplePGPMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_CompressionLevel(TElSimplePGPMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_SymmetricKeyAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_SymmetricKeyAlgorithm(TElSimplePGPMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_UseOldPackets(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_UseOldPackets(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_UseNewFeatures(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_UseNewFeatures(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_CompressMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_CompressMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_EncryptMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_EncryptMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_IgnoreHeaderRecipients(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_IgnoreHeaderRecipients(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_IgnoreHeaderSigners(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_IgnoreHeaderSigners(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_SignMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_SignMessage(TElSimplePGPMIMEOptionsHandle _Handle, int8_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_ArmorHeaders(TElSimplePGPMIMEOptionsHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_ArmorHeaders(TElSimplePGPMIMEOptionsHandle _Handle, TStringListHandle Value);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_get_ArmorHeaders(TElSimplePGPMIMEOptionsHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_set_ArmorHeaders(TElSimplePGPMIMEOptionsHandle _Handle, TElStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEOptions_Create(TElSimplePGPMIMEOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_EncryptingKeys(TElSimplePGPMIMEMessageHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_EncryptingKeys(TElSimplePGPMIMEMessageHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_PGPMIMEOptions(TElSimplePGPMIMEMessageHandle _Handle, TElSimplePGPMIMEOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_PGPMIMEOptions(TElSimplePGPMIMEMessageHandle _Handle, TElSimplePGPMIMEOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_SigningKeys(TElSimplePGPMIMEMessageHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_SigningKeys(TElSimplePGPMIMEMessageHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_OnEncryptingKeyNotFound(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyNotFoundEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_OnEncryptingKeyNotFound(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_OnKeyPassphrase(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyPassphraseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_OnKeyPassphrase(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_get_OnSigningKeyNotFound(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyNotFoundEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_set_OnSigningKeyNotFound(TElSimplePGPMIMEMessageHandle _Handle, TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimplePGPMIMEMessage_Create(TComponentHandle AOwner, TElSimplePGPMIMEMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMessagePartHandlerPGPMime;
class TElMessagePartHandlerPGPKeys;
class TElSimplePGPMIMEOptions;
class TElSimplePGPMIMEMessage;
typedef TElMessagePartHandlerPGPMime ElMessagePartHandlerPGPMime;
typedef TElMessagePartHandlerPGPKeys ElMessagePartHandlerPGPKeys;
typedef TElSimplePGPMIMEOptions ElSimplePGPMIMEOptions;
typedef TElSimplePGPMIMEMessage ElSimplePGPMIMEMessage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPGPMIMEErrors)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPGPKeysErrors)

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME
class TElMessagePartHandlerPGPMime: public TElMessagePartHandler
{
	private:
		SB_DISABLE_COPY(TElMessagePartHandlerPGPMime)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_DecryptingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_VerifyingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_EncryptingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_SigningKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		static void GetDescription(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDescription(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDescription_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDescription_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		bool IsSigned();

		bool IsEncrypted();

		static TClassHandle ClassType();

		virtual TSBPGPMIMEErrors get_Errors();

		SB_DECLARE_PROPERTY_GET(TSBPGPMIMEErrors, get_Errors, TElMessagePartHandlerPGPMime, Errors);

		virtual bool get_Encrypt();

		virtual void set_Encrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Encrypt, set_Encrypt, TElMessagePartHandlerPGPMime, Encrypt);

		virtual bool get_Sign();

		virtual void set_Sign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sign, set_Sign, TElMessagePartHandlerPGPMime, Sign);

		virtual bool get_Compress();

		virtual void set_Compress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Compress, set_Compress, TElMessagePartHandlerPGPMime, Compress);

		virtual bool get_IgnoreHeaderRecipients();

		virtual void set_IgnoreHeaderRecipients(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreHeaderRecipients, set_IgnoreHeaderRecipients, TElMessagePartHandlerPGPMime, IgnoreHeaderRecipients);

		virtual bool get_IgnoreHeaderSigners();

		virtual void set_IgnoreHeaderSigners(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreHeaderSigners, set_IgnoreHeaderSigners, TElMessagePartHandlerPGPMime, IgnoreHeaderSigners);

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_DecryptingKeys();

		virtual void set_DecryptingKeys(TElPGPKeyring &Value);

		virtual void set_DecryptingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_DecryptingKeys, set_DecryptingKeys, TElMessagePartHandlerPGPMime, DecryptingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_VerifyingKeys();

		virtual void set_VerifyingKeys(TElPGPKeyring &Value);

		virtual void set_VerifyingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_VerifyingKeys, set_VerifyingKeys, TElMessagePartHandlerPGPMime, VerifyingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_EncryptingKeys();

		virtual void set_EncryptingKeys(TElPGPKeyring &Value);

		virtual void set_EncryptingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_EncryptingKeys, set_EncryptingKeys, TElMessagePartHandlerPGPMime, EncryptingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_SigningKeys();

		virtual void set_SigningKeys(TElPGPKeyring &Value);

		virtual void set_SigningKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_SigningKeys, set_SigningKeys, TElMessagePartHandlerPGPMime, SigningKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual TSBPGPEncryptionType get_EncryptionType();

		virtual void set_EncryptionType(TSBPGPEncryptionType Value);

		SB_DECLARE_PROPERTY(TSBPGPEncryptionType, get_EncryptionType, set_EncryptionType, TElMessagePartHandlerPGPMime, EncryptionType);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Passphrases();

		virtual void set_Passphrases(TStringList &Value);

		virtual void set_Passphrases(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_Passphrases, set_Passphrases, TElMessagePartHandlerPGPMime, Passphrases);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Passphrases();

		virtual void set_Passphrases(TElStringList &Value);

		virtual void set_Passphrases(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_Passphrases, set_Passphrases, TElMessagePartHandlerPGPMime, Passphrases);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBPGPProtectionType get_Protection();

		virtual void set_Protection(TSBPGPProtectionType Value);

		SB_DECLARE_PROPERTY(TSBPGPProtectionType, get_Protection, set_Protection, TElMessagePartHandlerPGPMime, Protection);

		virtual int32_t get_CompressionAlgorithm();

		virtual void set_CompressionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionAlgorithm, set_CompressionAlgorithm, TElMessagePartHandlerPGPMime, CompressionAlgorithm);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElMessagePartHandlerPGPMime, CompressionLevel);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElMessagePartHandlerPGPMime, HashAlgorithm);

		virtual int32_t get_SymmetricKeyAlgorithm();

		virtual void set_SymmetricKeyAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SymmetricKeyAlgorithm, set_SymmetricKeyAlgorithm, TElMessagePartHandlerPGPMime, SymmetricKeyAlgorithm);

		virtual bool get_UseNewFeatures();

		virtual void set_UseNewFeatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNewFeatures, set_UseNewFeatures, TElMessagePartHandlerPGPMime, UseNewFeatures);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElMessagePartHandlerPGPMime, UseOldPackets);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		virtual void set_ArmorHeaders(TStringList &Value);

		virtual void set_ArmorHeaders(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_ArmorHeaders, set_ArmorHeaders, TElMessagePartHandlerPGPMime, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ArmorHeaders();

		virtual void set_ArmorHeaders(TElStringList &Value);

		virtual void set_ArmorHeaders(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_ArmorHeaders, set_ArmorHeaders, TElMessagePartHandlerPGPMime, ArmorHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual void get_OnEncrypted(TSBPGPEncryptedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncrypted(TSBPGPEncryptedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigned(TSBPGPSignedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigned(TSBPGPSignedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue);

		virtual void get_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);

		TElMessagePartHandlerPGPMime(TElMessagePartHandlerPGPMimeHandle handle, TElOwnHandle ownHandle);

		explicit TElMessagePartHandlerPGPMime(TObject &aParams);

		explicit TElMessagePartHandlerPGPMime(TObject *aParams);

		virtual ~TElMessagePartHandlerPGPMime();

};
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPMIME */

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS
class TElMessagePartHandlerPGPKeys: public TElMessagePartHandler
{
	private:
		SB_DISABLE_COPY(TElMessagePartHandlerPGPKeys)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		void initInstances();

	public:
		static void GetDescription(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDescription(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDescription_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDescription_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keys();

		SB_DECLARE_PROPERTY_GET(TElPGPKeyring*, get_Keys, TElMessagePartHandlerPGPKeys, Keys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		TElMessagePartHandlerPGPKeys(TElMessagePartHandlerPGPKeysHandle handle, TElOwnHandle ownHandle);

		explicit TElMessagePartHandlerPGPKeys(TObject &aParams);

		explicit TElMessagePartHandlerPGPKeys(TObject *aParams);

		virtual ~TElMessagePartHandlerPGPKeys();

};
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERPGPKEYS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
class TElSimplePGPMIMEOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSimplePGPMIMEOptions)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Passphrases;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual TSBPGPEncryptionType get_EncryptionType();

		virtual void set_EncryptionType(TSBPGPEncryptionType Value);

		SB_DECLARE_PROPERTY(TSBPGPEncryptionType, get_EncryptionType, set_EncryptionType, TElSimplePGPMIMEOptions, EncryptionType);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Passphrases();

		virtual void set_Passphrases(TStringList &Value);

		virtual void set_Passphrases(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_Passphrases, set_Passphrases, TElSimplePGPMIMEOptions, Passphrases);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Passphrases();

		virtual void set_Passphrases(TElStringList &Value);

		virtual void set_Passphrases(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_Passphrases, set_Passphrases, TElSimplePGPMIMEOptions, Passphrases);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual TSBPGPProtectionType get_Protection();

		virtual void set_Protection(TSBPGPProtectionType Value);

		SB_DECLARE_PROPERTY(TSBPGPProtectionType, get_Protection, set_Protection, TElSimplePGPMIMEOptions, Protection);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElSimplePGPMIMEOptions, HashAlgorithm);

		virtual int32_t get_CompressionAlgorithm();

		virtual void set_CompressionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionAlgorithm, set_CompressionAlgorithm, TElSimplePGPMIMEOptions, CompressionAlgorithm);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSimplePGPMIMEOptions, CompressionLevel);

		virtual int32_t get_SymmetricKeyAlgorithm();

		virtual void set_SymmetricKeyAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SymmetricKeyAlgorithm, set_SymmetricKeyAlgorithm, TElSimplePGPMIMEOptions, SymmetricKeyAlgorithm);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElSimplePGPMIMEOptions, UseOldPackets);

		virtual bool get_UseNewFeatures();

		virtual void set_UseNewFeatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNewFeatures, set_UseNewFeatures, TElSimplePGPMIMEOptions, UseNewFeatures);

		virtual bool get_CompressMessage();

		virtual void set_CompressMessage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CompressMessage, set_CompressMessage, TElSimplePGPMIMEOptions, CompressMessage);

		virtual bool get_EncryptMessage();

		virtual void set_EncryptMessage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptMessage, set_EncryptMessage, TElSimplePGPMIMEOptions, EncryptMessage);

		virtual bool get_IgnoreHeaderRecipients();

		virtual void set_IgnoreHeaderRecipients(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreHeaderRecipients, set_IgnoreHeaderRecipients, TElSimplePGPMIMEOptions, IgnoreHeaderRecipients);

		virtual bool get_IgnoreHeaderSigners();

		virtual void set_IgnoreHeaderSigners(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreHeaderSigners, set_IgnoreHeaderSigners, TElSimplePGPMIMEOptions, IgnoreHeaderSigners);

		virtual bool get_SignMessage();

		virtual void set_SignMessage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignMessage, set_SignMessage, TElSimplePGPMIMEOptions, SignMessage);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		virtual void set_ArmorHeaders(TStringList &Value);

		virtual void set_ArmorHeaders(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_ArmorHeaders, set_ArmorHeaders, TElSimplePGPMIMEOptions, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_ArmorHeaders();

		virtual void set_ArmorHeaders(TElStringList &Value);

		virtual void set_ArmorHeaders(TElStringList *Value);

		SB_DECLARE_PROPERTY(TElStringList*, get_ArmorHeaders, set_ArmorHeaders, TElSimplePGPMIMEOptions, ArmorHeaders);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		TElSimplePGPMIMEOptions(TElSimplePGPMIMEOptionsHandle handle, TElOwnHandle ownHandle);

		TElSimplePGPMIMEOptions();

		virtual ~TElSimplePGPMIMEOptions();

};
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE
class TElSimplePGPMIMEMessage: public TElSimpleMIMEMessage
{
	private:
		SB_DISABLE_COPY(TElSimplePGPMIMEMessage)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_EncryptingKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
		TElSimplePGPMIMEOptions* _Inst_PGPMIMEOptions;
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_SigningKeys;
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_EncryptingKeys();

		virtual void set_EncryptingKeys(TElPGPKeyring &Value);

		virtual void set_EncryptingKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_EncryptingKeys, set_EncryptingKeys, TElSimplePGPMIMEMessage, EncryptingKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS
		virtual TElSimplePGPMIMEOptions* get_PGPMIMEOptions();

		virtual void set_PGPMIMEOptions(TElSimplePGPMIMEOptions &Value);

		virtual void set_PGPMIMEOptions(TElSimplePGPMIMEOptions *Value);

		SB_DECLARE_PROPERTY(TElSimplePGPMIMEOptions*, get_PGPMIMEOptions, set_PGPMIMEOptions, TElSimplePGPMIMEMessage, PGPMIMEOptions);
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_SigningKeys();

		virtual void set_SigningKeys(TElPGPKeyring &Value);

		virtual void set_SigningKeys(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_SigningKeys, set_SigningKeys, TElSimplePGPMIMEMessage, SigningKeys);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual void get_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEncryptingKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue);

		virtual void get_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSigningKeyNotFound(TSBPGPKeyNotFoundEvent pMethodValue, void * pDataValue);

		TElSimplePGPMIMEMessage(TElSimplePGPMIMEMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElSimplePGPMIMEMessage(TComponent &AOwner);

		explicit TElSimplePGPMIMEMessage(TComponent *AOwner);

		virtual ~TElSimplePGPMIMEMessage();

};
#endif /* SB_USE_CLASS_TELSIMPLEPGPMIMEMESSAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PGPMIME
SB_IMPORT uint32_t SB_APIENTRY SBPGPMIME_Initialize(void);
#endif /* SB_USE_GLOBAL_PROCS_PGPMIME */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPMIME */
