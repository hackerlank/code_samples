#ifndef __INC_SBPKCS5
#define __INC_SBPKCS5

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbconstants.h"
#include "sbhashfunction.h"
#include "sbsymmetriccrypto.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_PKCS5 	7168
#define SB_PKCS5_ERROR_UNSUPPORTED_ALGORITHM 	7169

typedef TElClassHandle TElPKCS5PBEHandle;

typedef uint8_t TSBPKCS5VersionRaw;

typedef enum
{
	sbP5v1 = 0,
	sbP5v2 = 1
} TSBPKCS5Version;

#ifdef SB_USE_CLASS_TELPKCS5PBE
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_Decrypt(TElPKCS5PBEHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_Encrypt(TElPKCS5PBEHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, const char * pcPassword, int32_t szPassword);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_DeriveKey(TElPKCS5PBEHandle _Handle, const char * pcPassword, int32_t szPassword, int32_t Bits, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_IsPRFSupported(TElPKCS5PBEHandle _Handle, int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_IsAlgorithmSupported(int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_IsAlgorithmSupported_1(TElPKCS5PBEHandle _Handle, int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_IsAlgorithmSupported_2(const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_IsAlgorithmSupported_3(TElPKCS5PBEHandle _Handle, const uint8_t pOID[], int32_t szOID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_GetAlgorithmByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_GetAlgorithmByOID_1(TElPKCS5PBEHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_Algorithm(TElPKCS5PBEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_Version(TElPKCS5PBEHandle _Handle, TSBPKCS5VersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_EncryptionAlgorithmOID(TElPKCS5PBEHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_EncryptionAlgorithmParams(TElPKCS5PBEHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_Salt(TElPKCS5PBEHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_set_Salt(TElPKCS5PBEHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_IterationCount(TElPKCS5PBEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_set_IterationCount(TElPKCS5PBEHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_get_PseudoRandomFunction(TElPKCS5PBEHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_set_PseudoRandomFunction(TElPKCS5PBEHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_Create(const uint8_t pOID[], int32_t szOID, const uint8_t pParams[], int32_t szParams, TElPKCS5PBEHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS5PBE_Create_1(int32_t StreamAlg, int32_t HashAlg, int8_t UseNewVersion, TElPKCS5PBEHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS5PBE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS5PBE;

#ifdef SB_USE_CLASS_TELPKCS5PBE
class TElPKCS5PBE: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS5PBE)
	public:
		void Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Password);

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Password);

		void DeriveKey(const std::string &Password, int32_t Bits, std::vector<uint8_t> &OutResult);

		bool IsPRFSupported(int32_t Alg);

		static bool IsAlgorithmSupported(int32_t Alg);

		bool IsAlgorithmSupported_Inst(int32_t Alg);

		static bool IsAlgorithmSupported(const std::vector<uint8_t> &OID);

		bool IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID);

		static int32_t GetAlgorithmByOID(const std::vector<uint8_t> &OID);

		int32_t GetAlgorithmByOID_Inst(const std::vector<uint8_t> &OID);

		virtual int32_t get_Algorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Algorithm, TElPKCS5PBE, Algorithm);

		virtual TSBPKCS5Version get_Version();

		SB_DECLARE_PROPERTY_GET(TSBPKCS5Version, get_Version, TElPKCS5PBE, Version);

		virtual void get_EncryptionAlgorithmOID(std::vector<uint8_t> &OutResult);

		virtual void get_EncryptionAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void set_Salt(const std::vector<uint8_t> &Value);

		virtual int32_t get_IterationCount();

		virtual void set_IterationCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IterationCount, set_IterationCount, TElPKCS5PBE, IterationCount);

		virtual int32_t get_PseudoRandomFunction();

		virtual void set_PseudoRandomFunction(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PseudoRandomFunction, set_PseudoRandomFunction, TElPKCS5PBE, PseudoRandomFunction);

		TElPKCS5PBE(TElPKCS5PBEHandle handle, TElOwnHandle ownHandle);

		TElPKCS5PBE(const std::vector<uint8_t> &OID, const std::vector<uint8_t> &Params);

		TElPKCS5PBE(int32_t StreamAlg, int32_t HashAlg, bool UseNewVersion);

};
#endif /* SB_USE_CLASS_TELPKCS5PBE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS5

void DeriveRouteOneOTP(const std::string &Input, const std::string &Password, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_PKCS5 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS5
SB_IMPORT uint32_t SB_APIENTRY SBPKCS5_DeriveRouteOneOTP(const char * pcInput, int32_t szInput, const char * pcPassword, int32_t szPassword, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_PKCS5 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS5 */

