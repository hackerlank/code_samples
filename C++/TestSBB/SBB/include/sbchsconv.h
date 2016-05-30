#ifndef __INC_SBCHSCONV
#define __INC_SBCHSCONV

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbsharedresource.h"
#include "sbconstants.h"
#include "sbchsconvbase.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TPlConverterHandle;

typedef TElClassHandle TPlCustomUTFHandle;

typedef TElClassHandle TPlUTF32Handle;

typedef TElClassHandle TPlUTF32BEHandle;

typedef TElClassHandle TPlUTF16Handle;

typedef TElClassHandle TPlUTF16BEHandle;

typedef TElClassHandle TPlUTF8Handle;

typedef TElClassHandle TPlCustomUTF7Handle;

typedef TElClassHandle TPlUTF7Handle;

typedef TElClassHandle TPlUTF7_IMAPHandle;

typedef TElClassHandle TPlConvBufferHandle;

typedef TElClassHandle TPlCustomStringStreamHandle;

typedef TElClassHandle TPlAnsiStringStreamHandle;

typedef TElClassHandle TPlWideStringStreamHandle;

typedef TElClassHandle TPlByteArrayStreamHandle;

typedef TElClassHandle TPlCustomStringStreamPoolHandle;

typedef TElClassHandle TPlAnsiStringStreamPoolHandle;

typedef TElClassHandle TPlWideStringStreamPoolHandle;

typedef uint8_t TPlConvertOptionRaw;

typedef enum
{
	coContinuePrevious = 0,
	coNoDefaultChar = 1,
	coInvalidCharException = 2,
	coWriteFileHeader = 3,
	coWriteLineBegin = 4,
	coWriteLineEnd = 5
} TPlConvertOption;

typedef uint32_t TPlConvertOptionsRaw;

typedef enum 
{
	f_coContinuePrevious = 1,
	f_coNoDefaultChar = 2,
	f_coInvalidCharException = 4,
	f_coWriteFileHeader = 8,
	f_coWriteLineBegin = 16,
	f_coWriteLineEnd = 32
} TPlConvertOptions;

typedef uint8_t TPlConverterLineStateRaw;

typedef enum
{
	lsStarted = 0,
	lsFinished = 1
} TPlConverterLineState;

typedef uint32_t TPlConverterLineStatesRaw;

typedef enum 
{
	f_lsStarted = 1,
	f_lsFinished = 2
} TPlConverterLineStates;

typedef uint8_t TPlUTF7StateRaw;

typedef enum
{
	usDirect = 0,
	usBase64 = 1,
	usShift = 2
} TPlUTF7State;

typedef Pointer TUserData;

typedef void (SB_CALLBACK *TEnumCharsetsProc)(const char * pcCategory, int32_t szCategory, const char * pcDescription, int32_t szDescription, const char * pcName, int32_t szName, const char * pcAliases, int32_t szAliases, void * UserData, int8_t * Stop);

#ifdef SB_USE_CLASS_TPLCONVERTER
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_Convert(TPlConverterHandle _Handle, const char * pcSource, int32_t szSource, char * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_Convert_1(TPlConverterHandle _Handle, TStreamHandle Source, TStreamHandle Dest, TPlConvertOptionsRaw Options, int32_t MaxChars);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_IsConvert(TPlConverterHandle _Handle, const char * pcSource, int32_t szSource, char * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_IsConvert_1(TPlConverterHandle _Handle, TStreamHandle Source, TStreamHandle Dest, TPlConvertOptionsRaw Options, int32_t MaxChars, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_ConvertFromUnicode(TPlConverterHandle _Handle, const sb_char16_t * pcSource, int32_t szSource, char * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_ConvertToUnicode(TPlConverterHandle _Handle, const char * pcSource, int32_t szSource, sb_char16_t * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_IsConvertFromUnicode(TPlConverterHandle _Handle, const sb_char16_t * pcSource, int32_t szSource, char * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_IsConvertToUnicode(TPlConverterHandle _Handle, const char * pcSource, int32_t szSource, sb_char16_t * pcDest, int32_t * szDest, TPlConvertOptionsRaw Options, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_get_DstCharset(TPlConverterHandle _Handle, IPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_get_DstCharsetName(TPlConverterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_set_DstCharsetName(TPlConverterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_get_SrcCharset(TPlConverterHandle _Handle, IPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_get_SrcCharsetName(TPlConverterHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_set_SrcCharsetName(TPlConverterHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_Create(TPlConverterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_Create_1(const char * pcSrcCharset, int32_t szSrcCharset, const char * pcDstCharset, int32_t szDstCharset, TPlConverterHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConverter_Create_2(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset, TPlConverterHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCONVERTER */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_GetCategory(TPlCustomUTFHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMUTF */

#ifdef SB_USE_CLASS_TPLUTF32
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_ConvertFromUCS(TPlUTF32Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_ConvertToUCS(TPlUTF32Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_ConvertBufferToUCS(TPlUTF32Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_GetDescription(TPlUTF32Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF32 */

#ifdef SB_USE_CLASS_TPLUTF32BE
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32BE_GetDescription(TPlUTF32BEHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32BE_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF32BE_Create(TPlUTF32BEHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF32BE */

#ifdef SB_USE_CLASS_TPLUTF16
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_ConvertFromUCS(TPlUTF16Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_ConvertToUCS(TPlUTF16Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_ConvertBufferToUCS(TPlUTF16Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_GetDescription(TPlUTF16Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF16 */

#ifdef SB_USE_CLASS_TPLUTF16BE
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16BE_GetDescription(TPlUTF16BEHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16BE_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF16BE_Create(TPlUTF16BEHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF16BE */

#ifdef SB_USE_CLASS_TPLUTF8
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_ConvertFromUCS(TPlUTF8Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_ConvertToUCS(TPlUTF8Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_ConvertBufferToUCS(TPlUTF8Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_GetCategory(TPlUTF8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_GetDescription(TPlUTF8Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_Create(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_CreateShift(int32_t Shift, TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_CreateNoInit(TPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF8_CreateForFinalize(TPlCharsetHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF8 */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF7
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF7_ConvertFromUCS(TPlCustomUTF7Handle _Handle, uint32_t Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF7_ConvertToUCS(TPlCustomUTF7Handle _Handle, TStreamHandle Stream, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF7_ConvertBufferToUCS(TPlCustomUTF7Handle _Handle, const void * Buf, int32_t Count, int8_t IsLastChunk, uint32_t * Char, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF7_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomUTF7_Create(TPlCustomUTF7Handle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_GetCategory(TPlUTF7Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_GetDescription(TPlUTF7Handle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_Create(TPlUTF7Handle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7_IMAP
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_IMAP_GetCategory(TPlUTF7_IMAPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_IMAP_GetDescription(TPlUTF7_IMAPHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_IMAP_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlUTF7_IMAP_Create(TPlUTF7_IMAPHandle * OutResult);
#endif /* SB_USE_CLASS_TPLUTF7_IMAP */

#ifdef SB_USE_CLASS_TPLCONVBUFFER
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_CheckString(TPlConvBufferHandle _Handle, TStreamHandle Stream, const char * pcStr, int32_t szStr, int32_t Shift, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_GetByte(TPlConvBufferHandle _Handle, TStreamHandle Stream, int8_t * Exists, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_GetWide(TPlConvBufferHandle _Handle, TStreamHandle Stream, int8_t * Exists, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_GetLong(TPlConvBufferHandle _Handle, TStreamHandle Stream, int8_t * Exists, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_ReturnByte(TPlConvBufferHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_ReturnByte_1(TPlConvBufferHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_ReturnBytes(TPlConvBufferHandle _Handle, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_Flush(TPlConvBufferHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_Put(TPlConvBufferHandle _Handle, const void * Data, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_PutByte(TPlConvBufferHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_PutWordLE(TPlConvBufferHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_RevokeByte(TPlConvBufferHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlConvBuffer_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCONVBUFFER */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Read(TPlCustomStringStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Write(TPlCustomStringStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Seek(TPlCustomStringStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Seek_1(TPlCustomStringStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Clear(TPlCustomStringStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStream_get_Data(TPlAnsiStringStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStream_set_Data(TPlAnsiStringStreamHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStream_get_Data(TPlWideStringStreamHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStream_set_Data(TPlWideStringStreamHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLBYTEARRAYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TPlByteArrayStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPLBYTEARRAYSTREAM */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL
SB_IMPORT uint32_t SB_APIENTRY TPlCustomStringStreamPool_Create(TPlCustomStringStreamPoolHandle * OutResult);
#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStreamPool_AcquireStream(TPlAnsiStringStreamPoolHandle _Handle, TPlAnsiStringStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStreamPool_ReleaseStream(TPlAnsiStringStreamPoolHandle _Handle, TPlAnsiStringStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TPlAnsiStringStreamPool_Create(TPlCustomStringStreamPoolHandle * OutResult);
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStreamPool_AcquireStream(TPlWideStringStreamPoolHandle _Handle, TPlWideStringStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStreamPool_ReleaseStream(TPlWideStringStreamPoolHandle _Handle, TPlWideStringStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TPlWideStringStreamPool_Create(TPlCustomStringStreamPoolHandle * OutResult);
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TPlConverter;
class TPlCustomUTF;
class TPlUTF32;
class TPlUTF32BE;
class TPlUTF16;
class TPlUTF16BE;
class TPlUTF8;
class TPlCustomUTF7;
class TPlUTF7;
class TPlUTF7_IMAP;
class TPlConvBuffer;
class TPlCustomStringStream;
class TPlAnsiStringStream;
class TPlWideStringStream;
class TPlByteArrayStream;
class TPlCustomStringStreamPool;
class TPlAnsiStringStreamPool;
class TPlWideStringStreamPool;

SB_DEFINE_ENUM_FLAG_OPERATORS(TPlConvertOptions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TPlConverterLineStates)

#ifdef SB_USE_CLASS_TPLCONVERTER
class TPlConverter: public TPersistent
{
	private:
		SB_DISABLE_COPY(TPlConverter)
	public:
		void Convert(const std::string &Source, std::string &Dest, TPlConvertOptions Options);

#ifdef SB_USE_CLASS_TSTREAM
		void Convert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars);

		void Convert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars);
#endif /* SB_USE_CLASS_TSTREAM */

		bool IsConvert(const std::string &Source, std::string &Dest, TPlConvertOptions Options);

#ifdef SB_USE_CLASS_TSTREAM
		bool IsConvert(TStream &Source, TStream &Dest, TPlConvertOptions Options, int32_t MaxChars);

		bool IsConvert(TStream *Source, TStream *Dest, TPlConvertOptions Options, int32_t MaxChars);
#endif /* SB_USE_CLASS_TSTREAM */

		void ConvertFromUnicode(const sb_u16string &Source, std::string &Dest, TPlConvertOptions Options);
#ifdef SB_U16STRING_USED
		void ConvertFromUnicode(const std::wstring &Source, std::string &Dest, TPlConvertOptions Options);
#endif /* SB_U16STRING_USED */

		void ConvertToUnicode(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options);
#ifdef SB_U16STRING_USED
		void ConvertToUnicode(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options);
#endif /* SB_U16STRING_USED */

		bool IsConvertFromUnicode(const sb_u16string &Source, std::string &Dest, TPlConvertOptions Options);
#ifdef SB_U16STRING_USED
		bool IsConvertFromUnicode(const std::wstring &Source, std::string &Dest, TPlConvertOptions Options);
#endif /* SB_U16STRING_USED */

		bool IsConvertToUnicode(const std::string &Source, sb_u16string &Dest, TPlConvertOptions Options);
#ifdef SB_U16STRING_USED
		bool IsConvertToUnicode(const std::string &Source, std::wstring &Dest, TPlConvertOptions Options);
#endif /* SB_U16STRING_USED */

#ifdef SB_USE_CLASS_IPLCHARSET
		virtual IPlCharsetHandle get_DstCharset();

		SB_DECLARE_PROPERTY_GET(IPlCharsetHandle, get_DstCharset, TPlConverter, DstCharset);
#endif /* SB_USE_CLASS_IPLCHARSET */

		virtual void get_DstCharsetName(std::string &OutResult);

		virtual void set_DstCharsetName(const std::string &Value);

#ifdef SB_USE_CLASS_IPLCHARSET
		virtual IPlCharsetHandle get_SrcCharset();

		SB_DECLARE_PROPERTY_GET(IPlCharsetHandle, get_SrcCharset, TPlConverter, SrcCharset);
#endif /* SB_USE_CLASS_IPLCHARSET */

		virtual void get_SrcCharsetName(std::string &OutResult);

		virtual void set_SrcCharsetName(const std::string &Value);

		TPlConverter(TPlConverterHandle handle, TElOwnHandle ownHandle);

		TPlConverter();

		TPlConverter(const std::string &SrcCharset, const std::string &DstCharset);

#ifdef SB_USE_CLASS_IPLCHARSET
		TPlConverter(IPlCharsetHandle SrcCharset, IPlCharsetHandle DstCharset);
#endif /* SB_USE_CLASS_IPLCHARSET */

};
#endif /* SB_USE_CLASS_TPLCONVERTER */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF
class TPlCustomUTF: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlCustomUTF)
	public:
		virtual void GetCategory(std::string &OutResult);

		static TClassHandle ClassType();

		TPlCustomUTF(TPlCustomUTFHandle handle, TElOwnHandle ownHandle);

		TPlCustomUTF();

		static TPlCustomUTF CreateShift(int32_t Shift);

		static TPlCustomUTF CreateNoInit();

		static TPlCustomUTF CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLCUSTOMUTF */

#ifdef SB_USE_CLASS_TPLUTF32
class TPlUTF32: public TPlCustomUTF
{
	private:
		SB_DISABLE_COPY(TPlUTF32)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF32(TPlUTF32Handle handle, TElOwnHandle ownHandle);

		TPlUTF32();

		static TPlUTF32 CreateShift(int32_t Shift);

		static TPlUTF32 CreateNoInit();

		static TPlUTF32 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLUTF32 */

#ifdef SB_USE_CLASS_TPLUTF32BE
class TPlUTF32BE: public TPlUTF32
{
	private:
		SB_DISABLE_COPY(TPlUTF32BE)
	public:
		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF32BE(TPlUTF32BEHandle handle, TElOwnHandle ownHandle);

		TPlUTF32BE();

};
#endif /* SB_USE_CLASS_TPLUTF32BE */

#ifdef SB_USE_CLASS_TPLUTF16
class TPlUTF16: public TPlCustomUTF
{
	private:
		SB_DISABLE_COPY(TPlUTF16)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF16(TPlUTF16Handle handle, TElOwnHandle ownHandle);

		TPlUTF16();

		static TPlUTF16 CreateShift(int32_t Shift);

		static TPlUTF16 CreateNoInit();

		static TPlUTF16 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLUTF16 */

#ifdef SB_USE_CLASS_TPLUTF16BE
class TPlUTF16BE: public TPlUTF16
{
	private:
		SB_DISABLE_COPY(TPlUTF16BE)
	public:
		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF16BE(TPlUTF16BEHandle handle, TElOwnHandle ownHandle);

		TPlUTF16BE();

};
#endif /* SB_USE_CLASS_TPLUTF16BE */

#ifdef SB_USE_CLASS_TPLUTF8
class TPlUTF8: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlUTF8)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF8(TPlUTF8Handle handle, TElOwnHandle ownHandle);

		TPlUTF8();

		static TPlUTF8 CreateShift(int32_t Shift);

		static TPlUTF8 CreateNoInit();

		static TPlUTF8 CreateForFinalize();

};
#endif /* SB_USE_CLASS_TPLUTF8 */

#ifdef SB_USE_CLASS_TPLCUSTOMUTF7
class TPlCustomUTF7: public TPlCharset
{
	private:
		SB_DISABLE_COPY(TPlCustomUTF7)
	public:
		virtual int32_t ConvertFromUCS(uint32_t Char);

#ifdef SB_USE_CLASS_TSTREAM
		virtual int32_t ConvertToUCS(TStream &Stream, uint32_t &Char);

		virtual int32_t ConvertToUCS(TStream *Stream, uint32_t &Char);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t ConvertBufferToUCS(const void * Buf, int32_t Count, bool IsLastChunk, uint32_t &Char);

		static TClassHandle ClassType();

		TPlCustomUTF7(TPlCustomUTF7Handle handle, TElOwnHandle ownHandle);

		TPlCustomUTF7();

};
#endif /* SB_USE_CLASS_TPLCUSTOMUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7
class TPlUTF7: public TPlCustomUTF7
{
	private:
		SB_DISABLE_COPY(TPlUTF7)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF7(TPlUTF7Handle handle, TElOwnHandle ownHandle);

		TPlUTF7();

};
#endif /* SB_USE_CLASS_TPLUTF7 */

#ifdef SB_USE_CLASS_TPLUTF7_IMAP
class TPlUTF7_IMAP: public TPlCustomUTF7
{
	private:
		SB_DISABLE_COPY(TPlUTF7_IMAP)
	public:
		virtual void GetCategory(std::string &OutResult);

		virtual void GetDescription(std::string &OutResult);

		static TClassHandle ClassType();

		TPlUTF7_IMAP(TPlUTF7_IMAPHandle handle, TElOwnHandle ownHandle);

		TPlUTF7_IMAP();

};
#endif /* SB_USE_CLASS_TPLUTF7_IMAP */

#ifdef SB_USE_CLASS_TPLCONVBUFFER
class TPlConvBuffer: public TInterfacedObject
{
	private:
		SB_DISABLE_COPY(TPlConvBuffer)
	public:
#ifdef SB_USE_CLASS_TSTREAM
		bool CheckString(TStream &Stream, const std::string &Str, int32_t Shift);

		bool CheckString(TStream *Stream, const std::string &Str, int32_t Shift);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		uint8_t GetByte(TStream &Stream, bool &Exists);

		uint8_t GetByte(TStream *Stream, bool &Exists);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		uint16_t GetWide(TStream &Stream, bool &Exists);

		uint16_t GetWide(TStream *Stream, bool &Exists);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		uint32_t GetLong(TStream &Stream, bool &Exists);

		uint32_t GetLong(TStream *Stream, bool &Exists);
#endif /* SB_USE_CLASS_TSTREAM */

		void ReturnByte();

		void ReturnByte(uint8_t Value);

		void ReturnBytes(int32_t Count);

#ifdef SB_USE_CLASS_TSTREAM
		void Flush(TStream &Stream);

		void Flush(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Put(const void * Data, int32_t Count);

		void PutByte(uint8_t Value);

		void PutWordLE(uint16_t Value);

		uint8_t RevokeByte();

		TPlConvBuffer(TPlConvBufferHandle handle, TElOwnHandle ownHandle);

		TPlConvBuffer();

};
#endif /* SB_USE_CLASS_TPLCONVBUFFER */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM
class TPlCustomStringStream: public TStream
{
	private:
		SB_DISABLE_COPY(TPlCustomStringStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		void Clear();

		TPlCustomStringStream(TPlCustomStringStreamHandle handle, TElOwnHandle ownHandle);

		TPlCustomStringStream();

};
#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
class TPlAnsiStringStream: public TPlCustomStringStream
{
	private:
		SB_DISABLE_COPY(TPlAnsiStringStream)
	public:
		virtual void get_Data(std::string &OutResult);

		virtual void set_Data(const std::string &Value);

		TPlAnsiStringStream(TPlAnsiStringStreamHandle handle, TElOwnHandle ownHandle);

		TPlAnsiStringStream();

};
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
class TPlWideStringStream: public TPlCustomStringStream
{
	private:
		SB_DISABLE_COPY(TPlWideStringStream)
	public:
		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Data(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Data(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TPlWideStringStream(TPlWideStringStreamHandle handle, TElOwnHandle ownHandle);

		TPlWideStringStream();

};
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLBYTEARRAYSTREAM
class TPlByteArrayStream: public TStream
{
	private:
		SB_DISABLE_COPY(TPlByteArrayStream)
	public:
		TPlByteArrayStream(TPlByteArrayStreamHandle handle, TElOwnHandle ownHandle);

		TPlByteArrayStream();

};
#endif /* SB_USE_CLASS_TPLBYTEARRAYSTREAM */

#ifdef SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL
class TPlCustomStringStreamPool: public TObject
{
	private:
		SB_DISABLE_COPY(TPlCustomStringStreamPool)
	public:
		TPlCustomStringStreamPool(TPlCustomStringStreamPoolHandle handle, TElOwnHandle ownHandle);

		TPlCustomStringStreamPool();

};
#endif /* SB_USE_CLASS_TPLCUSTOMSTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL
class TPlAnsiStringStreamPool: public TPlCustomStringStreamPool
{
	private:
		SB_DISABLE_COPY(TPlAnsiStringStreamPool)
	public:
#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
		TPlAnsiStringStreamHandle AcquireStream();
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLANSISTRINGSTREAM
		void ReleaseStream(TPlAnsiStringStream &Stream);

		void ReleaseStream(TPlAnsiStringStream *Stream);
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAM */

		TPlAnsiStringStreamPool(TPlAnsiStringStreamPoolHandle handle, TElOwnHandle ownHandle);

		TPlAnsiStringStreamPool();

};
#endif /* SB_USE_CLASS_TPLANSISTRINGSTREAMPOOL */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL
class TPlWideStringStreamPool: public TPlCustomStringStreamPool
{
	private:
		SB_DISABLE_COPY(TPlWideStringStreamPool)
	public:
#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
		TPlWideStringStreamHandle AcquireStream();
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

#ifdef SB_USE_CLASS_TPLWIDESTRINGSTREAM
		void ReleaseStream(TPlWideStringStream &Stream);

		void ReleaseStream(TPlWideStringStream *Stream);
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAM */

		TPlWideStringStreamPool(TPlWideStringStreamPoolHandle handle, TElOwnHandle ownHandle);

		TPlWideStringStreamPool();

};
#endif /* SB_USE_CLASS_TPLWIDESTRINGSTREAMPOOL */

#ifdef SB_USE_GLOBAL_PROCS_CHSCONV

void EnumCharsets(void * EnumProc, void * UserData);

#ifdef SB_USE_CLASS_IPLCHARSET
IPlCharsetHandle CreateCharset(const std::string &Name);
#endif /* SB_USE_CLASS_IPLCHARSET */

#ifdef SB_USE_CLASS_IPLCHARSET
IPlCharsetHandle CreateCharsetByDescription(const std::string &ADescription);
#endif /* SB_USE_CLASS_IPLCHARSET */

#ifdef SB_USE_CLASS_IPLCHARSET
IPlCharsetHandle CreateSystemDefaultCharset();
#endif /* SB_USE_CLASS_IPLCHARSET */

void GetSystemDefaultCharsetName(std::string &OutResult);

void GetCharsetNameByAlias(const std::string &Alias, std::string &OutResult);

void InitializeCharsetObjects();

#endif /* SB_USE_GLOBAL_PROCS_CHSCONV */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CHSCONV
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_EnumCharsets(void * EnumProc, void * UserData);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_CreateCharset(const char * pcName, int32_t szName, IPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_CreateCharsetByDescription(const char * pcADescription, int32_t szADescription, IPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_CreateSystemDefaultCharset(IPlCharsetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_GetSystemDefaultCharsetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_GetCharsetNameByAlias(const char * pcAlias, int32_t szAlias, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBChSConv_InitializeCharsetObjects(void);
#endif /* SB_USE_GLOBAL_PROCS_CHSCONV */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCHSCONV */

