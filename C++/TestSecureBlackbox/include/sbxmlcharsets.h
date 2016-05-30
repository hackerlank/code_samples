#ifndef __INC_SBXMLCHARSETS
#define __INC_SBXMLCHARSETS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbchsconvbase.h"
#include "sbchsconv.h"
#include "sbxmldefs.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_BUFFER_SIZE
#define SB_BUFFER_SIZE 	262144
#endif

typedef TElClassHandle TElXMLBufferingStreamHandle;

typedef TElClassHandle TElXMLCodecHandle;

typedef TElXMLCodecHandle ElXMLCodecHandle;

typedef TElClassHandle TElXML8BitCodecHandle;

typedef TElXML8BitCodecHandle ElXML8BitCodecHandle;

typedef TElClassHandle TElXMLUTF8CodecHandle;

typedef TElXMLUTF8CodecHandle ElXMLUTF8CodecHandle;

typedef TElClassHandle TElXMLUnicodeCodecHandle;

typedef TElXMLUnicodeCodecHandle ElXMLUnicodeCodecHandle;

typedef TElClassHandle TElXMLStringCodecHandle;

typedef TElXMLStringCodecHandle ElXMLStringCodecHandle;

#ifdef SB_USE_CLASS_TELXMLBUFFERINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Read(TElXMLBufferingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Write(TElXMLBufferingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Seek(TElXMLBufferingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Seek_1(TElXMLBufferingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Flush(TElXMLBufferingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_get_Stream(TElXMLBufferingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_set_Stream(TElXMLBufferingStreamHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_get_EndOfFile(TElXMLBufferingStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLBufferingStream_Create(TElXMLBufferingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLBUFFERINGSTREAM */

#ifdef SB_USE_CLASS_TELXMLCODEC
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_MigrateTo(TElXMLCodecHandle _Handle, TElXMLCodecHandle Codec);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Flush(TElXMLCodecHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_NextChar(TElXMLCodecHandle _Handle, sb_char16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_WriteChar(TElXMLCodecHandle _Handle, sb_char16_t c);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_WriteStartup(TElXMLCodecHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Detect(TElXMLCodecHandle _Handle, const char * pcDefaultEncoding, int32_t szDefaultEncoding, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Detect_1(TStreamHandle aStream, const char * pcDefaultEncoding, int32_t szDefaultEncoding, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Detect_2(TElXMLCodecHandle _Handle, TStreamHandle aStream, const char * pcDefaultEncoding, int32_t szDefaultEncoding, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_GetCodec(const char * pcaEnc, int32_t szaEnc, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_GetCodec_1(TElXMLCodecHandle _Handle, const char * pcaEnc, int32_t szaEnc, TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_Stream(TElXMLCodecHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_set_Stream(TElXMLCodecHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_sEOF(TElXMLCodecHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_sPos(TElXMLCodecHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_set_sPos(TElXMLCodecHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_sSize(TElXMLCodecHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_set_sSize(TElXMLCodecHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_Name(TElXMLCodecHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_get_WriteBOM(TElXMLCodecHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_set_WriteBOM(TElXMLCodecHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Create(TElXMLCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLCodec_Create_1(TStreamHandle aStream, TElXMLCodecHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLCODEC */

#ifdef SB_USE_CLASS_TELXML8BITCODEC
SB_IMPORT uint32_t SB_APIENTRY TElXML8BitCodec_get_Charset(TElXML8BitCodecHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXML8BitCodec_set_Charset(TElXML8BitCodecHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXML8BitCodec_Create(TElXML8BitCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXML8BitCodec_Create_1(const char * pcaEncoding, int32_t szaEncoding, TElXML8BitCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXML8BitCodec_Create_2(TStreamHandle aStream, TElXML8BitCodecHandle * OutResult);
#endif /* SB_USE_CLASS_TELXML8BITCODEC */

#ifdef SB_USE_CLASS_TELXMLUTF8CODEC
SB_IMPORT uint32_t SB_APIENTRY TElXMLUTF8Codec_Create(TElXMLUTF8CodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUTF8Codec_Create_1(TStreamHandle aStream, TElXMLUTF8CodecHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUTF8CODEC */

#ifdef SB_USE_CLASS_TELXMLUNICODECODEC
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnicodeCodec_get_BigEndian(TElXMLUnicodeCodecHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnicodeCodec_set_BigEndian(TElXMLUnicodeCodecHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnicodeCodec_Create(TElXMLUnicodeCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLUnicodeCodec_Create_1(TStreamHandle aStream, TElXMLUnicodeCodecHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLUNICODECODEC */

#ifdef SB_USE_CLASS_TELXMLSTRINGCODEC
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_NextChar(TElXMLStringCodecHandle _Handle, sb_char16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_WriteChar(TElXMLStringCodecHandle _Handle, sb_char16_t c);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_WriteStartup(TElXMLStringCodecHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_get_Data(TElXMLStringCodecHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_set_Data(TElXMLStringCodecHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_Create(TElXMLStringCodecHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLStringCodec_Create_1(TStreamHandle aStream, TElXMLStringCodecHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLSTRINGCODEC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLBufferingStream;
class TElXMLCodec;
typedef TElXMLCodec ElXMLCodec;
class TElXML8BitCodec;
typedef TElXML8BitCodec ElXML8BitCodec;
class TElXMLUTF8Codec;
typedef TElXMLUTF8Codec ElXMLUTF8Codec;
class TElXMLUnicodeCodec;
typedef TElXMLUnicodeCodec ElXMLUnicodeCodec;
class TElXMLStringCodec;
typedef TElXMLStringCodec ElXMLStringCodec;

#ifdef SB_USE_CLASS_TELXMLBUFFERINGSTREAM
class TElXMLBufferingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElXMLBufferingStream)
		TStream* _Inst_Stream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		void Flush();

		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElXMLBufferingStream, Stream);

		virtual bool get_EndOfFile();

		SB_DECLARE_PROPERTY_GET(bool, get_EndOfFile, TElXMLBufferingStream, EndOfFile);

		TElXMLBufferingStream(TElXMLBufferingStreamHandle handle, TElOwnHandle ownHandle);

		TElXMLBufferingStream();

		virtual ~TElXMLBufferingStream();

};
#endif /* SB_USE_CLASS_TELXMLBUFFERINGSTREAM */

#ifdef SB_USE_CLASS_TELXMLCODEC
class TElXMLCodec: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLCodec)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void MigrateTo(TElXMLCodec &Codec);

		void MigrateTo(TElXMLCodec *Codec);

		void Flush();

		virtual sb_char16_t NextChar();

		virtual void WriteChar(sb_char16_t c);

		virtual void WriteStartup();

		TElXMLCodecHandle Detect(const std::string &DefaultEncoding);

#ifdef SB_USE_CLASS_TSTREAM
		static TElXMLCodecHandle Detect(TStream &aStream, const std::string &DefaultEncoding);

		static TElXMLCodecHandle Detect(TStream *aStream, const std::string &DefaultEncoding);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TElXMLCodecHandle Detect_Inst(TStream &aStream, const std::string &DefaultEncoding);

		TElXMLCodecHandle Detect_Inst(TStream *aStream, const std::string &DefaultEncoding);
#endif /* SB_USE_CLASS_TSTREAM */

		static TElXMLCodecHandle GetCodec(const std::string &aEnc);

		TElXMLCodecHandle GetCodec_Inst(const std::string &aEnc);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElXMLCodec, Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_sEOF();

		SB_DECLARE_PROPERTY_GET(bool, get_sEOF, TElXMLCodec, sEOF);

		virtual int64_t get_sPos();

		virtual void set_sPos(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_sPos, set_sPos, TElXMLCodec, sPos);

		virtual int64_t get_sSize();

		virtual void set_sSize(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_sSize, set_sSize, TElXMLCodec, sSize);

		virtual void get_Name(std::string &OutResult);

		virtual bool get_WriteBOM();

		virtual void set_WriteBOM(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteBOM, set_WriteBOM, TElXMLCodec, WriteBOM);

		TElXMLCodec(TElXMLCodecHandle handle, TElOwnHandle ownHandle);

		TElXMLCodec();

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElXMLCodec(TStream &aStream);

		explicit TElXMLCodec(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual ~TElXMLCodec();

};
#endif /* SB_USE_CLASS_TELXMLCODEC */

#ifdef SB_USE_CLASS_TELXML8BITCODEC
class TElXML8BitCodec: public TElXMLCodec
{
	private:
		SB_DISABLE_COPY(TElXML8BitCodec)
	public:
		virtual void get_Charset(std::string &OutResult);

		virtual void set_Charset(const std::string &Value);

		TElXML8BitCodec(TElXML8BitCodecHandle handle, TElOwnHandle ownHandle);

		TElXML8BitCodec();

		explicit TElXML8BitCodec(const std::string &aEncoding);

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElXML8BitCodec(TStream &aStream);

		explicit TElXML8BitCodec(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELXML8BITCODEC */

#ifdef SB_USE_CLASS_TELXMLUTF8CODEC
class TElXMLUTF8Codec: public TElXMLCodec
{
	private:
		SB_DISABLE_COPY(TElXMLUTF8Codec)
	public:
		TElXMLUTF8Codec(TElXMLUTF8CodecHandle handle, TElOwnHandle ownHandle);

		TElXMLUTF8Codec();

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElXMLUTF8Codec(TStream &aStream);

		explicit TElXMLUTF8Codec(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELXMLUTF8CODEC */

#ifdef SB_USE_CLASS_TELXMLUNICODECODEC
class TElXMLUnicodeCodec: public TElXMLCodec
{
	private:
		SB_DISABLE_COPY(TElXMLUnicodeCodec)
	public:
		virtual bool get_BigEndian();

		virtual void set_BigEndian(bool Value);

		SB_DECLARE_PROPERTY(bool, get_BigEndian, set_BigEndian, TElXMLUnicodeCodec, BigEndian);

		TElXMLUnicodeCodec(TElXMLUnicodeCodecHandle handle, TElOwnHandle ownHandle);

		TElXMLUnicodeCodec();

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElXMLUnicodeCodec(TStream &aStream);

		explicit TElXMLUnicodeCodec(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELXMLUNICODECODEC */

#ifdef SB_USE_CLASS_TELXMLSTRINGCODEC
class TElXMLStringCodec: public TElXMLCodec
{
	private:
		SB_DISABLE_COPY(TElXMLStringCodec)
	public:
		virtual sb_char16_t NextChar();

		virtual void WriteChar(sb_char16_t c);

		virtual void WriteStartup();

		virtual void get_Data(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Data(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Data(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Data(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLStringCodec(TElXMLStringCodecHandle handle, TElOwnHandle ownHandle);

		TElXMLStringCodec();

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElXMLStringCodec(TStream &aStream);

		explicit TElXMLStringCodec(TStream *aStream);
#endif /* SB_USE_CLASS_TSTREAM */

};
#endif /* SB_USE_CLASS_TELXMLSTRINGCODEC */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLCHARSETS */

