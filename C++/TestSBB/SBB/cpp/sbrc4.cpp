#include "sbrc4.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_RC4

SB_INLINE void Initialize(TRC4Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBRC4_Initialize(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

bool Encrypt(TRC4Context &Context, void * Buf, void * OutBuf, uint32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRC4_Encrypt(&Context, Buf, OutBuf, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void Encrypt(void * InBuffer, int32_t Size, const TRC4ExpandedKey &ExpandedKey, void * OutBuffer)
{
	SBCheckError(SBRC4_Encrypt_1(InBuffer, Size, &ExpandedKey, OutBuffer));
}

bool Decrypt(TRC4Context &Context, void * Buf, void * OutBuf, uint32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRC4_Decrypt(&Context, Buf, OutBuf, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void Decrypt(void * InBuffer, int32_t Size, const TRC4ExpandedKey &ExpandedKey, void * OutBuffer)
{
	SBCheckError(SBRC4_Decrypt_1(InBuffer, Size, &ExpandedKey, OutBuffer));
}

bool NFinalize(TRC4Context &Context)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBRC4_NFinalize(&Context, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_RC4 */

};	/* namespace SecureBlackbox */

