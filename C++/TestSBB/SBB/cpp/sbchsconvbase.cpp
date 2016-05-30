#include "sbchsconvbase.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TPLCHARSET

bool TPlCharset::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlCharset_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlCharset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlCharset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlCharset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCharset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCharset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCharset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlCharset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlCharset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlCharset::ConvertBufferToUTF16(const void * SrcBuf, int32_t SrcCount, bool IsLastChunk, void * DstBuf, int32_t &DstCount)
{
	int32_t OutResult;
	SBCheckError(TPlCharset_ConvertBufferToUTF16(_Handle, SrcBuf, SrcCount, (int8_t)IsLastChunk, DstBuf, &DstCount, &OutResult));
	return OutResult;
}

void TPlCharset::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCharset_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-989605709, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCharset::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCharset_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1234696671, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlCharset::GetName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlCharset_GetName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1804787472, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlCharset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlCharset_ClassType(&OutResult));
	return OutResult;
}

TPlCharset::TPlCharset(TPlCharsetHandle handle, TElOwnHandle ownHandle) : TInterfacedObject(handle, ownHandle)
{
}

TPlCharset::TPlCharset() : TInterfacedObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlCharset_Create(&_Handle));
}

TPlCharset TPlCharset::CreateShift(int32_t Shift)
{
	TPlCharsetHandle _Handle;
	SBCheckError(TPlCharset_CreateShift(Shift, &_Handle));
	return TPlCharset(_Handle, SB_OWN_HANDLE);
}

TPlCharset TPlCharset::CreateNoInit()
{
	TPlCharsetHandle _Handle;
	SBCheckError(TPlCharset_CreateNoInit(&_Handle));
	return TPlCharset(_Handle, SB_OWN_HANDLE);
}

TPlCharset TPlCharset::CreateForFinalize()
{
	TPlCharsetHandle _Handle;
	SBCheckError(TPlCharset_CreateForFinalize(&_Handle));
	return TPlCharset(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLCHARSET */

#ifdef SB_USE_CLASS_TPLTABLECHARSET

bool TPlTableCharset::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlTableCharset_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlTableCharset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlTableCharset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlTableCharset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlTableCharset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlTableCharset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlTableCharset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlTableCharset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlTableCharset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlTableCharset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlTableCharset_ClassType(&OutResult));
	return OutResult;
}

TPlTableCharset::TPlTableCharset(TPlTableCharsetHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlTableCharset::TPlTableCharset() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlTableCharset_Create(&_Handle));
}

TPlTableCharset TPlTableCharset::CreateForFinalize()
{
	TPlTableCharsetHandle _Handle;
	SBCheckError(TPlTableCharset_CreateForFinalize(&_Handle));
	return TPlTableCharset(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLTABLECHARSET */

#ifdef SB_USE_CLASS_TPLMIXEDCHARSET

bool TPlMixedCharset::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlMixedCharset_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlMixedCharset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlMixedCharset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlMixedCharset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlMixedCharset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlMixedCharset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlMixedCharset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlMixedCharset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlMixedCharset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlMixedCharset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlMixedCharset_ClassType(&OutResult));
	return OutResult;
}

TPlMixedCharset::TPlMixedCharset(TPlMixedCharsetHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlMixedCharset::TPlMixedCharset() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlMixedCharset_Create(&_Handle));
}

TPlMixedCharset TPlMixedCharset::CreateShift(int32_t Shift)
{
	TPlMixedCharsetHandle _Handle;
	SBCheckError(TPlMixedCharset_CreateShift(Shift, &_Handle));
	return TPlMixedCharset(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLMIXEDCHARSET */

#ifdef SB_USE_CLASS_TPLCONVERTINGCHARSET

bool TPlConvertingCharset::CanConvert(uint32_t Char)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TPlConvertingCharset_CanConvert(_Handle, Char, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TPlConvertingCharset::ConvertFromUCS(uint32_t Char)
{
	int32_t OutResult;
	SBCheckError(TPlConvertingCharset_ConvertFromUCS(_Handle, Char, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TPlConvertingCharset::ConvertToUCS(TStream &Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlConvertingCharset_ConvertToUCS(_Handle, Stream.getHandle(), &Char, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TPlConvertingCharset::ConvertToUCS(TStream *Stream, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlConvertingCharset_ConvertToUCS(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &Char, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TPlConvertingCharset::ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char)
{
	int32_t OutResult;
	SBCheckError(TPlConvertingCharset_ConvertBufferToUCS(_Handle, Buf, Count, (int8_t)IsLastChunk, &Char, &OutResult));
	return OutResult;
}

SB_INLINE TClassHandle TPlConvertingCharset::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlConvertingCharset_ClassType(&OutResult));
	return OutResult;
}

TPlConvertingCharset::TPlConvertingCharset(TPlConvertingCharsetHandle handle, TElOwnHandle ownHandle) : TPlCharset(handle, ownHandle)
{
}

TPlConvertingCharset::TPlConvertingCharset() : TPlCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlConvertingCharset_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPLCONVERTINGCHARSET */

#ifdef SB_USE_CLASS_TPLASCII

void TPlASCII::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlASCII_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2090684966, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlASCII::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlASCII_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1255183235, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlASCII::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlASCII_ClassType(&OutResult));
	return OutResult;
}

TPlASCII::TPlASCII(TPlASCIIHandle handle, TElOwnHandle ownHandle) : TPlTableCharset(handle, ownHandle)
{
}

TPlASCII::TPlASCII() : TPlTableCharset(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlASCII_Create(&_Handle));
}

TPlASCII TPlASCII::CreateForFinalize()
{
	TPlASCIIHandle _Handle;
	SBCheckError(TPlASCII_CreateForFinalize(&_Handle));
	return TPlASCII(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLASCII */

#ifdef SB_USE_CLASS_TPLISO_8859_1

void TPlISO_8859_1::GetCategory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_1_GetCategory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(611523414, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TPlISO_8859_1::GetDescription(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPlISO_8859_1_GetDescription(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1167430327, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE TClassHandle TPlISO_8859_1::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TPlISO_8859_1_ClassType(&OutResult));
	return OutResult;
}

TPlISO_8859_1::TPlISO_8859_1(TPlISO_8859_1Handle handle, TElOwnHandle ownHandle) : TPlASCII(handle, ownHandle)
{
}

TPlISO_8859_1::TPlISO_8859_1() : TPlASCII(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPlISO_8859_1_Create(&_Handle));
}

TPlISO_8859_1 TPlISO_8859_1::CreateForFinalize()
{
	TPlISO_8859_1Handle _Handle;
	SBCheckError(TPlISO_8859_1_CreateForFinalize(&_Handle));
	return TPlISO_8859_1(_Handle, SB_OWN_HANDLE);
}

#endif /* SB_USE_CLASS_TPLISO_8859_1 */

#ifdef SB_USE_GLOBAL_PROCS_CHSCONVBASE

SB_INLINE void RegisterCharset(TPlCharsetClassHandle CharsetClass)
{
	SBCheckError(SBChSConvBase_RegisterCharset(CharsetClass));
}

SB_INLINE void UnregisterCharset(TPlCharsetClassHandle CharsetClass)
{
	SBCheckError(SBChSConvBase_UnregisterCharset(CharsetClass));
}

SB_INLINE void RegisterCharsetLibrary(void * RegistrationProc)
{
	SBCheckError(SBChSConvBase_RegisterCharsetLibrary(RegistrationProc));
}

SB_INLINE void AbstractError(const std::string &ClassName, const std::string &Method)
{
	SBCheckError(SBChSConvBase_AbstractError(ClassName.data(), (int32_t)ClassName.length(), Method.data(), (int32_t)Method.length()));
}

#endif /* SB_USE_GLOBAL_PROCS_CHSCONVBASE */

};	/* namespace SecureBlackbox */

