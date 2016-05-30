#ifndef __INC_SBUNICODE
#define __INC_SBUNICODE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
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
typedef TElClassHandle TElUnicodeConverterHandle;

#ifdef SB_USE_CLASS_TELUNICODECONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElUnicodeConverter_StrToUtf8(TElUnicodeConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnicodeConverter_Utf8ToStr(TElUnicodeConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnicodeConverter_StrToWideStr(TElUnicodeConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnicodeConverter_WideStrToStr(TElUnicodeConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUnicodeConverter_Create(TElUnicodeConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELUNICODECONVERTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElUnicodeConverter;

#ifdef SB_USE_CLASS_TELUNICODECONVERTER
class TElUnicodeConverter: public TElStringConverter
{
	private:
		SB_DISABLE_COPY(TElUnicodeConverter)
	public:
		virtual void StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		virtual void StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		TElUnicodeConverter(TElUnicodeConverterHandle handle, TElOwnHandle ownHandle);

		TElUnicodeConverter();

};
#endif /* SB_USE_CLASS_TELUNICODECONVERTER */

#ifdef SB_USE_GLOBAL_PROCS_UNICODE

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
TElStringConverterHandle CreateUnicodeStringConverter();
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

#endif /* SB_USE_GLOBAL_PROCS_UNICODE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_UNICODE
SB_IMPORT uint32_t SB_APIENTRY SBUnicode_CreateUnicodeStringConverter(TElStringConverterHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_UNICODE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBUNICODE */

