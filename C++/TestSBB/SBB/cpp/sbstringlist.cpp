#include "sbstringlist.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSTRINGTOKENIZER

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE TStringListHandle TElStringTokenizer::GetAll()
{
	TStringListHandle OutResult;
	SBCheckError(TElStringTokenizer_GetAll(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE TElStringListHandle TElStringTokenizer::GetAll()
{
	TElStringListHandle OutResult;
	SBCheckError(TElStringTokenizer_GetAll(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
SB_INLINE void TElStringTokenizer::GetAll(TStringList &ResultList)
{
	SBCheckError(TElStringTokenizer_GetAll_1(_Handle, ResultList.getHandle()));
}

SB_INLINE void TElStringTokenizer::GetAll(TStringList *ResultList)
{
	SBCheckError(TElStringTokenizer_GetAll_1(_Handle, (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
SB_INLINE void TElStringTokenizer::GetAll(TElStringList &ResultList)
{
	SBCheckError(TElStringTokenizer_GetAll_1(_Handle, ResultList.getHandle()));
}

SB_INLINE void TElStringTokenizer::GetAll(TElStringList *ResultList)
{
	SBCheckError(TElStringTokenizer_GetAll_1(_Handle, (ResultList != NULL) ? ResultList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

bool TElStringTokenizer::GetNext(std::string &Value)
{
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElStringTokenizer_GetNext(_Handle, (char *)Value.data(), &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(1193243616, 1, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Value.resize(szValue);
	return (OutResultRaw != 0);
}

bool TElStringTokenizer::GetRest(std::string &Value)
{
	int32_t szValue = (int32_t)Value.length();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElStringTokenizer_GetRest(_Handle, (char *)Value.data(), &szValue, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Value.resize(szValue);
		SBCheckError(SBGetLastReturnStringA(-469236171, 1, (char *)Value.data(), &szValue));
	}
	else
		SBCheckError(_err);

	Value.resize(szValue);
	return (OutResultRaw != 0);
}

SB_INLINE void TElStringTokenizer::Reset()
{
	SBCheckError(TElStringTokenizer_Reset(_Handle));
}

SB_INLINE char TElStringTokenizer::get_ClosingQuote()
{
	char OutResult;
	SBCheckError(TElStringTokenizer_get_ClosingQuote(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElStringTokenizer::set_ClosingQuote(char Value)
{
	SBCheckError(TElStringTokenizer_set_ClosingQuote(_Handle, Value));
}

bool TElStringTokenizer::get_ReturnEmptyTokens()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElStringTokenizer_get_ReturnEmptyTokens(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElStringTokenizer::set_ReturnEmptyTokens(bool Value)
{
	SBCheckError(TElStringTokenizer_set_ReturnEmptyTokens(_Handle, (int8_t)Value));
}

void TElStringTokenizer::get_Delimiters(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringTokenizer_get_Delimiters(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1469019188, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElStringTokenizer::set_Delimiters(const std::string &Value)
{
	SBCheckError(TElStringTokenizer_set_Delimiters(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE char TElStringTokenizer::get_EscapeChar()
{
	char OutResult;
	SBCheckError(TElStringTokenizer_get_EscapeChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElStringTokenizer::set_EscapeChar(char Value)
{
	SBCheckError(TElStringTokenizer_set_EscapeChar(_Handle, Value));
}

SB_INLINE char TElStringTokenizer::get_OpeningQuote()
{
	char OutResult;
	SBCheckError(TElStringTokenizer_get_OpeningQuote(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElStringTokenizer::set_OpeningQuote(char Value)
{
	SBCheckError(TElStringTokenizer_set_OpeningQuote(_Handle, Value));
}

void TElStringTokenizer::get_SourceString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElStringTokenizer_get_SourceString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-566352019, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElStringTokenizer::set_SourceString(const std::string &Value)
{
	SBCheckError(TElStringTokenizer_set_SourceString(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElStringTokenizer::get_TrimQuotes()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElStringTokenizer_get_TrimQuotes(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElStringTokenizer::set_TrimQuotes(bool Value)
{
	SBCheckError(TElStringTokenizer_set_TrimQuotes(_Handle, (int8_t)Value));
}

bool TElStringTokenizer::get_TrimSpaces()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElStringTokenizer_get_TrimSpaces(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElStringTokenizer::set_TrimSpaces(bool Value)
{
	SBCheckError(TElStringTokenizer_set_TrimSpaces(_Handle, (int8_t)Value));
}

TElStringTokenizer::TElStringTokenizer(TElStringTokenizerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElStringTokenizer::TElStringTokenizer() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElStringTokenizer_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSTRINGTOKENIZER */

};	/* namespace SecureBlackbox */
