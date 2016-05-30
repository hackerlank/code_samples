#include "sbtarutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_TARUTILS

SB_INLINE int64_t Oct2Dec(const std::string &Oct)
{
	int64_t OutResult;
	SBCheckError(SBTarUtils_Oct2Dec(Oct.data(), (int32_t)Oct.length(), &OutResult));
	return OutResult;
}

void Dec2Oct(int64_t Dec, int32_t Len, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBTarUtils_Dec2Oct(Dec, Len, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-331840100, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TruncArray(const std::vector<uint8_t> &B, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBTarUtils_TruncArray(SB_STD_VECTOR_FRONT_ADR(B), (int32_t)B.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1827016839, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_TARUTILS */

};	/* namespace SecureBlackbox */

