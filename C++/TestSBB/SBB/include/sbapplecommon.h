#ifndef __INC_SBAPPLECOMMON
#define __INC_SBAPPLECOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifdef MACOS
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"
#include "sbstrutils.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_NOT_MACOS_OR_IOS
#define SB_kAuthorizationEmptyEnvironment 	NULL

#endif
#ifdef MACOS
typedef PChar SB_MarshaledString;

typedef Pointer SB_CFTypeRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFError, * SB_CFErrorRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFNull, * SB_CFNullRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFArray, * SB_CFArrayRef, * SB_CFMutableArrayRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFDictionary, * SB_CFDictionaryRef, * SB_CFMutableDictionaryRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFBoolean, * SB_CFBooleanRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFAllocator, * SB_CFAllocatorRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFString, * SB_CFStringRef;

#pragma pack(4)
typedef struct 
{
} __SB_CFData, * SB_CFDataRef, * SB_CFMutableDataRef;

#pragma pack(4)
typedef struct 
{
	int64_t location;
	int64_t length;
} SB_CFRange;

typedef uint8_t SB_CFComparisionResultRaw;

typedef enum
{
	SB_SB_kCFCompareLessThan = -1,
	SB_SB_kCFCompareEqualTo = 0,
	SB_SB_kCFCompareGreaterThan = 1
} SB_CFComparisionResult;

typedef uint16_t SB_CFStringCompareFlagsRaw;

typedef enum
{
	SB_SB_kCFCompareCaseInsensitive = 1,
	SB_SB_kCFCompareBackwards = 4,
	SB_SB_kCFCompareAnchored = 8,
	SB_SB_kCFCompareNonliteral = 16,
	SB_SB_kCFCompareLocalized = 32,
	SB_SB_kCFCompareNumerically = 64,
	SB_SB_kCFCompareDiacriticInsensitive = 128,
	SB_SB_kCFCompareWidthInsensitive = 256,
	SB_SB_kCFCompareForcedOrdering = 512
} SB_CFStringCompareFlags;

typedef uint32_t SB_CFStringEncodingRaw;

typedef enum
{
	SB_SB_kCFStringEncodingMacRoman = 0,
	SB_SB_kCFStringEncodingWindowsLatin1 = 1280,
	SB_SB_kCFStringEncodingUTF16 = 256,
	SB_SB_kCFStringEncodingUnicode = 256,
	SB_SB_kCFStringEncodingISOLatin1 = 513,
	SB_SB_kCFStringEncodingNextStepLatin = 2817,
	SB_SB_kCFStringEncodingASCII = 1536,
	SB_SB_kCFStringEncodingUTF8 = 134217984,
	SB_SB_kCFStringEncodingNonLossyASCII = 3071,
	SB_SB_kCFStringEncodingUTF16BE = 268435712,
	SB_SB_kCFStringEncodingUTF32 = 201326848,
	SB_SB_kCFStringEncodingUTF16LE = 335544576,
	SB_SB_kCFStringEncodingUTF32BE = 402653440,
	SB_SB_kCFStringEncodingUTF32LE = 469762304
} SB_CFStringEncoding;

typedef void (SB_CALLBACK *SB_CFDictionaryRetainCallBack)(SB_CFAllocatorRef allocator, void * value, void * (* OutResult));

typedef void (SB_CALLBACK *SB_CFDictionaryReleaseCallBack)(SB_CFAllocatorRef allocator, void * value);

typedef void (SB_CALLBACK *SB_CFDictionaryCopyDescriptionCallBack)(void * value, SB_CFStringRef (* OutResult));

typedef void (SB_CALLBACK *SB_CFDictionaryEqualCallBack)(void * value1, void * value2, int8_t * OutResult);

typedef void (SB_CALLBACK *SB_CFDictionaryHashCallBack)(void * value, uint32_t * OutResult);

#pragma pack(4)
typedef struct 
{
	int64_t version;
	void * retain;
	void * release;
	void * copyDescription;
	void * equal;
	void * hash;
} SB_CFDictionaryKeyCallBacks, * SB_PCFDictionaryKeyCallBacks;

#pragma pack(4)
typedef struct 
{
	int64_t version;
	void * retain;
	void * release;
	void * copyDescription;
	void * equal;
} SB_CFDictionaryValueCallBacks, * SB_PCFDictionaryValueCallBacks;

typedef void (SB_CALLBACK *SB_CFArrayRetainCallBack)(SB_CFAllocatorRef allocator, void * value, void * (* OutResult));

typedef void (SB_CALLBACK *SB_CFArrayReleaseCallBack)(SB_CFAllocatorRef allocator, void * value);

typedef void (SB_CALLBACK *SB_CFArrayCopyDescriptionCallBack)(void * value, SB_CFStringRef (* OutResult));

typedef void (SB_CALLBACK *SB_CFArrayEqualCallBack)(void * value1, void * value2, int8_t * OutResult);

#pragma pack(4)
typedef struct 
{
	int64_t version;
	void * retain;
	void * release;
	void * copyDescription;
	void * equal;
} SB_CFArrayCallBacks, * SB_PCFArrayCallBacks;

#ifndef SB_IOS
typedef uint8_t SB_SecKeychainStatusRaw;

typedef enum
{
	SB_SB_kSecUnlockStateStatus = 1,
	SB_SB_kSecReadPermStatus = 2,
	SB_SB_UnlockReadPermStatus = 3,
	SB_SB_kSecWritePermStatus = 4,
	SB_SB_UnlockWritePermStatus = 5,
	SB_SB_ReadWritePermStatus = 6,
	SB_SB_UnlockReadWritePermStatus = 7
} SB_SecKeychainStatus;

typedef SB_SecKeychainStatusRaw * SB_PSecKeychainStatus;

typedef uint8_t SB_SecExternalFormatRaw;

typedef enum
{
	SB_SB_kSecFormatUnknown = 0,
	SB_SB_kSecFormatOpenSSL = 1,
	SB_SB_kSecFormatSSH = 2,
	SB_SB_kSecFormatBSAFE = 3,
	SB_SB_kSecFormatRawKey = 4,
	SB_SB_kSecFormatWrappedPKCS8 = 5,
	SB_SB_kSecFormatWrappedOpenSSL = 6,
	SB_SB_kSecFormatWrappedSSH = 7,
	SB_SB_kSecFormatWrappedLSH = 8,
	SB_SB_kSecFormatX509Cert = 9,
	SB_SB_kSecFormatPEMSequence = 10,
	SB_SB_kSecFormatPKCS7 = 11,
	SB_SB_kSecFormatPKCS12 = 12,
	SB_SB_kSecFormatNetscapeCertSequence = 13,
	SB_SB_kSecFormatSSHv2 = 14
} SB_SecExternalFormat;

typedef SB_SecExternalFormatRaw * SB_PSecExternalFormat;

typedef uint8_t SB_SecExternalItemTypeRaw;

typedef enum
{
	SB_SB_kSecItemTypeUnknown = 0,
	SB_SB_kSecItemTypePrivateKey = 1,
	SB_SB_kSecItemTypePublicKey = 2,
	SB_SB_kSecItemTypeSessionKey = 3,
	SB_SB_kSecItemTypeCertificate = 4,
	SB_SB_kSecItemTypeAggregate = 5
} SB_SecExternalItemType;

typedef SB_SecExternalItemTypeRaw * SB_PSecExternalItemType;

typedef uint8_t SB_SecItemImportExportFlagsRaw;

typedef enum
{
	SB_SB_kSecItemPemArmour = 1
} SB_SecItemImportExportFlags;

typedef uint8_t SB_SecKeyImportExportFlagsRaw;

typedef enum
{
	SB_SB_kSecKeyImportOnlyOne = 1,
	SB_SB_kSecKeySecurePassphrase = 2,
	SB_SB_kSecKeyNoAccessControl = 4
} SB_SecKeyImportExportFlags;

#endif
#pragma pack(4)
typedef struct 
{
#ifndef SB_IOS
} SB_OpaqueSecKeychainRef, * SB_SecKeychainRef;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecAccessRef, * SB_SecAccessRef;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecKeychainItemRef, * SB_SecKeychainItemRef;

#pragma pack(4)
typedef struct 
{
	uint32_t version;
	uint32_t flags;
	void * passphrase;
	SB_CFStringRef alertTitle;
	SB_CFStringRef alertPrompt;
	SB_SecAccessRef accessRef;
	SB_CFArrayRef keyUsage;
	SB_CFArrayRef keyAttrs;
} SB_SecItemImportExportKeyParameters, * SB_PSecItemImportExportKeyParameters;

typedef uint32_t SB_SecItemClassRaw;

typedef enum
{
	SB_SB_kSecCertificateItemClass = -2147479552,
	SB_SB_kSecGenericPasswordItemClass = 1734700656,
	SB_SB_kSecSymmetricKeyItemClass = 17,
	SB_SB_kSecPrivateKeyItemClass = 16,
	SB_SB_kSecPublicKeyItemClass = 15,
	SB_SB_kSecInternetPasswordItemClass = 1768842612
} SB_SecItemClass;

typedef uint32_t SB_SecItemAttrRaw;

typedef enum
{
	SB_SB_kSecAccountItemAttr = 1633903476,
	SB_SB_kSecCreationDateItemAttr = 1667522932,
	SB_SB_kSecAlias = 1634494835,
	SB_SB_kSecAddressItemAttr = 1633969266,
	SB_SB_kSecAuthenticationTypeItemAttr = 1635023216,
	SB_SB_kSecModDateItemAttr = 1835295092,
	SB_SB_kSecCrlEncoding = 1668443747,
	SB_SB_kSecCrlType = 1668445296,
	SB_SB_kSecCertificateEncoding = 1667591779,
	SB_SB_kSecCertificateType = 1668577648,
	SB_SB_kSecGenericItemAttr = 1734700641,
	SB_SB_kSecCustomIconItemAttr = 1668641641,
	SB_SB_kSecInvisibleItemAttr = 1768846953,
	SB_SB_kSecLabelItemAttr = 1818321516,
	SB_SB_kSecCreatorItemAttr = 1668445298,
	SB_SB_kSecCommentItemAttr = 1768123764,
	SB_SB_kSecDescriptionItemAttr = 1684370275,
	SB_SB_kSecTypeItemAttr = 1954115685,
	SB_SB_kSecProtocolItemAttr = 1886675820,
	SB_SB_kSecSignatureItemAttr = 1936943463,
	SB_SB_kSecPathItemAttr = 1885434984,
	SB_SB_kSecPortItemAttr = 1886351988,
	SB_SB_kSecServerItemAttr = 1936881266,
	SB_SB_kSecSecurityDomainItemAttr = 1935961454,
	SB_SB_kSecServiceItemAttr = 1937138533,
	SB_SB_kSecNegativeItemAttr = 1852139361,
	SB_SB_kSecScriptCodeItemAttr = 1935897200,
	SB_SB_kSecVolumeItemAttr = 1986817381
} SB_SecItemAttr;

#pragma pack(4)
typedef struct 
{
	SB_SecItemAttrRaw tag;
	uint32_t length;
	void * data;
} SB_SecKeychainAttribute, * SB_PSecKeychainAttribute;

#pragma pack(4)
typedef struct 
{
	uint32_t count;
	SB_SecKeychainAttribute * (* attrs);
} SB_SecKeychainAttributeList, * SB_PSecKeychainAttributeList;

typedef uint32_t SB_AuthorizationFlagsRaw;

typedef enum
{
	SB_SB_kAuthorizationFlagDefaults = 0,
	SB_SB_kAuthorizationFlagInteractionAllowed = 1,
	SB_SB_kAuthorizationFlagExtendRights = 2,
	SB_SB_kAuthorizationFlagPartialRights = 4,
	SB_SB_kAuthorizationFlagDestroyRights = 8,
	SB_SB_kAuthorizationFlagPreAuthorize = 16,
	SB_SB_kAuthorizationFlagNoData = 1048576
} SB_AuthorizationFlags;

#pragma pack(4)
typedef struct 
{
} SB_AuthorizationOpaqueRef, * SB_AuthorizationRef;

#pragma pack(4)
typedef struct 
{
	char * name;
	uint32_t valueLength;
	void * value;
	uint32_t flags;
} SB_AuthorizationItem, * SB_PAuthorizationItem;

#pragma pack(4)
typedef struct 
{
	uint32_t count;
	SB_AuthorizationItem * (* items);
} SB_AuthorizationItemSet, * SB_PAuthorizationItemSet;

typedef uint8_t SB_SecTrustSettingsDomainRaw;

typedef enum
{
	SB_SB_kSecTrustSettingsDomainUser = 0,
	SB_SB_kSecTrustSettingsDomainAdmin = 1,
	SB_SB_kSecTrustSettingsDomainSystem = 2
} SB_SecTrustSettingsDomain;

#pragma pack(4)
typedef struct 
{
#endif
} __SB_SecTrust, * SB_SecTrustRef;

typedef uint8_t SB_SecTrustResultTypeRaw;

typedef enum
{
	SB_SB_kSecTrustResultInvalid = 0,
	SB_SB_kSecTrustResultProceed = 1,
	SB_SB_kSecTrustResultDeny = 3,
	SB_SB_kSecTrustResultUnspecified = 4,
	SB_SB_kSecTrustResultRecoverableTrustFailure = 5,
	SB_SB_kSecTrustResultFatalTrustFailure = 6,
	SB_SB_kSecTrustResultOtherError = 7
} SB_SecTrustResultType;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecCertificateRef, * SB_SecCertificateRef;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecIdentityRef, * SB_SecIdentityRef;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecKeyRef, * SB_SecKeyRef;

#pragma pack(4)
typedef struct 
{
} SB_OpaqueSecPolicyRef, * SB_SecPolicyRef;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_APPLECOMMON

SB_CFNullRef SB_kCFNull();

SB_CFBooleanRef SB_kCFBooleanTrue();

SB_CFBooleanRef SB_kCFBooleanFalse();

SB_CFAllocatorRef SB_kCFAllocatorDefault();

void SB_kCFTypeDictionaryKeyCallBacks(SB_CFDictionaryKeyCallBacks &OutResult);

void SB_kCFTypeDictionaryValueCallBacks(SB_CFDictionaryValueCallBacks &OutResult);

void SB_kCFTypeArrayCallBacks(SB_CFArrayCallBacks &OutResult);

void * SB_kSecClass();

void * SB_kSecClassCertificate();

void * SB_kSecClassKey();

void * SB_kSecClassIdentity();

void * SB_kSecMatchLimit();

void * SB_kSecMatchSearchList();

void * SB_kSecMatchLimitAll();

void * SB_kSecMatchLimitOne();

void * SB_kSecMatchItemList();

void * SB_kSecMatchTrustedOnly();

void * SB_kSecMatchValidOnDate();

void * SB_kSecMatchSubjectContains();

void * SB_kSecMatchIssuers();

void * SB_kSecReturnRef();

void * SB_kSecReturnData();

void * SB_kSecReturnAttributes();

void * SB_kSecReturnPersistentRef();

void * SB_kSecUseItemList();

void * SB_kSecValueData();

void * SB_kSecValueRef();

void * SB_kSecValuePersistentRef();

void * SB_kSecAttrKeyClass();

void * SB_kSecAttrKeyClassPublic();

void * SB_kSecAttrKeyClassPrivate();

void * SB_kSecAttrKeyClassSymmetric();

void * SB_kSecAttrKeyType();

void * SB_kSecAttrKeyTypeRSA();

void * SB_kSecAttrKeyTypeEC();

void * SB_kSecAttrCanEncrypt();

void * SB_kSecAttrCanDecrypt();

void * SB_kSecAttrCanDerive();

void * SB_kSecAttrCanSign();

void * SB_kSecAttrCanVerify();

void * SB_kSecAttrCanWrap();

void * SB_kSecAttrCanUnwrap();

void * SB_kSecAttrIsPermanent();

void * SB_kSecAttrCertificateType();

void * SB_kSecAttrCertificateEncoding();

void * SB_kSecAttrLabel();

void * SB_kSecAttrSubject();

void * SB_kSecAttrIssuer();

void * SB_kSecAttrSerialNumber();

void * SB_kSecAttrSubjectKeyID();

void * SB_kSecAttrPublicKeyHash();

void * SB_kSecAttrApplicationLabel();

void * SB_kSecAttrApplicationTag();

void * SB_kSecAttrKeySizeInBits();

void * SB_kSecAttrEffectiveKeySize();

void * SB_kSecPropertyTypeTitle();

void * SB_kSecPropertyTypeError();

void * SB_kSecTrustEvaluationDate();

void * SB_kSecTrustExtendedValidation();

void * SB_kSecTrustOrganizationName();

void * SB_kSecTrustResultValue();

void * SB_kSecTrustRevocationChecked();

void * SB_kSecTrustRevocationValidUntilDate();

SB_CFStringRef SB_kSecImportExportPassphrase();

SB_CFStringRef SB_kSecImportItemLabel();

SB_CFStringRef SB_kSecImportItemKeyID();

SB_CFStringRef SB_kSecImportItemTrust();

SB_CFStringRef SB_kSecImportItemCertChain();

SB_CFStringRef SB_kSecImportItemIdentity();

#ifndef SB_IOS
SB_CFStringRef SB_kSecImportExportKeychain();
#else
void * SB_kSecAttrAccessible();
#endif

#ifndef SB_IOS
SB_CFStringRef SB_kSecImportExportAccess();
#else
void * SB_kSecAttrAccessGroup();
#endif

#ifndef SB_IOS
void * SB_kSecUseKeychain();
#else
void * SB_kSecAttrAccessibleWhenUnlocked();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyTypeDSA();
#else
void * SB_kSecAttrAccessibleAfterFirstUnlock();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyTypeAES();
#else
void * SB_kSecAttrAccessibleAlways();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyTypeDES();
#else
void * SB_kSecAttrAccessibleWhenUnlockedThisDeviceOnly();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyType3DES();
#else
void * SB_kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyTypeRC4();
#else
void * SB_kSecAttrAccessibleAlwaysThisDeviceOnly();
#endif

#ifndef SB_IOS
void * SB_kSecAttrKeyTypeRC2();

void * SB_kSecAttrKeyTypeCAST();

void * SB_kSecAttrKeyTypeECDSA();

void * SB_kSecAttrIsSensitive();

void * SB_kSecAttrIsExtractable();

void * SB_kSecAttrAccess();

#endif
int32_t SB_SecItemCopyMatching(SB_CFDictionaryRef query, void * &res);

int32_t SB_SecItemAdd(SB_CFDictionaryRef attributes, void * &res);

int32_t SB_SecItemUpdate(SB_CFDictionaryRef query, SB_CFDictionaryRef attrToUpdate);

int32_t SB_SecItemDelete(SB_CFDictionaryRef query);

SB_CFDataRef SB_SecCertificateCopyData(SB_SecCertificateRef cert);

SB_SecCertificateRef SB_SecCertificateCreateWithData(SB_CFAllocatorRef allocator, SB_CFDataRef data);

SB_CFStringRef SB_SecCertificateCopySubjectSummary(SB_SecCertificateRef cert);

int32_t SB_SecIdentityCopyCertificate(SB_SecIdentityRef identity, SB_SecCertificateRef &cert);

int32_t SB_SecIdentityCopyPrivateKey(SB_SecIdentityRef identity, SB_SecKeyRef &privateKey);

int32_t SB_SecTrustCreateWithCertificates(void * certs, void * policies, SB_SecTrustRef &trust);

int32_t SB_SecTrustSetAnchorCertificates(SB_SecTrustRef trust, SB_CFArrayRef anchorCerts);

int32_t SB_SecTrustSetAnchorCertificatesOnly(SB_SecTrustRef trust, bool anchorCertsOnly);

int32_t SB_SecTrustEvaluate(SB_SecTrustRef trust, SB_SecTrustResultType &res);

int32_t SB_SecTrustGetTrustResult(SB_SecTrustRef trust, SB_SecTrustResultType &res);

SB_CFArrayRef SB_SecTrustCopyProperties(SB_SecTrustRef trust);

SB_CFDictionaryRef SB_SecTrustCopyResult(SB_SecTrustRef trust);

SB_CFDataRef SB_SecTrustCopyExceptions(SB_SecTrustRef trust);

bool SB_SecTrustSetExceptions(SB_SecTrustRef trust, SB_CFDataRef exceptions);

SB_SecPolicyRef SB_SecPolicyCreateBasicX509();

int32_t SB_SecPKCS12Import(SB_CFDataRef pkcs12data, SB_CFDictionaryRef options, SB_CFArrayRef &items);

#ifndef SB_IOS
int32_t SB_SecItemImport(SB_CFDataRef importedData, SB_CFStringRef fileNameOrExt, SB_SecExternalFormatRaw * inFormat, SB_SecExternalItemTypeRaw * itemType, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_SecKeychainRef importKeychain, SB_CFArrayRef &outItems);

int32_t SB_SecItemExport(void * secItemOrArray, SB_SecExternalFormat outFormat, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_CFDataRef &exportedData);

int32_t SB_SecKeychainCopySearchList(SB_CFArrayRef &list);

int32_t SB_SecKeychainSetSearchList(SB_CFArrayRef list);

int32_t SB_SecKeychainCopyDefault(SB_SecKeychainRef &keychain);

int32_t SB_SecKeychainSetDefault(SB_SecKeychainRef keychain);

int32_t SB_SecKeychainUnlock(SB_SecKeychainRef keychain, uint32_t passwordLength, void * password, bool usePassword);

int32_t SB_SecKeychainLock(SB_SecKeychainRef keychain);

int32_t SB_SecKeychainLockAll();

int32_t SB_SecKeychainGetStatus(SB_SecKeychainRef keychain, SB_SecKeychainStatusRaw * &status);

int32_t SB_SecKeychainGetPath(SB_SecKeychainRef keychain, uint32_t * &pathLength, char * pathName);

int32_t SB_SecKeychainOpen(char * pathName, SB_SecKeychainRef &keychain);

int32_t SB_SecKeychainCreate(char * pathName, uint32_t passwordLength, void * password, bool promptUser, SB_SecAccessRef initialAccess, SB_SecKeychainRef &keychain);

int32_t SB_SecKeychainDelete(SB_SecKeychainRef keychainOrArray);

int32_t SB_SecKeychainCopyAccess(SB_SecKeychainRef keychain, SB_SecAccessRef &access);

int32_t SB_SecKeychainSetAccess(SB_SecKeychainRef keychain, SB_SecAccessRef access);

int32_t SB_SecKeychainSetUserInteractionAllowed(bool state);

int32_t SB_SecKeychainGetUserInteractionAllowed(bool &state);

int32_t SB_SecAccessCreate(SB_CFStringRef descriptor, SB_CFArrayRef trustedList, SB_SecAccessRef &access);

SB_CFStringRef SB_SecCopyErrorMessageString(int32_t status, void * reserved);

int32_t SB_SecKeychainItemCopyAccess(SB_SecKeychainItemRef item, SB_SecAccessRef &access);

int32_t SB_SecKeychainItemSetAccess(SB_SecKeychainItemRef item, SB_SecAccessRef access);

int32_t SB_SecKeychainItemDelete(SB_SecKeychainItemRef item);

int32_t SB_SecKeychainItemCreateFromContent(SB_SecItemClass itemClass, SB_PSecKeychainAttributeList attrList, uint32_t length, void * data, SB_SecKeychainRef keychainRef, SB_SecAccessRef access, SB_SecKeychainItemRef &item);

int32_t SB_SecKeychainItemCopyContent(SB_SecKeychainItemRef item, SB_SecItemClass &itemClass, SB_PSecKeychainAttributeList attrList, uint32_t &length, void * data);

int32_t SB_SecKeychainItemFreeContent(SB_PSecKeychainAttributeList attrList, void * data);

SB_SecKeyRef SB_SecKeyCreateFromData(SB_CFDictionaryRef keyParams, SB_CFDataRef keyData, SB_CFErrorRef &err);

int32_t SB_SecIdentityCreateWithCertificate(void * keychainOrArr, SB_SecCertificateRef cert, SB_SecIdentityRef &ident);

int32_t SB_SecCertificateAddToKeychain(SB_SecCertificateRef cert, SB_SecKeychainRef keychain);

int32_t SB_SecTrustSetKeychains(SB_SecTrustRef trust, void * keychainOrArray);

int32_t SB_AuthorizationCreate(SB_PAuthorizationItemSet rights, SB_PAuthorizationItemSet environment, uint32_t flags, SB_AuthorizationRef &authorization);

int32_t SB_AuthorizationFree(SB_AuthorizationRef authorization, uint32_t flags);

int32_t SB_SecTrustSettingsCopyTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain, SB_CFArrayRef &trustSettings);

int32_t SB_SecTrustSettingsSetTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain, void * trustSettingsDictOrArray);

int32_t SB_SecTrustSettingsRemoveTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain);

#endif
void SB_CFRelease(void * cf);

SB_CFMutableDictionaryRef SB_CFDictionaryCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks);

void SB_CFDictionaryAddValue(SB_CFMutableDictionaryRef theDict, void * key, void * value);

void SB_CFDictionaryRemoveValue(SB_CFMutableDictionaryRef theDict, void * key);

void SB_CFDictionaryReplaceValue(SB_CFMutableDictionaryRef theDict, void * key, void * value);

SB_CFDictionaryRef SB_CFDictionaryCreate(SB_CFAllocatorRef allocator, void * keys, void * values, int64_t numValues, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks);

bool SB_CFDictionaryGetValueIfPresent(SB_CFDictionaryRef dict, void * key, void * &value);

SB_CFArrayRef SB_CFArrayCreate(SB_CFAllocatorRef allocator, void * values, int64_t numValues, SB_PCFArrayCallBacks callBacks);

SB_CFMutableArrayRef SB_CFArrayCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFArrayCallBacks callBacks);

SB_CFMutableArrayRef SB_CFArrayCreateMutableCopy(SB_CFAllocatorRef allocator, int64_t capacity, SB_CFArrayRef arr);

void SB_CFArrayAppendArray(SB_CFMutableArrayRef arr, SB_CFArrayRef otherArr, SB_CFRange &otherRange);

void SB_CFArrayAppendValue(SB_CFMutableArrayRef arr, void * value);

int64_t SB_CFArrayGetCount(SB_CFArrayRef theArray);

void * SB_CFArrayGetValueAtIndex(SB_CFArrayRef theArray, int64_t idx);

void SB_CFArrayRemoveValueAtIndex(SB_CFMutableArrayRef theArray, int64_t idx);

int64_t SB_CFDataGetLength(SB_CFDataRef data);

uint8_t * SB_CFDataGetBytePtr(SB_CFDataRef data);

void SB_CFDataGetBytes(SB_CFDataRef data, SB_CFRange &range, uint8_t * buf);

SB_CFDataRef SB_CFDataCreate(SB_CFAllocatorRef allocator, uint8_t * bytes, int64_t length);

SB_CFStringRef SB___CFStringMakeConstantString(char * str);

sb_char16_t * SB_CFStringGetCharactersPtr(SB_CFStringRef theString);

void SB_CFStringGetCharacters(SB_CFStringRef theString, SB_CFRange &range, sb_char16_t * buffer);

SB_CFStringRef SB_CFStringCreateWithCharacters(SB_CFAllocatorRef alloc, sb_char16_t * chars, int64_t numChars);

int64_t SB_CFStringGetLength(SB_CFStringRef theString);

SB_CFComparisionResult SB_CFStringCompare(SB_CFStringRef theString1, SB_CFStringRef theString2, uint32_t compareOptions);

SB_CFStringRef SB_CFStringCreateFromExternalRepresentation(SB_CFAllocatorRef alloc, SB_CFDataRef data, SB_CFStringEncoding encoding);

SB_CFStringRef SB_CFErrorCopyDescription(SB_CFErrorRef err);

SB_CFStringRef SB_NSUserName();

SB_CFStringRef SB_NSFullUserName();

SB_CFStringRef SB_NSHomeDirectory();

SB_CFStringRef SB_NSHomeDirectoryForUser(SB_CFStringRef userName);

SB_CFStringRef SB_CFSTR(const sb_u16string &str);
#ifdef SB_U16STRING_USED
SB_CFStringRef SB_CFSTR(const std::wstring &str);
#endif /* SB_U16STRING_USED */

void FreeAndNilCF(void * &cfObj);

void CFStringToString(SB_CFStringRef cfstr, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void CFStringToString(SB_CFStringRef cfstr, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

SB_CFStringRef StringToCFString(const sb_u16string &str);
#ifdef SB_U16STRING_USED
SB_CFStringRef StringToCFString(const std::wstring &str);
#endif /* SB_U16STRING_USED */

void GetOSStatusString(int32_t status, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetOSStatusString(int32_t status, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void GetCFErrorDescriptionString(SB_CFErrorRef err, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetCFErrorDescriptionString(SB_CFErrorRef err, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertToSecString(const sb_u16string &str, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void ConvertToSecString(const std::wstring &str, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void * libSecHandle();

void * libCFHandle();

void * dlopen(char * name, int32_t mode);

void * dlsym(void * lib, char * name);

int32_t dlclose(void * lib);

#endif /* SB_USE_GLOBAL_PROCS_APPLECOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_APPLECOMMON
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFNull(SB_CFNullRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFBooleanTrue(SB_CFBooleanRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFBooleanFalse(SB_CFBooleanRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFAllocatorDefault(SB_CFAllocatorRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFTypeDictionaryKeyCallBacks(SB_CFDictionaryKeyCallBacks * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFTypeDictionaryValueCallBacks(SB_CFDictionaryValueCallBacks * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kCFTypeArrayCallBacks(SB_CFArrayCallBacks * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecClass(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecClassCertificate(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecClassKey(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecClassIdentity(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchLimit(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchSearchList(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchLimitAll(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchLimitOne(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchItemList(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchTrustedOnly(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchValidOnDate(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchSubjectContains(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecMatchIssuers(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecReturnRef(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecReturnData(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecReturnAttributes(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecReturnPersistentRef(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecUseItemList(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecValueData(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecValueRef(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecValuePersistentRef(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyClass(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyClassPublic(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyClassPrivate(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyClassSymmetric(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyType(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeRSA(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeEC(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanEncrypt(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanDecrypt(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanDerive(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanSign(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanVerify(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanWrap(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCanUnwrap(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrIsPermanent(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCertificateType(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrCertificateEncoding(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrLabel(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrSubject(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrIssuer(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrSerialNumber(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrSubjectKeyID(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrPublicKeyHash(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrApplicationLabel(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrApplicationTag(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeySizeInBits(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrEffectiveKeySize(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecPropertyTypeTitle(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecPropertyTypeError(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustEvaluationDate(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustExtendedValidation(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustOrganizationName(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustResultValue(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustRevocationChecked(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecTrustRevocationValidUntilDate(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportExportPassphrase(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportItemLabel(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportItemKeyID(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportItemTrust(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportItemCertChain(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportItemIdentity(SB_CFStringRef * OutResult);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportExportKeychain(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecImportExportAccess(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecUseKeychain(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeDSA(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeAES(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeDES(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyType3DES(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeRC4(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeRC2(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeCAST(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrKeyTypeECDSA(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrIsSensitive(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrIsExtractable(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccess(void * * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessible(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessGroup(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleWhenUnlocked(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleAfterFirstUnlock(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleAlways(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleWhenUnlockedThisDeviceOnly(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_kSecAttrAccessibleAlwaysThisDeviceOnly(void * * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemCopyMatching(SB_CFDictionaryRef query, void * * res, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemAdd(SB_CFDictionaryRef attributes, void * * res, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemUpdate(SB_CFDictionaryRef query, SB_CFDictionaryRef attrToUpdate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemDelete(SB_CFDictionaryRef query, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecCertificateCopyData(SB_SecCertificateRef cert, SB_CFDataRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecCertificateCreateWithData(SB_CFAllocatorRef allocator, SB_CFDataRef data, SB_SecCertificateRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecCertificateCopySubjectSummary(SB_SecCertificateRef cert, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecIdentityCopyCertificate(SB_SecIdentityRef identity, SB_SecCertificateRef * cert, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecIdentityCopyPrivateKey(SB_SecIdentityRef identity, SB_SecKeyRef * privateKey, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustCreateWithCertificates(void * certs, void * policies, SB_SecTrustRef * trust, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSetAnchorCertificates(SB_SecTrustRef trust, SB_CFArrayRef anchorCerts, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSetAnchorCertificatesOnly(SB_SecTrustRef trust, int8_t anchorCertsOnly, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustEvaluate(SB_SecTrustRef trust, SB_SecTrustResultTypeRaw * res, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustGetTrustResult(SB_SecTrustRef trust, SB_SecTrustResultTypeRaw * res, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustCopyProperties(SB_SecTrustRef trust, SB_CFArrayRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustCopyResult(SB_SecTrustRef trust, SB_CFDictionaryRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustCopyExceptions(SB_SecTrustRef trust, SB_CFDataRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSetExceptions(SB_SecTrustRef trust, SB_CFDataRef exceptions, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecPolicyCreateBasicX509(SB_SecPolicyRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecPKCS12Import(SB_CFDataRef pkcs12data, SB_CFDictionaryRef options, SB_CFArrayRef * items, int32_t * OutResult);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemImport(SB_CFDataRef importedData, SB_CFStringRef fileNameOrExt, SB_SecExternalFormatRaw * inFormat, SB_SecExternalItemTypeRaw * itemType, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_SecKeychainRef importKeychain, SB_CFArrayRef * outItems, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecItemExport(void * secItemOrArray, SB_SecExternalFormatRaw outFormat, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_CFDataRef * exportedData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainCopySearchList(SB_CFArrayRef * list, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainSetSearchList(SB_CFArrayRef list, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainCopyDefault(SB_SecKeychainRef * keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainSetDefault(SB_SecKeychainRef keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainUnlock(SB_SecKeychainRef keychain, uint32_t passwordLength, void * password, int8_t usePassword, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainLock(SB_SecKeychainRef keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainLockAll(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainGetStatus(SB_SecKeychainRef keychain, SB_SecKeychainStatusRaw * * status, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainGetPath(SB_SecKeychainRef keychain, uint32_t * * pathLength, char * pathName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainOpen(char * pathName, SB_SecKeychainRef * keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainCreate(char * pathName, uint32_t passwordLength, void * password, int8_t promptUser, SB_SecAccessRef initialAccess, SB_SecKeychainRef * keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainDelete(SB_SecKeychainRef keychainOrArray, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainCopyAccess(SB_SecKeychainRef keychain, SB_SecAccessRef * access, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainSetAccess(SB_SecKeychainRef keychain, SB_SecAccessRef access, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainSetUserInteractionAllowed(int8_t state, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainGetUserInteractionAllowed(int8_t * state, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecAccessCreate(SB_CFStringRef descriptor, SB_CFArrayRef trustedList, SB_SecAccessRef * access, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecCopyErrorMessageString(int32_t status, void * reserved, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemCopyAccess(SB_SecKeychainItemRef item, SB_SecAccessRef * access, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemSetAccess(SB_SecKeychainItemRef item, SB_SecAccessRef access, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemDelete(SB_SecKeychainItemRef item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemCreateFromContent(SB_SecItemClassRaw itemClass, SB_PSecKeychainAttributeList attrList, uint32_t length, void * data, SB_SecKeychainRef keychainRef, SB_SecAccessRef access, SB_SecKeychainItemRef * item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemCopyContent(SB_SecKeychainItemRef item, SB_SecItemClassRaw * itemClass, SB_PSecKeychainAttributeList attrList, uint32_t * length, void * data, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeychainItemFreeContent(SB_PSecKeychainAttributeList attrList, void * data, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecKeyCreateFromData(SB_CFDictionaryRef keyParams, SB_CFDataRef keyData, SB_CFErrorRef * err, SB_SecKeyRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecIdentityCreateWithCertificate(void * keychainOrArr, SB_SecCertificateRef cert, SB_SecIdentityRef * ident, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecCertificateAddToKeychain(SB_SecCertificateRef cert, SB_SecKeychainRef keychain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSetKeychains(SB_SecTrustRef trust, void * keychainOrArray, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_AuthorizationCreate(SB_PAuthorizationItemSet rights, SB_PAuthorizationItemSet environment, uint32_t flags, SB_AuthorizationRef * authorization, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_AuthorizationFree(SB_AuthorizationRef authorization, uint32_t flags, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSettingsCopyTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomainRaw domain, SB_CFArrayRef * trustSettings, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSettingsSetTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomainRaw domain, void * trustSettingsDictOrArray, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_SecTrustSettingsRemoveTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomainRaw domain, int32_t * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFRelease(void * cf);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks, SB_CFMutableDictionaryRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryAddValue(SB_CFMutableDictionaryRef theDict, void * key, void * value);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryRemoveValue(SB_CFMutableDictionaryRef theDict, void * key);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryReplaceValue(SB_CFMutableDictionaryRef theDict, void * key, void * value);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryCreate(SB_CFAllocatorRef allocator, void * keys, void * values, int64_t numValues, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks, SB_CFDictionaryRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDictionaryGetValueIfPresent(SB_CFDictionaryRef dict, void * key, void * * value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayCreate(SB_CFAllocatorRef allocator, void * values, int64_t numValues, SB_PCFArrayCallBacks callBacks, SB_CFArrayRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFArrayCallBacks callBacks, SB_CFMutableArrayRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayCreateMutableCopy(SB_CFAllocatorRef allocator, int64_t capacity, SB_CFArrayRef arr, SB_CFMutableArrayRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayAppendArray(SB_CFMutableArrayRef arr, SB_CFArrayRef otherArr, SB_CFRange * otherRange);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayAppendValue(SB_CFMutableArrayRef arr, void * value);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayGetCount(SB_CFArrayRef theArray, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayGetValueAtIndex(SB_CFArrayRef theArray, int64_t idx, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFArrayRemoveValueAtIndex(SB_CFMutableArrayRef theArray, int64_t idx);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDataGetLength(SB_CFDataRef data, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDataGetBytePtr(SB_CFDataRef data, uint8_t * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDataGetBytes(SB_CFDataRef data, SB_CFRange * range, uint8_t * buf);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFDataCreate(SB_CFAllocatorRef allocator, uint8_t * bytes, int64_t length, SB_CFDataRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB___CFStringMakeConstantString(char * str, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringGetCharactersPtr(SB_CFStringRef theString, sb_char16_t * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringGetCharacters(SB_CFStringRef theString, SB_CFRange * range, sb_char16_t * buffer);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringCreateWithCharacters(SB_CFAllocatorRef alloc, sb_char16_t * chars, int64_t numChars, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringGetLength(SB_CFStringRef theString, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringCompare(SB_CFStringRef theString1, SB_CFStringRef theString2, uint32_t compareOptions, SB_CFComparisionResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFStringCreateFromExternalRepresentation(SB_CFAllocatorRef alloc, SB_CFDataRef data, SB_CFStringEncodingRaw encoding, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFErrorCopyDescription(SB_CFErrorRef err, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_NSUserName(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_NSFullUserName(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_NSHomeDirectory(SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_NSHomeDirectoryForUser(SB_CFStringRef userName, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_SB_CFSTR(const sb_char16_t * pcstr, int32_t szstr, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_FreeAndNilCF(void * * cfObj);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_CFStringToString(SB_CFStringRef cfstr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_StringToCFString(const sb_char16_t * pcstr, int32_t szstr, SB_CFStringRef * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_GetOSStatusString(int32_t status, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_GetCFErrorDescriptionString(SB_CFErrorRef err, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_ConvertToSecString(const sb_char16_t * pcstr, int32_t szstr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_libSecHandle(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_libCFHandle(void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_dlopen(char * name, int32_t mode, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_dlsym(void * lib, char * name, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBAppleCommon_dlclose(void * lib, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_APPLECOMMON */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAPPLECOMMON */
