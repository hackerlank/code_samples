#ifndef __INC_SBX509EXT
#define __INC_SBX509EXT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrdn.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbasn1.h"
#include "sbpkcs7utils.h"
#include "sbasn1tree.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_PEM_CERTIFICATE_BEGIN_LINE 	"-----BEGIN CERTIFICATE-----"
#define SB_PEM_CERTIFICATE_END_LINE 	"-----END CERTIFICATE-----"
#define SB_PEM_CERTIFICATEX509_BEGIN_LINE 	"-----BEGIN X509 CERTIFICATE-----"
#define SB_PEM_CERTIFICATEX509_END_LINE 	"-----END X509 CERTIFICATE-----"
#define SB_PEM_RSA_PRIVATE_KEY_BEGIN_LINE 	"-----BEGIN RSA PRIVATE KEY-----"
#define SB_PEM_RSA_PRIVATE_KEY_END_LINE 	"-----END RSA PRIVATE KEY-----"
#define SB_PEM_DSA_PRIVATE_KEY_BEGIN_LINE 	"-----BEGIN DSA PRIVATE KEY-----"
#define SB_PEM_DSA_PRIVATE_KEY_END_LINE 	"-----END DSA PRIVATE KEY-----"
#define SB_PEM_DH_PRIVATE_KEY_BEGIN_LINE 	"-----BEGIN DH PRIVATE KEY-----"
#define SB_PEM_DH_PRIVATE_KEY_END_LINE 	"-----END DH PRIVATE KEY-----"
#define SB_PEM_EC_PRIVATE_KEY_BEGIN_LINE 	"-----BEGIN EC PRIVATE KEY-----"
#define SB_PEM_EC_PRIVATE_KEY_END_LINE 	"-----END EC PRIVATE KEY-----"
#define SB_PEM_PRIVATE_KEY_BEGIN_LINE 	"-----BEGIN PRIVATE KEY-----"
#define SB_PEM_PRIVATE_KEY_END_LINE 	"-----END PRIVATE KEY-----"
#define SB_CERT_OID_NETSCAPE_CERT_TYPE 	"`\x86""H\x01""\x86""\xF8""B\x01""\x01"
#define SB_CERT_OID_NETSCAPE_BASE_URL 	"`\x86""H\x01""\x86""\xF8""B\x01""\x02"
#define SB_CERT_OID_NETSCAPE_REVOKE_URL 	"`\x86""H\x01""\x86""\xF8""B\x01""\x03"
#define SB_CERT_OID_NETSCAPE_CA_REVOKE_URL 	"`\x86""H\x01""\x86""\xF8""B\x01""\x04"
#define SB_CERT_OID_NETSCAPE_RENEWAL_URL 	"`\x86""H\x01""\x86""\xF8""B\x01""\a"
#define SB_CERT_OID_NETSCAPE_CA_POLICY 	"`\x86""H\x01""\x86""\xF8""B\x01""\b"
#define SB_CERT_OID_NETSCAPE_SERVER_NAME 	"`\x86""H\x01""\x86""\xF8""B\x01""\f"
#define SB_CERT_OID_NETSCAPE_COMMENT 	"`\x86""H\x01""\x86""\xF8""B\x01""\r"
#define SB_CERT_OID_SUBJECT_DIRECTORY_ATTRIBUTES 	"U\x1D""\t"
#define SB_CERT_OID_SUBJECT_KEY_IDENTIFIER 	"U\x1D""\x0E"
#define SB_CERT_OID_KEY_USAGE 	"U\x1D""\x0F"
#define SB_CERT_OID_PRIVATE_KEY_USAGE_PERIOD 	"U\x1D""\x10"
#define SB_CERT_OID_SUBJECT_ALTERNATIVE_NAME 	"U\x1D""\x11"
#define SB_CERT_OID_ISSUER_ALTERNATIVE_NAME 	"U\x1D""\x12"
#define SB_CERT_OID_BASIC_CONSTRAINTS 	"U\x1D""\x13"
#define SB_CERT_OID_NAME_CONSTRAINTS 	"U\x1D""\x1E"
#define SB_CERT_OID_CRL_DISTRIBUTION_POINTS 	"U\x1D""\x1F"
#define SB_CERT_OID_CERTIFICATE_POLICIES 	"U\x1D"" "
#define SB_CERT_OID_POLICY_MAPPINGS 	"U\x1D""!"
#define SB_CERT_OID_AUTHORITY_KEY_IDENTIFIER 	"U\x1D""#"
#define SB_CERT_OID_POLICY_CONSTRAINTS 	"U\x1D""$"
#define SB_CERT_OID_EXTENDED_KEY_USAGE 	"U\x1D""%"
#define SB_CERT_OID_AUTHORITY_INFORMATION_ACCESS 	"+\x06""\x01""\x05""\x05""\a\x01""\x01"

typedef TElClassHandle TElEDIPartyNameHandle;

typedef TElEDIPartyNameHandle ElEDIPartyNameHandle;

typedef TElClassHandle TElOtherNameHandle;

typedef TElOtherNameHandle ElOtherNameHandle;

typedef TElClassHandle TElPermanentIdentifierHandle;

typedef TElPermanentIdentifierHandle ElPermanentIdentifierHandle;

typedef TElClassHandle TElGeneralNameHandle;

typedef TElGeneralNameHandle ElGeneralNameHandle;

typedef TElClassHandle TElGeneralNamesHandle;

typedef TElGeneralNamesHandle ElGeneralNamesHandle;

typedef TElClassHandle TElCustomExtensionHandle;

typedef TElCustomExtensionHandle ElCustomExtensionHandle;

typedef TElClassHandle TElAuthorityKeyIdentifierExtensionHandle;

typedef TElAuthorityKeyIdentifierExtensionHandle ElAuthorityKeyIdentifierExtensionHandle;

typedef TElClassHandle TElSubjectKeyIdentifierExtensionHandle;

typedef TElSubjectKeyIdentifierExtensionHandle ElSubjectKeyIdentifierExtensionHandle;

typedef TElClassHandle TElKeyUsageExtensionHandle;

typedef TElKeyUsageExtensionHandle ElKeyUsageExtensionHandle;

typedef TElClassHandle TElPrivateKeyUsagePeriodExtensionHandle;

typedef TElPrivateKeyUsagePeriodExtensionHandle ElPrivateKeyUsagePeriodExtensionHandle;

typedef TElClassHandle TElNetscapeCertTypeExtensionHandle;

typedef TElNetscapeCertTypeExtensionHandle ElNetscapeCertTypeExtensionHandle;

typedef TElClassHandle TElNetscapeStringHandle;

typedef TElNetscapeStringHandle ElNetscapeStringHandle;

typedef TElClassHandle TElNetscapeBaseURLHandle;

typedef TElNetscapeBaseURLHandle ElNetscapeBaseURLHandle;

typedef TElClassHandle TElNetscapeRevokeURLHandle;

typedef TElNetscapeRevokeURLHandle ElNetscapeRevokeURLHandle;

typedef TElClassHandle TElNetscapeCARevokeURLHandle;

typedef TElNetscapeCARevokeURLHandle ElNetscapeCARevokeURLHandle;

typedef TElClassHandle TElNetscapeRenewalURLHandle;

typedef TElNetscapeRenewalURLHandle ElNetscapeRenewalURLHandle;

typedef TElClassHandle TElNetscapeCAPolicyHandle;

typedef TElNetscapeCAPolicyHandle ElNetscapeCAPolicyHandle;

typedef TElClassHandle TElNetscapeServerNameHandle;

typedef TElNetscapeServerNameHandle ElNetscapeServerNameHandle;

typedef TElClassHandle TElNetscapeCommentHandle;

typedef TElNetscapeCommentHandle ElNetscapeCommentHandle;

typedef TElClassHandle TElCommonNameHandle;

typedef TElCommonNameHandle ElCommonNameHandle;

typedef TElClassHandle TElUserNoticeHandle;

typedef TElUserNoticeHandle ElUserNoticeHandle;

typedef TElClassHandle TElSinglePolicyQualifierHandle;

typedef TElSinglePolicyQualifierHandle ElSinglePolicyQualifierHandle;

typedef TElClassHandle TElSinglePolicyInformationHandle;

typedef TElSinglePolicyInformationHandle ElSinglePolicyInformationHandle;

typedef TElClassHandle TElCertificatePoliciesExtensionHandle;

typedef TElCertificatePoliciesExtensionHandle ElCertificatePoliciesExtensionHandle;

typedef TElClassHandle TElPolicyMappingHandle;

typedef TElPolicyMappingHandle ElPolicyMappingHandle;

typedef TElClassHandle TElPolicyMappingsExtensionHandle;

typedef TElPolicyMappingsExtensionHandle ElPolicyMappingsExtensionHandle;

typedef TElClassHandle TElAlternativeNameExtensionHandle;

typedef TElAlternativeNameExtensionHandle ElAlternativeNameExtensionHandle;

typedef TElClassHandle TElBasicConstraintsExtensionHandle;

typedef TElBasicConstraintsExtensionHandle ElBasicConstraintsExtensionHandle;

typedef TElClassHandle TElNameConstraintHandle;

typedef TElNameConstraintHandle ElNameConstraintHandle;

typedef TElClassHandle TElNameConstraintsExtensionHandle;

typedef TElNameConstraintsExtensionHandle ElNameConstraintsExtensionHandle;

typedef TElClassHandle TElPolicyConstraintsExtensionHandle;

typedef TElPolicyConstraintsExtensionHandle ElPolicyConstraintsExtensionHandle;

typedef TElClassHandle TElExtendedKeyUsageExtensionHandle;

typedef TElExtendedKeyUsageExtensionHandle ElExtendedKeyUsageExtensionHandle;

typedef TElClassHandle TElDistributionPointHandle;

typedef TElDistributionPointHandle ElDistributionPointHandle;

typedef TElClassHandle TElCRLDistributionPointsExtensionHandle;

typedef TElCRLDistributionPointsExtensionHandle ElCRLDistributionPointsExtensionHandle;

typedef TElClassHandle TElAccessDescriptionHandle;

typedef TElAccessDescriptionHandle ElAccessDescriptionHandle;

typedef TElClassHandle TElAuthorityInformationAccessExtensionHandle;

typedef TElAuthorityInformationAccessExtensionHandle ElAuthorityInformationAccessExtensionHandle;

typedef TElClassHandle TElSubjectDirectoryAttributesExtensionHandle;

typedef TElSubjectDirectoryAttributesExtensionHandle ElSubjectDirectoryAttributesExtensionHandle;

typedef TElClassHandle TElCertificateExtensionsHandle;

typedef TElCertificateExtensionsHandle ElCertificateExtensionsHandle;

typedef TElClassHandle TElExtensionWriterHandle;

typedef TElExtensionWriterHandle ElExtensionWriterHandle;

typedef TElClassHandle TElExtensionReaderHandle;

typedef TElExtensionReaderHandle ElExtensionReaderHandle;

typedef uint8_t TSBCertificateExtensionRaw;

typedef enum
{
	ceAuthorityKeyIdentifier = 0,
	ceSubjectKeyIdentifier = 1,
	ceKeyUsage = 2,
	cePrivateKeyUsagePeriod = 3,
	ceCertificatePolicies = 4,
	cePolicyMappings = 5,
	ceSubjectAlternativeName = 6,
	ceIssuerAlternativeName = 7,
	ceBasicConstraints = 8,
	ceNameConstraints = 9,
	cePolicyConstraints = 10,
	ceExtendedKeyUsage = 11,
	ceCRLDistributionPoints = 12,
	ceAuthorityInformationAccess = 13,
	ceNetscapeCertType = 14,
	ceNetscapeBaseURL = 15,
	ceNetscapeRevokeURL = 16,
	ceNetscapeCARevokeURL = 17,
	ceNetscapeRenewalURL = 18,
	ceNetscapeCAPolicyURL = 19,
	ceNetscapeServerName = 20,
	ceNetscapeComment = 21,
	ceCommonName = 22,
	ceSubjectDirectoryAttributes = 23
} TSBCertificateExtension;

typedef uint32_t TSBCertificateExtensionsRaw;

typedef enum 
{
	f_ceAuthorityKeyIdentifier = 1,
	f_ceSubjectKeyIdentifier = 2,
	f_ceKeyUsage = 4,
	f_cePrivateKeyUsagePeriod = 8,
	f_ceCertificatePolicies = 16,
	f_cePolicyMappings = 32,
	f_ceSubjectAlternativeName = 64,
	f_ceIssuerAlternativeName = 128,
	f_ceBasicConstraints = 256,
	f_ceNameConstraints = 512,
	f_cePolicyConstraints = 1024,
	f_ceExtendedKeyUsage = 2048,
	f_ceCRLDistributionPoints = 4096,
	f_ceAuthorityInformationAccess = 8192,
	f_ceNetscapeCertType = 16384,
	f_ceNetscapeBaseURL = 32768,
	f_ceNetscapeRevokeURL = 65536,
	f_ceNetscapeCARevokeURL = 131072,
	f_ceNetscapeRenewalURL = 262144,
	f_ceNetscapeCAPolicyURL = 524288,
	f_ceNetscapeServerName = 1048576,
	f_ceNetscapeComment = 2097152,
	f_ceCommonName = 4194304,
	f_ceSubjectDirectoryAttributes = 8388608
} TSBCertificateExtensions;

typedef uint8_t TSBKeyUsageTypeRaw;

typedef enum
{
	kuDigitalSignature = 0,
	kuNonRepudiation = 1,
	kuKeyEncipherment = 2,
	kuDataEncipherment = 3,
	kuKeyAgreement = 4,
	kuKeyCertSign = 5,
	kuCRLSign = 6,
	kuEncipherOnly = 7,
	kuDecipherOnly = 8
} TSBKeyUsageType;

typedef uint32_t TSBKeyUsageRaw;

typedef enum 
{
	f_kuDigitalSignature = 1,
	f_kuNonRepudiation = 2,
	f_kuKeyEncipherment = 4,
	f_kuDataEncipherment = 8,
	f_kuKeyAgreement = 16,
	f_kuKeyCertSign = 32,
	f_kuCRLSign = 64,
	f_kuEncipherOnly = 128,
	f_kuDecipherOnly = 256
} TSBKeyUsage;

typedef uint8_t TSBCRLReasonFlagRaw;

typedef enum
{
	rfUnspecified = 0,
	rfKeyCompromise = 1,
	rfCACompromise = 2,
	rfAffiliationChanged = 3,
	rfSuperseded = 4,
	rfCessationOfOperation = 5,
	rfCertificateHold = 6,
	rfObsolete1 = 7,
	rfRemoveFromCRL = 8,
	rfPrivilegeWithdrawn = 9,
	rfAACompromise = 10
} TSBCRLReasonFlag;

typedef uint32_t TSBCRLReasonFlagsRaw;

typedef enum 
{
	f_rfUnspecified = 1,
	f_rfKeyCompromise = 2,
	f_rfCACompromise = 4,
	f_rfAffiliationChanged = 8,
	f_rfSuperseded = 16,
	f_rfCessationOfOperation = 32,
	f_rfCertificateHold = 64,
	f_rfObsolete1 = 128,
	f_rfRemoveFromCRL = 256,
	f_rfPrivilegeWithdrawn = 512,
	f_rfAACompromise = 1024
} TSBCRLReasonFlags;

typedef uint8_t TSBGeneralNameRaw;

typedef enum
{
	gnRFC822Name = 0,
	gnDNSName = 1,
	gnDirectoryName = 2,
	gnEdiPartyName = 3,
	gnUniformResourceIdentifier = 4,
	gnIPAddress = 5,
	gnRegisteredID = 6,
	gnOtherName = 7,
	gnUnknown = 8,
	gnPermanentIdentifier = 9
} TSBGeneralName;

typedef uint8_t TElNetscapeCertTypeFlagRaw;

typedef enum
{
	nsSSLClient = 0,
	nsSSLServer = 1,
	nsSMIME = 2,
	nsObjectSign = 3,
	nsSSLCA = 4,
	nsSMIMECA = 5,
	nsObjectSignCA = 6
} TElNetscapeCertTypeFlag;

typedef uint32_t TElNetscapeCertTypeRaw;

typedef enum 
{
	f_nsSSLClient = 1,
	f_nsSSLServer = 2,
	f_nsSMIME = 4,
	f_nsObjectSign = 8,
	f_nsSSLCA = 16,
	f_nsSMIMECA = 32,
	f_nsObjectSignCA = 64
} TElNetscapeCertType;

typedef uint8_t TElDistributionPointParameterRaw;

typedef enum
{
	dppName = 0,
	dppCRLIssuer = 1,
	dppReasonFlags = 2
} TElDistributionPointParameter;

typedef uint32_t TElDistributionPointParametersRaw;

typedef enum 
{
	f_dppName = 1,
	f_dppCRLIssuer = 2,
	f_dppReasonFlags = 4
} TElDistributionPointParameters;

#ifdef SB_USE_CLASS_TELEDIPARTYNAME
SB_IMPORT uint32_t SB_APIENTRY TElEDIPartyName_get_NameAssigner(TElEDIPartyNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEDIPartyName_set_NameAssigner(TElEDIPartyNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElEDIPartyName_get_PartyName(TElEDIPartyNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElEDIPartyName_set_PartyName(TElEDIPartyNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElEDIPartyName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */

#ifdef SB_USE_CLASS_TELOTHERNAME
SB_IMPORT uint32_t SB_APIENTRY TElOtherName_get_OID(TElOtherNameHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOtherName_set_OID(TElOtherNameHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOtherName_get_Value(TElOtherNameHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOtherName_set_Value(TElOtherNameHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOtherName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELOTHERNAME */

#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElPermanentIdentifier_get_PermanentIdentifier(TElPermanentIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPermanentIdentifier_set_PermanentIdentifier(TElPermanentIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPermanentIdentifier_get_Assigner(TElPermanentIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPermanentIdentifier_set_Assigner(TElPermanentIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPermanentIdentifier_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

#ifdef SB_USE_CLASS_TELGENERALNAME
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_Assign(TElGeneralNameHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_AssignTo(TElGeneralNameHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_LoadFromTag(TElGeneralNameHandle _Handle, TElASN1CustomTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_SaveToTag(TElGeneralNameHandle _Handle, TElASN1SimpleTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_RFC822Name(TElGeneralNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_RFC822Name(TElGeneralNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_DNSName(TElGeneralNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_DNSName(TElGeneralNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_DirectoryName(TElGeneralNameHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_EdiPartyName(TElGeneralNameHandle _Handle, TElEDIPartyNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_UniformResourceIdentifier(TElGeneralNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_UniformResourceIdentifier(TElGeneralNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_IpAddress(TElGeneralNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_IpAddress(TElGeneralNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_IpAddressBytes(TElGeneralNameHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_IpAddressBytes(TElGeneralNameHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_RegisteredID(TElGeneralNameHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_RegisteredID(TElGeneralNameHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_OtherName(TElGeneralNameHandle _Handle, TElOtherNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_PermanentIdentifier(TElGeneralNameHandle _Handle, TElPermanentIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_NameType(TElGeneralNameHandle _Handle, TSBGeneralNameRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_set_NameType(TElGeneralNameHandle _Handle, TSBGeneralNameRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_get_IsEmpty(TElGeneralNameHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralName_Create(TElGeneralNameHandle * OutResult);
#endif /* SB_USE_CLASS_TELGENERALNAME */

#ifdef SB_USE_CLASS_TELGENERALNAMES
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Assign(TElGeneralNamesHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_AssignTo(TElGeneralNamesHandle _Handle, TPersistentHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Equals(TElGeneralNamesHandle _Handle, TElGeneralNamesHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_HasCommon(TElGeneralNamesHandle _Handle, TElGeneralNamesHandle Other, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Add(TElGeneralNamesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Remove(TElGeneralNamesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Clear(TElGeneralNamesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_ContainsEmailAddress(TElGeneralNamesHandle _Handle, const char * pcAddr, int32_t szAddr, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_FindNameByType(TElGeneralNamesHandle _Handle, TSBGeneralNameRaw NameType, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_LoadFromTag(TElGeneralNamesHandle _Handle, TElASN1ConstrainedTagHandle Tag, int8_t AllowRDN, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_SaveToTag(TElGeneralNamesHandle _Handle, TElASN1ConstrainedTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_get_Names(TElGeneralNamesHandle _Handle, int32_t Index, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_get_Count(TElGeneralNamesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGeneralNames_Create(TElGeneralNamesHandle * OutResult);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_SaveToTag(TElCustomExtensionHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_get_Critical(TElCustomExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_set_Critical(TElCustomExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_get_OID(TElCustomExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_set_OID(TElCustomExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_get_Value(TElCustomExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_set_Value(TElCustomExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_get_SaveDefaultASN1Tags(TElCustomExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_set_SaveDefaultASN1Tags(TElCustomExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_get_KeyIdentifier(TElAuthorityKeyIdentifierExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_set_KeyIdentifier(TElAuthorityKeyIdentifierExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_get_AuthorityCertIssuer(TElAuthorityKeyIdentifierExtensionHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_get_AuthorityCertSerial(TElAuthorityKeyIdentifierExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_set_AuthorityCertSerial(TElAuthorityKeyIdentifierExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierExtension_Create(TElAuthorityKeyIdentifierExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSubjectKeyIdentifierExtension_get_KeyIdentifier(TElSubjectKeyIdentifierExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectKeyIdentifierExtension_set_KeyIdentifier(TElSubjectKeyIdentifierExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectKeyIdentifierExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_DigitalSignature(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_DigitalSignature(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_NonRepudiation(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_NonRepudiation(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_KeyEncipherment(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_KeyEncipherment(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_DataEncipherment(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_DataEncipherment(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_KeyAgreement(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_KeyAgreement(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_KeyCertSign(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_KeyCertSign(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_CRLSign(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_CRLSign(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_EncipherOnly(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_EncipherOnly(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_get_DecipherOnly(TElKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_set_DecipherOnly(TElKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElKeyUsageExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElPrivateKeyUsagePeriodExtension_get_NotBefore(TElPrivateKeyUsagePeriodExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPrivateKeyUsagePeriodExtension_set_NotBefore(TElPrivateKeyUsagePeriodExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPrivateKeyUsagePeriodExtension_get_NotAfter(TElPrivateKeyUsagePeriodExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPrivateKeyUsagePeriodExtension_set_NotAfter(TElPrivateKeyUsagePeriodExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPrivateKeyUsagePeriodExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeCertTypeExtension_get_CertType(TElNetscapeCertTypeExtensionHandle _Handle, TElNetscapeCertTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeCertTypeExtension_set_CertType(TElNetscapeCertTypeExtensionHandle _Handle, TElNetscapeCertTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeCertTypeExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPESTRING
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeString_get_Content(TElNetscapeStringHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeString_set_Content(TElNetscapeStringHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeString_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPESTRING */

#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeBaseURL_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */

#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeRevokeURL_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeCARevokeURL_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeRenewalURL_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeCAPolicy_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */

#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeServerName_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */

#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
SB_IMPORT uint32_t SB_APIENTRY TElNetscapeComment_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */

#ifdef SB_USE_CLASS_TELCOMMONNAME
SB_IMPORT uint32_t SB_APIENTRY TElCommonName_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMMONNAME */

#ifdef SB_USE_CLASS_TELUSERNOTICE
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_get_Organization(TElUserNoticeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_set_Organization(TElUserNoticeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_get_NoticeNumbers(TElUserNoticeHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_set_NoticeNumbers(TElUserNoticeHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_get_NoticeNumbersCount(TElUserNoticeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_set_NoticeNumbersCount(TElUserNoticeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_get_ExplicitText(TElUserNoticeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_set_ExplicitText(TElUserNoticeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUserNotice_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELUSERNOTICE */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyQualifier_get_CPSURI(TElSinglePolicyQualifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyQualifier_set_CPSURI(TElSinglePolicyQualifierHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyQualifier_get_UserNotice(TElSinglePolicyQualifierHandle _Handle, TElUserNoticeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyQualifier_Create(TElSinglePolicyQualifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_get_PolicyIdentifier(TElSinglePolicyInformationHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_set_PolicyIdentifier(TElSinglePolicyInformationHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_get_QualifierCount(TElSinglePolicyInformationHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_set_QualifierCount(TElSinglePolicyInformationHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_get_Qualifiers(TElSinglePolicyInformationHandle _Handle, int32_t Index, TElSinglePolicyQualifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSinglePolicyInformation_Create(TElSinglePolicyInformationHandle * OutResult);
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCertificatePoliciesExtension_Remove(TElCertificatePoliciesExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCertificatePoliciesExtension_get_PolicyInformation(TElCertificatePoliciesExtensionHandle _Handle, int32_t Index, TElSinglePolicyInformationHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificatePoliciesExtension_get_Count(TElCertificatePoliciesExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificatePoliciesExtension_set_Count(TElCertificatePoliciesExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificatePoliciesExtension_Create(TElCertificatePoliciesExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYMAPPING
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMapping_get_IssuerDomainPolicy(TElPolicyMappingHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMapping_set_IssuerDomainPolicy(TElPolicyMappingHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMapping_get_SubjectDomainPolicy(TElPolicyMappingHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMapping_set_SubjectDomainPolicy(TElPolicyMappingHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMapping_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMappingsExtension_Remove(TElPolicyMappingsExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMappingsExtension_get_Count(TElPolicyMappingsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMappingsExtension_set_Count(TElPolicyMappingsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMappingsExtension_get_Policies(TElPolicyMappingsExtensionHandle _Handle, int32_t Index, TElPolicyMappingHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyMappingsExtension_Create(TElPolicyMappingsExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElAlternativeNameExtension_get_Content(TElAlternativeNameExtensionHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlternativeNameExtension_Create(int8_t IssuerAltName, TElAlternativeNameExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElBasicConstraintsExtension_get_CA(TElBasicConstraintsExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBasicConstraintsExtension_set_CA(TElBasicConstraintsExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBasicConstraintsExtension_get_PathLenConstraint(TElBasicConstraintsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBasicConstraintsExtension_set_PathLenConstraint(TElBasicConstraintsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBasicConstraintsExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_get_Base(TElNameConstraintHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_get_Minimum(TElNameConstraintHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_set_Minimum(TElNameConstraintHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_get_Maximum(TElNameConstraintHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_set_Maximum(TElNameConstraintHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraint_Create(TElNameConstraintHandle * OutResult);
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_AreNamesAcceptable(TElNameConstraintsExtensionHandle _Handle, TElRelativeDistinguishedNameHandle Subj, TElGeneralNamesHandle SubjAltName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_RemovePermitted(TElNameConstraintsExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_RemoveExcluded(TElNameConstraintsExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_get_PermittedSubtrees(TElNameConstraintsExtensionHandle _Handle, int32_t Index, TElNameConstraintHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_get_ExcludedSubtrees(TElNameConstraintsExtensionHandle _Handle, int32_t Index, TElNameConstraintHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_get_PermittedCount(TElNameConstraintsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_set_PermittedCount(TElNameConstraintsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_get_ExcludedCount(TElNameConstraintsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_set_ExcludedCount(TElNameConstraintsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElNameConstraintsExtension_Create(TElNameConstraintsExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElPolicyConstraintsExtension_get_RequireExplicitPolicy(TElPolicyConstraintsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyConstraintsExtension_set_RequireExplicitPolicy(TElPolicyConstraintsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyConstraintsExtension_get_InhibitPolicyMapping(TElPolicyConstraintsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyConstraintsExtension_set_InhibitPolicyMapping(TElPolicyConstraintsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPolicyConstraintsExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_AddCustomUsage(TElExtendedKeyUsageExtensionHandle _Handle, const uint8_t pUsageOID[], int32_t szUsageOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_RemoveCustomUsage(TElExtendedKeyUsageExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_ClearCustomUsages(TElExtendedKeyUsageExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_TotalUsageCount(TElExtendedKeyUsageExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_ServerAuthentication(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_ServerAuthentication(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_ClientAuthentication(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_ClientAuthentication(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_CodeSigning(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_CodeSigning(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_EmailProtection(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_EmailProtection(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_TimeStamping(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_TimeStamping(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_OCSPSigning(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_OCSPSigning(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_SmartCardLogon(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_SmartCardLogon(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_KeyPurposeClientAuth(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_KeyPurposeClientAuth(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_KeyPurposeKDC(TElExtendedKeyUsageExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_KeyPurposeKDC(TElExtendedKeyUsageExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_CustomUsages(TElExtendedKeyUsageExtensionHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_set_CustomUsages(TElExtendedKeyUsageExtensionHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_get_CustomUsageCount(TElExtendedKeyUsageExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedKeyUsageExtension_Create(TElExtendedKeyUsageExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_get_Name(TElDistributionPointHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_get_ReasonFlags(TElDistributionPointHandle _Handle, TSBCRLReasonFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_set_ReasonFlags(TElDistributionPointHandle _Handle, TSBCRLReasonFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_get_CRLIssuer(TElDistributionPointHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_get_Included(TElDistributionPointHandle _Handle, TElDistributionPointParametersRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_set_Included(TElDistributionPointHandle _Handle, TElDistributionPointParametersRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDistributionPoint_Create(TElDistributionPointHandle * OutResult);
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCRLDistributionPointsExtension_Remove(TElCRLDistributionPointsExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCRLDistributionPointsExtension_get_DistributionPoints(TElCRLDistributionPointsExtensionHandle _Handle, int32_t Index, TElDistributionPointHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLDistributionPointsExtension_get_Count(TElCRLDistributionPointsExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLDistributionPointsExtension_set_Count(TElCRLDistributionPointsExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLDistributionPointsExtension_Create(TElCRLDistributionPointsExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */

#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
SB_IMPORT uint32_t SB_APIENTRY TElAccessDescription_get_AccessMethod(TElAccessDescriptionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAccessDescription_set_AccessMethod(TElAccessDescriptionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAccessDescription_get_AccessLocation(TElAccessDescriptionHandle _Handle, TElGeneralNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAccessDescription_Create(TElAccessDescriptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityInformationAccessExtension_Remove(TElAuthorityInformationAccessExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityInformationAccessExtension_get_AccessDescriptions(TElAuthorityInformationAccessExtensionHandle _Handle, int32_t Index, TElAccessDescriptionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityInformationAccessExtension_get_Count(TElAuthorityInformationAccessExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityInformationAccessExtension_set_Count(TElAuthorityInformationAccessExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityInformationAccessExtension_Create(TElAuthorityInformationAccessExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSubjectDirectoryAttributesExtension_get_Attributes(TElSubjectDirectoryAttributesExtensionHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubjectDirectoryAttributesExtension_Create(TElSubjectDirectoryAttributesExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_RemoveOther(TElCertificateExtensionsHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_ClearExtensions(TElCertificateExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_AuthorityKeyIdentifier(TElCertificateExtensionsHandle _Handle, TElAuthorityKeyIdentifierExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_SubjectKeyIdentifier(TElCertificateExtensionsHandle _Handle, TElSubjectKeyIdentifierExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_KeyUsage(TElCertificateExtensionsHandle _Handle, TElKeyUsageExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_KeyUsage(TElCertificateExtensionsHandle _Handle, TElKeyUsageExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_PrivateKeyUsagePeriod(TElCertificateExtensionsHandle _Handle, TElPrivateKeyUsagePeriodExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_PrivateKeyUsagePeriod(TElCertificateExtensionsHandle _Handle, TElPrivateKeyUsagePeriodExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_CertificatePolicies(TElCertificateExtensionsHandle _Handle, TElCertificatePoliciesExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_PolicyMappings(TElCertificateExtensionsHandle _Handle, TElPolicyMappingsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_PolicyMappings(TElCertificateExtensionsHandle _Handle, TElPolicyMappingsExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_SubjectAlternativeName(TElCertificateExtensionsHandle _Handle, TElAlternativeNameExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_SubjectAlternativeName(TElCertificateExtensionsHandle _Handle, TElAlternativeNameExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_IssuerAlternativeName(TElCertificateExtensionsHandle _Handle, TElAlternativeNameExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_IssuerAlternativeName(TElCertificateExtensionsHandle _Handle, TElAlternativeNameExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_BasicConstraints(TElCertificateExtensionsHandle _Handle, TElBasicConstraintsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_BasicConstraints(TElCertificateExtensionsHandle _Handle, TElBasicConstraintsExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NameConstraints(TElCertificateExtensionsHandle _Handle, TElNameConstraintsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_PolicyConstraints(TElCertificateExtensionsHandle _Handle, TElPolicyConstraintsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_PolicyConstraints(TElCertificateExtensionsHandle _Handle, TElPolicyConstraintsExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_ExtendedKeyUsage(TElCertificateExtensionsHandle _Handle, TElExtendedKeyUsageExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_CRLDistributionPoints(TElCertificateExtensionsHandle _Handle, TElCRLDistributionPointsExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_AuthorityInformationAccess(TElCertificateExtensionsHandle _Handle, TElAuthorityInformationAccessExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeCertType(TElCertificateExtensionsHandle _Handle, TElNetscapeCertTypeExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeCertType(TElCertificateExtensionsHandle _Handle, TElNetscapeCertTypeExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeComment(TElCertificateExtensionsHandle _Handle, TElNetscapeCommentHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeComment(TElCertificateExtensionsHandle _Handle, TElNetscapeCommentHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeBaseURL(TElCertificateExtensionsHandle _Handle, TElNetscapeBaseURLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeBaseURL(TElCertificateExtensionsHandle _Handle, TElNetscapeBaseURLHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeRevokeURL(TElCertificateExtensionsHandle _Handle, TElNetscapeRevokeURLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeRevokeURL(TElCertificateExtensionsHandle _Handle, TElNetscapeRevokeURLHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeCARevokeURL(TElCertificateExtensionsHandle _Handle, TElNetscapeCARevokeURLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeCARevokeURL(TElCertificateExtensionsHandle _Handle, TElNetscapeCARevokeURLHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeRenewalURL(TElCertificateExtensionsHandle _Handle, TElNetscapeRenewalURLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeRenewalURL(TElCertificateExtensionsHandle _Handle, TElNetscapeRenewalURLHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeCAPolicy(TElCertificateExtensionsHandle _Handle, TElNetscapeCAPolicyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeCAPolicy(TElCertificateExtensionsHandle _Handle, TElNetscapeCAPolicyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_NetscapeServerName(TElCertificateExtensionsHandle _Handle, TElNetscapeServerNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_NetscapeServerName(TElCertificateExtensionsHandle _Handle, TElNetscapeServerNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_CommonName(TElCertificateExtensionsHandle _Handle, TElCommonNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_CommonName(TElCertificateExtensionsHandle _Handle, TElCommonNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_SubjectDirectoryAttributes(TElCertificateExtensionsHandle _Handle, TElSubjectDirectoryAttributesExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_OtherExtensions(TElCertificateExtensionsHandle _Handle, int32_t Index, TElCustomExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_OtherCount(TElCertificateExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_OtherCount(TElCertificateExtensionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_get_Included(TElCertificateExtensionsHandle _Handle, TSBCertificateExtensionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_set_Included(TElCertificateExtensionsHandle _Handle, TSBCertificateExtensionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateExtensions_Create(TElCertificateExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

#ifdef SB_USE_CLASS_TELEXTENSIONWRITER
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensions(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtension(TElExtensionWriterHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t Critical, const uint8_t pValue[], int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionBasicConstraints(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionKeyUsage(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionPrivateKeyUsagePeriod(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionSubjectAltName(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionIssuerAltName(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionExtendedKeyUsage(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionPolicyMappings(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionNameConstraints(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionPolicyConstraints(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionCertificatePolicies(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionAuthorityKeyIdentifier(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionCRLDistributionPoints(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionAuthorityInformationAccess(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionNetscapeCertType(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionNetscapeString(TElExtensionWriterHandle _Handle, const uint8_t pAOID[], int32_t szAOID, const char * pcANetStr, int32_t szANetStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionNetscapeString_1(TElExtensionWriterHandle _Handle, const uint8_t pAOID[], int32_t szAOID, const uint8_t pANetStr[], int32_t szANetStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionSubjectKeyIdentifier(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WritePolicyInformation(TElExtensionWriterHandle _Handle, TElSinglePolicyInformationHandle P, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteDistributionPoint(TElExtensionWriterHandle _Handle, TElDistributionPointHandle P, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_WriteExtensionSubjectDirectoryAttributes(TElExtensionWriterHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_get_Extensions(TElExtensionWriterHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_get_UseA3Prefix(TElExtensionWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_set_UseA3Prefix(TElExtensionWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_get_SaveDefaultASN1Tags(TElExtensionWriterHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_set_SaveDefaultASN1Tags(TElExtensionWriterHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionWriter_Create(TElCertificateExtensionsHandle Exts, int8_t CertExtensions, TElExtensionWriterHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTENSIONWRITER */

#ifdef SB_USE_CLASS_TELEXTENSIONREADER
SB_IMPORT uint32_t SB_APIENTRY TElExtensionReader_ParseExtension(TElExtensionReaderHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t Critical, const uint8_t pContent[], int32_t szContent);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionReader_get_Extensions(TElExtensionReaderHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElExtensionReader_Create(TElCertificateExtensionsHandle Exts, int8_t StrictMode, TElExtensionReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTENSIONREADER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElEDIPartyName;
typedef TElEDIPartyName ElEDIPartyName;
class TElOtherName;
typedef TElOtherName ElOtherName;
class TElPermanentIdentifier;
typedef TElPermanentIdentifier ElPermanentIdentifier;
class TElGeneralName;
typedef TElGeneralName ElGeneralName;
class TElGeneralNames;
typedef TElGeneralNames ElGeneralNames;
class TElCustomExtension;
typedef TElCustomExtension ElCustomExtension;
class TElAuthorityKeyIdentifierExtension;
typedef TElAuthorityKeyIdentifierExtension ElAuthorityKeyIdentifierExtension;
class TElSubjectKeyIdentifierExtension;
typedef TElSubjectKeyIdentifierExtension ElSubjectKeyIdentifierExtension;
class TElKeyUsageExtension;
typedef TElKeyUsageExtension ElKeyUsageExtension;
class TElPrivateKeyUsagePeriodExtension;
typedef TElPrivateKeyUsagePeriodExtension ElPrivateKeyUsagePeriodExtension;
class TElNetscapeCertTypeExtension;
typedef TElNetscapeCertTypeExtension ElNetscapeCertTypeExtension;
class TElNetscapeString;
typedef TElNetscapeString ElNetscapeString;
class TElNetscapeBaseURL;
typedef TElNetscapeBaseURL ElNetscapeBaseURL;
class TElNetscapeRevokeURL;
typedef TElNetscapeRevokeURL ElNetscapeRevokeURL;
class TElNetscapeCARevokeURL;
typedef TElNetscapeCARevokeURL ElNetscapeCARevokeURL;
class TElNetscapeRenewalURL;
typedef TElNetscapeRenewalURL ElNetscapeRenewalURL;
class TElNetscapeCAPolicy;
typedef TElNetscapeCAPolicy ElNetscapeCAPolicy;
class TElNetscapeServerName;
typedef TElNetscapeServerName ElNetscapeServerName;
class TElNetscapeComment;
typedef TElNetscapeComment ElNetscapeComment;
class TElCommonName;
typedef TElCommonName ElCommonName;
class TElUserNotice;
typedef TElUserNotice ElUserNotice;
class TElSinglePolicyQualifier;
typedef TElSinglePolicyQualifier ElSinglePolicyQualifier;
class TElSinglePolicyInformation;
typedef TElSinglePolicyInformation ElSinglePolicyInformation;
class TElCertificatePoliciesExtension;
typedef TElCertificatePoliciesExtension ElCertificatePoliciesExtension;
class TElPolicyMapping;
typedef TElPolicyMapping ElPolicyMapping;
class TElPolicyMappingsExtension;
typedef TElPolicyMappingsExtension ElPolicyMappingsExtension;
class TElAlternativeNameExtension;
typedef TElAlternativeNameExtension ElAlternativeNameExtension;
class TElBasicConstraintsExtension;
typedef TElBasicConstraintsExtension ElBasicConstraintsExtension;
class TElNameConstraint;
typedef TElNameConstraint ElNameConstraint;
class TElNameConstraintsExtension;
typedef TElNameConstraintsExtension ElNameConstraintsExtension;
class TElPolicyConstraintsExtension;
typedef TElPolicyConstraintsExtension ElPolicyConstraintsExtension;
class TElExtendedKeyUsageExtension;
typedef TElExtendedKeyUsageExtension ElExtendedKeyUsageExtension;
class TElDistributionPoint;
typedef TElDistributionPoint ElDistributionPoint;
class TElCRLDistributionPointsExtension;
typedef TElCRLDistributionPointsExtension ElCRLDistributionPointsExtension;
class TElAccessDescription;
typedef TElAccessDescription ElAccessDescription;
class TElAuthorityInformationAccessExtension;
typedef TElAuthorityInformationAccessExtension ElAuthorityInformationAccessExtension;
class TElSubjectDirectoryAttributesExtension;
typedef TElSubjectDirectoryAttributesExtension ElSubjectDirectoryAttributesExtension;
class TElCertificateExtensions;
typedef TElCertificateExtensions ElCertificateExtensions;
class TElExtensionWriter;
typedef TElExtensionWriter ElExtensionWriter;
class TElExtensionReader;
typedef TElExtensionReader ElExtensionReader;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCertificateExtensions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBKeyUsage)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCRLReasonFlags)

SB_DEFINE_ENUM_FLAG_OPERATORS(TElNetscapeCertType)

SB_DEFINE_ENUM_FLAG_OPERATORS(TElDistributionPointParameters)

#ifdef SB_USE_CLASS_TELEDIPARTYNAME
class TElEDIPartyName: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElEDIPartyName)
	public:
		virtual void get_NameAssigner(std::string &OutResult);

		virtual void set_NameAssigner(const std::string &Value);

		virtual void get_PartyName(std::string &OutResult);

		virtual void set_PartyName(const std::string &Value);

		TElEDIPartyName(TElEDIPartyNameHandle handle, TElOwnHandle ownHandle);

		TElEDIPartyName();

};
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */

#ifdef SB_USE_CLASS_TELOTHERNAME
class TElOtherName: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOtherName)
	public:
		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void set_OID(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		TElOtherName(TElOtherNameHandle handle, TElOwnHandle ownHandle);

		TElOtherName();

};
#endif /* SB_USE_CLASS_TELOTHERNAME */

#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
class TElPermanentIdentifier: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPermanentIdentifier)
	public:
		virtual void get_PermanentIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_PermanentIdentifier(const std::vector<uint8_t> &Value);

		virtual void get_Assigner(std::vector<uint8_t> &OutResult);

		virtual void set_Assigner(const std::vector<uint8_t> &Value);

		TElPermanentIdentifier(TElPermanentIdentifierHandle handle, TElOwnHandle ownHandle);

		TElPermanentIdentifier();

};
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

#ifdef SB_USE_CLASS_TELGENERALNAME
class TElGeneralName: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElGeneralName)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_DirectoryName;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELEDIPARTYNAME
		TElEDIPartyName* _Inst_EdiPartyName;
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */
#ifdef SB_USE_CLASS_TELOTHERNAME
		TElOtherName* _Inst_OtherName;
#endif /* SB_USE_CLASS_TELOTHERNAME */
#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
		TElPermanentIdentifier* _Inst_PermanentIdentifier;
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
		bool LoadFromTag(TElASN1CustomTag &Tag);

		bool LoadFromTag(TElASN1CustomTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
		bool SaveToTag(TElASN1SimpleTag &Tag);

		bool SaveToTag(TElASN1SimpleTag *Tag);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

		virtual void get_RFC822Name(std::string &OutResult);

		virtual void set_RFC822Name(const std::string &Value);

		virtual void get_DNSName(std::string &OutResult);

		virtual void set_DNSName(const std::string &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_DirectoryName();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_DirectoryName, TElGeneralName, DirectoryName);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELEDIPARTYNAME
		virtual TElEDIPartyName* get_EdiPartyName();

		SB_DECLARE_PROPERTY_GET(TElEDIPartyName*, get_EdiPartyName, TElGeneralName, EdiPartyName);
#endif /* SB_USE_CLASS_TELEDIPARTYNAME */

		virtual void get_UniformResourceIdentifier(std::string &OutResult);

		virtual void set_UniformResourceIdentifier(const std::string &Value);

		virtual void get_IpAddress(std::string &OutResult);

		virtual void set_IpAddress(const std::string &Value);

		virtual void get_IpAddressBytes(std::vector<uint8_t> &OutResult);

		virtual void set_IpAddressBytes(const std::vector<uint8_t> &Value);

		virtual void get_RegisteredID(std::vector<uint8_t> &OutResult);

		virtual void set_RegisteredID(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELOTHERNAME
		virtual TElOtherName* get_OtherName();

		SB_DECLARE_PROPERTY_GET(TElOtherName*, get_OtherName, TElGeneralName, OtherName);
#endif /* SB_USE_CLASS_TELOTHERNAME */

#ifdef SB_USE_CLASS_TELPERMANENTIDENTIFIER
		virtual TElPermanentIdentifier* get_PermanentIdentifier();

		SB_DECLARE_PROPERTY_GET(TElPermanentIdentifier*, get_PermanentIdentifier, TElGeneralName, PermanentIdentifier);
#endif /* SB_USE_CLASS_TELPERMANENTIDENTIFIER */

		virtual TSBGeneralName get_NameType();

		virtual void set_NameType(TSBGeneralName Value);

		SB_DECLARE_PROPERTY(TSBGeneralName, get_NameType, set_NameType, TElGeneralName, NameType);

		virtual bool get_IsEmpty();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEmpty, TElGeneralName, IsEmpty);

		TElGeneralName(TElGeneralNameHandle handle, TElOwnHandle ownHandle);

		TElGeneralName();

		virtual ~TElGeneralName();

};
#endif /* SB_USE_CLASS_TELGENERALNAME */

#ifdef SB_USE_CLASS_TELGENERALNAMES
class TElGeneralNames: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElGeneralNames)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_Names;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void AssignTo(TPersistent &Dest);

		virtual void AssignTo(TPersistent *Dest);

		bool Equals(TElGeneralNames &Other);

		bool Equals(TElGeneralNames *Other);

		bool HasCommon(TElGeneralNames &Other);

		bool HasCommon(TElGeneralNames *Other);

		int32_t Add();

		void Remove(int32_t Index);

		void Clear();

		bool ContainsEmailAddress(const std::string &Addr);

		int32_t FindNameByType(TSBGeneralName NameType, int32_t StartIndex);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		bool LoadFromTag(TElASN1ConstrainedTag &Tag, bool AllowRDN);

		bool LoadFromTag(TElASN1ConstrainedTag *Tag, bool AllowRDN);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		bool SaveToTag(TElASN1ConstrainedTag &Tag);

		bool SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_Names(int32_t Index);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElGeneralNames, Count);

		TElGeneralNames(TElGeneralNamesHandle handle, TElOwnHandle ownHandle);

		TElGeneralNames();

		virtual ~TElGeneralNames();

};
#endif /* SB_USE_CLASS_TELGENERALNAMES */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
class TElCustomExtension: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElCustomExtension)
	public:
#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		virtual void SaveToTag(TElASN1ConstrainedTag &Tag);

		virtual void SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual bool get_Critical();

		virtual void set_Critical(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Critical, set_Critical, TElCustomExtension, Critical);

		virtual void get_OID(std::vector<uint8_t> &OutResult);

		virtual void set_OID(const std::vector<uint8_t> &Value);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

		virtual bool get_SaveDefaultASN1Tags();

		virtual void set_SaveDefaultASN1Tags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveDefaultASN1Tags, set_SaveDefaultASN1Tags, TElCustomExtension, SaveDefaultASN1Tags);

		TElCustomExtension(TElCustomExtensionHandle handle, TElOwnHandle ownHandle);

		TElCustomExtension();

};
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
class TElAuthorityKeyIdentifierExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElAuthorityKeyIdentifierExtension)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_AuthorityCertIssuer;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
		virtual void get_KeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_KeyIdentifier(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_AuthorityCertIssuer();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_AuthorityCertIssuer, TElAuthorityKeyIdentifierExtension, AuthorityCertIssuer);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual void get_AuthorityCertSerial(std::vector<uint8_t> &OutResult);

		virtual void set_AuthorityCertSerial(const std::vector<uint8_t> &Value);

		TElAuthorityKeyIdentifierExtension(TElAuthorityKeyIdentifierExtensionHandle handle, TElOwnHandle ownHandle);

		TElAuthorityKeyIdentifierExtension();

		virtual ~TElAuthorityKeyIdentifierExtension();

};
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
class TElSubjectKeyIdentifierExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElSubjectKeyIdentifierExtension)
	public:
		virtual void get_KeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_KeyIdentifier(const std::vector<uint8_t> &Value);

		TElSubjectKeyIdentifierExtension(TElSubjectKeyIdentifierExtensionHandle handle, TElOwnHandle ownHandle);

		TElSubjectKeyIdentifierExtension();

};
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
class TElKeyUsageExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElKeyUsageExtension)
	public:
		virtual bool get_DigitalSignature();

		virtual void set_DigitalSignature(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DigitalSignature, set_DigitalSignature, TElKeyUsageExtension, DigitalSignature);

		virtual bool get_NonRepudiation();

		virtual void set_NonRepudiation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NonRepudiation, set_NonRepudiation, TElKeyUsageExtension, NonRepudiation);

		virtual bool get_KeyEncipherment();

		virtual void set_KeyEncipherment(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeyEncipherment, set_KeyEncipherment, TElKeyUsageExtension, KeyEncipherment);

		virtual bool get_DataEncipherment();

		virtual void set_DataEncipherment(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DataEncipherment, set_DataEncipherment, TElKeyUsageExtension, DataEncipherment);

		virtual bool get_KeyAgreement();

		virtual void set_KeyAgreement(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeyAgreement, set_KeyAgreement, TElKeyUsageExtension, KeyAgreement);

		virtual bool get_KeyCertSign();

		virtual void set_KeyCertSign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeyCertSign, set_KeyCertSign, TElKeyUsageExtension, KeyCertSign);

		virtual bool get_CRLSign();

		virtual void set_CRLSign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CRLSign, set_CRLSign, TElKeyUsageExtension, CRLSign);

		virtual bool get_EncipherOnly();

		virtual void set_EncipherOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncipherOnly, set_EncipherOnly, TElKeyUsageExtension, EncipherOnly);

		virtual bool get_DecipherOnly();

		virtual void set_DecipherOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DecipherOnly, set_DecipherOnly, TElKeyUsageExtension, DecipherOnly);

		TElKeyUsageExtension(TElKeyUsageExtensionHandle handle, TElOwnHandle ownHandle);

		TElKeyUsageExtension();

};
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
class TElPrivateKeyUsagePeriodExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElPrivateKeyUsagePeriodExtension)
	public:
		virtual int64_t get_NotBefore();

		virtual void set_NotBefore(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotBefore, set_NotBefore, TElPrivateKeyUsagePeriodExtension, NotBefore);

		virtual int64_t get_NotAfter();

		virtual void set_NotAfter(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NotAfter, set_NotAfter, TElPrivateKeyUsagePeriodExtension, NotAfter);

		TElPrivateKeyUsagePeriodExtension(TElPrivateKeyUsagePeriodExtensionHandle handle, TElOwnHandle ownHandle);

		TElPrivateKeyUsagePeriodExtension();

};
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
class TElNetscapeCertTypeExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElNetscapeCertTypeExtension)
	public:
		virtual TElNetscapeCertType get_CertType();

		virtual void set_CertType(TElNetscapeCertType Value);

		SB_DECLARE_PROPERTY(TElNetscapeCertType, get_CertType, set_CertType, TElNetscapeCertTypeExtension, CertType);

		TElNetscapeCertTypeExtension(TElNetscapeCertTypeExtensionHandle handle, TElOwnHandle ownHandle);

		TElNetscapeCertTypeExtension();

};
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPESTRING
class TElNetscapeString: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElNetscapeString)
	public:
		virtual void get_Content(std::string &OutResult);

		virtual void set_Content(const std::string &Value);

		TElNetscapeString(TElNetscapeStringHandle handle, TElOwnHandle ownHandle);

		TElNetscapeString();

};
#endif /* SB_USE_CLASS_TELNETSCAPESTRING */

#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
class TElNetscapeBaseURL: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeBaseURL)
	public:
		TElNetscapeBaseURL(TElNetscapeBaseURLHandle handle, TElOwnHandle ownHandle);

		TElNetscapeBaseURL();

};
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */

#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
class TElNetscapeRevokeURL: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeRevokeURL)
	public:
		TElNetscapeRevokeURL(TElNetscapeRevokeURLHandle handle, TElOwnHandle ownHandle);

		TElNetscapeRevokeURL();

};
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
class TElNetscapeCARevokeURL: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeCARevokeURL)
	public:
		TElNetscapeCARevokeURL(TElNetscapeCARevokeURLHandle handle, TElOwnHandle ownHandle);

		TElNetscapeCARevokeURL();

};
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
class TElNetscapeRenewalURL: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeRenewalURL)
	public:
		TElNetscapeRenewalURL(TElNetscapeRenewalURLHandle handle, TElOwnHandle ownHandle);

		TElNetscapeRenewalURL();

};
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
class TElNetscapeCAPolicy: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeCAPolicy)
	public:
		TElNetscapeCAPolicy(TElNetscapeCAPolicyHandle handle, TElOwnHandle ownHandle);

		TElNetscapeCAPolicy();

};
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */

#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
class TElNetscapeServerName: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeServerName)
	public:
		TElNetscapeServerName(TElNetscapeServerNameHandle handle, TElOwnHandle ownHandle);

		TElNetscapeServerName();

};
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */

#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
class TElNetscapeComment: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElNetscapeComment)
	public:
		TElNetscapeComment(TElNetscapeCommentHandle handle, TElOwnHandle ownHandle);

		TElNetscapeComment();

};
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */

#ifdef SB_USE_CLASS_TELCOMMONNAME
class TElCommonName: public TElNetscapeString
{
	private:
		SB_DISABLE_COPY(TElCommonName)
	public:
		TElCommonName(TElCommonNameHandle handle, TElOwnHandle ownHandle);

		TElCommonName();

};
#endif /* SB_USE_CLASS_TELCOMMONNAME */

#ifdef SB_USE_CLASS_TELUSERNOTICE
class TElUserNotice: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElUserNotice)
	public:
		virtual void get_Organization(std::string &OutResult);

		virtual void set_Organization(const std::string &Value);

		virtual int32_t get_NoticeNumbers(int32_t Index);

		virtual void set_NoticeNumbers(int32_t Index, int32_t Value);

		virtual int32_t get_NoticeNumbersCount();

		virtual void set_NoticeNumbersCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_NoticeNumbersCount, set_NoticeNumbersCount, TElUserNotice, NoticeNumbersCount);

		virtual void get_ExplicitText(std::string &OutResult);

		virtual void set_ExplicitText(const std::string &Value);

		TElUserNotice(TElUserNoticeHandle handle, TElOwnHandle ownHandle);

		TElUserNotice();

};
#endif /* SB_USE_CLASS_TELUSERNOTICE */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
class TElSinglePolicyQualifier: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSinglePolicyQualifier)
#ifdef SB_USE_CLASS_TELUSERNOTICE
		TElUserNotice* _Inst_UserNotice;
#endif /* SB_USE_CLASS_TELUSERNOTICE */

		void initInstances();

	public:
		virtual void get_CPSURI(std::string &OutResult);

		virtual void set_CPSURI(const std::string &Value);

#ifdef SB_USE_CLASS_TELUSERNOTICE
		virtual TElUserNotice* get_UserNotice();

		SB_DECLARE_PROPERTY_GET(TElUserNotice*, get_UserNotice, TElSinglePolicyQualifier, UserNotice);
#endif /* SB_USE_CLASS_TELUSERNOTICE */

		TElSinglePolicyQualifier(TElSinglePolicyQualifierHandle handle, TElOwnHandle ownHandle);

		TElSinglePolicyQualifier();

		virtual ~TElSinglePolicyQualifier();

};
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
class TElSinglePolicyInformation: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSinglePolicyInformation)
#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
		TElSinglePolicyQualifier* _Inst_Qualifiers;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

		void initInstances();

	public:
		virtual void get_PolicyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_PolicyIdentifier(const std::vector<uint8_t> &Value);

		virtual int32_t get_QualifierCount();

		virtual void set_QualifierCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_QualifierCount, set_QualifierCount, TElSinglePolicyInformation, QualifierCount);

#ifdef SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER
		virtual TElSinglePolicyQualifier* get_Qualifiers(int32_t Index);
#endif /* SB_USE_CLASS_TELSINGLEPOLICYQUALIFIER */

		TElSinglePolicyInformation(TElSinglePolicyInformationHandle handle, TElOwnHandle ownHandle);

		TElSinglePolicyInformation();

		virtual ~TElSinglePolicyInformation();

};
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
class TElCertificatePoliciesExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElCertificatePoliciesExtension)
#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
		TElSinglePolicyInformation* _Inst_PolicyInformation;
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

		void initInstances();

	public:
		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
		virtual TElSinglePolicyInformation* get_PolicyInformation(int32_t Index);
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElCertificatePoliciesExtension, Count);

		TElCertificatePoliciesExtension(TElCertificatePoliciesExtensionHandle handle, TElOwnHandle ownHandle);

		TElCertificatePoliciesExtension();

		virtual ~TElCertificatePoliciesExtension();

};
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYMAPPING
class TElPolicyMapping: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElPolicyMapping)
	public:
		virtual void get_IssuerDomainPolicy(std::vector<uint8_t> &OutResult);

		virtual void set_IssuerDomainPolicy(const std::vector<uint8_t> &Value);

		virtual void get_SubjectDomainPolicy(std::vector<uint8_t> &OutResult);

		virtual void set_SubjectDomainPolicy(const std::vector<uint8_t> &Value);

		TElPolicyMapping(TElPolicyMappingHandle handle, TElOwnHandle ownHandle);

		TElPolicyMapping();

};
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
class TElPolicyMappingsExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElPolicyMappingsExtension)
#ifdef SB_USE_CLASS_TELPOLICYMAPPING
		TElPolicyMapping* _Inst_Policies;
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

		void initInstances();

	public:
		void Remove(int32_t Index);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElPolicyMappingsExtension, Count);

#ifdef SB_USE_CLASS_TELPOLICYMAPPING
		virtual TElPolicyMapping* get_Policies(int32_t Index);
#endif /* SB_USE_CLASS_TELPOLICYMAPPING */

		TElPolicyMappingsExtension(TElPolicyMappingsExtensionHandle handle, TElOwnHandle ownHandle);

		TElPolicyMappingsExtension();

		virtual ~TElPolicyMappingsExtension();

};
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
class TElAlternativeNameExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElAlternativeNameExtension)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_Content;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_Content();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_Content, TElAlternativeNameExtension, Content);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		TElAlternativeNameExtension(TElAlternativeNameExtensionHandle handle, TElOwnHandle ownHandle);

		explicit TElAlternativeNameExtension(bool IssuerAltName);

		virtual ~TElAlternativeNameExtension();

};
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
class TElBasicConstraintsExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElBasicConstraintsExtension)
	public:
		virtual bool get_CA();

		virtual void set_CA(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CA, set_CA, TElBasicConstraintsExtension, CA);

		virtual int32_t get_PathLenConstraint();

		virtual void set_PathLenConstraint(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PathLenConstraint, set_PathLenConstraint, TElBasicConstraintsExtension, PathLenConstraint);

		TElBasicConstraintsExtension(TElBasicConstraintsExtensionHandle handle, TElOwnHandle ownHandle);

		TElBasicConstraintsExtension();

};
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
class TElNameConstraint: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElNameConstraint)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_Base;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_Base();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_Base, TElNameConstraint, Base);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		virtual int32_t get_Minimum();

		virtual void set_Minimum(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Minimum, set_Minimum, TElNameConstraint, Minimum);

		virtual int32_t get_Maximum();

		virtual void set_Maximum(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Maximum, set_Maximum, TElNameConstraint, Maximum);

		TElNameConstraint(TElNameConstraintHandle handle, TElOwnHandle ownHandle);

		TElNameConstraint();

		virtual ~TElNameConstraint();

};
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
class TElNameConstraintsExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElNameConstraintsExtension)
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
		TElNameConstraint* _Inst_PermittedSubtrees;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
		TElNameConstraint* _Inst_ExcludedSubtrees;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELGENERALNAMES_AND_TELRELATIVEDISTINGUISHEDNAME
		bool AreNamesAcceptable(TElRelativeDistinguishedName &Subj, TElGeneralNames &SubjAltName);

		bool AreNamesAcceptable(TElRelativeDistinguishedName *Subj, TElGeneralNames *SubjAltName);
#endif /* SB_USE_CLASSES_TELGENERALNAMES_AND_TELRELATIVEDISTINGUISHEDNAME */

		void RemovePermitted(int32_t Index);

		void RemoveExcluded(int32_t Index);

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
		virtual TElNameConstraint* get_PermittedSubtrees(int32_t Index);
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINT
		virtual TElNameConstraint* get_ExcludedSubtrees(int32_t Index);
#endif /* SB_USE_CLASS_TELNAMECONSTRAINT */

		virtual int32_t get_PermittedCount();

		virtual void set_PermittedCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PermittedCount, set_PermittedCount, TElNameConstraintsExtension, PermittedCount);

		virtual int32_t get_ExcludedCount();

		virtual void set_ExcludedCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExcludedCount, set_ExcludedCount, TElNameConstraintsExtension, ExcludedCount);

		TElNameConstraintsExtension(TElNameConstraintsExtensionHandle handle, TElOwnHandle ownHandle);

		TElNameConstraintsExtension();

		virtual ~TElNameConstraintsExtension();

};
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
class TElPolicyConstraintsExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElPolicyConstraintsExtension)
	public:
		virtual int32_t get_RequireExplicitPolicy();

		virtual void set_RequireExplicitPolicy(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RequireExplicitPolicy, set_RequireExplicitPolicy, TElPolicyConstraintsExtension, RequireExplicitPolicy);

		virtual int32_t get_InhibitPolicyMapping();

		virtual void set_InhibitPolicyMapping(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_InhibitPolicyMapping, set_InhibitPolicyMapping, TElPolicyConstraintsExtension, InhibitPolicyMapping);

		TElPolicyConstraintsExtension(TElPolicyConstraintsExtensionHandle handle, TElOwnHandle ownHandle);

		TElPolicyConstraintsExtension();

};
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
class TElExtendedKeyUsageExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElExtendedKeyUsageExtension)
	public:
		int32_t AddCustomUsage(const std::vector<uint8_t> &UsageOID);

		void RemoveCustomUsage(int32_t Index);

		void ClearCustomUsages();

		virtual int32_t get_TotalUsageCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TotalUsageCount, TElExtendedKeyUsageExtension, TotalUsageCount);

		virtual bool get_ServerAuthentication();

		virtual void set_ServerAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ServerAuthentication, set_ServerAuthentication, TElExtendedKeyUsageExtension, ServerAuthentication);

		virtual bool get_ClientAuthentication();

		virtual void set_ClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ClientAuthentication, set_ClientAuthentication, TElExtendedKeyUsageExtension, ClientAuthentication);

		virtual bool get_CodeSigning();

		virtual void set_CodeSigning(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CodeSigning, set_CodeSigning, TElExtendedKeyUsageExtension, CodeSigning);

		virtual bool get_EmailProtection();

		virtual void set_EmailProtection(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EmailProtection, set_EmailProtection, TElExtendedKeyUsageExtension, EmailProtection);

		virtual bool get_TimeStamping();

		virtual void set_TimeStamping(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TimeStamping, set_TimeStamping, TElExtendedKeyUsageExtension, TimeStamping);

		virtual bool get_OCSPSigning();

		virtual void set_OCSPSigning(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OCSPSigning, set_OCSPSigning, TElExtendedKeyUsageExtension, OCSPSigning);

		virtual bool get_SmartCardLogon();

		virtual void set_SmartCardLogon(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SmartCardLogon, set_SmartCardLogon, TElExtendedKeyUsageExtension, SmartCardLogon);

		virtual bool get_KeyPurposeClientAuth();

		virtual void set_KeyPurposeClientAuth(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeyPurposeClientAuth, set_KeyPurposeClientAuth, TElExtendedKeyUsageExtension, KeyPurposeClientAuth);

		virtual bool get_KeyPurposeKDC();

		virtual void set_KeyPurposeKDC(bool Value);

		SB_DECLARE_PROPERTY(bool, get_KeyPurposeKDC, set_KeyPurposeKDC, TElExtendedKeyUsageExtension, KeyPurposeKDC);

		virtual void get_CustomUsages(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_CustomUsages(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_CustomUsageCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CustomUsageCount, TElExtendedKeyUsageExtension, CustomUsageCount);

		TElExtendedKeyUsageExtension(TElExtendedKeyUsageExtensionHandle handle, TElOwnHandle ownHandle);

		TElExtendedKeyUsageExtension();

};
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
class TElDistributionPoint: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDistributionPoint)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_Name;
#endif /* SB_USE_CLASS_TELGENERALNAMES */
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_CRLIssuer;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_Name();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_Name, TElDistributionPoint, Name);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual TSBCRLReasonFlags get_ReasonFlags();

		virtual void set_ReasonFlags(TSBCRLReasonFlags Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlags, get_ReasonFlags, set_ReasonFlags, TElDistributionPoint, ReasonFlags);

#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_CRLIssuer();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_CRLIssuer, TElDistributionPoint, CRLIssuer);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual TElDistributionPointParameters get_Included();

		virtual void set_Included(TElDistributionPointParameters Value);

		SB_DECLARE_PROPERTY(TElDistributionPointParameters, get_Included, set_Included, TElDistributionPoint, Included);

		TElDistributionPoint(TElDistributionPointHandle handle, TElOwnHandle ownHandle);

		TElDistributionPoint();

		virtual ~TElDistributionPoint();

};
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
class TElCRLDistributionPointsExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElCRLDistributionPointsExtension)
#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
		TElDistributionPoint* _Inst_DistributionPoints;
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

		void initInstances();

	public:
		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
		virtual TElDistributionPoint* get_DistributionPoints(int32_t Index);
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElCRLDistributionPointsExtension, Count);

		TElCRLDistributionPointsExtension(TElCRLDistributionPointsExtensionHandle handle, TElOwnHandle ownHandle);

		TElCRLDistributionPointsExtension();

		virtual ~TElCRLDistributionPointsExtension();

};
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */

#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
class TElAccessDescription: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElAccessDescription)
#ifdef SB_USE_CLASS_TELGENERALNAME
		TElGeneralName* _Inst_AccessLocation;
#endif /* SB_USE_CLASS_TELGENERALNAME */

		void initInstances();

	public:
		virtual void get_AccessMethod(std::vector<uint8_t> &OutResult);

		virtual void set_AccessMethod(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELGENERALNAME
		virtual TElGeneralName* get_AccessLocation();

		SB_DECLARE_PROPERTY_GET(TElGeneralName*, get_AccessLocation, TElAccessDescription, AccessLocation);
#endif /* SB_USE_CLASS_TELGENERALNAME */

		TElAccessDescription(TElAccessDescriptionHandle handle, TElOwnHandle ownHandle);

		TElAccessDescription();

		virtual ~TElAccessDescription();

};
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
class TElAuthorityInformationAccessExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElAuthorityInformationAccessExtension)
#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
		TElAccessDescription* _Inst_AccessDescriptions;
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

		void initInstances();

	public:
		void Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELACCESSDESCRIPTION
		virtual TElAccessDescription* get_AccessDescriptions(int32_t Index);
#endif /* SB_USE_CLASS_TELACCESSDESCRIPTION */

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElAuthorityInformationAccessExtension, Count);

		TElAuthorityInformationAccessExtension(TElAuthorityInformationAccessExtensionHandle handle, TElOwnHandle ownHandle);

		TElAuthorityInformationAccessExtension();

		virtual ~TElAuthorityInformationAccessExtension();

};
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
class TElSubjectDirectoryAttributesExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElSubjectDirectoryAttributesExtension)
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_Attributes, TElSubjectDirectoryAttributesExtension, Attributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		TElSubjectDirectoryAttributesExtension(TElSubjectDirectoryAttributesExtensionHandle handle, TElOwnHandle ownHandle);

		TElSubjectDirectoryAttributesExtension();

		virtual ~TElSubjectDirectoryAttributesExtension();

};
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
class TElCertificateExtensions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCertificateExtensions)
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
		TElAuthorityKeyIdentifierExtension* _Inst_AuthorityKeyIdentifier;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
		TElSubjectKeyIdentifierExtension* _Inst_SubjectKeyIdentifier;
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */
#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
		TElKeyUsageExtension* _Inst_KeyUsage;
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
		TElPrivateKeyUsagePeriodExtension* _Inst_PrivateKeyUsagePeriod;
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
		TElCertificatePoliciesExtension* _Inst_CertificatePolicies;
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
		TElPolicyMappingsExtension* _Inst_PolicyMappings;
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		TElAlternativeNameExtension* _Inst_SubjectAlternativeName;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		TElAlternativeNameExtension* _Inst_IssuerAlternativeName;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
		TElBasicConstraintsExtension* _Inst_BasicConstraints;
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
		TElNameConstraintsExtension* _Inst_NameConstraints;
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
		TElPolicyConstraintsExtension* _Inst_PolicyConstraints;
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
		TElExtendedKeyUsageExtension* _Inst_ExtendedKeyUsage;
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
		TElCRLDistributionPointsExtension* _Inst_CRLDistributionPoints;
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */
#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
		TElAuthorityInformationAccessExtension* _Inst_AuthorityInformationAccess;
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
		TElNetscapeCertTypeExtension* _Inst_NetscapeCertType;
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */
#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
		TElNetscapeComment* _Inst_NetscapeComment;
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */
#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
		TElNetscapeBaseURL* _Inst_NetscapeBaseURL;
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */
#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
		TElNetscapeRevokeURL* _Inst_NetscapeRevokeURL;
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
		TElNetscapeCARevokeURL* _Inst_NetscapeCARevokeURL;
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */
#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
		TElNetscapeRenewalURL* _Inst_NetscapeRenewalURL;
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */
#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
		TElNetscapeCAPolicy* _Inst_NetscapeCAPolicy;
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */
#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
		TElNetscapeServerName* _Inst_NetscapeServerName;
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */
#ifdef SB_USE_CLASS_TELCOMMONNAME
		TElCommonName* _Inst_CommonName;
#endif /* SB_USE_CLASS_TELCOMMONNAME */
#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
		TElSubjectDirectoryAttributesExtension* _Inst_SubjectDirectoryAttributes;
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		TElCustomExtension* _Inst_OtherExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		void initInstances();

	public:
		bool RemoveOther(int32_t Index);

		void ClearExtensions();

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION
		virtual TElAuthorityKeyIdentifierExtension* get_AuthorityKeyIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAuthorityKeyIdentifierExtension*, get_AuthorityKeyIdentifier, TElCertificateExtensions, AuthorityKeyIdentifier);
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION
		virtual TElSubjectKeyIdentifierExtension* get_SubjectKeyIdentifier();

		SB_DECLARE_PROPERTY_GET(TElSubjectKeyIdentifierExtension*, get_SubjectKeyIdentifier, TElCertificateExtensions, SubjectKeyIdentifier);
#endif /* SB_USE_CLASS_TELSUBJECTKEYIDENTIFIEREXTENSION */

#ifdef SB_USE_CLASS_TELKEYUSAGEEXTENSION
		virtual TElKeyUsageExtension* get_KeyUsage();

		virtual void set_KeyUsage(TElKeyUsageExtension &Value);

		virtual void set_KeyUsage(TElKeyUsageExtension *Value);

		SB_DECLARE_PROPERTY(TElKeyUsageExtension*, get_KeyUsage, set_KeyUsage, TElCertificateExtensions, KeyUsage);
#endif /* SB_USE_CLASS_TELKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION
		virtual TElPrivateKeyUsagePeriodExtension* get_PrivateKeyUsagePeriod();

		virtual void set_PrivateKeyUsagePeriod(TElPrivateKeyUsagePeriodExtension &Value);

		virtual void set_PrivateKeyUsagePeriod(TElPrivateKeyUsagePeriodExtension *Value);

		SB_DECLARE_PROPERTY(TElPrivateKeyUsagePeriodExtension*, get_PrivateKeyUsagePeriod, set_PrivateKeyUsagePeriod, TElCertificateExtensions, PrivateKeyUsagePeriod);
#endif /* SB_USE_CLASS_TELPRIVATEKEYUSAGEPERIODEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION
		virtual TElCertificatePoliciesExtension* get_CertificatePolicies();

		SB_DECLARE_PROPERTY_GET(TElCertificatePoliciesExtension*, get_CertificatePolicies, TElCertificateExtensions, CertificatePolicies);
#endif /* SB_USE_CLASS_TELCERTIFICATEPOLICIESEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION
		virtual TElPolicyMappingsExtension* get_PolicyMappings();

		virtual void set_PolicyMappings(TElPolicyMappingsExtension &Value);

		virtual void set_PolicyMappings(TElPolicyMappingsExtension *Value);

		SB_DECLARE_PROPERTY(TElPolicyMappingsExtension*, get_PolicyMappings, set_PolicyMappings, TElCertificateExtensions, PolicyMappings);
#endif /* SB_USE_CLASS_TELPOLICYMAPPINGSEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		virtual TElAlternativeNameExtension* get_SubjectAlternativeName();

		virtual void set_SubjectAlternativeName(TElAlternativeNameExtension &Value);

		virtual void set_SubjectAlternativeName(TElAlternativeNameExtension *Value);

		SB_DECLARE_PROPERTY(TElAlternativeNameExtension*, get_SubjectAlternativeName, set_SubjectAlternativeName, TElCertificateExtensions, SubjectAlternativeName);
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		virtual TElAlternativeNameExtension* get_IssuerAlternativeName();

		virtual void set_IssuerAlternativeName(TElAlternativeNameExtension &Value);

		virtual void set_IssuerAlternativeName(TElAlternativeNameExtension *Value);

		SB_DECLARE_PROPERTY(TElAlternativeNameExtension*, get_IssuerAlternativeName, set_IssuerAlternativeName, TElCertificateExtensions, IssuerAlternativeName);
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION
		virtual TElBasicConstraintsExtension* get_BasicConstraints();

		virtual void set_BasicConstraints(TElBasicConstraintsExtension &Value);

		virtual void set_BasicConstraints(TElBasicConstraintsExtension *Value);

		SB_DECLARE_PROPERTY(TElBasicConstraintsExtension*, get_BasicConstraints, set_BasicConstraints, TElCertificateExtensions, BasicConstraints);
#endif /* SB_USE_CLASS_TELBASICCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION
		virtual TElNameConstraintsExtension* get_NameConstraints();

		SB_DECLARE_PROPERTY_GET(TElNameConstraintsExtension*, get_NameConstraints, TElCertificateExtensions, NameConstraints);
#endif /* SB_USE_CLASS_TELNAMECONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION
		virtual TElPolicyConstraintsExtension* get_PolicyConstraints();

		virtual void set_PolicyConstraints(TElPolicyConstraintsExtension &Value);

		virtual void set_PolicyConstraints(TElPolicyConstraintsExtension *Value);

		SB_DECLARE_PROPERTY(TElPolicyConstraintsExtension*, get_PolicyConstraints, set_PolicyConstraints, TElCertificateExtensions, PolicyConstraints);
#endif /* SB_USE_CLASS_TELPOLICYCONSTRAINTSEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION
		virtual TElExtendedKeyUsageExtension* get_ExtendedKeyUsage();

		SB_DECLARE_PROPERTY_GET(TElExtendedKeyUsageExtension*, get_ExtendedKeyUsage, TElCertificateExtensions, ExtendedKeyUsage);
#endif /* SB_USE_CLASS_TELEXTENDEDKEYUSAGEEXTENSION */

#ifdef SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION
		virtual TElCRLDistributionPointsExtension* get_CRLDistributionPoints();

		SB_DECLARE_PROPERTY_GET(TElCRLDistributionPointsExtension*, get_CRLDistributionPoints, TElCertificateExtensions, CRLDistributionPoints);
#endif /* SB_USE_CLASS_TELCRLDISTRIBUTIONPOINTSEXTENSION */

#ifdef SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION
		virtual TElAuthorityInformationAccessExtension* get_AuthorityInformationAccess();

		SB_DECLARE_PROPERTY_GET(TElAuthorityInformationAccessExtension*, get_AuthorityInformationAccess, TElCertificateExtensions, AuthorityInformationAccess);
#endif /* SB_USE_CLASS_TELAUTHORITYINFORMATIONACCESSEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION
		virtual TElNetscapeCertTypeExtension* get_NetscapeCertType();

		virtual void set_NetscapeCertType(TElNetscapeCertTypeExtension &Value);

		virtual void set_NetscapeCertType(TElNetscapeCertTypeExtension *Value);

		SB_DECLARE_PROPERTY(TElNetscapeCertTypeExtension*, get_NetscapeCertType, set_NetscapeCertType, TElCertificateExtensions, NetscapeCertType);
#endif /* SB_USE_CLASS_TELNETSCAPECERTTYPEEXTENSION */

#ifdef SB_USE_CLASS_TELNETSCAPECOMMENT
		virtual TElNetscapeComment* get_NetscapeComment();

		virtual void set_NetscapeComment(TElNetscapeComment &Value);

		virtual void set_NetscapeComment(TElNetscapeComment *Value);

		SB_DECLARE_PROPERTY(TElNetscapeComment*, get_NetscapeComment, set_NetscapeComment, TElCertificateExtensions, NetscapeComment);
#endif /* SB_USE_CLASS_TELNETSCAPECOMMENT */

#ifdef SB_USE_CLASS_TELNETSCAPEBASEURL
		virtual TElNetscapeBaseURL* get_NetscapeBaseURL();

		virtual void set_NetscapeBaseURL(TElNetscapeBaseURL &Value);

		virtual void set_NetscapeBaseURL(TElNetscapeBaseURL *Value);

		SB_DECLARE_PROPERTY(TElNetscapeBaseURL*, get_NetscapeBaseURL, set_NetscapeBaseURL, TElCertificateExtensions, NetscapeBaseURL);
#endif /* SB_USE_CLASS_TELNETSCAPEBASEURL */

#ifdef SB_USE_CLASS_TELNETSCAPEREVOKEURL
		virtual TElNetscapeRevokeURL* get_NetscapeRevokeURL();

		virtual void set_NetscapeRevokeURL(TElNetscapeRevokeURL &Value);

		virtual void set_NetscapeRevokeURL(TElNetscapeRevokeURL *Value);

		SB_DECLARE_PROPERTY(TElNetscapeRevokeURL*, get_NetscapeRevokeURL, set_NetscapeRevokeURL, TElCertificateExtensions, NetscapeRevokeURL);
#endif /* SB_USE_CLASS_TELNETSCAPEREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAREVOKEURL
		virtual TElNetscapeCARevokeURL* get_NetscapeCARevokeURL();

		virtual void set_NetscapeCARevokeURL(TElNetscapeCARevokeURL &Value);

		virtual void set_NetscapeCARevokeURL(TElNetscapeCARevokeURL *Value);

		SB_DECLARE_PROPERTY(TElNetscapeCARevokeURL*, get_NetscapeCARevokeURL, set_NetscapeCARevokeURL, TElCertificateExtensions, NetscapeCARevokeURL);
#endif /* SB_USE_CLASS_TELNETSCAPECAREVOKEURL */

#ifdef SB_USE_CLASS_TELNETSCAPERENEWALURL
		virtual TElNetscapeRenewalURL* get_NetscapeRenewalURL();

		virtual void set_NetscapeRenewalURL(TElNetscapeRenewalURL &Value);

		virtual void set_NetscapeRenewalURL(TElNetscapeRenewalURL *Value);

		SB_DECLARE_PROPERTY(TElNetscapeRenewalURL*, get_NetscapeRenewalURL, set_NetscapeRenewalURL, TElCertificateExtensions, NetscapeRenewalURL);
#endif /* SB_USE_CLASS_TELNETSCAPERENEWALURL */

#ifdef SB_USE_CLASS_TELNETSCAPECAPOLICY
		virtual TElNetscapeCAPolicy* get_NetscapeCAPolicy();

		virtual void set_NetscapeCAPolicy(TElNetscapeCAPolicy &Value);

		virtual void set_NetscapeCAPolicy(TElNetscapeCAPolicy *Value);

		SB_DECLARE_PROPERTY(TElNetscapeCAPolicy*, get_NetscapeCAPolicy, set_NetscapeCAPolicy, TElCertificateExtensions, NetscapeCAPolicy);
#endif /* SB_USE_CLASS_TELNETSCAPECAPOLICY */

#ifdef SB_USE_CLASS_TELNETSCAPESERVERNAME
		virtual TElNetscapeServerName* get_NetscapeServerName();

		virtual void set_NetscapeServerName(TElNetscapeServerName &Value);

		virtual void set_NetscapeServerName(TElNetscapeServerName *Value);

		SB_DECLARE_PROPERTY(TElNetscapeServerName*, get_NetscapeServerName, set_NetscapeServerName, TElCertificateExtensions, NetscapeServerName);
#endif /* SB_USE_CLASS_TELNETSCAPESERVERNAME */

#ifdef SB_USE_CLASS_TELCOMMONNAME
		virtual TElCommonName* get_CommonName();

		virtual void set_CommonName(TElCommonName &Value);

		virtual void set_CommonName(TElCommonName *Value);

		SB_DECLARE_PROPERTY(TElCommonName*, get_CommonName, set_CommonName, TElCertificateExtensions, CommonName);
#endif /* SB_USE_CLASS_TELCOMMONNAME */

#ifdef SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION
		virtual TElSubjectDirectoryAttributesExtension* get_SubjectDirectoryAttributes();

		SB_DECLARE_PROPERTY_GET(TElSubjectDirectoryAttributesExtension*, get_SubjectDirectoryAttributes, TElCertificateExtensions, SubjectDirectoryAttributes);
#endif /* SB_USE_CLASS_TELSUBJECTDIRECTORYATTRIBUTESEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		virtual TElCustomExtension* get_OtherExtensions(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		virtual int32_t get_OtherCount();

		virtual void set_OtherCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OtherCount, set_OtherCount, TElCertificateExtensions, OtherCount);

		virtual TSBCertificateExtensions get_Included();

		virtual void set_Included(TSBCertificateExtensions Value);

		SB_DECLARE_PROPERTY(TSBCertificateExtensions, get_Included, set_Included, TElCertificateExtensions, Included);

		TElCertificateExtensions(TElCertificateExtensionsHandle handle, TElOwnHandle ownHandle);

		TElCertificateExtensions();

		virtual ~TElCertificateExtensions();

};
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

#ifdef SB_USE_CLASS_TELEXTENSIONWRITER
class TElExtensionWriter: public TObject
{
	private:
		SB_DISABLE_COPY(TElExtensionWriter)
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		void initInstances();

	public:
		void WriteExtensions(std::vector<uint8_t> &OutResult);

		void WriteExtension(const std::vector<uint8_t> &OID, bool Critical, const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult);

		void WriteExtensionBasicConstraints(std::vector<uint8_t> &OutResult);

		void WriteExtensionKeyUsage(std::vector<uint8_t> &OutResult);

		void WriteExtensionPrivateKeyUsagePeriod(std::vector<uint8_t> &OutResult);

		void WriteExtensionSubjectAltName(std::vector<uint8_t> &OutResult);

		void WriteExtensionIssuerAltName(std::vector<uint8_t> &OutResult);

		void WriteExtensionExtendedKeyUsage(std::vector<uint8_t> &OutResult);

		void WriteExtensionPolicyMappings(std::vector<uint8_t> &OutResult);

		void WriteExtensionNameConstraints(std::vector<uint8_t> &OutResult);

		void WriteExtensionPolicyConstraints(std::vector<uint8_t> &OutResult);

		void WriteExtensionCertificatePolicies(std::vector<uint8_t> &OutResult);

		void WriteExtensionAuthorityKeyIdentifier(std::vector<uint8_t> &OutResult);

		void WriteExtensionCRLDistributionPoints(std::vector<uint8_t> &OutResult);

		void WriteExtensionAuthorityInformationAccess(std::vector<uint8_t> &OutResult);

		void WriteExtensionNetscapeCertType(std::vector<uint8_t> &OutResult);

		void WriteExtensionNetscapeString(const std::vector<uint8_t> &AOID, const std::string &ANetStr, std::vector<uint8_t> &OutResult);

		void WriteExtensionNetscapeString(const std::vector<uint8_t> &AOID, const std::vector<uint8_t> &ANetStr, std::vector<uint8_t> &OutResult);

		void WriteExtensionSubjectKeyIdentifier(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELSINGLEPOLICYINFORMATION
		void WritePolicyInformation(TElSinglePolicyInformation &P, std::vector<uint8_t> &OutResult);

		void WritePolicyInformation(TElSinglePolicyInformation *P, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSINGLEPOLICYINFORMATION */

#ifdef SB_USE_CLASS_TELDISTRIBUTIONPOINT
		void WriteDistributionPoint(TElDistributionPoint &P, std::vector<uint8_t> &OutResult);

		void WriteDistributionPoint(TElDistributionPoint *P, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELDISTRIBUTIONPOINT */

		void WriteExtensionSubjectDirectoryAttributes(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElExtensionWriter, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		virtual bool get_UseA3Prefix();

		virtual void set_UseA3Prefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseA3Prefix, set_UseA3Prefix, TElExtensionWriter, UseA3Prefix);

		virtual bool get_SaveDefaultASN1Tags();

		virtual void set_SaveDefaultASN1Tags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveDefaultASN1Tags, set_SaveDefaultASN1Tags, TElExtensionWriter, SaveDefaultASN1Tags);

		TElExtensionWriter(TElExtensionWriterHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElExtensionWriter(TElCertificateExtensions &Exts, bool CertExtensions);

		TElExtensionWriter(TElCertificateExtensions *Exts, bool CertExtensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		virtual ~TElExtensionWriter();

};
#endif /* SB_USE_CLASS_TELEXTENSIONWRITER */

#ifdef SB_USE_CLASS_TELEXTENSIONREADER
class TElExtensionReader: public TObject
{
	private:
		SB_DISABLE_COPY(TElExtensionReader)
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		void initInstances();

	public:
		void ParseExtension(const std::vector<uint8_t> &OID, bool Critical, const std::vector<uint8_t> &Content);

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElExtensionReader, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		TElExtensionReader(TElExtensionReaderHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElExtensionReader(TElCertificateExtensions &Exts, bool StrictMode);

		TElExtensionReader(TElCertificateExtensions *Exts, bool StrictMode);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		virtual ~TElExtensionReader();

};
#endif /* SB_USE_CLASS_TELEXTENSIONREADER */

#ifdef SB_USE_GLOBAL_PROCS_X509EXT

void OctetsToIPAddress(const std::vector<uint8_t> &Octets, std::string &OutResult);

void IPAddressToOctets(const std::string &IPAddrStr, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_X509EXT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_X509EXT
SB_IMPORT uint32_t SB_APIENTRY SBX509Ext_OctetsToIPAddress(const uint8_t pOctets[], int32_t szOctets, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBX509Ext_IPAddressToOctets(const char * pcIPAddrStr, int32_t szIPAddrStr, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_X509EXT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBX509EXT */

