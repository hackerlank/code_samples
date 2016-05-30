#ifndef __INC_SBRC2
#define __INC_SBRC2

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
#define SB_TRC2BufferSize 	8
#define SB_TRC2ExpandedKeyLength 	64

typedef uint16_t TRC2ExpandedKey[64];

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_RC2

void ExpandKey(const std::vector<uint8_t> &Key, TRC2ExpandedKey &ExpandedKey);

void Encrypt(uint32_t &B0, uint32_t &B1, const TRC2ExpandedKey &ExpandedKey);

void Decrypt(uint32_t &B0, uint32_t &B1, const TRC2ExpandedKey &ExpandedKey);

bool ParseASN1Params(const std::vector<uint8_t> &Params, std::vector<uint8_t> &IV, int32_t &KeyBits);

void WriteASN1Params(const std::vector<uint8_t> &IV, int32_t KeyBits, std::vector<uint8_t> &Params);

#endif /* SB_USE_GLOBAL_PROCS_RC2 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RC2
SB_IMPORT uint32_t SB_APIENTRY SBRC2_ExpandKey(const uint8_t pKey[], int32_t szKey, TRC2ExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBRC2_Encrypt(uint32_t * B0, uint32_t * B1, const TRC2ExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBRC2_Decrypt(uint32_t * B0, uint32_t * B1, const TRC2ExpandedKey * ExpandedKey);
SB_IMPORT uint32_t SB_APIENTRY SBRC2_ParseASN1Params(const uint8_t pParams[], int32_t szParams, uint8_t pIV[], int32_t * szIV, int32_t * KeyBits, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBRC2_WriteASN1Params(const uint8_t pIV[], int32_t szIV, int32_t KeyBits, uint8_t pParams[], int32_t * szParams);
#endif /* SB_USE_GLOBAL_PROCS_RC2 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRC2 */

