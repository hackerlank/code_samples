#include "sbdes.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_DES

SB_INLINE void ExpandKeyForEncryption(const std::vector<uint8_t> &Key, TDESExpandedKey &ExpandedKey)
{
	SBCheckError(SBDES_ExpandKeyForEncryption(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &ExpandedKey));
}

SB_INLINE void ExpandKeyForDecryption(const std::vector<uint8_t> &Key, TDESExpandedKey &ExpandedKey)
{
	SBCheckError(SBDES_ExpandKeyForDecryption(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &ExpandedKey));
}

SB_INLINE void Encrypt(uint32_t &B0, uint32_t &B1, const TDESExpandedKey &ExpandedKey)
{
	SBCheckError(SBDES_Encrypt(&B0, &B1, &ExpandedKey));
}

SB_INLINE void EncryptEDE(uint32_t &B0, uint32_t &B1, const TDESExpandedKey &Key1, const TDESExpandedKey &Key2, const TDESExpandedKey &Key3)
{
	SBCheckError(SBDES_EncryptEDE(&B0, &B1, &Key1, &Key2, &Key3));
}

#endif /* SB_USE_GLOBAL_PROCS_DES */

};	/* namespace SecureBlackbox */

