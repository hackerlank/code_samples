#include "sbgost341001.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_GOST341001

bool Generate(void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * D, int32_t &DSize, void * Qx, int32_t &QxSize, void * Qy, int32_t &QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBGOST341001_Generate(A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, Fld, D, &DSize, Qx, &QxSize, Qy, &QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Sign(void * hash, int32_t hashSize, void * d, int32_t dSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBGOST341001_Sign(hash, hashSize, d, dSize, A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, Fld, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Verify(void * hash, int32_t hashSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * R, int32_t RSize, void * S, int32_t SSize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBGOST341001_Verify(hash, hashSize, Qx, QxSize, Qy, QySize, R, RSize, S, SSize, A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, Fld, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool DeriveKey(void * ukm, int32_t ukmSize, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize, void * A, int32_t ASize, void * B, int32_t BSize, void * X, int32_t XSize, void * Y, int32_t YSize, void * N, int32_t NSize, void * P, int32_t PSize, int32_t Fld, void * R, int32_t &RSize, void * S, int32_t &SSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBGOST341001_DeriveKey(ukm, ukmSize, D, DSize, Qx, QxSize, Qy, QySize, A, ASize, B, BSize, X, XSize, Y, YSize, N, NSize, P, PSize, Fld, R, &RSize, S, &SSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_GOST341001 */

};	/* namespace SecureBlackbox */

