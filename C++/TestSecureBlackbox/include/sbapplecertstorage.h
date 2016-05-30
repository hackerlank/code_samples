#ifndef __INC_SBAPPLECERTSTORAGE
#define __INC_SBAPPLECERTSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#ifdef MACOS
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbapplecommon.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovbuiltin.h"
#endif

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef MACOS
typedef TElClassHandle TElAppleCertStorageHandle;

typedef TElAppleCertStorageHandle ElAppleCertStorageHandle;

#ifndef SB_IOS
typedef void (SB_CALLBACK *TElEvaluationResultEvent)(void * _ObjectData, TObjectHandle Sender, const sb_char16_t * pcres, int32_t szres, const SB_SecTrustResultTypeRaw resType);
#else
typedef void (SB_CALLBACK *TElEvaluationResultEvent)(void * _ObjectData, TObjectHandle Sender, const sb_char16_t * pcres, int32_t szres, const SB_SecTrustResultTypeRaw resType, SB_SecTrustRef trust);
#endif

#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_GetOpenedKeychains(TStringsHandle Keychains);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_GetOpenedKeychains_1(TElAppleCertStorageHandle _Handle, TStringsHandle Keychains);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_AddToSearchList(const sb_char16_t * pcKeychainPath, int32_t szKeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_AddToSearchList_1(TElAppleCertStorageHandle _Handle, const sb_char16_t * pcKeychainPath, int32_t szKeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_AddToSearchList_2(TStringListHandle KeychainsPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_AddToSearchList_3(TElAppleCertStorageHandle _Handle, TStringListHandle KeychainsPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_RemoveFromSearchList(const sb_char16_t * pcKeychainPath, int32_t szKeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_RemoveFromSearchList_1(TElAppleCertStorageHandle _Handle, const sb_char16_t * pcKeychainPath, int32_t szKeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_RemoveFromSearchList_2(TStringListHandle KeychainsPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_RemoveFromSearchList_3(TElAppleCertStorageHandle _Handle, TStringListHandle KeychainsPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_CreateKeychain(const sb_char16_t * pckeychainPath, int32_t szkeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_CreateKeychain_1(TElAppleCertStorageHandle _Handle, const sb_char16_t * pckeychainPath, int32_t szkeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_CreateKeychain_2(const sb_char16_t * pckeychainPath, int32_t szkeychainPath, const sb_char16_t * pcpassword, int32_t szpassword);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_CreateKeychain_3(TElAppleCertStorageHandle _Handle, const sb_char16_t * pckeychainPath, int32_t szkeychainPath, const sb_char16_t * pcpassword, int32_t szpassword);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_DeleteKeychain(const sb_char16_t * pckeychainPath, int32_t szkeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_DeleteKeychain_1(TElAppleCertStorageHandle _Handle, const sb_char16_t * pckeychainPath, int32_t szkeychainPath);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_DeleteKeychain_2(const sb_char16_t * pckeychainPath, int32_t szkeychainPath, const sb_char16_t * pcpassword, int32_t szpassword);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_DeleteKeychain_3(TElAppleCertStorageHandle _Handle, const sb_char16_t * pckeychainPath, int32_t szkeychainPath, const sb_char16_t * pcpassword, int32_t szpassword);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Add(TElAppleCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t CopyPrivateKey);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Add_1(TElAppleCertStorageHandle _Handle, TElX509CertificateHandle Certificate, const sb_char16_t * pckeychainPath, int32_t szkeychainPath, int8_t CopyPrivateKey, int8_t setTrusted);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Add_2(TElAppleCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t BindToExistingPrivateKey, const sb_char16_t * pckeychainPath, int32_t szkeychainPath, int8_t setTrusted);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Add_1(TElAppleCertStorageHandle _Handle, TElX509CertificateHandle Certificate, const sb_char16_t * pcaccessGroup, int32_t szaccessGroup, int8_t CopyPrivateKey, int8_t accessibleThisDeviceOnly);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Add_2(TElAppleCertStorageHandle _Handle, TElX509CertificateHandle Certificate, int8_t BindToExistingPrivateKey, const sb_char16_t * pcaccessGroup, int32_t szaccessGroup, int8_t accessibleThisDeviceOnly);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_ClearAll(TElAppleCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Remove(TElAppleCertStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Refresh(TElAppleCertStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_PreloadCertificates(TElAppleCertStorageHandle _Handle);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_EvaluateTrust(TElAppleCertStorageHandle _Handle, int32_t Index);
#else
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_EvaluateTrust(TElAppleCertStorageHandle _Handle, int32_t Index, int8_t setTrusted);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_ExportWithPrivateKey(TElAppleCertStorageHandle _Handle, int32_t Index, const sb_char16_t * pcpassword, int32_t szpassword, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_Count(TElAppleCertStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_Certificates(TElAppleCertStorageHandle _Handle, int32_t Index, TElX509CertificateHandle * OutResult);
#ifndef SB_IOS
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_Keychains(TElAppleCertStorageHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_set_Keychains(TElAppleCertStorageHandle _Handle, TStringListHandle Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_ReadOnly(TElAppleCertStorageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_set_ReadOnly(TElAppleCertStorageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_CryptoProvider(TElAppleCertStorageHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_set_CryptoProvider(TElAppleCertStorageHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_LastPassword(TElAppleCertStorageHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_set_LastPassword(TElAppleCertStorageHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_get_OnEvaluationResult(TElAppleCertStorageHandle _Handle, TElEvaluationResultEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_set_OnEvaluationResult(TElAppleCertStorageHandle _Handle, TElEvaluationResultEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAppleCertStorage_Create(TComponentHandle Owner, TElAppleCertStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef MACOS
#ifdef __cplusplus

// Class forward declaration
class TElAppleCertStorage;
typedef TElAppleCertStorage ElAppleCertStorage;

#ifdef SB_USE_CLASS_TELAPPLECERTSTORAGE
class TElAppleCertStorage: public TElCustomCertStorage
{
	private:
		SB_DISABLE_COPY(TElAppleCertStorage)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Keychains;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		void initInstances();

	public:
#ifndef SB_IOS
#ifdef SB_USE_CLASS_TSTRINGS
		static void GetOpenedKeychains(TStrings &Keychains);

		static void GetOpenedKeychains(TStrings *Keychains);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGS
		void GetOpenedKeychains_Inst(TStrings &Keychains);

		void GetOpenedKeychains_Inst(TStrings *Keychains);
#endif /* SB_USE_CLASS_TSTRINGS */

		static void AddToSearchList(const sb_u16string &KeychainPath);
#ifdef SB_U16STRING_USED
		static void AddToSearchList(const std::wstring &KeychainPath);
#endif /* SB_U16STRING_USED */

		void AddToSearchList_Inst(const sb_u16string &KeychainPath);
#ifdef SB_U16STRING_USED
		void AddToSearchList_Inst(const std::wstring &KeychainPath);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTRINGLIST
		static void AddToSearchList(TStringList &KeychainsPath);

		static void AddToSearchList(TStringList *KeychainsPath);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		void AddToSearchList_Inst(TStringList &KeychainsPath);

		void AddToSearchList_Inst(TStringList *KeychainsPath);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		static void RemoveFromSearchList(const sb_u16string &KeychainPath);
#ifdef SB_U16STRING_USED
		static void RemoveFromSearchList(const std::wstring &KeychainPath);
#endif /* SB_U16STRING_USED */

		void RemoveFromSearchList_Inst(const sb_u16string &KeychainPath);
#ifdef SB_U16STRING_USED
		void RemoveFromSearchList_Inst(const std::wstring &KeychainPath);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TSTRINGLIST
		static void RemoveFromSearchList(TStringList &KeychainsPath);

		static void RemoveFromSearchList(TStringList *KeychainsPath);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
		void RemoveFromSearchList_Inst(TStringList &KeychainsPath);

		void RemoveFromSearchList_Inst(TStringList *KeychainsPath);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		static void CreateKeychain(const sb_u16string &keychainPath);
#ifdef SB_U16STRING_USED
		static void CreateKeychain(const std::wstring &keychainPath);
#endif /* SB_U16STRING_USED */

		void CreateKeychain_Inst(const sb_u16string &keychainPath);
#ifdef SB_U16STRING_USED
		void CreateKeychain_Inst(const std::wstring &keychainPath);
#endif /* SB_U16STRING_USED */

		static void CreateKeychain(const sb_u16string &keychainPath, const sb_u16string &password);
#ifdef SB_U16STRING_USED
		static void CreateKeychain(const std::wstring &keychainPath, const std::wstring &password);
#endif /* SB_U16STRING_USED */

		void CreateKeychain_Inst(const sb_u16string &keychainPath, const sb_u16string &password);
#ifdef SB_U16STRING_USED
		void CreateKeychain_Inst(const std::wstring &keychainPath, const std::wstring &password);
#endif /* SB_U16STRING_USED */

		static void DeleteKeychain(const sb_u16string &keychainPath);
#ifdef SB_U16STRING_USED
		static void DeleteKeychain(const std::wstring &keychainPath);
#endif /* SB_U16STRING_USED */

		void DeleteKeychain_Inst(const sb_u16string &keychainPath);
#ifdef SB_U16STRING_USED
		void DeleteKeychain_Inst(const std::wstring &keychainPath);
#endif /* SB_U16STRING_USED */

		static void DeleteKeychain(const sb_u16string &keychainPath, const sb_u16string &password);
#ifdef SB_U16STRING_USED
		static void DeleteKeychain(const std::wstring &keychainPath, const std::wstring &password);
#endif /* SB_U16STRING_USED */

		void DeleteKeychain_Inst(const sb_u16string &keychainPath, const sb_u16string &password);
#ifdef SB_U16STRING_USED
		void DeleteKeychain_Inst(const std::wstring &keychainPath, const std::wstring &password);
#endif /* SB_U16STRING_USED */

#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual void Add(TElX509Certificate &Certificate, bool CopyPrivateKey);

		virtual void Add(TElX509Certificate *Certificate, bool CopyPrivateKey);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
#ifndef SB_IOS
		void Add(TElX509Certificate &Certificate, const sb_u16string &keychainPath, bool CopyPrivateKey, bool setTrusted);
#else
		void Add(TElX509Certificate &Certificate, const sb_u16string &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly);
#endif

#ifndef SB_IOS
		void Add(TElX509Certificate *Certificate, const sb_u16string &keychainPath, bool CopyPrivateKey, bool setTrusted);
#else
		void Add(TElX509Certificate *Certificate, const sb_u16string &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly);
#endif
#ifdef SB_U16STRING_USED
#ifndef SB_IOS
		void Add(TElX509Certificate &Certificate, const std::wstring &keychainPath, bool CopyPrivateKey, bool setTrusted);
#else
		void Add(TElX509Certificate &Certificate, const std::wstring &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly);
#endif

#ifndef SB_IOS
		void Add(TElX509Certificate *Certificate, const std::wstring &keychainPath, bool CopyPrivateKey, bool setTrusted);
#else
		void Add(TElX509Certificate *Certificate, const std::wstring &accessGroup, bool CopyPrivateKey, bool accessibleThisDeviceOnly);
#endif
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
#ifndef SB_IOS
		void Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const sb_u16string &keychainPath, bool setTrusted);
#else
		void Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const sb_u16string &accessGroup, bool accessibleThisDeviceOnly);
#endif

#ifndef SB_IOS
		void Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const sb_u16string &keychainPath, bool setTrusted);
#else
		void Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const sb_u16string &accessGroup, bool accessibleThisDeviceOnly);
#endif
#ifdef SB_U16STRING_USED
#ifndef SB_IOS
		void Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::wstring &keychainPath, bool setTrusted);
#else
		void Add(TElX509Certificate &Certificate, bool BindToExistingPrivateKey, const std::wstring &accessGroup, bool accessibleThisDeviceOnly);
#endif

#ifndef SB_IOS
		void Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::wstring &keychainPath, bool setTrusted);
#else
		void Add(TElX509Certificate *Certificate, bool BindToExistingPrivateKey, const std::wstring &accessGroup, bool accessibleThisDeviceOnly);
#endif
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void ClearAll();

		virtual void Remove(int32_t Index);

		void Refresh();

		void PreloadCertificates();

#ifndef SB_IOS
		void EvaluateTrust(int32_t Index);
#else
		void EvaluateTrust(int32_t Index, bool setTrusted);
#endif

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle ExportWithPrivateKey(int32_t Index, const sb_u16string &password);
#ifdef SB_U16STRING_USED
		TElX509CertificateHandle ExportWithPrivateKey(int32_t Index, const std::wstring &password);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElAppleCertStorage, Count);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificates(int32_t Index);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifndef SB_IOS

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Keychains();

		virtual void set_Keychains(TStringList &Value);

		virtual void set_Keychains(TStringList *Value);

		SB_DECLARE_PROPERTY(TStringList*, get_Keychains, set_Keychains, TElAppleCertStorage, Keychains);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif

		virtual bool get_ReadOnly();

		virtual void set_ReadOnly(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReadOnly, set_ReadOnly, TElAppleCertStorage, ReadOnly);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElAppleCertStorage, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

		virtual void get_LastPassword(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_LastPassword(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_LastPassword(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_LastPassword(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OnEvaluationResult(TElEvaluationResultEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEvaluationResult(TElEvaluationResultEvent pMethodValue, void * pDataValue);

		TElAppleCertStorage(TElAppleCertStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElAppleCertStorage(TComponent &Owner);

		explicit TElAppleCertStorage(TComponent *Owner);

		virtual ~TElAppleCertStorage();

};
#endif /* SB_USE_CLASS_TELAPPLECERTSTORAGE */

#endif  /* __cplusplus */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAPPLECERTSTORAGE */
