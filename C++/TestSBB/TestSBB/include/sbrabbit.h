#ifndef __INC_SBRABBIT
#define __INC_SBRABBIT

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
typedef uint32_t UInt32Array8[8];

#pragma pack(1)
typedef struct 
{
	uint32_t X[8];
	uint32_t C[8];
	uint32_t K[8];
	uint8_t Carry;
} Rabbit_Instance;

#pragma pack(1)
typedef struct 
{
	Rabbit_Instance Rabbit;
	Rabbit_Instance Rabbit_Master;
} Rabbit_Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_RABBIT

void Rabbit_Init(Rabbit_Context &Context, const std::vector<uint8_t> &Key);

void Rabbit_IVInit(Rabbit_Context &Context, const std::vector<uint8_t> &IV_Key);

void Rabbit_Cipher(Rabbit_Context &Context, const std::vector<uint8_t> &Src, std::vector<uint8_t> &Dst);

#endif /* SB_USE_GLOBAL_PROCS_RABBIT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_RABBIT
SB_IMPORT uint32_t SB_APIENTRY SBRabbit_Rabbit_Init(Rabbit_Context * Context, const uint8_t pKey[], int32_t szKey);
SB_IMPORT uint32_t SB_APIENTRY SBRabbit_Rabbit_IVInit(Rabbit_Context * Context, const uint8_t pIV_Key[], int32_t szIV_Key);
SB_IMPORT uint32_t SB_APIENTRY SBRabbit_Rabbit_Cipher(Rabbit_Context * Context, const uint8_t pSrc[], int32_t szSrc, uint8_t pDst[], int32_t * szDst);
#endif /* SB_USE_GLOBAL_PROCS_RABBIT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBRABBIT */

