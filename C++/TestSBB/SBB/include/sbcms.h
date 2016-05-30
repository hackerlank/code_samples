#ifndef __INC_SBCMS
#define __INC_SBCMS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbtspclient.h"
#include "sbhashfunction.h"
#include "sbcustomcrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbpublickeycrypto.h"
#include "sbcrl.h"
#include "sbcrlstorage.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbpkcs7utils.h"
#include "sbpkcs7.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbpkicommon.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbocspstorage.h"
#include "sbcmsutils.h"
#include "sbalgorithmidentifier.h"
#include "sbcertvalidator.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbdcpkiconstants.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_CMS 	9216
#define SB_CMS_ERROR_INVALID_CERT_REFS 	9217
#define SB_CMS_ERROR_INVALID_REVOC_REFS 	9218
#define SB_CMS_ERROR_INVALID_REVOC_VALS 	9219
#define SB_CMS_ERROR_INVALID_CRL_ID 	9220
#define SB_CMS_ERROR_INVALID_OCSP_ID 	9221
#define SB_CMS_ERROR_INVALID_SIGNER_ID 	9222
#define SB_CMS_ERROR_INVALID_ALG_ID 	9223
#define SB_CMS_ERROR_INVALID_PARAMETERS 	9224
#define SB_CMS_ERROR_INVALID_HASH 	9225
#define SB_CMS_ERROR_INVALID_SIGN_STRUCT 	9226
#define SB_CMS_ERROR_INVALID_COUNTERSIGN 	9227
#define SB_CMS_ERROR_INVALID_TIMESTAMP_TYPE 	9228
#define SB_CMS_ERROR_INVALID_TIMESTAMP 	9229
#define SB_CMS_ERROR_INVALID_TIMESTAMP_CMS 	9230
#define SB_CMS_ERROR_INVALID_TIMESTAMP_ASN1 	9231
#define SB_CMS_ERROR_INVALID_PKCS7_IN_DATA 	9232
#define SB_CMS_ERROR_INVALID_KEY_PARAMS 	9233
#define SB_CMS_ERROR_INVALID_POLICY_QUAL 	9234
#define SB_CMS_ERROR_INVALID_SIG_POLICY 	9235
#define SB_CMS_ERROR_INVALID_CONTENT_HINTS 	9236
#define SB_CMS_ERROR_INVALID_CONTENT_REFS 	9237
#define SB_CMS_ERROR_INVALID_SIGNER_LOCATION 	9238
#define SB_CMS_ERROR_INVALID_SIGNING_CERT 	9239
#define SB_CMS_ERROR_INVALID_SIGNER_ATTRS 	9240
#define SB_CMS_ERROR_INVALID_ATS_HASH_INDEX 	9241
#define SB_CMS_ERROR_UNSUPPORTED_ALGORITHM 	9248
#define SB_CMS_ERROR_NO_PRIVATE_KEY 	9249
#define SB_CMS_ERROR_NO_DECRYPTION_KEY 	9250
#define SB_CMS_ERROR_NO_SIGNED_DATA 	9251
#define SB_CMS_ERROR_NO_SIGNING_CERT 	9252
#define SB_CMS_ERROR_NO_RECIPIENT_CERT 	9253
#define SB_CMS_ERROR_WRONG_CONTENT_TYPE 	9254
#define SB_CMS_ERROR_TIMESTAMPING_FAILED 	9265
#define SB_CMS_ERROR_REMOTE_SIGN_FAILED 	9266
#define SB_CMS_ERROR_DECRYPTION_FAILED 	9267
#define SB_CMS_ERROR_UNEXPECTED_END_OF_DATA 	9281
#define SB_CMS_ERROR_UNEXPECTED_ELEMENT_IN_CHAIN 	9282
#define SB_CMS_ERROR_DUPLICATE_ELEMENT_IN_CHAIN 	9283
#define SB_CMS_ERROR_CHAIN_INCOMPLETE 	9284
#define SB_CMS_ERROR_INCONSISTENT_TIMESTAMP_STATE 	9285
#define SB_CMS_ERROR_ASN1_SERIALIZATION_FAILED 	9286
#define SB_CMS_ERROR_CANT_SAVE_TO_SOURCE 	9287
#define SB_CMS_ERROR_BUFFER_TOO_SMALL 	9288
#define SB_CMS_ERROR_BAD_TEMPLATE 	9289
#define SB_CMS_ERROR_INVALID_SIGNATURE_POLICY_STORE 	9290
#define SB_CMS_ERROR_UNSUPPORTED_SIGNING_MODE 	9291

typedef TElClassHandle TElASN1DirectoryStringHandle;

typedef TElClassHandle TElCMSPropertyHandle;

typedef TElClassHandle TElCMSHashHandle;

typedef TElClassHandle TElCMSSignerIdentifierHandle;

typedef TElClassHandle TElCMSCertificateRefsHandle;

typedef TElClassHandle TElCMSCRLIdentifierHandle;

typedef TElClassHandle TElCMSCRLValidatedIDHandle;

typedef TElClassHandle TElCMSOCSPIdentifierHandle;

typedef TElClassHandle TElCMSOCSPResponsesIDHandle;

typedef TElClassHandle TElCMSRevocationRefHandle;

typedef TElClassHandle TElCMSRevocationRefsHandle;

typedef TElClassHandle TElCMSRevocationValuesHandle;

typedef TElClassHandle TElCMSContentHandle;

typedef TElClassHandle TElCMSSigPolicyQualifierHandle;

typedef TElClassHandle TElCMSSignaturePolicyHandle;

typedef TElClassHandle TElCMSContentHintsHandle;

typedef TElClassHandle TElCMSContentReferenceHandle;

typedef TElClassHandle TElCMSCommitmentTypeIndicationHandle;

typedef TElClassHandle TElCMSSignerLocationHandle;

typedef TElClassHandle TElCMSSigningCertificateHandle;

typedef TElClassHandle TElCMSSignerAttributesHandle;

typedef TElClassHandle TElCMSSignaturePolicyStoreHandle;

typedef TElClassHandle TElCMSSignatureHandle;

typedef TElClassHandle TElCMSTimestampHandle;

typedef TElClassHandle TElATSHashIndexProcessorHandle;

typedef TElClassHandle TElSignedCMSMessageHandle;

typedef TElClassHandle TElCMSContentHashHandle;

typedef TElClassHandle TElCMSMessageHandle;

typedef TElClassHandle TElSignedAndEnvelopedCMSMessageHandle;

typedef uint8_t TSBASN1DirectoryStringEncodingRaw;

typedef enum
{
	dseTeletexString = 0,
	dsePrintableString = 1,
	dseUniversalString = 2,
	dseUTF8String = 3,
	dseBMPString = 4
} TSBASN1DirectoryStringEncoding;

typedef uint8_t TSBCMSRevocationRefsWriteModeRaw;

typedef enum
{
	rrwmWriteAll = 0,
	rrwmWriteCRLIfPresent = 1,
	rrwmWriteOCSPIfPresent = 2
} TSBCMSRevocationRefsWriteMode;

typedef uint8_t TSBCMSSignerIdentifierTypeRaw;

typedef enum
{
	sitESSCertID = 0,
	sitOtherCertID = 1,
	sitESSCertIDV2 = 2
} TSBCMSSignerIdentifierType;

typedef uint8_t TSBSigPolicyQualifierTypeRaw;

typedef enum
{
	spqtURI = 0,
	spqtUserNotice = 1,
	spqtCustom = 2
} TSBSigPolicyQualifierType;

typedef uint8_t TSBCMSSigningCertificateTypeRaw;

typedef enum
{
	sctESSSigningCertificate = 0,
	sctOtherSigningCertificate = 1,
	sctESSSigningCertificateV2 = 2
} TSBCMSSigningCertificateType;

typedef uint8_t TSBCMSSignerAttributesVersionRaw;

typedef enum
{
	saVersion1 = 0,
	saVersion2 = 1
} TSBCMSSignerAttributesVersion;

typedef uint8_t TSBCMSSignaturePolicyStoreTypeRaw;

typedef enum
{
	pstDocument = 0,
	pstURI = 1
} TSBCMSSignaturePolicyStoreType;

typedef uint8_t TSBCMSTimestampTypeRaw;

typedef enum
{
	cvtGeneric = 0,
	cvtESC = 1,
	cvtCertsAndCRLs = 2,
	cvtArchive = 3,
	cvtArchive2 = 4,
	cvtArchive3 = 5,
	cvtContent = 6
} TSBCMSTimestampType;

typedef uint8_t TSBCMSItemTypeRaw;

typedef enum
{
	citCertificate = 0,
	citCRL = 1,
	citOCSPResponse = 2,
	citTimestamp = 3
} TSBCMSItemType;

typedef void (SB_CALLBACK *TSBCMSBeforeSignEvent)(void * _ObjectData, TObjectHandle Sender, TElPublicKeyCryptoHandle Crypto);

typedef void (SB_CALLBACK *TSBCMSBeforeVerifyEvent)(void * _ObjectData, TObjectHandle Sender, TElPublicKeyCryptoHandle Crypto);

typedef void (SB_CALLBACK *TSBCMSCertificateTrustedEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle Cert, int8_t * Trusted);

typedef void (SB_CALLBACK *TSBCMSItemValidatedEvent)(void * _ObjectData, TObjectHandle Sender, TSBCMSItemTypeRaw ItemType, TObjectHandle Item, int8_t * Valid);

typedef void (SB_CALLBACK *TSBCMSCRLNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElCMSCRLValidatedIDHandle ID, TElX509CertificateHandle Cert, TElCertificateRevocationListHandle * Crl);

typedef void (SB_CALLBACK *TSBCMSOCSPResponseNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElCMSOCSPResponsesIDHandle ID, TElX509CertificateHandle Cert, TElOCSPResponseHandle * Ocsp);

typedef uint8_t TSBCMSSigningOptionRaw;

typedef enum
{
	csoInsertMessageDigests = 0,
	csoInsertSigningTime = 1,
	csoInsertContentType = 2,
	csoUseGeneralizedTimeFormat = 3,
	csoIncludeCertToMessage = 4,
	csoIncludeCertToAttributes = 5,
	csoImzagerMIMCompatibility = 6,
	csoForceSigningCertificateV2Usage = 7,
	csoAnnexKArchiveTimestampV2Mode = 8,
	csoDigitPADSSCompatibility = 9,
	csoCompareRDNAsStrings = 10,
	csoIgnoreDERReqInArchiveTimestamps = 11,
	csoSkipEnvContentInfoOnSigArchival = 12,
	csoUseGenericSigAlgorithmOIDs = 13,
	csoUsePlainContentForTimestampHashes = 14,
	csoUseATSHashIndexV1 = 15,
	csoCheckATSHashIndexElements = 16
} TSBCMSSigningOption;

typedef uint32_t TSBCMSSigningOptionsRaw;

typedef enum 
{
	f_csoInsertMessageDigests = 1,
	f_csoInsertSigningTime = 2,
	f_csoInsertContentType = 4,
	f_csoUseGeneralizedTimeFormat = 8,
	f_csoIncludeCertToMessage = 16,
	f_csoIncludeCertToAttributes = 32,
	f_csoImzagerMIMCompatibility = 64,
	f_csoForceSigningCertificateV2Usage = 128,
	f_csoAnnexKArchiveTimestampV2Mode = 256,
	f_csoDigitPADSSCompatibility = 512,
	f_csoCompareRDNAsStrings = 1024,
	f_csoIgnoreDERReqInArchiveTimestamps = 2048,
	f_csoSkipEnvContentInfoOnSigArchival = 4096,
	f_csoUseGenericSigAlgorithmOIDs = 8192,
	f_csoUsePlainContentForTimestampHashes = 16384,
	f_csoUseATSHashIndexV1 = 32768,
	f_csoCheckATSHashIndexElements = 65536
} TSBCMSSigningOptions;

typedef void (SB_CALLBACK *TSBCMSRemoteSignCallback)(void * _ObjectData, TObjectHandle Sender, TObjectHandle Param, const uint8_t pHash[], int32_t szHash, uint8_t pSignedHash[], int32_t * szSignedHash, int8_t * OutResult);

typedef uint8_t TSBCMSSignatureStateRaw;

typedef enum
{
	cssSigned = 0,
	cssUnsigned = 1
} TSBCMSSignatureState;

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
SB_IMPORT uint32_t SB_APIENTRY TElASN1DirectoryString_get_Value(TElASN1DirectoryStringHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DirectoryString_set_Value(TElASN1DirectoryStringHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DirectoryString_get_Encoding(TElASN1DirectoryStringHandle _Handle, TSBASN1DirectoryStringEncodingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DirectoryString_set_Encoding(TElASN1DirectoryStringHandle _Handle, TSBASN1DirectoryStringEncodingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DirectoryString_Create(TElASN1DirectoryStringHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELCMSPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_get_Included(TElCMSPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_set_Included(TElCMSPropertyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_get_Signed(TElCMSPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_set_Signed(TElCMSPropertyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_get_RecalculateValue(TElCMSPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_set_RecalculateValue(TElCMSPropertyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_get_RawValue(TElCMSPropertyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSProperty_Create(TElCMSPropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSPROPERTY */

#ifdef SB_USE_CLASS_TELCMSHASH
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_Clear(TElCMSHashHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_get_HashAlgorithm(TElCMSHashHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_set_HashAlgorithm(TElCMSHashHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_get_HashAlgorithmParams(TElCMSHashHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_set_HashAlgorithmParams(TElCMSHashHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_get_HashValue(TElCMSHashHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_set_HashValue(TElCMSHashHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSHash_Create(TElCMSHashHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_Import(TElCMSSignerIdentifierHandle _Handle, TElX509CertificateHandle Cert, int32_t HashAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_Clear(TElCMSSignerIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_Corresponds(TElCMSSignerIdentifierHandle _Handle, TElX509CertificateHandle Cert, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_get_Hash(TElCMSSignerIdentifierHandle _Handle, TElCMSHashHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_get_Issuer(TElCMSSignerIdentifierHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_get_SerialNumber(TElCMSSignerIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_get_SignerIdentifierType(TElCMSSignerIdentifierHandle _Handle, TSBCMSSignerIdentifierTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_set_SignerIdentifierType(TElCMSSignerIdentifierHandle _Handle, TSBCMSSignerIdentifierTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerIdentifier_Create(TElCMSSignerIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_Add(TElCMSCertificateRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_Remove(TElCMSCertificateRefsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_Clear(TElCMSCertificateRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_get_CertIDs(TElCMSCertificateRefsHandle _Handle, int32_t Index, TElCMSSignerIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_get_CertIDCount(TElCMSCertificateRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCertificateRefs_Create(TElCMSCertificateRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_Clear(TElCMSCRLIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_get_Issuer(TElCMSCRLIdentifierHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_get_Time(TElCMSCRLIdentifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_set_Time(TElCMSCRLIdentifierHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_get_Number(TElCMSCRLIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_set_Number(TElCMSCRLIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLIdentifier_Create(TElCMSCRLIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLValidatedID_Import(TElCMSCRLValidatedIDHandle _Handle, TElCertificateRevocationListHandle CRL, int32_t HashAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLValidatedID_CRLMatches(TElCMSCRLValidatedIDHandle _Handle, TElCertificateRevocationListHandle CRL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLValidatedID_get_CRLHash(TElCMSCRLValidatedIDHandle _Handle, TElCMSHashHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLValidatedID_get_CRLIdentifier(TElCMSCRLValidatedIDHandle _Handle, TElCMSCRLIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCRLValidatedID_Create(TElCMSCRLValidatedIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */

#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_Assign(TElCMSOCSPIdentifierHandle _Handle, TElCMSOCSPIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_Clear(TElCMSOCSPIdentifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_get_ResponderID(TElCMSOCSPIdentifierHandle _Handle, TElOCSPResponderIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_get_Time(TElCMSOCSPIdentifierHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_set_Time(TElCMSOCSPIdentifierHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPIdentifier_Create(TElCMSOCSPIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_Clear(TElCMSOCSPResponsesIDHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_Import(TElCMSOCSPResponsesIDHandle _Handle, TElOCSPResponseHandle Response, int32_t HashAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_OCSPResponseMatches(TElCMSOCSPResponsesIDHandle _Handle, TElOCSPResponseHandle Response, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_get_OCSPIdentifier(TElCMSOCSPResponsesIDHandle _Handle, TElCMSOCSPIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_get_OCSPHash(TElCMSOCSPResponsesIDHandle _Handle, TElCMSHashHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSOCSPResponsesID_Create(TElCMSOCSPResponsesIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_AddCRLID(TElCMSRevocationRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_AddOCSPID(TElCMSRevocationRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_RemoveCRLID(TElCMSRevocationRefHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_RemoveOCSPID(TElCMSRevocationRefHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_ClearCRLIDs(TElCMSRevocationRefHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_ClearOCSPIDs(TElCMSRevocationRefHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_Import(TElCMSRevocationRefHandle _Handle, TListHandle CRLList, TListHandle OCSPList);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_Import2(TElCMSRevocationRefHandle _Handle, TElMemoryCRLStorageHandle CRLs, TListHandle OCSPList);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_CRLIDs(TElCMSRevocationRefHandle _Handle, int32_t Index, TElCMSCRLValidatedIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_OCSPIDs(TElCMSRevocationRefHandle _Handle, int32_t Index, TElCMSOCSPResponsesIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_CRLIDCount(TElCMSRevocationRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_OCSPIDCount(TElCMSRevocationRefHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_OtherRevType(TElCMSRevocationRefHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_set_OtherRevType(TElCMSRevocationRefHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_get_OtherRevRefs(TElCMSRevocationRefHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_set_OtherRevRefs(TElCMSRevocationRefHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRef_Create(TElCMSRevocationRefHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_Add(TElCMSRevocationRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_Remove(TElCMSRevocationRefsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_Clear(TElCMSRevocationRefsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_get_Refs(TElCMSRevocationRefsHandle _Handle, int32_t Index, TElCMSRevocationRefHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_get_RefCount(TElCMSRevocationRefsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_get_AddASN1ExplicitTagsForEmptyRecords(TElCMSRevocationRefsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_set_AddASN1ExplicitTagsForEmptyRecords(TElCMSRevocationRefsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_get_WriteMode(TElCMSRevocationRefsHandle _Handle, TSBCMSRevocationRefsWriteModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_set_WriteMode(TElCMSRevocationRefsHandle _Handle, TSBCMSRevocationRefsWriteModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationRefs_Create(TElCMSRevocationRefsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_AddCRL(TElCMSRevocationValuesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_AddOCSPResponse(TElCMSRevocationValuesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_RemoveCRL(TElCMSRevocationValuesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_RemoveOCSPResponse(TElCMSRevocationValuesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_ClearCRLs(TElCMSRevocationValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_ClearOCSPResponses(TElCMSRevocationValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_Clear(TElCMSRevocationValuesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_CRLs(TElCMSRevocationValuesHandle _Handle, int32_t Index, TElCertificateRevocationListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_OCSPResponses(TElCMSRevocationValuesHandle _Handle, int32_t Index, TElOCSPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_CRLCount(TElCMSRevocationValuesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_OCSPResponseCount(TElCMSRevocationValuesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_OtherRevType(TElCMSRevocationValuesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_set_OtherRevType(TElCMSRevocationValuesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_get_OtherRevValues(TElCMSRevocationValuesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_set_OtherRevValues(TElCMSRevocationValuesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSRevocationValues_Create(TElCMSRevocationValuesHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELCMSCONTENT
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Clear(TElCMSContentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Init(TElCMSContentHandle _Handle, TStreamHandle Stream, int64_t Offset, int64_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Init_1(TElCMSContentHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Read(TElCMSContentHandle _Handle, void * Buffer, int32_t Size, int64_t Offset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_AddKnownHash(TElCMSContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_AddKnownHash_1(TElCMSContentHandle _Handle, int32_t AlgID, const uint8_t pHashAlgParams[], int32_t szHashAlgParams, const uint8_t pHash[], int32_t szHash, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_RemoveKnownHash(TElCMSContentHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_ClearKnownHashes(TElCMSContentHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_get_Size(TElCMSContentHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_get_ContentIsHash(TElCMSContentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_set_ContentIsHash(TElCMSContentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_get_RawContent(TElCMSContentHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_get_KnownHashes(TElCMSContentHandle _Handle, int32_t Index, TElCMSHashHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_get_KnownHashCount(TElCMSContentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Create(TElCMSContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Create_1(TElPKCS7SignedDataHandle Data, TElCMSContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContent_Create_2(TElPKCS7SignedAndEnvelopedDataHandle Data, TElCMSContentHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCONTENT */

#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_Clear(TElCMSSigPolicyQualifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_AddNoticeNumber(TElCMSSigPolicyQualifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_RemoveNoticeNumber(TElCMSSigPolicyQualifierHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_ClearNoticeNumbers(TElCMSSigPolicyQualifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_ID(TElCMSSigPolicyQualifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_ID(TElCMSSigPolicyQualifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_QualifierType(TElCMSSigPolicyQualifierHandle _Handle, TSBSigPolicyQualifierTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_QualifierType(TElCMSSigPolicyQualifierHandle _Handle, TSBSigPolicyQualifierTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_URI(TElCMSSigPolicyQualifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_URI(TElCMSSigPolicyQualifierHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_ExplicitText(TElCMSSigPolicyQualifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_ExplicitText(TElCMSSigPolicyQualifierHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_Organization(TElCMSSigPolicyQualifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_Organization(TElCMSSigPolicyQualifierHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_CustomData(TElCMSSigPolicyQualifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_CustomData(TElCMSSigPolicyQualifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_NoticeNumbers(TElCMSSigPolicyQualifierHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_NoticeNumbers(TElCMSSigPolicyQualifierHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_NoticeNumberCount(TElCMSSigPolicyQualifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_get_UseUTF8(TElCMSSigPolicyQualifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_set_UseUTF8(TElCMSSigPolicyQualifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigPolicyQualifier_Create(TElCMSSigPolicyQualifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_AddQualifier(TElCMSSignaturePolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_RemoveQualifier(TElCMSSignaturePolicyHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_ClearQualifiers(TElCMSSignaturePolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_Clear(TElCMSSignaturePolicyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_get_PolicyIdentifier(TElCMSSignaturePolicyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_set_PolicyIdentifier(TElCMSSignaturePolicyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_get_PolicyHash(TElCMSSignaturePolicyHandle _Handle, TElCMSHashHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_get_Qualifiers(TElCMSSignaturePolicyHandle _Handle, int32_t Index, TElCMSSigPolicyQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_get_QualifierCount(TElCMSSignaturePolicyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_get_Implied(TElCMSSignaturePolicyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_set_Implied(TElCMSSignaturePolicyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicy_Create(TElCMSSignaturePolicyHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */

#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHints_get_ContentDescription(TElCMSContentHintsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHints_set_ContentDescription(TElCMSContentHintsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHints_get_ContentType(TElCMSContentHintsHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHints_set_ContentType(TElCMSContentHintsHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHints_Create(TElCMSContentHintsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */

#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_get_ContentType(TElCMSContentReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_set_ContentType(TElCMSContentReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_get_ContentIdentifier(TElCMSContentReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_set_ContentIdentifier(TElCMSContentReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_get_OriginatorSignatureValue(TElCMSContentReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_set_OriginatorSignatureValue(TElCMSContentReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentReference_Create(TElCMSContentReferenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */

#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_Clear(TElCMSCommitmentTypeIndicationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfOrigin(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfOrigin(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfReceipt(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfReceipt(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfDelivery(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfDelivery(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfSender(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfSender(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfApproval(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfApproval(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_ProofOfCreation(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_set_ProofOfCreation(TElCMSCommitmentTypeIndicationHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_get_CustomIdentifiers(TElCMSCommitmentTypeIndicationHandle _Handle, TElByteArrayListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSCommitmentTypeIndication_Create(TElCMSCommitmentTypeIndicationHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_Clear(TElCMSSignerLocationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_AddPostalAddressLine(TElCMSSignerLocationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_RemovePostalAddressLine(TElCMSSignerLocationHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_ClearPostalAddressLines(TElCMSSignerLocationHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_get_CountryName(TElCMSSignerLocationHandle _Handle, TElASN1DirectoryStringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_get_LocalityName(TElCMSSignerLocationHandle _Handle, TElASN1DirectoryStringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_get_PostalAddressLines(TElCMSSignerLocationHandle _Handle, int32_t Index, TElASN1DirectoryStringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_get_PostalAddressLineCount(TElCMSSignerLocationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerLocation_Create(TElCMSSignerLocationHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */

#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_Clear(TElCMSSigningCertificateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_AddCertID(TElCMSSigningCertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_RemoveCertID(TElCMSSigningCertificateHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_ClearCertIDs(TElCMSSigningCertificateHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_Corresponds(TElCMSSigningCertificateHandle _Handle, TElX509CertificateHandle Cert, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_get_CertIDs(TElCMSSigningCertificateHandle _Handle, int32_t Index, TElCMSSignerIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_get_CertIDCount(TElCMSSigningCertificateHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_get_SigningCertificateType(TElCMSSigningCertificateHandle _Handle, TSBCMSSigningCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_set_SigningCertificateType(TElCMSSigningCertificateHandle _Handle, TSBCMSSigningCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSigningCertificate_Create(TElCMSSigningCertificateHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_Clear(TElCMSSignerAttributesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_get_ClaimedAttributes(TElCMSSignerAttributesHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_get_CertifiedAttributesBinary(TElCMSSignerAttributesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_set_CertifiedAttributesBinary(TElCMSSignerAttributesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_get_SignedAssertions(TElCMSSignerAttributesHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_get_Version(TElCMSSignerAttributesHandle _Handle, TSBCMSSignerAttributesVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_set_Version(TElCMSSignerAttributesHandle _Handle, TSBCMSSignerAttributesVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_get_AttributeCertificateType(TElCMSSignerAttributesHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_set_AttributeCertificateType(TElCMSSignerAttributesHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignerAttributes_Create(TElCMSSignerAttributesHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_Clear(TElCMSSignaturePolicyStoreHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_get_DocSpecOID(TElCMSSignaturePolicyStoreHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_set_DocSpecOID(TElCMSSignaturePolicyStoreHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_get_DocSpecURI(TElCMSSignaturePolicyStoreHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_set_DocSpecURI(TElCMSSignaturePolicyStoreHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_get_EncodedPolicyDocument(TElCMSSignaturePolicyStoreHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_set_EncodedPolicyDocument(TElCMSSignaturePolicyStoreHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_get_PolicyLocalURI(TElCMSSignaturePolicyStoreHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_set_PolicyLocalURI(TElCMSSignaturePolicyStoreHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_get_PolicyStoreType(TElCMSSignaturePolicyStoreHandle _Handle, TSBCMSSignaturePolicyStoreTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_set_PolicyStoreType(TElCMSSignaturePolicyStoreHandle _Handle, TSBCMSSignaturePolicyStoreTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignaturePolicyStore_Create(TElCMSSignaturePolicyStoreHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Assign(TElCMSSignatureHandle _Handle, TElCMSSignatureHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddCountersignature(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddCountersignature_1(TElCMSSignatureHandle _Handle, const uint8_t pSignature[], int32_t szSignature, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddTimestamp(TElCMSSignatureHandle _Handle, TElCustomTSPClientHandle TSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddTimestamp_1(TElCMSSignatureHandle _Handle, const uint8_t pTimestamp[], int32_t szTimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddContentTimestamp(TElCMSSignatureHandle _Handle, TElCustomTSPClientHandle TSPClient, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddContentTimestamp_1(TElCMSSignatureHandle _Handle, const uint8_t pTimestamp[], int32_t szTimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddValidationTimestamp(TElCMSSignatureHandle _Handle, TElCustomTSPClientHandle TSPClient, TSBCMSTimestampTypeRaw TimestampType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddCompleteValidationData(TElCMSSignatureHandle _Handle, TElCustomCertStorageHandle Chain, TElMemoryCRLStorageHandle CRLs, TListHandle OCSPResponses, int8_t ReferencesOnly);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_AddCompleteValidationDataItem(TElCMSSignatureHandle _Handle, TElX509CertificateHandle Cert, TElMemoryCRLStorageHandle CRLs, TListHandle OCSPResponses, int8_t ReferencesOnly);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_RemoveCountersignature(TElCMSSignatureHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_RemoveTimestamp(TElCMSSignatureHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_RemoveContentTimestamp(TElCMSSignatureHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_RemoveValidationTimestamp(TElCMSSignatureHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_ClearCountersignatures(TElCMSSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_ClearTimestamps(TElCMSSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_ClearContentTimestamps(TElCMSSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_ClearValidationTimestamps(TElCMSSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Sign(TElCMSSignatureHandle _Handle, TElX509CertificateHandle Cert, TElCustomCertStorageHandle Chain);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_SignRemote(TElCMSSignatureHandle _Handle, TElX509CertificateHandle Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, void * Param, TElCustomCertStorageHandle Chain);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_SignRemote_1(TElCMSSignatureHandle _Handle, TElX509CertificateHandle Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, int8_t ExternalHashCalculation, void * Param, TElCustomCertStorageHandle Chain);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Validate(TElCMSSignatureHandle _Handle, TSBCMSSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Validate_1(TElCMSSignatureHandle _Handle, TSBCMSValidationOptionsRaw Options, TSBCMSAdvancedSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Validate_2(TElCMSSignatureHandle _Handle, TElX509CertificateValidatorHandle Validator, TSBCMSValidationOptionsRaw Options, TSBCMSAdvancedSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_GetSignedCMSMessage(TElCMSSignatureHandle _Handle, TElSignedCMSMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_InitiateAsyncSign(TElCMSSignatureHandle _Handle, TElX509CertificateHandle Cert, TElCustomCertStorageHandle Chain, TElDCAsyncStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_InitiateAsyncSign_1(TElCMSSignatureHandle _Handle, TElDCAsyncStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_InitiateAsyncSign_2(TElCMSSignatureHandle _Handle, TSBDCAsyncSignMethodRaw AsyncSignMethod, TElDCAsyncStateHandle * State);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_CompleteAsyncSign(TElCMSSignatureHandle _Handle, TElDCAsyncStateHandle AsyncState);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_UpdateCMS(TElCMSSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_Content(TElCMSSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_Signer(TElCMSSignatureHandle _Handle, TElPKCS7IssuerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_DigestAlgorithm(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_DigestAlgorithm(TElCMSSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_EncryptedDigest(TElCMSSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_PublicKeyAlgorithm(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_PublicKeyAlgorithm(TElCMSSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_FingerprintAlgorithm(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_FingerprintAlgorithm(TElCMSSignatureHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CustomSignedAttributes(TElCMSSignatureHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CustomUnsignedAttributes(TElCMSSignatureHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignedAttributesPresent(TElCMSSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignatureAlgorithm(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_Countersignatures(TElCMSSignatureHandle _Handle, int32_t Index, TElCMSSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_Timestamps(TElCMSSignatureHandle _Handle, int32_t Index, TElCMSTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentTimestamps(TElCMSSignatureHandle _Handle, int32_t Index, TElCMSTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ValidationTimestamps(TElCMSSignatureHandle _Handle, int32_t Index, TElCMSTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CountersignatureCount(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_TimestampCount(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentTimestampCount(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_LastValidationResult(TElCMSSignatureHandle _Handle, TSBCMSAdvancedSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_LastValidatorValidity(TElCMSSignatureHandle _Handle, TSBCertificateValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_LastValidatorReason(TElCMSSignatureHandle _Handle, TSBCertificateValidityReasonRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentType(TElCMSSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_ContentType(TElCMSSignatureHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SigningTime(TElCMSSignatureHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_SigningTime(TElCMSSignatureHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignaturePolicy(TElCMSSignatureHandle _Handle, TElCMSSignaturePolicyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentHints(TElCMSSignatureHandle _Handle, TElCMSContentHintsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentIdentifier(TElCMSSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_ContentIdentifier(TElCMSSignatureHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ContentReference(TElCMSSignatureHandle _Handle, TElCMSContentReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CommitmentTypeIndication(TElCMSSignatureHandle _Handle, TElCMSCommitmentTypeIndicationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_CommitmentTypeIndication(TElCMSSignatureHandle _Handle, TElCMSCommitmentTypeIndicationHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignerLocation(TElCMSSignatureHandle _Handle, TElCMSSignerLocationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SigningCertificate(TElCMSSignatureHandle _Handle, TElCMSSigningCertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_MessageDigest(TElCMSSignatureHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_MimeType(TElCMSSignatureHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_MimeType(TElCMSSignatureHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CertificateRefs(TElCMSSignatureHandle _Handle, TElCMSCertificateRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_CertificateValues(TElCMSSignatureHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_RevocationRefs(TElCMSSignatureHandle _Handle, TElCMSRevocationRefsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_RevocationValues(TElCMSSignatureHandle _Handle, TElCMSRevocationValuesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignerAttributes(TElCMSSignatureHandle _Handle, TElCMSSignerAttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SignaturePolicyStore(TElCMSSignatureHandle _Handle, TElCMSSignaturePolicyStoreHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_ValidationTimestampCount(TElCMSSignatureHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_State(TElCMSSignatureHandle _Handle, TSBCMSSignatureStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_SigningOptions(TElCMSSignatureHandle _Handle, TSBCMSSigningOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_SigningOptions(TElCMSSignatureHandle _Handle, TSBCMSSigningOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_UsePSS(TElCMSSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_UsePSS(TElCMSSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_UseCachedDigests(TElCMSSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_UseCachedDigests(TElCMSSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_LiberalMode(TElCMSSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_LiberalMode(TElCMSSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_AuthenticodeMode(TElCMSSignatureHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_AuthenticodeMode(TElCMSSignatureHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnBeforeSign(TElCMSSignatureHandle _Handle, TSBCMSBeforeSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnBeforeSign(TElCMSSignatureHandle _Handle, TSBCMSBeforeSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnBeforeVerify(TElCMSSignatureHandle _Handle, TSBCMSBeforeVerifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnBeforeVerify(TElCMSSignatureHandle _Handle, TSBCMSBeforeVerifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnCertificateNeeded(TElCMSSignatureHandle _Handle, TSBCMSCertificateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnCertificateNeeded(TElCMSSignatureHandle _Handle, TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnIsCertificateTrusted(TElCMSSignatureHandle _Handle, TSBCMSCertificateTrustedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnIsCertificateTrusted(TElCMSSignatureHandle _Handle, TSBCMSCertificateTrustedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnCRLNeeded(TElCMSSignatureHandle _Handle, TSBCMSCRLNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnCRLNeeded(TElCMSSignatureHandle _Handle, TSBCMSCRLNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnOCSPResponseNeeded(TElCMSSignatureHandle _Handle, TSBCMSOCSPResponseNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnOCSPResponseNeeded(TElCMSSignatureHandle _Handle, TSBCMSOCSPResponseNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnItemValidated(TElCMSSignatureHandle _Handle, TSBCMSItemValidatedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnItemValidated(TElCMSSignatureHandle _Handle, TSBCMSItemValidatedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_get_OnProgress(TElCMSSignatureHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_set_OnProgress(TElCMSSignatureHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Create(TObjectHandle Subject, TElCMSSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Create_1(TObjectHandle Subject, TElPKCS7SignerHandle PKCS7Signer, TElCMSSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSSignature_Create_2(TObjectHandle Subject, const uint8_t pData[], int32_t szData, TElCMSSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_Validate(TElCMSTimestampHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_UpdateCMS(TElCMSTimestampHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_Certificates(TElCMSTimestampHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_CRLs(TElCMSTimestampHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_OCSPResponses(TElCMSTimestampHandle _Handle, TElOCSPResponseStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_Signatures(TElCMSTimestampHandle _Handle, int32_t Index, TElCMSSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_SignatureCount(TElCMSTimestampHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_Info(TElCMSTimestampHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_TimestampType(TElCMSTimestampHandle _Handle, TSBCMSTimestampTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_UseCachedDigests(TElCMSTimestampHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_set_UseCachedDigests(TElCMSTimestampHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_DigestCalcType(TElCMSTimestampHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_get_CMS(TElCMSTimestampHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_Create(TObjectHandle Subject, TElCMSTimestampHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSTimestamp_Create_1(TObjectHandle Subject, const uint8_t pData[], int32_t szData, TElCMSTimestampHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELATSHASHINDEXPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_Clear(TElATSHashIndexProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_Load(TElATSHashIndexProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_CertPresent(TElATSHashIndexProcessorHandle _Handle, TElX509CertificateHandle Cert, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_CRLPresent(TElATSHashIndexProcessorHandle _Handle, TElCertificateRevocationListHandle Crl, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_OCSPResponsePresent(TElATSHashIndexProcessorHandle _Handle, TElOCSPResponseHandle OcspResponse, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_CertHashes(TElATSHashIndexProcessorHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_CertHashesCount(TElATSHashIndexProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_RevInfoHashes(TElATSHashIndexProcessorHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_RevInfoHashesCount(TElATSHashIndexProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_AttributeHashes(TElATSHashIndexProcessorHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_AttributeHashesCount(TElATSHashIndexProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_get_HashAlgorithm(TElATSHashIndexProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElATSHashIndexProcessor_Create(TElATSHashIndexProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELATSHASHINDEXPROCESSOR */

#ifdef SB_USE_CLASS_TELCMSMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_Clear(TElCMSMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_CreateNew(TElCMSMessageHandle _Handle, TStreamHandle DataStream, int64_t Offset, int64_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_CreateNew_1(TElCMSMessageHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_Open(TElCMSMessageHandle _Handle, TStreamHandle CMSStream, TStreamHandle DataStream, int64_t CMSCount, int64_t DataCount);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_Save(TElCMSMessageHandle _Handle, TStreamHandle DestStream);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_Close(TElCMSMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_get_Content(TElCMSMessageHandle _Handle, TElCMSContentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_get_Detached(TElCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_set_Detached(TElCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_get_UseUndefSize(TElCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_set_UseUndefSize(TElCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCMSMessage_Create(TComponentHandle AOwner, TElCMSMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSMESSAGE */

#ifdef SB_USE_CLASS_TELCMSCONTENTHASH
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHash_Clear(TElCMSContentHashHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHash_GetHash(TElCMSContentHashHandle _Handle, int32_t Alg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHash_SetHash(TElCMSContentHashHandle _Handle, int32_t Alg, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCMSContentHash_Create(TElCMSContentHashHandle * OutResult);
#endif /* SB_USE_CLASS_TELCMSCONTENTHASH */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_AddSignature(TElSignedCMSMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_RemoveSignature(TElSignedCMSMessageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_ClearSignatures(TElSignedCMSMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_ExtractAllCertificates(TElSignedCMSMessageHandle _Handle, TElCustomCertStorageHandle Storage);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_ExtractAllValidationElements(TElSignedCMSMessageHandle _Handle, TElCustomCertStorageHandle Storage, TElMemoryCRLStorageHandle Crls, TListHandle Ocsps);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_ContentType(TElSignedCMSMessageHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_set_ContentType(TElSignedCMSMessageHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_ContentVersion(TElSignedCMSMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_set_ContentVersion(TElSignedCMSMessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_Certificates(TElSignedCMSMessageHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_CRLs(TElSignedCMSMessageHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_OCSPResponses(TElSignedCMSMessageHandle _Handle, TElOCSPResponseStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_Signatures(TElSignedCMSMessageHandle _Handle, int32_t Index, TElCMSSignatureHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_SignatureCount(TElSignedCMSMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_UseImplicitContent(TElSignedCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_set_UseImplicitContent(TElSignedCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_SerializeContentOnUpdate(TElSignedCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_set_SerializeContentOnUpdate(TElSignedCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_get_CertStorage(TElSignedCMSMessageHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_set_CertStorage(TElSignedCMSMessageHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedCMSMessage_Create(TComponentHandle AOwner, TElSignedCMSMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

#ifdef SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_CryptoProviderManager(TElSignedAndEnvelopedCMSMessageHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_CryptoProviderManager(TElSignedAndEnvelopedCMSMessageHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_Recipients(TElSignedAndEnvelopedCMSMessageHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_Recipients(TElSignedAndEnvelopedCMSMessageHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_Algorithm(TElSignedAndEnvelopedCMSMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_Algorithm(TElSignedAndEnvelopedCMSMessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_BitsInKey(TElSignedAndEnvelopedCMSMessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_BitsInKey(TElSignedAndEnvelopedCMSMessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_UseImplicitContentEncoding(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_UseImplicitContentEncoding(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_UseOAEP(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_UseOAEP(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_get_AlignEncryptedKey(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_set_AlignEncryptedKey(TElSignedAndEnvelopedCMSMessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignedAndEnvelopedCMSMessage_Create(TComponentHandle AOwner, TElSignedAndEnvelopedCMSMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElASN1DirectoryString;
class TElCMSProperty;
class TElCMSHash;
class TElCMSSignerIdentifier;
class TElCMSCertificateRefs;
class TElCMSCRLIdentifier;
class TElCMSCRLValidatedID;
class TElCMSOCSPIdentifier;
class TElCMSOCSPResponsesID;
class TElCMSRevocationRef;
class TElCMSRevocationRefs;
class TElCMSRevocationValues;
class TElCMSContent;
class TElCMSSigPolicyQualifier;
class TElCMSSignaturePolicy;
class TElCMSContentHints;
class TElCMSContentReference;
class TElCMSCommitmentTypeIndication;
class TElCMSSignerLocation;
class TElCMSSigningCertificate;
class TElCMSSignerAttributes;
class TElCMSSignaturePolicyStore;
class TElCMSSignature;
class TElCMSTimestamp;
class TElATSHashIndexProcessor;
class TElSignedCMSMessage;
class TElCMSContentHash;
class TElCMSMessage;
class TElSignedAndEnvelopedCMSMessage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCMSSigningOptions)

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
class TElASN1DirectoryString: public TObject
{
	private:
		SB_DISABLE_COPY(TElASN1DirectoryString)
	public:
		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		virtual TSBASN1DirectoryStringEncoding get_Encoding();

		virtual void set_Encoding(TSBASN1DirectoryStringEncoding Value);

		SB_DECLARE_PROPERTY(TSBASN1DirectoryStringEncoding, get_Encoding, set_Encoding, TElASN1DirectoryString, Encoding);

		TElASN1DirectoryString(TElASN1DirectoryStringHandle handle, TElOwnHandle ownHandle);

		TElASN1DirectoryString();

};
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELCMSPROPERTY
class TElCMSProperty: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSProperty)
	public:
		virtual bool get_Included();

		virtual void set_Included(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Included, set_Included, TElCMSProperty, Included);

		virtual bool get_Signed();

		virtual void set_Signed(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Signed, set_Signed, TElCMSProperty, Signed);

		virtual bool get_RecalculateValue();

		virtual void set_RecalculateValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RecalculateValue, set_RecalculateValue, TElCMSProperty, RecalculateValue);

		virtual void get_RawValue(std::vector<uint8_t> &OutResult);

		TElCMSProperty(TElCMSPropertyHandle handle, TElOwnHandle ownHandle);

		TElCMSProperty();

};
#endif /* SB_USE_CLASS_TELCMSPROPERTY */

#ifdef SB_USE_CLASS_TELCMSHASH
class TElCMSHash: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSHash)
	public:
		void Clear();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElCMSHash, HashAlgorithm);

		virtual void get_HashAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_HashAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_HashValue(std::vector<uint8_t> &OutResult);

		virtual void set_HashValue(const std::vector<uint8_t> &Value);

		TElCMSHash(TElCMSHashHandle handle, TElOwnHandle ownHandle);

		TElCMSHash();

};
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
class TElCMSSignerIdentifier: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSSignerIdentifier)
#ifdef SB_USE_CLASS_TELCMSHASH
		TElCMSHash* _Inst_Hash;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Import(TElX509Certificate &Cert, int32_t HashAlgorithm);

		void Import(TElX509Certificate *Cert, int32_t HashAlgorithm);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void Clear();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool Corresponds(TElX509Certificate &Cert);

		bool Corresponds(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSHASH
		virtual TElCMSHash* get_Hash();

		SB_DECLARE_PROPERTY_GET(TElCMSHash*, get_Hash, TElCMSSignerIdentifier, Hash);
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_Issuer, TElCMSSignerIdentifier, Issuer);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual TSBCMSSignerIdentifierType get_SignerIdentifierType();

		virtual void set_SignerIdentifierType(TSBCMSSignerIdentifierType Value);

		SB_DECLARE_PROPERTY(TSBCMSSignerIdentifierType, get_SignerIdentifierType, set_SignerIdentifierType, TElCMSSignerIdentifier, SignerIdentifierType);

		TElCMSSignerIdentifier(TElCMSSignerIdentifierHandle handle, TElOwnHandle ownHandle);

		TElCMSSignerIdentifier();

		virtual ~TElCMSSignerIdentifier();

};
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
class TElCMSCertificateRefs: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSCertificateRefs)
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
		TElCMSSignerIdentifier* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

		void initInstances();

	public:
		int32_t Add();

		void Remove(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
		virtual TElCMSSignerIdentifier* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElCMSCertificateRefs, CertIDCount);

		TElCMSCertificateRefs(TElCMSCertificateRefsHandle handle, TElOwnHandle ownHandle);

		TElCMSCertificateRefs();

		virtual ~TElCMSCertificateRefs();

};
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
class TElCMSCRLIdentifier: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSCRLIdentifier)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Issuer, TElCMSCRLIdentifier, Issuer);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElCMSCRLIdentifier, Time);

		virtual int32_t get_Number();

		virtual void set_Number(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Number, set_Number, TElCMSCRLIdentifier, Number);

		TElCMSCRLIdentifier(TElCMSCRLIdentifierHandle handle, TElOwnHandle ownHandle);

		TElCMSCRLIdentifier();

		virtual ~TElCMSCRLIdentifier();

};
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
class TElCMSCRLValidatedID: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSCRLValidatedID)
#ifdef SB_USE_CLASS_TELCMSHASH
		TElCMSHash* _Inst_CRLHash;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
		TElCMSCRLIdentifier* _Inst_CRLIdentifier;
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		void Import(TElCertificateRevocationList &CRL, int32_t HashAlgorithm);

		void Import(TElCertificateRevocationList *CRL, int32_t HashAlgorithm);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		bool CRLMatches(TElCertificateRevocationList &CRL);

		bool CRLMatches(TElCertificateRevocationList *CRL);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELCMSHASH
		virtual TElCMSHash* get_CRLHash();

		SB_DECLARE_PROPERTY_GET(TElCMSHash*, get_CRLHash, TElCMSCRLValidatedID, CRLHash);
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSCRLIDENTIFIER
		virtual TElCMSCRLIdentifier* get_CRLIdentifier();

		SB_DECLARE_PROPERTY_GET(TElCMSCRLIdentifier*, get_CRLIdentifier, TElCMSCRLValidatedID, CRLIdentifier);
#endif /* SB_USE_CLASS_TELCMSCRLIDENTIFIER */

		TElCMSCRLValidatedID(TElCMSCRLValidatedIDHandle handle, TElOwnHandle ownHandle);

		TElCMSCRLValidatedID();

		virtual ~TElCMSCRLValidatedID();

};
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */

#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
class TElCMSOCSPIdentifier: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSOCSPIdentifier)
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
		TElOCSPResponderID* _Inst_ResponderID;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

		void initInstances();

	public:
		void Assign(TElCMSOCSPIdentifier &Source);

		void Assign(TElCMSOCSPIdentifier *Source);

		void Clear();

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
		virtual TElOCSPResponderID* get_ResponderID();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponderID*, get_ResponderID, TElCMSOCSPIdentifier, ResponderID);
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

		virtual int64_t get_Time();

		virtual void set_Time(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Time, set_Time, TElCMSOCSPIdentifier, Time);

		TElCMSOCSPIdentifier(TElCMSOCSPIdentifierHandle handle, TElOwnHandle ownHandle);

		TElCMSOCSPIdentifier();

		virtual ~TElCMSOCSPIdentifier();

};
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
class TElCMSOCSPResponsesID: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSOCSPResponsesID)
#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
		TElCMSOCSPIdentifier* _Inst_OCSPIdentifier;
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */
#ifdef SB_USE_CLASS_TELCMSHASH
		TElCMSHash* _Inst_OCSPHash;
#endif /* SB_USE_CLASS_TELCMSHASH */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		void Import(TElOCSPResponse &Response, int32_t HashAlgorithm);

		void Import(TElOCSPResponse *Response, int32_t HashAlgorithm);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		bool OCSPResponseMatches(TElOCSPResponse &Response);

		bool OCSPResponseMatches(TElOCSPResponse *Response);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELCMSOCSPIDENTIFIER
		virtual TElCMSOCSPIdentifier* get_OCSPIdentifier();

		SB_DECLARE_PROPERTY_GET(TElCMSOCSPIdentifier*, get_OCSPIdentifier, TElCMSOCSPResponsesID, OCSPIdentifier);
#endif /* SB_USE_CLASS_TELCMSOCSPIDENTIFIER */

#ifdef SB_USE_CLASS_TELCMSHASH
		virtual TElCMSHash* get_OCSPHash();

		SB_DECLARE_PROPERTY_GET(TElCMSHash*, get_OCSPHash, TElCMSOCSPResponsesID, OCSPHash);
#endif /* SB_USE_CLASS_TELCMSHASH */

		TElCMSOCSPResponsesID(TElCMSOCSPResponsesIDHandle handle, TElOwnHandle ownHandle);

		TElCMSOCSPResponsesID();

		virtual ~TElCMSOCSPResponsesID();

};
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
class TElCMSRevocationRef: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSRevocationRef)
#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
		TElCMSCRLValidatedID* _Inst_CRLIDs;
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */
#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
		TElCMSOCSPResponsesID* _Inst_OCSPIDs;
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

		void initInstances();

	public:
		int32_t AddCRLID();

		int32_t AddOCSPID();

		void RemoveCRLID(int32_t Index);

		void RemoveOCSPID(int32_t Index);

		void ClearCRLIDs();

		void ClearOCSPIDs();

#ifdef SB_USE_CLASS_TLIST
		void Import(TList &CRLList, TList &OCSPList);

		void Import(TList *CRLList, TList *OCSPList);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TLIST
		void Import2(TElMemoryCRLStorage &CRLs, TList &OCSPList);

		void Import2(TElMemoryCRLStorage *CRLs, TList *OCSPList);
#endif /* SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASS_TELCMSCRLVALIDATEDID
		virtual TElCMSCRLValidatedID* get_CRLIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSCRLVALIDATEDID */

#ifdef SB_USE_CLASS_TELCMSOCSPRESPONSESID
		virtual TElCMSOCSPResponsesID* get_OCSPIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSOCSPRESPONSESID */

		virtual int32_t get_CRLIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CRLIDCount, TElCMSRevocationRef, CRLIDCount);

		virtual int32_t get_OCSPIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OCSPIDCount, TElCMSRevocationRef, OCSPIDCount);

		virtual void get_OtherRevType(std::vector<uint8_t> &OutResult);

		virtual void set_OtherRevType(const std::vector<uint8_t> &Value);

		virtual void get_OtherRevRefs(std::vector<uint8_t> &OutResult);

		virtual void set_OtherRevRefs(const std::vector<uint8_t> &Value);

		TElCMSRevocationRef(TElCMSRevocationRefHandle handle, TElOwnHandle ownHandle);

		TElCMSRevocationRef();

		virtual ~TElCMSRevocationRef();

};
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
class TElCMSRevocationRefs: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSRevocationRefs)
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
		TElCMSRevocationRef* _Inst_Refs;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

		void initInstances();

	public:
		int32_t Add();

		void Remove(int32_t Index);

		void Clear();

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREF
		virtual TElCMSRevocationRef* get_Refs(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREF */

		virtual int32_t get_RefCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RefCount, TElCMSRevocationRefs, RefCount);

		virtual bool get_AddASN1ExplicitTagsForEmptyRecords();

		virtual void set_AddASN1ExplicitTagsForEmptyRecords(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AddASN1ExplicitTagsForEmptyRecords, set_AddASN1ExplicitTagsForEmptyRecords, TElCMSRevocationRefs, AddASN1ExplicitTagsForEmptyRecords);

		virtual TSBCMSRevocationRefsWriteMode get_WriteMode();

		virtual void set_WriteMode(TSBCMSRevocationRefsWriteMode Value);

		SB_DECLARE_PROPERTY(TSBCMSRevocationRefsWriteMode, get_WriteMode, set_WriteMode, TElCMSRevocationRefs, WriteMode);

		TElCMSRevocationRefs(TElCMSRevocationRefsHandle handle, TElOwnHandle ownHandle);

		TElCMSRevocationRefs();

		virtual ~TElCMSRevocationRefs();

};
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
class TElCMSRevocationValues: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSRevocationValues)
#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		TElCertificateRevocationList* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		TElOCSPResponse* _Inst_OCSPResponses;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		void initInstances();

	public:
		int32_t AddCRL();

		int32_t AddOCSPResponse();

		void RemoveCRL(int32_t Index);

		void RemoveOCSPResponse(int32_t Index);

		void ClearCRLs();

		void ClearOCSPResponses();

		void Clear();

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		virtual TElCertificateRevocationList* get_CRLs(int32_t Index);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		virtual TElOCSPResponse* get_OCSPResponses(int32_t Index);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		virtual int32_t get_CRLCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CRLCount, TElCMSRevocationValues, CRLCount);

		virtual int32_t get_OCSPResponseCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OCSPResponseCount, TElCMSRevocationValues, OCSPResponseCount);

		virtual void get_OtherRevType(std::vector<uint8_t> &OutResult);

		virtual void set_OtherRevType(const std::vector<uint8_t> &Value);

		virtual void get_OtherRevValues(std::vector<uint8_t> &OutResult);

		virtual void set_OtherRevValues(const std::vector<uint8_t> &Value);

		TElCMSRevocationValues(TElCMSRevocationValuesHandle handle, TElOwnHandle ownHandle);

		TElCMSRevocationValues();

		virtual ~TElCMSRevocationValues();

};
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELCMSCONTENT
class TElCMSContent: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSContent)
#ifdef SB_USE_CLASS_TELCMSHASH
		TElCMSHash* _Inst_KnownHashes;
#endif /* SB_USE_CLASS_TELCMSHASH */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		void Init(TStream &Stream, int64_t Offset, int64_t Size);

		void Init(TStream *Stream, int64_t Offset, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

		void Init(void * Buffer, int32_t Size);

		int32_t Read(void * Buffer, int32_t Size, int64_t Offset);

		int32_t AddKnownHash();

		int32_t AddKnownHash(int32_t AlgID, const std::vector<uint8_t> &HashAlgParams, const std::vector<uint8_t> &Hash);

		void RemoveKnownHash(int32_t Index);

		void ClearKnownHashes();

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElCMSContent, Size);

		virtual bool get_ContentIsHash();

		virtual void set_ContentIsHash(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ContentIsHash, set_ContentIsHash, TElCMSContent, ContentIsHash);

		virtual void get_RawContent(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELCMSHASH
		virtual TElCMSHash* get_KnownHashes(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSHASH */

		virtual int32_t get_KnownHashCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KnownHashCount, TElCMSContent, KnownHashCount);

		TElCMSContent(TElCMSContentHandle handle, TElOwnHandle ownHandle);

		TElCMSContent();

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDDATA
		explicit TElCMSContent(TElPKCS7SignedData &Data);

		explicit TElCMSContent(TElPKCS7SignedData *Data);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDDATA */

#ifdef SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA
		explicit TElCMSContent(TElPKCS7SignedAndEnvelopedData &Data);

		explicit TElCMSContent(TElPKCS7SignedAndEnvelopedData *Data);
#endif /* SB_USE_CLASS_TELPKCS7SIGNEDANDENVELOPEDDATA */

		virtual ~TElCMSContent();

};
#endif /* SB_USE_CLASS_TELCMSCONTENT */

#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
class TElCMSSigPolicyQualifier: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSSigPolicyQualifier)
	public:
		void Clear();

		int32_t AddNoticeNumber();

		void RemoveNoticeNumber(int32_t Index);

		void ClearNoticeNumbers();

		virtual void get_ID(std::vector<uint8_t> &OutResult);

		virtual void set_ID(const std::vector<uint8_t> &Value);

		virtual TSBSigPolicyQualifierType get_QualifierType();

		virtual void set_QualifierType(TSBSigPolicyQualifierType Value);

		SB_DECLARE_PROPERTY(TSBSigPolicyQualifierType, get_QualifierType, set_QualifierType, TElCMSSigPolicyQualifier, QualifierType);

		virtual void get_URI(std::string &OutResult);

		virtual void set_URI(const std::string &Value);

		virtual void get_ExplicitText(std::string &OutResult);

		virtual void set_ExplicitText(const std::string &Value);

		virtual void get_Organization(std::string &OutResult);

		virtual void set_Organization(const std::string &Value);

		virtual void get_CustomData(std::vector<uint8_t> &OutResult);

		virtual void set_CustomData(const std::vector<uint8_t> &Value);

		virtual int32_t get_NoticeNumbers(int32_t Index);

		virtual void set_NoticeNumbers(int32_t Index, int32_t Value);

		virtual int32_t get_NoticeNumberCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_NoticeNumberCount, TElCMSSigPolicyQualifier, NoticeNumberCount);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElCMSSigPolicyQualifier, UseUTF8);

		TElCMSSigPolicyQualifier(TElCMSSigPolicyQualifierHandle handle, TElOwnHandle ownHandle);

		TElCMSSigPolicyQualifier();

};
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
class TElCMSSignaturePolicy: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSSignaturePolicy)
#ifdef SB_USE_CLASS_TELCMSHASH
		TElCMSHash* _Inst_PolicyHash;
#endif /* SB_USE_CLASS_TELCMSHASH */
#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
		TElCMSSigPolicyQualifier* _Inst_Qualifiers;
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

		void initInstances();

	public:
		int32_t AddQualifier();

		void RemoveQualifier(int32_t Index);

		void ClearQualifiers();

		void Clear();

		virtual void get_PolicyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_PolicyIdentifier(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCMSHASH
		virtual TElCMSHash* get_PolicyHash();

		SB_DECLARE_PROPERTY_GET(TElCMSHash*, get_PolicyHash, TElCMSSignaturePolicy, PolicyHash);
#endif /* SB_USE_CLASS_TELCMSHASH */

#ifdef SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER
		virtual TElCMSSigPolicyQualifier* get_Qualifiers(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSSIGPOLICYQUALIFIER */

		virtual int32_t get_QualifierCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_QualifierCount, TElCMSSignaturePolicy, QualifierCount);

		virtual bool get_Implied();

		virtual void set_Implied(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Implied, set_Implied, TElCMSSignaturePolicy, Implied);

		TElCMSSignaturePolicy(TElCMSSignaturePolicyHandle handle, TElOwnHandle ownHandle);

		TElCMSSignaturePolicy();

		virtual ~TElCMSSignaturePolicy();

};
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */

#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
class TElCMSContentHints: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSContentHints)
	public:
		virtual void get_ContentDescription(std::string &OutResult);

		virtual void set_ContentDescription(const std::string &Value);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		TElCMSContentHints(TElCMSContentHintsHandle handle, TElOwnHandle ownHandle);

		TElCMSContentHints();

};
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */

#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
class TElCMSContentReference: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSContentReference)
	public:
		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual void get_ContentIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_ContentIdentifier(const std::vector<uint8_t> &Value);

		virtual void get_OriginatorSignatureValue(std::vector<uint8_t> &OutResult);

		virtual void set_OriginatorSignatureValue(const std::vector<uint8_t> &Value);

		TElCMSContentReference(TElCMSContentReferenceHandle handle, TElOwnHandle ownHandle);

		TElCMSContentReference();

};
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */

#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
class TElCMSCommitmentTypeIndication: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSCommitmentTypeIndication)
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		TElByteArrayList* _Inst_CustomIdentifiers;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		void initInstances();

	public:
		void Clear();

		virtual bool get_ProofOfOrigin();

		virtual void set_ProofOfOrigin(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfOrigin, set_ProofOfOrigin, TElCMSCommitmentTypeIndication, ProofOfOrigin);

		virtual bool get_ProofOfReceipt();

		virtual void set_ProofOfReceipt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfReceipt, set_ProofOfReceipt, TElCMSCommitmentTypeIndication, ProofOfReceipt);

		virtual bool get_ProofOfDelivery();

		virtual void set_ProofOfDelivery(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfDelivery, set_ProofOfDelivery, TElCMSCommitmentTypeIndication, ProofOfDelivery);

		virtual bool get_ProofOfSender();

		virtual void set_ProofOfSender(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfSender, set_ProofOfSender, TElCMSCommitmentTypeIndication, ProofOfSender);

		virtual bool get_ProofOfApproval();

		virtual void set_ProofOfApproval(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfApproval, set_ProofOfApproval, TElCMSCommitmentTypeIndication, ProofOfApproval);

		virtual bool get_ProofOfCreation();

		virtual void set_ProofOfCreation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ProofOfCreation, set_ProofOfCreation, TElCMSCommitmentTypeIndication, ProofOfCreation);

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
		virtual TElByteArrayList* get_CustomIdentifiers();

		SB_DECLARE_PROPERTY_GET(TElByteArrayList*, get_CustomIdentifiers, TElCMSCommitmentTypeIndication, CustomIdentifiers);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

		TElCMSCommitmentTypeIndication(TElCMSCommitmentTypeIndicationHandle handle, TElOwnHandle ownHandle);

		TElCMSCommitmentTypeIndication();

		virtual ~TElCMSCommitmentTypeIndication();

};
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
class TElCMSSignerLocation: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSSignerLocation)
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		TElASN1DirectoryString* _Inst_CountryName;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		TElASN1DirectoryString* _Inst_LocalityName;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */
#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		TElASN1DirectoryString* _Inst_PostalAddressLines;
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

		void initInstances();

	public:
		void Clear();

		int32_t AddPostalAddressLine();

		void RemovePostalAddressLine(int32_t Index);

		void ClearPostalAddressLines();

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		virtual TElASN1DirectoryString* get_CountryName();

		SB_DECLARE_PROPERTY_GET(TElASN1DirectoryString*, get_CountryName, TElCMSSignerLocation, CountryName);
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		virtual TElASN1DirectoryString* get_LocalityName();

		SB_DECLARE_PROPERTY_GET(TElASN1DirectoryString*, get_LocalityName, TElCMSSignerLocation, LocalityName);
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

#ifdef SB_USE_CLASS_TELASN1DIRECTORYSTRING
		virtual TElASN1DirectoryString* get_PostalAddressLines(int32_t Index);
#endif /* SB_USE_CLASS_TELASN1DIRECTORYSTRING */

		virtual int32_t get_PostalAddressLineCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PostalAddressLineCount, TElCMSSignerLocation, PostalAddressLineCount);

		TElCMSSignerLocation(TElCMSSignerLocationHandle handle, TElOwnHandle ownHandle);

		TElCMSSignerLocation();

		virtual ~TElCMSSignerLocation();

};
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */

#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
class TElCMSSigningCertificate: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSSigningCertificate)
#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
		TElCMSSignerIdentifier* _Inst_CertIDs;
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

		void initInstances();

	public:
		void Clear();

		int32_t AddCertID();

		void RemoveCertID(int32_t Index);

		void ClearCertIDs();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool Corresponds(TElX509Certificate &Cert);

		bool Corresponds(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSSIGNERIDENTIFIER
		virtual TElCMSSignerIdentifier* get_CertIDs(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSSIGNERIDENTIFIER */

		virtual int32_t get_CertIDCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertIDCount, TElCMSSigningCertificate, CertIDCount);

		virtual TSBCMSSigningCertificateType get_SigningCertificateType();

		virtual void set_SigningCertificateType(TSBCMSSigningCertificateType Value);

		SB_DECLARE_PROPERTY(TSBCMSSigningCertificateType, get_SigningCertificateType, set_SigningCertificateType, TElCMSSigningCertificate, SigningCertificateType);

		TElCMSSigningCertificate(TElCMSSigningCertificateHandle handle, TElOwnHandle ownHandle);

		TElCMSSigningCertificate();

		virtual ~TElCMSSigningCertificate();

};
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */

#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
class TElCMSSignerAttributes: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSSignerAttributes)
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_ClaimedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_SignedAssertions;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_ClaimedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_ClaimedAttributes, TElCMSSignerAttributes, ClaimedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual void get_CertifiedAttributesBinary(std::vector<uint8_t> &OutResult);

		virtual void set_CertifiedAttributesBinary(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_SignedAssertions();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_SignedAssertions, TElCMSSignerAttributes, SignedAssertions);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual TSBCMSSignerAttributesVersion get_Version();

		virtual void set_Version(TSBCMSSignerAttributesVersion Value);

		SB_DECLARE_PROPERTY(TSBCMSSignerAttributesVersion, get_Version, set_Version, TElCMSSignerAttributes, Version);

		virtual void get_AttributeCertificateType(std::vector<uint8_t> &OutResult);

		virtual void set_AttributeCertificateType(const std::vector<uint8_t> &Value);

		TElCMSSignerAttributes(TElCMSSignerAttributesHandle handle, TElOwnHandle ownHandle);

		TElCMSSignerAttributes();

		virtual ~TElCMSSignerAttributes();

};
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
class TElCMSSignaturePolicyStore: public TElCMSProperty
{
	private:
		SB_DISABLE_COPY(TElCMSSignaturePolicyStore)
	public:
		void Clear();

		virtual void get_DocSpecOID(std::vector<uint8_t> &OutResult);

		virtual void set_DocSpecOID(const std::vector<uint8_t> &Value);

		virtual void get_DocSpecURI(std::string &OutResult);

		virtual void set_DocSpecURI(const std::string &Value);

		virtual void get_EncodedPolicyDocument(std::vector<uint8_t> &OutResult);

		virtual void set_EncodedPolicyDocument(const std::vector<uint8_t> &Value);

		virtual void get_PolicyLocalURI(std::string &OutResult);

		virtual void set_PolicyLocalURI(const std::string &Value);

		virtual TSBCMSSignaturePolicyStoreType get_PolicyStoreType();

		virtual void set_PolicyStoreType(TSBCMSSignaturePolicyStoreType Value);

		SB_DECLARE_PROPERTY(TSBCMSSignaturePolicyStoreType, get_PolicyStoreType, set_PolicyStoreType, TElCMSSignaturePolicyStore, PolicyStoreType);

		TElCMSSignaturePolicyStore(TElCMSSignaturePolicyStoreHandle handle, TElOwnHandle ownHandle);

		TElCMSSignaturePolicyStore();

};
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
class TElCMSSignature: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSSignature)
#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		TElPKCS7Issuer* _Inst_Signer;
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_CustomSignedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_CustomUnsignedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
		TElCMSSignature* _Inst_Countersignatures;
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		TElCMSTimestamp* _Inst_Timestamps;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		TElCMSTimestamp* _Inst_ContentTimestamps;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		TElCMSTimestamp* _Inst_ValidationTimestamps;
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
		TElCMSSignaturePolicy* _Inst_SignaturePolicy;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */
#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
		TElCMSContentHints* _Inst_ContentHints;
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */
#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
		TElCMSContentReference* _Inst_ContentReference;
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */
#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
		TElCMSCommitmentTypeIndication* _Inst_CommitmentTypeIndication;
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */
#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
		TElCMSSignerLocation* _Inst_SignerLocation;
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */
#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
		TElCMSSigningCertificate* _Inst_SigningCertificate;
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */
#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
		TElCMSCertificateRefs* _Inst_CertificateRefs;
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertificateValues;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
		TElCMSRevocationRefs* _Inst_RevocationRefs;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */
#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
		TElCMSRevocationValues* _Inst_RevocationValues;
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */
#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
		TElCMSSignerAttributes* _Inst_SignerAttributes;
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */
#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
		TElCMSSignaturePolicyStore* _Inst_SignaturePolicyStore;
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

		void initInstances();

	public:
		void Assign(TElCMSSignature &Source);

		void Assign(TElCMSSignature *Source);

		int32_t AddCountersignature();

		int32_t AddCountersignature(const std::vector<uint8_t> &Signature);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddTimestamp(TElCustomTSPClient &TSPClient);

		int32_t AddTimestamp(TElCustomTSPClient *TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		int32_t AddTimestamp(const std::vector<uint8_t> &Timestamp);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddContentTimestamp(TElCustomTSPClient &TSPClient);

		int32_t AddContentTimestamp(TElCustomTSPClient *TSPClient);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

		int32_t AddContentTimestamp(const std::vector<uint8_t> &Timestamp);

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
		int32_t AddValidationTimestamp(TElCustomTSPClient &TSPClient, TSBCMSTimestampType TimestampType);

		int32_t AddValidationTimestamp(TElCustomTSPClient *TSPClient, TSBCMSTimestampType TimestampType);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST
		void AddCompleteValidationData(TElCustomCertStorage &Chain, TElMemoryCRLStorage &CRLs, TList &OCSPResponses, bool ReferencesOnly);

		void AddCompleteValidationData(TElCustomCertStorage *Chain, TElMemoryCRLStorage *CRLs, TList *OCSPResponses, bool ReferencesOnly);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST */

#ifdef SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TELX509CERTIFICATE_AND_TLIST
		void AddCompleteValidationDataItem(TElX509Certificate &Cert, TElMemoryCRLStorage &CRLs, TList &OCSPResponses, bool ReferencesOnly);

		void AddCompleteValidationDataItem(TElX509Certificate *Cert, TElMemoryCRLStorage *CRLs, TList *OCSPResponses, bool ReferencesOnly);
#endif /* SB_USE_CLASSES_TELMEMORYCRLSTORAGE_AND_TELX509CERTIFICATE_AND_TLIST */

		void RemoveCountersignature(int32_t Index);

		void RemoveTimestamp(int32_t Index);

		void RemoveContentTimestamp(int32_t Index);

		void RemoveValidationTimestamp(int32_t Index);

		void ClearCountersignatures();

		void ClearTimestamps();

		void ClearContentTimestamps();

		void ClearValidationTimestamps();

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
		void Sign(TElX509Certificate &Cert, TElCustomCertStorage &Chain);

		void Sign(TElX509Certificate *Cert, TElCustomCertStorage *Chain);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
		void SignRemote(TElX509Certificate &Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, void * Param, TElCustomCertStorage &Chain);

		void SignRemote(TElX509Certificate *Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, void * Param, TElCustomCertStorage *Chain);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE
		void SignRemote(TElX509Certificate &Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, bool ExternalHashCalculation, void * Param, TElCustomCertStorage &Chain);

		void SignRemote(TElX509Certificate *Cert, TSBCMSRemoteSignCallback pMethodSignCallback, void * pDataSignCallback, bool ExternalHashCalculation, void * Param, TElCustomCertStorage *Chain);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATE */

		TSBCMSSignatureValidity Validate();

		TSBCMSAdvancedSignatureValidity Validate(TSBCMSValidationOptions Options);

#ifdef SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR
		TSBCMSAdvancedSignatureValidity Validate(TElX509CertificateValidator &Validator, TSBCMSValidationOptions Options);

		TSBCMSAdvancedSignatureValidity Validate(TElX509CertificateValidator *Validator, TSBCMSValidationOptions Options);
#endif /* SB_USE_CLASS_TELX509CERTIFICATEVALIDATOR */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
		TElSignedCMSMessageHandle GetSignedCMSMessage();
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELX509CERTIFICATE
		void InitiateAsyncSign(TElX509Certificate &Cert, TElCustomCertStorage &Chain, TElDCAsyncState &State);

		void InitiateAsyncSign(TElX509Certificate *Cert, TElCustomCertStorage *Chain, TElDCAsyncState &State);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELDCASYNCSTATE_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		void InitiateAsyncSign(TElDCAsyncState &State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		void InitiateAsyncSign(TSBDCAsyncSignMethod AsyncSignMethod, TElDCAsyncState &State);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		void CompleteAsyncSign(TElDCAsyncState &AsyncState);

		void CompleteAsyncSign(TElDCAsyncState *AsyncState);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

		void UpdateCMS();

		virtual void get_Content(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELPKCS7ISSUER
		virtual TElPKCS7Issuer* get_Signer();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Issuer*, get_Signer, TElCMSSignature, Signer);
#endif /* SB_USE_CLASS_TELPKCS7ISSUER */

		virtual int32_t get_DigestAlgorithm();

		virtual void set_DigestAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DigestAlgorithm, set_DigestAlgorithm, TElCMSSignature, DigestAlgorithm);

		virtual void get_EncryptedDigest(std::vector<uint8_t> &OutResult);

		virtual int32_t get_PublicKeyAlgorithm();

		virtual void set_PublicKeyAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PublicKeyAlgorithm, set_PublicKeyAlgorithm, TElCMSSignature, PublicKeyAlgorithm);

		virtual int32_t get_FingerprintAlgorithm();

		virtual void set_FingerprintAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FingerprintAlgorithm, set_FingerprintAlgorithm, TElCMSSignature, FingerprintAlgorithm);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_CustomSignedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_CustomSignedAttributes, TElCMSSignature, CustomSignedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_CustomUnsignedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_CustomUnsignedAttributes, TElCMSSignature, CustomUnsignedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual bool get_SignedAttributesPresent();

		SB_DECLARE_PROPERTY_GET(bool, get_SignedAttributesPresent, TElCMSSignature, SignedAttributesPresent);

		virtual int32_t get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureAlgorithm, TElCMSSignature, SignatureAlgorithm);

		virtual TElCMSSignature* get_Countersignatures(int32_t Index);

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		virtual TElCMSTimestamp* get_Timestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		virtual TElCMSTimestamp* get_ContentTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
		virtual TElCMSTimestamp* get_ValidationTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

		virtual int32_t get_CountersignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CountersignatureCount, TElCMSSignature, CountersignatureCount);

		virtual int32_t get_TimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TimestampCount, TElCMSSignature, TimestampCount);

		virtual int32_t get_ContentTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ContentTimestampCount, TElCMSSignature, ContentTimestampCount);

		virtual TSBCMSAdvancedSignatureValidity get_LastValidationResult();

		SB_DECLARE_PROPERTY_GET(TSBCMSAdvancedSignatureValidity, get_LastValidationResult, TElCMSSignature, LastValidationResult);

		virtual TSBCertificateValidity get_LastValidatorValidity();

		SB_DECLARE_PROPERTY_GET(TSBCertificateValidity, get_LastValidatorValidity, TElCMSSignature, LastValidatorValidity);

		virtual TSBCertificateValidityReason get_LastValidatorReason();

		SB_DECLARE_PROPERTY_GET(TSBCertificateValidityReason, get_LastValidatorReason, TElCMSSignature, LastValidatorReason);

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElCMSSignature, SigningTime);

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICY
		virtual TElCMSSignaturePolicy* get_SignaturePolicy();

		SB_DECLARE_PROPERTY_GET(TElCMSSignaturePolicy*, get_SignaturePolicy, TElCMSSignature, SignaturePolicy);
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICY */

#ifdef SB_USE_CLASS_TELCMSCONTENTHINTS
		virtual TElCMSContentHints* get_ContentHints();

		SB_DECLARE_PROPERTY_GET(TElCMSContentHints*, get_ContentHints, TElCMSSignature, ContentHints);
#endif /* SB_USE_CLASS_TELCMSCONTENTHINTS */

		virtual void get_ContentIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_ContentIdentifier(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCMSCONTENTREFERENCE
		virtual TElCMSContentReference* get_ContentReference();

		SB_DECLARE_PROPERTY_GET(TElCMSContentReference*, get_ContentReference, TElCMSSignature, ContentReference);
#endif /* SB_USE_CLASS_TELCMSCONTENTREFERENCE */

#ifdef SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION
		virtual TElCMSCommitmentTypeIndication* get_CommitmentTypeIndication();

		virtual void set_CommitmentTypeIndication(TElCMSCommitmentTypeIndication &Value);

		virtual void set_CommitmentTypeIndication(TElCMSCommitmentTypeIndication *Value);

		SB_DECLARE_PROPERTY(TElCMSCommitmentTypeIndication*, get_CommitmentTypeIndication, set_CommitmentTypeIndication, TElCMSSignature, CommitmentTypeIndication);
#endif /* SB_USE_CLASS_TELCMSCOMMITMENTTYPEINDICATION */

#ifdef SB_USE_CLASS_TELCMSSIGNERLOCATION
		virtual TElCMSSignerLocation* get_SignerLocation();

		SB_DECLARE_PROPERTY_GET(TElCMSSignerLocation*, get_SignerLocation, TElCMSSignature, SignerLocation);
#endif /* SB_USE_CLASS_TELCMSSIGNERLOCATION */

#ifdef SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE
		virtual TElCMSSigningCertificate* get_SigningCertificate();

		SB_DECLARE_PROPERTY_GET(TElCMSSigningCertificate*, get_SigningCertificate, TElCMSSignature, SigningCertificate);
#endif /* SB_USE_CLASS_TELCMSSIGNINGCERTIFICATE */

		virtual void get_MessageDigest(std::vector<uint8_t> &OutResult);

		virtual void get_MimeType(std::string &OutResult);

		virtual void set_MimeType(const std::string &Value);

#ifdef SB_USE_CLASS_TELCMSCERTIFICATEREFS
		virtual TElCMSCertificateRefs* get_CertificateRefs();

		SB_DECLARE_PROPERTY_GET(TElCMSCertificateRefs*, get_CertificateRefs, TElCMSSignature, CertificateRefs);
#endif /* SB_USE_CLASS_TELCMSCERTIFICATEREFS */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertificateValues();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_CertificateValues, TElCMSSignature, CertificateValues);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONREFS
		virtual TElCMSRevocationRefs* get_RevocationRefs();

		SB_DECLARE_PROPERTY_GET(TElCMSRevocationRefs*, get_RevocationRefs, TElCMSSignature, RevocationRefs);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONREFS */

#ifdef SB_USE_CLASS_TELCMSREVOCATIONVALUES
		virtual TElCMSRevocationValues* get_RevocationValues();

		SB_DECLARE_PROPERTY_GET(TElCMSRevocationValues*, get_RevocationValues, TElCMSSignature, RevocationValues);
#endif /* SB_USE_CLASS_TELCMSREVOCATIONVALUES */

#ifdef SB_USE_CLASS_TELCMSSIGNERATTRIBUTES
		virtual TElCMSSignerAttributes* get_SignerAttributes();

		SB_DECLARE_PROPERTY_GET(TElCMSSignerAttributes*, get_SignerAttributes, TElCMSSignature, SignerAttributes);
#endif /* SB_USE_CLASS_TELCMSSIGNERATTRIBUTES */

#ifdef SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE
		virtual TElCMSSignaturePolicyStore* get_SignaturePolicyStore();

		SB_DECLARE_PROPERTY_GET(TElCMSSignaturePolicyStore*, get_SignaturePolicyStore, TElCMSSignature, SignaturePolicyStore);
#endif /* SB_USE_CLASS_TELCMSSIGNATUREPOLICYSTORE */

		virtual int32_t get_ValidationTimestampCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ValidationTimestampCount, TElCMSSignature, ValidationTimestampCount);

		virtual TSBCMSSignatureState get_State();

		SB_DECLARE_PROPERTY_GET(TSBCMSSignatureState, get_State, TElCMSSignature, State);

		virtual TSBCMSSigningOptions get_SigningOptions();

		virtual void set_SigningOptions(TSBCMSSigningOptions Value);

		SB_DECLARE_PROPERTY(TSBCMSSigningOptions, get_SigningOptions, set_SigningOptions, TElCMSSignature, SigningOptions);

		virtual bool get_UsePSS();

		virtual void set_UsePSS(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePSS, set_UsePSS, TElCMSSignature, UsePSS);

		virtual bool get_UseCachedDigests();

		virtual void set_UseCachedDigests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCachedDigests, set_UseCachedDigests, TElCMSSignature, UseCachedDigests);

		virtual bool get_LiberalMode();

		virtual void set_LiberalMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_LiberalMode, set_LiberalMode, TElCMSSignature, LiberalMode);

		virtual bool get_AuthenticodeMode();

		virtual void set_AuthenticodeMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AuthenticodeMode, set_AuthenticodeMode, TElCMSSignature, AuthenticodeMode);

		virtual void get_OnBeforeSign(TSBCMSBeforeSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBCMSBeforeSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeVerify(TSBCMSBeforeVerifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeVerify(TSBCMSBeforeVerifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeeded(TSBCMSCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnIsCertificateTrusted(TSBCMSCertificateTrustedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnIsCertificateTrusted(TSBCMSCertificateTrustedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCRLNeeded(TSBCMSCRLNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCRLNeeded(TSBCMSCRLNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnOCSPResponseNeeded(TSBCMSOCSPResponseNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOCSPResponseNeeded(TSBCMSOCSPResponseNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnItemValidated(TSBCMSItemValidatedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnItemValidated(TSBCMSItemValidatedEvent pMethodValue, void * pDataValue);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElCMSSignature(TElCMSSignatureHandle handle, TElOwnHandle ownHandle);

		explicit TElCMSSignature(TObject &Subject);

		explicit TElCMSSignature(TObject *Subject);

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		TElCMSSignature(TObject &Subject, TElPKCS7Signer &PKCS7Signer);

		TElCMSSignature(TObject *Subject, TElPKCS7Signer *PKCS7Signer);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

		TElCMSSignature(TObject &Subject, const std::vector<uint8_t> &Data);

		TElCMSSignature(TObject *Subject, const std::vector<uint8_t> &Data);

		virtual ~TElCMSSignature();

};
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

#ifdef SB_USE_CLASS_TELCMSTIMESTAMP
class TElCMSTimestamp: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSTimestamp)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		TElOCSPResponseStorage* _Inst_OCSPResponses;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
		TElCMSSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_Info;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		void initInstances();

	public:
		bool Validate();

		void UpdateCMS();

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_Certificates, TElCMSTimestamp, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_CRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_CRLs, TElCMSTimestamp, CRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		virtual TElOCSPResponseStorage* get_OCSPResponses();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponseStorage*, get_OCSPResponses, TElCMSTimestamp, OCSPResponses);
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
		virtual TElCMSSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElCMSTimestamp, SignatureCount);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_Info();

		SB_DECLARE_PROPERTY_GET(TElClientTSPInfo*, get_Info, TElCMSTimestamp, Info);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual TSBCMSTimestampType get_TimestampType();

		SB_DECLARE_PROPERTY_GET(TSBCMSTimestampType, get_TimestampType, TElCMSTimestamp, TimestampType);

		virtual bool get_UseCachedDigests();

		virtual void set_UseCachedDigests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCachedDigests, set_UseCachedDigests, TElCMSTimestamp, UseCachedDigests);

		virtual void get_DigestCalcType(std::string &OutResult);

		virtual void get_CMS(std::vector<uint8_t> &OutResult);

		TElCMSTimestamp(TElCMSTimestampHandle handle, TElOwnHandle ownHandle);

		explicit TElCMSTimestamp(TObject &Subject);

		explicit TElCMSTimestamp(TObject *Subject);

		TElCMSTimestamp(TObject &Subject, const std::vector<uint8_t> &Data);

		TElCMSTimestamp(TObject *Subject, const std::vector<uint8_t> &Data);

		virtual ~TElCMSTimestamp();

};
#endif /* SB_USE_CLASS_TELCMSTIMESTAMP */

#ifdef SB_USE_CLASS_TELATSHASHINDEXPROCESSOR
class TElATSHashIndexProcessor: public TObject
{
	private:
		SB_DISABLE_COPY(TElATSHashIndexProcessor)
	public:
		void Clear();

		void Load(const std::vector<uint8_t> &Buffer, int32_t StartIndex, int32_t Count);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool CertPresent(TElX509Certificate &Cert);

		bool CertPresent(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
		bool CRLPresent(TElCertificateRevocationList &Crl);

		bool CRLPresent(TElCertificateRevocationList *Crl);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		bool OCSPResponsePresent(TElOCSPResponse &OcspResponse);

		bool OCSPResponsePresent(TElOCSPResponse *OcspResponse);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		virtual void get_CertHashes(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual int32_t get_CertHashesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CertHashesCount, TElATSHashIndexProcessor, CertHashesCount);

		virtual void get_RevInfoHashes(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual int32_t get_RevInfoHashesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RevInfoHashesCount, TElATSHashIndexProcessor, RevInfoHashesCount);

		virtual void get_AttributeHashes(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual int32_t get_AttributeHashesCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AttributeHashesCount, TElATSHashIndexProcessor, AttributeHashesCount);

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElATSHashIndexProcessor, HashAlgorithm);

		TElATSHashIndexProcessor(TElATSHashIndexProcessorHandle handle, TElOwnHandle ownHandle);

		TElATSHashIndexProcessor();

};
#endif /* SB_USE_CLASS_TELATSHASHINDEXPROCESSOR */

#ifdef SB_USE_CLASS_TELCMSMESSAGE
class TElCMSMessage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCMSMessage)
#ifdef SB_USE_CLASS_TELCMSCONTENT
		TElCMSContent* _Inst_Content;
#endif /* SB_USE_CLASS_TELCMSCONTENT */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		void CreateNew(TStream &DataStream, int64_t Offset, int64_t Size);

		void CreateNew(TStream *DataStream, int64_t Offset, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

		void CreateNew(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &CMSStream, TStream &DataStream, int64_t CMSCount, int64_t DataCount);

		void Open(TStream *CMSStream, TStream *DataStream, int64_t CMSCount, int64_t DataCount);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Save(TStream &DestStream);

		void Save(TStream *DestStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Close();

#ifdef SB_USE_CLASS_TELCMSCONTENT
		virtual TElCMSContent* get_Content();

		SB_DECLARE_PROPERTY_GET(TElCMSContent*, get_Content, TElCMSMessage, Content);
#endif /* SB_USE_CLASS_TELCMSCONTENT */

		virtual bool get_Detached();

		virtual void set_Detached(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Detached, set_Detached, TElCMSMessage, Detached);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElCMSMessage, UseUndefSize);

		TElCMSMessage(TElCMSMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElCMSMessage(TComponent &AOwner);

		explicit TElCMSMessage(TComponent *AOwner);

		virtual ~TElCMSMessage();

};
#endif /* SB_USE_CLASS_TELCMSMESSAGE */

#ifdef SB_USE_CLASS_TELCMSCONTENTHASH
class TElCMSContentHash: public TObject
{
	private:
		SB_DISABLE_COPY(TElCMSContentHash)
	public:
		void Clear();

		void GetHash(int32_t Alg, std::vector<uint8_t> &OutResult);

		void SetHash(int32_t Alg, const std::vector<uint8_t> &Value);

		TElCMSContentHash(TElCMSContentHashHandle handle, TElOwnHandle ownHandle);

		TElCMSContentHash();

};
#endif /* SB_USE_CLASS_TELCMSCONTENTHASH */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
class TElSignedCMSMessage: public TElCMSMessage
{
	private:
		SB_DISABLE_COPY(TElSignedCMSMessage)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		TElOCSPResponseStorage* _Inst_OCSPResponses;
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */
#ifdef SB_USE_CLASS_TELCMSSIGNATURE
		TElCMSSignature* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		int32_t AddSignature();

		void RemoveSignature(int32_t Index);

		void ClearSignatures();

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void ExtractAllCertificates(TElCustomCertStorage &Storage);

		void ExtractAllCertificates(TElCustomCertStorage *Storage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST
		void ExtractAllValidationElements(TElCustomCertStorage &Storage, TElMemoryCRLStorage &Crls, TList &Ocsps);

		void ExtractAllValidationElements(TElCustomCertStorage *Storage, TElMemoryCRLStorage *Crls, TList *Ocsps);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELMEMORYCRLSTORAGE_AND_TLIST */

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual int32_t get_ContentVersion();

		virtual void set_ContentVersion(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ContentVersion, set_ContentVersion, TElSignedCMSMessage, ContentVersion);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_Certificates, TElSignedCMSMessage, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_CRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_CRLs, TElSignedCMSMessage, CRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE
		virtual TElOCSPResponseStorage* get_OCSPResponses();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponseStorage*, get_OCSPResponses, TElSignedCMSMessage, OCSPResponses);
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

#ifdef SB_USE_CLASS_TELCMSSIGNATURE
		virtual TElCMSSignature* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELCMSSIGNATURE */

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElSignedCMSMessage, SignatureCount);

		virtual bool get_UseImplicitContent();

		virtual void set_UseImplicitContent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseImplicitContent, set_UseImplicitContent, TElSignedCMSMessage, UseImplicitContent);

		virtual bool get_SerializeContentOnUpdate();

		virtual void set_SerializeContentOnUpdate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SerializeContentOnUpdate, set_SerializeContentOnUpdate, TElSignedCMSMessage, SerializeContentOnUpdate);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSignedCMSMessage, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		TElSignedCMSMessage(TElSignedCMSMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElSignedCMSMessage(TComponent &AOwner);

		explicit TElSignedCMSMessage(TComponent *AOwner);

		virtual ~TElSignedCMSMessage();

};
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

#ifdef SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE
class TElSignedAndEnvelopedCMSMessage: public TElSignedCMSMessage
{
	private:
		SB_DISABLE_COPY(TElSignedAndEnvelopedCMSMessage)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Recipients;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSignedAndEnvelopedCMSMessage, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Recipients();

		virtual void set_Recipients(TElCustomCertStorage &Value);

		virtual void set_Recipients(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_Recipients, set_Recipients, TElSignedAndEnvelopedCMSMessage, Recipients);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElSignedAndEnvelopedCMSMessage, Algorithm);

		virtual int32_t get_BitsInKey();

		virtual void set_BitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BitsInKey, set_BitsInKey, TElSignedAndEnvelopedCMSMessage, BitsInKey);

		virtual bool get_UseImplicitContentEncoding();

		virtual void set_UseImplicitContentEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseImplicitContentEncoding, set_UseImplicitContentEncoding, TElSignedAndEnvelopedCMSMessage, UseImplicitContentEncoding);

		virtual bool get_UseOAEP();

		virtual void set_UseOAEP(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseOAEP, set_UseOAEP, TElSignedAndEnvelopedCMSMessage, UseOAEP);

		virtual bool get_AlignEncryptedKey();

		virtual void set_AlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedKey, set_AlignEncryptedKey, TElSignedAndEnvelopedCMSMessage, AlignEncryptedKey);

		TElSignedAndEnvelopedCMSMessage(TElSignedAndEnvelopedCMSMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElSignedAndEnvelopedCMSMessage(TComponent &AOwner);

		explicit TElSignedAndEnvelopedCMSMessage(TComponent *AOwner);

		virtual ~TElSignedAndEnvelopedCMSMessage();

};
#endif /* SB_USE_CLASS_TELSIGNEDANDENVELOPEDCMSMESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_CMS

void GetTimestampTypeOID(TSBCMSTimestampType TimestampType, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_CMS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CMS
SB_IMPORT uint32_t SB_APIENTRY SBCMS_GetTimestampTypeOID(TSBCMSTimestampTypeRaw TimestampType, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_CMS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCMS */

