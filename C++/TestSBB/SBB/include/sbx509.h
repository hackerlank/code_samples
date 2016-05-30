#ifndef __INC_SBX509
#define __INC_SBX509

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifdef SB_WINDOWS
#include "sbwincrypt.h"
#endif
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbmd.h"
#include "sbsha.h"
#include "sbmath.h"
#include "sbrdn.h"
#include "sbasn1.h"
#include "sbpem.h"
#include "sbhashfunction.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbpkiasync.h"
#include "sbx509ext.h"
#include "sbcustomcrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbpublickeycrypto.h"
#include "sbalgorithmidentifier.h"
#include "sbcryptoprov.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_X509 	20480
#define SB_X509_ERROR_INVALID_PVK_FILE 	20481
#define SB_X509_ERROR_INVALID_PASSWORD 	20482
#define SB_X509_ERROR_NO_PRIVATE_KEY 	20483
#define SB_X509_ERROR_UNSUPPORTED_ALGORITHM 	20484
#define SB_X509_ERROR_INVALID_PRIVATE_KEY 	20485
#define SB_X509_ERROR_INTERNAL_ERROR 	20486
#define SB_X509_ERROR_BUFFER_TOO_SMALL 	20487
#define SB_X509_ERROR_NO_CERTIFICATE 	20488
#define SB_X509_ERROR_UNRECOGNIZED_FORMAT 	20489
#define SB_X509_ERROR_EMPTY_ISSUER 	20490
#define SB_X509_ERROR_EMPTY_SUBJECT 	20491
#define SB_X509_ERROR_BLOB_SIZE_TOO_SMALL 	20492
#define SB_X509_ERROR_INVALID_TBS_CERTIFICATE 	20493
#define SB_X509_ERROR_CERTIFICATE_TOO_LONG 	20494
#define SB_X509_ERROR_INVALID_KEY_MATERIAL 	20495
#define SB_X509_ERROR_INVALID_PUBKEY_PARAMS 	20496
#define SB_X509_ERROR_CANT_SET_FRIENDLY_NAME 	20497
#define SB_X509_ERROR_UNSUPPORTED_KEY_TYPE 	20498
#define SB_X509_ERROR_FAILED_TO_CLONE_CONTEXT 	20499
#define SB_BT_WINDOWS 	1
#define SB_BT_PKCS11 	2
#define SB_BT_WAB 	4
#define SB_BT_OUTLOOK 	8
#define SB_BT_FILE 	16
#define SB_BT_APPLE 	32

typedef TElClassHandle TElSubjectPublicKeyInfoHandle;

typedef TElSubjectPublicKeyInfoHandle ElSubjectPublicKeyInfoHandle;

typedef TElClassHandle TElTBSCertificateHandle;

typedef TElTBSCertificateHandle ElTBSCertificateHandle;

typedef TElClassHandle TElX509CertificateChainHandle;

typedef TElX509CertificateChainHandle ElX509CertificateChainHandle;

typedef TElClassHandle TElX509CertificateHandle;

typedef TElX509CertificateHandle ElX509CertificateHandle;

typedef TElClassHandle TElBaseCertStorageHandle;

typedef TElBaseCertStorageHandle ElBaseCertStorageHandle;

typedef uint8_t TSBCertificateValidityRaw;

typedef enum
{
	cvOk = 0,
	cvSelfSigned = 1,
	cvInvalid = 2,
	cvStorageError = 3,
	cvChainUnvalidated = 4
} TSBCertificateValidity;

typedef uint32_t TSBCertificateValidityReasonRaw;

typedef enum 
{
	f_vrBadData = 1,
	f_vrRevoked = 2,
	f_vrNotYetValid = 4,
	f_vrExpired = 8,
	f_vrInvalidSignature = 16,
	f_vrUnknownCA = 32,
	f_vrCAUnauthorized = 64,
	f_vrCRLNotVerified = 128,
	f_vrOCSPNotVerified = 256,
	f_vrIdentityMismatch = 512,
	f_vrNoKeyUsage = 1024,
	f_vrBlocked = 2048
} TSBCertificateValidityReason;

typedef uint8_t TSBCertFileFormatRaw;

typedef enum
{
	cfUnknown = 0,
	cfDER = 1,
	cfPEM = 2,
	cfPFX = 3,
	cfSPC = 4
} TSBCertFileFormat;

typedef uint8_t TSBX509KeyFileFormatRaw;

typedef enum
{
	kffUnknown = 0,
	kffDER = 1,
	kffPEM = 2,
	kffPFX = 3,
	kffPVK = 4,
	kffNET = 5,
	kffPKCS8 = 6
} TSBX509KeyFileFormat;

#pragma pack(4)
typedef struct 
{
	double NotBefore;
	double NotAfter;
} TValidity;

#pragma pack(4)
typedef struct 
{
	void * Country;
	void * StateOrProvince;
	void * Locality;
	void * Organization;
	void * OrganizationUnit;
	void * CommonName;
	void * EMailAddress;
} TName;

typedef uint8_t TSBCertSecurityLevelRaw;

typedef enum
{
	cslLow = 0,
	cslMedium = 1,
	cslHigh = 2
} TSBCertSecurityLevel;

typedef TElClassHandle TElX509CertificateClassHandle;

typedef TElX509CertificateClassHandle ElX509CertificateClassHandle;

#pragma pack(1)
typedef struct 
{
	uint32_t magic;
	uint32_t reserved;
	uint32_t keytype;
	uint32_t encrypted;
	uint32_t saltlen;
	uint32_t keylen;
} TPVKHeader;

#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
SB_IMPORT uint32_t SB_APIENTRY TElSubjectPublicKeyInfo_Clear(TElSubjectPublicKeyInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectPublicKeyInfo_get_PublicKeyAlgorithmIdentifier(TElSubjectPublicKeyInfoHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectPublicKeyInfo_get_PublicKeyAlgorithm(TElSubjectPublicKeyInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectPublicKeyInfo_get_RawData(TElSubjectPublicKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectPublicKeyInfo_Create(TElSubjectPublicKeyInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELTBSCERTIFICATE
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_Clear(TElTBSCertificateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_Version(TElTBSCertificateHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_set_Version(TElTBSCertificateHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_SerialNumber(TElTBSCertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_set_SerialNumber(TElTBSCertificateHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_SignatureIdentifier(TElTBSCertificateHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_Issuer(TElTBSCertificateHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_Subject(TElTBSCertificateHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_SubjectPublicKeyInfo(TElTBSCertificateHandle _Handle, TElSubjectPublicKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_IssuerUniqueID(TElTBSCertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_set_IssuerUniqueID(TElTBSCertificateHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_SubjectUniqueID(TElTBSCertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_set_SubjectUniqueID(TElTBSCertificateHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_get_Validity(TElTBSCertificateHandle _Handle, TValidity * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_set_Validity(TElTBSCertificateHandle _Handle, TValidity * Value);
SB_IMPORT uint32_t SB_APIENTRY TElTBSCertificate_Create(TElTBSCertificateHandle * OutResult);
#endif /* SB_USE_CLASS_TELTBSCERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_Add(TElX509CertificateChainHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_Validate(TElX509CertificateChainHandle _Handle, TSBCertificateValidityReasonRaw * Reason, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_Validate_1(TElX509CertificateChainHandle _Handle, TSBCertificateValidityReasonRaw * Reason, int8_t CheckCACertDates, int64_t ValidityMoment, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_get_Certificates(TElX509CertificateChainHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_get_Complete(TElX509CertificateChainHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_get_Count(TElX509CertificateChainHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateChain_Create(TComponentHandle Owner, TElX509CertificateChainHandle * OutResult);
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat(const char * pcFileName, int32_t szFileName, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat_1(TElX509CertificateHandle _Handle, const char * pcFileName, int32_t szFileName, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat_2(TStreamHandle Stream, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat_3(TElX509CertificateHandle _Handle, TStreamHandle Stream, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat_4(void * Buffer, int32_t Size, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectCertFileFormat_5(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, TSBCertFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat(TStreamHandle Stream, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat_1(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat_2(const char * pcFileName, int32_t szFileName, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat_3(TElX509CertificateHandle _Handle, const char * pcFileName, int32_t szFileName, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat_4(void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_DetectKeyFileFormat_5(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_Equals(TElX509CertificateHandle _Handle, TElX509CertificateHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SameCertificate(TElX509CertificateHandle _Handle, TElX509CertificateHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_Clone(TElX509CertificateHandle _Handle, TElX509CertificateHandle Dest, int8_t CopyPrivateKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_Clone_1(TElX509CertificateHandle _Handle, TElX509CertificateHandle Dest, TElCustomCryptoProviderHandle CryptoProvider);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_ChangeSecurityLevel(TElX509CertificateHandle _Handle, TSBCertSecurityLevelRaw Level, const char * pcPassword, int32_t szPassword);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_KeyCorresponds(TElX509CertificateHandle _Handle, void * KeyBuffer, int32_t KeySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromBuffer(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromBufferPEM(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassPhrase, int32_t szPassPhrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBuffer(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferPEM(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassPhrase, int32_t szPassPhrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromBufferPFX(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromBufferSPC(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferMS(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferPKCS8(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromBufferAuto(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferAuto(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferNET(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferPVK(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromBufferPKCS15(TElX509CertificateHandle _Handle, void * Buffer, int32_t Size, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamPKCS15(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromStream(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStream(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamPEM(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassPhrase, int32_t szPassPhrase, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromStreamPEM(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassPhrase, int32_t szPassPhrase, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromStreamPFX(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromStreamSPC(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamMS(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamPKCS8(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamPVK(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromStreamAuto(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamAuto(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromStreamNET(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadFromFileAuto(TElX509CertificateHandle _Handle, const char * pcFilename, int32_t szFilename, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_LoadKeyFromFileAuto(TElX509CertificateHandle _Handle, const char * pcFilename, int32_t szFilename, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToBuffer(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBuffer(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToBufferPEM(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferPEM(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferPEM_1(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, const char * pcPassPhrase, int32_t szPassPhrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToBufferPFX(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToBufferPFX_1(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToBufferSPC(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferMS(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferNET(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferPVK(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int8_t UseStrongEncryption, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToBufferPKCS8(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToStream(TElX509CertificateHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStream(TElX509CertificateHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToStreamPEM(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassPhrase, int32_t szPassPhrase);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamPEM(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassPhrase, int32_t szPassPhrase);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamPEM_1(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, const char * pcPassPhrase, int32_t szPassPhrase);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToStreamPFX(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToStreamPFX_1(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToStreamSPC(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyValueToBuffer(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamMS(TElX509CertificateHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamNET(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamPVK(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int8_t UseStrongEncryption, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToStreamPKCS8(TElX509CertificateHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveToFile(TElX509CertificateHandle _Handle, const char * pcFilename, int32_t szFilename, const char * pcPassword, int32_t szPassword, TSBCertFileFormatRaw Format, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SaveKeyToFile(TElX509CertificateHandle _Handle, const char * pcFilename, int32_t szFilename, const char * pcPassword, int32_t szPassword, TSBX509KeyFileFormatRaw Format, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_Validate(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_ValidateWithCA(TElX509CertificateHandle _Handle, TElX509CertificateHandle CACertificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetRSAParams(TElX509CertificateHandle _Handle, void * RSAModulus, int32_t * RSAModulusSize, void * RSAPublicKey, int32_t * RSAPublicKeySize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetDSSParams(TElX509CertificateHandle _Handle, void * DSSP, int32_t * DSSPSize, void * DSSQ, int32_t * DSSQSize, void * DSSG, int32_t * DSSGSize, void * DSSY, int32_t * DSSYSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetDHParams(TElX509CertificateHandle _Handle, void * DHP, int32_t * DHPSize, void * DHG, int32_t * DHGSize, void * DHY, int32_t * DHYSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetPublicKeyBlob(TElX509CertificateHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetPublicKeyBlob_1(TElX509CertificateHandle _Handle, uint8_t pBuffer[], int32_t * szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetFullPublicKeyInfo(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetHashMD5(TElX509CertificateHandle _Handle, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetHashSHA1(TElX509CertificateHandle _Handle, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetKeyHashSHA1(TElX509CertificateHandle _Handle, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetCertificateHash(TElX509CertificateHandle _Handle, int32_t Alg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetZIPCertIdentifier(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_GetPublicKeySize(TElX509CertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_IsKeyValid(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_WriteSerialNumber(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_WriteExtensionSubjectKeyIdentifier(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_WriteSubject(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_WriteIssuer(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_SetKeyMaterial(TElX509CertificateHandle _Handle, TElPublicKeyMaterialHandle Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_View(TElX509CertificateHandle _Handle, uint32_t Owner, int8_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CertificateBinary(TElX509CertificateHandle _Handle, PByteArray * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CertificateSize(TElX509CertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SignatureAlgorithm(TElX509CertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SignatureAlgorithmIdentifier(TElX509CertificateHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_Signature(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_Version(TElX509CertificateHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_Version(TElX509CertificateHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SerialNumber(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_SerialNumber(TElX509CertificateHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_ValidFrom(TElX509CertificateHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_ValidFrom(TElX509CertificateHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_ValidTo(TElX509CertificateHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_ValidTo(TElX509CertificateHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_BelongsTo(TElX509CertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_BelongsTo(TElX509CertificateHandle _Handle, int32_t Value);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CertHandle(TElX509CertificateHandle _Handle, PCCERT_CONTEXT * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_CertHandle(TElX509CertificateHandle _Handle, PCCERT_CONTEXT Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_FriendlyName(TElX509CertificateHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_FriendlyName(TElX509CertificateHandle _Handle, const char * pcValue, int32_t szValue);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_IssuerUniqueID(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SubjectUniqueID(TElX509CertificateHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_PublicKeyAlgorithm(TElX509CertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_PublicKeyAlgorithmIdentifier(TElX509CertificateHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_PrivateKeyExists(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_PrivateKeyExtractable(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CAAvailable(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_CAAvailable(TElX509CertificateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SelfSigned(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_IssuerName(TElX509CertificateHandle _Handle, TName * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SubjectName(TElX509CertificateHandle _Handle, TName * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_IssuerRDN(TElX509CertificateHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_SubjectRDN(TElX509CertificateHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_Extensions(TElX509CertificateHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CertStorage(TElX509CertificateHandle _Handle, TElBaseCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_CertStorage(TElX509CertificateHandle _Handle, TElBaseCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_StorageName(TElX509CertificateHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_StorageName(TElX509CertificateHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CanEncrypt(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CanSign(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_StrictMode(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_StrictMode(TElX509CertificateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_UseUTF8(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_UseUTF8(TElX509CertificateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_Chain(TElX509CertificateHandle _Handle, TElX509CertificateChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_Chain(TElX509CertificateHandle _Handle, TElX509CertificateChainHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_KeyMaterial(TElX509CertificateHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_NegativeSerial(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_ReportErrorOnPartialLoad(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_ReportErrorOnPartialLoad(TElX509CertificateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CryptoProvider(TElX509CertificateHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_CryptoProvider(TElX509CertificateHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_CryptoProviderManager(TElX509CertificateHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_CryptoProviderManager(TElX509CertificateHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_get_IgnoreVersion(TElX509CertificateHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_set_IgnoreVersion(TElX509CertificateHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509Certificate_Create(TComponentHandle Owner, TElX509CertificateHandle * OutResult);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElBaseCertStorage_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSubjectPublicKeyInfo;
typedef TElSubjectPublicKeyInfo ElSubjectPublicKeyInfo;
class TElTBSCertificate;
typedef TElTBSCertificate ElTBSCertificate;
class TElX509CertificateChain;
typedef TElX509CertificateChain ElX509CertificateChain;
class TElX509Certificate;
typedef TElX509Certificate ElX509Certificate;
class TElBaseCertStorage;
typedef TElBaseCertStorage ElBaseCertStorage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCertificateValidityReason)

#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
class TElSubjectPublicKeyInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElSubjectPublicKeyInfo)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_PublicKeyAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_PublicKeyAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_PublicKeyAlgorithmIdentifier, TElSubjectPublicKeyInfo, PublicKeyAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual int32_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyAlgorithm, TElSubjectPublicKeyInfo, PublicKeyAlgorithm);

		virtual void get_RawData(std::vector<uint8_t> &OutResult);

		TElSubjectPublicKeyInfo(TElSubjectPublicKeyInfoHandle handle, TElOwnHandle ownHandle);

		TElSubjectPublicKeyInfo();

		virtual ~TElSubjectPublicKeyInfo();

};
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

#ifdef SB_USE_CLASS_TELTBSCERTIFICATE
class TElTBSCertificate: public TObject
{
	private:
		SB_DISABLE_COPY(TElTBSCertificate)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_SignatureIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Issuer;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Subject;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
		TElSubjectPublicKeyInfo* _Inst_SubjectPublicKeyInfo;
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

		void initInstances();

	public:
		void Clear();

		virtual uint8_t get_Version();

		virtual void set_Version(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Version, set_Version, TElTBSCertificate, Version);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_SignatureIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_SignatureIdentifier, TElTBSCertificate, SignatureIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Issuer, TElTBSCertificate, Issuer);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Subject();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Subject, TElTBSCertificate, Subject);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO
		virtual TElSubjectPublicKeyInfo* get_SubjectPublicKeyInfo();

		SB_DECLARE_PROPERTY_GET(TElSubjectPublicKeyInfo*, get_SubjectPublicKeyInfo, TElTBSCertificate, SubjectPublicKeyInfo);
#endif /* SB_USE_CLASS_TELSUBJECTPUBLICKEYINFO */

		virtual void get_IssuerUniqueID(std::vector<uint8_t> &OutResult);

		virtual void set_IssuerUniqueID(const std::vector<uint8_t> &Value);

		virtual void get_SubjectUniqueID(std::vector<uint8_t> &OutResult);

		virtual void set_SubjectUniqueID(const std::vector<uint8_t> &Value);

		virtual void get_Validity(TValidity &OutResult);

		virtual void set_Validity(TValidity &Value);

		TElTBSCertificate(TElTBSCertificateHandle handle, TElOwnHandle ownHandle);

		TElTBSCertificate();

		virtual ~TElTBSCertificate();

};
#endif /* SB_USE_CLASS_TELTBSCERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
class TElX509CertificateChain: public TComponent
{
	private:
		SB_DISABLE_COPY(TElX509CertificateChain)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool Add(TElX509Certificate &Certificate);

		bool Add(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		TSBCertificateValidity Validate(TSBCertificateValidityReason &Reason, int64_t ValidityMoment);

		TSBCertificateValidity Validate(TSBCertificateValidityReason &Reason, bool CheckCACertDates, int64_t ValidityMoment);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual bool get_Complete();

		SB_DECLARE_PROPERTY_GET(bool, get_Complete, TElX509CertificateChain, Complete);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElX509CertificateChain, Count);

		TElX509CertificateChain(TElX509CertificateChainHandle handle, TElOwnHandle ownHandle);

		explicit TElX509CertificateChain(TComponent &Owner);

		explicit TElX509CertificateChain(TComponent *Owner);

		virtual ~TElX509CertificateChain();

};
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
class TElX509Certificate: public TComponent
{
	private:
		SB_DISABLE_COPY(TElX509Certificate)
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_SignatureAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_PublicKeyAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_SubjectRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
		TElBaseCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */
#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
		TElX509CertificateChain* _Inst_Chain;
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		static TSBCertFileFormat DetectCertFileFormat(const std::string &FileName);

		TSBCertFileFormat DetectCertFileFormat_Inst(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		static TSBCertFileFormat DetectCertFileFormat(TStream &Stream);

		static TSBCertFileFormat DetectCertFileFormat(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TSBCertFileFormat DetectCertFileFormat_Inst(TStream &Stream);

		TSBCertFileFormat DetectCertFileFormat_Inst(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		static TSBCertFileFormat DetectCertFileFormat(void * Buffer, int32_t Size);

		TSBCertFileFormat DetectCertFileFormat_Inst(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		static TSBX509KeyFileFormat DetectKeyFileFormat(TStream &Stream, const std::string &Password);

		static TSBX509KeyFileFormat DetectKeyFileFormat(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TSBX509KeyFileFormat DetectKeyFileFormat_Inst(TStream &Stream, const std::string &Password);

		TSBX509KeyFileFormat DetectKeyFileFormat_Inst(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

		static TSBX509KeyFileFormat DetectKeyFileFormat(const std::string &FileName, const std::string &Password);

		TSBX509KeyFileFormat DetectKeyFileFormat_Inst(const std::string &FileName, const std::string &Password);

		static TSBX509KeyFileFormat DetectKeyFileFormat(void * Buffer, int32_t Size, const std::string &Password);

		TSBX509KeyFileFormat DetectKeyFileFormat_Inst(void * Buffer, int32_t Size, const std::string &Password);

		bool Equals(TElX509Certificate &Other);

		bool Equals(TElX509Certificate *Other);

		bool SameCertificate(TElX509Certificate &Other);

		bool SameCertificate(TElX509Certificate *Other);

		void Clone(TElX509Certificate &Dest, bool CopyPrivateKey);

		void Clone(TElX509Certificate *Dest, bool CopyPrivateKey);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		void Clone(TElX509Certificate &Dest, TElCustomCryptoProvider &CryptoProvider);

		void Clone(TElX509Certificate *Dest, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_WINDOWS
		void ChangeSecurityLevel(TSBCertSecurityLevel Level, const std::string &Password);
#endif

		bool KeyCorresponds(void * KeyBuffer, int32_t KeySize);

		void LoadFromBuffer(void * Buffer, int32_t Size);

		int32_t LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &PassPhrase);

		void LoadKeyFromBuffer(void * Buffer, int32_t Size);

		int32_t LoadKeyFromBufferPEM(void * Buffer, int32_t Size, const std::string &PassPhrase);

		int32_t LoadFromBufferPFX(void * Buffer, int32_t Size, const std::string &Password);

		int32_t LoadFromBufferSPC(void * Buffer, int32_t Size);

		int32_t LoadKeyFromBufferMS(void * Buffer, int32_t Size);

		int32_t LoadKeyFromBufferPKCS8(void * Buffer, int32_t Size, const std::string &Password);

		int32_t LoadFromBufferAuto(void * Buffer, int32_t Size, const std::string &Password);

		int32_t LoadKeyFromBufferAuto(void * Buffer, int32_t Size, const std::string &Password);

		int32_t LoadKeyFromBufferNET(void * Buffer, int32_t Size, const std::string &Password);

		int32_t LoadKeyFromBufferPVK(void * Buffer, int32_t Size, const std::string &Password);

		void LoadKeyFromBufferPKCS15(void * Buffer, int32_t Size, const std::string &Password);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadKeyFromStreamPKCS15(TStream &Stream, const std::string &Password, int32_t Count);

		void LoadKeyFromStreamPKCS15(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream, int32_t Count);

		void LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadKeyFromStream(TStream &Stream, int32_t Count);

		void LoadKeyFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamPEM(TStream &Stream, const std::string &PassPhrase, int32_t Count);

		int32_t LoadKeyFromStreamPEM(TStream *Stream, const std::string &PassPhrase, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPEM(TStream &Stream, const std::string &PassPhrase, int32_t Count);

		int32_t LoadFromStreamPEM(TStream *Stream, const std::string &PassPhrase, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPFX(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadFromStreamPFX(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamSPC(TStream &Stream, int32_t Count);

		int32_t LoadFromStreamSPC(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamMS(TStream &Stream, int32_t Count);

		int32_t LoadKeyFromStreamMS(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamPKCS8(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadKeyFromStreamPKCS8(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamPVK(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadKeyFromStreamPVK(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamAuto(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadFromStreamAuto(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamAuto(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadKeyFromStreamAuto(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamNET(TStream &Stream, const std::string &Password, int32_t Count);

		int32_t LoadKeyFromStreamNET(TStream *Stream, const std::string &Password, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t LoadFromFileAuto(const std::string &Filename, const std::string &Password);

		int32_t LoadKeyFromFileAuto(const std::string &Filename, const std::string &Password);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

		bool SaveKeyToBuffer(void * Buffer, int32_t &Size);

		bool SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &PassPhrase);

		bool SaveKeyToBufferPEM(void * Buffer, int32_t &Size, const std::string &PassPhrase);

		bool SaveKeyToBufferPEM(void * Buffer, int32_t &Size, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase);

		int32_t SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);

		int32_t SaveToBufferPFX(void * Buffer, int32_t &Size, const std::string &Password);

		int32_t SaveToBufferSPC(void * Buffer, int32_t &Size);

		int32_t SaveKeyToBufferMS(void * Buffer, int32_t &Size);

		int32_t SaveKeyToBufferNET(void * Buffer, int32_t &Size);

		int32_t SaveKeyToBufferPVK(void * Buffer, int32_t &Size, const std::string &Password, bool UseStrongEncryption);

		int32_t SaveKeyToBufferPKCS8(void * Buffer, int32_t &Size, const std::string &Password);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStream(TStream &Stream);

		void SaveKeyToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStreamPEM(TStream &Stream, const std::string &PassPhrase);

		void SaveToStreamPEM(TStream *Stream, const std::string &PassPhrase);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStreamPEM(TStream &Stream, const std::string &PassPhrase);

		void SaveKeyToStreamPEM(TStream *Stream, const std::string &PassPhrase);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStreamPEM(TStream &Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase);

		void SaveKeyToStreamPEM(TStream *Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &PassPhrase);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStreamPFX(TStream &Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);

		int32_t SaveToStreamPFX(TStream *Stream, const std::string &Password, int32_t KeyEncryptionAlgorithm, int32_t CertEncryptionAlgorithm);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStreamPFX(TStream &Stream, const std::string &Password);

		int32_t SaveToStreamPFX(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStreamSPC(TStream &Stream);

		int32_t SaveToStreamSPC(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool SaveKeyValueToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveKeyToStreamMS(TStream &Stream);

		int32_t SaveKeyToStreamMS(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveKeyToStreamNET(TStream &Stream, const std::string &Password);

		int32_t SaveKeyToStreamNET(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveKeyToStreamPVK(TStream &Stream, const std::string &Password, bool UseStrongEncryption);

		int32_t SaveKeyToStreamPVK(TStream *Stream, const std::string &Password, bool UseStrongEncryption);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveKeyToStreamPKCS8(TStream &Stream, const std::string &Password);

		int32_t SaveKeyToStreamPKCS8(TStream *Stream, const std::string &Password);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t SaveToFile(const std::string &Filename, const std::string &Password, TSBCertFileFormat Format);

		int32_t SaveKeyToFile(const std::string &Filename, const std::string &Password, TSBX509KeyFileFormat Format);

		bool Validate();

		bool ValidateWithCA(TElX509Certificate &CACertificate);

		bool ValidateWithCA(TElX509Certificate *CACertificate);

		bool GetRSAParams(void * RSAModulus, int32_t &RSAModulusSize, void * RSAPublicKey, int32_t &RSAPublicKeySize);

		bool GetDSSParams(void * DSSP, int32_t &DSSPSize, void * DSSQ, int32_t &DSSQSize, void * DSSG, int32_t &DSSGSize, void * DSSY, int32_t &DSSYSize);

		bool GetDHParams(void * DHP, int32_t &DHPSize, void * DHG, int32_t &DHGSize, void * DHY, int32_t &DHYSize);

		bool GetPublicKeyBlob(void * Buffer, int32_t &Size);

		void GetPublicKeyBlob(std::vector<uint8_t> &Buffer);

		void GetFullPublicKeyInfo(std::vector<uint8_t> &OutResult);

		void GetHashMD5(TMessageDigest128 &OutResult);

		void GetHashSHA1(TMessageDigest160 &OutResult);

		void GetKeyHashSHA1(TMessageDigest160 &OutResult);

		void GetCertificateHash(int32_t Alg, std::vector<uint8_t> &OutResult);

		void GetZIPCertIdentifier(std::vector<uint8_t> &OutResult);

		int32_t GetPublicKeySize();

		bool IsKeyValid();

		void WriteSerialNumber(std::vector<uint8_t> &OutResult);

		void WriteExtensionSubjectKeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void WriteSubject(std::vector<uint8_t> &OutResult);

		virtual void WriteIssuer(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void SetKeyMaterial(TElPublicKeyMaterial &Value);

		void SetKeyMaterial(TElPublicKeyMaterial *Value);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_WINDOWS
		bool View(uint32_t Owner);
#endif

		static TClassHandle ClassType();

		virtual PByteArray get_CertificateBinary();

		SB_DECLARE_PROPERTY_GET(PByteArray, get_CertificateBinary, TElX509Certificate, CertificateBinary);

		virtual int32_t get_CertificateSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertificateSize, TElX509Certificate, CertificateSize);

		virtual int32_t get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureAlgorithm, TElX509Certificate, SignatureAlgorithm);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_SignatureAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_SignatureAlgorithmIdentifier, TElX509Certificate, SignatureAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_Signature(std::vector<uint8_t> &OutResult);

		virtual uint8_t get_Version();

		virtual void set_Version(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Version, set_Version, TElX509Certificate, Version);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual int64_t get_ValidFrom();

		virtual void set_ValidFrom(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidFrom, set_ValidFrom, TElX509Certificate, ValidFrom);

		virtual int64_t get_ValidTo();

		virtual void set_ValidTo(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidTo, set_ValidTo, TElX509Certificate, ValidTo);

		virtual int32_t get_BelongsTo();

		virtual void set_BelongsTo(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BelongsTo, set_BelongsTo, TElX509Certificate, BelongsTo);

#ifdef SB_WINDOWS
		virtual PCCERT_CONTEXT get_CertHandle();

		virtual void set_CertHandle(PCCERT_CONTEXT Value);

		SB_DECLARE_PROPERTY(PCCERT_CONTEXT, get_CertHandle, set_CertHandle, TElX509Certificate, CertHandle);

		virtual void get_FriendlyName(std::string &OutResult);

		virtual void set_FriendlyName(const std::string &Value);
#endif

		virtual void get_IssuerUniqueID(std::vector<uint8_t> &OutResult);

		virtual void get_SubjectUniqueID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyAlgorithm, TElX509Certificate, PublicKeyAlgorithm);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_PublicKeyAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_PublicKeyAlgorithmIdentifier, TElX509Certificate, PublicKeyAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual bool get_PrivateKeyExists();

		SB_DECLARE_PROPERTY_GET(bool, get_PrivateKeyExists, TElX509Certificate, PrivateKeyExists);

		virtual bool get_PrivateKeyExtractable();

		SB_DECLARE_PROPERTY_GET(bool, get_PrivateKeyExtractable, TElX509Certificate, PrivateKeyExtractable);

		virtual bool get_CAAvailable();

		virtual void set_CAAvailable(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CAAvailable, set_CAAvailable, TElX509Certificate, CAAvailable);

		virtual bool get_SelfSigned();

		SB_DECLARE_PROPERTY_GET(bool, get_SelfSigned, TElX509Certificate, SelfSigned);

		virtual void get_IssuerName(TName &OutResult);

		virtual void get_SubjectName(TName &OutResult);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_IssuerRDN, TElX509Certificate, IssuerRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_SubjectRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_SubjectRDN, TElX509Certificate, SubjectRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElX509Certificate, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
		virtual TElBaseCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElBaseCertStorage &Value);

		virtual void set_CertStorage(TElBaseCertStorage *Value);

		SB_DECLARE_PROPERTY(TElBaseCertStorage*, get_CertStorage, set_CertStorage, TElX509Certificate, CertStorage);
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */

		virtual void get_StorageName(std::string &OutResult);

		virtual void set_StorageName(const std::string &Value);

		virtual bool get_CanEncrypt();

		SB_DECLARE_PROPERTY_GET(bool, get_CanEncrypt, TElX509Certificate, CanEncrypt);

		virtual bool get_CanSign();

		SB_DECLARE_PROPERTY_GET(bool, get_CanSign, TElX509Certificate, CanSign);

		virtual bool get_StrictMode();

		virtual void set_StrictMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictMode, set_StrictMode, TElX509Certificate, StrictMode);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElX509Certificate, UseUTF8);

#ifdef SB_USE_CLASS_TELX509CERTIFICATECHAIN
		virtual TElX509CertificateChain* get_Chain();

		virtual void set_Chain(TElX509CertificateChain &Value);

		virtual void set_Chain(TElX509CertificateChain *Value);

		SB_DECLARE_PROPERTY(TElX509CertificateChain*, get_Chain, set_Chain, TElX509Certificate, Chain);
#endif /* SB_USE_CLASS_TELX509CERTIFICATECHAIN */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_KeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElPublicKeyMaterial*, get_KeyMaterial, TElX509Certificate, KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		virtual bool get_NegativeSerial();

		SB_DECLARE_PROPERTY_GET(bool, get_NegativeSerial, TElX509Certificate, NegativeSerial);

		virtual bool get_ReportErrorOnPartialLoad();

		virtual void set_ReportErrorOnPartialLoad(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReportErrorOnPartialLoad, set_ReportErrorOnPartialLoad, TElX509Certificate, ReportErrorOnPartialLoad);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElX509Certificate, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElX509Certificate, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_IgnoreVersion();

		virtual void set_IgnoreVersion(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreVersion, set_IgnoreVersion, TElX509Certificate, IgnoreVersion);

		TElX509Certificate(TElX509CertificateHandle handle, TElOwnHandle ownHandle);

		explicit TElX509Certificate(TComponent &Owner);

		explicit TElX509Certificate(TComponent *Owner);

		virtual ~TElX509Certificate();

};
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELBASECERTSTORAGE
class TElBaseCertStorage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElBaseCertStorage)
	public:
		TElBaseCertStorage(TElBaseCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElBaseCertStorage(TComponent &AOwner);

		explicit TElBaseCertStorage(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELBASECERTSTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_X509

void PVKHeaderToByteArray(const TPVKHeader &Header, std::vector<uint8_t> &OutResult);

void PVK_DeriveKey(const std::vector<uint8_t> &Password, const std::vector<uint8_t> &Salt, bool AWeakMethod, std::vector<uint8_t> &OutResult);

void RaiseX509Error(int32_t ErrorCode);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
bool SerialNumberCorresponds(TElX509Certificate &Cert, const std::vector<uint8_t> &Serial);
bool SerialNumberCorresponds(TElX509Certificate *Cert, const std::vector<uint8_t> &Serial);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
void GetOriginalSerialNumber(TElX509Certificate &Cert, std::vector<uint8_t> &OutResult);
void GetOriginalSerialNumber(TElX509Certificate *Cert, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

bool GetX509NegativeSerialWorkaround();

void SetX509NegativeSerialWorkaround(bool Value);

#endif /* SB_USE_GLOBAL_PROCS_X509 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_X509
SB_IMPORT uint32_t SB_APIENTRY SBX509_PVKHeaderToByteArray(const TPVKHeader * Header, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509_PVK_DeriveKey(const uint8_t pPassword[], int32_t szPassword, const uint8_t pSalt[], int32_t szSalt, int8_t AWeakMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509_RaiseX509Error(int32_t ErrorCode);
SB_IMPORT uint32_t SB_APIENTRY SBX509_SerialNumberCorresponds(TElX509CertificateHandle Cert, const uint8_t pSerial[], int32_t szSerial, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509_GetOriginalSerialNumber(TElX509CertificateHandle Cert, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509_GetX509NegativeSerialWorkaround(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509_SetX509NegativeSerialWorkaround(int8_t Value);
#endif /* SB_USE_GLOBAL_PROCS_X509 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBX509 */
