#ifndef __INC_SBSTREAMS
#define __INC_SBSTREAMS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TStreamHandle TElStreamHandle;

typedef TMemoryStreamHandle TElMemoryStreamHandle;

typedef TStreamHandle SBStreams_TElNativeStreamHandle;

typedef TElClassHandle TElFileStreamHandle;

typedef TElClassHandle TElDataStreamHandle;

typedef TElClassHandle TElMultiStreamHandle;

typedef TElClassHandle TElReadCachingStreamHandle;

typedef TElClassHandle TElWriteCachingStreamHandle;

#ifdef SB_USE_CLASS_TELFILESTREAM
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_get_Position64(TElFileStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_set_Position64(TElFileStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_get_Size64(TElFileStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_set_Size64(TElFileStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_Create(const char * pcAFileName, int32_t szAFileName, uint16_t Mode, TFileStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileStream_Create_1(const char * pcAFileName, int32_t szAFileName, uint16_t Mode, uint32_t Rights, TFileStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILESTREAM */

#ifdef SB_USE_CLASS_TELDATASTREAM
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_get_Start(TElDataStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_get_Stream(TElDataStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_set_Stream(TElDataStreamHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_get_FreeOnSent(TElDataStreamHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_set_FreeOnSent(TElDataStreamHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_Create(TStreamHandle LStream, int8_t LFreeOnSent, TElDataStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDataStream_Create_1(const uint8_t pBuffer[], int32_t szBuffer, TElDataStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELDATASTREAM */

#ifdef SB_USE_CLASS_TELMULTISTREAM
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_AddStream(TElMultiStreamHandle _Handle, TStreamHandle AStream, int8_t FreeStream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_Read(TElMultiStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_Write(TElMultiStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_Seek(TElMultiStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_Seek_1(TElMultiStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMultiStream_Create(TElMultiStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELMULTISTREAM */

#ifdef SB_USE_CLASS_TELREADCACHINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_Read(TElReadCachingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_Write(TElReadCachingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_Seek(TElReadCachingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_Seek_1(TElReadCachingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_get_Stream(TElReadCachingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_set_Stream(TElReadCachingStreamHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_get_CacheSize(TElReadCachingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_set_CacheSize(TElReadCachingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElReadCachingStream_Create(TElReadCachingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELREADCACHINGSTREAM */

#ifdef SB_USE_CLASS_TELWRITECACHINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Read(TElWriteCachingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Write(TElWriteCachingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Seek(TElWriteCachingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Seek_1(TElWriteCachingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Flush(TElWriteCachingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_get_Stream(TElWriteCachingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_set_Stream(TElWriteCachingStreamHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_get_CacheSize(TElWriteCachingStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_set_CacheSize(TElWriteCachingStreamHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElWriteCachingStream_Create(TElWriteCachingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELWRITECACHINGSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TStream TElStream;
typedef TMemoryStream TElMemoryStream;
typedef TStream SBStreams_TElNativeStream;
class TElFileStream;
class TElDataStream;
class TElMultiStream;
class TElReadCachingStream;
class TElWriteCachingStream;

#ifdef SB_USE_CLASS_TELFILESTREAM
class TElFileStream: public TFileStream
{
	private:
		SB_DISABLE_COPY(TElFileStream)
	public:
		virtual int64_t get_Position64();

		virtual void set_Position64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Position64, set_Position64, TElFileStream, Position64);

		virtual int64_t get_Size64();

		virtual void set_Size64(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size64, set_Size64, TElFileStream, Size64);

		TElFileStream(TElFileStreamHandle handle, TElOwnHandle ownHandle);

		TElFileStream(const std::string &AFileName, uint16_t Mode);

		TElFileStream(const std::string &AFileName, uint16_t Mode, uint32_t Rights);

};
#endif /* SB_USE_CLASS_TELFILESTREAM */

#ifdef SB_USE_CLASS_TELDATASTREAM
class TElDataStream: public TObject
{
	private:
		SB_DISABLE_COPY(TElDataStream)
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_Stream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		virtual int64_t get_Start();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Start, TElDataStream, Start);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElDataStream, Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_FreeOnSent();

		virtual void set_FreeOnSent(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FreeOnSent, set_FreeOnSent, TElDataStream, FreeOnSent);

		TElDataStream(TElDataStreamHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSTREAM
		TElDataStream(TStream &LStream, bool LFreeOnSent);

		TElDataStream(TStream *LStream, bool LFreeOnSent);
#endif /* SB_USE_CLASS_TSTREAM */

		explicit TElDataStream(const std::vector<uint8_t> &Buffer);

		virtual ~TElDataStream();

};
#endif /* SB_USE_CLASS_TELDATASTREAM */

#ifdef SB_USE_CLASS_TELMULTISTREAM
class TElMultiStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElMultiStream)
	public:
		bool AddStream(TStream &AStream, bool FreeStream);

		bool AddStream(TStream *AStream, bool FreeStream);

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TElMultiStream(TElMultiStreamHandle handle, TElOwnHandle ownHandle);

		TElMultiStream();

};
#endif /* SB_USE_CLASS_TELMULTISTREAM */

#ifdef SB_USE_CLASS_TELREADCACHINGSTREAM
class TElReadCachingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElReadCachingStream)
		TStream* _Inst_Stream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_Stream();

		virtual void set_Stream(TStream &Value);

		virtual void set_Stream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElReadCachingStream, Stream);

		virtual int32_t get_CacheSize();

		virtual void set_CacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CacheSize, set_CacheSize, TElReadCachingStream, CacheSize);

		TElReadCachingStream(TElReadCachingStreamHandle handle, TElOwnHandle ownHandle);

		TElReadCachingStream();

		virtual ~TElReadCachingStream();

};
#endif /* SB_USE_CLASS_TELREADCACHINGSTREAM */

#ifdef SB_USE_CLASS_TELWRITECACHINGSTREAM
class TElWriteCachingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElWriteCachingStream)
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

		SB_DECLARE_PROPERTY(TStream*, get_Stream, set_Stream, TElWriteCachingStream, Stream);

		virtual int32_t get_CacheSize();

		virtual void set_CacheSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CacheSize, set_CacheSize, TElWriteCachingStream, CacheSize);

		TElWriteCachingStream(TElWriteCachingStreamHandle handle, TElOwnHandle ownHandle);

		TElWriteCachingStream();

		virtual ~TElWriteCachingStream();

};
#endif /* SB_USE_CLASS_TELWRITECACHINGSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_STREAMS

#ifdef SB_USE_CLASS_TSTREAM
int64_t CopyStream(TStream &SrcStream, TStream &DestStream, int64_t Offset, int64_t Count, bool PreservePosition);
int64_t CopyStream(TStream *SrcStream, TStream *DestStream, int64_t Offset, int64_t Count, bool PreservePosition);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t CopyStream(TStream &Source, TStream &Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent);
int64_t CopyStream(TStream *Source, TStream *Dest, int64_t Offset, int64_t Count, bool PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t StreamPosition(TStream &Stream);
int64_t StreamPosition(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
int64_t StreamSize(TStream &Stream);
int64_t StreamSize(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void SetStreamPosition(TStream &Stream, int64_t Position);
void SetStreamPosition(TStream *Stream, int64_t Position);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamSetPosition(TStream &Stream, int64_t NewPosition);
void StreamSetPosition(TStream *Stream, int64_t NewPosition);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamRewind(TStream &Stream);
void StreamRewind(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamRead(TStream &Stream, std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
void StreamRead(TStream *Stream, std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamReadAll(TStream &Stream, std::vector<uint8_t> &OutResult);
void StreamReadAll(TStream *Stream, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
uint8_t StreamReadByte(TStream &Stream);
uint8_t StreamReadByte(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamWrite(TStream &Stream, const std::vector<uint8_t> &Buffer);
void StreamWrite(TStream *Stream, const std::vector<uint8_t> &Buffer);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamWrite(TStream &Stream, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
void StreamWrite(TStream *Stream, const std::vector<uint8_t> &Buffer, int32_t Offset, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamWriteLn(TStream &Stream, const std::string &Text);
void StreamWriteLn(TStream *Stream, const std::string &Text);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
void StreamClear(TStream &Stream);
void StreamClear(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_STREAMS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_STREAMS
SB_IMPORT uint32_t SB_APIENTRY SBStreams_CopyStream(TStreamHandle SrcStream, TStreamHandle DestStream, int64_t Offset, int64_t Count, int8_t PreservePosition, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_CopyStream_1(TStreamHandle Source, TStreamHandle Dest, int64_t Offset, int64_t Count, int8_t PreservePosition, TSBProgressEvent pMethodProgressEvent, void * pDataProgressEvent, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamPosition(TStreamHandle Stream, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamSize(TStreamHandle Stream, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_SetStreamPosition(TStreamHandle Stream, int64_t Position);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamSetPosition(TStreamHandle Stream, int64_t NewPosition);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamRewind(TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamRead(TStreamHandle Stream, uint8_t pBuffer[], int32_t * szBuffer, int32_t Offset, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamReadAll(TStreamHandle Stream, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamReadByte(TStreamHandle Stream, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamWrite(TStreamHandle Stream, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamWrite_1(TStreamHandle Stream, const uint8_t pBuffer[], int32_t szBuffer, int32_t Offset, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamWriteLn(TStreamHandle Stream, const char * pcText, int32_t szText);
SB_IMPORT uint32_t SB_APIENTRY SBStreams_StreamClear(TStreamHandle Stream);
#endif /* SB_USE_GLOBAL_PROCS_STREAMS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSTREAMS */

