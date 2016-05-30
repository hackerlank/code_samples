#ifndef __INC_SBSSHKEYSTORAGE
#define __INC_SBSSHKEYSTORAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbencoding.h"
#include "sbrandom.h"
#include "sbsharedresource.h"
#include "sbpkcs8.h"
#include "sbasn1tree.h"
#include "sbcryptoprov.h"
#include "sbsymmetriccrypto.h"
#include "sbhashfunction.h"
#include "sbpublickeycrypto.h"
#include "sbconstants.h"
#include "sbx509.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ALGORITHM_RSA 	0
#define SB_ALGORITHM_DSS 	1
#define SB_ALGORITHM_ECDSA 	2
#define SB_ALGORITHM_NOT_SPECIFIED 	65535
#define SB_ERROR_SSH_KEYS_INVALID_PUBLIC_KEY 	3329
#define SB_ERROR_SSH_KEYS_INVALID_PRIVATE_KEY 	3330
#define SB_ERROR_SSH_KEYS_FILE_READ_ERROR 	3331
#define SB_ERROR_SSH_KEYS_FILE_WRITE_ERROR 	3332
#define SB_ERROR_SSH_KEYS_UNSUPPORTED_ALGORITHM 	3333
#define SB_ERROR_SSH_KEYS_INTERNAL_ERROR 	3334
#define SB_ERROR_SSH_KEYS_BUFFER_TOO_SMALL 	3335
#define SB_ERROR_SSH_KEYS_NO_PRIVATE_KEY 	3336
#define SB_ERROR_SSH_KEYS_INVALID_PASSPHRASE 	3337
#define SB_ERROR_SSH_KEYS_UNSUPPORTED_PEM_ALGORITHM 	3338
#define SB_ERROR_SSH_KEYS_UNSUPPORTED_CURVE 	3339

typedef TElClassHandle TElSSHKeyHandle;

typedef TElSSHKeyHandle ElSSHKeyHandle;

typedef TElClassHandle TElSSHCustomKeyStorageHandle;

typedef TElSSHCustomKeyStorageHandle ElSSHCustomKeyStorageHandle;

typedef TElClassHandle TElSSHMemoryKeyStorageHandle;

typedef TElSSHMemoryKeyStorageHandle ElSSHMemoryKeyStorageHandle;

typedef uint8_t TSBSSHKeyFormatRaw;

typedef enum
{
	kfOpenSSH = 0,
	kfIETF = 1,
	kfPuTTY = 2,
	kfX509 = 3,
	kfBinary = 4,
	kfSSH1 = 5,
	kfPGP = 6,
	kfPKCS8 = 7
} TSBSSHKeyFormat;

#ifdef SB_USE_CLASS_TELSSHKEY
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_IsKeyValid(TElSSHKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Copy(TElSSHKeyHandle _Handle, TElSSHKeyHandle * Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Clear(TElSSHKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Clone(TElSSHKeyHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_CreateObjectInstance(TElSSHKeyHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Generate(TElSSHKeyHandle _Handle, int32_t Algorithm, int32_t Bits, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_GenerateEC(TElSSHKeyHandle _Handle, int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_LoadPublicKey(TElSSHKeyHandle _Handle, const char * pcPublicKeyFile, int32_t szPublicKeyFile, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_LoadPublicKey_1(TElSSHKeyHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_LoadPrivateKey(TElSSHKeyHandle _Handle, const char * pcPrivateKeyFile, int32_t szPrivateKeyFile, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_LoadPrivateKey_1(TElSSHKeyHandle _Handle, void * Buffer, int32_t Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_SavePublicKey(TElSSHKeyHandle _Handle, void * Buffer, int32_t * Size, TSBEOLMarkerRaw EOLMarker, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_SavePublicKey_1(TElSSHKeyHandle _Handle, const char * pcPublicKeyFile, int32_t szPublicKeyFile, TSBEOLMarkerRaw EOLMarker, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_SavePrivateKey(TElSSHKeyHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_SavePrivateKey_1(TElSSHKeyHandle _Handle, const char * pcPrivateKeyFile, int32_t szPrivateKeyFile, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Import(TElSSHKeyHandle _Handle, TElX509CertificateHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_LoadPublicKeyFromBlob(TElSSHKeyHandle _Handle, const char * pcAlgName, int32_t szAlgName, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_SavePublicKeyToBlob(TElSSHKeyHandle _Handle, char * pcAlgName, int32_t * szAlgName, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_RSAPublicExponent(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_RSAPublicExponent(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_RSAPublicModulus(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_RSAPublicModulus(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_RSAPrivateExponent(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_RSAPrivateExponent(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_DSSP(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_DSSP(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_DSSQ(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_DSSQ(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_DSSG(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_DSSG(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_DSSY(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_DSSY(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_DSSX(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_DSSX(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_CurveID(TElSSHKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_CurveID(TElSSHKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_ECCD(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_ECCD(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_ECCQX(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_ECCQX(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_ECCQY(TElSSHKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_ECCQY(TElSSHKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_FingerprintMD5(TElSSHKeyHandle _Handle, TMessageDigest128 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_FingerprintMD5String(TElSSHKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_FingerprintSHA1(TElSSHKeyHandle _Handle, TMessageDigest160 * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_FingerprintSHA1String(TElSSHKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Algorithm(TElSSHKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_Algorithm(TElSSHKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Bits(TElSSHKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Comment(TElSSHKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_Comment(TElSSHKeyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Subject(TElSSHKeyHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_Subject(TElSSHKeyHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_KeyFormat(TElSSHKeyHandle _Handle, TSBSSHKeyFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_KeyFormat(TElSSHKeyHandle _Handle, TSBSSHKeyFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_KeyProtectionAlgorithm(TElSSHKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_KeyProtectionAlgorithm(TElSSHKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_IsPrivate(TElSSHKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_IsPublic(TElSSHKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_IsExtractable(TElSSHKeyHandle _Handle, int8_t * OutResult);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Headers(TElSSHKeyHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Headers(TElSSHKeyHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_Certificate(TElSSHKeyHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_KeyMaterial(TElSSHKeyHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_UsePlatformKeyGeneration(TElSSHKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_UsePlatformKeyGeneration(TElSSHKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_get_CryptoProviderManager(TElSSHKeyHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_set_CryptoProviderManager(TElSSHKeyHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHKey_Create(TElSSHKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_Add(TElSSHCustomKeyStorageHandle _Handle, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_Remove(TElSSHCustomKeyStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_Clear(TElSSHCustomKeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_IndexOf(TElSSHCustomKeyStorageHandle _Handle, TElSSHKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_LoadPublic(TElSSHCustomKeyStorageHandle _Handle, TStreamHandle F, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_LoadPublic_1(TElSSHCustomKeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_SavePublic(TElSSHCustomKeyStorageHandle _Handle, TStreamHandle F, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_SavePublic_1(TElSSHCustomKeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_get_Keys(TElSSHCustomKeyStorageHandle _Handle, int32_t Index, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_get_Count(TElSSHCustomKeyStorageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_get_CryptoProviderManager(TElSSHCustomKeyStorageHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_set_CryptoProviderManager(TElSSHCustomKeyStorageHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHCustomKeyStorage_Create(TComponentHandle AOwner, TElSSHCustomKeyStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_Add(TElSSHMemoryKeyStorageHandle _Handle, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_Remove(TElSSHMemoryKeyStorageHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_Clear(TElSSHMemoryKeyStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_LoadPublic(TElSSHMemoryKeyStorageHandle _Handle, TStreamHandle F, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_LoadPublic_1(TElSSHMemoryKeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_SavePublic(TElSSHMemoryKeyStorageHandle _Handle, TStreamHandle F, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_SavePublic_1(TElSSHMemoryKeyStorageHandle _Handle, const char * pcFilename, int32_t szFilename, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_IndexOf(TElSSHMemoryKeyStorageHandle _Handle, TElSSHKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHMemoryKeyStorage_Create(TComponentHandle AOwner, TElSSHMemoryKeyStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHKey;
typedef TElSSHKey ElSSHKey;
class TElSSHCustomKeyStorage;
typedef TElSSHCustomKeyStorage ElSSHCustomKeyStorage;
class TElSSHMemoryKeyStorage;
typedef TElSSHMemoryKeyStorage ElSSHMemoryKeyStorage;

#ifdef SB_USE_CLASS_TELSSHKEY
class TElSSHKey: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHKey)
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Headers;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		bool IsKeyValid();

		virtual void Copy(TElSSHKey &Dest);

		virtual void Clear();

		virtual TElSSHKeyHandle Clone();

		virtual TElSSHKeyHandle CreateObjectInstance();

		int32_t Generate(int32_t Algorithm, int32_t Bits);

		int32_t GenerateEC(int32_t Curve);

		int32_t LoadPublicKey(const std::string &PublicKeyFile);

		int32_t LoadPublicKey(void * Buffer, int32_t Size);

		int32_t LoadPrivateKey(const std::string &PrivateKeyFile, const std::string &Passphrase);

		int32_t LoadPrivateKey(void * Buffer, int32_t Size, const std::string &Passphrase);

		int32_t SavePublicKey(void * Buffer, int32_t &Size, TSBEOLMarker EOLMarker);

		int32_t SavePublicKey(const std::string &PublicKeyFile, TSBEOLMarker EOLMarker);

		int32_t SavePrivateKey(void * Buffer, int32_t &Size, const std::string &Passphrase);

		int32_t SavePrivateKey(const std::string &PrivateKeyFile, const std::string &Passphrase);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Import(TElX509Certificate &Certificate);

		void Import(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		int32_t LoadPublicKeyFromBlob(const std::string &AlgName, void * Buffer, int32_t Size);

		int32_t SavePublicKeyToBlob(std::string &AlgName, void * Buffer, int32_t &Size);

		virtual void get_RSAPublicExponent(std::vector<uint8_t> &OutResult);

		virtual void set_RSAPublicExponent(const std::vector<uint8_t> &Value);

		virtual void get_RSAPublicModulus(std::vector<uint8_t> &OutResult);

		virtual void set_RSAPublicModulus(const std::vector<uint8_t> &Value);

		virtual void get_RSAPrivateExponent(std::vector<uint8_t> &OutResult);

		virtual void set_RSAPrivateExponent(const std::vector<uint8_t> &Value);

		virtual void get_DSSP(std::vector<uint8_t> &OutResult);

		virtual void set_DSSP(const std::vector<uint8_t> &Value);

		virtual void get_DSSQ(std::vector<uint8_t> &OutResult);

		virtual void set_DSSQ(const std::vector<uint8_t> &Value);

		virtual void get_DSSG(std::vector<uint8_t> &OutResult);

		virtual void set_DSSG(const std::vector<uint8_t> &Value);

		virtual void get_DSSY(std::vector<uint8_t> &OutResult);

		virtual void set_DSSY(const std::vector<uint8_t> &Value);

		virtual void get_DSSX(std::vector<uint8_t> &OutResult);

		virtual void set_DSSX(const std::vector<uint8_t> &Value);

		virtual int32_t get_CurveID();

		virtual void set_CurveID(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CurveID, set_CurveID, TElSSHKey, CurveID);

		virtual void get_ECCD(std::vector<uint8_t> &OutResult);

		virtual void set_ECCD(const std::vector<uint8_t> &Value);

		virtual void get_ECCQX(std::vector<uint8_t> &OutResult);

		virtual void set_ECCQX(const std::vector<uint8_t> &Value);

		virtual void get_ECCQY(std::vector<uint8_t> &OutResult);

		virtual void set_ECCQY(const std::vector<uint8_t> &Value);

		virtual void get_FingerprintMD5(TMessageDigest128 &OutResult);

		virtual void get_FingerprintMD5String(std::string &OutResult);

		virtual void get_FingerprintSHA1(TMessageDigest160 &OutResult);

		virtual void get_FingerprintSHA1String(std::string &OutResult);

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElSSHKey, Algorithm);

		virtual int32_t get_Bits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Bits, TElSSHKey, Bits);

		virtual void get_Comment(std::string &OutResult);

		virtual void set_Comment(const std::string &Value);

		virtual void get_Subject(std::string &OutResult);

		virtual void set_Subject(const std::string &Value);

		virtual TSBSSHKeyFormat get_KeyFormat();

		virtual void set_KeyFormat(TSBSSHKeyFormat Value);

		SB_DECLARE_PROPERTY(TSBSSHKeyFormat, get_KeyFormat, set_KeyFormat, TElSSHKey, KeyFormat);

		virtual int32_t get_KeyProtectionAlgorithm();

		virtual void set_KeyProtectionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyProtectionAlgorithm, set_KeyProtectionAlgorithm, TElSSHKey, KeyProtectionAlgorithm);

		virtual bool get_IsPrivate();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPrivate, TElSSHKey, IsPrivate);

		virtual bool get_IsPublic();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPublic, TElSSHKey, IsPublic);

		virtual bool get_IsExtractable();

		SB_DECLARE_PROPERTY_GET(bool, get_IsExtractable, TElSSHKey, IsExtractable);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Headers, TElSSHKey, Headers);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Headers();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Headers, TElSSHKey, Headers);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificate();

		SB_DECLARE_PROPERTY_GET(TElX509Certificate*, get_Certificate, TElSSHKey, Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_KeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElPublicKeyMaterial*, get_KeyMaterial, TElSSHKey, KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		virtual bool get_UsePlatformKeyGeneration();

		virtual void set_UsePlatformKeyGeneration(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UsePlatformKeyGeneration, set_UsePlatformKeyGeneration, TElSSHKey, UsePlatformKeyGeneration);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSSHKey, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElSSHKey(TElSSHKeyHandle handle, TElOwnHandle ownHandle);

		TElSSHKey();

		virtual ~TElSSHKey();

};
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
class TElSSHCustomKeyStorage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHCustomKeyStorage)
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_Keys;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void Add(TElSSHKey &Key);

		virtual void Add(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual int32_t IndexOf(TElSSHKey &Key);

		virtual int32_t IndexOf(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t LoadPublic(TStream &F, int32_t Count);

		virtual int32_t LoadPublic(TStream *F, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t LoadPublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t SavePublic(TStream &F);

		virtual int32_t SavePublic(TStream *F);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t SavePublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_Keys(int32_t Index);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSSHCustomKeyStorage, Count);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSSHCustomKeyStorage, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElSSHCustomKeyStorage(TElSSHCustomKeyStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHCustomKeyStorage(TComponent &AOwner);

		explicit TElSSHCustomKeyStorage(TComponent *AOwner);

		virtual ~TElSSHCustomKeyStorage();

};
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE
class TElSSHMemoryKeyStorage: public TElSSHCustomKeyStorage
{
	private:
		SB_DISABLE_COPY(TElSSHMemoryKeyStorage)
	public:
#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void Add(TElSSHKey &Key);

		virtual void Add(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t LoadPublic(TStream &F, int32_t Count);

		virtual int32_t LoadPublic(TStream *F, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t LoadPublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t SavePublic(TStream &F);

		virtual int32_t SavePublic(TStream *F);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t SavePublic(const std::string &Filename);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual int32_t IndexOf(TElSSHKey &Key);

		virtual int32_t IndexOf(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		TElSSHMemoryKeyStorage(TElSSHMemoryKeyStorageHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHMemoryKeyStorage(TComponent &AOwner);

		explicit TElSSHMemoryKeyStorage(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHMEMORYKEYSTORAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHKEYSTORAGE */
