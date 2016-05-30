#include "sbblowfish.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_BLOWFISH

SB_INLINE void EncryptBlock(TSBBlowfishContext &Context, uint32_t &L, uint32_t &R)
{
	SBCheckError(SBBlowfish_EncryptBlock(&Context, &L, &R));
}

SB_INLINE void DecryptBlock(TSBBlowfishContext &Context, uint32_t &L, uint32_t &R)
{
	SBCheckError(SBBlowfish_DecryptBlock(&Context, &L, &R));
}

SB_INLINE void Initialize(TSBBlowfishContext &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBBlowfish_Initialize(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void EksInitialize(TSBBlowfishContext &Context, int32_t Rounds, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBBlowfish_EksInitialize(&Context, Rounds, SB_STD_VECTOR_FRONT_ADR(Salt), (int32_t)Salt.size(), SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

#endif /* SB_USE_GLOBAL_PROCS_BLOWFISH */

};	/* namespace SecureBlackbox */

