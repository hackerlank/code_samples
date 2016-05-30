#include "sbftpscommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_FTPSCOMMON

bool IsWhitespace(uint8_t b)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBFTPSCommon_IsWhitespace(b, &OutResultRaw));
	return (OutResultRaw != 0);
}

void DateTimeToFTPTimeVal(int64_t DateTime, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBFTPSCommon_DateTimeToFTPTimeVal(DateTime, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1996554184, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnixPermissionsToStringRwx(uint32_t Permissions, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBFTPSCommon_UnixPermissionsToStringRwx(Permissions, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-406138125, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnixPermissionsToStringOct(uint32_t Permissions, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBFTPSCommon_UnixPermissionsToStringOct(Permissions, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1082947502, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_FTPSCOMMON */

};	/* namespace SecureBlackbox */

