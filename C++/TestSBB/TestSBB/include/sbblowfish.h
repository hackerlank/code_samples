#ifndef __INC_SBBLOWFISH
#define __INC_SBBLOWFISH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"

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
	uint32_t P0;
	uint32_t P1;
	uint32_t P2;
	uint32_t P3;
	uint32_t P4;
	uint32_t P5;
	uint32_t P6;
	uint32_t P7;
	uint32_t P8;
	uint32_t P9;
	uint32_t P10;
	uint32_t P11;
	uint32_t P12;
	uint32_t P13;
	uint32_t P14;
	uint32_t P15;
	uint32_t P16;
	uint32_t P17;
	uint32_t S0[256];
	uint32_t S1[256];
	uint32_t S2[256];
	uint32_t S3[256];
} TSBBlowfishContext;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_BLOWFISH

void EncryptBlock(TSBBlowfishContext &Context, uint32_t &L, uint32_t &R);

void DecryptBlock(TSBBlowfishContext &Context, uint32_t &L, uint32_t &R);

void Initialize(TSBBlowfishContext &Context, const std::vector<uint8_t> &Key);

void EksInitialize(TSBBlowfishContext &Context, int32_t Rounds, const std::vector<uint8_t> &Salt, const std::vector<uint8_t> &Key);

#endif /* SB_USE_GLOBAL_PROCS_BLOWFISH */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_BLOWFISH
SB_IMPORT uint32_t SB_APIENTRY SBBlowfish_EncryptBlock(TSBBlowfishContext * Context, uint32_t * L, uint32_t * R);
SB_IMPORT uint32_t SB_APIENTRY SBBlowfish_DecryptBlock(TSBBlowfishContext * Context, uint32_t * L, uint32_t * R);
SB_IMPORT uint32_t SB_APIENTRY SBBlowfish_Initialize(TSBBlowfishContext * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBBlowfish_EksInitialize(TSBBlowfishContext * Context, int32_t Rounds, const uint8_t pSalt[], int32_t szSalt, const uint8_t pKey[], int32_t szKey);
#endif /* SB_USE_GLOBAL_PROCS_BLOWFISH */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBLOWFISH */

