#ifndef __INC_SBRSA
#define __INC_SBRSA

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsharedresource.h"
#include "sbmath.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElRSAAntiTimingParamsHandle;

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElRSAAntiTimingParams_Init(TElRSAAntiTimingParamsHandle _Handle, const uint8_t pRSAM[], int32_t szRSAM, const uint8_t pRSAE[], int32_t szRSAE);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAntiTimingParams_Reset(TElRSAAntiTimingParamsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAntiTimingParams_GetNextBlindingPair(TElRSAAntiTimingParamsHandle _Handle, PLInt VI, PLInt VF);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAntiTimingParams_get_Initialized(TElRSAAntiTimingParamsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAntiTimingParams_Create(TElRSAAntiTimingParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElRSAAntiTimingParams;

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
class TElRSAAntiTimingParams: public TObject
{
	private:
		SB_DISABLE_COPY(TElRSAAntiTimingParams)
	public:
		void Init(const std::vector<uint8_t> &RSAM, const std::vector<uint8_t> &RSAE);

		void Reset();

		void GetNextBlindingPair(PLInt VI, PLInt VF);

		virtual bool get_Initialized();

		SB_DECLARE_PROPERTY_GET(bool, get_Initialized, TElRSAAntiTimingParams, Initialized);

		TElRSAAntiTimingParams(TElRSAAntiTimingParamsHandle handle, TElOwnHandle ownHandle);

		TElRSAAntiTimingParams();

};
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_GLOBAL_PROCS_RSA

bool ValidateSignature(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize);

bool ValidateSignature(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t SignatureSize);

void ExtractSignedData(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize, std::vector<uint8_t> &OutResult);

bool Generate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize);

bool Generate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool Generate(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U);

bool ExternalGenerate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize);

bool ExternalGenerate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool ExternalGenerate(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U);

bool SBRSA_ExternalGenerationSupported();

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Sign(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams);
bool Sign(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Sign(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams);
bool Sign(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool Encrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * OutBuffer, int32_t &OutSize);

bool Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, PLInt PublicModulus, PLInt PublicExponent);

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Decrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool Decrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Decrypt(void * InBuffer, int32_t InSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool Decrypt(void * InBuffer, int32_t InSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool DecodePrivateKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize);

bool DecodePrivateKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * E1, int32_t &E1Size, void * E2, int32_t &E2Size, void * U, int32_t &USize);

bool EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Prime1, int32_t Prime1Size, void * Prime2, int32_t Prime2Size, void * Exponent1, int32_t Exponent1Size, void * Exponent2, int32_t Exponent2Size, void * Coef, int32_t CoefSize, void * OutBuffer, int32_t &OutSize);

bool EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize);

bool IsValidKey(void * Blob, int32_t BlobSize);

bool EncryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * Blob, int32_t BlobSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * Blob, int32_t BlobSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool DecodePublicKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, std::vector<uint8_t> &AlgID, bool InnerValuesOnly);

bool EncodePublicKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const std::vector<uint8_t> &AlgID, void * OutBuffer, int32_t &OutSize, bool InnerValuesOnly);

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * KeyBlob, int32_t KeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams);
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * KeyBlob, int32_t KeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams);
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool VerifyPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize);

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool PerformExponentiation(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool PerformExponentiation(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool PerformExponentiation(void * Blob, int32_t BlobSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams);
bool PerformExponentiation(void * Blob, int32_t BlobSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams);
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#endif /* SB_USE_GLOBAL_PROCS_RSA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RSA
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ValidateSignature(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ValidateSignature_1(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t SignatureSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ExtractSignedData(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Generate(int32_t Bits, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Generate_1(int32_t Bits, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, void * PrivateKeyBlob, int32_t * PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Generate_2(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ExternalGenerate(int32_t Bits, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ExternalGenerate_1(int32_t Bits, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, void * PrivateKeyBlob, int32_t * PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ExternalGenerate_2(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_ExternalGenerationSupported(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Sign(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t * SignatureSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Sign_1(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t * SignatureSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Encrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Encrypt_1(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, PLInt PublicModulus, PLInt PublicExponent, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Decrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_Decrypt_1(void * InBuffer, int32_t InSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_DecodePrivateKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_DecodePrivateKey_1(void * Buffer, int32_t Size, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, void * PrivateExponent, int32_t * PrivateExponentSize, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * E1, int32_t * E1Size, void * E2, int32_t * E2Size, void * U, int32_t * USize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Prime1, int32_t Prime1Size, void * Prime2, int32_t Prime2Size, void * Exponent1, int32_t Exponent1Size, void * Exponent2, int32_t Exponent2Size, void * Coef, int32_t CoefSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_EncodePrivateKey_1(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_IsValidKey(void * Blob, int32_t BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_EncryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_DecryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_DecryptOAEP_1(void * InBuffer, int32_t InSize, void * Blob, int32_t BlobSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_DecodePublicKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, uint8_t pAlgID[], int32_t * szAlgID, int8_t InnerValuesOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_EncodePublicKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const uint8_t pAlgID[], int32_t szAlgID, void * OutBuffer, int32_t * OutSize, int8_t InnerValuesOnly, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * KeyBlob, int32_t KeyBlobSize, void * Signature, int32_t * SignatureSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_SignPSS_1(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t * SignatureSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_VerifyPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_PerformExponentiation(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRSA_PerformExponentiation_1(void * Blob, int32_t BlobSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, TElRSAAntiTimingParamsHandle AntiTimingParams, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_RSA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRSA */

