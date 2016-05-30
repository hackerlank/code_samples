#include "sbsshconstants.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SSHCONSTANTS

void GetSSHPacketNameByCode(int32_t Code, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBSSHConstants_GetSSHPacketNameByCode(Code, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-516904072, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_SSHCONSTANTS */

};	/* namespace SecureBlackbox */

