#ifndef __INC_SBPGPRESOURCESTRINGS
#define __INC_SBPGPRESOURCESTRINGS

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
#define SB_SPGPInvalidPacket 	"Invalid PGP packet"
#define SB_SPGPInvalidPacketType 	"Invalid PGP packet type"
#define SB_SPGPUnknownPacketVersion 	"Unknown PGP packet version"
#define SB_SPGPUnknownKeyVersion 	"Unknown PGP key version"
#define SB_SPGPInvalidKeyData 	"Invalid PGP key data"
#define SB_SPGPInvalidKeyS2K 	"Invalid S2K: Not enough data to calculate key material."
#define SB_SPGPInvalidKeyUsage 	"Invalid key usage"
#define SB_SPGPInvalidKeyVersion 	"Invalid key version"
#define SB_SPGPKeyIsReadOnly 	"Cannot modify key"
#define SB_SPGPKeyDataNotSet 	"Key data not set"
#define SB_SPGPInvalidSymmetricKey 	"Invalid symmetric key"
#define SB_SPGPInvalidInitialVector 	"Invalid initial vector"
#define SB_SPGPUnknownSignatureVersion 	"Unknown PGP signature version"
#define SB_SPGPUnknownKeyAlgorithm 	"Unknown Public Key algorithm"
#define SB_SPGPInvalidSigningAlgorithm 	"Invalid signing algorithm"
#define SB_SPGPInvalidEncryptionAlgorithm 	"Invalid encryption algorithm"
#define SB_SPGPInvalidTypeCast 	"Invalid type cast"
#define SB_SPGPUnknownSignatureAlgorithm 	"Unknown PGP signature algorithm"
#define SB_SPGPInvalidSignData 	"Invalid sign data"
#define SB_SPGPInvalidSignatureSubpacket 	"Invalid signature subpacket"
#define SB_SPGPUnknownSignatureSubpacket 	"Unknown signature subpacket"
#define SB_SPGPInvalidSignatureSubpackets 	"Invalid signature subpackets"
#define SB_SPGPSignatureReadOnly 	"Signature is in read-only state"
#define SB_SPGPSignatureDataNotSet 	"Signature isn\'t filled properly"
#define SB_SPGPInvalidSignatureType 	"Invalid signature type"
#define SB_SPGPUnsupportedStreamAlgorithm 	"Unsupported stream cipher algorithm : %d"
#define SB_SPGPUnsupportedHashAlgorithm 	"Unsupported hash algorithm"
#define SB_SPGPUnsupportedSymmetricAlgorithm 	"Unsupported symmetric algorithm"
#define SB_SPGPUnexpectedEndOfPacket 	"Unexpected end of packet"
#define SB_SPGPUnexpectedPacket 	"Unexpected packet"
#define SB_SPGPUnsupportedS2KType 	"Unsupported S2K type"
#define SB_SPGPInvalidS2KType 	"Invalid S2K type"
#define SB_SPGPInvalidPacketData 	"Invalid packet data"
#define SB_SPGPInvalidMPInt 	"Invalid multi-precision integer"
#define SB_SPGPInvalidX509Certificate 	"Invalid X.509 certificate"
#define SB_SPGPInvalidPacketSequence 	"Invalid packet sequence"
#define SB_SPGPInvalidPublicKeyPacketSequence 	"Invalid public key packet sequence"
#define SB_SPGPInvalidSecretKeyPacketSequence 	"Invalid secret key packet sequence"
#define SB_SPGPInvalidKeyringPacketSequence 	"Invalid keyring packet sequence"
#define SB_SPGPInvalidPassword 	"Invalid password"
#define SB_SPGPInvalidKeySize 	"Invalid key size"
#define SB_SPGPInvalidParameter 	"Invalid parameter"
#define SB_SPGPBoundToSecretKey 	"This public key is bound to secret key. Please remove the secret key first."
#define SB_SPGPNotImplemented 	"Not implemented"
#define SB_SPGPIndexOutOfBounds 	"Index out of bounds"
#define SB_SPGPNoKeyForDecryption 	"No appropriate OpenPGP secret key for decryption found"
#define SB_SPGPNoKeyForEncryption 	"No suitable OpenPGP public key for encryption found"
#define SB_SPGPInvalidResyncSize 	"Invalid resync data size"
#define SB_SPGPMessageWasTampered 	"Message was tampered"
#define SB_SPGPUnsupportedVersion 	"Unsupported version"
#define SB_SPGPInvalidHeaderLine 	"Invalid header line"
#define SB_SPGPInvalidArmor 	"Invalid armor"
#define SB_SPGPInvalidCRC 	"Invalid CRC"
#define SB_SPGPUnexpectedCharacter 	"Unexpected character"
#define SB_SPGPUnexpectedEndOfData 	"Unexpected end of data"
#define SB_SPGPInvalidData 	"Invalid data"
#define SB_SPGPUnknownDataType 	"Unknown data type"
#define SB_SPGPDecompressionFailed 	"Decompression failed"
#define SB_SPGPInvalidSignature 	"Invalid signature"
#define SB_SPGPFailedToOpenFile 	"Failed to open %s"
#define SB_SPGPNoAnonymousOutputStream 	"The output stream must have some name"
#define SB_SPGPNoAnonymousInputStreams 	"All input streams must have corresponding names"
#define SB_SPGPKeyringNotAssigned 	"Keyring property is not assigned"
#define SB_SPGPNoSecretKeys 	"No secret keys"
#define SB_SPGPNoDataToSign 	"No data to sign"
#define SB_SPGPDataSizeTooLarge 	"Data size is to large"
#define SB_SPGPInternalException 	"Internal exception [%d]"
#define SB_SPGPUnknownBlockType 	"Unknown block type: [%d]"
#define SB_SPGPUnexpectedBlockType 	"Unexpected block type: [%d]"
#define SB_SPGPUnknownCompressionAlgorithm 	"Unknown compression algorithm: [%d]"
#define SB_SPGPInvalidPadding 	"Invalid PKCS1 padding"
#define SB_SPGPBadDecryptedKey 	"Bad decrypted key"
#define SB_SPGPKeyDoesNotMatchSignature 	"Key does not match signature"
#define SB_SPGPDecryptionFailed 	"Decryption failed (secret key mismatch\?)"
#define SB_SPGPSigningFailed 	"Signing failed (secret key mismatch/passphrase not provided\?)"
#define SB_SPGPKeyAlreadyPrepared 	"Key is already prepared for the cryptographic operation"
#define SB_SPGPKeyIsNotBeingGenerated 	"Key is not being generated, use BeginGenerate() method"
#define SB_SPGPKeyIsAlreadyBeingGenerated 	"Key is already being generated"
#define SB_SPGPUnsupportedKeyMaterial 	"Unsupported key material"
#define SB_SPGPArmoringNotSupported 	"Self-extractable files do not support armoring"
#define SB_SPGPNoPublicKeyFound 	"No public key found"
#define SB_SPGPNoSecretKeyFound 	"No secret key found"
#define SB_SPGPInconsistentPublicAndSecretKeys 	"Inconsistent public and secret keys"
#define SB_SPGPUnsupportedEllipticCurve 	"Unsupported elliptic curve"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPRESOURCESTRINGS */

