#ifndef __INC_SBCUSTOMCERTSTORAGE
#define __INC_SBCUSTOMCERTSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbcryptoprov.h"
#include "sbrdn.h"
#include "sbsymmetriccrypto.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbcrl.h"
#include "sbpem.h"
#include "sbjks.h"
#include "sbstreams.h"
#include "sbsharedresource.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCustomCertStorageHandle;

typedef TElCustomCertStorageHandle ElCustomCertStorageHandle;

typedef TElClassHandle TElCertificateLookupHandle;

typedef TElCertificateLookupHandle ElCertificateLookupHandle;

typedef TElClassHandle TElMemoryCertStorageHandle;

typedef TElMemoryCertStorageHandle ElMemoryCertStorageHandle;

typedef TElClassHandle TElFileCertStorageHandle;

typedef TElFileCertStorageHandle ElFileCertStorageHandle;

typedef uint8_t TSBLookupCriterionRaw;

typedef enum
{
	lcIssuer = 0,
	lcSubject = 1,
	lcValidity = 2,
	lcPublicKeyAlgorithm = 3,
	lcSignatureAlgorithm = 4,
	lcPublicKeySize = 5,
	lcAuthorityKeyIdentifier = 6,
	lcSubjectKeyIdentifier = 7,
	lcKeyUsage = 8,
	lcEmail = 9,
	lcSerialNumber = 10,
	lcPublicKeyHash = 11,
	lcCertificateHash = 12
} TSBLookupCriterion;

typedef uint32_t TSBLookupCriteriaRaw;

typedef enum 
{
	f_lcIssuer = 1,
	f_lcSubject = 2,
	f_lcValidity = 4,
	f_lcPublicKeyAlgorithm = 8,
	f_lcSignatureAlgorithm = 16,
	f_lcPublicKeySize = 32,
	f_lcAuthorityKeyIdentifier = 64,
	f_lcSubjectKeyIdentifier = 128,
	f_lcKeyUsage = 256,
	f_lcEmail = 512,
	f_lcSerialNumber = 1024,
	f_lcPublicKeyHash = 2048,
	f_lcCertificateHash = 4096
} TSBLookupCriteria;

typedef uint8_t TSBLookupOptionRaw;

typedef enum
{
	loExactMatch = 0,
	loMatchAll = 1,
	loCompareRDNAsStrings = 2
} TSBLookupOption;

typedef uint32_t TSBLookupOptionsRaw;

typedef enum 
{
	f_loExactMatch = 1,
	f_loMatchAll = 2,
	f_loCompareRDNAsStrings = 4
} TSBLookupOptions;

typedef uint8_t TSBDateLookupOptionRaw;

typedef enum
{
	dloBefore = 0,
	dloAfter = 1,
	dloBetween = 2
} TSBDateLookupOption;

typedef uint32_t TSBDateLookupOptionsRaw;

typedef enum 
{
	f_dloBefore = 1,
	f_dloAfter = 2,
	f_dloBetween = 4
} TSBDateLookupOptions;

typedef uint8_t TSBKeySizeLookupOptionRaw;

typedef enum
{
	ksloSmaller = 0,
	ksloGreater = 1,
	ksloBetween = 2
} TSBKeySizeLookupOption;

typedef uint8_t TSBKeyUsageLookupOptionRaw;

typedef enum
{
	kuloMatchAll = 0
} TSBKeyUsageLookupOption;

typedef uint32_t TSBKeyUsageLookupOptionsRaw;

typedef enum 
{
	f_kuloMatchAll = 1
} TSBKeyUsageLookupOptions;

typedef uint8_t TSBCertStorageOptionRaw;

typedef enum
{
	csoStrictChainBuilding = 0,
	csoIgnoreInvalidCertificates = 1
} TSBCertStorageOption;

typedef uint32_t TSBCertStorageOptionsRaw;

typedef enum 
{
	f_csoStrictChainBuilding = 1,
	f_csoIgnoreInvalidCertificates = 2
} TSBCertStorageOptions;

typedef void (SB_CALLBACK *TSBCertificateValidationEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Certificate, TElCustomCertStorageHandle AdditionalCertificates, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason, int8_t * DoContinue);

typedef uint8_t TSBFileCertStorageAccessTypeRaw;

typedef enum
{
	csatImmediate = 0,
	csatOnDemand = 1
} TSBFileCertStorageAccessType;

typedef uint8_t TSBFileCertStorageSaveOptionRaw;

typedef enum
{
	fcsoSaveOnDestroy = 0,
	fcsoSaveOnFilenameChange = 1,
	fcsoSaveOnChange = 2
} TSBFileCertStorageSaveOption;

typedef uint32_t TSBFileCertStorageSaveOptionsRaw;

typedef enum 
{
	f_fcsoSaveOnDestroy = 1,
	f_fcsoSaveOnFilenameChange = 2,
	f_fcsoSaveOnChange = 4
} TSBFileCertStorageSaveOptions;

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Validate(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, TSBCertificateValidityReasonRaw * Reason, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Validate_1(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, TSBCertificateValidityReasonRaw * Reason, int8_t CheckCACertDates, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Add(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Remove(TElCustomCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_ExportTo(TElCustomCertStorageHandle _Handle, TElCustomCertStorageHandle Storage);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromBufferPKCS7(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPKCS7(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromStreamPKCS7(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPKCS7(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromBufferPEM(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPEM(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPEM_1(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromStreamPEM(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPEM(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPEM_1(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromBufferJKS(TElCustomCertStorageHandle _Handle, void * Buffer, const char * pcPass, int32_t szPass, int32_t Size, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferJKS(TElCustomCertStorageHandle _Handle, void * Buffer, const char * pcPass, int32_t szPass, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferJKSEx(TElCustomCertStorageHandle _Handle, void * Buffer, const char * pcPass, int32_t szPass, int32_t * Size, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromStreamJKS(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPass, int32_t szPass, int32_t Count, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamJKS(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPass, int32_t szPass, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamJKSEx(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPass, int32_t szPass, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromBufferPFX(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPFX(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPFX_1(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromStreamPFX(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPFX(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPFX_1(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromBufferPkiPath(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToBufferPkiPath(TElCustomCertStorageHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_LoadFromStreamPkiPath(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, int32_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_SaveToStreamPkiPath(TElCustomCertStorageHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_BuildChain(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, TElX509CertificateChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_BuildChain_1(TElCustomCertStorageHandle _Handle, int32_t ChainIndex, TElX509CertificateChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_IndexOf(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_IsPresent(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Clear(TElCustomCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_FindByHash(TElCustomCertStorageHandle _Handle, const TMessageDigest160 * Digest, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_FindByHash_1(TElCustomCertStorageHandle _Handle, const TMessageDigest128 * Digest, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_GetIssuerCertificate(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_IsReadOnly(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_IsReadOnly_1(TElCustomCertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_FindFirst(TElCustomCertStorageHandle _Handle, TElCertificateLookupHandle Lookup, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_FindNext(TElCustomCertStorageHandle _Handle, TElCertificateLookupHandle Lookup, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_ImportFrom(TElCustomCertStorageHandle _Handle, TElX509CertificateChainHandle Chain);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_ImportFrom_1(TElCustomCertStorageHandle _Handle, TElX509CertificateChainHandle Chain, int8_t ImportEndEntity);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_BeginRead(TElCustomCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Contains(TElCustomCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_EndRead(TElCustomCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_Count(TElCustomCertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_ChainCount(TElCustomCertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_Certificates(TElCustomCertStorageHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_Chains(TElCustomCertStorageHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_CRL(TElCustomCertStorageHandle _Handle, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_set_CRL(TElCustomCertStorageHandle _Handle, TElCertificateRevocationListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_CryptoProviderManager(TElCustomCertStorageHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_set_CryptoProviderManager(TElCustomCertStorageHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_get_Options(TElCustomCertStorageHandle _Handle, TSBCertStorageOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_set_Options(TElCustomCertStorageHandle _Handle, TSBCertStorageOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCertStorage_Create(TComponentHandle Owner, TElCustomCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_AuthorityKeyIdentifier(TElCertificateLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_AuthorityKeyIdentifier(TElCertificateLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_SubjectKeyIdentifier(TElCertificateLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_SubjectKeyIdentifier(TElCertificateLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_SerialNumber(TElCertificateLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_SerialNumber(TElCertificateLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_PublicKeyHash(TElCertificateLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_PublicKeyHash(TElCertificateLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_CertificateHash(TElCertificateLookupHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_CertificateHash(TElCertificateLookupHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_Criteria(TElCertificateLookupHandle _Handle, TSBLookupCriteriaRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_Criteria(TElCertificateLookupHandle _Handle, TSBLookupCriteriaRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_Options(TElCertificateLookupHandle _Handle, TSBLookupOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_Options(TElCertificateLookupHandle _Handle, TSBLookupOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_IssuerRDN(TElCertificateLookupHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_SubjectRDN(TElCertificateLookupHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_ValidFrom(TElCertificateLookupHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_ValidFrom(TElCertificateLookupHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_ValidTo(TElCertificateLookupHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_ValidTo(TElCertificateLookupHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_PublicKeyAlgorithm(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_PublicKeyAlgorithm(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_SignatureAlgorithm(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_SignatureAlgorithm(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_PublicKeySizeMin(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_PublicKeySizeMin(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_PublicKeySizeMax(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_PublicKeySizeMax(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_KeyUsage(TElCertificateLookupHandle _Handle, TSBKeyUsageRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_KeyUsage(TElCertificateLookupHandle _Handle, TSBKeyUsageRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_EmailAddresses(TElCertificateLookupHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_PublicKeyHashAlgorithm(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_PublicKeyHashAlgorithm(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_CertificateHashAlgorithm(TElCertificateLookupHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_CertificateHashAlgorithm(TElCertificateLookupHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_DateLookupOptions(TElCertificateLookupHandle _Handle, TSBDateLookupOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_DateLookupOptions(TElCertificateLookupHandle _Handle, TSBDateLookupOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_KeySizeLookupOption(TElCertificateLookupHandle _Handle, TSBKeySizeLookupOptionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_KeySizeLookupOption(TElCertificateLookupHandle _Handle, TSBKeySizeLookupOptionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_get_KeyUsageLookupOptions(TElCertificateLookupHandle _Handle, TSBKeyUsageLookupOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_set_KeyUsageLookupOptions(TElCertificateLookupHandle _Handle, TSBKeyUsageLookupOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateLookup_Create(TComponentHandle AOwner, TElCertificateLookupHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCertStorage_Add(TElMemoryCertStorageHandle _Handle, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCertStorage_Remove(TElMemoryCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCertStorage_get_CertificateList(TElMemoryCertStorageHandle _Handle, TSBObjectListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryCertStorage_Create(TComponentHandle Owner, TElMemoryCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELFILECERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Validate(TElFileCertStorageHandle _Handle, TElX509CertificateHandle Certificate, TSBCertificateValidityReasonRaw * Reason, int8_t CheckCACertDates, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Add(TElFileCertStorageHandle _Handle, TElX509CertificateHandle X509Certificate, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Remove(TElFileCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Clear(TElFileCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_SaveToFile(TElFileCertStorageHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Reload(TElFileCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Save(TElFileCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_get_FileName(TElFileCertStorageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_set_FileName(TElFileCertStorageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_get_AccessType(TElFileCertStorageHandle _Handle, TSBFileCertStorageAccessTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_set_AccessType(TElFileCertStorageHandle _Handle, TSBFileCertStorageAccessTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_get_SaveOptions(TElFileCertStorageHandle _Handle, TSBFileCertStorageSaveOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_set_SaveOptions(TElFileCertStorageHandle _Handle, TSBFileCertStorageSaveOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileCertStorage_Create(TComponentHandle Owner, TElFileCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILECERTSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomCertStorage;
typedef TElCustomCertStorage ElCustomCertStorage;
class TElCertificateLookup;
typedef TElCertificateLookup ElCertificateLookup;
class TElMemoryCertStorage;
typedef TElMemoryCertStorage ElMemoryCertStorage;
class TElFileCertStorage;
typedef TElFileCertStorage ElFileCertStorage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBLookupCriteria)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBLookupOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBDateLookupOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBKeyUsageLookupOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCertStorageOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBFileCertStorageSaveOptions)

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
class TElCustomCertStorage: public TElBaseCertStorage
{
	private:
		SB_DISABLE_COPY(TElCustomCertStorage)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		TElCertificateRevocationList* _Inst_CRL;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TSBCertificateValidity Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, int64_t ValidityMoment);

		virtual TSBCertificateValidity Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, int64_t ValidityMoment);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TSBCertificateValidity Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);

		virtual TSBCertificateValidity Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Remove(int32_t Index);

		virtual void ExportTo(TElCustomCertStorage &Storage);

		virtual void ExportTo(TElCustomCertStorage *Storage);

		int32_t LoadFromBufferPKCS7(void * Buffer, int32_t Size);

		bool SaveToBufferPKCS7(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPKCS7(TStream &Stream, int32_t Count);

		int32_t LoadFromStreamPKCS7(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamPKCS7(TStream &Stream);

		bool SaveToStreamPKCS7(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &Password);

		bool SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Password);

		bool SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPEM(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadFromStreamPEM(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamPEM(TStream &Stream, const std::string &Password);

		bool SaveToStreamPEM(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamPEM(TStream &Stream, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode);

		bool SaveToStreamPEM(TStream *Stream, const std::string &Password, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode);
#endif /* SB_USE_CLASS_TSTREAM */

		bool LoadFromBufferJKS(void * Buffer, const std::string &Pass, int32_t Size, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded);

		bool SaveToBufferJKS(void * Buffer, const std::string &Pass, int32_t &Size);

		bool SaveToBufferJKSEx(void * Buffer, const std::string &Pass, int32_t &Size, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded);

#ifdef SB_USE_CLASS_TSTREAM
		bool LoadFromStreamJKS(TStream &Stream, const std::string &Pass, int32_t Count, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded);

		bool LoadFromStreamJKS(TStream *Stream, const std::string &Pass, int32_t Count, TElJKSPasswordEvent pMethodOnPasswordNeeded, void * pDataOnPasswordNeeded);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamJKS(TStream &Stream, const std::string &Pass);

		bool SaveToStreamJKS(TStream *Stream, const std::string &Pass);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamJKSEx(TStream &Stream, const std::string &Pass, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded);

		bool SaveToStreamJKSEx(TStream *Stream, const std::string &Pass, TElJKSAliasNeededEvent pMethodOnAliasNeeded, void * pDataOnAliasNeeded);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t LoadFromBufferPFX(void * Buffer, int32_t Size, const std::string &Password);

		int32_t SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);

		int32_t SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPFX(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadFromStreamPFX(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStreamPFX(TStream &Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);

		int32_t SaveToStreamPFX(TStream *Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStreamPFX(TStream &Stream, const std::string &Password);

		int32_t SaveToStreamPFX(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

		bool LoadFromBufferPkiPath(void * Buffer, int32_t Size);

		bool SaveToBufferPkiPath(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		bool LoadFromStreamPkiPath(TStream &Stream, int32_t Count);

		bool LoadFromStreamPkiPath(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStreamPkiPath(TStream &Stream);

		bool SaveToStreamPkiPath(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATECHAIN
		TElX509CertificateChainHandle BuildChain(TElX509Certificate &Certificate);

		TElX509CertificateChainHandle BuildChain(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASSES_TELX509CERTIFICATE_AND_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
		TElX509CertificateChainHandle BuildChain(int32_t ChainIndex);
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual int32_t IndexOf(TElX509Certificate &Certificate);

		virtual int32_t IndexOf(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool IsPresent(TElX509Certificate &Certificate);

		bool IsPresent(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Clear();

		int32_t FindByHash(const TMessageDigest160 &Digest);

		int32_t FindByHash(const TMessageDigest128 &Digest);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual int32_t GetIssuerCertificate(TElX509Certificate &Certificate);

		virtual int32_t GetIssuerCertificate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		static bool IsReadOnly();

		virtual bool IsReadOnly_Inst();

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
		int32_t FindFirst(TElCertificateLookup &Lookup);

		int32_t FindFirst(TElCertificateLookup *Lookup);
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
		int32_t FindNext(TElCertificateLookup &Lookup);

		int32_t FindNext(TElCertificateLookup *Lookup);
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
		virtual void ImportFrom(TElX509CertificateChain &Chain);

		virtual void ImportFrom(TElX509CertificateChain *Chain);
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
		virtual void ImportFrom(TElX509CertificateChain &Chain, bool ImportEndEntity);

		virtual void ImportFrom(TElX509CertificateChain *Chain, bool ImportEndEntity);
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

		void BeginRead();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool Contains(TElX509Certificate &Certificate);

		bool Contains(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void EndRead();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomCertStorage, Count);

		virtual int32_t get_ChainCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ChainCount, TElCustomCertStorage, ChainCount);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual int32_t get_Chains(int32_t Index);

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual TElCertificateRevocationList* get_CRL();

		virtual void set_CRL(TElCertificateRevocationList &Value);

		virtual void set_CRL(TElCertificateRevocationList *Value);

		SB_DECLARE_PROPERTY(TElCertificateRevocationList*, get_CRL, set_CRL, TElCustomCertStorage, CRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElCustomCertStorage, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual TSBCertStorageOptions get_Options();

		virtual void set_Options(TSBCertStorageOptions Value);

		SB_DECLARE_PROPERTY(TSBCertStorageOptions, get_Options, set_Options, TElCustomCertStorage, Options);

		TElCustomCertStorage(TElCustomCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomCertStorage(TComponent &Owner);

		explicit TElCustomCertStorage(TComponent *Owner);

		virtual ~TElCustomCertStorage();

};
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCERTIFICATELOOKUP
class TElCertificateLookup: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCertificateLookup)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_SubjectRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_EmailAddresses;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void get_AuthorityKeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_AuthorityKeyIdentifier(const std::vector<uint8_t> &Value);

		virtual void get_SubjectKeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_SubjectKeyIdentifier(const std::vector<uint8_t> &Value);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual void get_PublicKeyHash(std::vector<uint8_t> &OutResult);

		virtual void set_PublicKeyHash(const std::vector<uint8_t> &Value);

		virtual void get_CertificateHash(std::vector<uint8_t> &OutResult);

		virtual void set_CertificateHash(const std::vector<uint8_t> &Value);

		virtual TSBLookupCriteria get_Criteria();

		virtual void set_Criteria(TSBLookupCriteria Value);

		SB_DECLARE_PROPERTY(TSBLookupCriteria, get_Criteria, set_Criteria, TElCertificateLookup, Criteria);

		virtual TSBLookupOptions get_Options();

		virtual void set_Options(TSBLookupOptions Value);

		SB_DECLARE_PROPERTY(TSBLookupOptions, get_Options, set_Options, TElCertificateLookup, Options);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_IssuerRDN, TElCertificateLookup, IssuerRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_SubjectRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_SubjectRDN, TElCertificateLookup, SubjectRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int64_t get_ValidFrom();

		virtual void set_ValidFrom(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidFrom, set_ValidFrom, TElCertificateLookup, ValidFrom);

		virtual int64_t get_ValidTo();

		virtual void set_ValidTo(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidTo, set_ValidTo, TElCertificateLookup, ValidTo);

		virtual int32_t get_PublicKeyAlgorithm();

		virtual void set_PublicKeyAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PublicKeyAlgorithm, set_PublicKeyAlgorithm, TElCertificateLookup, PublicKeyAlgorithm);

		virtual int32_t get_SignatureAlgorithm();

		virtual void set_SignatureAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SignatureAlgorithm, set_SignatureAlgorithm, TElCertificateLookup, SignatureAlgorithm);

		virtual int32_t get_PublicKeySizeMin();

		virtual void set_PublicKeySizeMin(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PublicKeySizeMin, set_PublicKeySizeMin, TElCertificateLookup, PublicKeySizeMin);

		virtual int32_t get_PublicKeySizeMax();

		virtual void set_PublicKeySizeMax(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PublicKeySizeMax, set_PublicKeySizeMax, TElCertificateLookup, PublicKeySizeMax);

		virtual TSBKeyUsage get_KeyUsage();

		virtual void set_KeyUsage(TSBKeyUsage Value);

		SB_DECLARE_PROPERTY(TSBKeyUsage, get_KeyUsage, set_KeyUsage, TElCertificateLookup, KeyUsage);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_EmailAddresses();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_EmailAddresses, TElCertificateLookup, EmailAddresses);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual int32_t get_PublicKeyHashAlgorithm();

		virtual void set_PublicKeyHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PublicKeyHashAlgorithm, set_PublicKeyHashAlgorithm, TElCertificateLookup, PublicKeyHashAlgorithm);

		virtual int32_t get_CertificateHashAlgorithm();

		virtual void set_CertificateHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CertificateHashAlgorithm, set_CertificateHashAlgorithm, TElCertificateLookup, CertificateHashAlgorithm);

		virtual TSBDateLookupOptions get_DateLookupOptions();

		virtual void set_DateLookupOptions(TSBDateLookupOptions Value);

		SB_DECLARE_PROPERTY(TSBDateLookupOptions, get_DateLookupOptions, set_DateLookupOptions, TElCertificateLookup, DateLookupOptions);

		virtual TSBKeySizeLookupOption get_KeySizeLookupOption();

		virtual void set_KeySizeLookupOption(TSBKeySizeLookupOption Value);

		SB_DECLARE_PROPERTY(TSBKeySizeLookupOption, get_KeySizeLookupOption, set_KeySizeLookupOption, TElCertificateLookup, KeySizeLookupOption);

		virtual TSBKeyUsageLookupOptions get_KeyUsageLookupOptions();

		virtual void set_KeyUsageLookupOptions(TSBKeyUsageLookupOptions Value);

		SB_DECLARE_PROPERTY(TSBKeyUsageLookupOptions, get_KeyUsageLookupOptions, set_KeyUsageLookupOptions, TElCertificateLookup, KeyUsageLookupOptions);

		TElCertificateLookup(TElCertificateLookupHandle handle, TElOwnHandle ownHandle);

		explicit TElCertificateLookup(TComponent &AOwner);

		explicit TElCertificateLookup(TComponent *AOwner);

		virtual ~TElCertificateLookup();

};
#endif /* SB_USE_CLASS_TELCERTIFICATELOOKUP */

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
class TElMemoryCertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElMemoryCertStorage)
#ifdef SB_USE_CLASS_TSBOBJECTLIST
		TSBObjectList* _Inst_CertificateList;
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TSBOBJECTLIST
		virtual TSBObjectList* get_CertificateList();

		SB_DECLARE_PROPERTY_GET(TSBObjectList*, get_CertificateList, TElMemoryCertStorage, CertificateList);
#endif /* SB_USE_CLASS_TSBOBJECTLIST */

		TElMemoryCertStorage(TElMemoryCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElMemoryCertStorage(TComponent &Owner);

		explicit TElMemoryCertStorage(TComponent *Owner);

		virtual ~TElMemoryCertStorage();

};
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELFILECERTSTORAGE
class TElFileCertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElFileCertStorage)
	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TSBCertificateValidity Validate(TElX509Certificate &Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);

		virtual TSBCertificateValidity Validate(TElX509Certificate *Certificate, TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &X509Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *X509Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Remove(int32_t Index);

		virtual void Clear();

		void SaveToFile(const std::string &FileName);

		void Reload();

		void Save();

		virtual void get_FileName(std::string &OutResult);

		virtual void set_FileName(const std::string &Value);

		virtual TSBFileCertStorageAccessType get_AccessType();

		virtual void set_AccessType(TSBFileCertStorageAccessType Value);

		SB_DECLARE_PROPERTY(TSBFileCertStorageAccessType, get_AccessType, set_AccessType, TElFileCertStorage, AccessType);

		virtual TSBFileCertStorageSaveOptions get_SaveOptions();

		virtual void set_SaveOptions(TSBFileCertStorageSaveOptions Value);

		SB_DECLARE_PROPERTY(TSBFileCertStorageSaveOptions, get_SaveOptions, set_SaveOptions, TElFileCertStorage, SaveOptions);

		TElFileCertStorage(TElFileCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElFileCertStorage(TComponent &Owner);

		explicit TElFileCertStorage(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELFILECERTSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCUSTOMCERTSTORAGE */

