#ifndef __INC_SBRC4
#define __INC_SBRC4

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint8_t TRC4ExpandedKey[256];

#pragma pack(4)
typedef struct 
{
	uint8_t L;
	uint8_t K;
	uint8_t TK[256];
} TRC4Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_RC4

void Initialize(TRC4Context &Context, const std::vector<uint8_t> &Key);

bool Encrypt(TRC4Context &Context, void * Buf, void * OutBuf, uint32_t Size);

void Encrypt(void * InBuffer, int32_t Size, const TRC4ExpandedKey &ExpandedKey, void * OutBuffer);

bool Decrypt(TRC4Context &Context, void * Buf, void * OutBuf, uint32_t Size);

void Decrypt(void * InBuffer, int32_t Size, const TRC4ExpandedKey &ExpandedKey, void * OutBuffer);

bool NFinalize(TRC4Context &Context);

#endif /* SB_USE_GLOBAL_PROCS_RC4 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RC4
SB_IMPORT uint32_t SB_APIENTRY SBRC4_Initialize(TRC4Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBRC4_Encrypt(TRC4Context * Context, void * Buf, void * OutBuf, uint32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRC4_Encrypt_1(void * InBuffer, int32_t Size, const TRC4ExpandedKey * ExpandedKey, void * OutBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBRC4_Decrypt(TRC4Context * Context, void * Buf, void * OutBuf, uint32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRC4_Decrypt_1(void * InBuffer, int32_t Size, const TRC4ExpandedKey * ExpandedKey, void * OutBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBRC4_NFinalize(TRC4Context * Context, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_RC4 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRC4 */

