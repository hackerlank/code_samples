#ifndef __INC_SBMIMESTREAM
#define __INC_SBMIMESTREAM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_rsStreamReadError 	"Stream read error"
#define SB_rsCannotOpenFile 	"Cannot open file \"%s\""

typedef TElClassHandle TElCustomMIMEStreamHandle;

typedef TElClassHandle TNullMIMEStreamHandle;

typedef TElClassHandle TElCustomMemoryMIMEStreamHandle;

typedef TElClassHandle TElMemoryMIMEStreamHandle;

typedef TElClassHandle TAnsiStringMIMEStreamHandle;

typedef TElClassHandle TWideStringMIMEStreamHandle;

typedef TElCustomMIMEStreamHandle ElCustomStreamHandle;

typedef TElMemoryMIMEStreamHandle ElMemoryStreamHandle;

typedef TElCustomMemoryMIMEStreamHandle ElCustomMemoryStreamHandle;

#ifdef SB_USE_CLASS_TELCUSTOMMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_Flush(TElCustomMIMEStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_CopyFrom(TElCustomMIMEStreamHandle _Handle, TStreamHandle SrcStream, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream__CopyTo(TElCustomMIMEStreamHandle _Handle, TStreamHandle DestStream, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_Squeeze(TElCustomMIMEStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_Reserve(TElCustomMIMEStreamHandle _Handle, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_get_Capacity(TElCustomMIMEStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_set_Capacity(TElCustomMIMEStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMIMEStream_Create(TElCustomMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMMIMESTREAM */

#ifdef SB_USE_CLASS_TNULLMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Read(TNullMIMEStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Write(TNullMIMEStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Seek(TNullMIMEStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Seek_1(TNullMIMEStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Create(TNullMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TNullMIMEStream_Create_1(int64_t ASize, TNullMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TNULLMIMESTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_SetMemory(TElCustomMemoryMIMEStreamHandle _Handle, const uint8_t pValue[], int32_t szValue, int64_t ASize);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_SaveToStream(TElCustomMemoryMIMEStreamHandle _Handle, TStreamHandle Stream, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_SaveToFileEx(TElCustomMemoryMIMEStreamHandle _Handle, const sb_char16_t * pcFileName, int32_t szFileName, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_SaveToFile(TElCustomMemoryMIMEStreamHandle _Handle, const sb_char16_t * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_LoadFromStream(TElCustomMemoryMIMEStreamHandle _Handle, TStreamHandle Stream, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_LoadFromFileEx(TElCustomMemoryMIMEStreamHandle _Handle, const sb_char16_t * pcFileName, int32_t szFileName, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_LoadFromFile(TElCustomMemoryMIMEStreamHandle _Handle, const sb_char16_t * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Read(TElCustomMemoryMIMEStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Write(TElCustomMemoryMIMEStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Seek(TElCustomMemoryMIMEStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Seek_1(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Clear(TElCustomMemoryMIMEStreamHandle _Handle, int64_t NewCapacity);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Squeeze(TElCustomMemoryMIMEStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Reserve(TElCustomMemoryMIMEStreamHandle _Handle, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_SizePos(TElCustomMemoryMIMEStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_get_Memory(TElCustomMemoryMIMEStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_set_Memory(TElCustomMemoryMIMEStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_get_MemoryDelta(TElCustomMemoryMIMEStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_set_MemoryDelta(TElCustomMemoryMIMEStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Create(TElCustomMemoryMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomMemoryMIMEStream_Create_1(int64_t ACapacity, TElCustomMemoryMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TELMEMORYMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_get_Memory(TElMemoryMIMEStreamHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_set_Memory(TElMemoryMIMEStreamHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_get_Bytes(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_set_Bytes(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_get_Words(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_set_Words(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_Create(TElCustomMemoryMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryMIMEStream_Create_1(int64_t ACapacity, TElCustomMemoryMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TANSISTRINGMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_GetAnsiStringMIMEStream(TAnsiStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_GetAnsiStringMIMEStream_1(TAnsiStringMIMEStreamHandle _Handle, TAnsiStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_WriteChar(TAnsiStringMIMEStreamHandle _Handle, char ch);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_WriteString(TAnsiStringMIMEStreamHandle _Handle, const char * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_get_AnsiLength(TAnsiStringMIMEStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_set_AnsiLength(TAnsiStringMIMEStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_get_AnsiData(TAnsiStringMIMEStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_set_AnsiData(TAnsiStringMIMEStreamHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_get_Bytes(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_set_Bytes(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_get_Chars(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_set_Chars(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, char Value);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_Create(TAnsiStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_Create_1(const char * pcsValue, int32_t szsValue, TAnsiStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TAnsiStringMIMEStream_Create_2(int64_t ACapacity, TAnsiStringMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TANSISTRINGMIMESTREAM */

#ifdef SB_USE_CLASS_TWIDESTRINGMIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_WriteWChar(TWideStringMIMEStreamHandle _Handle, sb_char16_t ch);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_WriteWString(TWideStringMIMEStreamHandle _Handle, const sb_char16_t * pcS, int32_t szS, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_get_CurrentWord(TWideStringMIMEStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_get_WideData(TWideStringMIMEStreamHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_set_WideData(TWideStringMIMEStreamHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_get_WideLength(TWideStringMIMEStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_set_WideLength(TWideStringMIMEStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_get_Words(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_set_Words(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_get_WChars(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, sb_char16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_set_WChars(TElCustomMemoryMIMEStreamHandle _Handle, int64_t Index, sb_char16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_Create(TWideStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_Create_1(const sb_char16_t * pcwsValue, int32_t szwsValue, TWideStringMIMEStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TWideStringMIMEStream_Create_2(int64_t ACapacity, TWideStringMIMEStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TWIDESTRINGMIMESTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomMIMEStream;
class TNullMIMEStream;
class TElCustomMemoryMIMEStream;
class TElMemoryMIMEStream;
class TAnsiStringMIMEStream;
class TWideStringMIMEStream;
typedef TElCustomMIMEStream ElCustomStream;
typedef TElMemoryMIMEStream ElMemoryStream;
typedef TElCustomMemoryMIMEStream ElCustomMemoryStream;

#ifdef SB_USE_CLASS_TELCUSTOMMIMESTREAM
class TElCustomMIMEStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElCustomMIMEStream)
	public:
		virtual void Flush();

		virtual int64_t CopyFrom(TStream &SrcStream, int64_t Count);

		virtual int64_t CopyFrom(TStream *SrcStream, int64_t Count);

		virtual int64_t _CopyTo(TStream &DestStream, int64_t Count);

		virtual int64_t _CopyTo(TStream *DestStream, int64_t Count);

		virtual void Squeeze();

		virtual void Reserve(int32_t Count);

		virtual int64_t get_Capacity();

		virtual void set_Capacity(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Capacity, set_Capacity, TElCustomMIMEStream, Capacity);

		TElCustomMIMEStream(TElCustomMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TElCustomMIMEStream();

};
#endif /* SB_USE_CLASS_TELCUSTOMMIMESTREAM */

#ifdef SB_USE_CLASS_TNULLMIMESTREAM
class TNullMIMEStream: public TElCustomMIMEStream
{
	private:
		SB_DISABLE_COPY(TNullMIMEStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TNullMIMEStream(TNullMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TNullMIMEStream();

		explicit TNullMIMEStream(int64_t ASize);

};
#endif /* SB_USE_CLASS_TNULLMIMESTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM
class TElCustomMemoryMIMEStream: public TElCustomMIMEStream
{
	private:
		SB_DISABLE_COPY(TElCustomMemoryMIMEStream)
	public:
		void SetMemory(const std::vector<uint8_t> &Value, int64_t ASize);

		int64_t SaveToStream(TStream &Stream, int64_t Count);

		int64_t SaveToStream(TStream *Stream, int64_t Count);

		int64_t SaveToFileEx(const sb_u16string &FileName, int64_t Count);
#ifdef SB_U16STRING_USED
		int64_t SaveToFileEx(const std::wstring &FileName, int64_t Count);
#endif /* SB_U16STRING_USED */

		void SaveToFile(const sb_u16string &FileName);
#ifdef SB_U16STRING_USED
		void SaveToFile(const std::wstring &FileName);
#endif /* SB_U16STRING_USED */

		int64_t LoadFromStream(TStream &Stream, int64_t Count);

		int64_t LoadFromStream(TStream *Stream, int64_t Count);

		int64_t LoadFromFileEx(const sb_u16string &FileName, int64_t Count);
#ifdef SB_U16STRING_USED
		int64_t LoadFromFileEx(const std::wstring &FileName, int64_t Count);
#endif /* SB_U16STRING_USED */

		void LoadFromFile(const sb_u16string &FileName);
#ifdef SB_U16STRING_USED
		void LoadFromFile(const std::wstring &FileName);
#endif /* SB_U16STRING_USED */

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		void Clear(int64_t NewCapacity);

		virtual void Squeeze();

		virtual void Reserve(int32_t Count);

		int64_t SizePos();

		virtual void get_Memory(std::vector<uint8_t> &OutResult);

		virtual void set_Memory(const std::vector<uint8_t> &Value);

		virtual int32_t get_MemoryDelta();

		virtual void set_MemoryDelta(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MemoryDelta, set_MemoryDelta, TElCustomMemoryMIMEStream, MemoryDelta);

		TElCustomMemoryMIMEStream(TElCustomMemoryMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TElCustomMemoryMIMEStream();

		explicit TElCustomMemoryMIMEStream(int64_t ACapacity);

};
#endif /* SB_USE_CLASS_TELCUSTOMMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TELMEMORYMIMESTREAM
class TElMemoryMIMEStream: public TElCustomMemoryMIMEStream
{
	private:
		SB_DISABLE_COPY(TElMemoryMIMEStream)
	public:
		virtual void get_Memory(std::vector<uint8_t> &OutResult);

		virtual void set_Memory(const std::vector<uint8_t> &Value);

		virtual uint8_t get_Bytes(int64_t Index);

		virtual void set_Bytes(int64_t Index, uint8_t Value);

		virtual uint16_t get_Words(int64_t Index);

		virtual void set_Words(int64_t Index, uint16_t Value);

		TElMemoryMIMEStream(TElMemoryMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TElMemoryMIMEStream();

		explicit TElMemoryMIMEStream(int64_t ACapacity);

};
#endif /* SB_USE_CLASS_TELMEMORYMIMESTREAM */

#ifdef SB_USE_CLASS_TANSISTRINGMIMESTREAM
class TAnsiStringMIMEStream: public TElCustomMemoryMIMEStream
{
	private:
		SB_DISABLE_COPY(TAnsiStringMIMEStream)
	public:
		static TAnsiStringMIMEStreamHandle GetAnsiStringMIMEStream();

		TAnsiStringMIMEStreamHandle GetAnsiStringMIMEStream_Inst();

		void WriteChar(char ch);

		int64_t WriteString(const std::string &S);

		virtual int64_t get_AnsiLength();

		virtual void set_AnsiLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_AnsiLength, set_AnsiLength, TAnsiStringMIMEStream, AnsiLength);

		virtual void get_AnsiData(std::string &OutResult);

		virtual void set_AnsiData(const std::string &Value);

		virtual uint8_t get_Bytes(int64_t Index);

		virtual void set_Bytes(int64_t Index, uint8_t Value);

		virtual char get_Chars(int64_t Index);

		virtual void set_Chars(int64_t Index, char Value);

		TAnsiStringMIMEStream(TAnsiStringMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TAnsiStringMIMEStream();

		explicit TAnsiStringMIMEStream(const std::string &sValue);

		explicit TAnsiStringMIMEStream(int64_t ACapacity);

};
#endif /* SB_USE_CLASS_TANSISTRINGMIMESTREAM */

#ifdef SB_USE_CLASS_TWIDESTRINGMIMESTREAM
class TWideStringMIMEStream: public TElCustomMemoryMIMEStream
{
	private:
		SB_DISABLE_COPY(TWideStringMIMEStream)
	public:
		void WriteWChar(sb_char16_t ch);

		int64_t WriteWString(const sb_u16string &S);
#ifdef SB_U16STRING_USED
		int64_t WriteWString(const std::wstring &S);
#endif /* SB_U16STRING_USED */

		virtual int32_t get_CurrentWord();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CurrentWord, TWideStringMIMEStream, CurrentWord);

		virtual void get_WideData(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_WideData(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_WideData(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_WideData(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual int64_t get_WideLength();

		virtual void set_WideLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_WideLength, set_WideLength, TWideStringMIMEStream, WideLength);

		virtual uint16_t get_Words(int64_t Index);

		virtual void set_Words(int64_t Index, uint16_t Value);

		virtual sb_char16_t get_WChars(int64_t Index);

		virtual void set_WChars(int64_t Index, sb_char16_t Value);

		TWideStringMIMEStream(TWideStringMIMEStreamHandle handle, TElOwnHandle ownHandle);

		TWideStringMIMEStream();

		explicit TWideStringMIMEStream(const sb_u16string &wsValue);

#ifdef SB_U16STRING_USED
		explicit TWideStringMIMEStream(const std::wstring &wsValue);

#endif /* SB_U16STRING_USED */
		explicit TWideStringMIMEStream(int64_t ACapacity);

};
#endif /* SB_USE_CLASS_TWIDESTRINGMIMESTREAM */

#ifdef SB_USE_GLOBAL_PROCS_MIMESTREAM

#ifdef SB_USE_CLASS_TSTREAM
int64_t WriteStringToStream(const std::vector<uint8_t> &S, TStream &Stream, int64_t LPos, int64_t Count);
int64_t WriteStringToStream(const std::vector<uint8_t> &S, TStream *Stream, int64_t LPos, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t WriteStringToStream(const std::string &S, TStream &Stream, int64_t LPos, int64_t Count);
int64_t WriteStringToStream(const std::string &S, TStream *Stream, int64_t LPos, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t WriteWideStringToStream(const sb_u16string &S, TStream &Stream);
int64_t WriteWideStringToStream(const sb_u16string &S, TStream *Stream);
#ifdef SB_U16STRING_USED
int64_t WriteWideStringToStream(const std::wstring &S, TStream &Stream);
int64_t WriteWideStringToStream(const std::wstring &S, TStream *Stream);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t WriteStreamToStream(TStream &Source, TStream &Dest, int64_t Count);
int64_t WriteStreamToStream(TStream *Source, TStream *Dest, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool ReadLineFromStream(TStream &Source, TStream &smDest, int32_t &iLineLength, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL);
bool ReadLineFromStream(TStream *Source, TStream *smDest, int32_t &iLineLength, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool ReadLineFromStream(TStream &Source, std::string &sDest, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL);
bool ReadLineFromStream(TStream *Source, std::string &sDest, int32_t MaxLineLength, bool bReadLongLine, bool bSeekLongToEOL);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t SeekStreamToEnd(TStream &Stream);
int64_t SeekStreamToEnd(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_MIMESTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MIMESTREAM
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_WriteStringToStream(const uint8_t pS[], int32_t szS, TStreamHandle Stream, int64_t LPos, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_WriteStringToStream_1(const char * pcS, int32_t szS, TStreamHandle Stream, int64_t LPos, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_WriteWideStringToStream(const sb_char16_t * pcS, int32_t szS, TStreamHandle Stream, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_WriteStreamToStream(TStreamHandle Source, TStreamHandle Dest, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_ReadLineFromStream(TStreamHandle Source, TStreamHandle smDest, int32_t * iLineLength, int32_t MaxLineLength, int8_t bReadLongLine, int8_t bSeekLongToEOL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_ReadLineFromStream_1(TStreamHandle Source, char * pcsDest, int32_t * szsDest, int32_t MaxLineLength, int8_t bReadLongLine, int8_t bSeekLongToEOL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEStream_SeekStreamToEnd(TStreamHandle Stream, int64_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_MIMESTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMIMESTREAM */

