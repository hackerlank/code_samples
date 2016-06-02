#ifndef __INC_SBCRYPTOPROVRS
#define __INC_SBCRYPTOPROVRS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SInvalidPublicKey 	"Invalid public key"
#define SB_SInvalidSecretKey 	"Invalid secret key"
#ifndef SB_SBufferTooSmall
#define SB_SBufferTooSmall 	"Buffer too small"
#endif
#define SB_SPrimitiveOpFailed 	"Primitive operation failed"
#define SB_SUnsupportedAlgorithmInt 	"Unsupported algorithm (%d)"
#define SB_SUnsupportedAlgorithmStr 	"Unsupported algorithm (%s)"
#define SB_SUnsupportedPropertyStr 	"Unsupported property (%s)"
#define SB_SUnknownAlgorithmProperty 	"Unknown algorithm property (%s)"
#define SB_SCryptoAPIError 	"CryptoAPI error %d"
#define SB_SUnsupportedHashAlgorithmInt 	"Unsupported hash algorithm (%d)"
#define SB_SUnsupportedPropertyValue 	"Unsupported property value (%s)"
#define SB_SModuleInitializationFailed 	"Module initialization failed (%s)"
#define SB_SHashAlgorithmMismatch 	"Hash algorithm mismatch (%d)"
#define SB_SInvalidContext 	"Invalid context"
#define SB_SInvalidAlgorithm 	"Invalid algorithm"
#define SB_SCannotChangeAlgorithm 	"The algorithm cannot be changed"
#define SB_SCannotChangeROProperty 	"Cannot change read-only property"
#define SB_SNotASymmetricCipherContext 	"Not a symmetric cipher context"
#define SB_SNotAHashContext 	"Not a hash context"
#define SB_SNotAPKIContext 	"Not a public key operation context"
#define SB_SNotARC4Context 	"Not a RC4 context"
#define SB_SNotAGOST89Context 	"Not a GOST 28147-89 context"
#define SB_SNotAGOST2001Context 	"Not a GOST 34.10-2001 context"
#define SB_SNotARSAContext 	"Not a RSA context"
#define SB_SNotAECDSAContext 	"Not a ECDSA context"
#define SB_SCannotCloneContext 	"Cannot clone a context"
#ifndef SB_SInternalError
#define SB_SInternalError 	"Internal error"
#endif
#define SB_SUnsupportedOperation 	"Unsupported operation"
#define SB_SUnrecognizedPadding 	"Unrecognized padding mode"
#define SB_SInternalException 	"Internal exception"
#define SB_SInvalidKeyMaterial 	"Invalid key material"
#define SB_SNoIVInKeyMaterial 	"Required IV not set in key material"
#define SB_SInvalidKeyFormat 	"Invalid key format"
#define SB_SInvalidCipherMode 	"Invalid cipher mode of operation"
#define SB_SInvalidCryptoProvider 	"Invalid cryptographic provider"
#define SB_SCannotCompleteOperation 	"Cannot complete operation"
#define SB_SInterruptedByUser 	"Interrupted by user"
#define SB_SUnsupportedCryptoProvider 	"Unsupported crypto provider"
#define SB_SPublicKeyNotFound 	"Public key not found"
#define SB_SSecretKeyNotFound 	"Secret key not found"
#define SB_SBadKeyMaterial 	"Bad key material"
#define SB_SInvalidKeyMaterialType 	"Invalid key material type"
#ifndef SB_SSigningFailed
#define SB_SSigningFailed 	"Signing failed"
#endif
#ifndef SB_SEncryptionFailed
#define SB_SEncryptionFailed 	"Encryption failed"
#endif
#define SB_SDecryptionFailed 	"Decryption failed"
#define SB_SKEKDerivationFailed 	"KEK derivation failed"
#define SB_SUnsupportedEncryptionType 	"Encryption type"
#define SB_SOnlyDetachedSigningSupported 	"Only detached signing supported"
#define SB_SInputTooLong 	"Input too long"
#define SB_SBadSignatureFormatting 	"Bad signature formatting"
#ifndef SB_SInvalidSignature
#define SB_SInvalidSignature 	"Invalid signature"
#endif
#define SB_SCannotModifyReadOnlyProperty 	"Cannot modify read-only property"
#define SB_SKeyGenerationFailed 	"Key generation failed"
#define SB_SNotASigningAlgorithm 	"Not a signing algorithm"
#define SB_SFeatureNotAvailable 	"Feature not available"
#define SB_SFailedToModifyReadonlyProperty 	"Failed to modify read-only property"
#define SB_SUnsupportedKeyMaterial 	"Unsupported key material"
#define SB_SKeyPropertyNotSupported 	"Key does not support the property"
#define SB_SInvalidPadding 	"Invalid symmetric cipher padding"
#define SB_SKeyDecryptionFailed 	"Key decryption failed"
#define SB_SDriverNotFound 	"Driver not found"
#define SB_SUnsupportedFeature 	"Unsupported feature"
#define SB_SCannotClonePKCS11Context 	"Cannot clone PKCS#11 context"
#define SB_SCannotCloneWin32Context 	"Cannot clone Win32 context"
#define SB_SKeyAlreadyPrepared 	"Key is already prepared"
#define SB_SFailedToExportSecretKey 	"Failed to export secret key"
#define SB_SObjectNotFound 	"Object not found"
#define SB_SBadObjectType 	"Bad object type"
#define SB_SHandleNotFound 	"Handle not found"
#define SB_SMethodNotImplemented 	"Method not implemented"
#define SB_SPublicKeyTooLong 	"Public key is too long"
#define SB_SInvalidECDomainParameters 	"Invalid elliptic curve domain parameters"
#define SB_SUnknownEC 	"Unknown elliptic curve"
#define SB_SUnknownField 	"Unknown elliptic curve field"
#define SB_SInvalidKeyProperty 	"Invalid key property"
#define SB_SOperationInitializationFailed 	"Operation initialization failed"
#define SB_SInstantiationFailed 	"Failed to instantiate the type"
#define SB_SInvalidPropertyValue 	"Invalid property value"
#define SB_SUnsupportedPublicKeyFormat 	"Unsupported public key format"
#define SB_SCannotUnregisterDefaultProvider 	"Cannot unregister the default cryptographic provider"
#define SB_SNoSuitableProviderInt 	"Unsupported cryptographic operation. Operation: %d, Algorithm: %d, Mode: %d."
#define SB_SNoSuitableProviderStr 	"Unsupported cryptographic operation. Operation: %d, Algorithm: %s, Params: %s, Mode: %d."

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVRS */

