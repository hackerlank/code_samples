#include "sbimaputils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELIMAPPARSER

bool TElIMAPParser::HasMoreTokens()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPParser_HasMoreTokens(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElIMAPParser::NextToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPParser_NextToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(483471963, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIMAPParser::GetRemainderString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPParser_GetRemainderString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1532330315, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElIMAPParser::get_Source(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPParser_get_Source(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1522733645, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElIMAPParser::set_Source(const std::string &Value)
{
	SBCheckError(TElIMAPParser_set_Source(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElIMAPParser::get_CurrentToken(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElIMAPParser_get_CurrentToken(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2017019035, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElIMAPParser::get_IsParenthesized()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPParser_get_IsParenthesized(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElIMAPParser::get_IsSection()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElIMAPParser_get_IsSection(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElIMAPParser::get_CurrentPosition()
{
	int32_t OutResult;
	SBCheckError(TElIMAPParser_get_CurrentPosition(_Handle, &OutResult));
	return OutResult;
}

TElIMAPParser::TElIMAPParser(TElIMAPParserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElIMAPParser::TElIMAPParser(const std::string &Source) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPParser_Create(Source.data(), (int32_t)Source.length(), &_Handle));
}

TElIMAPParser::TElIMAPParser() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElIMAPParser_Create_1(&_Handle));
}

#endif /* SB_USE_CLASS_TELIMAPPARSER */

#ifdef SB_USE_GLOBAL_PROCS_IMAPUTILS

void QuoteString(const std::string &Value, char Quote, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBIMAPUtils_QuoteString(Value.data(), (int32_t)Value.length(), Quote, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1154545812, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void QuoteStringIfNeed(const std::string &Value, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBIMAPUtils_QuoteStringIfNeed(Value.data(), (int32_t)Value.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1451417137, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnQuoteString(const std::string &Value, bool QuotesRemoved, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBIMAPUtils_UnQuoteString(Value.data(), (int32_t)Value.length(), (int8_t)QuotesRemoved, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(884596243, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t IsLiteralToken(const std::string &Token)
{
	int32_t OutResult;
	SBCheckError(SBIMAPUtils_IsLiteralToken(Token.data(), (int32_t)Token.length(), &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_IMAPUTILS */

};	/* namespace SecureBlackbox */

