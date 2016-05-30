#include "sbtwofish.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_TWOFISH

SB_INLINE void ExpandKey(const std::vector<uint8_t> &Key, TTwofishExpandedKey &ExpandedKey)
{
	SBCheckError(SBTwofish_ExpandKey(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &ExpandedKey));
}

SB_INLINE void EncryptBlock(const TTwofishExpandedKey &ExpandedKey, uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3)
{
	SBCheckError(SBTwofish_EncryptBlock(&ExpandedKey, &B0, &B1, &B2, &B3));
}

SB_INLINE void DecryptBlock(const TTwofishExpandedKey &ExpandedKey, uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3)
{
	SBCheckError(SBTwofish_DecryptBlock(&ExpandedKey, &B0, &B1, &B2, &B3));
}

#endif /* SB_USE_GLOBAL_PROCS_TWOFISH */

};	/* namespace SecureBlackbox */

