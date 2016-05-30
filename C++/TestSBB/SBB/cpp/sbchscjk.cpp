#include "sbchscjk.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCUSTOMEUCCHARSET

SB_INLINE int32_t TPlCustomEUCCharset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomEUCCharset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlCustomEUCCharset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomEUCCharset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCustomEUCCharset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomEUCCharset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlCustomEUCCharset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomEUCCharset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlCustomEUCCharset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCustomEUCCharset_ClassType(&OutResult));
	return OutResult;
}

TPlCustomEUCCharset::TPlCustomEUCCharset(TPlCustomEUCCharsetHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlCustomEUCCharset::TPlCustomEUCCharset() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomEUCCharset_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCUSTOMEUCCHARSET */

#ifdef SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET

SB_INLINE int32_t TPlCustomISO_2022Charset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomISO_2022Charset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlCustomISO_2022Charset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomISO_2022Charset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCustomISO_2022Charset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomISO_2022Charset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlCustomISO_2022Charset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCustomISO_2022Charset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlCustomISO_2022Charset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCustomISO_2022Charset_ClassType(&OutResult));
	return OutResult;
}

TPlCustomISO_2022Charset::TPlCustomISO_2022Charset(TPlCustomISO_2022CharsetHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlCustomISO_2022Charset::TPlCustomISO_2022Charset() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCustomISO_2022Charset_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCUSTOMISO_2022CHARSET */

#ifdef SB_USE_CLASS_TPLSHIFTJISCODE

SB_INLINE TClassHandle TPlShiftJISCode::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlShiftJISCode_ClassType(&OutResult));
	return OutResult;
}

TPlShiftJISCode::TPlShiftJISCode(TPlShiftJISCodeHandle handle, TElOwnHandle ownHandle) : TPlConvertingCharset(handle, ownHandle)
{
}

TPlShiftJISCode::TPlShiftJISCode() : TPlConvertingCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlShiftJISCode_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLSHIFTJISCODE */

#ifdef SB_USE_CLASS_TPLSHIFTJIS

void TPlShiftJIS::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlShiftJIS_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2021332437, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlShiftJIS::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlShiftJIS_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1418163584, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlShiftJIS::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlShiftJIS_ClassType(&OutResult));
	return OutResult;
}

TPlShiftJIS::TPlShiftJIS(TPlShiftJISHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlShiftJIS::TPlShiftJIS() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlShiftJIS_Create(&_Handle));
}

TPlShiftJIS TPlShiftJIS::CreateShift(int32_t Shift)
{
	TPlShiftJISHandle _Handle;
	SBCheckError(TPlShiftJIS_CreateShift(Shift, &_Handle));
	return TPlShiftJIS(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLSHIFTJIS */

#ifdef SB_USE_CLASS_TPLEUC_JP

void TPlEUC_JP::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_JP_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(145377387, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlEUC_JP::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_JP_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(845665674, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlEUC_JP::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlEUC_JP_ClassType(&OutResult));
	return OutResult;
}

TPlEUC_JP::TPlEUC_JP(TPlEUC_JPHandle handle, TElOwnHandle ownHandle) : TPlCustomEUCCharset(handle, ownHandle)
{
}

TPlEUC_JP::TPlEUC_JP() : TPlCustomEUCCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlEUC_JP_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLEUC_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP

void TPlISO_2022_JP::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2114590763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_JP::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-557628445, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_JP::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_JP_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_JP::TPlISO_2022_JP(TPlISO_2022_JPHandle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_JP::TPlISO_2022_JP() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_JP_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_JP */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_1

void TPlISO_2022_JP_1::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_1_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1032701087, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_JP_1::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_1_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(498127468, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_JP_1::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_JP_1_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_JP_1::TPlISO_2022_JP_1(TPlISO_2022_JP_1Handle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_JP_1::TPlISO_2022_JP_1() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_JP_1_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_JP_1 */

#ifdef SB_USE_CLASS_TPLISO_2022_JP_2

void TPlISO_2022_JP_2::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_2_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1453678131, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_JP_2::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_JP_2_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(341198906, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_JP_2::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_JP_2_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_JP_2::TPlISO_2022_JP_2(TPlISO_2022_JP_2Handle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_JP_2::TPlISO_2022_JP_2() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_JP_2_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_JP_2 */

#ifdef SB_USE_CLASS_TPLGBK

void TPlGBK::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGBK_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1635215067, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlGBK::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGBK_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1518437264, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlGBK::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGBK_ClassType(&OutResult));
	return OutResult;
}

TPlGBK::TPlGBK(TPlGBKHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlGBK::TPlGBK() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGBK_Create(&_Handle));
}

TPlGBK TPlGBK::CreateShift(int32_t Shift)
{
	TPlGBKHandle _Handle;
	SBCheckError(TPlGBK_CreateShift(Shift, &_Handle));
	return TPlGBK(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGBK */

#ifdef SB_USE_CLASS_TPLHZ_GB_2312

void TPlHZ_GB_2312::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlHZ_GB_2312_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1509144479, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlHZ_GB_2312::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlHZ_GB_2312_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1627282882, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TPlHZ_GB_2312::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlHZ_GB_2312_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlHZ_GB_2312::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlHZ_GB_2312_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlHZ_GB_2312::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlHZ_GB_2312_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlHZ_GB_2312::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlHZ_GB_2312_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlHZ_GB_2312::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlHZ_GB_2312_ClassType(&OutResult));
	return OutResult;
}

TPlHZ_GB_2312::TPlHZ_GB_2312(TPlHZ_GB_2312Handle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlHZ_GB_2312::TPlHZ_GB_2312() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlHZ_GB_2312_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLHZ_GB_2312 */

#ifdef SB_USE_CLASS_TPLGB_18030CODE

bool TPlGB_18030Code::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlGB_18030Code_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlGB_18030Code::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlGB_18030Code_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlGB_18030Code::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlGB_18030Code_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlGB_18030Code::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlGB_18030Code_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlGB_18030Code::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlGB_18030Code_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlGB_18030Code::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGB_18030Code_ClassType(&OutResult));
	return OutResult;
}

TPlGB_18030Code::TPlGB_18030Code(TPlGB_18030CodeHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlGB_18030Code::TPlGB_18030Code() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGB_18030Code_Create(&_Handle));
}

TPlGB_18030Code TPlGB_18030Code::CreateShift(int32_t Shift)
{
	TPlGB_18030CodeHandle _Handle;
	SBCheckError(TPlGB_18030Code_CreateShift(Shift, &_Handle));
	return TPlGB_18030Code(_Handle, SB_OWN_HANDLE);
}

TPlGB_18030Code TPlGB_18030Code::CreateNoInit()
{
	TPlGB_18030CodeHandle _Handle;
	SBCheckError(TPlGB_18030Code_CreateNoInit(&_Handle));
	return TPlGB_18030Code(_Handle, SB_OWN_HANDLE);
}

TPlGB_18030Code TPlGB_18030Code::CreateForFinalize()
{
	TPlGB_18030CodeHandle _Handle;
	SBCheckError(TPlGB_18030Code_CreateForFinalize(&_Handle));
	return TPlGB_18030Code(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGB_18030CODE */

#ifdef SB_USE_CLASS_TPLGB_18030

void TPlGB_18030::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGB_18030_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-250530226, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlGB_18030::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlGB_18030_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2140005922, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlGB_18030::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlGB_18030_ClassType(&OutResult));
	return OutResult;
}

TPlGB_18030::TPlGB_18030(TPlGB_18030Handle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlGB_18030::TPlGB_18030() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlGB_18030_Create(&_Handle));
}

TPlGB_18030 TPlGB_18030::CreateShift(int32_t Shift)
{
	TPlGB_18030Handle _Handle;
	SBCheckError(TPlGB_18030_CreateShift(Shift, &_Handle));
	return TPlGB_18030(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLGB_18030 */

#ifdef SB_USE_CLASS_TPLISO_2022_CN

void TPlISO_2022_CN::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_CN_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1616119629, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_CN::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_CN_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-994412746, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_CN::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_CN_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_CN::TPlISO_2022_CN(TPlISO_2022_CNHandle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_CN::TPlISO_2022_CN() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_CN_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_CN */

#ifdef SB_USE_CLASS_TPLISO_2022_CN_EXT

void TPlISO_2022_CN_EXT::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_CN_EXT_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-351609082, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_CN_EXT::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_CN_EXT_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1003365846, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_CN_EXT::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_CN_EXT_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_CN_EXT::TPlISO_2022_CN_EXT(TPlISO_2022_CN_EXTHandle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_CN_EXT::TPlISO_2022_CN_EXT() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_CN_EXT_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_CN_EXT */

#ifdef SB_USE_CLASS_TPLBIGFIVEHKSCS

void TPlBigFiveHKSCS::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlBigFiveHKSCS_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(937782763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlBigFiveHKSCS::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlBigFiveHKSCS_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(656494424, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlBigFiveHKSCS::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlBigFiveHKSCS_ClassType(&OutResult));
	return OutResult;
}

TPlBigFiveHKSCS::TPlBigFiveHKSCS(TPlBigFiveHKSCSHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlBigFiveHKSCS::TPlBigFiveHKSCS() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlBigFiveHKSCS_Create(&_Handle));
}

TPlBigFiveHKSCS TPlBigFiveHKSCS::CreateShift(int32_t Shift)
{
	TPlBigFiveHKSCSHandle _Handle;
	SBCheckError(TPlBigFiveHKSCS_CreateShift(Shift, &_Handle));
	return TPlBigFiveHKSCS(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLBIGFIVEHKSCS */

#ifdef SB_USE_CLASS_TPLCP950

void TPlCP950::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP950_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1097557876, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP950::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP950_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(639064894, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP950::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP950_ClassType(&OutResult));
	return OutResult;
}

TPlCP950::TPlCP950(TPlCP950Handle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlCP950::TPlCP950() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP950_Create(&_Handle));
}

TPlCP950 TPlCP950::CreateShift(int32_t Shift)
{
	TPlCP950Handle _Handle;
	SBCheckError(TPlCP950_CreateShift(Shift, &_Handle));
	return TPlCP950(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP950 */

#ifdef SB_USE_CLASS_TPLCNS_11643

SB_INLINE int32_t TPlCNS_11643::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlCNS_11643_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlCNS_11643::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCNS_11643_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCNS_11643::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCNS_11643_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlCNS_11643::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCNS_11643_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlCNS_11643::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCNS_11643_ClassType(&OutResult));
	return OutResult;
}

TPlCNS_11643::TPlCNS_11643(TPlCNS_11643Handle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlCNS_11643::TPlCNS_11643() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCNS_11643_Create(&_Handle));
}

TPlCNS_11643 TPlCNS_11643::CreateShift(int32_t Shift)
{
	TPlCNS_11643Handle _Handle;
	SBCheckError(TPlCNS_11643_CreateShift(Shift, &_Handle));
	return TPlCNS_11643(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCNS_11643 */

#ifdef SB_USE_CLASS_TPLEUC_TW

void TPlEUC_TW::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_TW_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2076957903, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlEUC_TW::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_TW_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1523583355, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlEUC_TW::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlEUC_TW_ClassType(&OutResult));
	return OutResult;
}

TPlEUC_TW::TPlEUC_TW(TPlEUC_TWHandle handle, TElOwnHandle ownHandle) : TPlCustomEUCCharset(handle, ownHandle)
{
}

TPlEUC_TW::TPlEUC_TW() : TPlCustomEUCCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlEUC_TW_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLEUC_TW */

#ifdef SB_USE_CLASS_TPLCP949

void TPlCP949::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP949_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2143405180, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCP949::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCP949_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(50907790, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCP949::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCP949_ClassType(&OutResult));
	return OutResult;
}

TPlCP949::TPlCP949(TPlCP949Handle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlCP949::TPlCP949() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCP949_Create(&_Handle));
}

TPlCP949 TPlCP949::CreateShift(int32_t Shift)
{
	TPlCP949Handle _Handle;
	SBCheckError(TPlCP949_CreateShift(Shift, &_Handle));
	return TPlCP949(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCP949 */

#ifdef SB_USE_CLASS_TPLJOHABHANGUL

bool TPlJohabHangul::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlJohabHangul_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlJohabHangul::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlJohabHangul_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlJohabHangul::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlJohabHangul_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlJohabHangul::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlJohabHangul_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlJohabHangul::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlJohabHangul_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlJohabHangul::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJohabHangul_ClassType(&OutResult));
	return OutResult;
}

TPlJohabHangul::TPlJohabHangul(TPlJohabHangulHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlJohabHangul::TPlJohabHangul() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJohabHangul_Create(&_Handle));
}

TPlJohabHangul TPlJohabHangul::CreateShift(int32_t Shift)
{
	TPlJohabHangulHandle _Handle;
	SBCheckError(TPlJohabHangul_CreateShift(Shift, &_Handle));
	return TPlJohabHangul(_Handle, SB_OWN_HANDLE);
}

TPlJohabHangul TPlJohabHangul::CreateNoInit()
{
	TPlJohabHangulHandle _Handle;
	SBCheckError(TPlJohabHangul_CreateNoInit(&_Handle));
	return TPlJohabHangul(_Handle, SB_OWN_HANDLE);
}

TPlJohabHangul TPlJohabHangul::CreateForFinalize()
{
	TPlJohabHangulHandle _Handle;
	SBCheckError(TPlJohabHangul_CreateForFinalize(&_Handle));
	return TPlJohabHangul(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLJOHABHANGUL */

#ifdef SB_USE_CLASS_TPLJOHABNONHANGUL

SB_INLINE TClassHandle TPlJohabNonHangul::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJohabNonHangul_ClassType(&OutResult));
	return OutResult;
}

TPlJohabNonHangul::TPlJohabNonHangul(TPlJohabNonHangulHandle handle, TElOwnHandle ownHandle) : TPlConvertingCharset(handle, ownHandle)
{
}

TPlJohabNonHangul::TPlJohabNonHangul() : TPlConvertingCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJohabNonHangul_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLJOHABNONHANGUL */

#ifdef SB_USE_CLASS_TPLJOHAB

void TPlJohab::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlJohab_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(264728573, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlJohab::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlJohab_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1787364690, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlJohab::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlJohab_ClassType(&OutResult));
	return OutResult;
}

TPlJohab::TPlJohab(TPlJohabHandle handle, TElOwnHandle ownHandle) : TPlMixedCharset(handle, ownHandle)
{
}

TPlJohab::TPlJohab() : TPlMixedCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlJohab_Create(&_Handle));
}

TPlJohab TPlJohab::CreateShift(int32_t Shift)
{
	TPlJohabHandle _Handle;
	SBCheckError(TPlJohab_CreateShift(Shift, &_Handle));
	return TPlJohab(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLJOHAB */

#ifdef SB_USE_CLASS_TPLEUC_KR

void TPlEUC_KR::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_KR_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1080182059, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlEUC_KR::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlEUC_KR_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1423132429, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlEUC_KR::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlEUC_KR_ClassType(&OutResult));
	return OutResult;
}

TPlEUC_KR::TPlEUC_KR(TPlEUC_KRHandle handle, TElOwnHandle ownHandle) : TPlCustomEUCCharset(handle, ownHandle)
{
}

TPlEUC_KR::TPlEUC_KR() : TPlCustomEUCCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlEUC_KR_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLEUC_KR */

#ifdef SB_USE_CLASS_TPLISO_2022_KR

void TPlISO_2022_KR::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_KR_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2113002022, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_2022_KR::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_2022_KR_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(830471583, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_2022_KR::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_2022_KR_ClassType(&OutResult));
	return OutResult;
}

TPlISO_2022_KR::TPlISO_2022_KR(TPlISO_2022_KRHandle handle, TElOwnHandle ownHandle) : TPlCustomISO_2022Charset(handle, ownHandle)
{
}

TPlISO_2022_KR::TPlISO_2022_KR() : TPlCustomISO_2022Charset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_2022_KR_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLISO_2022_KR */

};	/* namespace SecureBlackbox */

