#ifndef __INC_SBMIMEENC
#define __INC_SBMIMEENC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbmimestream.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_cSplitOutLenDef 	70
#define SB_cMinusOne 	-1

typedef TElClassHandle TElMimeEncodingStreamHandle;

typedef TElClassHandle TElBase64StreamHandle;

typedef TElClassHandle TElQuotedPrintableStreamHandle;

typedef TElClassHandle TEl7BitStreamHandle;

typedef TElClassHandle TEl8BitStreamHandle;

typedef TElClassHandle TElBinaryStreamHandle;

typedef TElMimeEncodingStreamHandle ElMimeEncodingStreamHandle;

typedef TElBase64StreamHandle ElBase64StreamHandle;

typedef TElQuotedPrintableStreamHandle ElQuotedPrintableStreamHandle;

typedef TEl7BitStreamHandle El7BitStreamHandle;

typedef TEl8BitStreamHandle El8BitStreamHandle;

typedef TElBinaryStreamHandle ElBinaryStreamHandle;

typedef TElClassHandle TElMimeEncodingStreamClassHandle;

typedef TElMimeEncodingStreamClassHandle ElMimeEncodingStreamClassHandle;

typedef uint8_t TElEncodingTypeRaw;

typedef enum
{
	etNotEncoded = 0,
	etQuotedPrintable = 1,
	etBase64 = 2
} TElEncodingType;

typedef TElEncodingType ElEncodingType;

#ifdef SB_USE_CLASS_TELMIMEENCODINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_ReInit(TElMimeEncodingStreamHandle _Handle, TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream__CopyTo(TElMimeEncodingStreamHandle _Handle, TStreamHandle DestStream, int64_t Count, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_Seek(TElMimeEncodingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_Seek_1(TElMimeEncodingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_GetEncodingName_1(TElMimeEncodingStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_GetEncodedSize(TElMimeEncodingStreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_GetDecodedSize(TElMimeEncodingStreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_get_IsErrorOccured(TElMimeEncodingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_get_Stream(TElMimeEncodingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_set_Stream(TElMimeEncodingStreamHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_get_SplitOnLen(TElMimeEncodingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_set_SplitOnLen(TElMimeEncodingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_Create(TElMimeEncodingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMimeEncodingStream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElMimeEncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELMIMEENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELBASE64STREAM
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_ReInit(TElBase64StreamHandle _Handle, TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_Read(TElBase64StreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_Write(TElBase64StreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_Flush(TElBase64StreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_GetEncodedSize(TElBase64StreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_GetDecodedSize(TElBase64StreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_GetEncodingName_1(TElBase64StreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_Create(TElBase64StreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBase64Stream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElBase64StreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELBASE64STREAM */

#ifdef SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_Read(TElQuotedPrintableStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_Write(TElQuotedPrintableStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_GetEncodedSize(TElQuotedPrintableStreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_GetDecodedSize(TElQuotedPrintableStreamHandle _Handle, int32_t SourceSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_GetEncodingName_1(TElQuotedPrintableStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_Create(TElMimeEncodingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElQuotedPrintableStream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElMimeEncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM */

#ifdef SB_USE_CLASS_TEL7BITSTREAM
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_Read(TEl7BitStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_Write(TEl7BitStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_GetEncodingName_1(TEl7BitStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_ReInit(TEl7BitStreamHandle _Handle, TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_get_Passthrough(TEl7BitStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_set_Passthrough(TEl7BitStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_Create(TElMimeEncodingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl7BitStream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElMimeEncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TEL7BITSTREAM */

#ifdef SB_USE_CLASS_TEL8BITSTREAM
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_Read(TEl8BitStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_Write(TEl8BitStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_GetEncodingName_1(TEl8BitStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_Create(TElMimeEncodingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TEl8BitStream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElMimeEncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TEL8BITSTREAM */

#ifdef SB_USE_CLASS_TELBINARYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElBinaryStream_GetEncodingName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBinaryStream_GetEncodingName_1(TElBinaryStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBinaryStream_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBinaryStream_Create(TElMimeEncodingStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBinaryStream_Create_1(TStreamHandle Stream, int32_t StreamLen, int32_t SplitOnLen, TElMimeEncodingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELBINARYSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMimeEncodingStream;
class TElBase64Stream;
class TElQuotedPrintableStream;
class TEl7BitStream;
class TEl8BitStream;
class TElBinaryStream;
typedef TElMimeEncodingStream ElMimeEncodingStream;
typedef TElBase64Stream ElBase64Stream;
typedef TElQuotedPrintableStream ElQuotedPrintableStream;
typedef TEl7BitStream El7BitStream;
typedef TEl8BitStream El8BitStream;
typedef TElBinaryStream ElBinaryStream;

#ifdef SB_USE_CLASS_TELMIMEENCODINGSTREAM
class TElMimeEncodingStream: public TElCustomMIMEStream
{
	private:
		SB_DISABLE_COPY(TElMimeEncodingStream)
		TStream* _Inst_Stream;

		void initInstances();

	public:
		virtual void ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual void ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual int64_t _CopyTo(TStream &DestStream, int64_t Count);

		virtual int64_t _CopyTo(TStream *DestStream, int64_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		virtual int32_t GetEncodedSize(int32_t SourceSize);

		virtual int32_t GetDecodedSize(int32_t SourceSize);

		static TClassHandle ClassType();

		virtual bool get_IsErrorOccured();

		SB_DECLARE_PROPERTY_GET(bool, get_IsErrorOccured, TElMimeEncodingStream, IsErrorOccured);

		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElMimeEncodingStream, Stream);

		virtual int32_t get_SplitOnLen();

		virtual void set_SplitOnLen(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SplitOnLen, set_SplitOnLen, TElMimeEncodingStream, SplitOnLen);

		TElMimeEncodingStream(TElMimeEncodingStreamHandle handle, TElOwnHandle ownHandle);

		TElMimeEncodingStream();

		TElMimeEncodingStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TElMimeEncodingStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual ~TElMimeEncodingStream();

};
#endif /* SB_USE_CLASS_TELMIMEENCODINGSTREAM */

#ifdef SB_USE_CLASS_TELBASE64STREAM
class TElBase64Stream: public TElMimeEncodingStream
{
	private:
		SB_DISABLE_COPY(TElBase64Stream)
	public:
		virtual void ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual void ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual void Flush();

		virtual int32_t GetEncodedSize(int32_t SourceSize);

		virtual int32_t GetDecodedSize(int32_t SourceSize);

		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		TElBase64Stream(TElBase64StreamHandle handle, TElOwnHandle ownHandle);

		TElBase64Stream();

		TElBase64Stream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TElBase64Stream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

};
#endif /* SB_USE_CLASS_TELBASE64STREAM */

#ifdef SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM
class TElQuotedPrintableStream: public TElMimeEncodingStream
{
	private:
		SB_DISABLE_COPY(TElQuotedPrintableStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t GetEncodedSize(int32_t SourceSize);

		virtual int32_t GetDecodedSize(int32_t SourceSize);

		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		TElQuotedPrintableStream(TElQuotedPrintableStreamHandle handle, TElOwnHandle ownHandle);

		TElQuotedPrintableStream();

		TElQuotedPrintableStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TElQuotedPrintableStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

};
#endif /* SB_USE_CLASS_TELQUOTEDPRINTABLESTREAM */

#ifdef SB_USE_CLASS_TEL7BITSTREAM
class TEl7BitStream: public TElMimeEncodingStream
{
	private:
		SB_DISABLE_COPY(TEl7BitStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		virtual void ReInit(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		virtual void ReInit(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

		static TClassHandle ClassType();

		virtual bool get_Passthrough();

		virtual void set_Passthrough(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Passthrough, set_Passthrough, TEl7BitStream, Passthrough);

		TEl7BitStream(TEl7BitStreamHandle handle, TElOwnHandle ownHandle);

		TEl7BitStream();

		TEl7BitStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TEl7BitStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

};
#endif /* SB_USE_CLASS_TEL7BITSTREAM */

#ifdef SB_USE_CLASS_TEL8BITSTREAM
class TEl8BitStream: public TElMimeEncodingStream
{
	private:
		SB_DISABLE_COPY(TEl8BitStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		TEl8BitStream(TEl8BitStreamHandle handle, TElOwnHandle ownHandle);

		TEl8BitStream();

		TEl8BitStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TEl8BitStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

};
#endif /* SB_USE_CLASS_TEL8BITSTREAM */

#ifdef SB_USE_CLASS_TELBINARYSTREAM
class TElBinaryStream: public TEl8BitStream
{
	private:
		SB_DISABLE_COPY(TElBinaryStream)
	public:
		static void GetEncodingName(std::string &OutResult);

		virtual void GetEncodingName_Inst(std::string &OutResult);

		static TClassHandle ClassType();

		TElBinaryStream(TElBinaryStreamHandle handle, TElOwnHandle ownHandle);

		TElBinaryStream();

		TElBinaryStream(TStream &Stream, int32_t StreamLen, int32_t SplitOnLen);

		TElBinaryStream(TStream *Stream, int32_t StreamLen, int32_t SplitOnLen);

};
#endif /* SB_USE_CLASS_TELBINARYSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_MIMEENC

void DecodeHeader(const std::string &EncodedStr, TElEncodingType Encoding, std::string &OutCodePage, std::string &DecodedStr);

void EncodeQuotedPrintableBodyForHeader(const std::string &Source, int32_t &Offset, int32_t Max, std::string &Dest);

void ToBase64(uint8_t b1, uint8_t b2, uint8_t b3, std::vector<char> &OutCh);

void ToBase64(uint8_t b1, uint8_t b2, std::vector<char> &OutCh);

void ToBase64(uint8_t b1, std::vector<char> &OutCh);

void ToBase64(std::vector<char> &InpCh, int32_t InpLen, std::vector<char> &OutCh);

void ToBase64(std::vector<char> &InpCh, int32_t StartIdx, int32_t InpLen, std::vector<char> &OutCh);

void ToBase64(const std::string &InpStr, int32_t SplitOnLen, std::string &OutResult);

bool FromBase64(std::vector<char> &InpCh, int32_t InpLen, std::vector<char> &OutCh, int32_t &OutLen);

bool FromBase64(const std::string &sBase64, std::string &sOutData);

#endif /* SB_USE_GLOBAL_PROCS_MIMEENC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MIMEENC
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_DecodeHeader(const char * pcEncodedStr, int32_t szEncodedStr, TElEncodingTypeRaw Encoding, char * pcOutCodePage, int32_t * szOutCodePage, char * pcDecodedStr, int32_t * szDecodedStr);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_EncodeQuotedPrintableBodyForHeader(const char * pcSource, int32_t szSource, int32_t * Offset, int32_t Max, char * pcDest, int32_t * szDest);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64(uint8_t b1, uint8_t b2, uint8_t b3, char pOutCh[], int32_t * szOutCh);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64_1(uint8_t b1, uint8_t b2, char pOutCh[], int32_t * szOutCh);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64_2(uint8_t b1, char pOutCh[], int32_t * szOutCh);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64_3(char pInpCh[], int32_t * szInpCh, int32_t InpLen, char pOutCh[], int32_t * szOutCh);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64_4(char pInpCh[], int32_t * szInpCh, int32_t StartIdx, int32_t InpLen, char pOutCh[], int32_t * szOutCh);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_ToBase64_5(const char * pcInpStr, int32_t szInpStr, int32_t SplitOnLen, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_FromBase64(char pInpCh[], int32_t * szInpCh, int32_t InpLen, char pOutCh[], int32_t * szOutCh, int32_t * OutLen, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMIMEEnc_FromBase64_1(const char * pcsBase64, int32_t szsBase64, char * pcsOutData, int32_t * szsOutData, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_MIMEENC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMIMEENC */

