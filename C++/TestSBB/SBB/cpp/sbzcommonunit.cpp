#include "sbzcommonunit.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ZCOMMONUNIT

void zlibVersion(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBZCommonUnit_zlibVersion((uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-802749151, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t adler32(uint32_t adler, void * buf, uint32_t len)
{
	uint32_t OutResult;
	SBCheckError(SBZCommonUnit_adler32(adler, buf, len, &OutResult));
	return OutResult;
}

SB_INLINE void * zlibAllocMem(void * AppData, int32_t Items, int32_t Size)
{
	void * OutResult;
	SBCheckError(SBZCommonUnit_zlibAllocMem(AppData, Items, Size, &OutResult));
	return OutResult;
}

SB_INLINE void zlibFreeMem(void * AppData, void * Block)
{
	SBCheckError(SBZCommonUnit_zlibFreeMem(AppData, Block));
}

SB_INLINE int32_t CCheck(int32_t code)
{
	int32_t OutResult;
	SBCheckError(SBZCommonUnit_CCheck(code, &OutResult));
	return OutResult;
}

SB_INLINE void ZlibMemCpy(void * dest, void * source, int32_t count)
{
	SBCheckError(SBZCommonUnit_ZlibMemCpy(dest, source, count));
}

#endif /* SB_USE_GLOBAL_PROCS_ZCOMMONUNIT */

};	/* namespace SecureBlackbox */

