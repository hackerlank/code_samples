#ifndef __INC_SBSTRINGLIST
#define __INC_SBSTRINGLIST

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
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
#ifdef SB_WINDOWS
typedef TStringListHandle ElStringListHandle;
#else
typedef TElStringListHandle ElStringListHandle;
#endif

typedef TElClassHandle TElStringTokenizerHandle;

typedef uint8_t TSBTokenizerModeRaw;

typedef enum
{
	tAll = 0,
	tNext = 1,
	tRest = 2
} TSBTokenizerMode;

#ifdef SB_USE_CLASS_TELSTRINGTOKENIZER
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetAll(TElStringTokenizerHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetAll_1(TElStringTokenizerHandle _Handle, TStringListHandle ResultList);
#else
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetAll(TElStringTokenizerHandle _Handle, TElStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetAll_1(TElStringTokenizerHandle _Handle, TElStringListHandle ResultList);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetNext(TElStringTokenizerHandle _Handle, char * pcValue, int32_t * szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_GetRest(TElStringTokenizerHandle _Handle, char * pcValue, int32_t * szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_Reset(TElStringTokenizerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_ClosingQuote(TElStringTokenizerHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_ClosingQuote(TElStringTokenizerHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_ReturnEmptyTokens(TElStringTokenizerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_ReturnEmptyTokens(TElStringTokenizerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_Delimiters(TElStringTokenizerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_Delimiters(TElStringTokenizerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_EscapeChar(TElStringTokenizerHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_EscapeChar(TElStringTokenizerHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_OpeningQuote(TElStringTokenizerHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_OpeningQuote(TElStringTokenizerHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_SourceString(TElStringTokenizerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_SourceString(TElStringTokenizerHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_TrimQuotes(TElStringTokenizerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_TrimQuotes(TElStringTokenizerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_get_TrimSpaces(TElStringTokenizerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_set_TrimSpaces(TElStringTokenizerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElStringTokenizer_Create(TElStringTokenizerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTRINGTOKENIZER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
#ifdef SB_WINDOWS
typedef TStringList ElStringList;
#else
typedef TElStringList ElStringList;
#endif
class TElStringTokenizer;

#ifdef SB_USE_CLASS_TELSTRINGTOKENIZER
class TElStringTokenizer: public TObject
{
	private:
		SB_DISABLE_COPY(TElStringTokenizer)
	public:
#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringListHandle GetAll();
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringListHandle GetAll();
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		void GetAll(TStringList &ResultList);

		void GetAll(TStringList *ResultList);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		void GetAll(TElStringList &ResultList);

		void GetAll(TElStringList *ResultList);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		bool GetNext(std::string &Value);

		bool GetRest(std::string &Value);

		void Reset();

		virtual char get_ClosingQuote();

		virtual void set_ClosingQuote(char Value);

		SB_DECLARE_PROPERTY(char, get_ClosingQuote, set_ClosingQuote, TElStringTokenizer, ClosingQuote);

		virtual bool get_ReturnEmptyTokens();

		virtual void set_ReturnEmptyTokens(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReturnEmptyTokens, set_ReturnEmptyTokens, TElStringTokenizer, ReturnEmptyTokens);

		virtual void get_Delimiters(std::string &OutResult);

		virtual void set_Delimiters(const std::string &Value);

		virtual char get_EscapeChar();

		virtual void set_EscapeChar(char Value);

		SB_DECLARE_PROPERTY(char, get_EscapeChar, set_EscapeChar, TElStringTokenizer, EscapeChar);

		virtual char get_OpeningQuote();

		virtual void set_OpeningQuote(char Value);

		SB_DECLARE_PROPERTY(char, get_OpeningQuote, set_OpeningQuote, TElStringTokenizer, OpeningQuote);

		virtual void get_SourceString(std::string &OutResult);

		virtual void set_SourceString(const std::string &Value);

		virtual bool get_TrimQuotes();

		virtual void set_TrimQuotes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TrimQuotes, set_TrimQuotes, TElStringTokenizer, TrimQuotes);

		virtual bool get_TrimSpaces();

		virtual void set_TrimSpaces(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TrimSpaces, set_TrimSpaces, TElStringTokenizer, TrimSpaces);

		TElStringTokenizer(TElStringTokenizerHandle handle, TElOwnHandle ownHandle);

		TElStringTokenizer();

};
#endif /* SB_USE_CLASS_TELSTRINGTOKENIZER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSTRINGLIST */
