#ifndef __INC_SBCHSCONVCONSTS
#define __INC_SBCHSCONVCONSTS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SEncodingError 	"%s ecoding error: %s"
#define SB_SDecodingError 	"%s decoding error: %s"
#define SB_SIllegalCharacter 	"Illegal character"
#define SB_SUnicodeCategory 	"Unicode"
#define SB_SArabicCategory 	"Arabic"
#define SB_SBalticCategory 	"Baltic"
#define SB_SCelticCategory 	"Celtic"
#define SB_SCyrillicCategory 	"Cyrillic"
#define SB_SGreekCategory 	"Greek"
#define SB_SHebrewCategory 	"Hebrew"
#define SB_SNordicCategory 	"Nordic"
#define SB_SIcelandicCategory 	"Icelandic"
#define SB_STurkishCategory 	"Turkish"
#define SB_SRomanianCategory 	"Romanian"
#define SB_SVietnameseCategory 	"Vietnamese"
#define SB_SGeorgianCategory 	"Georgian"
#define SB_SArmenianCategory 	"Armenian"
#define SB_STajikCategory 	"Tajik"
#define SB_SThaiCategory 	"Thai"
#define SB_SUSCategory 	"United States"
#define SB_SCentralEuropeanCategory 	"Central European"
#define SB_SSouthEuropeanCategory 	"South European"
#define SB_SWesternEuropeanCategory 	"Western European"
#define SB_SChineseCategory 	"Chinese"
#define SB_SJapaneseCategory 	"Japanese"
#define SB_SKoreanCategory 	"Korean"
#define SB_SUTF32 	"Unicode (UTF-32)"
#define SB_SUTF32BE 	"Unicode (UTF-32 Big Endian)"
#define SB_SUTF16 	"Unicode (UTF-16)"
#define SB_SUTF16BE 	"Unicode (UTF-16 Big Endian)"
#define SB_SUTF8 	"Unicode (UTF-8)"
#define SB_SUTF7 	"Unicode (UTF-7)"
#define SB_SUS_ASCII 	"US-ASCII (7 bit)"
#define SB_SISO_8859_1 	"Western European (ISO-8859-1)"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHSCONVCONSTS */

