#include "sbdefs.h"
#ifdef SB_WINDOWS
#include "sbsspi.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SSPI

bool SEC_SUCCESS(int32_t Status)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSSPI_SEC_SUCCESS(Status, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void SecInvalidateHandleInt(SecHandle &x)
{
	SBCheckError(SBSSPI_SecInvalidateHandleInt(&x));
}

bool SecIsValidHandleInt(const SecHandle &x)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSSPI_SecIsValidHandleInt(&x, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void FreeAuthLibrary()
{
	SBCheckError(SBSSPI_FreeAuthLibrary());
}

#endif /* SB_USE_GLOBAL_PROCS_SSPI */

};	/* namespace SecureBlackbox */
#endif
