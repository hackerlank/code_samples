#include "sbseed.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SEED

SB_INLINE void SeedCoding(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSEEDKey &Key, uint8_t Direction)
{
	SBCheckError(SBSeed_SeedCoding(&B0, &B1, &B2, &B3, &Key, Direction));
}

#endif /* SB_USE_GLOBAL_PROCS_SEED */

};	/* namespace SecureBlackbox */

