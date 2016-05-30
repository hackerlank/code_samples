#include "sbasutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ASUTILS

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t SBASUtils_CopyStream(TStream &Source, TStream &Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent)
{
	int64_t OutResult;
	SBCheckError(SBASUtils_CopyStream(Source.getHandle(), Dest.getHandle(), Offset, Count, (int8_t)PreservePosition, pMethodProgressEvent, pDataProgressEvent, &OutResult));
	return OutResult;
}
SB_INLINE int64_t SBASUtils_CopyStream(TStream *Source, TStream *Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent)
{
	int64_t OutResult;
	SBCheckError(SBASUtils_CopyStream((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, Offset, Count, (int8_t)PreservePosition, pMethodProgressEvent, pDataProgressEvent, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

void QuoteMessageID(const std::string &MessageID, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBASUtils_QuoteMessageID(MessageID.data(), (int32_t)MessageID.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-771850497, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void WriteField(TStream &Stream, const std::string &Name, const std::string &Value)
{
	SBCheckError(SBASUtils_WriteField(Stream.getHandle(), Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void WriteField(TStream *Stream, const std::string &Name, const std::string &Value)
{
	SBCheckError(SBASUtils_WriteField((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void WriteLineA(TStream &Stream, const std::string &Line)
{
	SBCheckError(SBASUtils_WriteLineA(Stream.getHandle(), Line.data(), (int32_t)Line.length()));
}
SB_INLINE void WriteLineA(TStream *Stream, const std::string &Line)
{
	SBCheckError(SBASUtils_WriteLineA((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Line.data(), (int32_t)Line.length()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void WriteLine(TStream &Stream, const sb_u16string &Line)
{
	SBCheckError(SBASUtils_WriteLine(Stream.getHandle(), Line.data(), (int32_t)Line.length()));
}
SB_INLINE void WriteLine(TStream *Stream, const sb_u16string &Line)
{
	SBCheckError(SBASUtils_WriteLine((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Line.data(), (int32_t)Line.length()));
}
#ifdef SB_U16STRING_USED
SB_INLINE void WriteLine(TStream &Stream, const std::wstring &Line)
{
	std::string u16Line;
	sb_to_u16string(Line, u16Line);
	SBCheckError(SBASUtils_WriteLine(Stream.getHandle(), reinterpret_cast<const sb_char16_t*>(u16Line.data()), (int32_t)u16Line.length() >> 1));
}
SB_INLINE void WriteLine(TStream *Stream, const std::wstring &Line)
{
	std::string u16Line;
	sb_to_u16string(Line, u16Line);
	SBCheckError(SBASUtils_WriteLine((Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16Line.data()), (int32_t)u16Line.length() >> 1));
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_ASUTILS */

};	/* namespace SecureBlackbox */

