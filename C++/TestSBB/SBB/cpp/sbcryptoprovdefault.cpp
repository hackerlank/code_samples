#include "sbcryptoprovdefault.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
SB_INLINE TElCustomCryptoProviderHandle DefaultCryptoProvider()
{
	TElCustomCryptoProviderHandle OutResult;
	SBCheckError(SBCryptoProvDefault_DefaultCryptoProvider(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

SB_INLINE void SetDefaultCryptoProviderType(TElCustomCryptoProviderClassHandle Value)
{
	SBCheckError(SBCryptoProvDefault_SetDefaultCryptoProviderType(Value));
}

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT */

};	/* namespace SecureBlackbox */

