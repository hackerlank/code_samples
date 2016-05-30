#include "sbrsa.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS

SB_INLINE void TElRSAAntiTimingParams::Init(const std::vector<uint8_t> &RSAM, const std::vector<uint8_t> &RSAE)
{
	SBCheckError(TElRSAAntiTimingParams_Init(_Handle, SB_STD_VECTOR_FRONT_ADR(RSAM), (int32_t)RSAM.size(), SB_STD_VECTOR_FRONT_ADR(RSAE), (int32_t)RSAE.size()));
}

SB_INLINE void TElRSAAntiTimingParams::Reset()
{
	SBCheckError(TElRSAAntiTimingParams_Reset(_Handle));
}

SB_INLINE void TElRSAAntiTimingParams::GetNextBlindingPair(PLInt VI, PLInt VF)
{
	SBCheckError(TElRSAAntiTimingParams_GetNextBlindingPair(_Handle, VI, VF));
}

bool TElRSAAntiTimingParams::get_Initialized()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElRSAAntiTimingParams_get_Initialized(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElRSAAntiTimingParams::TElRSAAntiTimingParams(TElRSAAntiTimingParamsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElRSAAntiTimingParams::TElRSAAntiTimingParams() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElRSAAntiTimingParams_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_GLOBAL_PROCS_RSA

bool ValidateSignature(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ValidateSignature(Hash, HashSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, Signature, SignatureSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ValidateSignature(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t SignatureSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ValidateSignature_1(Hash, HashSize, PrivateKeyBlob, PrivateKeyBlobSize, Signature, SignatureSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

void ExtractSignedData(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBRSA_ExtractSignedData(PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, Signature, SignatureSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1061495975, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool Generate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Generate(Bits, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Generate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Generate_1(Bits, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, PrivateKeyBlob, &PrivateKeyBlobSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Generate(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Generate_2(Bits, PublicModulus, PublicExponent, PrivateExponent, P, Q, U, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ExternalGenerate(Bits, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ExternalGenerate_1(Bits, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, PrivateKeyBlob, &PrivateKeyBlobSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, PLInt PublicModulus, PLInt PublicExponent, PLInt PrivateExponent, PLInt P, PLInt Q, PLInt U)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ExternalGenerate_2(Bits, PublicModulus, PublicExponent, PrivateExponent, P, Q, U, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBRSA_ExternalGenerationSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_ExternalGenerationSupported(&OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Sign(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Sign(Hash, HashSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, Signature, &SignatureSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool Sign(void * Hash, int32_t HashSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Sign(Hash, HashSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, Signature, &SignatureSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Sign(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Sign_1(Hash, HashSize, PrivateKeyBlob, PrivateKeyBlobSize, Signature, &SignatureSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool Sign(void * Hash, int32_t HashSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Sign_1(Hash, HashSize, PrivateKeyBlob, PrivateKeyBlobSize, Signature, &SignatureSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool Encrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Encrypt(InBuffer, InSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, PLInt PublicModulus, PLInt PublicExponent)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Encrypt_1(InBuffer, InSize, OutBuffer, &OutSize, PublicModulus, PublicExponent, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Decrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Decrypt(InBuffer, InSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool Decrypt(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Decrypt(InBuffer, InSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool Decrypt(void * InBuffer, int32_t InSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Decrypt_1(InBuffer, InSize, PrivateKeyBlob, PrivateKeyBlobSize, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool Decrypt(void * InBuffer, int32_t InSize, void * PrivateKeyBlob, int32_t PrivateKeyBlobSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_Decrypt_1(InBuffer, InSize, PrivateKeyBlob, PrivateKeyBlobSize, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool DecodePrivateKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecodePrivateKey(Buffer, Size, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodePrivateKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, void * PrivateExponent, int32_t &PrivateExponentSize, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * E1, int32_t &E1Size, void * E2, int32_t &E2Size, void * U, int32_t &USize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecodePrivateKey_1(Buffer, Size, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, PrivateExponent, &PrivateExponentSize, P, &PSize, Q, &QSize, E1, &E1Size, E2, &E2Size, U, &USize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Prime1, int32_t Prime1Size, void * Prime2, int32_t Prime2Size, void * Exponent1, int32_t Exponent1Size, void * Exponent2, int32_t Exponent2Size, void * Coef, int32_t CoefSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_EncodePrivateKey(PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, PrivateExponent, PrivateExponentSize, Prime1, Prime1Size, Prime2, Prime2Size, Exponent1, Exponent1Size, Exponent2, Exponent2Size, Coef, CoefSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodePrivateKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_EncodePrivateKey_1(PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, PrivateExponent, PrivateExponentSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsValidKey(void * Blob, int32_t BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_IsValidKey(Blob, BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_EncryptOAEP(InBuffer, InSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, Salt, SaltSize, HashAlg, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecryptOAEP(InBuffer, InSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, Salt, SaltSize, HashAlg, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * PublicModulus, int32_t PublicModulusSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecryptOAEP(InBuffer, InSize, PublicModulus, PublicModulusSize, PrivateExponent, PrivateExponentSize, Salt, SaltSize, HashAlg, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * Blob, int32_t BlobSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecryptOAEP_1(InBuffer, InSize, Blob, BlobSize, Salt, SaltSize, HashAlg, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool DecryptOAEP(void * InBuffer, int32_t InSize, void * Blob, int32_t BlobSize, void * Salt, int32_t SaltSize, int32_t HashAlg, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_DecryptOAEP_1(InBuffer, InSize, Blob, BlobSize, Salt, SaltSize, HashAlg, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool DecodePublicKey(void * Buffer, int32_t Size, void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize, std::vector<uint8_t> &AlgID, bool InnerValuesOnly)
{
	int32_t szAlgID = (int32_t)AlgID.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBRSA_DecodePublicKey(Buffer, Size, PublicModulus, &PublicModulusSize, PublicExponent, &PublicExponentSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(AlgID), &szAlgID, (int8_t)InnerValuesOnly, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AlgID.resize(szAlgID);
		SBCheckError(SBGetLastReturnBuffer(2077103448, 6, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(AlgID), &szAlgID));
	}
	else
		SBCheckError(_err);

	AlgID.resize(szAlgID);
	return (OutResultRaw != 0);
}

bool EncodePublicKey(void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, const std::vector<uint8_t> &AlgID, void * OutBuffer, int32_t &OutSize, bool InnerValuesOnly)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_EncodePublicKey(PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, SB_STD_VECTOR_FRONT_ADR(AlgID), (int32_t)AlgID.size(), OutBuffer, &OutSize, (int8_t)InnerValuesOnly, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * KeyBlob, int32_t KeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_SignPSS(HashValue, HashValueSize, HashAlgorithm, SaltSize, KeyBlob, KeyBlobSize, Signature, &SignatureSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * KeyBlob, int32_t KeyBlobSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_SignPSS(HashValue, HashValueSize, HashAlgorithm, SaltSize, KeyBlob, KeyBlobSize, Signature, &SignatureSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_SignPSS_1(HashValue, HashValueSize, HashAlgorithm, SaltSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, PrivateExponent, PrivateExponentSize, Signature, &SignatureSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool SignPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * PrivateExponent, int32_t PrivateExponentSize, void * Signature, int32_t &SignatureSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_SignPSS_1(HashValue, HashValueSize, HashAlgorithm, SaltSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, PrivateExponent, PrivateExponentSize, Signature, &SignatureSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

bool VerifyPSS(void * HashValue, int32_t HashValueSize, int32_t HashAlgorithm, int32_t SaltSize, void * PublicModulus, int32_t PublicModulusSize, void * PublicExponent, int32_t PublicExponentSize, void * Signature, int32_t SignatureSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_VerifyPSS(HashValue, HashValueSize, HashAlgorithm, SaltSize, PublicModulus, PublicModulusSize, PublicExponent, PublicExponentSize, Signature, SignatureSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool PerformExponentiation(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_PerformExponentiation(Modulus, ModulusSize, Exponent, ExponentSize, InBuffer, InSize, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool PerformExponentiation(void * Modulus, int32_t ModulusSize, void * Exponent, int32_t ExponentSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_PerformExponentiation(Modulus, ModulusSize, Exponent, ExponentSize, InBuffer, InSize, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#ifdef SB_USE_CLASS_TELRSAANTITIMINGPARAMS
bool PerformExponentiation(void * Blob, int32_t BlobSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams &AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_PerformExponentiation_1(Blob, BlobSize, InBuffer, InSize, OutBuffer, &OutSize, AntiTimingParams.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool PerformExponentiation(void * Blob, int32_t BlobSize, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, TElRSAAntiTimingParams *AntiTimingParams)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRSA_PerformExponentiation_1(Blob, BlobSize, InBuffer, InSize, OutBuffer, &OutSize, (AntiTimingParams != NULL) ? AntiTimingParams->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRSAANTITIMINGPARAMS */

#endif /* SB_USE_GLOBAL_PROCS_RSA */

};	/* namespace SecureBlackbox */

