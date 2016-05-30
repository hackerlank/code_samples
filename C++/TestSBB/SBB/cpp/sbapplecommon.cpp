#include "sbdefs.h"

#ifdef MACOS
#include "sbapplecommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_APPLECOMMON

SB_INLINE SB_CFNullRef SB_kCFNull()
{
	SB_CFNullRef OutResult;
	SBCheckError(SBAppleCommon_SB_kCFNull(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFBooleanRef SB_kCFBooleanTrue()
{
	SB_CFBooleanRef OutResult;
	SBCheckError(SBAppleCommon_SB_kCFBooleanTrue(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFBooleanRef SB_kCFBooleanFalse()
{
	SB_CFBooleanRef OutResult;
	SBCheckError(SBAppleCommon_SB_kCFBooleanFalse(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFAllocatorRef SB_kCFAllocatorDefault()
{
	SB_CFAllocatorRef OutResult;
	SBCheckError(SBAppleCommon_SB_kCFAllocatorDefault(&OutResult));
	return OutResult;
}

SB_INLINE void SB_kCFTypeDictionaryKeyCallBacks(SB_CFDictionaryKeyCallBacks &OutResult)
{
	SBCheckError(SBAppleCommon_SB_kCFTypeDictionaryKeyCallBacks(&OutResult));
}

SB_INLINE void SB_kCFTypeDictionaryValueCallBacks(SB_CFDictionaryValueCallBacks &OutResult)
{
	SBCheckError(SBAppleCommon_SB_kCFTypeDictionaryValueCallBacks(&OutResult));
}

SB_INLINE void SB_kCFTypeArrayCallBacks(SB_CFArrayCallBacks &OutResult)
{
	SBCheckError(SBAppleCommon_SB_kCFTypeArrayCallBacks(&OutResult));
}

SB_INLINE void * SB_kSecClass()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecClass(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecClassCertificate()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecClassCertificate(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecClassKey()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecClassKey(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecClassIdentity()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecClassIdentity(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchLimit()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchLimit(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchSearchList()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchSearchList(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchLimitAll()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchLimitAll(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchLimitOne()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchLimitOne(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchItemList()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchItemList(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchTrustedOnly()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchTrustedOnly(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchValidOnDate()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchValidOnDate(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchSubjectContains()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchSubjectContains(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecMatchIssuers()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecMatchIssuers(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecReturnRef()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecReturnRef(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecReturnData()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecReturnData(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecReturnAttributes()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecReturnAttributes(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecReturnPersistentRef()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecReturnPersistentRef(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecUseItemList()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecUseItemList(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecValueData()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecValueData(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecValueRef()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecValueRef(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecValuePersistentRef()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecValuePersistentRef(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyClass()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyClass(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyClassPublic()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyClassPublic(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyClassPrivate()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyClassPrivate(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyClassSymmetric()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyClassSymmetric(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyType()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyType(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyTypeRSA()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeRSA(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeyTypeEC()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeEC(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanEncrypt()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanEncrypt(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanDecrypt()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanDecrypt(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanDerive()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanDerive(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanSign()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanSign(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanVerify()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanVerify(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanWrap()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanWrap(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCanUnwrap()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCanUnwrap(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrIsPermanent()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrIsPermanent(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCertificateType()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCertificateType(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrCertificateEncoding()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrCertificateEncoding(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrLabel()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrLabel(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrSubject()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrSubject(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrIssuer()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrIssuer(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrSerialNumber()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrSerialNumber(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrSubjectKeyID()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrSubjectKeyID(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrPublicKeyHash()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrPublicKeyHash(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrApplicationLabel()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrApplicationLabel(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrApplicationTag()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrApplicationTag(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrKeySizeInBits()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeySizeInBits(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrEffectiveKeySize()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrEffectiveKeySize(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecPropertyTypeTitle()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecPropertyTypeTitle(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecPropertyTypeError()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecPropertyTypeError(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustEvaluationDate()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustEvaluationDate(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustExtendedValidation()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustExtendedValidation(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustOrganizationName()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustOrganizationName(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustResultValue()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustResultValue(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustRevocationChecked()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustRevocationChecked(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecTrustRevocationValidUntilDate()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecTrustRevocationValidUntilDate(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportExportPassphrase()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportExportPassphrase(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportItemLabel()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportItemLabel(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportItemKeyID()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportItemKeyID(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportItemTrust()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportItemTrust(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportItemCertChain()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportItemCertChain(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportItemIdentity()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportItemIdentity(&OutResult));
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE SB_CFStringRef SB_kSecImportExportKeychain()
#else
SB_INLINE void * SB_kSecAttrAccessible()
#endif
{
#ifndef SB_IOS
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportExportKeychain(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_kSecImportExportAccess()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_kSecImportExportAccess(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecUseKeychain()
{
#endif
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecUseKeychain(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessible(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeDSA()
#else
SB_INLINE void * SB_kSecAttrAccessGroup()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeDSA(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessGroup(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeAES()
#else
SB_INLINE void * SB_kSecAttrAccessibleWhenUnlocked()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeAES(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleWhenUnlocked(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeDES()
#else
SB_INLINE void * SB_kSecAttrAccessibleAfterFirstUnlock()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeDES(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleAfterFirstUnlock(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyType3DES()
#else
SB_INLINE void * SB_kSecAttrAccessibleAlways()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyType3DES(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleAlways(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeRC4()
#else
SB_INLINE void * SB_kSecAttrAccessibleWhenUnlockedThisDeviceOnly()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeRC4(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleWhenUnlockedThisDeviceOnly(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeRC2()
#else
SB_INLINE void * SB_kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeRC2(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeCAST()
#else
SB_INLINE void * SB_kSecAttrAccessibleAlwaysThisDeviceOnly()
#endif
{
	void * OutResult;
#ifndef SB_IOS
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeCAST(&OutResult));
#else
	SBCheckError(SBAppleCommon_SB_kSecAttrAccessibleAlwaysThisDeviceOnly(&OutResult));
#endif
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE void * SB_kSecAttrKeyTypeECDSA()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrKeyTypeECDSA(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrIsSensitive()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrIsSensitive(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrIsExtractable()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrIsExtractable(&OutResult));
	return OutResult;
}

SB_INLINE void * SB_kSecAttrAccess()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_kSecAttrAccess(&OutResult));
	return OutResult;
}

#endif
SB_INLINE int32_t SB_SecItemCopyMatching(SB_CFDictionaryRef query, void * &res)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemCopyMatching(query, &res, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecItemAdd(SB_CFDictionaryRef attributes, void * &res)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemAdd(attributes, &res, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecItemUpdate(SB_CFDictionaryRef query, SB_CFDictionaryRef attrToUpdate)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemUpdate(query, attrToUpdate, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecItemDelete(SB_CFDictionaryRef query)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemDelete(query, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFDataRef SB_SecCertificateCopyData(SB_SecCertificateRef cert)
{
	SB_CFDataRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecCertificateCopyData(cert, &OutResult));
	return OutResult;
}

SB_INLINE SB_SecCertificateRef SB_SecCertificateCreateWithData(SB_CFAllocatorRef allocator, SB_CFDataRef data)
{
	SB_SecCertificateRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecCertificateCreateWithData(allocator, data, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_SecCertificateCopySubjectSummary(SB_SecCertificateRef cert)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecCertificateCopySubjectSummary(cert, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecIdentityCopyCertificate(SB_SecIdentityRef identity, SB_SecCertificateRef &cert)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecIdentityCopyCertificate(identity, &cert, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecIdentityCopyPrivateKey(SB_SecIdentityRef identity, SB_SecKeyRef &privateKey)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecIdentityCopyPrivateKey(identity, &privateKey, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustCreateWithCertificates(void * certs, void * policies, SB_SecTrustRef &trust)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustCreateWithCertificates(certs, policies, &trust, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSetAnchorCertificates(SB_SecTrustRef trust, SB_CFArrayRef anchorCerts)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSetAnchorCertificates(trust, anchorCerts, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSetAnchorCertificatesOnly(SB_SecTrustRef trust, bool anchorCertsOnly)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSetAnchorCertificatesOnly(trust, (int8_t)anchorCertsOnly, &OutResult));
	return OutResult;
}

int32_t SB_SecTrustEvaluate(SB_SecTrustRef trust, SB_SecTrustResultType &res)
{
	int32_t OutResult;
	SB_SecTrustResultTypeRaw resRaw = (SB_SecTrustResultTypeRaw)res;
	SBCheckError(SBAppleCommon_SB_SecTrustEvaluate(trust, &resRaw, &OutResult));
	res = (SB_SecTrustResultType)resRaw;
	return OutResult;
}

int32_t SB_SecTrustGetTrustResult(SB_SecTrustRef trust, SB_SecTrustResultType &res)
{
	int32_t OutResult;
	SB_SecTrustResultTypeRaw resRaw = (SB_SecTrustResultTypeRaw)res;
	SBCheckError(SBAppleCommon_SB_SecTrustGetTrustResult(trust, &resRaw, &OutResult));
	res = (SB_SecTrustResultType)resRaw;
	return OutResult;
}

SB_INLINE SB_CFArrayRef SB_SecTrustCopyProperties(SB_SecTrustRef trust)
{
	SB_CFArrayRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustCopyProperties(trust, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFDictionaryRef SB_SecTrustCopyResult(SB_SecTrustRef trust)
{
	SB_CFDictionaryRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustCopyResult(trust, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFDataRef SB_SecTrustCopyExceptions(SB_SecTrustRef trust)
{
	SB_CFDataRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustCopyExceptions(trust, &OutResult));
	return OutResult;
}

bool SB_SecTrustSetExceptions(SB_SecTrustRef trust, SB_CFDataRef exceptions)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAppleCommon_SB_SecTrustSetExceptions(trust, exceptions, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE SB_SecPolicyRef SB_SecPolicyCreateBasicX509()
{
	SB_SecPolicyRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecPolicyCreateBasicX509(&OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecPKCS12Import(SB_CFDataRef pkcs12data, SB_CFDictionaryRef options, SB_CFArrayRef &items)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecPKCS12Import(pkcs12data, options, &items, &OutResult));
	return OutResult;
}

#ifndef SB_IOS
SB_INLINE int32_t SB_SecItemImport(SB_CFDataRef importedData, SB_CFStringRef fileNameOrExt, SB_SecExternalFormatRaw * inFormat, SB_SecExternalItemTypeRaw * itemType, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_SecKeychainRef importKeychain, SB_CFArrayRef &outItems)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemImport(importedData, fileNameOrExt, inFormat, itemType, flags, keyParams, importKeychain, &outItems, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecItemExport(void * secItemOrArray, SB_SecExternalFormat outFormat, uint32_t flags, SB_PSecItemImportExportKeyParameters keyParams, SB_CFDataRef &exportedData)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecItemExport(secItemOrArray, (SB_SecExternalFormatRaw)outFormat, flags, keyParams, &exportedData, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainCopySearchList(SB_CFArrayRef &list)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainCopySearchList(&list, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainSetSearchList(SB_CFArrayRef list)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainSetSearchList(list, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainCopyDefault(SB_SecKeychainRef &keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainCopyDefault(&keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainSetDefault(SB_SecKeychainRef keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainSetDefault(keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainUnlock(SB_SecKeychainRef keychain, uint32_t passwordLength, void * password, bool usePassword)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainUnlock(keychain, passwordLength, password, (int8_t)usePassword, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainLock(SB_SecKeychainRef keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainLock(keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainLockAll()
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainLockAll(&OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainGetStatus(SB_SecKeychainRef keychain, SB_SecKeychainStatusRaw * &status)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainGetStatus(keychain, &status, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainGetPath(SB_SecKeychainRef keychain, uint32_t * &pathLength, char * pathName)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainGetPath(keychain, &pathLength, pathName, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainOpen(char * pathName, SB_SecKeychainRef &keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainOpen(pathName, &keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainCreate(char * pathName, uint32_t passwordLength, void * password, bool promptUser, SB_SecAccessRef initialAccess, SB_SecKeychainRef &keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainCreate(pathName, passwordLength, password, (int8_t)promptUser, initialAccess, &keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainDelete(SB_SecKeychainRef keychainOrArray)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainDelete(keychainOrArray, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainCopyAccess(SB_SecKeychainRef keychain, SB_SecAccessRef &access)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainCopyAccess(keychain, &access, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainSetAccess(SB_SecKeychainRef keychain, SB_SecAccessRef access)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainSetAccess(keychain, access, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainSetUserInteractionAllowed(bool state)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainSetUserInteractionAllowed((int8_t)state, &OutResult));
	return OutResult;
}

int32_t SB_SecKeychainGetUserInteractionAllowed(bool &state)
{
	int32_t OutResult;
	int8_t stateRaw = (int8_t)state;
	SBCheckError(SBAppleCommon_SB_SecKeychainGetUserInteractionAllowed(&stateRaw, &OutResult));
	state = (stateRaw != 0);
	return OutResult;
}

SB_INLINE int32_t SB_SecAccessCreate(SB_CFStringRef descriptor, SB_CFArrayRef trustedList, SB_SecAccessRef &access)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecAccessCreate(descriptor, trustedList, &access, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_SecCopyErrorMessageString(int32_t status, void * reserved)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecCopyErrorMessageString(status, reserved, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainItemCopyAccess(SB_SecKeychainItemRef item, SB_SecAccessRef &access)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemCopyAccess(item, &access, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainItemSetAccess(SB_SecKeychainItemRef item, SB_SecAccessRef access)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemSetAccess(item, access, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainItemDelete(SB_SecKeychainItemRef item)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemDelete(item, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainItemCreateFromContent(SB_SecItemClass itemClass, SB_PSecKeychainAttributeList attrList, uint32_t length, void * data, SB_SecKeychainRef keychainRef, SB_SecAccessRef access, SB_SecKeychainItemRef &item)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemCreateFromContent((SB_SecItemClassRaw)itemClass, attrList, length, data, keychainRef, access, &item, &OutResult));
	return OutResult;
}

int32_t SB_SecKeychainItemCopyContent(SB_SecKeychainItemRef item, SB_SecItemClass &itemClass, SB_PSecKeychainAttributeList attrList, uint32_t &length, void * data)
{
	int32_t OutResult;
	SB_SecItemClassRaw itemClassRaw = (SB_SecItemClassRaw)itemClass;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemCopyContent(item, &itemClassRaw, attrList, &length, data, &OutResult));
	itemClass = (SB_SecItemClass)itemClassRaw;
	return OutResult;
}

SB_INLINE int32_t SB_SecKeychainItemFreeContent(SB_PSecKeychainAttributeList attrList, void * data)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeychainItemFreeContent(attrList, data, &OutResult));
	return OutResult;
}

SB_INLINE SB_SecKeyRef SB_SecKeyCreateFromData(SB_CFDictionaryRef keyParams, SB_CFDataRef keyData, SB_CFErrorRef &err)
{
	SB_SecKeyRef OutResult;
	SBCheckError(SBAppleCommon_SB_SecKeyCreateFromData(keyParams, keyData, &err, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecIdentityCreateWithCertificate(void * keychainOrArr, SB_SecCertificateRef cert, SB_SecIdentityRef &ident)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecIdentityCreateWithCertificate(keychainOrArr, cert, &ident, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecCertificateAddToKeychain(SB_SecCertificateRef cert, SB_SecKeychainRef keychain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecCertificateAddToKeychain(cert, keychain, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSetKeychains(SB_SecTrustRef trust, void * keychainOrArray)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSetKeychains(trust, keychainOrArray, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_AuthorizationCreate(SB_PAuthorizationItemSet rights, SB_PAuthorizationItemSet environment, uint32_t flags, SB_AuthorizationRef &authorization)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_AuthorizationCreate(rights, environment, flags, &authorization, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_AuthorizationFree(SB_AuthorizationRef authorization, uint32_t flags)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_AuthorizationFree(authorization, flags, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSettingsCopyTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain, SB_CFArrayRef &trustSettings)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSettingsCopyTrustSettings(certRef, (SB_SecTrustSettingsDomainRaw)domain, &trustSettings, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSettingsSetTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain, void * trustSettingsDictOrArray)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSettingsSetTrustSettings(certRef, (SB_SecTrustSettingsDomainRaw)domain, trustSettingsDictOrArray, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SB_SecTrustSettingsRemoveTrustSettings(SB_SecCertificateRef certRef, SB_SecTrustSettingsDomain domain)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_SB_SecTrustSettingsRemoveTrustSettings(certRef, (SB_SecTrustSettingsDomainRaw)domain, &OutResult));
	return OutResult;
}

#endif
SB_INLINE void SB_CFRelease(void * cf)
{
	SBCheckError(SBAppleCommon_SB_CFRelease(cf));
}

SB_INLINE SB_CFMutableDictionaryRef SB_CFDictionaryCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks)
{
	SB_CFMutableDictionaryRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFDictionaryCreateMutable(allocator, capacity, keyCallBacks, valueCallBacks, &OutResult));
	return OutResult;
}

SB_INLINE void SB_CFDictionaryAddValue(SB_CFMutableDictionaryRef theDict, void * key, void * value)
{
	SBCheckError(SBAppleCommon_SB_CFDictionaryAddValue(theDict, key, value));
}

SB_INLINE void SB_CFDictionaryRemoveValue(SB_CFMutableDictionaryRef theDict, void * key)
{
	SBCheckError(SBAppleCommon_SB_CFDictionaryRemoveValue(theDict, key));
}

SB_INLINE void SB_CFDictionaryReplaceValue(SB_CFMutableDictionaryRef theDict, void * key, void * value)
{
	SBCheckError(SBAppleCommon_SB_CFDictionaryReplaceValue(theDict, key, value));
}

SB_INLINE SB_CFDictionaryRef SB_CFDictionaryCreate(SB_CFAllocatorRef allocator, void * keys, void * values, int64_t numValues, SB_PCFDictionaryKeyCallBacks keyCallBacks, SB_PCFDictionaryValueCallBacks valueCallBacks)
{
	SB_CFDictionaryRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFDictionaryCreate(allocator, keys, values, numValues, keyCallBacks, valueCallBacks, &OutResult));
	return OutResult;
}

bool SB_CFDictionaryGetValueIfPresent(SB_CFDictionaryRef dict, void * key, void * &value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBAppleCommon_SB_CFDictionaryGetValueIfPresent(dict, key, &value, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE SB_CFArrayRef SB_CFArrayCreate(SB_CFAllocatorRef allocator, void * values, int64_t numValues, SB_PCFArrayCallBacks callBacks)
{
	SB_CFArrayRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFArrayCreate(allocator, values, numValues, callBacks, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFMutableArrayRef SB_CFArrayCreateMutable(SB_CFAllocatorRef allocator, int64_t capacity, SB_PCFArrayCallBacks callBacks)
{
	SB_CFMutableArrayRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFArrayCreateMutable(allocator, capacity, callBacks, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFMutableArrayRef SB_CFArrayCreateMutableCopy(SB_CFAllocatorRef allocator, int64_t capacity, SB_CFArrayRef arr)
{
	SB_CFMutableArrayRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFArrayCreateMutableCopy(allocator, capacity, arr, &OutResult));
	return OutResult;
}

SB_INLINE void SB_CFArrayAppendArray(SB_CFMutableArrayRef arr, SB_CFArrayRef otherArr, SB_CFRange &otherRange)
{
	SBCheckError(SBAppleCommon_SB_CFArrayAppendArray(arr, otherArr, &otherRange));
}

SB_INLINE void SB_CFArrayAppendValue(SB_CFMutableArrayRef arr, void * value)
{
	SBCheckError(SBAppleCommon_SB_CFArrayAppendValue(arr, value));
}

SB_INLINE int64_t SB_CFArrayGetCount(SB_CFArrayRef theArray)
{
	int64_t OutResult;
	SBCheckError(SBAppleCommon_SB_CFArrayGetCount(theArray, &OutResult));
	return OutResult;
}

SB_INLINE void * SB_CFArrayGetValueAtIndex(SB_CFArrayRef theArray, int64_t idx)
{
	void * OutResult;
	SBCheckError(SBAppleCommon_SB_CFArrayGetValueAtIndex(theArray, idx, &OutResult));
	return OutResult;
}

SB_INLINE void SB_CFArrayRemoveValueAtIndex(SB_CFMutableArrayRef theArray, int64_t idx)
{
	SBCheckError(SBAppleCommon_SB_CFArrayRemoveValueAtIndex(theArray, idx));
}

SB_INLINE int64_t SB_CFDataGetLength(SB_CFDataRef data)
{
	int64_t OutResult;
	SBCheckError(SBAppleCommon_SB_CFDataGetLength(data, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t * SB_CFDataGetBytePtr(SB_CFDataRef data)
{
	uint8_t * OutResult;
	SBCheckError(SBAppleCommon_SB_CFDataGetBytePtr(data, &OutResult));
	return OutResult;
}

SB_INLINE void SB_CFDataGetBytes(SB_CFDataRef data, SB_CFRange &range, uint8_t * buf)
{
	SBCheckError(SBAppleCommon_SB_CFDataGetBytes(data, &range, buf));
}

SB_INLINE SB_CFDataRef SB_CFDataCreate(SB_CFAllocatorRef allocator, uint8_t * bytes, int64_t length)
{
	SB_CFDataRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFDataCreate(allocator, bytes, length, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB___CFStringMakeConstantString(char * str)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB___CFStringMakeConstantString(str, &OutResult));
	return OutResult;
}

SB_INLINE sb_char16_t * SB_CFStringGetCharactersPtr(SB_CFStringRef theString)
{
	sb_char16_t * OutResult;
	SBCheckError(SBAppleCommon_SB_CFStringGetCharactersPtr(theString, &OutResult));
	return OutResult;
}

SB_INLINE void SB_CFStringGetCharacters(SB_CFStringRef theString, SB_CFRange &range, sb_char16_t * buffer)
{
	SBCheckError(SBAppleCommon_SB_CFStringGetCharacters(theString, &range, buffer));
}

SB_INLINE SB_CFStringRef SB_CFStringCreateWithCharacters(SB_CFAllocatorRef alloc, sb_char16_t * chars, int64_t numChars)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFStringCreateWithCharacters(alloc, chars, numChars, &OutResult));
	return OutResult;
}

SB_INLINE int64_t SB_CFStringGetLength(SB_CFStringRef theString)
{
	int64_t OutResult;
	SBCheckError(SBAppleCommon_SB_CFStringGetLength(theString, &OutResult));
	return OutResult;
}

SB_CFComparisionResult SB_CFStringCompare(SB_CFStringRef theString1, SB_CFStringRef theString2, uint32_t compareOptions)
{
	SB_CFComparisionResultRaw OutResultRaw = 0;
	SBCheckError(SBAppleCommon_SB_CFStringCompare(theString1, theString2, compareOptions, &OutResultRaw));
	return (SB_CFComparisionResult)OutResultRaw;
}

SB_INLINE SB_CFStringRef SB_CFStringCreateFromExternalRepresentation(SB_CFAllocatorRef alloc, SB_CFDataRef data, SB_CFStringEncoding encoding)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFStringCreateFromExternalRepresentation(alloc, data, (SB_CFStringEncodingRaw)encoding, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_CFErrorCopyDescription(SB_CFErrorRef err)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFErrorCopyDescription(err, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_NSUserName()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_NSUserName(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_NSFullUserName()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_NSFullUserName(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_NSHomeDirectory()
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_NSHomeDirectory(&OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_NSHomeDirectoryForUser(SB_CFStringRef userName)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_NSHomeDirectoryForUser(userName, &OutResult));
	return OutResult;
}

SB_INLINE SB_CFStringRef SB_CFSTR(const sb_u16string &str)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_SB_CFSTR(str.data(), (int32_t)str.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE SB_CFStringRef SB_CFSTR(const std::wstring &str)
{
	SB_CFStringRef OutResult;
	std::string u16str;
	sb_to_u16string(str, u16str);
	SBCheckError(SBAppleCommon_SB_CFSTR(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

SB_INLINE void FreeAndNilCF(void * &cfObj)
{
	SBCheckError(SBAppleCommon_FreeAndNilCF(&cfObj));
}

void CFStringToString(SB_CFStringRef cfstr, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAppleCommon_CFStringToString(cfstr, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1811422612, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void CFStringToString(SB_CFStringRef cfstr, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBAppleCommon_CFStringToString(cfstr, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1811422612, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE SB_CFStringRef StringToCFString(const sb_u16string &str)
{
	SB_CFStringRef OutResult;
	SBCheckError(SBAppleCommon_StringToCFString(str.data(), (int32_t)str.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE SB_CFStringRef StringToCFString(const std::wstring &str)
{
	SB_CFStringRef OutResult;
	std::string u16str;
	sb_to_u16string(str, u16str);
	SBCheckError(SBAppleCommon_StringToCFString(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */

void GetOSStatusString(int32_t status, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAppleCommon_GetOSStatusString(status, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-225658800, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetOSStatusString(int32_t status, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBAppleCommon_GetOSStatusString(status, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-225658800, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void GetCFErrorDescriptionString(SB_CFErrorRef err, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBAppleCommon_GetCFErrorDescriptionString(err, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1171414034, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void GetCFErrorDescriptionString(SB_CFErrorRef err, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBAppleCommon_GetCFErrorDescriptionString(err, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1171414034, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ConvertToSecString(const sb_u16string &str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBAppleCommon_ConvertToSecString(str.data(), (int32_t)str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1639843887, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ConvertToSecString(const std::wstring &str, std::vector<uint8_t> &OutResult)
{
	std::string u16str;
	sb_to_u16string(str, u16str);
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBAppleCommon_ConvertToSecString(reinterpret_cast<const sb_char16_t*>(u16str.data()), (int32_t)u16str.length() >> 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1639843887, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_U16STRING_USED */

SB_INLINE void * libSecHandle()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_libSecHandle(&OutResult));
	return OutResult;
}

SB_INLINE void * libCFHandle()
{
	void * OutResult;
	SBCheckError(SBAppleCommon_libCFHandle(&OutResult));
	return OutResult;
}

SB_INLINE void * dlopen(char * name, int32_t mode)
{
	void * OutResult;
	SBCheckError(SBAppleCommon_dlopen(name, mode, &OutResult));
	return OutResult;
}

SB_INLINE void * dlsym(void * lib, char * name)
{
	void * OutResult;
	SBCheckError(SBAppleCommon_dlsym(lib, name, &OutResult));
	return OutResult;
}

SB_INLINE int32_t dlclose(void * lib)
{
	int32_t OutResult;
	SBCheckError(SBAppleCommon_dlclose(lib, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_APPLECOMMON */

};	/* namespace SecureBlackbox */
#endif
