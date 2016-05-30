#ifndef __INC_SBCRYPTOPROVDEFAULT
#define __INC_SBCRYPTOPROVDEFAULT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovbuiltin.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
TElCustomCryptoProviderHandle DefaultCryptoProvider();
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

void SetDefaultCryptoProviderType(TElCustomCryptoProviderClassHandle Value);

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvDefault_DefaultCryptoProvider(TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvDefault_SetDefaultCryptoProviderType(TElCustomCryptoProviderClassHandle Value);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVDEFAULT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVDEFAULT */

