#ifndef __INC_SBTWOFISH
#define __INC_SBTWOFISH

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
#pragma pack(4)
typedef struct 
{
	uint32_t ExpandedKey[40];
	uint32_t SBoxKey[4];
	uint8_t SBox0[256];
	uint8_t SBox1[256];
	uint8_t SBox2[256];
	uint8_t SBox3[256];
	int32_t KeyLen;
} TTwofishExpandedKey;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_TWOFISH

void ExpandKey(const std::vector<uint8_t> &Key, TTwofishExpandedKey &ExpandedKey);

void EncryptBlock(const TTwofishExpandedKey &ExpandedKey, uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3);

void DecryptBlock(const TTwofishExpandedKey &ExpandedKey, uint32_t &B0, uint32_t &B1, uint32_t &B2, uint32_t &B3);

#endif /* SB_USE_GLOBAL_PROCS_TWOFISH */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_TWOFISH
SB_IMPORT uint32_t SB_APIENTRY SBTwofish_ExpandKey(const uint8_t pKey[], int32_t szKey, TTwofishExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBTwofish_EncryptBlock(const TTwofishExpandedKey * ExpandedKey, uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3);
SB_IMPORT uint32_t SB_APIENTRY SBTwofish_DecryptBlock(const TTwofishExpandedKey * ExpandedKey, uint32_t * B0, uint32_t * B1, uint32_t * B2, uint32_t * B3);
#endif /* SB_USE_GLOBAL_PROCS_TWOFISH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTWOFISH */

