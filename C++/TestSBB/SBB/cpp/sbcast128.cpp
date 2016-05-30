#include "sbcast128.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CAST128

SB_INLINE void ExpandKey(const TCAST128Key &Key, TCAST128ExpandedKey &ExpandedKey)
{
	SBCheckError(SBCAST128_ExpandKey(&Key, &ExpandedKey));
}

SB_INLINE void Encrypt16(uint32_t &B0, uint32_t &B1, TCAST128ExpandedKey &ExpandedKey)
{
	SBCheckError(SBCAST128_Encrypt16(&B0, &B1, &ExpandedKey));
}

SB_INLINE void Decrypt16(uint32_t &B0, uint32_t &B1, TCAST128ExpandedKey &ExpandedKey)
{
	SBCheckError(SBCAST128_Decrypt16(&B0, &B1, &ExpandedKey));
}

#endif /* SB_USE_GLOBAL_PROCS_CAST128 */

};	/* namespace SecureBlackbox */

