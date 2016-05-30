#include "sbecdsa.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ECDSA

bool GenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_GenerateEx(A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, FldType, Fld, D, &DSize, Qx, &QxSize, Qy, &QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool GenerateforSSH(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_GenerateforSSH(A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, FldType, Fld, D, &DSize, Qx, &QxSize, Qy, &QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExternalGenerateEx(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t CurveID, const std::vector<uint8_t> &CurveOID, int32_t FldType, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_ExternalGenerateEx(A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, CurveID, SB_STD_VECTOR_FRONT_ADR(CurveOID), (int32_t)CurveOID.size(), FldType, Fld, D, &DSize, Qx, &QxSize, Qy, &QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SignEx(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flag, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_SignEx(hash, hashSize, d, dSize, A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, FldType, Fld, Flag, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool VerifyEx(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t FldType, int32_t Fld, int32_t Flags)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_VerifyEx(hash, hashSize, Qx, QxSize, Qy, QySize, R, RSize, S, SSize, A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, FldType, Fld, Flags, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool EncodePrivateKey(void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, int32_t Curve, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_EncodePrivateKey(D, DSize, Qx, QxSize, Qy, QySize, Curve, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DecodePrivateKey(void * Buffer, int32_t Size, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize, int32_t &Curve)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_DecodePrivateKey(Buffer, Size, D, &DSize, Qx, &QxSize, Qy, &QySize, &Curve, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool SBECDSA_ExternalGenerationSupported()
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECDSA_ExternalGenerationSupported(&OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_ECDSA */

};	/* namespace SecureBlackbox */

