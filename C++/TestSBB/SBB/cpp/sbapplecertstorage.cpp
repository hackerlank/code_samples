#include "sbdefs.h"

#ifdef MACOS
#include "sbapplecertstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElAppleCertStorage::GetOpenedKeychains(TStrings &Keychains)
{
	SBCheckError(TElAppleCertStorage_GetOpenedKeychains(Keychains.getHandle()));
}

SB_INLINE void TElAppleCertStorage::GetOpenedKeychains(TStrings *Keychains)
{
	SBCheckError(TElAppleCertStorage_GetOpenedKeychains((Keychains != NULL) ? Keychains->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
SB_INLINE void TElAppleCertStorage::GetOpenedKeychains_Inst(TStrings &Keychains)
{
	SBCheckError(TElAppleCertStorage_GetOpenedKeychains_1(_Handle, Keychains.getHandle()));
}

SB_INLINE void TElAppleCertStorage::GetOpenedKeychains_Inst(TStrings *Keychains)
{
	SBCheckError(TElAppleCertStorage_GetOpenedKeychains_1(_Handle, (Keychains != NULL) ? Keychains->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGS */

SB_INLINE void TElAppleCertStorage::AddToSearchList(const sb_u16string &KeychainPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList(KeychainPath.data(), (int32_t)KeychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::AddToSearchList(const std::wstring &KeychainPath)
{
	std::string u16KeychainPath;
	sb_to_u16string(KeychainPath, u16KeychainPath);
	SBCheckError(TElAppleCertStorage_AddToSearchList(reinterpret_cast<const sb_char16_t*>(u16KeychainPath.data()), (int32_t)u16KeychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::AddToSearchList_Inst(const sb_u16string &KeychainPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList_1(_Handle, KeychainPath.data(), (int32_t)KeychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::AddToSearchList_Inst(const std::wstring &KeychainPath)
{
	std::string u16KeychainPath;
	sb_to_u16string(KeychainPath, u16KeychainPath);
	SBCheckError(TElAppleCertStorage_AddToSearchList_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16KeychainPath.data()), (int32_t)u16KeychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAppleCertStorage::AddToSearchList(TStringList &KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList_2(KeychainsPath.getHandle()));
}

SB_INLINE void TElAppleCertStorage::AddToSearchList(TStringList *KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList_2((KeychainsPath != NULL) ? KeychainsPath->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAppleCertStorage::AddToSearchList_Inst(TStringList &KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList_3(_Handle, KeychainsPath.getHandle()));
}

SB_INLINE void TElAppleCertStorage::AddToSearchList_Inst(TStringList *KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_AddToSearchList_3(_Handle, (KeychainsPath != NULL) ? KeychainsPath->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE void TElAppleCertStorage::RemoveFromSearchList(const sb_u16string &KeychainPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList(KeychainPath.data(), (int32_t)KeychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::RemoveFromSearchList(const std::wstring &KeychainPath)
{
	std::string u16KeychainPath;
	sb_to_u16string(KeychainPath, u16KeychainPath);
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList(reinterpret_cast<const sb_char16_t*>(u16KeychainPath.data()), (int32_t)u16KeychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::RemoveFromSearchList_Inst(const sb_u16string &KeychainPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_1(_Handle, KeychainPath.data(), (int32_t)KeychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::RemoveFromSearchList_Inst(const std::wstring &KeychainPath)
{
	std::string u16KeychainPath;
	sb_to_u16string(KeychainPath, u16KeychainPath);
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16KeychainPath.data()), (int32_t)u16KeychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAppleCertStorage::RemoveFromSearchList(TStringList &KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_2(KeychainsPath.getHandle()));
}

SB_INLINE void TElAppleCertStorage::RemoveFromSearchList(TStringList *KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_2((KeychainsPath != NULL) ? KeychainsPath->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElAppleCertStorage::RemoveFromSearchList_Inst(TStringList &KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_3(_Handle, KeychainsPath.getHandle()));
}

SB_INLINE void TElAppleCertStorage::RemoveFromSearchList_Inst(TStringList *KeychainsPath)
{
	SBCheckError(TElAppleCertStorage_RemoveFromSearchList_3(_Handle, (KeychainsPath != NULL) ? KeychainsPath->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE void TElAppleCertStorage::CreateKeychain(const sb_u16string &keychainPath)
{
	SBCheckError(TElAppleCertStorage_CreateKeychain(keychainPath.data(), (int32_t)keychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::CreateKeychain(const std::wstring &keychainPath)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_CreateKeychain(reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::CreateKeychain_Inst(const sb_u16string &keychainPath)
{
	SBCheckError(TElAppleCertStorage_CreateKeychain_1(_Handle, keychainPath.data(), (int32_t)keychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::CreateKeychain_Inst(const std::wstring &keychainPath)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_CreateKeychain_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::CreateKeychain(const sb_u16string &keychainPath, const sb_u16string &password)
{
	SBCheckError(TElAppleCertStorage_CreateKeychain_2(keychainPath.data(), (int32_t)keychainPath.length(), password.data(), (int32_t)password.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::CreateKeychain(const std::wstring &keychainPath, const std::wstring &password)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	std::string u16password;
	sb_to_u16string(password, u16password);
	SBCheckError(TElAppleCertStorage_CreateKeychain_2(reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16password.data()), (int32_t)u16password.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::CreateKeychain_Inst(const sb_u16string &keychainPath, const sb_u16string &password)
{
	SBCheckError(TElAppleCertStorage_CreateKeychain_3(_Handle, keychainPath.data(), (int32_t)keychainPath.length(), password.data(), (int32_t)password.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::CreateKeychain_Inst(const std::wstring &keychainPath, const std::wstring &password)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	std::string u16password;
	sb_to_u16string(password, u16password);
	SBCheckError(TElAppleCertStorage_CreateKeychain_3(_Handle, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16password.data()), (int32_t)u16password.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::DeleteKeychain(const sb_u16string &keychainPath)
{
	SBCheckError(TElAppleCertStorage_DeleteKeychain(keychainPath.data(), (int32_t)keychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::DeleteKeychain(const std::wstring &keychainPath)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_DeleteKeychain(reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::DeleteKeychain_Inst(const sb_u16string &keychainPath)
{
	SBCheckError(TElAppleCertStorage_DeleteKeychain_1(_Handle, keychainPath.data(), (int32_t)keychainPath.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::DeleteKeychain_Inst(const std::wstring &keychainPath)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_DeleteKeychain_1(_Handle, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::DeleteKeychain(const sb_u16string &keychainPath, const sb_u16string &password)
{
	SBCheckError(TElAppleCertStorage_DeleteKeychain_2(keychainPath.data(), (int32_t)keychainPath.length(), password.data(), (int32_t)password.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::DeleteKeychain(const std::wstring &keychainPath, const std::wstring &password)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	std::string u16password;
	sb_to_u16string(password, u16password);
	SBCheckError(TElAppleCertStorage_DeleteKeychain_2(reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16password.data()), (int32_t)u16password.length() >> 1));
}
#endif /* SB_U16STRING_USED */

SB_INLINE void TElAppleCertStorage::DeleteKeychain_Inst(const sb_u16string &keychainPath, const sb_u16string &password)
{
	SBCheckError(TElAppleCertStorage_DeleteKeychain_3(_Handle, keychainPath.data(), (int32_t)keychainPath.length(), password.data(), (int32_t)password.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::DeleteKeychain_Inst(const std::wstring &keychainPath, const std::wstring &password)
{
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	std::string u16password;
	sb_to_u16string(password, u16password);
	SBCheckError(TElAppleCertStorage_DeleteKeychain_3(_Handle, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, reinterpret_cast<const sb_char16_t*>(u16password.data()), (int32_t)u16password.length() >> 1));
}
#endif /* SB_U16STRING_USED */

#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElAppleCertStorage_Add(_Handle, Certificate.getHandle(), (int8_t)CopyPrivateKey));
}

SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, bool CopyPrivateKey)
{
	SBCheckError(TElAppleCertStorage_Add(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)CopyPrivateKey));
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, const sb_u16string &keychainPath, bool CopyPrivateKey, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, const sb_u16string &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, Certificate.getHandle(), keychainPath.data(), (int32_t)keychainPath.length(), (int8_t)CopyPrivateKey, (int8_t)setTrusted));
#else
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, Certificate.getHandle(), accessGroup.data(), (int32_t)accessGroup.length(), (int8_t)CopyPrivateKey, (int8_t)accessibleThisDeviceOnly));
#endif
}

#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, const sb_u16string &keychainPath, bool CopyPrivateKey, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, const sb_u16string &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, keychainPath.data(), (int32_t)keychainPath.length(), (int8_t)CopyPrivateKey, (int8_t)setTrusted));
#else
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, accessGroup.data(), (int32_t)accessGroup.length(), (int8_t)CopyPrivateKey, (int8_t)accessibleThisDeviceOnly));
#endif
}
#ifdef SB_U16STRING_USED
#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, const std::wstring &keychainPath, bool CopyPrivateKey, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, const std::wstring &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, Certificate.getHandle(), reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, (int8_t)CopyPrivateKey, (int8_t)setTrusted));
#else
	std::string u16accessGroup;
	sb_to_u16string(accessGroup, u16accessGroup);
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, Certificate.getHandle(), reinterpret_cast<const sb_char16_t*>(u16accessGroup.data()), (int32_t)u16accessGroup.length() >> 1, (int8_t)CopyPrivateKey, (int8_t)accessibleThisDeviceOnly));
#endif
}

#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, const std::wstring &keychainPath, bool CopyPrivateKey, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, const std::wstring &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, (int8_t)CopyPrivateKey, (int8_t)setTrusted));
#else
	std::string u16accessGroup;
	sb_to_u16string(accessGroup, u16accessGroup);
	SBCheckError(TElAppleCertStorage_Add_1(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16accessGroup.data()), (int32_t)u16accessGroup.length() >> 1, (int8_t)CopyPrivateKey, (int8_t)accessibleThisDeviceOnly));
#endif
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const sb_u16string &keychainPath, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const sb_u16string &accessGroup, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, Certificate.getHandle(), (int8_t)BindToExistingPrivateKey, keychainPath.data(), (int32_t)keychainPath.length(), (int8_t)setTrusted));
#else
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, Certificate.getHandle(), (int8_t)BindToExistingPrivateKey, accessGroup.data(), (int32_t)accessGroup.length(), (int8_t)accessibleThisDeviceOnly));
#endif
}

#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const sb_u16string &keychainPath, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const sb_u16string &accessGroup, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)BindToExistingPrivateKey, keychainPath.data(), (int32_t)keychainPath.length(), (int8_t)setTrusted));
#else
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)BindToExistingPrivateKey, accessGroup.data(), (int32_t)accessGroup.length(), (int8_t)accessibleThisDeviceOnly));
#endif
}
#ifdef SB_U16STRING_USED
#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::wstring &keychainPath, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::wstring &accessGroup, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, Certificate.getHandle(), (int8_t)BindToExistingPrivateKey, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, (int8_t)setTrusted));
#else
	std::string u16accessGroup;
	sb_to_u16string(accessGroup, u16accessGroup);
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, Certificate.getHandle(), (int8_t)BindToExistingPrivateKey, reinterpret_cast<const sb_char16_t*>(u16accessGroup.data()), (int32_t)u16accessGroup.length() >> 1, (int8_t)accessibleThisDeviceOnly));
#endif
}

#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::wstring &keychainPath, bool setTrusted)
#else
SB_INLINE void TElAppleCertStorage::Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::wstring &accessGroup, bool accessibleThisDeviceOnly)
#endif
{
#ifndef SB_IOS
	std::string u16keychainPath;
	sb_to_u16string(keychainPath, u16keychainPath);
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)BindToExistingPrivateKey, reinterpret_cast<const sb_char16_t*>(u16keychainPath.data()), (int32_t)u16keychainPath.length() >> 1, (int8_t)setTrusted));
#else
	std::string u16accessGroup;
	sb_to_u16string(accessGroup, u16accessGroup);
	SBCheckError(TElAppleCertStorage_Add_2(_Handle, (Certificate != NULL) ? Certificate->getHandle() : SB_NULL_HANDLE, (int8_t)BindToExistingPrivateKey, reinterpret_cast<const sb_char16_t*>(u16accessGroup.data()), (int32_t)u16accessGroup.length() >> 1, (int8_t)accessibleThisDeviceOnly));
#endif
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE void TElAppleCertStorage::ClearAll()
{
	SBCheckError(TElAppleCertStorage_ClearAll(_Handle));
}

SB_INLINE void TElAppleCertStorage::Remove(int32_t Index)
{
	SBCheckError(TElAppleCertStorage_Remove(_Handle, Index));
}

SB_INLINE void TElAppleCertStorage::Refresh()
{
	SBCheckError(TElAppleCertStorage_Refresh(_Handle));
}

SB_INLINE void TElAppleCertStorage::PreloadCertificates()
{
	SBCheckError(TElAppleCertStorage_PreloadCertificates(_Handle));
}

#ifndef SB_IOS
SB_INLINE void TElAppleCertStorage::EvaluateTrust(int32_t Index)
#else
SB_INLINE void TElAppleCertStorage::EvaluateTrust(int32_t Index, bool setTrusted)
#endif
{
#ifndef SB_IOS
	SBCheckError(TElAppleCertStorage_EvaluateTrust(_Handle, Index));
#else
	SBCheckError(TElAppleCertStorage_EvaluateTrust(_Handle, Index, (int8_t)setTrusted));
#endif
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElAppleCertStorage::ExportWithPrivateKey(int32_t Index, const sb_u16string &password)
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElAppleCertStorage_ExportWithPrivateKey(_Handle, Index, password.data(), (int32_t)password.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElX509CertificateHandle TElAppleCertStorage::ExportWithPrivateKey(int32_t Index, const std::wstring &password)
{
	TElX509CertificateHandle OutResult;
	std::string u16password;
	sb_to_u16string(password, u16password);
	SBCheckError(TElAppleCertStorage_ExportWithPrivateKey(_Handle, Index, reinterpret_cast<const sb_char16_t*>(u16password.data()), (int32_t)u16password.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

SB_INLINE int32_t TElAppleCertStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElAppleCertStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
TElX509Certificate* TElAppleCertStorage::get_Certificates(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAppleCertStorage_get_Certificates(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElX509Certificate(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElAppleCertStorage::get_Keychains()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAppleCertStorage_get_Keychains(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keychains)
		this->_Inst_Keychains = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Keychains->updateHandle(hOutResult);
	return this->_Inst_Keychains;
}

SB_INLINE void TElAppleCertStorage::set_Keychains(TStringList &Value)
{
	SBCheckError(TElAppleCertStorage_set_Keychains(_Handle, Value.getHandle()));
}

SB_INLINE void TElAppleCertStorage::set_Keychains(TStringList *Value)
{
	SBCheckError(TElAppleCertStorage_set_Keychains(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

#endif
bool TElAppleCertStorage::get_ReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAppleCertStorage_get_ReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAppleCertStorage::set_ReadOnly(bool Value)
{
	SBCheckError(TElAppleCertStorage_set_ReadOnly(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProvider* TElAppleCertStorage::get_CryptoProvider()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAppleCertStorage_get_CryptoProvider(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CryptoProvider)
		this->_Inst_CryptoProvider = new TElCustomCryptoProvider(hOutResult, ohFalse);
	else
		this->_Inst_CryptoProvider->updateHandle(hOutResult);
	return this->_Inst_CryptoProvider;
}

SB_INLINE void TElAppleCertStorage::set_CryptoProvider(TElCustomCryptoProvider &Value)
{
	SBCheckError(TElAppleCertStorage_set_CryptoProvider(_Handle, Value.getHandle()));
}

SB_INLINE void TElAppleCertStorage::set_CryptoProvider(TElCustomCryptoProvider *Value)
{
	SBCheckError(TElAppleCertStorage_set_CryptoProvider(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void TElAppleCertStorage::get_LastPassword(sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElAppleCertStorage_get_LastPassword(_Handle, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(279149066, 1, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_U16STRING_USED
void TElAppleCertStorage::get_LastPassword(std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = TElAppleCertStorage_get_LastPassword(_Handle, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(279149066, 1, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAppleCertStorage::set_LastPassword(const sb_u16string &Value)
{
	SBCheckError(TElAppleCertStorage_set_LastPassword(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_U16STRING_USED
SB_INLINE void TElAppleCertStorage::set_LastPassword(const std::wstring &Value)
{
	std::string u16Value;
	sb_to_u16string(Value, u16Value);
	SBCheckError(TElAppleCertStorage_set_LastPassword(_Handle, reinterpret_cast<const sb_char16_t*>(u16Value.data()), (int32_t)u16Value.length() >> 1));
}

#endif /* SB_U16STRING_USED */
SB_INLINE void TElAppleCertStorage::get_OnEvaluationResult(TElEvaluationResultEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAppleCertStorage_get_OnEvaluationResult(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAppleCertStorage::set_OnEvaluationResult(TElEvaluationResultEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAppleCertStorage_set_OnEvaluationResult(_Handle, pMethodValue, pDataValue));
}

void TElAppleCertStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Keychains = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}

TElAppleCertStorage::TElAppleCertStorage(TElAppleCertStorageHandle handle, TElOwnHandle ownHandle) : TElCustomCertStorage(handle, ownHandle)
{
	initInstances();
}

TElAppleCertStorage::TElAppleCertStorage(TComponent &Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAppleCertStorage_Create(Owner.getHandle(), &_Handle));
}

TElAppleCertStorage::TElAppleCertStorage(TComponent *Owner) : TElCustomCertStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAppleCertStorage_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElAppleCertStorage::~TElAppleCertStorage()
{
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Keychains;
	this->_Inst_Keychains = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
	delete this->_Inst_CryptoProvider;
	this->_Inst_CryptoProvider = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
}
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */

};	/* namespace SecureBlackbox */
#endif
