#ifndef __INC_SBCHACHA20
#define __INC_SBCHACHA20

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbpoly1305.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_TChaCha20KeySize 	32
#define SB_TChaCha20NonceSize 	12
#define SB_TChaCha20StateSize 	16

typedef uint32_t * PSBChaCha20Counter;

typedef uint32_t TSBChaCha20State[16];

typedef TSBChaCha20State * PSBChaCha20State;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CHACHA20

void QuarterRound(int32_t a, int32_t b, int32_t c, int32_t d, TSBChaCha20State &State);

void InnerBlock(TSBChaCha20State &State);

void ChaCha20Block(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, std::vector<uint8_t> &OutResult);

void ChaCha20Encrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, const std::vector<uint8_t> &Msg, std::vector<uint8_t> &OutResult);

void ChaCha20Decrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, uint32_t Counter, const std::vector<uint8_t> &Msg, std::vector<uint8_t> &OutResult);

void Poly1305KeyGen(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, std::vector<uint8_t> &OutResult);

void AEADEncrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, const std::vector<uint8_t> &Msg, const std::vector<uint8_t> &AAD, TSBPoly1305Mode Mode, TSBPoly1305Tag &Tag, std::vector<uint8_t> &OutResult);

bool AEADDecrypt(const std::vector<uint8_t> &Key, const std::vector<uint8_t> &Nonce, const std::vector<uint8_t> &EMsg, const std::vector<uint8_t> &AAD, const TSBPoly1305Tag &Tag, TSBPoly1305Mode Mode, std::vector<uint8_t> &DMsg);

#endif /* SB_USE_GLOBAL_PROCS_CHACHA20 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CHACHA20
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_QuarterRound(int32_t a, int32_t b, int32_t c, int32_t d, TSBChaCha20State * State);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_InnerBlock(TSBChaCha20State * State);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_ChaCha20Block(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, uint32_t Counter, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_ChaCha20Encrypt(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, uint32_t Counter, const uint8_t pMsg[], int32_t szMsg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_ChaCha20Decrypt(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, uint32_t Counter, const uint8_t pMsg[], int32_t szMsg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_Poly1305KeyGen(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_AEADEncrypt(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, const uint8_t pMsg[], int32_t szMsg, const uint8_t pAAD[], int32_t szAAD, TSBPoly1305ModeRaw Mode, TSBPoly1305Tag * Tag, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChaCha20_AEADDecrypt(const uint8_t pKey[], int32_t szKey, const uint8_t pNonce[], int32_t szNonce, const uint8_t pEMsg[], int32_t szEMsg, const uint8_t pAAD[], int32_t szAAD, const TSBPoly1305Tag * Tag, TSBPoly1305ModeRaw Mode, uint8_t pDMsg[], int32_t * szDMsg, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CHACHA20 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHACHA20 */

