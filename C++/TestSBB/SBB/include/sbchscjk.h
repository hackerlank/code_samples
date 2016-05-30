#ifndef __INC_SBCHSCJK
#define __INC_SBCHSCJK

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbchsconvbase.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SShiftJIS 	"Japanese (Shift-JIS)"
#define SB_SEUC_JP 	"Japanese (EUC)"
#define SB_SISO_2022_JP 	"Japanese (ISO-2022-JP)"
#define SB_SISO_2022_JP_1 	"Japanese (ISO-2022-JP-1)"
#define SB_SISO_2022_JP_2 	"Japanese (ISO-2022-JP-2)"
#define SB_SGBK 	"Chinese Simplified (GBK/GB2312)"
#define SB_SHZ_GB_2312 	"Chinese Simplified (HZ-GB2312)"
#define SB_SGB_18030 	"Chinese Simplified (GB-18030)"
#define SB_SISO_2022_CN 	"Chinese Simplified (ISO-2022-CN)"
#define SB_SISO_2022_CN_EXT 	"Chinese Simplified (ISO-2022-CN-EXT)"
#define SB_SBigFiveHKSCS 	"Chinese Traditional (Big5 HKSCS)"
#define SB_SCP950 	"Chinese Traditional (Windows-950)"
#define SB_SEUC_TW 	"Chinese Traditional (EUC-TW)"
#define SB_SCP949 	"Korean (CP949)"
#define SB_SJohab 	"Korean (Johab)"
#define SB_SEUC_KR 	"Korean (EUC)"
#define SB_SISO_2022_KR 	"Korean (ISO-2022-KR)"

typedef TElClassHandle TPlCustomEUCCharsetHandle;

typedef TElClassHandle TPlCustomISO_2022CharsetHandle;

typedef TElClassHandle TPlShiftJISCodeHandle;

typedef TElClassHandle TPlShiftJISHandle;

typedef TElClassHandle TPlEUC_JPHandle;

typedef TElClassHandle TPlISO_2022_JPHandle;

typedef TElClassHandle TPlISO_2022_JP_1Handle;

typedef TElClassHandle TPlISO_2022_JP_2Handle;

typedef TElClassHandle TPlGBKHandle;

typedef TElClassHandle TPlHZ_GB_2312Handle;

typedef TElClassHandle TPlGB_18030CodeHandle;

typedef TElClassHandle TPlGB_18030Handle;

typedef TElClassHandle TPlISO_2022_CNHandle;

typedef TElClassHandle TPlISO_2022_CN_EXTHandle;

typedef TElClassHandle TPlBigFiveHKSCSHandle;

typedef TElClassHandle TPlCP950Handle;

typedef TElClassHandle TPlCNS_11643Handle;

typedef TElClassHandle TPlEUC_TWHandle;

typedef TElClassHandle TPlCP949Handle;

typedef TElClassHandle TPlJohabHangulHandle;

typedef TElClassHandle TPlJohabNonHangulHandle;

typedef TElClassHandle TPlJohabHandle;

typedef TElClassHandle TPlEUC_KRHandle;

typedef TElClassHandle TPlISO_2022_KRHandle;

#ifdef SB_USE_CLASS_TPLCUSTOMEUCCHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlCustomEUCCharset_ConvertFromUCS(TPlCustomEUCCharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomEUCCharset_ConvertToUCS(TPlCustomEUCCharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomEUCCharset_ConvertBufferToUCS(TPlCustomEUCCharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomEUCCharset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomEUCCharset_Create(TPlCustomEUCCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMEUCCHARSET */

#ifdef SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET
SB_IMPORT uint32_t SB_APIENTRY TPlCustomISO_2022Charset_ConvertFromUCS(TPlCustomISO_2022CharsetHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomISO_2022Charset_ConvertToUCS(TPlCustomISO_2022CharsetHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomISO_2022Charset_ConvertBufferToUCS(TPlCustomISO_2022CharsetHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomISO_2022Charset_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomISO_2022Charset_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET */

#ifdef SB_USE_CLASS_TPLSHIFTJISCODE
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJISCode_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJISCode_Create(TPlConvertingCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLSHIFTJISCODE */

#ifdef SB_USE_CLASS_TPLSHIFTJIS
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJIS_GetCategory(TPlShiftJISHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJIS_GetDescription(TPlShiftJISHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJIS_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJIS_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlShiftJIS_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLSHIFTJIS */

#ifdef SB_USE_CLASS_TPLEUC_JP
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_JP_GetCategory(TPlEUC_JPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_JP_GetDescription(TPlEUC_JPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_JP_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_JP_Create(TPlCustomEUCCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLEUC_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_GetCategory(TPlISO_2022_JPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_GetDescription(TPlISO_2022_JPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_1
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_1_GetCategory(TPlISO_2022_JP_1Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_1_GetDescription(TPlISO_2022_JP_1Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_1_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_1_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_JP_1 */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_2
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_2_GetCategory(TPlISO_2022_JP_2Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_2_GetDescription(TPlISO_2022_JP_2Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_2_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_JP_2_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_JP_2 */

#ifdef SB_USE_CLASS_TPLGBK
SB_IMPORT uint32_t SB_APIENTRY TPlGBK_GetCategory(TPlGBKHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBK_GetDescription(TPlGBKHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBK_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBK_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGBK_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGBK */

#ifdef SB_USE_CLASS_TPLHZ_GB_2312
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_GetCategory(TPlHZ_GB_2312Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_GetDescription(TPlHZ_GB_2312Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_ConvertFromUCS(TPlHZ_GB_2312Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_ConvertToUCS(TPlHZ_GB_2312Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_ConvertBufferToUCS(TPlHZ_GB_2312Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlHZ_GB_2312_Create(TPlHZ_GB_2312Handle * OutResult);
#endif /* SB_USE_CLASS_TPLHZ_GB_2312 */

#ifdef SB_USE_CLASS_TPLGB_18030CODE
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_CanConvert(TPlGB_18030CodeHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_ConvertFromUCS(TPlGB_18030CodeHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_ConvertToUCS(TPlGB_18030CodeHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_ConvertBufferToUCS(TPlGB_18030CodeHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030Code_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGB_18030CODE */

#ifdef SB_USE_CLASS_TPLGB_18030
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030_GetCategory(TPlGB_18030Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030_GetDescription(TPlGB_18030Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlGB_18030_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLGB_18030 */

#ifdef SB_USE_CLASS_TPLISO_2022_CN
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_GetCategory(TPlISO_2022_CNHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_GetDescription(TPlISO_2022_CNHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_CN */

#ifdef SB_USE_CLASS_TPLISO_2022_CN_EXT
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_EXT_GetCategory(TPlISO_2022_CN_EXTHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_EXT_GetDescription(TPlISO_2022_CN_EXTHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_EXT_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_CN_EXT_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_CN_EXT */

#ifdef SB_USE_CLASS_TPLBIGFIVEHKSCS
SB_IMPORT uint32_t SB_APIENTRY TPlBigFiveHKSCS_GetCategory(TPlBigFiveHKSCSHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFiveHKSCS_GetDescription(TPlBigFiveHKSCSHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFiveHKSCS_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFiveHKSCS_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlBigFiveHKSCS_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLBIGFIVEHKSCS */

#ifdef SB_USE_CLASS_TPLCP950
SB_IMPORT uint32_t SB_APIENTRY TPlCP950_GetCategory(TPlCP950Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950_GetDescription(TPlCP950Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP950_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP950 */

#ifdef SB_USE_CLASS_TPLCNS_11643
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_ConvertFromUCS(TPlCNS_11643Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_ConvertToUCS(TPlCNS_11643Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_ConvertBufferToUCS(TPlCNS_11643Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCNS_11643_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCNS_11643 */

#ifdef SB_USE_CLASS_TPLEUC_TW
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_TW_GetCategory(TPlEUC_TWHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_TW_GetDescription(TPlEUC_TWHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_TW_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_TW_Create(TPlCustomEUCCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLEUC_TW */

#ifdef SB_USE_CLASS_TPLCP949
SB_IMPORT uint32_t SB_APIENTRY TPlCP949_GetCategory(TPlCP949Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP949_GetDescription(TPlCP949Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP949_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP949_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCP949_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCP949 */

#ifdef SB_USE_CLASS_TPLJOHABHANGUL
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_CanConvert(TPlJohabHangulHandle _Handle, uint32_t Char, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_ConvertFromUCS(TPlJohabHangulHandle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_ConvertToUCS(TPlJohabHangulHandle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_ConvertBufferToUCS(TPlJohabHangulHandle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabHangul_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJOHABHANGUL */

#ifdef SB_USE_CLASS_TPLJOHABNONHANGUL
SB_IMPORT uint32_t SB_APIENTRY TPlJohabNonHangul_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohabNonHangul_Create(TPlConvertingCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJOHABNONHANGUL */

#ifdef SB_USE_CLASS_TPLJOHAB
SB_IMPORT uint32_t SB_APIENTRY TPlJohab_GetCategory(TPlJohabHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohab_GetDescription(TPlJohabHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohab_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohab_Create(TPlMixedCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlJohab_CreateShift(int32_t Shift, TPlMixedCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLJOHAB */

#ifdef SB_USE_CLASS_TPLEUC_KR
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_KR_GetCategory(TPlEUC_KRHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_KR_GetDescription(TPlEUC_KRHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_KR_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlEUC_KR_Create(TPlCustomEUCCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLEUC_KR */

#ifdef SB_USE_CLASS_TPLISO_2022_KR
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_KR_GetCategory(TPlISO_2022_KRHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_KR_GetDescription(TPlISO_2022_KRHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_KR_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlISO_2022_KR_Create(TPlCustomISO_2022CharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLISO_2022_KR */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlCustomEUCCharset;
class TPlCustomISO_2022Charset;
class TPlShiftJISCode;
class TPlShiftJIS;
class TPlEUC_JP;
class TPlISO_2022_JP;
class TPlISO_2022_JP_1;
class TPlISO_2022_JP_2;
class TPlGBK;
class TPlHZ_GB_2312;
class TPlGB_18030Code;
class TPlGB_18030;
class TPlISO_2022_CN;
class TPlISO_2022_CN_EXT;
class TPlBigFiveHKSCS;
class TPlCP950;
class TPlCNS_11643;
class TPlEUC_TW;
class TPlCP949;
class TPlJohabHangul;
class TPlJohabNonHangul;
class TPlJohab;
class TPlEUC_KR;
class TPlISO_2022_KR;

#ifdef SB_USE_CLASS_TPLCUSTOMEUCCHARSET
class TPlCustomEUCCharset: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlCustomEUCCharset)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlCustomEUCCharset(TPlCustomEUCCharsetHandle handle, TElOwnHandle ownHandle);

		TPlCustomEUCCharset();

};
#endif /* SB_USE_CLASS_TPLCUSTOMEUCCHARSET */

#ifdef SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET
class TPlCustomISO_2022Charset: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlCustomISO_2022Charset)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlCustomISO_2022Charset(TPlCustomISO_2022CharsetHandle handle, TElOwnHandle ownHandle);

		TPlCustomISO_2022Charset();

};
#endif /* SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET */

#ifdef SB_USE_CLASS_TPLSHIFTJISCODE
class TPlShiftJISCode: public TPlConvertingCharset
{
	private:
		SB_DISABLE_COPY(TPlShiftJISCode)
	public:
		static TClassHandle ClassType();

		TPlShiftJISCode(TPlShiftJISCodeHandle handle, TElOwnHandle ownHandle);

		TPlShiftJISCode();

};
#endif /* SB_USE_CLASS_TPLSHIFTJISCODE */

#ifdef SB_USE_CLASS_TPLSHIFTJIS
class TPlShiftJIS: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlShiftJIS)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlShiftJIS(TPlShiftJISHandle handle, TElOwnHandle ownHandle);

		TPlShiftJIS();

		static TPlShiftJIS CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLSHIFTJIS */

#ifdef SB_USE_CLASS_TPLEUC_JP
class TPlEUC_JP: public TPlCustomEUCCharset
{
	private:
		SB_DISABLE_COPY(TPlEUC_JP)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlEUC_JP(TPlEUC_JPHandle handle, TElOwnHandle ownHandle);

		TPlEUC_JP();

};
#endif /* SB_USE_CLASS_TPLEUC_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP
class TPlISO_2022_JP: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_JP)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_JP(TPlISO_2022_JPHandle handle, TElOwnHandle ownHandle);

		TPlISO_2022_JP();

};
#endif /* SB_USE_CLASS_TPLISO_2022_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_1
class TPlISO_2022_JP_1: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_JP_1)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_JP_1(TPlISO_2022_JP_1Handle handle, TElOwnHandle ownHandle);

		TPlISO_2022_JP_1();

};
#endif /* SB_USE_CLASS_TPLISO_2022_JP_1 */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_2
class TPlISO_2022_JP_2: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_JP_2)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_JP_2(TPlISO_2022_JP_2Handle handle, TElOwnHandle ownHandle);

		TPlISO_2022_JP_2();

};
#endif /* SB_USE_CLASS_TPLISO_2022_JP_2 */

#ifdef SB_USE_CLASS_TPLGBK
class TPlGBK: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlGBK)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlGBK(TPlGBKHandle handle, TElOwnHandle ownHandle);

		TPlGBK();

		static TPlGBK CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLGBK */

#ifdef SB_USE_CLASS_TPLHZ_GB_2312
class TPlHZ_GB_2312: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlHZ_GB_2312)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlHZ_GB_2312(TPlHZ_GB_2312Handle handle, TElOwnHandle ownHandle);

		TPlHZ_GB_2312();

};
#endif /* SB_USE_CLASS_TPLHZ_GB_2312 */

#ifdef SB_USE_CLASS_TPLGB_18030CODE
class TPlGB_18030Code: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlGB_18030Code)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlGB_18030Code(TPlGB_18030CodeHandle handle, TElOwnHandle ownHandle);

		TPlGB_18030Code();

		static TPlGB_18030Code CreateShift(int32_t Shift);

		static TPlGB_18030Code CreateNoInit();

		static TPlGB_18030Code CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLGB_18030CODE */

#ifdef SB_USE_CLASS_TPLGB_18030
class TPlGB_18030: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlGB_18030)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlGB_18030(TPlGB_18030Handle handle, TElOwnHandle ownHandle);

		TPlGB_18030();

		static TPlGB_18030 CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLGB_18030 */

#ifdef SB_USE_CLASS_TPLISO_2022_CN
class TPlISO_2022_CN: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_CN)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_CN(TPlISO_2022_CNHandle handle, TElOwnHandle ownHandle);

		TPlISO_2022_CN();

};
#endif /* SB_USE_CLASS_TPLISO_2022_CN */

#ifdef SB_USE_CLASS_TPLISO_2022_CN_EXT
class TPlISO_2022_CN_EXT: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_CN_EXT)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_CN_EXT(TPlISO_2022_CN_EXTHandle handle, TElOwnHandle ownHandle);

		TPlISO_2022_CN_EXT();

};
#endif /* SB_USE_CLASS_TPLISO_2022_CN_EXT */

#ifdef SB_USE_CLASS_TPLBIGFIVEHKSCS
class TPlBigFiveHKSCS: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlBigFiveHKSCS)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlBigFiveHKSCS(TPlBigFiveHKSCSHandle handle, TElOwnHandle ownHandle);

		TPlBigFiveHKSCS();

		static TPlBigFiveHKSCS CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLBIGFIVEHKSCS */

#ifdef SB_USE_CLASS_TPLCP950
class TPlCP950: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlCP950)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP950(TPlCP950Handle handle, TElOwnHandle ownHandle);

		TPlCP950();

		static TPlCP950 CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLCP950 */

#ifdef SB_USE_CLASS_TPLCNS_11643
class TPlCNS_11643: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlCNS_11643)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlCNS_11643(TPlCNS_11643Handle handle, TElOwnHandle ownHandle);

		TPlCNS_11643();

		static TPlCNS_11643 CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLCNS_11643 */

#ifdef SB_USE_CLASS_TPLEUC_TW
class TPlEUC_TW: public TPlCustomEUCCharset
{
	private:
		SB_DISABLE_COPY(TPlEUC_TW)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlEUC_TW(TPlEUC_TWHandle handle, TElOwnHandle ownHandle);

		TPlEUC_TW();

};
#endif /* SB_USE_CLASS_TPLEUC_TW */

#ifdef SB_USE_CLASS_TPLCP949
class TPlCP949: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlCP949)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCP949(TPlCP949Handle handle, TElOwnHandle ownHandle);

		TPlCP949();

		static TPlCP949 CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLCP949 */

#ifdef SB_USE_CLASS_TPLJOHABHANGUL
class TPlJohabHangul: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlJohabHangul)
	public:
		virtual bool CanConvert(uint32_t Char);

		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlJohabHangul(TPlJohabHangulHandle handle, TElOwnHandle ownHandle);

		TPlJohabHangul();

		static TPlJohabHangul CreateShift(int32_t Shift);

		static TPlJohabHangul CreateNoInit();

		static TPlJohabHangul CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLJOHABHANGUL */

#ifdef SB_USE_CLASS_TPLJOHABNONHANGUL
class TPlJohabNonHangul: public TPlConvertingCharset
{
	private:
		SB_DISABLE_COPY(TPlJohabNonHangul)
	public:
		static TClassHandle ClassType();

		TPlJohabNonHangul(TPlJohabNonHangulHandle handle, TElOwnHandle ownHandle);

		TPlJohabNonHangul();

};
#endif /* SB_USE_CLASS_TPLJOHABNONHANGUL */

#ifdef SB_USE_CLASS_TPLJOHAB
class TPlJohab: public TPlMixedCharset
{
	private:
		SB_DISABLE_COPY(TPlJohab)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlJohab(TPlJohabHandle handle, TElOwnHandle ownHandle);

		TPlJohab();

		static TPlJohab CreateShift(int32_t Shift);

};
#endif /* SB_USE_CLASS_TPLJOHAB */

#ifdef SB_USE_CLASS_TPLEUC_KR
class TPlEUC_KR: public TPlCustomEUCCharset
{
	private:
		SB_DISABLE_COPY(TPlEUC_KR)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlEUC_KR(TPlEUC_KRHandle handle, TElOwnHandle ownHandle);

		TPlEUC_KR();

};
#endif /* SB_USE_CLASS_TPLEUC_KR */

#ifdef SB_USE_CLASS_TPLISO_2022_KR
class TPlISO_2022_KR: public TPlCustomISO_2022Charset
{
	private:
		SB_DISABLE_COPY(TPlISO_2022_KR)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlISO_2022_KR(TPlISO_2022_KRHandle handle, TElOwnHandle ownHandle);

		TPlISO_2022_KR();

};
#endif /* SB_USE_CLASS_TPLISO_2022_KR */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHSCJK */

