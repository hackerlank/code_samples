#ifndef __INC_SBIMAPUTILS
#define __INC_SBIMAPUTILS

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
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElIMAPParserHandle;

#ifdef SB_USE_CLASS_TELIMAPPARSER
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_HasMoreTokens(TElIMAPParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_NextToken(TElIMAPParserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_GetRemainderString(TElIMAPParserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_get_Source(TElIMAPParserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_set_Source(TElIMAPParserHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_get_CurrentToken(TElIMAPParserHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_get_IsParenthesized(TElIMAPParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_get_IsSection(TElIMAPParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_get_CurrentPosition(TElIMAPParserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_Create(const char * pcSource, int32_t szSource, TElIMAPParserHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIMAPParser_Create_1(TElIMAPParserHandle * OutResult);
#endif /* SB_USE_CLASS_TELIMAPPARSER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElIMAPParser;

#ifdef SB_USE_CLASS_TELIMAPPARSER
class TElIMAPParser: public TObject
{
	private:
		SB_DISABLE_COPY(TElIMAPParser)
	public:
		bool HasMoreTokens();

		void NextToken(std::string &OutResult);

		void GetRemainderString(std::string &OutResult);

		virtual void get_Source(std::string &OutResult);

		virtual void set_Source(const std::string &Value);

		virtual void get_CurrentToken(std::string &OutResult);

		virtual bool get_IsParenthesized();

		SB_DECLARE_PROPERTY_GET(bool, get_IsParenthesized, TElIMAPParser, IsParenthesized);

		virtual bool get_IsSection();

		SB_DECLARE_PROPERTY_GET(bool, get_IsSection, TElIMAPParser, IsSection);

		virtual int32_t get_CurrentPosition();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CurrentPosition, TElIMAPParser, CurrentPosition);

		TElIMAPParser(TElIMAPParserHandle handle, TElOwnHandle ownHandle);

		explicit TElIMAPParser(const std::string &Source);

		TElIMAPParser();

};
#endif /* SB_USE_CLASS_TELIMAPPARSER */

#ifdef SB_USE_GLOBAL_PROCS_IMAPUTILS

void QuoteString(const std::string &Value, char Quote, std::string &OutResult);

void QuoteStringIfNeed(const std::string &Value, std::string &OutResult);

void UnQuoteString(const std::string &Value, bool QuotesRemoved, std::string &OutResult);

int32_t IsLiteralToken(const std::string &Token);

#endif /* SB_USE_GLOBAL_PROCS_IMAPUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_IMAPUTILS
SB_IMPORT uint32_t SB_APIENTRY SBIMAPUtils_QuoteString(const char * pcValue, int32_t szValue, char Quote, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBIMAPUtils_QuoteStringIfNeed(const char * pcValue, int32_t szValue, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBIMAPUtils_UnQuoteString(const char * pcValue, int32_t szValue, int8_t QuotesRemoved, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBIMAPUtils_IsLiteralToken(const char * pcToken, int32_t szToken, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_IMAPUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBIMAPUTILS */

