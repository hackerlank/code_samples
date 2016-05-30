#ifndef __INC_SBPKCS12
#define __INC_SBPKCS12

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbpkcs7.h"
#include "sbcrl.h"
#include "sbpkcs7utils.h"
#include "sbasn1tree.h"
#include "sbasn1.h"
#include "sbx509.h"
#include "sbrandom.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbmd.h"
#include "sbsha.h"
#include "sbmath.h"
#include "sbcryptoprov.h"
#include "sbhashfunction.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbcrlstorage.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_PKCS12 	7936
#define SB_PKCS12_ERROR_INVALID_ASN_DATA 	7937
#define SB_PKCS12_ERROR_NO_DATA 	7938
#define SB_PKCS12_ERROR_INVALID_DATA 	7939
#define SB_PKCS12_ERROR_INVALID_VERSION 	7940
#define SB_PKCS12_ERROR_INVALID_CONTENT 	7941
#define SB_PKCS12_ERROR_INVALID_AUTHENTICATED_SAFE_DATA 	7942
#define SB_PKCS12_ERROR_INVALID_MAC_DATA 	7943
#define SB_PKCS12_ERROR_INVALID_SAFE_CONTENTS 	7944
#define SB_PKCS12_ERROR_INVALID_SAFE_BAG 	7945
#define SB_PKCS12_ERROR_INVALID_SHROUDED_KEY_BAG 	7946
#define SB_PKCS12_ERROR_UNKNOWN_PBE_ALGORITHM 	7947
#define SB_PKCS12_ERROR_INTERNAL_ERROR 	7948
#define SB_PKCS12_ERROR_INVALID_PBE_ALGORITHM_PARAMS 	7949
#define SB_PKCS12_ERROR_INVALID_CERT_BAG 	7950
#define SB_PKCS12_ERROR_UNSUPPORTED_CERTIFICATE_TYPE 	7951
#define SB_PKCS12_ERROR_INVALID_PRIVATE_KEY 	7952
#define SB_PKCS12_ERROR_INVALID_MAC 	7953
#define SB_PKCS12_ERROR_NO_CERTIFICATES 	7954
#define SB_PKCS12_ERROR_INVALID_PASSWORD 	7955
#define SB_PKCS12_ERROR_BUFFER_TOO_SMALL 	7956
#define SB_PKCS12_ERROR_INVALID_CRL_BAG 	7957
#define SB_PKCS12_ERROR_UNSUPPORTED_CRL_TYPE 	7958

typedef TElClassHandle TElPKCS12MessageHandle;

typedef TElPKCS12MessageHandle ElPKCS12MessageHandle;

#ifdef SB_USE_CLASS_TELPKCS12MESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_LoadFromBuffer(TElPKCS12MessageHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_SaveToBuffer(TElPKCS12MessageHandle _Handle, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_Iterations(TElPKCS12MessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_Iterations(TElPKCS12MessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_Password(TElPKCS12MessageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_Password(TElPKCS12MessageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_Certificates(TElPKCS12MessageHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_CRLs(TElPKCS12MessageHandle _Handle, TElMemoryCRLStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_KeyEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_KeyEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_CertEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_CertEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_CRLEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_CRLEncryptionAlgorithm(TElPKCS12MessageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_UseEmptyPasswordWorkaround(TElPKCS12MessageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_UseEmptyPasswordWorkaround(TElPKCS12MessageHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_get_CryptoProviderManager(TElPKCS12MessageHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_set_CryptoProviderManager(TElPKCS12MessageHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS12Message_Create(TElPKCS12MessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS12MESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS12Message;
typedef TElPKCS12Message ElPKCS12Message;

#ifdef SB_USE_CLASS_TELPKCS12MESSAGE
class TElPKCS12Message: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS12Message)
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		TElMemoryCRLStorage* _Inst_CRLs;
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		int32_t LoadFromBuffer(void * Buffer, int32_t Size);

		int32_t SaveToBuffer(void * Buffer, int32_t &Size);

		virtual int32_t get_Iterations();

		virtual void set_Iterations(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Iterations, set_Iterations, TElPKCS12Message, Iterations);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElPKCS12Message, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYCRLSTORAGE
		virtual TElMemoryCRLStorage* get_CRLs();

		SB_DECLARE_PROPERTY_GET(TElMemoryCRLStorage*, get_CRLs, TElPKCS12Message, CRLs);
#endif /* SB_USE_CLASS_TELMEMORYCRLSTORAGE */

		virtual int32_t get_KeyEncryptionAlgorithm();

		virtual void set_KeyEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyEncryptionAlgorithm, set_KeyEncryptionAlgorithm, TElPKCS12Message, KeyEncryptionAlgorithm);

		virtual int32_t get_CertEncryptionAlgorithm();

		virtual void set_CertEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CertEncryptionAlgorithm, set_CertEncryptionAlgorithm, TElPKCS12Message, CertEncryptionAlgorithm);

		virtual int32_t get_CRLEncryptionAlgorithm();

		virtual void set_CRLEncryptionAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CRLEncryptionAlgorithm, set_CRLEncryptionAlgorithm, TElPKCS12Message, CRLEncryptionAlgorithm);

		virtual bool get_UseEmptyPasswordWorkaround();

		virtual void set_UseEmptyPasswordWorkaround(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseEmptyPasswordWorkaround, set_UseEmptyPasswordWorkaround, TElPKCS12Message, UseEmptyPasswordWorkaround);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElPKCS12Message, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElPKCS12Message(TElPKCS12MessageHandle handle, TElOwnHandle ownHandle);

		TElPKCS12Message();

		virtual ~TElPKCS12Message();

};
#endif /* SB_USE_CLASS_TELPKCS12MESSAGE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS12

int32_t BufToInt(void * Buffer, int32_t Size);

void IntToBuf(int32_t Number, std::vector<uint8_t> &OutResult);

void RaisePKCS12Error(int32_t ErrorCode);

#endif /* SB_USE_GLOBAL_PROCS_PKCS12 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS12
SB_IMPORT uint32_t SB_APIENTRY SBPKCS12_BufToInt(void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS12_IntToBuf(int32_t Number, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPKCS12_RaisePKCS12Error(int32_t ErrorCode);
#endif /* SB_USE_GLOBAL_PROCS_PKCS12 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS12 */

