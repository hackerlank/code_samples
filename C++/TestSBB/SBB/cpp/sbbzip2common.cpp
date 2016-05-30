#include "sbbzip2common.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_BZIP2COMMON

#ifdef SB_USE_CLASS_ESTATE
SB_INLINE void BZ2_compressBlock(EState &s, bool is_last_block)
{
	SBCheckError(SBBzip2Common_BZ2_compressBlock(s.getHandle(), (int8_t)is_last_block));
}
SB_INLINE void BZ2_compressBlock(EState *s, bool is_last_block)
{
	SBCheckError(SBBzip2Common_BZ2_compressBlock((s != NULL) ? s->getHandle() : SB_NULL_HANDLE, (int8_t)is_last_block));
}
#endif /* SB_USE_CLASS_ESTATE */

#ifdef SB_USE_CLASS_DSTATE
SB_INLINE int32_t BZ2_decompress(DState &s)
{
	int32_t OutResult;
	SBCheckError(SBBzip2Common_BZ2_decompress(s.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t BZ2_decompress(DState *s)
{
	int32_t OutResult;
	SBCheckError(SBBzip2Common_BZ2_decompress((s != NULL) ? s->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_DSTATE */

#endif /* SB_USE_GLOBAL_PROCS_BZIP2COMMON */

};	/* namespace SecureBlackbox */

