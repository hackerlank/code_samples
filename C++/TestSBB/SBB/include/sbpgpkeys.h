#ifndef __INC_SBPGPKEYS
#define __INC_SBPGPKEYS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbpgpentities.h"
#include "sbpgpexceptions.h"
#include "sbpgpconstants.h"
#include "sbpgputils.h"
#include "sbsharedresource.h"
#include "sbpgpmd.h"
#include "sbmath.h"
#include "sbrandom.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbsymmetriccrypto.h"
#include "sbx509.h"
#include "sbpublickeycrypto.h"
#include "sbhashfunction.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPGPCustomPublicKeyHandle;

typedef TElPGPCustomPublicKeyHandle ElPGPCustomPublicKeyHandle;

typedef TElClassHandle TElPGPPublicSubkeyHandle;

typedef TElPGPPublicSubkeyHandle ElPGPPublicSubkeyHandle;

typedef TElClassHandle TElPGPPublicKeyHandle;

typedef TElPGPPublicKeyHandle ElPGPPublicKeyHandle;

typedef TElClassHandle TElPGPCustomSecretKeyHandle;

typedef TElPGPCustomSecretKeyHandle ElPGPCustomSecretKeyHandle;

typedef TElClassHandle TElPGPSecretSubkeyHandle;

typedef TElPGPSecretSubkeyHandle ElPGPSecretSubkeyHandle;

typedef TElClassHandle TElPGPSecretKeyHandle;

typedef TElPGPSecretKeyHandle ElPGPSecretKeyHandle;

typedef TElClassHandle TElPGPTrustHandle;

typedef TElPGPTrustHandle ElPGPTrustHandle;

typedef TElClassHandle TElPGPSignatureHandle;

typedef TElPGPSignatureHandle ElPGPSignatureHandle;

typedef TElClassHandle TElPGPCustomUserHandle;

typedef TElPGPCustomUserHandle ElPGPCustomUserHandle;

typedef TElClassHandle TElPGPUserIDHandle;

typedef TElPGPUserIDHandle ElPGPUserIDHandle;

typedef TElClassHandle TElPGPUserAttrHandle;

typedef TElPGPUserAttrHandle ElPGPUserAttrHandle;

typedef TElClassHandle TElPGPKeyringHandle;

typedef TElPGPKeyringHandle ElPGPKeyringHandle;

typedef TElClassHandle TElPGPJpegImageHandle;

typedef uint8_t TSBPGPUserCertificationTypeRaw;

typedef enum
{
	ctGeneric = 0,
	ctPersona = 1,
	ctCasual = 2,
	ctPositive = 3
} TSBPGPUserCertificationType;

typedef uint8_t TSBPGPKeyTrustRaw;

typedef enum
{
	ktUndefined = 0,
	ktNone = 1,
	ktMarginal = 2,
	ktTrusted = 3,
	ktImplicit = 4
} TSBPGPKeyTrust;

typedef void (SB_CALLBACK *TSBPGPPasswordEvent)(void * _ObjectData, TObjectHandle Sender, void * UserData, char * pcRes, int32_t * szRes);

typedef void (SB_CALLBACK *TSBPGPBeforeSignEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPSignatureHandle Signature, TObjectHandle Subject);

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Assign(TElPGPCustomPublicKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_AssignTo(TElPGPCustomPublicKeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_AddSignature(TElPGPCustomPublicKeyHandle _Handle, TElPGPSignatureHandle Signature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_RemoveSignature(TElPGPCustomPublicKeyHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_RemoveSignature_1(TElPGPCustomPublicKeyHandle _Handle, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_ClearSignatures(TElPGPCustomPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Verify(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle PublicKey, TElPGPCustomUserHandle User, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Verify_1(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Verify_2(TElPGPCustomPublicKeyHandle _Handle, TElHashFunctionHandle HashFunction, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Verify_3(TElPGPCustomPublicKeyHandle _Handle, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Verify_4(TElPGPCustomPublicKeyHandle _Handle, TElPGPSignatureHandle SubjectSignature, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_DirectVerify(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_RevocationVerify(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_RevocationVerify_1(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPCustomUserHandle User, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_DirectRevocationVerify(TElPGPCustomPublicKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_ExportKeyMaterial(TElPGPCustomPublicKeyHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_ImportKeyMaterial(TElPGPCustomPublicKeyHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_ImportKeyMaterial_1(TElPGPCustomPublicKeyHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Encrypt(TElPGPCustomPublicKeyHandle _Handle, const uint8_t pData[], int32_t szData, TSBPGPEncryptedSymmetricKey * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_IsSigningKey(TElPGPCustomPublicKeyHandle _Handle, int8_t WithSubkeys, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_IsEncryptingKey(TElPGPCustomPublicKeyHandle _Handle, int8_t WithSubkeys, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_PrepareForEncryption(TElPGPCustomPublicKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_CancelPreparation(TElPGPCustomPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_AsyncOperationFinished(TElPGPCustomPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_AcquireLock(TElPGPCustomPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_ReleaseLock(TElPGPCustomPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_KeyID(TElPGPCustomPublicKeyHandle _Handle, TSBKeyID * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_KeyFP(TElPGPCustomPublicKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Timestamp(TElPGPCustomPublicKeyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_set_Timestamp(TElPGPCustomPublicKeyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Expires(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_set_Expires(TElPGPCustomPublicKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_PublicKeyAlgorithm(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_BitsInKey(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_KeyHashAlgorithm(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_set_KeyHashAlgorithm(TElPGPCustomPublicKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_QBits(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Curve(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Version(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_UseOldPackets(TElPGPCustomPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_set_UseOldPackets(TElPGPCustomPublicKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Signatures(TElPGPCustomPublicKeyHandle _Handle, int32_t Index, TElPGPSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_SignatureCount(TElPGPCustomPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Revoked(TElPGPCustomPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_get_Enabled(TElPGPCustomPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_set_Enabled(TElPGPCustomPublicKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomPublicKey_Create(TElPGPCustomPublicKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_Assign(TElPGPPublicSubkeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_AssignTo(TElPGPPublicSubkeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_get_SecretKey(TElPGPPublicSubkeyHandle _Handle, TElPGPSecretSubkeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_get_Supkey(TElPGPPublicSubkeyHandle _Handle, TElPGPPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_get_Trust(TElPGPPublicSubkeyHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicSubkey_Create(TElPGPPublicSubkeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveSubkey(TElPGPPublicKeyHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveSubkey_1(TElPGPPublicKeyHandle _Handle, TElPGPPublicSubkeyHandle Subkey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_Assign(TElPGPPublicKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AssignTo(TElPGPPublicKeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AssignFromX509(TElPGPPublicKeyHandle _Handle, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_LoadFromStream(TElPGPPublicKeyHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_LoadFromFile(TElPGPPublicKeyHandle _Handle, const char * pcFilename, int32_t szFilename);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_SaveToStream(TElPGPPublicKeyHandle _Handle, TStreamHandle Stream, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_SaveToFile(TElPGPPublicKeyHandle _Handle, const char * pcFilename, int32_t szFilename, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AddSubkey(TElPGPPublicKeyHandle _Handle, TElPGPPublicSubkeyHandle Subkey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_ClearSubkeys(TElPGPPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AddUserID(TElPGPPublicKeyHandle _Handle, TElPGPUserIDHandle User, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AddUserAttr(TElPGPPublicKeyHandle _Handle, TElPGPUserAttrHandle User, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveUserID(TElPGPPublicKeyHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveUserID_1(TElPGPPublicKeyHandle _Handle, TElPGPUserIDHandle User, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveUserAttr(TElPGPPublicKeyHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_RemoveUserAttr_1(TElPGPPublicKeyHandle _Handle, TElPGPUserAttrHandle UserAttr, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_ClearUserIDs(TElPGPPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_ClearUserAttrs(TElPGPPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_PrepareForEncryption(TElPGPPublicKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_CancelPreparation(TElPGPPublicKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_AsyncOperationFinished(TElPGPPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_ArmorBoundary(TElPGPPublicKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_set_ArmorBoundary(TElPGPPublicKeyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_ArmorHeaders(TElPGPPublicKeyHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_Subkeys(TElPGPPublicKeyHandle _Handle, int32_t Index, TElPGPPublicSubkeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_UserIDs(TElPGPPublicKeyHandle _Handle, int32_t Index, TElPGPUserIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_UserAttrs(TElPGPPublicKeyHandle _Handle, int32_t Index, TElPGPUserAttrHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredSymAlgs(TElPGPPublicKeyHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredHashAlgs(TElPGPPublicKeyHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredComprAlgs(TElPGPPublicKeyHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_SubkeyCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_UserIDCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_UserAttrCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_Trust(TElPGPPublicKeyHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_KeyTrust(TElPGPPublicKeyHandle _Handle, TSBPGPKeyTrustRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_set_KeyTrust(TElPGPPublicKeyHandle _Handle, TSBPGPKeyTrustRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_SecretKey(TElPGPPublicKeyHandle _Handle, TElPGPSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_WriteOldPrefix(TElPGPPublicKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_set_WriteOldPrefix(TElPGPPublicKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredSymAlgCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredHashAlgCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_get_PreferredComprAlgCount(TElPGPPublicKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPPublicKey_Create(TElPGPPublicKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Assign(TElPGPCustomSecretKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_AssignTo(TElPGPCustomSecretKeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Generate(TElPGPCustomSecretKeyHandle _Handle, const char * pcPassword, int32_t szPassword, int32_t Bits, int32_t Algorithm, int8_t UseOldFormat, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_BeginGenerate(TElPGPCustomSecretKeyHandle _Handle, int32_t Bits, int32_t Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_EndGenerate(TElPGPCustomSecretKeyHandle _Handle, const char * pcPassword, int32_t szPassword, int8_t UseOldFormat, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_CancelGeneration(TElPGPCustomSecretKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ChangePassphrase(TElPGPCustomSecretKeyHandle _Handle, const char * pcNewPassphrase, int32_t szNewPassphrase, TSBPGPProtectionTypeRaw ProtectionType);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ChangeProtection(TElPGPCustomSecretKeyHandle _Handle, const char * pcNewPassphrase, int32_t szNewPassphrase, TSBPGPProtectionTypeRaw PrType, int32_t EncAlgorithm, int32_t HshAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Sign(TElPGPCustomSecretKeyHandle _Handle, TElPGPPublicKeyHandle PublicKey, TElPGPCustomUserHandle User, TElPGPSignatureHandle Signature, TSBPGPUserCertificationTypeRaw CertType);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Sign_1(TElPGPCustomSecretKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, TElPGPSignatureHandle EmbeddedSignature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Sign_2(TElPGPCustomSecretKeyHandle _Handle, int64_t TimeStamp, TElPGPSignatureHandle Signature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Sign_3(TElPGPCustomSecretKeyHandle _Handle, TElPGPSignatureHandle SubjectSignature, TElPGPSignatureHandle Signature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Sign_4(TElPGPCustomSecretKeyHandle _Handle, TElHashFunctionHandle HashFunction, TElPGPSignatureHandle Signature, int32_t SignatureClass);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_DirectSign(TElPGPCustomSecretKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Revoke(TElPGPCustomSecretKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Revoke_1(TElPGPCustomSecretKeyHandle _Handle, TElPGPPublicKeyHandle Key, TElPGPCustomUserHandle User, TElPGPSignatureHandle Signature, TElPGPSignatureHandle RevokedSignature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_DirectRevoke(TElPGPCustomSecretKeyHandle _Handle, TElPGPCustomPublicKeyHandle Key, TElPGPSignatureHandle Signature, TElPGPSignatureHandle RevokedSignature);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Decrypt(TElPGPCustomSecretKeyHandle _Handle, const TSBPGPEncryptedSymmetricKey * EncrData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_PassphraseValid(TElPGPCustomSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_IsSigningKey(TElPGPCustomSecretKeyHandle _Handle, int8_t WithSubkeys, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_IsEncryptingKey(TElPGPCustomSecretKeyHandle _Handle, int8_t WithSubkeys, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ExportKeyMaterial(TElPGPCustomSecretKeyHandle _Handle, int8_t PublicOnly, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ExportSecretKeyMaterial(TElPGPCustomSecretKeyHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ImportKeyMaterial(TElPGPCustomSecretKeyHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ImportKeyMaterial_1(TElPGPCustomSecretKeyHandle _Handle, TElPublicKeyMaterialHandle SecKeyMaterial, TElPublicKeyMaterialHandle PubKeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ImportKeyMaterial_2(TElPGPCustomSecretKeyHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ImportKeyMaterial_3(TElPGPCustomSecretKeyHandle _Handle, TElPublicKeyMaterialHandle SecKeyMaterial, TElPublicKeyMaterialHandle PubKeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_KeyID(TElPGPCustomSecretKeyHandle _Handle, TSBKeyID * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_KeyFP(TElPGPCustomSecretKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_PrepareForSigning(TElPGPCustomSecretKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_CancelPreparation(TElPGPCustomSecretKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_AsyncOperationFinished(TElPGPCustomSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_AcquireLock(TElPGPCustomSecretKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_ReleaseLock(TElPGPCustomSecretKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_UseOldPackets(TElPGPCustomSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_UseOldPackets(TElPGPCustomSecretKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Timestamp(TElPGPCustomSecretKeyHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_Timestamp(TElPGPCustomSecretKeyHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Version(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Expires(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_Expires(TElPGPCustomSecretKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_BitsInKey(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_PublicKeyAlgorithm(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_EncryptionAlgorithm(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_HashAlgorithm(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_KeyHashAlgorithm(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_KeyHashAlgorithm(TElPGPCustomSecretKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_QBits(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_QBits(TElPGPCustomSecretKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Curve(TElPGPCustomSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_Curve(TElPGPCustomSecretKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Protection(TElPGPCustomSecretKeyHandle _Handle, TSBPGPProtectionTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Passphrase(TElPGPCustomSecretKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_Passphrase(TElPGPCustomSecretKeyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Trust(TElPGPCustomSecretKeyHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_get_Enabled(TElPGPCustomSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_set_Enabled(TElPGPCustomSecretKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomSecretKey_Create(TElPGPCustomSecretKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretSubkey_Assign(TElPGPSecretSubkeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretSubkey_AssignTo(TElPGPSecretSubkeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretSubkey_get_Supkey(TElPGPSecretSubkeyHandle _Handle, TElPGPSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretSubkey_get_PublicKey(TElPGPSecretSubkeyHandle _Handle, TElPGPPublicSubkeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretSubkey_Create(TElPGPSecretSubkeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_RemoveSubkey(TElPGPSecretKeyHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_RemoveSubkey_1(TElPGPSecretKeyHandle _Handle, TElPGPSecretSubkeyHandle Subkey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_Assign(TElPGPSecretKeyHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_AssignTo(TElPGPSecretKeyHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_AssignFromX509(TElPGPSecretKeyHandle _Handle, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_LoadFromStream(TElPGPSecretKeyHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_LoadFromFile(TElPGPSecretKeyHandle _Handle, const char * pcFilename, int32_t szFilename);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_SaveToStream(TElPGPSecretKeyHandle _Handle, TStreamHandle Stream, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_SaveToFile(TElPGPSecretKeyHandle _Handle, const char * pcFilename, int32_t szFilename, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_BindUser(TElPGPSecretKeyHandle _Handle, TElPGPCustomUserHandle User);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_Generate(TElPGPSecretKeyHandle _Handle, const char * pcPassword, int32_t szPassword, int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm, const char * pcUserName, int32_t szUserName, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_Generate_1(TElPGPSecretKeyHandle _Handle, const char * pcPassword, int32_t szPassword, int32_t KeyBits, int32_t KeyAlgorithm, const char * pcUserName, int32_t szUserName, int8_t UseOldStyle, int32_t Expires);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_BeginGenerate(TElPGPSecretKeyHandle _Handle, int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_EndGenerate(TElPGPSecretKeyHandle _Handle, const char * pcPassword, int32_t szPassword, const char * pcUserName, int32_t szUserName, int32_t Expires, int8_t UseOldFormat);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_AddSubkey(TElPGPSecretKeyHandle _Handle, TElPGPSecretSubkeyHandle Subkey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_PrepareForSigning(TElPGPSecretKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_CancelPreparation(TElPGPSecretKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_AsyncOperationFinished(TElPGPSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_ArmorBoundary(TElPGPSecretKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_set_ArmorBoundary(TElPGPSecretKeyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_ArmorHeaders(TElPGPSecretKeyHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_Subkeys(TElPGPSecretKeyHandle _Handle, int32_t Index, TElPGPSecretSubkeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_SubkeyCount(TElPGPSecretKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_PublicKey(TElPGPSecretKeyHandle _Handle, TElPGPPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_WriteFlags(TElPGPSecretKeyHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_set_WriteFlags(TElPGPSecretKeyHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_WriteOldPrefix(TElPGPSecretKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_set_WriteOldPrefix(TElPGPSecretKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_get_OnBeforeSign(TElPGPSecretKeyHandle _Handle, TSBPGPBeforeSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_set_OnBeforeSign(TElPGPSecretKeyHandle _Handle, TSBPGPBeforeSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSecretKey_Create(TElPGPSecretKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPTRUST
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_Assign(TElPGPTrustHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_AssignTo(TElPGPTrustHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_OwnerTrust(TElPGPTrustHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_OwnerTrust(TElPGPTrustHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_Disabled(TElPGPTrustHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_Disabled(TElPGPTrustHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_BuckStop(TElPGPTrustHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_BuckStop(TElPGPTrustHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_KeyLegit(TElPGPTrustHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_KeyLegit(TElPGPTrustHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_WarnOnly(TElPGPTrustHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_WarnOnly(TElPGPTrustHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_SigTrust(TElPGPTrustHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_SigTrust(TElPGPTrustHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_Checked(TElPGPTrustHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_Checked(TElPGPTrustHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_Contiguous(TElPGPTrustHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_Contiguous(TElPGPTrustHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_get_Flags(TElPGPTrustHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_set_Flags(TElPGPTrustHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPTrust_Create(TElPGPTrustHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPTRUST */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_Assign(TElPGPSignatureHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_AssignTo(TElPGPSignatureHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_LoadFromStream(TElPGPSignatureHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_SaveToStream(TElPGPSignatureHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_SaveOnePass(TElPGPSignatureHandle _Handle, int8_t Nested);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_SaveOnePassToStream(TElPGPSignatureHandle _Handle, TStreamHandle Stream, int8_t Nested);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsKeyRevocation(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsSubkeyRevocation(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsUserRevocation(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsDocumentSignature(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsStandalone(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsUserCertification(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsSubkeyBinding(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsDirectKeySignature(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_IsTimestampSignature(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_SignerKeyID(TElPGPSignatureHandle _Handle, TSBKeyID * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_AddExtension(TElPGPSignatureHandle _Handle, TSBPGPSignatureExtensionRaw ExtType, int8_t Hashed, int8_t Critical, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_RemoveExtension(TElPGPSignatureHandle _Handle, TSBPGPSignatureExtensionRaw ExtType, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_RemoveExtension_1(TElPGPSignatureHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_GetExtensionByType(TElPGPSignatureHandle _Handle, TSBPGPSignatureExtensionRaw ExtType, int32_t Index, TElPGPSignatureSubpacketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_GetExtensionCount(TElPGPSignatureHandle _Handle, TSBPGPSignatureExtensionRaw ExtType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_ClearExtensions(TElPGPSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_IsX509Certificate(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Extensions(TElPGPSignatureHandle _Handle, int32_t Index, TElPGPSignatureSubpacketHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_RegularExpression(TElPGPSignatureHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_RegularExpression(TElPGPSignatureHandle _Handle, int32_t Index, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Version(TElPGPSignatureHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_Version(TElPGPSignatureHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_HashAlgorithm(TElPGPSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_HashAlgorithm(TElPGPSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_UseOldPackets(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_UseOldPackets(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_X509Certificate(TElPGPSignatureHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Validated(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_Validated(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_StrictlyValid(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_StrictlyValid(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_CreationTime(TElPGPSignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_CreationTime(TElPGPSignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_KeyExpirationTime(TElPGPSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_KeyExpirationTime(TElPGPSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_ExpirationTime(TElPGPSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_ExpirationTime(TElPGPSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Exportable(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_Exportable(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Revocable(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_Revocable(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_TrustLevel(TElPGPSignatureHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_TrustLevel(TElPGPSignatureHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_TrustAmount(TElPGPSignatureHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_TrustAmount(TElPGPSignatureHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Trust(TElPGPSignatureHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_RegularExpressionCount(TElPGPSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_RegularExpressionCount(TElPGPSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_PrimaryUserID(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_PrimaryUserID(TElPGPSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_PolicyURL(TElPGPSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_PolicyURL(TElPGPSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_SignerUserID(TElPGPSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_SignerUserID(TElPGPSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_ReasonForRevocation(TElPGPSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_ReasonForRevocation(TElPGPSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_SignatureClass(TElPGPSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_CertificationType(TElPGPSignatureHandle _Handle, TSBPGPUserCertificationTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_set_CertificationType(TElPGPSignatureHandle _Handle, TSBPGPUserCertificationTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_Revocation(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_get_IsTextSignature(TElPGPSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_Create(TElPGPSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_Create_1(TElPGPSignatureEntityHandle Entity, TElPGPSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPSignature_Create_2(TElPGPSignatureHandle Source, int8_t CopySigMaterial, TElPGPSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPCUSTOMUSER
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_Assign(TElPGPCustomUserHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_AssignTo(TElPGPCustomUserHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_AddSignature(TElPGPCustomUserHandle _Handle, TElPGPSignatureHandle Signature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_ClearSignatures(TElPGPCustomUserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_RemoveSignature(TElPGPCustomUserHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_RemoveSignature_1(TElPGPCustomUserHandle _Handle, TElPGPSignatureHandle Signature, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_get_Signatures(TElPGPCustomUserHandle _Handle, int32_t Index, TElPGPSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_get_SignatureCount(TElPGPCustomUserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_get_Revoked(TElPGPCustomUserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPCustomUser_Create(TElPGPCustomUserHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPCUSTOMUSER */

#ifdef SB_USE_CLASS_TELPGPUSERID
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_Assign(TElPGPUserIDHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_AssignTo(TElPGPUserIDHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_get_Name(TElPGPUserIDHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_set_Name(TElPGPUserIDHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_get_Trust(TElPGPUserIDHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserID_Create(TElPGPUserIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_Assign(TElPGPUserAttrHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_AssignTo(TElPGPUserAttrHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_AddImage(TElPGPUserAttrHandle _Handle, TElPGPJpegImageHandle Image, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_RemoveImage(TElPGPUserAttrHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_ClearImages(TElPGPUserAttrHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_ImageCount(TElPGPUserAttrHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_get_Trust(TElPGPUserAttrHandle _Handle, TElPGPTrustHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_get_Images(TElPGPUserAttrHandle _Handle, int32_t Index, TElPGPJpegImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_set_Images(TElPGPUserAttrHandle _Handle, int32_t Index, TElPGPJpegImageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPUserAttr_Create(TElPGPUserAttrHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

#ifdef SB_USE_CLASS_TELPGPKEYRING
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Load(TElPGPKeyringHandle _Handle, TStreamHandle APublic, TStreamHandle ASecret, int8_t Clear);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Load_1(TElPGPKeyringHandle _Handle, const char * pcPublicKeysFile, int32_t szPublicKeysFile, const char * pcSecretKeysFile, int32_t szSecretKeysFile, int8_t Clear);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_AddX509Certificate(TElPGPKeyringHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_AddPublicKey(TElPGPKeyringHandle _Handle, TElPGPPublicKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_AddSecretKey(TElPGPKeyringHandle _Handle, TElPGPSecretKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_RemovePublicKey(TElPGPKeyringHandle _Handle, TElPGPPublicKeyHandle Key, int8_t RemoveSecretKeyIfExists, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_RemovePublicKey_1(TElPGPKeyringHandle _Handle, int32_t Index, int8_t RemoveSecretKeyIfExists, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_RemoveSecretKey(TElPGPKeyringHandle _Handle, TElPGPSecretKeyHandle Key, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_RemoveSecretKey_1(TElPGPKeyringHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Clear(TElPGPKeyringHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Save(TElPGPKeyringHandle _Handle, TStreamHandle APublic, TStreamHandle ASecret, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Save_1(TElPGPKeyringHandle _Handle, const char * pcPublicKeysFile, int32_t szPublicKeysFile, const char * pcSecretKeysFile, int32_t szSecretKeysFile, int8_t Armor);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_ExportTo(TElPGPKeyringHandle _Handle, TElPGPKeyringHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindPublicKeyByID(TElPGPKeyringHandle _Handle, const TSBKeyID * KeyID, TElPGPCustomPublicKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindPublicKeyByID_1(TElPGPKeyringHandle _Handle, const char * pcKeyID, int32_t szKeyID, TElPGPCustomPublicKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindSecretKeyByID(TElPGPKeyringHandle _Handle, const TSBKeyID * KeyID, TElPGPCustomSecretKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindSecretKeyByID_1(TElPGPKeyringHandle _Handle, const char * pcKeyID, int32_t szKeyID, TElPGPCustomSecretKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_InternalFindPublicKeyByID(TElPGPKeyringHandle _Handle, const uint8_t pKeyID[], int32_t szKeyID, TElPGPCustomPublicKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_InternalFindSecretKeyByID(TElPGPKeyringHandle _Handle, const uint8_t pKeyID[], int32_t szKeyID, TElPGPCustomSecretKeyHandle * Res, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindPublicKeyByFP(TElPGPKeyringHandle _Handle, const uint8_t pFP[], int32_t szFP, TElPGPCustomPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindSecretKeyByFP(TElPGPKeyringHandle _Handle, const uint8_t pFP[], int32_t szFP, TElPGPCustomSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindPublicKeyByEmailAddress(TElPGPKeyringHandle _Handle, const char * pcAddress, int32_t szAddress, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_FindSecretKeyByEmailAddress(TElPGPKeyringHandle _Handle, const char * pcAddress, int32_t szAddress, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_ListKeys(TElPGPKeyringHandle _Handle, int8_t PublicOnly, const char * pcTemplate, int32_t szTemplate, TListHandle * ListOfKeys);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_ListKeys_1(TElPGPKeyringHandle _Handle, int8_t PublicOnly, const char * pcTemplate, int32_t szTemplate, int8_t IncludeSubkeysMatchingUserIDTemplateInResult, TListHandle * ListOfKeys);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_ListKeys_2(TElPGPKeyringHandle _Handle, int8_t PublicOnly, const TStringListHandle Templates, int8_t IsAndCondition, TListHandle * ListOfKeys);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_ListKeys_3(TElPGPKeyringHandle _Handle, int8_t PublicOnly, const TStringListHandle Templates, int8_t IsAndCondition, int8_t IncludeSubkeysMatchingUserIDTemplateInResult, TListHandle * ListOfKeys);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_PrepareForEncryption(TElPGPKeyringHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_PrepareForSigning(TElPGPKeyringHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_CancelPreparation(TElPGPKeyringHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_AsyncOperationFinished(TElPGPKeyringHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_ArmorBoundary(TElPGPKeyringHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_set_ArmorBoundary(TElPGPKeyringHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_ArmorHeaders(TElPGPKeyringHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_PublicKeys(TElPGPKeyringHandle _Handle, int32_t Index, TElPGPPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_SecretKeys(TElPGPKeyringHandle _Handle, int32_t Index, TElPGPSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_PublicCount(TElPGPKeyringHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_SecretCount(TElPGPKeyringHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_SaveSecretKeySignatures(TElPGPKeyringHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_set_SaveSecretKeySignatures(TElPGPKeyringHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_get_WriteTrust(TElPGPKeyringHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_set_WriteTrust(TElPGPKeyringHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPGPKeyring_Create(TComponentHandle AOwner, TElPGPKeyringHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_Assign(TElPGPJpegImageHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_AssignTo(TElPGPJpegImageHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_Save(TElPGPJpegImageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_Load(TElPGPJpegImageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_SaveToStream(TElPGPJpegImageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_LoadFromStream(TElPGPJpegImageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_SaveToFile(TElPGPJpegImageHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_LoadFromFile(TElPGPJpegImageHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_get_JpegData(TElPGPJpegImageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_set_JpegData(TElPGPJpegImageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_get_OnRead(TElPGPJpegImageHandle _Handle, TSBPGPReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_set_OnRead(TElPGPJpegImageHandle _Handle, TSBPGPReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_get_OnWrite(TElPGPJpegImageHandle _Handle, TSBPGPWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_set_OnWrite(TElPGPJpegImageHandle _Handle, TSBPGPWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_Create(TElPGPJpegImageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPGPJpegImage_Create_1(TElPGPUserAttrImageSubpacketHandle Source, TElPGPJpegImageHandle * OutResult);
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPGPCustomPublicKey;
typedef TElPGPCustomPublicKey ElPGPCustomPublicKey;
class TElPGPPublicSubkey;
typedef TElPGPPublicSubkey ElPGPPublicSubkey;
class TElPGPPublicKey;
typedef TElPGPPublicKey ElPGPPublicKey;
class TElPGPCustomSecretKey;
typedef TElPGPCustomSecretKey ElPGPCustomSecretKey;
class TElPGPSecretSubkey;
typedef TElPGPSecretSubkey ElPGPSecretSubkey;
class TElPGPSecretKey;
typedef TElPGPSecretKey ElPGPSecretKey;
class TElPGPTrust;
typedef TElPGPTrust ElPGPTrust;
class TElPGPSignature;
typedef TElPGPSignature ElPGPSignature;
class TElPGPCustomUser;
typedef TElPGPCustomUser ElPGPCustomUser;
class TElPGPUserID;
typedef TElPGPUserID ElPGPUserID;
class TElPGPUserAttr;
typedef TElPGPUserAttr ElPGPUserAttr;
class TElPGPKeyring;
typedef TElPGPKeyring ElPGPKeyring;
class TElPGPJpegImage;

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
class TElPGPCustomPublicKey: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPCustomPublicKey)
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		TElPGPSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		int32_t AddSignature(TElPGPSignature &Signature);

		int32_t AddSignature(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		bool RemoveSignature(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool RemoveSignature(TElPGPSignature &Signature);

		bool RemoveSignature(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void ClearSignatures();

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE
		bool Verify(TElPGPCustomPublicKey &PublicKey, TElPGPCustomUser &User, TElPGPSignature &Signature);

		bool Verify(TElPGPCustomPublicKey *PublicKey, TElPGPCustomUser *User, TElPGPSignature *Signature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool Verify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		bool Verify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE
		bool Verify(TElHashFunction &HashFunction, TElPGPSignature &Signature);

		bool Verify(TElHashFunction *HashFunction, TElPGPSignature *Signature);
#endif /* SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool Verify(TElPGPSignature &Signature);

		bool Verify(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool Verify(TElPGPSignature &SubjectSignature, TElPGPSignature &Signature);

		bool Verify(TElPGPSignature *SubjectSignature, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool DirectVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		bool DirectVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool RevocationVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		bool RevocationVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE
		bool RevocationVerify(TElPGPCustomPublicKey &Key, TElPGPCustomUser &User, TElPGPSignature &Signature);

		bool RevocationVerify(TElPGPCustomPublicKey *Key, TElPGPCustomUser *User, TElPGPSignature *Signature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool DirectRevocationVerify(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		bool DirectRevocationVerify(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterialHandle ExportKeyMaterial();
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial);

		void ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);

		void ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void Encrypt(const std::vector<uint8_t> &Data, TSBPGPEncryptedSymmetricKey &OutResult);

		bool IsSigningKey(bool WithSubkeys);

		bool IsEncryptingKey(bool WithSubkeys);

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

		void AcquireLock();

		void ReleaseLock();

		void KeyID(TSBKeyID &OutResult);

		void KeyFP(std::vector<uint8_t> &OutResult);

		virtual int64_t get_Timestamp();

		virtual void set_Timestamp(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Timestamp, set_Timestamp, TElPGPCustomPublicKey, Timestamp);

		virtual int32_t get_Expires();

		virtual void set_Expires(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Expires, set_Expires, TElPGPCustomPublicKey, Expires);

		virtual int32_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyAlgorithm, TElPGPCustomPublicKey, PublicKeyAlgorithm);

		virtual int32_t get_BitsInKey();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BitsInKey, TElPGPCustomPublicKey, BitsInKey);

		virtual int32_t get_KeyHashAlgorithm();

		virtual void set_KeyHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyHashAlgorithm, set_KeyHashAlgorithm, TElPGPCustomPublicKey, KeyHashAlgorithm);

		virtual int32_t get_QBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_QBits, TElPGPCustomPublicKey, QBits);

		virtual int32_t get_Curve();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Curve, TElPGPCustomPublicKey, Curve);

		virtual int32_t get_Version();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Version, TElPGPCustomPublicKey, Version);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElPGPCustomPublicKey, UseOldPackets);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		virtual TElPGPSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElPGPCustomPublicKey, SignatureCount);

		virtual bool get_Revoked();

		SB_DECLARE_PROPERTY_GET(bool, get_Revoked, TElPGPCustomPublicKey, Revoked);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElPGPCustomPublicKey, Enabled);

		TElPGPCustomPublicKey(TElPGPCustomPublicKeyHandle handle, TElOwnHandle ownHandle);

		TElPGPCustomPublicKey();

		virtual ~TElPGPCustomPublicKey();

};
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
class TElPGPPublicSubkey: public TElPGPCustomPublicKey
{
	private:
		SB_DISABLE_COPY(TElPGPPublicSubkey)
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		TElPGPSecretSubkey* _Inst_SecretKey;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		TElPGPPublicKey* _Inst_Supkey;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		virtual TElPGPSecretSubkey* get_SecretKey();

		SB_DECLARE_PROPERTY_GET(TElPGPSecretSubkey*, get_SecretKey, TElPGPPublicSubkey, SecretKey);
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		virtual TElPGPPublicKey* get_Supkey();

		SB_DECLARE_PROPERTY_GET(TElPGPPublicKey*, get_Supkey, TElPGPPublicSubkey, Supkey);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPPublicSubkey, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

		TElPGPPublicSubkey(TElPGPPublicSubkeyHandle handle, TElOwnHandle ownHandle);

		TElPGPPublicSubkey();

		virtual ~TElPGPPublicSubkey();

};
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
class TElPGPPublicKey: public TElPGPCustomPublicKey
{
	private:
		SB_DISABLE_COPY(TElPGPPublicKey)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		TElPGPPublicSubkey* _Inst_Subkeys;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */
#ifdef SB_USE_CLASS_TELPGPUSERID
		TElPGPUserID* _Inst_UserIDs;
#endif /* SB_USE_CLASS_TELPGPUSERID */
#ifdef SB_USE_CLASS_TELPGPUSERATTR
		TElPGPUserAttr* _Inst_UserAttrs;
#endif /* SB_USE_CLASS_TELPGPUSERATTR */
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		TElPGPSecretKey* _Inst_SecretKey;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		void initInstances();

	public:
		bool RemoveSubkey(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		bool RemoveSubkey(TElPGPPublicSubkey &Subkey);

		bool RemoveSubkey(TElPGPPublicSubkey *Subkey);
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void AssignFromX509(TElX509Certificate &Certificate);

		void AssignFromX509(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void LoadFromStream(TStream &Stream);

		virtual void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadFromFile(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream, bool Armor);

		virtual void SaveToStream(TStream *Stream, bool Armor);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToFile(const std::string &Filename, bool Armor);

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		int32_t AddSubkey(TElPGPPublicSubkey &Subkey);

		int32_t AddSubkey(TElPGPPublicSubkey *Subkey);
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

		void ClearSubkeys();

#ifdef SB_USE_CLASS_TELPGPUSERID
		int32_t AddUserID(TElPGPUserID &User);

		int32_t AddUserID(TElPGPUserID *User);
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
		int32_t AddUserAttr(TElPGPUserAttr &User);

		int32_t AddUserAttr(TElPGPUserAttr *User);
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

		bool RemoveUserID(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPUSERID
		bool RemoveUserID(TElPGPUserID &User);

		bool RemoveUserID(TElPGPUserID *User);
#endif /* SB_USE_CLASS_TELPGPUSERID */

		bool RemoveUserAttr(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPUSERATTR
		bool RemoveUserAttr(TElPGPUserAttr &UserAttr);

		bool RemoveUserAttr(TElPGPUserAttr *UserAttr);
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

		void ClearUserIDs();

		void ClearUserAttrs();

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

		virtual void get_ArmorBoundary(std::string &OutResult);

		virtual void set_ArmorBoundary(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ArmorHeaders, TElPGPPublicKey, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		virtual TElPGPPublicSubkey* get_Subkeys(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

#ifdef SB_USE_CLASS_TELPGPUSERID
		virtual TElPGPUserID* get_UserIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
		virtual TElPGPUserAttr* get_UserAttrs(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

		virtual int32_t get_PreferredSymAlgs(int32_t Index);

		virtual int32_t get_PreferredHashAlgs(int32_t Index);

		virtual int32_t get_PreferredComprAlgs(int32_t Index);

		virtual int32_t get_SubkeyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubkeyCount, TElPGPPublicKey, SubkeyCount);

		virtual int32_t get_UserIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_UserIDCount, TElPGPPublicKey, UserIDCount);

		virtual int32_t get_UserAttrCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_UserAttrCount, TElPGPPublicKey, UserAttrCount);

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPPublicKey, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

		virtual TSBPGPKeyTrust get_KeyTrust();

		virtual void set_KeyTrust(TSBPGPKeyTrust Value);

		SB_DECLARE_PROPERTY(TSBPGPKeyTrust, get_KeyTrust, set_KeyTrust, TElPGPPublicKey, KeyTrust);

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		virtual TElPGPSecretKey* get_SecretKey();

		SB_DECLARE_PROPERTY_GET(TElPGPSecretKey*, get_SecretKey, TElPGPPublicKey, SecretKey);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		virtual bool get_WriteOldPrefix();

		virtual void set_WriteOldPrefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteOldPrefix, set_WriteOldPrefix, TElPGPPublicKey, WriteOldPrefix);

		virtual int32_t get_PreferredSymAlgCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PreferredSymAlgCount, TElPGPPublicKey, PreferredSymAlgCount);

		virtual int32_t get_PreferredHashAlgCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PreferredHashAlgCount, TElPGPPublicKey, PreferredHashAlgCount);

		virtual int32_t get_PreferredComprAlgCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PreferredComprAlgCount, TElPGPPublicKey, PreferredComprAlgCount);

		TElPGPPublicKey(TElPGPPublicKeyHandle handle, TElOwnHandle ownHandle);

		TElPGPPublicKey();

		virtual ~TElPGPPublicKey();

};
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
class TElPGPCustomSecretKey: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPCustomSecretKey)
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		void Generate(const std::string &Password, int32_t Bits, int32_t Algorithm, bool UseOldFormat, int32_t Expires);

		void BeginGenerate(int32_t Bits, int32_t Algorithm);

		void EndGenerate(const std::string &Password, bool UseOldFormat, int32_t Expires);

		void CancelGeneration();

		void ChangePassphrase(const std::string &NewPassphrase, TSBPGPProtectionType ProtectionType);

		void ChangeProtection(const std::string &NewPassphrase, TSBPGPProtectionType PrType, int32_t EncAlgorithm, int32_t HshAlgorithm);

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE
		void Sign(TElPGPPublicKey &PublicKey, TElPGPCustomUser &User, TElPGPSignature &Signature, TSBPGPUserCertificationType CertType);

		void Sign(TElPGPPublicKey *PublicKey, TElPGPCustomUser *User, TElPGPSignature *Signature, TSBPGPUserCertificationType CertType);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
		void Sign(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature, TElPGPSignature &EmbeddedSignature);

		void Sign(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature, TElPGPSignature *EmbeddedSignature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		void Sign(int64_t TimeStamp, TElPGPSignature &Signature);

		void Sign(int64_t TimeStamp, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		void Sign(TElPGPSignature &SubjectSignature, TElPGPSignature &Signature);

		void Sign(TElPGPSignature *SubjectSignature, TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE
		void Sign(TElHashFunction &HashFunction, TElPGPSignature &Signature, int32_t SignatureClass);

		void Sign(TElHashFunction *HashFunction, TElPGPSignature *Signature, int32_t SignatureClass);
#endif /* SB_USE_CLASSES_TELHASHFUNCTION_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
		void DirectSign(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		void DirectSign(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
		void Revoke(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature);

		void Revoke(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE
		void Revoke(TElPGPPublicKey &Key, TElPGPCustomUser &User, TElPGPSignature &Signature, TElPGPSignature &RevokedSignature);

		void Revoke(TElPGPPublicKey *Key, TElPGPCustomUser *User, TElPGPSignature *Signature, TElPGPSignature *RevokedSignature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMUSER_AND_TELPGPPUBLICKEY_AND_TELPGPSIGNATURE */

#ifdef SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE
		void DirectRevoke(TElPGPCustomPublicKey &Key, TElPGPSignature &Signature, TElPGPSignature &RevokedSignature);

		void DirectRevoke(TElPGPCustomPublicKey *Key, TElPGPSignature *Signature, TElPGPSignature *RevokedSignature);
#endif /* SB_USE_CLASSES_TELPGPCUSTOMPUBLICKEY_AND_TELPGPSIGNATURE */

		void Decrypt(const TSBPGPEncryptedSymmetricKey &EncrData, std::vector<uint8_t> &OutResult);

		bool PassphraseValid();

		bool IsSigningKey(bool WithSubkeys);

		bool IsEncryptingKey(bool WithSubkeys);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterialHandle ExportKeyMaterial(bool PublicOnly);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ExportSecretKeyMaterial(TElPublicKeyMaterial &KeyMaterial);

		void ExportSecretKeyMaterial(TElPublicKeyMaterial *KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial);

		void ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &SecKeyMaterial, TElPublicKeyMaterial &PubKeyMaterial);

		void ImportKeyMaterial(TElPublicKeyMaterial *SecKeyMaterial, TElPublicKeyMaterial *PubKeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);

		void ImportKeyMaterial(TElPublicKeyMaterial *KeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void ImportKeyMaterial(TElPublicKeyMaterial &SecKeyMaterial, TElPublicKeyMaterial &PubKeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);

		void ImportKeyMaterial(TElPublicKeyMaterial *SecKeyMaterial, TElPublicKeyMaterial *PubKeyMaterial, int64_t Timestamp, int32_t KeyVersion, int32_t Expires);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void KeyID(TSBKeyID &OutResult);

		void KeyFP(std::vector<uint8_t> &OutResult);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

		void AcquireLock();

		void ReleaseLock();

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElPGPCustomSecretKey, UseOldPackets);

		virtual int64_t get_Timestamp();

		virtual void set_Timestamp(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Timestamp, set_Timestamp, TElPGPCustomSecretKey, Timestamp);

		virtual int32_t get_Version();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Version, TElPGPCustomSecretKey, Version);

		virtual int32_t get_Expires();

		virtual void set_Expires(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Expires, set_Expires, TElPGPCustomSecretKey, Expires);

		virtual int32_t get_BitsInKey();

		SB_DECLARE_PROPERTY_GET(int32_t, get_BitsInKey, TElPGPCustomSecretKey, BitsInKey);

		virtual int32_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyAlgorithm, TElPGPCustomSecretKey, PublicKeyAlgorithm);

		virtual int32_t get_EncryptionAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EncryptionAlgorithm, TElPGPCustomSecretKey, EncryptionAlgorithm);

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElPGPCustomSecretKey, HashAlgorithm);

		virtual int32_t get_KeyHashAlgorithm();

		virtual void set_KeyHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyHashAlgorithm, set_KeyHashAlgorithm, TElPGPCustomSecretKey, KeyHashAlgorithm);

		virtual int32_t get_QBits();

		virtual void set_QBits(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_QBits, set_QBits, TElPGPCustomSecretKey, QBits);

		virtual int32_t get_Curve();

		virtual void set_Curve(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Curve, set_Curve, TElPGPCustomSecretKey, Curve);

		virtual TSBPGPProtectionType get_Protection();

		SB_DECLARE_PROPERTY_GET(TSBPGPProtectionType, get_Protection, TElPGPCustomSecretKey, Protection);

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPCustomSecretKey, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElPGPCustomSecretKey, Enabled);

		TElPGPCustomSecretKey(TElPGPCustomSecretKeyHandle handle, TElOwnHandle ownHandle);

		TElPGPCustomSecretKey();

		virtual ~TElPGPCustomSecretKey();

};
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
class TElPGPSecretSubkey: public TElPGPCustomSecretKey
{
	private:
		SB_DISABLE_COPY(TElPGPSecretSubkey)
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		TElPGPSecretKey* _Inst_Supkey;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		TElPGPPublicSubkey* _Inst_PublicKey;
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		virtual TElPGPSecretKey* get_Supkey();

		SB_DECLARE_PROPERTY_GET(TElPGPSecretKey*, get_Supkey, TElPGPSecretSubkey, Supkey);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICSUBKEY
		virtual TElPGPPublicSubkey* get_PublicKey();

		SB_DECLARE_PROPERTY_GET(TElPGPPublicSubkey*, get_PublicKey, TElPGPSecretSubkey, PublicKey);
#endif /* SB_USE_CLASS_TELPGPPUBLICSUBKEY */

		TElPGPSecretSubkey(TElPGPSecretSubkeyHandle handle, TElOwnHandle ownHandle);

		TElPGPSecretSubkey();

		virtual ~TElPGPSecretSubkey();

};
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
class TElPGPSecretKey: public TElPGPCustomSecretKey
{
	private:
		SB_DISABLE_COPY(TElPGPSecretKey)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		TElPGPSecretSubkey* _Inst_Subkeys;
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		TElPGPPublicKey* _Inst_PublicKey;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

		void initInstances();

	public:
		bool RemoveSubkey(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		bool RemoveSubkey(TElPGPSecretSubkey &Subkey);

		bool RemoveSubkey(TElPGPSecretSubkey *Subkey);
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void AssignFromX509(TElX509Certificate &Certificate);

		void AssignFromX509(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void LoadFromStream(TStream &Stream);

		virtual void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadFromFile(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream, bool Armor);

		virtual void SaveToStream(TStream *Stream, bool Armor);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToFile(const std::string &Filename, bool Armor);

#ifdef SB_USE_CLASS_TELPGPCUSTOMUSER
		void BindUser(TElPGPCustomUser &User);

		void BindUser(TElPGPCustomUser *User);
#endif /* SB_USE_CLASS_TELPGPCUSTOMUSER */

		void Generate(const std::string &Password, int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm, const std::string &UserName, int32_t Expires);

		void Generate(const std::string &Password, int32_t KeyBits, int32_t KeyAlgorithm, const std::string &UserName, bool UseOldStyle, int32_t Expires);

		void BeginGenerate(int32_t KeyBits, int32_t KeyAlgorithm, int32_t SubkeyBits, int32_t SubkeyAlgorithm);

		void EndGenerate(const std::string &Password, const std::string &UserName, int32_t Expires, bool UseOldFormat);

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		int32_t AddSubkey(TElPGPSecretSubkey &Subkey);

		int32_t AddSubkey(TElPGPSecretSubkey *Subkey);
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

		virtual void get_ArmorBoundary(std::string &OutResult);

		virtual void set_ArmorBoundary(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ArmorHeaders, TElPGPSecretKey, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPSECRETSUBKEY
		virtual TElPGPSecretSubkey* get_Subkeys(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSECRETSUBKEY */

		virtual int32_t get_SubkeyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubkeyCount, TElPGPSecretKey, SubkeyCount);

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		virtual TElPGPPublicKey* get_PublicKey();

		SB_DECLARE_PROPERTY_GET(TElPGPPublicKey*, get_PublicKey, TElPGPSecretKey, PublicKey);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

		virtual uint8_t get_WriteFlags();

		virtual void set_WriteFlags(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_WriteFlags, set_WriteFlags, TElPGPSecretKey, WriteFlags);

		virtual bool get_WriteOldPrefix();

		virtual void set_WriteOldPrefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteOldPrefix, set_WriteOldPrefix, TElPGPSecretKey, WriteOldPrefix);

		virtual void get_OnBeforeSign(TSBPGPBeforeSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBPGPBeforeSignEvent pMethodValue, void * pDataValue);

		TElPGPSecretKey(TElPGPSecretKeyHandle handle, TElOwnHandle ownHandle);

		TElPGPSecretKey();

		virtual ~TElPGPSecretKey();

};
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPTRUST
class TElPGPTrust: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPTrust)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual uint8_t get_OwnerTrust();

		virtual void set_OwnerTrust(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_OwnerTrust, set_OwnerTrust, TElPGPTrust, OwnerTrust);

		virtual bool get_Disabled();

		virtual void set_Disabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Disabled, set_Disabled, TElPGPTrust, Disabled);

		virtual bool get_BuckStop();

		virtual void set_BuckStop(bool Value);

		SB_DECLARE_PROPERTY(bool, get_BuckStop, set_BuckStop, TElPGPTrust, BuckStop);

		virtual uint8_t get_KeyLegit();

		virtual void set_KeyLegit(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_KeyLegit, set_KeyLegit, TElPGPTrust, KeyLegit);

		virtual bool get_WarnOnly();

		virtual void set_WarnOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WarnOnly, set_WarnOnly, TElPGPTrust, WarnOnly);

		virtual uint8_t get_SigTrust();

		virtual void set_SigTrust(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_SigTrust, set_SigTrust, TElPGPTrust, SigTrust);

		virtual bool get_Checked();

		virtual void set_Checked(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Checked, set_Checked, TElPGPTrust, Checked);

		virtual bool get_Contiguous();

		virtual void set_Contiguous(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Contiguous, set_Contiguous, TElPGPTrust, Contiguous);

		virtual uint8_t get_Flags();

		virtual void set_Flags(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Flags, set_Flags, TElPGPTrust, Flags);

		TElPGPTrust(TElPGPTrustHandle handle, TElOwnHandle ownHandle);

		TElPGPTrust();

};
#endif /* SB_USE_CLASS_TELPGPTRUST */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
class TElPGPSignature: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPSignature)
#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
		TElPGPSignatureSubpacket* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_X509Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveOnePass(bool Nested);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveOnePassToStream(TStream &Stream, bool Nested);

		void SaveOnePassToStream(TStream *Stream, bool Nested);
#endif /* SB_USE_CLASS_TSTREAM */

		bool IsKeyRevocation();

		bool IsSubkeyRevocation();

		bool IsUserRevocation();

		bool IsDocumentSignature();

		bool IsStandalone();

		bool IsUserCertification();

		bool IsSubkeyBinding();

		bool IsDirectKeySignature();

		bool IsTimestampSignature();

		void SignerKeyID(TSBKeyID &OutResult);

		int32_t AddExtension(TSBPGPSignatureExtension ExtType, bool Hashed, bool Critical);

		bool RemoveExtension(TSBPGPSignatureExtension ExtType, int32_t Index);

		bool RemoveExtension(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
		TElPGPSignatureSubpacketHandle GetExtensionByType(TSBPGPSignatureExtension ExtType, int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

		int32_t GetExtensionCount(TSBPGPSignatureExtension ExtType);

		void ClearExtensions();

		virtual bool get_IsX509Certificate();

		SB_DECLARE_PROPERTY_GET(bool, get_IsX509Certificate, TElPGPSignature, IsX509Certificate);

#ifdef SB_USE_CLASS_TELPGPSIGNATURESUBPACKET
		virtual TElPGPSignatureSubpacket* get_Extensions(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSIGNATURESUBPACKET */

		virtual void get_RegularExpression(int32_t Index, std::string &OutResult);

		virtual void set_RegularExpression(int32_t Index, const std::string &Value);

		virtual uint8_t get_Version();

		virtual void set_Version(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Version, set_Version, TElPGPSignature, Version);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElPGPSignature, HashAlgorithm);

		virtual bool get_UseOldPackets();

		virtual void set_UseOldPackets(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOldPackets, set_UseOldPackets, TElPGPSignature, UseOldPackets);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_X509Certificate();

		SB_DECLARE_PROPERTY_GET(TElX509Certificate*, get_X509Certificate, TElPGPSignature, X509Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_Validated();

		virtual void set_Validated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Validated, set_Validated, TElPGPSignature, Validated);

		virtual bool get_StrictlyValid();

		virtual void set_StrictlyValid(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictlyValid, set_StrictlyValid, TElPGPSignature, StrictlyValid);

		virtual int64_t get_CreationTime();

		virtual void set_CreationTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_CreationTime, set_CreationTime, TElPGPSignature, CreationTime);

		virtual int32_t get_KeyExpirationTime();

		virtual void set_KeyExpirationTime(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyExpirationTime, set_KeyExpirationTime, TElPGPSignature, KeyExpirationTime);

		virtual int32_t get_ExpirationTime();

		virtual void set_ExpirationTime(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExpirationTime, set_ExpirationTime, TElPGPSignature, ExpirationTime);

		virtual bool get_Exportable();

		virtual void set_Exportable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Exportable, set_Exportable, TElPGPSignature, Exportable);

		virtual bool get_Revocable();

		virtual void set_Revocable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Revocable, set_Revocable, TElPGPSignature, Revocable);

		virtual uint8_t get_TrustLevel();

		virtual void set_TrustLevel(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_TrustLevel, set_TrustLevel, TElPGPSignature, TrustLevel);

		virtual uint8_t get_TrustAmount();

		virtual void set_TrustAmount(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_TrustAmount, set_TrustAmount, TElPGPSignature, TrustAmount);

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPSignature, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

		virtual int32_t get_RegularExpressionCount();

		virtual void set_RegularExpressionCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RegularExpressionCount, set_RegularExpressionCount, TElPGPSignature, RegularExpressionCount);

		virtual bool get_PrimaryUserID();

		virtual void set_PrimaryUserID(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PrimaryUserID, set_PrimaryUserID, TElPGPSignature, PrimaryUserID);

		virtual void get_PolicyURL(std::string &OutResult);

		virtual void set_PolicyURL(const std::string &Value);

		virtual void get_SignerUserID(std::string &OutResult);

		virtual void set_SignerUserID(const std::string &Value);

		virtual void get_ReasonForRevocation(std::string &OutResult);

		virtual void set_ReasonForRevocation(const std::string &Value);

		virtual int32_t get_SignatureClass();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureClass, TElPGPSignature, SignatureClass);

		virtual TSBPGPUserCertificationType get_CertificationType();

		virtual void set_CertificationType(TSBPGPUserCertificationType Value);

		SB_DECLARE_PROPERTY(TSBPGPUserCertificationType, get_CertificationType, set_CertificationType, TElPGPSignature, CertificationType);

		virtual bool get_Revocation();

		SB_DECLARE_PROPERTY_GET(bool, get_Revocation, TElPGPSignature, Revocation);

		virtual bool get_IsTextSignature();

		SB_DECLARE_PROPERTY_GET(bool, get_IsTextSignature, TElPGPSignature, IsTextSignature);

		TElPGPSignature(TElPGPSignatureHandle handle, TElOwnHandle ownHandle);

		TElPGPSignature();

#ifdef SB_USE_CLASS_TELPGPSIGNATUREENTITY
		explicit TElPGPSignature(TElPGPSignatureEntity &Entity);

		explicit TElPGPSignature(TElPGPSignatureEntity *Entity);
#endif /* SB_USE_CLASS_TELPGPSIGNATUREENTITY */

		TElPGPSignature(TElPGPSignature &Source, bool CopySigMaterial);

		TElPGPSignature(TElPGPSignature *Source, bool CopySigMaterial);

		virtual ~TElPGPSignature();

};
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPCUSTOMUSER
class TElPGPCustomUser: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPCustomUser)
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		TElPGPSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		int32_t AddSignature(TElPGPSignature &Signature);

		int32_t AddSignature(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		void ClearSignatures();

		bool RemoveSignature(int32_t Index);

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		bool RemoveSignature(TElPGPSignature &Signature);

		bool RemoveSignature(TElPGPSignature *Signature);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
		virtual TElPGPSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElPGPCustomUser, SignatureCount);

		virtual bool get_Revoked();

		SB_DECLARE_PROPERTY_GET(bool, get_Revoked, TElPGPCustomUser, Revoked);

		TElPGPCustomUser(TElPGPCustomUserHandle handle, TElOwnHandle ownHandle);

		TElPGPCustomUser();

		virtual ~TElPGPCustomUser();

};
#endif /* SB_USE_CLASS_TELPGPCUSTOMUSER */

#ifdef SB_USE_CLASS_TELPGPUSERID
class TElPGPUserID: public TElPGPCustomUser
{
	private:
		SB_DISABLE_COPY(TElPGPUserID)
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPUserID, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

		TElPGPUserID(TElPGPUserIDHandle handle, TElOwnHandle ownHandle);

		TElPGPUserID();

		virtual ~TElPGPUserID();

};
#endif /* SB_USE_CLASS_TELPGPUSERID */

#ifdef SB_USE_CLASS_TELPGPUSERATTR
class TElPGPUserAttr: public TElPGPCustomUser
{
	private:
		SB_DISABLE_COPY(TElPGPUserAttr)
#ifdef SB_USE_CLASS_TELPGPTRUST
		TElPGPTrust* _Inst_Trust;
#endif /* SB_USE_CLASS_TELPGPTRUST */
#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
		TElPGPJpegImage* _Inst_Images;
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
		int32_t AddImage(TElPGPJpegImage &Image);

		int32_t AddImage(TElPGPJpegImage *Image);
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

		bool RemoveImage(int32_t Index);

		void ClearImages();

		int32_t ImageCount();

#ifdef SB_USE_CLASS_TELPGPTRUST
		virtual TElPGPTrust* get_Trust();

		SB_DECLARE_PROPERTY_GET(TElPGPTrust*, get_Trust, TElPGPUserAttr, Trust);
#endif /* SB_USE_CLASS_TELPGPTRUST */

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
		virtual TElPGPJpegImage* get_Images(int32_t Index);

		virtual void set_Images(int32_t Index, TElPGPJpegImage &Value);

		virtual void set_Images(int32_t Index, TElPGPJpegImage *Value);
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

		TElPGPUserAttr(TElPGPUserAttrHandle handle, TElOwnHandle ownHandle);

		TElPGPUserAttr();

		virtual ~TElPGPUserAttr();

};
#endif /* SB_USE_CLASS_TELPGPUSERATTR */

#ifdef SB_USE_CLASS_TELPGPKEYRING
class TElPGPKeyring: public TComponent
{
	private:
		SB_DISABLE_COPY(TElPGPKeyring)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_ArmorHeaders;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		TElPGPPublicKey* _Inst_PublicKeys;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		TElPGPSecretKey* _Inst_SecretKeys;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Load(TStream &APublic, TStream &ASecret, bool Clear);

		void Load(TStream *APublic, TStream *ASecret, bool Clear);
#endif /* SB_USE_CLASS_TSTREAM */

		void Load(const std::string &PublicKeysFile, const std::string &SecretKeysFile, bool Clear);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddX509Certificate(TElX509Certificate &Certificate);

		int32_t AddX509Certificate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		int32_t AddPublicKey(TElPGPPublicKey &Key);

		int32_t AddPublicKey(TElPGPPublicKey *Key);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		int32_t AddSecretKey(TElPGPSecretKey &Key);

		int32_t AddSecretKey(TElPGPSecretKey *Key);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		bool RemovePublicKey(TElPGPPublicKey &Key, bool RemoveSecretKeyIfExists);

		bool RemovePublicKey(TElPGPPublicKey *Key, bool RemoveSecretKeyIfExists);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

		bool RemovePublicKey(int32_t Index, bool RemoveSecretKeyIfExists);

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		bool RemoveSecretKey(TElPGPSecretKey &Key);

		bool RemoveSecretKey(TElPGPSecretKey *Key);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		bool RemoveSecretKey(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		void Save(TStream &APublic, TStream &ASecret, bool Armor);

		void Save(TStream *APublic, TStream *ASecret, bool Armor);
#endif /* SB_USE_CLASS_TSTREAM */

		void Save(const std::string &PublicKeysFile, const std::string &SecretKeysFile, bool Armor);

		void ExportTo(TElPGPKeyring &Dest);

		void ExportTo(TElPGPKeyring *Dest);

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		int32_t FindPublicKeyByID(const TSBKeyID &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		int32_t FindPublicKeyByID(const std::string &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		int32_t FindSecretKeyByID(const TSBKeyID &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		int32_t FindSecretKeyByID(const std::string &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		int32_t InternalFindPublicKeyByID(const std::vector<uint8_t> &KeyID, TElPGPCustomPublicKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		int32_t InternalFindSecretKeyByID(const std::vector<uint8_t> &KeyID, TElPGPCustomSecretKey &Res, int32_t StartIndex);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		TElPGPCustomPublicKeyHandle FindPublicKeyByFP(const std::vector<uint8_t> &FP);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		TElPGPCustomSecretKeyHandle FindSecretKeyByFP(const std::vector<uint8_t> &FP);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

		int32_t FindPublicKeyByEmailAddress(const std::string &Address, int32_t StartIndex);

		int32_t FindSecretKeyByEmailAddress(const std::string &Address, int32_t StartIndex);

#ifdef SB_USE_CLASS_TLIST
		void ListKeys(bool PublicOnly, const std::string &Template, TList &ListOfKeys);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TLIST
		void ListKeys(bool PublicOnly, const std::string &Template, bool IncludeSubkeysMatchingUserIDTemplateInResult, TList &ListOfKeys);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTRINGLIST
		void ListKeys(bool PublicOnly, const TStringList &Templates, bool IsAndCondition, TList &ListOfKeys);
#endif /* SB_USE_CLASSES_TLIST_AND_TSTRINGLIST */

#ifdef SB_USE_CLASSES_TLIST_AND_TSTRINGLIST
		void ListKeys(bool PublicOnly, const TStringList &Templates, bool IsAndCondition, bool IncludeSubkeysMatchingUserIDTemplateInResult, TList &ListOfKeys);
#endif /* SB_USE_CLASSES_TLIST_AND_TSTRINGLIST */

		void PrepareForEncryption(bool MultiUse);

		void PrepareForSigning(bool MultiUse);

		void CancelPreparation();

		bool AsyncOperationFinished();

		virtual void get_ArmorBoundary(std::string &OutResult);

		virtual void set_ArmorBoundary(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_ArmorHeaders();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_ArmorHeaders, TElPGPKeyring, ArmorHeaders);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		virtual TElPGPPublicKey* get_PublicKeys(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		virtual TElPGPSecretKey* get_SecretKeys(int32_t Index);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		virtual int32_t get_PublicCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicCount, TElPGPKeyring, PublicCount);

		virtual int32_t get_SecretCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SecretCount, TElPGPKeyring, SecretCount);

		virtual bool get_SaveSecretKeySignatures();

		virtual void set_SaveSecretKeySignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveSecretKeySignatures, set_SaveSecretKeySignatures, TElPGPKeyring, SaveSecretKeySignatures);

		virtual bool get_WriteTrust();

		virtual void set_WriteTrust(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteTrust, set_WriteTrust, TElPGPKeyring, WriteTrust);

		TElPGPKeyring(TElPGPKeyringHandle handle, TElOwnHandle ownHandle);

		explicit TElPGPKeyring(TComponent &AOwner);

		explicit TElPGPKeyring(TComponent *AOwner);

		virtual ~TElPGPKeyring();

};
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TELPGPJPEGIMAGE
class TElPGPJpegImage: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPGPJpegImage)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		void Save();

		void Load();

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void SaveToFile(const std::string &FileName);

		void LoadFromFile(const std::string &FileName);

		virtual void get_JpegData(std::vector<uint8_t> &OutResult);

		virtual void set_JpegData(const std::vector<uint8_t> &Value);

		virtual void get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue);

		TElPGPJpegImage(TElPGPJpegImageHandle handle, TElOwnHandle ownHandle);

		TElPGPJpegImage();

#ifdef SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET
		explicit TElPGPJpegImage(TElPGPUserAttrImageSubpacket &Source);

		explicit TElPGPJpegImage(TElPGPUserAttrImageSubpacket *Source);
#endif /* SB_USE_CLASS_TELPGPUSERATTRIMAGESUBPACKET */

};
#endif /* SB_USE_CLASS_TELPGPJPEGIMAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPKEYS */

