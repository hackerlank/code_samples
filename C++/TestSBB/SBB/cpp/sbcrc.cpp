#include "sbcrc.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CRC

SB_INLINE uint32_t CRC32(void * Buffer, int32_t Size)
{
	uint32_t OutResult;
	SBCheckError(SBCRC_CRC32(Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t CRC32(void * Buffer, int32_t Size, uint32_t Start)
{
	uint32_t OutResult;
	SBCheckError(SBCRC_CRC32_1(Buffer, Size, Start, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_CRC */

};	/* namespace SecureBlackbox */

