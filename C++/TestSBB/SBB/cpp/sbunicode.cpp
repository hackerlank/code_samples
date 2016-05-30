#include "sbunicode.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELUNICODECONVERTER

void TElUnicodeConverter::StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUnicodeConverter_StrToUtf8(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-762213990, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElUnicodeConverter::Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUnicodeConverter_Utf8ToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1966738762, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElUnicodeConverter::StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElUnicodeConverter_StrToWideStr(_Handle, Source.data(), (int32_t)Source.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1558532535, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElUnicodeConverter::WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElUnicodeConverter_WideStrToStr(_Handle, SB_STD_VECTOR_FRONT_ADR(Source), (int32_t)Source.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(825643561, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElUnicodeConverter::TElUnicodeConverter(TElUnicodeConverterHandle handle, TElOwnHandle ownHandle) : TElStringConverter(handle, ownHandle)
{
}

TElUnicodeConverter::TElUnicodeConverter() : TElStringConverter(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElUnicodeConverter_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELUNICODECONVERTER */

#ifdef SB_USE_GLOBAL_PROCS_UNICODE

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
SB_INLINE TElStringConverterHandle CreateUnicodeStringConverter()
{
	TElStringConverterHandle OutResult;
	SBCheckError(SBUnicode_CreateUnicodeStringConverter(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

#endif /* SB_USE_GLOBAL_PROCS_UNICODE */

};	/* namespace SecureBlackbox */

