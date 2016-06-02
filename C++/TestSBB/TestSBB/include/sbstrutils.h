#ifndef __INC_SBSTRUTILS
#define __INC_SBSTRUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CP_UTF8 	65001

typedef TElClassHandle TElStringConverterHandle;

#ifdef SB_WINDOWS
typedef TElClassHandle TElPlatformStringConverterHandle;
#endif

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_StrToUtf8(TElStringConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_Utf8ToStr(TElStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_StrToWideStr(TElStringConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_WideStrToStr(TElStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_get_DefCharset(TElStringConverterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_set_DefCharset(TElStringConverterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElStringConverter_Create(TElStringConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_StrToUtf8(TElPlatformStringConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_Utf8ToStr(TElPlatformStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_StrToWideStr(TElPlatformStringConverterHandle _Handle, const char * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_WideStrToStr(TElPlatformStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_EncodeStr(TElPlatformStringConverterHandle _Handle, const char * pcSource, int32_t szSource, int32_t Encoding, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_EncodeStr_1(TElPlatformStringConverterHandle _Handle, const char * pcSource, int32_t szSource, const char * pcEncoding, int32_t szEncoding, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_DecodeStr(TElPlatformStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, int32_t Encoding, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_DecodeStr_1(TElPlatformStringConverterHandle _Handle, const uint8_t pSource[], int32_t szSource, const char * pcEncoding, int32_t szEncoding, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPlatformStringConverter_Create(TElPlatformStringConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER */
#endif

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElStringConverter;
#ifdef SB_WINDOWS
class TElPlatformStringConverter;
#endif

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
class TElStringConverter: public TObject
{
	private:
		SB_DISABLE_COPY(TElStringConverter)
	public:
		virtual void StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		virtual void StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		virtual void get_DefCharset(std::string &OutResult);

		virtual void set_DefCharset(const std::string &Value);

		TElStringConverter(TElStringConverterHandle handle, TElOwnHandle ownHandle);

		TElStringConverter();

};
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER
class TElPlatformStringConverter: public TElStringConverter
{
	private:
		SB_DISABLE_COPY(TElPlatformStringConverter)
	public:
		virtual void StrToUtf8(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void Utf8ToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		virtual void StrToWideStr(const std::string &Source, std::vector<uint8_t> &OutResult);

		virtual void WideStrToStr(const std::vector<uint8_t> &Source, std::string &OutResult);

		void EncodeStr(const std::string &Source, int32_t Encoding, std::vector<uint8_t> &OutResult);

		void EncodeStr(const std::string &Source, const std::string &Encoding, std::vector<uint8_t> &OutResult);

		void DecodeStr(const std::vector<uint8_t> &Source, int32_t Encoding, std::string &OutResult);

		void DecodeStr(const std::vector<uint8_t> &Source, const std::string &Encoding, std::string &OutResult);

		TElPlatformStringConverter(TElPlatformStringConverterHandle handle, TElOwnHandle ownHandle);

		TElPlatformStringConverter();

};
#endif /* SB_USE_CLASS_TELPLATFORMSTRINGCONVERTER */
#endif

#ifdef SB_USE_GLOBAL_PROCS_STRUTILS

bool StringEndsWith(const std::string &S, const std::string &SubS);

bool StringEndsWith(const std::string &S, const std::string &SubS, bool IgnoreCase);

bool StringEquals(const std::string &S1, const std::string &S2);

bool StringEquals(const std::string &S1, const std::string &S2, bool IgnoreCase);

bool StringEquals(const std::string &S1, const std::string &S2, int32_t MaxLength);

bool StringEquals(const std::string &S1, const std::string &S2, int32_t MaxLength, bool IgnoreCase);

bool StringEquals(const std::string &S1, int32_t Index1, const std::string &S2, int32_t Index2, int32_t MaxLength);

bool StringEquals(const std::string &S1, int32_t Index1, const std::string &S2, int32_t Index2, int32_t MaxLength, bool IgnoreCase);

int32_t StringIndexOf(const std::string &S, char C);

int32_t StringIndexOf(const std::string &S, char C, int32_t StartIndex);

int32_t StringIndexOf(const std::string &S, const std::string &SubS);

int32_t StringIndexOf(const std::string &S, const std::string &SubS, int32_t StartIndex);

int32_t StringIndexOfU(const sb_u16string &S, sb_char16_t C);
#ifdef SB_U16STRING_USED
int32_t StringIndexOfU(const std::wstring &S, sb_char16_t C);
#endif /* SB_U16STRING_USED */

void StringInsert(const sb_u16string &S, int32_t Index, sb_char16_t C, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringInsert(const std::wstring &S, int32_t Index, sb_char16_t C, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void StringInsert(const sb_u16string &S, int32_t Index, const sb_u16string &SubS, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringInsert(const std::wstring &S, int32_t Index, const std::wstring &SubS, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void StringInsert(const std::string &S, int32_t Index, char C, std::string &OutResult);

void StringInsert(const std::string &S, int32_t Index, const std::string &SubS, std::string &OutResult);

bool StringIsEmpty(const std::string &S);

int32_t StringLastIndexOf(const sb_u16string &S, sb_char16_t C);
#ifdef SB_U16STRING_USED
int32_t StringLastIndexOf(const std::wstring &S, sb_char16_t C);
#endif /* SB_U16STRING_USED */

int32_t StringLastIndexOf(const sb_u16string &S, sb_char16_t C, int32_t StartIndex);
#ifdef SB_U16STRING_USED
int32_t StringLastIndexOf(const std::wstring &S, sb_char16_t C, int32_t StartIndex);
#endif /* SB_U16STRING_USED */

int32_t StringLastIndexOf(const std::string &S, char C);

int32_t StringLastIndexOf(const std::string &S, char C, int32_t StartIndex);

void StringRemove(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringRemove(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void StringRemove(const sb_u16string &S, int32_t StartIndex, int32_t Count, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringRemove(const std::wstring &S, int32_t StartIndex, int32_t Count, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void WideStringRemove(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideStringRemove(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void WideStringRemove(const sb_u16string &S, int32_t StartIndex, int32_t Count, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideStringRemove(const std::wstring &S, int32_t StartIndex, int32_t Count, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void AnsiStringRemove(const std::string &S, int32_t StartIndex, std::string &OutResult);

void AnsiStringRemove(const std::string &S, int32_t StartIndex, int32_t Count, std::string &OutResult);

void StringToLower(const std::string &S, std::string &OutResult);

void StringToLowerInvariant(const std::string &S, std::string &OutResult);

bool StringStartsWith(const std::string &S, const std::string &SubS);

bool StringStartsWith(const std::string &S, const std::string &SubS, bool IgnoreCase);

void StringSubstring(const std::string &S, int32_t StartIndex, std::string &OutResult);

void StringSubstring(const std::string &S, int32_t StartIndex, int32_t Length, std::string &OutResult);

void StringSubstring(const sb_u16string &S, int32_t StartIndex, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringSubstring(const std::wstring &S, int32_t StartIndex, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void StringSubstring(const sb_u16string &S, int32_t StartIndex, int32_t Length, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringSubstring(const std::wstring &S, int32_t StartIndex, int32_t Length, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void StringTrim(const std::string &S, std::string &OutResult);

void StringTrimEnd(const std::string &S, std::string &OutResult);

void StringTrimStart(const std::string &S, std::string &OutResult);

void StringToUpper(const std::string &S, std::string &OutResult);

void StringToUpperInvariant(const std::string &S, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
void StringSplit(const std::string &S, char Separator, TStringList &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TSTRINGLIST
void StringSplit(const std::string &S, char Separator, bool RemoveEmptyEntries, TStringList &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool StringSplitPV(const std::string &S, std::string &Name, std::string &Value);

bool StringSplitPV(const std::string &S, std::string &Name, std::string &Value, char Separator);

bool StringSplitPV(const sb_u16string &S, sb_u16string &Name, sb_u16string &Value);
#ifdef SB_U16STRING_USED
bool StringSplitPV(const std::wstring &S, std::wstring &Name, std::wstring &Value);
#endif /* SB_U16STRING_USED */

bool StringSplitPV(const sb_u16string &S, sb_u16string &Name, sb_u16string &Value, sb_char16_t Separator);
#ifdef SB_U16STRING_USED
bool StringSplitPV(const std::wstring &S, std::wstring &Name, std::wstring &Value, sb_char16_t Separator);
#endif /* SB_U16STRING_USED */

void StringPadLeft(const std::string &S, char C, int32_t Len, std::string &OutResult);

void StringPadRight(const std::string &S, char C, int32_t Len, std::string &OutResult);

void StrToDefEncoding(const std::string &AStr, std::vector<uint8_t> &OutResult);

void DefEncodingToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult);

void StrToStdEncoding(const std::string &AStr, bool UseUTF8, std::vector<uint8_t> &OutResult);

void StdEncodingToStr(const std::vector<uint8_t> &ASrc, bool UseUTF8, std::string &OutResult);

void SBExtractFilePath(const std::string &FileName, std::string &OutResult);

void SBExtractFileName(const std::string &FileName, std::string &OutResult);

void SBExtractFileExt(const std::string &FileName, std::string &OutResult);

void SBExtractFileExt(const std::string &FileName, bool IncludeDot, std::string &OutResult);

void ReplaceExt(const std::string &FileName, const std::string &NewExtension, std::string &OutResult);

bool FilenameMatchesMask(const std::string &Name, const std::string &Mask, bool CaseSensitive);

bool DomainNameMatchesCertSN(const std::string &DomainName, const std::string &Match);

int32_t CountFoldersInPath(const std::string &Path);

void ParseURL(const std::string &URL, bool SingleNameIsPage, std::string &Protocol, std::string &Username, std::string &Password, std::string &Host, uint16_t &Port, std::string &Path, std::string &anchor, std::string &Parameters);

void ParseURL(const std::string &URL, bool SingleNameIsPage, std::string &Protocol, std::string &Username, std::string &Password, std::string &Host, uint16_t &Port, std::string &Path, std::string &anchor, std::string &Parameters, const std::string &DefaultProtocol);

void ComposeURL(const std::string &Protocol, const std::string &UserName, const std::string &Password, const std::string &Host, uint16_t Port, const std::string &Path, const std::string &Anchor, const std::string &Parameters, std::string &OutResult);

int32_t SBRightPos(const std::string &Substr, const std::string &Str);

int32_t SBPos(const std::string &substr, const std::string &str);

int32_t SBPos(const std::vector<uint8_t> &SubP, const std::vector<uint8_t> &P, int32_t StartPos);

int32_t SBPos(const std::string &SubP, const std::vector<uint8_t> &P, int32_t StartPos);

int32_t SBPos(uint8_t SubP, const std::vector<uint8_t> &P);

void SBCopy(const std::vector<uint8_t> &str, int32_t Offset, int32_t Size, std::vector<uint8_t> &OutResult);

void SBCopy(const std::vector<uint8_t> &str, std::vector<uint8_t> &OutResult);

void SBConcatAnsiStrings(const std::string &Str1, char Str2, std::string &OutResult);

void SBConcatAnsiStrings(const std::string &Str1, const std::string &Str2, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTRINGLIST
void SBConcatAnsiStrings(const TStringList &Strs, std::string &OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

void AnsiStrPas(char * P, std::string &OutResult);

void OIDToStr(const std::vector<uint8_t> &OID, std::string &OutResult);

void StrToOID(const std::string &Str, std::vector<uint8_t> &OutResult);

void StrToUTF8(const std::string &AStr, std::vector<uint8_t> &OutResult);

void UTF8ToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult);

void StrToWideStr(const std::string &AStr, std::vector<uint8_t> &OutResult);

void WideStrToStr(const std::vector<uint8_t> &ASrc, std::string &OutResult);

void EncodeString(const std::string &AStr, const std::string &Encoding, std::vector<uint8_t> &OutResult);

void DecodeString(const std::vector<uint8_t> &ASrc, const std::string &Encoding, std::string &OutResult);

void UnicodeChangeEndianness(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WideStrToUTF8(const sb_u16string &AStr, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void WideStrToUTF8(const std::wstring &AStr, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void WideStrToUTF8(const void * ASrc, int32_t Size, std::vector<uint8_t> &OutResult);

void UTF8ToWideStr(const std::vector<uint8_t> &Buf, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void UTF8ToWideStr(const std::vector<uint8_t> &Buf, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void UTF8ToWideStr(const void * Buf, int32_t Size, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void UTF8ToWideStr(const void * Buf, int32_t Size, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

ConversionResult ConvertUTF16toUTF8(const sb_u16string &source, std::vector<uint8_t> &target, ConversionFlags flags, bool BOM);
#ifdef SB_U16STRING_USED
ConversionResult ConvertUTF16toUTF8(const std::wstring &source, std::vector<uint8_t> &target, ConversionFlags flags, bool BOM);
#endif /* SB_U16STRING_USED */

bool isLegalUTF8(const std::vector<uint8_t> &source, uint32_t sourcelen);

ConversionResult ConvertUTF8toUTF16(const std::vector<uint8_t> &source, sb_u16string &target, ConversionFlags flags, bool BOM);
#ifdef SB_U16STRING_USED
ConversionResult ConvertUTF8toUTF16(const std::vector<uint8_t> &source, std::wstring &target, ConversionFlags flags, bool BOM);
#endif /* SB_U16STRING_USED */

void ConvertFromUTF8String(const std::vector<uint8_t> &Source, bool CheckBOM, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertFromUTF8String(const std::vector<uint8_t> &Source, bool CheckBOM, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertToUTF8String(const sb_u16string &Source, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
void ConvertToUTF8String(const std::wstring &Source, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

void ConvertFromUTF32String(const std::vector<uint8_t> &Source, bool CheckBOM, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ConvertFromUTF32String(const std::vector<uint8_t> &Source, bool CheckBOM, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_TELSTRINGCONVERTER
void SetGlobalStringConverter(TElStringConverter &Converter);
void SetGlobalStringConverter(TElStringConverter *Converter);
#endif /* SB_USE_CLASS_TELSTRINGCONVERTER */

void SetDefaultCharset(const std::string &Charset);

int64_t StrMixToInt64(const std::string &S);

void SBTrim(const std::vector<uint8_t> &S, std::vector<uint8_t> &OutResult);

void SBUppercase(const std::vector<uint8_t> &S, std::vector<uint8_t> &OutResult);

void StringReplace(const std::string &Source, const std::string &Entry, const std::string &ReplaceWith, std::string &OutResult);

void StringReplace(const sb_u16string &Source, const sb_u16string &Entry, const sb_u16string &ReplaceWith, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void StringReplace(const std::wstring &Source, const std::wstring &Entry, const std::wstring &ReplaceWith, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void PAnsiCharToByteArray(const char * P, std::vector<uint8_t> &OutResult);

void PrefixString(const std::string &S, int32_t Count, char Value, std::string &OutResult);

void SuffixString(const std::string &S, int32_t Count, char Value, std::string &OutResult);

void PathFirstComponent(const std::string &Path, std::string &OutResult);

void PathLastComponent(const std::string &Path, std::string &OutResult);

void PathCutFirstComponent(const std::string &Path, std::string &OutResult);

void PathCutLastComponent(const std::string &Path, std::string &OutResult);

bool PathIsDirectory(const std::string &Path);

void PathTrim(const std::string &Path, std::string &OutResult);

void PathConcatenate(const std::string &Path1, const std::string &Path2, std::string &OutResult);

void PathNormalizeSlashes(const std::string &Path, std::string &OutResult);

void PathReverseSlashes(const std::string &Path, std::string &OutResult);

bool PathMatchesMask(const std::string &Path, const std::string &Mask);

bool PathMatchesMask(const std::string &Path, const std::string &Mask, bool CaseSensitive);

bool IsFileMask(const std::string &Path);

void ExtractPathFromMask(const std::string &Mask, std::string &OutResult);

void SftpNormalizePath(const std::string &Path, std::string &OutResult);

void ZipPathFirstComponent(const std::string &Path, std::string &OutResult);

void ZipPathLastComponent(const std::string &Path, std::string &OutResult);

void ZipPathCutFirstComponent(const std::string &Path, std::string &OutResult);

void ZipPathCutLastComponent(const std::string &Path, std::string &OutResult);

bool ZipPathIsDirectory(const std::string &Path);

void ZipPathTrim(const std::string &Path, std::string &OutResult);

void ZipPathConcatenate(const std::string &Path1, const std::string &Path2, std::string &OutResult);

void ZipPathNormalizeSlashes(const std::string &Path, std::string &OutResult);

void ZipPathReverseSlashes(const std::string &Path, std::string &OutResult);

bool ZipPathMatchesMask(const std::string &Path, const std::string &Mask);

bool ZipPathMatchesMask(const std::string &Path, const std::string &Mask, bool CaseSensitive);

bool ZipIsFileMask(const std::string &Path);

void ZipExtractPathFromMask(const std::string &Mask, std::string &OutResult);

int32_t PosExSafe(const std::string &SubStr, const std::string &S, int32_t Offset, int32_t Count);

int32_t PosLast(const std::string &SubStr, const std::string &S);

int32_t WidePosEx(const sb_u16string &SubStr, const sb_u16string &S, int32_t Offset, int32_t Count);
#ifdef SB_U16STRING_USED
int32_t WidePosEx(const std::wstring &SubStr, const std::wstring &S, int32_t Offset, int32_t Count);
#endif /* SB_U16STRING_USED */

int32_t WidePosLast(const sb_u16string &SubStr, const sb_u16string &S);
#ifdef SB_U16STRING_USED
int32_t WidePosLast(const std::wstring &SubStr, const std::wstring &S);
#endif /* SB_U16STRING_USED */

void WideStringToByteString(const sb_u16string &WS, std::string &OutResult);
#ifdef SB_U16STRING_USED
void WideStringToByteString(const std::wstring &WS, std::string &OutResult);
#endif /* SB_U16STRING_USED */

void AnsiStringToByteWideString(const std::string &S, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void AnsiStringToByteWideString(const std::string &S, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void IntToStrPadLeft(int32_t Val, int32_t iWidth, sb_char16_t chTemplate, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void IntToStrPadLeft(int32_t Val, int32_t iWidth, sb_char16_t chTemplate, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void GetWideBytesOf(const sb_u16string &Value, std::vector<uint8_t> &B);
#ifdef SB_U16STRING_USED
void GetWideBytesOf(const std::wstring &Value, std::vector<uint8_t> &B);
#endif /* SB_U16STRING_USED */

void GetStringOf(const std::vector<uint8_t> &Bytes, std::string &S);

void GetStringOfEx(const std::vector<uint8_t> &Bytes, std::string &S, int64_t LPos, int64_t RPos);

void GetWideStringOf(const std::vector<uint8_t> &Bytes, sb_u16string &WS);
#ifdef SB_U16STRING_USED
void GetWideStringOf(const std::vector<uint8_t> &Bytes, std::wstring &WS);
#endif /* SB_U16STRING_USED */

void TrimEx(std::string &S, bool bTrimLeft, bool bTrimRight);

void TrimSemicolon(sb_u16string &S);
#ifdef SB_U16STRING_USED
void TrimSemicolon(std::wstring &S);
#endif /* SB_U16STRING_USED */

void ExtractWideFileName(const sb_u16string &FileName, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ExtractWideFileName(const std::wstring &FileName, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ExtractFileExtension(const sb_u16string &FileName, std::string &OutResult);
#ifdef SB_U16STRING_USED
void ExtractFileExtension(const std::wstring &FileName, std::string &OutResult);
#endif /* SB_U16STRING_USED */

void ExtractWideFileExtension(const sb_u16string &FileName, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ExtractWideFileExtension(const std::wstring &FileName, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void WideTrimRight(const sb_u16string &S, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void WideTrimRight(const std::wstring &S, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void DecodeDateTime(int64_t AValue, uint16_t &AYear, uint16_t &AMonth, uint16_t &ADay, uint16_t &AHour, uint16_t &AMinute, uint16_t &ASecond, uint16_t &AMilliSecond);

int32_t SBLength(const std::string &Str);

#endif /* SB_USE_GLOBAL_PROCS_STRUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_STRUTILS
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEndsWith(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEndsWith_1(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t IgnoreCase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals(const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals_1(const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int8_t IgnoreCase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals_2(const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t MaxLength, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals_3(const char * pcS1, int32_t szS1, const char * pcS2, int32_t szS2, int32_t MaxLength, int8_t IgnoreCase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals_4(const char * pcS1, int32_t szS1, int32_t Index1, const char * pcS2, int32_t szS2, int32_t Index2, int32_t MaxLength, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringEquals_5(const char * pcS1, int32_t szS1, int32_t Index1, const char * pcS2, int32_t szS2, int32_t Index2, int32_t MaxLength, int8_t IgnoreCase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIndexOf(const char * pcS, int32_t szS, char C, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIndexOf_1(const char * pcS, int32_t szS, char C, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIndexOf_2(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIndexOf_3(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIndexOfU(const sb_char16_t * pcS, int32_t szS, sb_char16_t C, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringInsert(const sb_char16_t * pcS, int32_t szS, int32_t Index, sb_char16_t C, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringInsert_1(const sb_char16_t * pcS, int32_t szS, int32_t Index, const sb_char16_t * pcSubS, int32_t szSubS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringInsert_2(const char * pcS, int32_t szS, int32_t Index, char C, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringInsert_3(const char * pcS, int32_t szS, int32_t Index, const char * pcSubS, int32_t szSubS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringIsEmpty(const char * pcS, int32_t szS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringLastIndexOf(const sb_char16_t * pcS, int32_t szS, sb_char16_t C, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringLastIndexOf_1(const sb_char16_t * pcS, int32_t szS, sb_char16_t C, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringLastIndexOf_2(const char * pcS, int32_t szS, char C, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringLastIndexOf_3(const char * pcS, int32_t szS, char C, int32_t StartIndex, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringRemove(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringRemove_1(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, int32_t Count, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStringRemove(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStringRemove_1(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, int32_t Count, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_AnsiStringRemove(const char * pcS, int32_t szS, int32_t StartIndex, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_AnsiStringRemove_1(const char * pcS, int32_t szS, int32_t StartIndex, int32_t Count, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringToLower(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringToLowerInvariant(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringStartsWith(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringStartsWith_1(const char * pcS, int32_t szS, const char * pcSubS, int32_t szSubS, int8_t IgnoreCase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSubstring(const char * pcS, int32_t szS, int32_t StartIndex, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSubstring_1(const char * pcS, int32_t szS, int32_t StartIndex, int32_t Length, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSubstring_2(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSubstring_3(const sb_char16_t * pcS, int32_t szS, int32_t StartIndex, int32_t Length, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringTrim(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringTrimEnd(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringTrimStart(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringToUpper(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringToUpperInvariant(const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplit(const char * pcS, int32_t szS, char Separator, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplit_1(const char * pcS, int32_t szS, char Separator, int8_t RemoveEmptyEntries, TStringListHandle OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplitPV(const char * pcS, int32_t szS, char * pcName, int32_t * szName, char * pcValue, int32_t * szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplitPV_1(const char * pcS, int32_t szS, char * pcName, int32_t * szName, char * pcValue, int32_t * szValue, char Separator, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplitPV_2(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcName, int32_t * szName, sb_char16_t * pcValue, int32_t * szValue, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringSplitPV_3(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcName, int32_t * szName, sb_char16_t * pcValue, int32_t * szValue, sb_char16_t Separator, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringPadLeft(const char * pcS, int32_t szS, char C, int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringPadRight(const char * pcS, int32_t szS, char C, int32_t Len, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrToDefEncoding(const char * pcAStr, int32_t szAStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_DefEncodingToStr(const uint8_t pASrc[], int32_t szASrc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrToStdEncoding(const char * pcAStr, int32_t szAStr, int8_t UseUTF8, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StdEncodingToStr(const uint8_t pASrc[], int32_t szASrc, int8_t UseUTF8, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBExtractFilePath(const char * pcFileName, int32_t szFileName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBExtractFileName(const char * pcFileName, int32_t szFileName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBExtractFileExt(const char * pcFileName, int32_t szFileName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBExtractFileExt_1(const char * pcFileName, int32_t szFileName, int8_t IncludeDot, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ReplaceExt(const char * pcFileName, int32_t szFileName, const char * pcNewExtension, int32_t szNewExtension, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_FilenameMatchesMask(const char * pcName, int32_t szName, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_DomainNameMatchesCertSN(const char * pcDomainName, int32_t szDomainName, const char * pcMatch, int32_t szMatch, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_CountFoldersInPath(const char * pcPath, int32_t szPath, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ParseURL(const char * pcURL, int32_t szURL, int8_t SingleNameIsPage, char * pcProtocol, int32_t * szProtocol, char * pcUsername, int32_t * szUsername, char * pcPassword, int32_t * szPassword, char * pcHost, int32_t * szHost, uint16_t * Port, char * pcPath, int32_t * szPath, char * pcanchor, int32_t * szanchor, char * pcParameters, int32_t * szParameters);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ParseURL_1(const char * pcURL, int32_t szURL, int8_t SingleNameIsPage, char * pcProtocol, int32_t * szProtocol, char * pcUsername, int32_t * szUsername, char * pcPassword, int32_t * szPassword, char * pcHost, int32_t * szHost, uint16_t * Port, char * pcPath, int32_t * szPath, char * pcanchor, int32_t * szanchor, char * pcParameters, int32_t * szParameters, const char * pcDefaultProtocol, int32_t szDefaultProtocol);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ComposeURL(const char * pcProtocol, int32_t szProtocol, const char * pcUserName, int32_t szUserName, const char * pcPassword, int32_t szPassword, const char * pcHost, int32_t szHost, uint16_t Port, const char * pcPath, int32_t szPath, const char * pcAnchor, int32_t szAnchor, const char * pcParameters, int32_t szParameters, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBRightPos(const char * pcSubstr, int32_t szSubstr, const char * pcStr, int32_t szStr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBPos(const char * pcsubstr, int32_t szsubstr, const char * pcstr, int32_t szstr, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBPos_1(const uint8_t pSubP[], int32_t szSubP, const uint8_t pP[], int32_t szP, int32_t StartPos, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBPos_2(const char * pcSubP, int32_t szSubP, const uint8_t pP[], int32_t szP, int32_t StartPos, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBPos_3(uint8_t SubP, const uint8_t pP[], int32_t szP, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBCopy(const uint8_t pstr[], int32_t szstr, int32_t Offset, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBCopy_1(const uint8_t pstr[], int32_t szstr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBConcatAnsiStrings(const char * pcStr1, int32_t szStr1, char Str2, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBConcatAnsiStrings_1(const char * pcStr1, int32_t szStr1, const char * pcStr2, int32_t szStr2, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBConcatAnsiStrings_2(const TStringListHandle Strs, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_AnsiStrPas(char * P, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_OIDToStr(const uint8_t pOID[], int32_t szOID, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrToOID(const char * pcStr, int32_t szStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrToUTF8(const char * pcAStr, int32_t szAStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_UTF8ToStr(const uint8_t pASrc[], int32_t szASrc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrToWideStr(const char * pcAStr, int32_t szAStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStrToStr(const uint8_t pASrc[], int32_t szASrc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_EncodeString(const char * pcAStr, int32_t szAStr, const char * pcEncoding, int32_t szEncoding, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_DecodeString(const uint8_t pASrc[], int32_t szASrc, const char * pcEncoding, int32_t szEncoding, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_UnicodeChangeEndianness(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStrToUTF8(const sb_char16_t * pcAStr, int32_t szAStr, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStrToUTF8_1(const void * ASrc, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_UTF8ToWideStr(const uint8_t pBuf[], int32_t szBuf, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_UTF8ToWideStr_1(const void * Buf, int32_t Size, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ConvertUTF16toUTF8(const sb_char16_t * pcsource, int32_t szsource, uint8_t ptarget[], int32_t * sztarget, ConversionFlagsRaw flags, int8_t BOM, ConversionResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_isLegalUTF8(const uint8_t psource[], int32_t szsource, uint32_t sourcelen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ConvertUTF8toUTF16(const uint8_t psource[], int32_t szsource, sb_char16_t * pctarget, int32_t * sztarget, ConversionFlagsRaw flags, int8_t BOM, ConversionResultRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ConvertFromUTF8String(const uint8_t pSource[], int32_t szSource, int8_t CheckBOM, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ConvertToUTF8String(const sb_char16_t * pcSource, int32_t szSource, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ConvertFromUTF32String(const uint8_t pSource[], int32_t szSource, int8_t CheckBOM, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SetGlobalStringConverter(TElStringConverterHandle Converter);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SetDefaultCharset(const char * pcCharset, int32_t szCharset);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StrMixToInt64(const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBTrim(const uint8_t pS[], int32_t szS, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBUppercase(const uint8_t pS[], int32_t szS, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringReplace(const char * pcSource, int32_t szSource, const char * pcEntry, int32_t szEntry, const char * pcReplaceWith, int32_t szReplaceWith, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_StringReplace_1(const sb_char16_t * pcSource, int32_t szSource, const sb_char16_t * pcEntry, int32_t szEntry, const sb_char16_t * pcReplaceWith, int32_t szReplaceWith, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PAnsiCharToByteArray(const char * P, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PrefixString(const char * pcS, int32_t szS, int32_t Count, char Value, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SuffixString(const char * pcS, int32_t szS, int32_t Count, char Value, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathFirstComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathLastComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathCutFirstComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathCutLastComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathIsDirectory(const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathTrim(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathConcatenate(const char * pcPath1, int32_t szPath1, const char * pcPath2, int32_t szPath2, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathNormalizeSlashes(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathReverseSlashes(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathMatchesMask(const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PathMatchesMask_1(const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_IsFileMask(const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ExtractPathFromMask(const char * pcMask, int32_t szMask, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SftpNormalizePath(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathFirstComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathLastComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathCutFirstComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathCutLastComponent(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathIsDirectory(const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathTrim(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathConcatenate(const char * pcPath1, int32_t szPath1, const char * pcPath2, int32_t szPath2, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathNormalizeSlashes(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathReverseSlashes(const char * pcPath, int32_t szPath, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathMatchesMask(const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipPathMatchesMask_1(const char * pcPath, int32_t szPath, const char * pcMask, int32_t szMask, int8_t CaseSensitive, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipIsFileMask(const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ZipExtractPathFromMask(const char * pcMask, int32_t szMask, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PosExSafe(const char * pcSubStr, int32_t szSubStr, const char * pcS, int32_t szS, int32_t Offset, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_PosLast(const char * pcSubStr, int32_t szSubStr, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WidePosEx(const sb_char16_t * pcSubStr, int32_t szSubStr, const sb_char16_t * pcS, int32_t szS, int32_t Offset, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WidePosLast(const sb_char16_t * pcSubStr, int32_t szSubStr, const sb_char16_t * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideStringToByteString(const sb_char16_t * pcWS, int32_t szWS, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_AnsiStringToByteWideString(const char * pcS, int32_t szS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_IntToStrPadLeft(int32_t Val, int32_t iWidth, sb_char16_t chTemplate, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_GetWideBytesOf(const sb_char16_t * pcValue, int32_t szValue, uint8_t pB[], int32_t * szB);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_GetStringOf(const uint8_t pBytes[], int32_t szBytes, char * pcS, int32_t * szS);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_GetStringOfEx(const uint8_t pBytes[], int32_t szBytes, char * pcS, int32_t * szS, int64_t LPos, int64_t RPos);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_GetWideStringOf(const uint8_t pBytes[], int32_t szBytes, sb_char16_t * pcWS, int32_t * szWS);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_TrimEx(char * pcS, int32_t * szS, int8_t bTrimLeft, int8_t bTrimRight);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_TrimSemicolon(sb_char16_t * pcS, int32_t * szS);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ExtractWideFileName(const sb_char16_t * pcFileName, int32_t szFileName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ExtractFileExtension(const sb_char16_t * pcFileName, int32_t szFileName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_ExtractWideFileExtension(const sb_char16_t * pcFileName, int32_t szFileName, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_WideTrimRight(const sb_char16_t * pcS, int32_t szS, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_DecodeDateTime(int64_t AValue, uint16_t * AYear, uint16_t * AMonth, uint16_t * ADay, uint16_t * AHour, uint16_t * AMinute, uint16_t * ASecond, uint16_t * AMilliSecond);
SB_IMPORT uint32_t SB_APIENTRY SBStrUtils_SBLength(const char * pcStr, int32_t szStr, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_STRUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSTRUTILS */
