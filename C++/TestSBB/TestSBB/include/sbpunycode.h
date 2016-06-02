#ifndef __INC_SBPUNYCODE
#define __INC_SBPUNYCODE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_BASE 	36
#define SB_TMIN 	1
#define SB_TMAX 	26
#define SB_SKEW 	38
#define SB_DAMP 	700
#define SB_INITIAL_BIAS 	72
#define SB_INITIAL_N 	128
#define SB_DELIMITER 	45
#define SB_MAXUINTGR 	2147483647
#define SB_MAXPUNYLEN 	256
#define SB_PUNYCODE_BAD_INPUT 	1
#define SB_PUNYCODE_BIG_OUTPUT 	2
#define SB_PUNYCODE_OVERFLOW 	3
#define SB_SBadInput 	"Invalid input"
#define SB_SBigOutput 	"Input or output is too large, recompile sources with larger limits"
#define SB_SOverflow 	"Arithmetic overflow"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_PUNYCODE

void PunycodeEncode(const sb_u16string &Input, std::string &OutResult);
#ifdef SB_U16STRING_USED
void PunycodeEncode(const std::wstring &Input, std::string &OutResult);
#endif /* SB_U16STRING_USED */

void PunycodeDecode(const std::string &Input, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void PunycodeDecode(const std::string &Input, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ToASCII(const sb_u16string &Domain, std::string &OutResult);
#ifdef SB_U16STRING_USED
void ToASCII(const std::wstring &Domain, std::string &OutResult);
#endif /* SB_U16STRING_USED */

void ToUnicode(const std::string &Domain, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ToUnicode(const std::string &Domain, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_PUNYCODE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PUNYCODE
SB_IMPORT uint32_t SB_APIENTRY SBPunycode_PunycodeEncode(const sb_char16_t * pcInput, int32_t szInput, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPunycode_PunycodeDecode(const char * pcInput, int32_t szInput, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPunycode_ToASCII(const sb_char16_t * pcDomain, int32_t szDomain, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPunycode_ToUnicode(const char * pcDomain, int32_t szDomain, sb_char16_t * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_PUNYCODE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPUNYCODE */

