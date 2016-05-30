#ifndef __INC_SBCAMELLIA
#define __INC_SBCAMELLIA

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint32_t TCmInt64[2];

typedef uint32_t TCmInt128[4];

typedef uint8_t TSBCamelliaBuffer[16];

typedef TSBCamelliaBuffer * PSBCamelliaBuffer;

#pragma pack(4)
typedef struct 
{
	TCmInt64 K[24];
	TCmInt64 KE[6];
	TCmInt64 KW[4];
} TSBCamelliaExpandedKey;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CAMELLIA

void EncryptBlock(uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3, const TSBCamelliaExpandedKey &Key, bool LongKey);

bool ExpandKeyForEncryption(const std::vector<uint8_t> &Key, TSBCamelliaExpandedKey &EKey);

bool ExpandKeyForDecryption(const std::vector<uint8_t> &Key, TSBCamelliaExpandedKey &EKey);

#endif /* SB_USE_GLOBAL_PROCS_CAMELLIA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CAMELLIA
SB_IMPORT uint32_t SB_APIENTRY SBCamellia_EncryptBlock(uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3, const TSBCamelliaExpandedKey * Key, int8_t LongKey);
SB_IMPORT uint32_t SB_APIENTRY SBCamellia_ExpandKeyForEncryption(const uint8_t pKey[], int32_t szKey, TSBCamelliaExpandedKey * EKey, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCamellia_ExpandKeyForDecryption(const uint8_t pKey[], int32_t szKey, TSBCamelliaExpandedKey * EKey, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CAMELLIA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCAMELLIA */

