#ifndef __INC_SBCHSUNICODE
#define __INC_SBCHSUNICODE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SInvalidChar 	"Invalid code sequence"
#define SB_HANGUL_SBASE 	44032
#define SB_HANGUL_LBASE 	4352
#define SB_HANGUL_VBASE 	4449
#define SB_HANGUL_TBASE 	4519
#define SB_HANGUL_LCOUNT 	19
#define SB_HANGUL_VCOUNT 	21
#define SB_HANGUL_TCOUNT 	28
#define SB_HANGUL_NCOUNT 	588
#define SB_HANGUL_SCOUNT 	11172
#define SB_HANGUL_L_START 	4352
#define SB_HANGUL_L_END 	4442
#define SB_HANGUL_L_FILLER 	4447
#define SB_HANGUL_V_START 	4448
#define SB_HANGUL_V_END 	4515
#define SB_HANGUL_T_START 	4520
#define SB_HANGUL_T_END 	4602
#define SB_HANGUL_S_START 	44032
#define SB_HANGUL_S_END 	55204
#define SB_UnassignedCodesCount 	396
#define SB_DeprecatedCodesCount 	4
#define SB_PrivateCodesCount 	3
#define SB_NonCharacterCodesCount 	18
#define SB_SurrogateCodesCount 	1
#define SB_BidiControlCount 	12

typedef uint8_t TPlCharTypeRaw;

typedef enum
{
	ctOther = 0,
	ctLetterUpper = 1,
	ctLetterLower = 2,
	ctLetterTitle = 3,
	ctLetterOther = 4,
	ctNumber = 5,
	ctPunctuation = 6,
	ctSpace = 7,
	ctControl = 8,
	ctMark = 9
} TPlCharType;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_CHSUNICODE

void WideUpperCase(sb_char16_t &C);

void WideUpperCase(const sb_u16string &S, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideUpperCase(const std::wstring &S, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void WideTitleCase(sb_char16_t &C);

void WideTitleCase(const sb_u16string &S, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideTitleCase(const std::wstring &S, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

TPlCharType GetCharType(sb_char16_t C);

void WideLowerCase(sb_char16_t &C);

void WideLowerCase(const sb_u16string &S, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideLowerCase(const std::wstring &S, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void Normalize_NFD(const sb_u16string &AString, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void Normalize_NFD(const std::wstring &AString, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void Normalize_NFC(const sb_u16string &AString, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void Normalize_NFC(const std::wstring &AString, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void Normalize_NFKD(const sb_u16string &AString, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void Normalize_NFKD(const std::wstring &AString, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void Normalize_NFKC(const sb_u16string &AString, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void Normalize_NFKC(const std::wstring &AString, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void CheckProhibit(const sb_u16string &str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void CheckProhibit(const std::wstring &str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void CheckBidi(const sb_u16string &str, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void CheckBidi(const std::wstring &str, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

int32_t GetCharCode(const sb_u16string &InCh);
#ifdef SB_U16STRING_USED
int32_t GetCharCode(const std::wstring &InCh);
#endif /* SB_U16STRING_USED */

void GetCharValue(uint32_t Code, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void GetCharValue(uint32_t Code, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#endif /* SB_USE_GLOBAL_PROCS_CHSUNICODE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CHSUNICODE
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideUpperCase(sb_char16_t * C);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideUpperCase_1(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideTitleCase(sb_char16_t * C);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideTitleCase_1(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_GetCharType(sb_char16_t C, TPlCharTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideLowerCase(sb_char16_t * C);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_WideLowerCase_1(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_Normalize_NFD(const sb_char16_t * pcAString, int32_t szAString, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_Normalize_NFC(const sb_char16_t * pcAString, int32_t szAString, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_Normalize_NFKD(const sb_char16_t * pcAString, int32_t szAString, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_Normalize_NFKC(const sb_char16_t * pcAString, int32_t szAString, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_CheckProhibit(const sb_char16_t * pcstr, int32_t szstr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_CheckBidi(const sb_char16_t * pcstr, int32_t szstr, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_GetCharCode(const sb_char16_t * pcInCh, int32_t szInCh, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSUnicode_GetCharValue(uint32_t Code, sb_char16_t * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_CHSUNICODE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHSUNICODE */

