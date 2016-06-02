#ifndef __INC_SBPGPEXCEPTIONS
#define __INC_SBPGPEXCEPTIONS

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
#define SB_PGP_INTEX_1 	1
#define SB_PGP_INTEX_2 	2
#define SB_PGP_INTEX_3 	3
#define SB_PGP_INTEX_4 	4
#define SB_PGP_INTEX_5 	5
#define SB_PGP_INTEX_6 	6
#define SB_PGP_INTEX_7 	7

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPEXCEPTIONS */

