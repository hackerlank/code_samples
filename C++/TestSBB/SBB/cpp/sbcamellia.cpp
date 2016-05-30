#include "sbcamellia.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CAMELLIA

SB_INLINE void EncryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSBCamelliaExpandedKey &Key, bool LongKey)
{
	SBCheckError(SBCamellia_EncryptBlock(&B0, &B1, &B2, &B3, &Key, (int8_t)LongKey));
}

bool ExpandKeyForEncryption(const std::vector<uint8_t> &Key, TSBCamelliaExpandedKey &EKey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCamellia_ExpandKeyForEncryption(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &EKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool ExpandKeyForDecryption(const std::vector<uint8_t> &Key, TSBCamelliaExpandedKey &EKey)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCamellia_ExpandKeyForDecryption(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &EKey, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_CAMELLIA */

};	/* namespace SecureBlackbox */

