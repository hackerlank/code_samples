#include "sbrabbit.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_RABBIT

SB_INLINE void Rabbit_Init(Rabbit_Context &Context, const std::vector<uint8_t> &Key)
{
	SBCheckError(SBRabbit_Rabbit_Init(&Context, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size()));
}

SB_INLINE void Rabbit_IVInit(Rabbit_Context &Context, const std::vector<uint8_t> &IV_Key)
{
	SBCheckError(SBRabbit_Rabbit_IVInit(&Context, SB_STD_VECTOR_FRONT_ADR(IV_Key), (int32_t)IV_Key.size()));
}

void Rabbit_Cipher(Rabbit_Context &Context, const std::vector<uint8_t> &Src, std::vector<uint8_t> &Dst)
{
	int32_t szDst = (int32_t)Dst.size();
	uint32_t _err = SBRabbit_Rabbit_Cipher(&Context, SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Dst), &szDst);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dst.resize(szDst);
		SBCheckError(SBGetLastReturnBuffer(2036673116, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Dst), &szDst));
	}
	else
		SBCheckError(_err);

	Dst.resize(szDst);
}

#endif /* SB_USE_GLOBAL_PROCS_RABBIT */

};	/* namespace SecureBlackbox */

