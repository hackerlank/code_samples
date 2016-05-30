#include "sbaes.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_AES

SB_INLINE void ExpandKeyForEncryption128(const TAESKey128 &Key, TAESExpandedKey128 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForEncryption128(&Key, &ExpandedKey));
}

SB_INLINE void ExpandKeyForEncryption192(const TAESKey192 &Key, TAESExpandedKey192 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForEncryption192(&Key, &ExpandedKey));
}

SB_INLINE void ExpandKeyForEncryption256(const TAESKey256 &Key, TAESExpandedKey256 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForEncryption256(&Key, &ExpandedKey));
}

SB_INLINE void ExpandKeyForDecryption128(TAESExpandedKey128 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForDecryption128(&ExpandedKey));
}

SB_INLINE void ExpandKeyForDecryption192(TAESExpandedKey192 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForDecryption192(&ExpandedKey));
}

SB_INLINE void ExpandKeyForDecryption256(TAESExpandedKey256 &ExpandedKey)
{
	SBCheckError(SBAES_ExpandKeyForDecryption256(&ExpandedKey));
}

SB_INLINE void Encrypt128(const TAESBuffer &InBuf, const TAESExpandedKey128 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Encrypt128(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Encrypt128(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey128 &Key)
{
	SBCheckError(SBAES_Encrypt128_1(&B0, &B1, &B2, &B3, &Key));
}

SB_INLINE void Encrypt192(const TAESBuffer &InBuf, const TAESExpandedKey192 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Encrypt192(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Encrypt192(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey192 &Key)
{
	SBCheckError(SBAES_Encrypt192_1(&B0, &B1, &B2, &B3, &Key));
}

SB_INLINE void Encrypt256(const TAESBuffer &InBuf, const TAESExpandedKey256 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Encrypt256(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Encrypt256(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey256 &Key)
{
	SBCheckError(SBAES_Encrypt256_1(&B0, &B1, &B2, &B3, &Key));
}

SB_INLINE void Decrypt128(const TAESBuffer &InBuf, const TAESExpandedKey128 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Decrypt128(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Decrypt128(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey128 &Key)
{
	SBCheckError(SBAES_Decrypt128_1(&B0, &B1, &B2, &B3, &Key));
}

SB_INLINE void Decrypt192(const TAESBuffer &InBuf, const TAESExpandedKey192 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Decrypt192(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Decrypt192(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey192 &Key)
{
	SBCheckError(SBAES_Decrypt192_1(&B0, &B1, &B2, &B3, &Key));
}

SB_INLINE void Decrypt256(const TAESBuffer &InBuf, const TAESExpandedKey256 &Key, TAESBuffer &OutBuf)
{
	SBCheckError(SBAES_Decrypt256(&InBuf, &Key, &OutBuf));
}

SB_INLINE void Decrypt256(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TAESExpandedKey256 &Key)
{
	SBCheckError(SBAES_Decrypt256_1(&B0, &B1, &B2, &B3, &Key));
}

#endif /* SB_USE_GLOBAL_PROCS_AES */

};	/* namespace SecureBlackbox */

