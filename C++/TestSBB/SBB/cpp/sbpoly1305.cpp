#include "sbpoly1305.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_POLY1305

SB_INLINE void Poly1305Clamp(TSBPoly1305Part &R)
{
	SBCheckError(SBPoly1305_Poly1305Clamp(&R));
}

SB_INLINE void Poly1305Add(const TSBPoly1305Part &B, TSBPoly1305Part &A)
{
	SBCheckError(SBPoly1305_Poly1305Add(&B, &A));
}

SB_INLINE void Poly1305Mult(const TSBPoly1305Part &B, const TSBPoly1305Part &A, TSBPoly1305MultRes &OutResult)
{
	SBCheckError(SBPoly1305_Poly1305Mult(&B, &A, &OutResult));
}

SB_INLINE void Poly1305Squeeze(const TSBPoly1305MultRes &B, TSBPoly1305Part &OutResult)
{
	SBCheckError(SBPoly1305_Poly1305Squeeze(&B, &OutResult));
}

SB_INLINE void Poly1305Final(TSBPoly1305Part &A)
{
	SBCheckError(SBPoly1305_Poly1305Final(&A));
}

SB_INLINE void GeneratePoly1305(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Msg, TSBPoly1305Tag &OutResult)
{
	SBCheckError(SBPoly1305_GeneratePoly1305(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), &OutResult));
}

#endif /* SB_USE_GLOBAL_PROCS_POLY1305 */

};	/* namespace SecureBlackbox */

