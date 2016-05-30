#include "sbserpent.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SERPENT

SB_INLINE void ExpandKey(const std::vector<uint8_t> &Key, TSerpentExpandedKey &ExpandedKey)
{
	SBCheckError(SBSerpent_ExpandKey(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &ExpandedKey));
}

SB_INLINE void EncryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSerpentExpandedKey &ExpandedKey)
{
	SBCheckError(SBSerpent_EncryptBlock(&B0, &B1, &B2, &B3, &ExpandedKey));
}

SB_INLINE void DecryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSerpentExpandedKey &ExpandedKey)
{
	SBCheckError(SBSerpent_DecryptBlock(&B0, &B1, &B2, &B3, &ExpandedKey));
}

#endif /* SB_USE_GLOBAL_PROCS_SERPENT */

};	/* namespace SecureBlackbox */

