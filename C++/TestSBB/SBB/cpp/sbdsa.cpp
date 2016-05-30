#include "sbdsa.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_DSA

bool ValidateSignature(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * R, int32_t RSize, void * S, int32_t SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_ValidateSignature(Hash, HashSize, P, PSize, Q, QSize, G, GSize, Y, YSize, R, RSize, S, SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Generate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_Generate(Bits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Generate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_Generate_1(Bits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, PrivateKeyBlob, &PrivateKeyBlobSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_ExternalGenerate(Bits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_ExternalGenerate_1(Bits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, PrivateKeyBlob, &PrivateKeyBlobSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool GenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_GenerateEx(PBits, QBits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_ExternalGenerateEx(PBits, QBits, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Sign(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_Sign(Hash, HashSize, P, PSize, Q, QSize, G, GSize, X, XSize, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SignEx(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_SignEx(Hash, HashSize, P, PSize, Q, QSize, G, GSize, X, XSize, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodePrivateKey(void * Buffer, int32_t Size, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_DecodePrivateKey(Buffer, Size, P, &PSize, Q, &QSize, G, &GSize, Y, &YSize, X, &XSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodePrivateKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_EncodePrivateKey(P, PSize, Q, QSize, G, GSize, Y, YSize, X, XSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_EncodeSignature(R, RSize, S, SSize, Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodeSignature(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_DecodeSignature(Blob, Size, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsValidKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, bool Secret, bool StrictMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_IsValidKey(P, PSize, Q, QSize, G, GSize, Y, YSize, X, XSize, (int8_t)Secret, (int8_t)StrictMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerationSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDSA_ExternalGenerationSupported(&OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_DSA */

};	/* namespace SecureBlackbox */

