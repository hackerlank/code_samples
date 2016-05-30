#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbwincrypt.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_WINCRYPT

#ifndef CPU64
SB_INLINE void * CertOpenSystemStore(uint32_t hProv, char * szSubsystemProtocol)
#else
SB_INLINE void * CertOpenSystemStore(int64_t hProv, char * szSubsystemProtocol)
#endif
{
	void * OutResult;
	SBCheckError(SBWinCrypt_CertOpenSystemStore(hProv, szSubsystemProtocol, &OutResult));
	return OutResult;
}

SB_INLINE PCCERT_CONTEXT CertFindCertificateInStore(void * hCertStore, uint32_t dwCertEncodingType, uint32_t dwFindFlags, uint32_t dwFindType, const void * pvFindPara, PCCERT_CONTEXT pPrevCertContext)
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(SBWinCrypt_CertFindCertificateInStore(hCertStore, dwCertEncodingType, dwFindFlags, dwFindType, pvFindPara, pPrevCertContext, &OutResult));
	return OutResult;
}

bool CertCloseStore(void * hCertStore, uint32_t dwFlags)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertCloseStore(hCertStore, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CertEnumSystemStore(uint32_t dwFlags, void * pvSystemStoreLocationPara, void * pvArg, PFN_CERT_ENUM_SYSTEM_STORE pfnEnum)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertEnumSystemStore(dwFlags, pvSystemStoreLocationPara, pvArg, pfnEnum, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CertAddEncodedCertificateToStore(void * hCertStore, uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded, uint32_t dwAddDisposition, PCCERT_CONTEXT &ppCertContext)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertAddEncodedCertificateToStore(hCertStore, dwCertEncodingType, pbCertEncoded, cbCertEncoded, dwAddDisposition, &ppCertContext, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CertFreeCertificateContext(PCCERT_CONTEXT pCertContext)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertFreeCertificateContext(pCertContext, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CertDeleteCertificateFromStore(PCCERT_CONTEXT pCertContext)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertDeleteCertificateFromStore(pCertContext, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE PCCERT_CONTEXT CertEnumCertificatesInStore(void * hCertStore, PCCERT_CONTEXT pPrevCertContext)
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(SBWinCrypt_CertEnumCertificatesInStore(hCertStore, pPrevCertContext, &OutResult));
	return OutResult;
}

SB_INLINE PCCERT_CONTEXT CertDuplicateCertificateContext(PCCERT_CONTEXT pCertContext)
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(SBWinCrypt_CertDuplicateCertificateContext(pCertContext, &OutResult));
	return OutResult;
}

bool CertEnumPhysicalStore(void * pvSystemStore, uint32_t dwFlags, void * pvArg, PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertEnumPhysicalStore(pvSystemStore, dwFlags, pvArg, pfnEnum, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
SB_INLINE void * CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, uint32_t hCryptProv, uint32_t dwFlags, const void * pvPara)
#else
SB_INLINE void * CertOpenStore(char * lpszStoreProvider, uint32_t dwMsgAndCertEncodingType, int64_t hCryptProv, uint32_t dwFlags, const void * pvPara)
#endif
{
	void * OutResult;
	SBCheckError(SBWinCrypt_CertOpenStore(lpszStoreProvider, dwMsgAndCertEncodingType, hCryptProv, dwFlags, pvPara, &OutResult));
	return OutResult;
}

bool CertGetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, void * pvData, uint32_t * pcbData)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertGetCertificateContextProperty(pCertContext, dwPropId, pvData, pcbData, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CertSetCertificateContextProperty(PCCERT_CONTEXT pCertContext, uint32_t dwPropId, uint32_t dwFlags, void * pvData)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CertSetCertificateContextProperty(pCertContext, dwPropId, dwFlags, pvData, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptAcquireContext(uint32_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags)
#else
bool CryptAcquireContext(int64_t * hProv, char * pszContainer, char * pszProvider, uint32_t dwProvType, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptAcquireContext(hProv, pszContainer, pszProvider, dwProvType, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptContextAddRef(uint32_t hProv, uint32_t * pdwReserved, uint32_t dwFlags)
#else
bool CryptContextAddRef(int64_t hProv, uint32_t * pdwReserved, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptContextAddRef(hProv, pdwReserved, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptGetUserKey(uint32_t hProv, uint32_t dwKeySpec, uint32_t * phUserKey)
#else
bool CryptGetUserKey(int64_t hProv, uint32_t dwKeySpec, int64_t * phUserKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptGetUserKey(hProv, dwKeySpec, phUserKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptDestroyKey(uint32_t hKey)
#else
bool CryptDestroyKey(int64_t hKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDestroyKey(hKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptReleaseContext(uint32_t hProv, uint32_t dwFlags)
#else
bool CryptReleaseContext(int64_t hProv, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptReleaseContext(hProv, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptExportKey(uint32_t hKey, uint32_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen)
#else
bool CryptExportKey(int64_t hKey, int64_t hExpKey, uint32_t dwBlobType, uint32_t dwFlags, uint8_t * pbData, uint32_t * pdwDataLen)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptExportKey(hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptImportKey(uint32_t hProv, uint8_t * pbData, uint32_t dwDataLen, uint32_t hPubKey, uint32_t dwFlags, uint32_t * phKey)
#else
bool CryptImportKey(int64_t hProv, uint8_t * pbData, uint32_t dwDataLen, int64_t hPubKey, uint32_t dwFlags, int64_t * phKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptImportKey(hProv, pbData, dwDataLen, hPubKey, dwFlags, phKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CryptSignMessage(PCRYPT_SIGN_MESSAGE_PARA pSignPara, bool fDetachedSignature, uint32_t cToBeSigned, const uint8_t * (* rgpbToBeSigned), uint32_t * rgcbToBeSigned, uint8_t * pbSignedBlob, uint32_t * pcbSignedBlob)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptSignMessage(pSignPara, (int32_t)fDetachedSignature, cToBeSigned, rgpbToBeSigned, rgcbToBeSigned, pbSignedBlob, pcbSignedBlob, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, uint32_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv)
#else
bool CryptAcquireCertificatePrivateKey(PCCERT_CONTEXT pCert, uint32_t dwFlags, void * pvReserved, int64_t * phCryptProv, uint32_t * pdwKeySpec, int32_t * pfCallerFreeProv)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptAcquireCertificatePrivateKey(pCert, dwFlags, pvReserved, phCryptProv, pdwKeySpec, pfCallerFreeProv, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptCreateHash(uint32_t hProv, uint32_t AlgId, uint32_t hKey, uint32_t dwFlags, uint32_t * phHash)
#else
bool CryptCreateHash(int64_t hProv, uint32_t AlgId, int64_t hKey, uint32_t dwFlags, int64_t * phHash)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptCreateHash(hProv, AlgId, hKey, dwFlags, phHash, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptSetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#else
bool CryptSetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptSetHashParam(hHash, dwParam, pbData, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptGetHashParam(uint32_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwFlags)
#else
bool CryptGetHashParam(int64_t hHash, uint32_t dwParam, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptGetHashParam(hHash, dwParam, pbData, &pdwDataLen, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptSignHash(uint32_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen)
#else
bool CryptSignHash(int64_t hHash, uint32_t dwKeySpec, char * sDescription, uint32_t dwFlags, uint8_t * pbSignature, uint32_t * pdwSigLen)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptSignHash(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptDestroyHash(uint32_t hHash)
#else
bool CryptDestroyHash(int64_t hHash)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDestroyHash(hHash, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptHashData(uint32_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags)
#else
bool CryptHashData(int64_t hHash, uint8_t * pbData, uint32_t dwDataLen, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptHashData(hHash, pbData, dwDataLen, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptVerifySignature(uint32_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, uint32_t hPubKey, char * sDescription, uint32_t dwFlags)
#else
bool CryptVerifySignature(int64_t hHash, uint8_t * pbSignature, uint32_t dwSigLen, int64_t hPubKey, char * sDescription, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptVerifySignature(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE sb_char16_t * CryptFindLocalizedName(const sb_char16_t * pwszCryptName)
{
	sb_char16_t * OutResult;
	SBCheckError(SBWinCrypt_CryptFindLocalizedName(pwszCryptName, &OutResult));
	return OutResult;
}

bool CryptDecryptMessage(PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, uint8_t * pbEncryptedBlob, uint32_t cbEncryptedBlob, uint8_t * pbDecrypted, uint32_t * pcbDecrypted, PCCERT_CONTEXT (* ppXchgCert))
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDecryptMessage(pDecryptPara, pbEncryptedBlob, cbEncryptedBlob, pbDecrypted, pcbDecrypted, ppXchgCert, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptDecrypt(uint32_t hKey, uint32_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen)
#else
bool CryptDecrypt(int64_t hKey, int64_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDecrypt(hKey, hHash, (int32_t)Final, dwFlags, pbData, &pdwDataLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptEncrypt(uint32_t hKey, uint32_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwBufLen)
#else
bool CryptEncrypt(int64_t hKey, int64_t hHash, bool Final, uint32_t dwFlags, uint8_t * pbData, uint32_t &pdwDataLen, uint32_t dwBufLen)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptEncrypt(hKey, hHash, (int32_t)Final, dwFlags, pbData, &pdwDataLen, dwBufLen, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptDuplicateKey(uint32_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, uint32_t &phKey)
#else
bool CryptDuplicateKey(int64_t hKey, uint32_t * pdwReserved, uint32_t dwFlags, int64_t &phKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDuplicateKey(hKey, pdwReserved, dwFlags, &phKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE PCCERT_CONTEXT CertCreateCertificateContext(uint32_t dwCertEncodingType, const uint8_t * pbCertEncoded, uint32_t cbCertEncoded)
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(SBWinCrypt_CertCreateCertificateContext(dwCertEncodingType, pbCertEncoded, cbCertEncoded, &OutResult));
	return OutResult;
}

#ifndef CPU64
bool CryptGetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags)
#else
bool CryptGetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t * pwdDataLen, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptGetProvParam(hProv, dwParam, pbData, pwdDataLen, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptGetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags)
#else
bool CryptGetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t * pdwDataLen, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptGetKeyParam(hKey, dwParam, pbData, pdwDataLen, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptDeriveKey(uint32_t hProv, uint32_t Algid, uint32_t hBaseData, uint32_t dwFlags, uint32_t * phKey)
#else
bool CryptDeriveKey(int64_t hProv, uint32_t Algid, int64_t hBaseData, uint32_t dwFlags, int64_t * phKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptDeriveKey(hProv, Algid, hBaseData, dwFlags, phKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptGenKey(uint32_t hProv, uint32_t Algid, uint32_t dwFlags, uint32_t * phKey)
#else
bool CryptGenKey(int64_t hProv, uint32_t Algid, uint32_t dwFlags, int64_t * phKey)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptGenKey(hProv, Algid, dwFlags, phKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CryptRegisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID, sb_char16_t * pwszDll, char * pszOverrideFuncName)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptRegisterOIDFunction(dwEncodingType, pszFuncName, pszOID, pwszDll, pszOverrideFuncName, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CryptUnregisterOIDFunction(uint32_t dwEncodingType, char * pszFuncName, char * pszOID)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptUnregisterOIDFunction(dwEncodingType, pszFuncName, pszOID, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CryptInstallOIDFunctionAddress(uint32_t hModule, uint32_t dwEncodingType, char * pszFuncName, uint32_t cFuncEntry, PCRYPT_OID_FUNC_ENTRY rgFuncEntry, uint32_t dwFlags)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptInstallOIDFunctionAddress(hModule, dwEncodingType, pszFuncName, cFuncEntry, rgFuncEntry, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t CoCreateGuid(PGUID guid)
{
	int32_t OutResult;
	SBCheckError(SBWinCrypt_CoCreateGuid(guid, &OutResult));
	return OutResult;
}

SB_INLINE void GetProcedureAddress(void * &P, const std::string &ModuleName, const std::string &ProcName)
{
	SBCheckError(SBWinCrypt_GetProcedureAddress(&P, ModuleName.data(), (int32_t)ModuleName.length(), ProcName.data(), (int32_t)ProcName.length()));
}

#ifndef CPU64
bool CryptSetProvParam(uint32_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#else
bool CryptSetProvParam(int64_t hProv, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptSetProvParam(hProv, dwParam, pbData, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifndef CPU64
bool CryptSetKeyParam(uint32_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#else
bool CryptSetKeyParam(int64_t hKey, uint32_t dwParam, uint8_t * pbData, uint32_t dwFlags)
#endif
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptSetKeyParam(hKey, dwParam, pbData, dwFlags, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CryptUIDlgViewCertificate(PCCRYPTUI_VIEWCERTIFICATE_STRUCT pCertViewInfo, int32_t * pfPropertiesChanged)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptUIDlgViewCertificate(pCertViewInfo, pfPropertiesChanged, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE PCCERT_CONTEXT CryptUIDlgSelectCertificate(PCCRYPTUI_SELECTCERTIFICATE_STRUCT pcsc)
{
	PCCERT_CONTEXT OutResult;
	SBCheckError(SBWinCrypt_CryptUIDlgSelectCertificate(pcsc, &OutResult));
	return OutResult;
}

bool CryptUIWizImport(uint32_t dwFlags, uint32_t hwndParent, sb_char16_t * pwszWizardTitle, void * pImportSrc, void * hDestCertStore)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_CryptUIWizImport(dwFlags, hwndParent, pwszWizardTitle, pImportSrc, hDestCertStore, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t NCryptCreatePersistedKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszAlgId, sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptCreatePersistedKey(hProvider, phKey, pszAlgId, pszKeyName, dwLegacyKeySpec, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptDecrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptDecrypt(hKey, pbInput, cbInput, pPaddingInfo, pbOutput, cbOutput, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptDeleteKey(uint32_t * hKey, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptDeleteKey(hKey, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptDeriveKey(uint32_t * hSharedSecret, sb_char16_t * pwszKDF, PNCryptBufferDesc pParameterList, uint8_t * pbDerivedKey, uint32_t cbDerivedKey, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptDeriveKey(hSharedSecret, pwszKDF, pParameterList, pbDerivedKey, cbDerivedKey, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptEncrypt(uint32_t * hKey, uint8_t * pbInput, uint32_t cbInput, void * pPaddingInfo, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptEncrypt(hKey, pbInput, cbInput, pPaddingInfo, pbOutput, cbOutput, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptEnumAlgorithms(uint32_t * hProvider, uint32_t dwAlgOperations, uint32_t * pdwAlgCount, PNCryptAlgorithmName (* ppAlgList), uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptEnumAlgorithms(hProvider, dwAlgOperations, pdwAlgCount, ppAlgList, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptEnumKeys(uint32_t * hProvider, sb_char16_t * pszScope, PNCryptKeyName (* ppKeyName), void * (* ppEnumState), uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptEnumKeys(hProvider, pszScope, ppKeyName, ppEnumState, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptEnumStorageProviders(uint32_t * pdwProviderCount, PNCryptProviderName (* ppProviderList), uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptEnumStorageProviders(pdwProviderCount, ppProviderList, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptExportKey(uint32_t * hKey, uint32_t * hExportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptExportKey(hKey, hExportKey, pszBlobType, pParameterList, pbOutput, cbOutput, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptFinalizeKey(uint32_t * hKey, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptFinalizeKey(hKey, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptFreeBuffer(void * pvInput)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptFreeBuffer(pvInput, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptFreeObject(uint32_t * hObject)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptFreeObject(hObject, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptGetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbOutput, uint32_t cbOutput, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptGetProperty(hObject, pszProperty, pbOutput, cbOutput, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptImportKey(uint32_t * hProvider, uint32_t * hImportKey, sb_char16_t * pszBlobType, PNCryptBufferDesc pParameterList, uint32_t * (* phKey), uint8_t * pbData, uint32_t cbData, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptImportKey(hProvider, hImportKey, pszBlobType, pParameterList, phKey, pbData, cbData, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptIsAlgSupported(uint32_t * hProvider, sb_char16_t * pszAlgId, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptIsAlgSupported(hProvider, pszAlgId, dwFlags, &OutResult));
	return OutResult;
}

bool NCryptIsKeyHandle(uint32_t * hKey)
{
	int32_t OutResultRaw = 0;
	SBCheckError(SBWinCrypt_NCryptIsKeyHandle(hKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t NCryptKeyDerivation(uint32_t * hProvider, uint32_t * hKey, sb_char16_t * pswzDerivedKeyAlg, uint32_t cbDerivedKeyLength, PNCryptBufferDesc pParameterList, uint32_t * (* phDerivedKey), uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptKeyDerivation(hProvider, hKey, pswzDerivedKeyAlg, cbDerivedKeyLength, pParameterList, phDerivedKey, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptNotifyChangeKey(uint32_t * hProvider, uint32_t * phEvent, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptNotifyChangeKey(hProvider, phEvent, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptOpenKey(uint32_t * hProvider, uint32_t * (* phKey), sb_char16_t * pszKeyName, uint32_t dwLegacyKeySpec, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptOpenKey(hProvider, phKey, pszKeyName, dwLegacyKeySpec, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptOpenStorageProvider(uint32_t * (* phProvider), sb_char16_t * pszProviderName, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptOpenStorageProvider(phProvider, pszProviderName, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptSecretAgreement(uint32_t * hPrivKey, uint32_t * hPubKey, uint32_t * (* phSecret), uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptSecretAgreement(hPrivKey, hPubKey, phSecret, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptSetProperty(uint32_t * hObject, sb_char16_t * pszProperty, uint8_t * pbInput, uint32_t cbInput, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptSetProperty(hObject, pszProperty, pbInput, cbInput, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptSignHash(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t * pcbResult, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptSignHash(hKey, pPaddingInfo, pbHashValue, cbHashValue, pbSignature, cbSignature, pcbResult, dwFlags, &OutResult));
	return OutResult;
}

#ifndef CPU64
SB_INLINE uint32_t NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), uint32_t hLegacyProv, uint32_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags)
#else
SB_INLINE uint32_t NCryptTranslateHandle(uint32_t * (* phProvider), uint32_t * (* phKey), int64_t hLegacyProv, int64_t hLegacyKey, uint32_t dwLegacyKeySpec, uint32_t dwFlags)
#endif
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptTranslateHandle(phProvider, phKey, hLegacyProv, hLegacyKey, dwLegacyKeySpec, dwFlags, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t NCryptVerifySignature(uint32_t * hKey, void * pPaddingInfo, uint8_t * pbHashValue, uint32_t cbHashValue, uint8_t * pbSignature, uint32_t cbSignature, uint32_t dwFlags)
{
	uint32_t OutResult;
	SBCheckError(SBWinCrypt_NCryptVerifySignature(hKey, pPaddingInfo, pbHashValue, cbHashValue, pbSignature, cbSignature, dwFlags, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_WINCRYPT */

};	/* namespace SecureBlackbox */
#endif
