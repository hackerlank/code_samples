#include "sbidea.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_IDEA

SB_INLINE void ExpandKeyForEncryption(const TIDEAKey &Key, TIDEAExpandedKey &ExpandedKey)
{
	SBCheckError(SBIDEA_ExpandKeyForEncryption(&Key, &ExpandedKey));
}

SB_INLINE void ExpandKeyForDecryption(const TIDEAExpandedKey &CipherKey, TIDEAExpandedKey &DecipherKey)
{
	SBCheckError(SBIDEA_ExpandKeyForDecryption(&CipherKey, &DecipherKey));
}

SB_INLINE void Encrypt(uint32_t &B0, uint32_t &B1, const TIDEAExpandedKey &Key)
{
	SBCheckError(SBIDEA_Encrypt(&B0, &B1, &Key));
}

#endif /* SB_USE_GLOBAL_PROCS_IDEA */

};	/* namespace SecureBlackbox */

