#ifndef __INC_SBCOMPRSTREAM
#define __INC_SBCOMPRSTREAM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbzlib.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCustomCompressingStreamHandle;

typedef TElClassHandle TElCustomDecompressingStreamHandle;

typedef TElClassHandle TElZlibCompressingStreamHandle;

typedef TElClassHandle TElZlibDecompressingStreamHandle;

#ifdef SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCustomCompressingStream_Read(TElCustomCompressingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCompressingStream_Write(TElCustomCompressingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCompressingStream_Seek(TElCustomCompressingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCompressingStream_Seek_1(TElCustomCompressingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomCompressingStream_Create(TStreamHandle SourceStream, int64_t Count, int8_t ReleaseSourceStream, TElCustomCompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_FinalizeOutput(TElCustomDecompressingStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_Read(TElCustomDecompressingStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_Write(TElCustomDecompressingStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_Seek(TElCustomDecompressingStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_Seek_1(TElCustomDecompressingStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_get_DestStream(TElCustomDecompressingStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomDecompressingStream_Create(TStreamHandle DestStream, int8_t ReleaseDestStream, TElCustomDecompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElZlibCompressingStream_Create(int32_t CompressionLevel, TStreamHandle SourceStream, int64_t Count, int8_t ReleaseSourceStream, TElZlibCompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElZlibDecompressingStream_Create(TStreamHandle DestStream, int8_t ReleaseDestStream, TElZlibDecompressingStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCustomCompressingStream;
class TElCustomDecompressingStream;
class TElZlibCompressingStream;
class TElZlibDecompressingStream;

#ifdef SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM
class TElCustomCompressingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElCustomCompressingStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		TElCustomCompressingStream(TElCustomCompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElCustomCompressingStream(TStream &SourceStream, int64_t Count, bool ReleaseSourceStream);

		TElCustomCompressingStream(TStream *SourceStream, int64_t Count, bool ReleaseSourceStream);

};
#endif /* SB_USE_CLASS_TELCUSTOMCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM
class TElCustomDecompressingStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElCustomDecompressingStream)
		TStream* _Inst_DestStream;

		void initInstances();

	public:
		void FinalizeOutput();

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElCustomDecompressingStream, DestStream);

		TElCustomDecompressingStream(TElCustomDecompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElCustomDecompressingStream(TStream &DestStream, bool ReleaseDestStream);

		TElCustomDecompressingStream(TStream *DestStream, bool ReleaseDestStream);

		virtual ~TElCustomDecompressingStream();

};
#endif /* SB_USE_CLASS_TELCUSTOMDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM
class TElZlibCompressingStream: public TElCustomCompressingStream
{
	private:
		SB_DISABLE_COPY(TElZlibCompressingStream)
	public:
		TElZlibCompressingStream(TElZlibCompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElZlibCompressingStream(int32_t CompressionLevel, TStream &SourceStream, int64_t Count, bool ReleaseSourceStream);

		TElZlibCompressingStream(int32_t CompressionLevel, TStream *SourceStream, int64_t Count, bool ReleaseSourceStream);

};
#endif /* SB_USE_CLASS_TELZLIBCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM
class TElZlibDecompressingStream: public TElCustomDecompressingStream
{
	private:
		SB_DISABLE_COPY(TElZlibDecompressingStream)
	public:
		TElZlibDecompressingStream(TElZlibDecompressingStreamHandle handle, TElOwnHandle ownHandle);

		TElZlibDecompressingStream(TStream &DestStream, bool ReleaseDestStream);

		TElZlibDecompressingStream(TStream *DestStream, bool ReleaseDestStream);

};
#endif /* SB_USE_CLASS_TELZLIBDECOMPRESSINGSTREAM */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCOMPRSTREAM */

