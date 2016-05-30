#include "sbelgamal.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ELGAMAL

bool Generate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_Generate(Bits, P, G, X, Y, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_ExternalGenerate(Bits, P, G, X, Y, pMethodProgressFunc, pDataProgressFunc, Data, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBElgamal_ExternalGenerationSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_ExternalGenerationSupported(&OutResultRaw));
	return (OutResultRaw != 0);
}

bool Encrypt(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_Encrypt(Src, P, G, Y, A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Decrypt(PLInt P, PLInt G, PLInt X, PLInt A, PLInt B, PLInt Dest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_Decrypt(P, G, X, A, B, Dest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Sign(PLInt Src, PLInt P, PLInt G, PLInt X, PLInt A, PLInt B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_Sign(Src, P, G, X, A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Verify(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_Verify(Src, P, G, Y, A, B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodeResult(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_EncodeResult(R, RSize, S, SSize, Blob, &BlobSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodeResult(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_DecodeResult(Blob, Size, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodePublicKey(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_EncodePublicKey(P, PSize, G, GSize, Y, YSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBElgamal_EncodePrivateKey(void * P, int32_t PSize, void * G, int32_t GSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBElgamal_EncodePrivateKey(P, PSize, G, GSize, X, XSize, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_ELGAMAL */

};	/* namespace SecureBlackbox */

