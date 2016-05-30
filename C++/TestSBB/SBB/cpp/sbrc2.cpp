#include "sbrc2.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_RC2

SB_INLINE void ExpandKey(const std::vector<uint8_t> &Key, TRC2ExpandedKey &ExpandedKey)
{
	SBCheckError(SBRC2_ExpandKey(SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), &ExpandedKey));
}

SB_INLINE void Encrypt(uint32_t &B0, uint32_t &B1, const TRC2ExpandedKey &ExpandedKey)
{
	SBCheckError(SBRC2_Encrypt(&B0, &B1, &ExpandedKey));
}

SB_INLINE void Decrypt(uint32_t &B0, uint32_t &B1, const TRC2ExpandedKey &ExpandedKey)
{
	SBCheckError(SBRC2_Decrypt(&B0, &B1, &ExpandedKey));
}

bool ParseASN1Params(const std::vector<uint8_t> &Params, std::vector<uint8_t> &IV, int32_t &KeyBits)
{
	int32_t szIV = (int32_t)IV.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBRC2_ParseASN1Params(SB_STD_VECTOR_FRONT_ADR(Params), (int32_t)Params.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IV), &szIV, &KeyBits, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IV.resize(szIV);
		SBCheckError(SBGetLastReturnBuffer(-2012554264, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IV), &szIV));
	}
	else
		SBCheckError(_err);

	IV.resize(szIV);
	return (OutResultRaw != 0);
}

void WriteASN1Params(const std::vector<uint8_t> &IV, int32_t KeyBits, std::vector<uint8_t> &Params)
{
	int32_t szParams = (int32_t)Params.size();
	uint32_t _err = SBRC2_WriteASN1Params(SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), KeyBits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Params.resize(szParams);
		SBCheckError(SBGetLastReturnBuffer(1781943983, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Params), &szParams));
	}
	else
		SBCheckError(_err);

	Params.resize(szParams);
}

#endif /* SB_USE_GLOBAL_PROCS_RC2 */

};	/* namespace SecureBlackbox */

