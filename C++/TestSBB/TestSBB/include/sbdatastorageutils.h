#ifndef __INC_SBDATASTORAGEUTILS
#define __INC_SBDATASTORAGEUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstreams.h"
#include "sbasn1tree.h"
#include "sbstringlist.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_DefaultMetadataCacheLimit 	1000

typedef TElClassHandle TElProxyStreamHandle;

typedef TElClassHandle TElMetadataCacheHandle;

typedef TElClassHandle TElProtectedObjectUploadStreamHandle;

typedef TElClassHandle TElProtectedObjectReaderHandle;

typedef TElClassHandle TElProtectedObjectDownloadStreamHandle;

typedef void (SB_CALLBACK *TSBProxyStreamBeforeWriteEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size, int8_t * Skip);

typedef void (SB_CALLBACK *TSBProxyStreamReadWriteEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Count);

typedef uint8_t TSBProtectedObjectMetadataLocationRaw;

typedef enum
{
	omlUnprotectedObject = 0,
	omlNoMetadata = 1,
	omlExternal = 2,
	omlExternalObject = 3,
	omlBeginning = 4,
	omlEnd = 5
} TSBProtectedObjectMetadataLocation;

typedef void (SB_CALLBACK *TSBProtectedObjectWriteEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBProtectedObjectMetadataNeededEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t pMetadata[], int32_t * szMetadata);

typedef uint8_t TSBProtectedObjectReadStrategyRaw;

typedef enum
{
	orsMinimizeBlockReads = 0,
	orsMinimizeTraffic = 1
} TSBProtectedObjectReadStrategy;

typedef void (SB_CALLBACK *TSBProtectedObjectBlockReadEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Offset, void * Buffer, int32_t MaxSize, int32_t * Read, int8_t * Last);

typedef void (SB_CALLBACK *TSBProtectedObjectStreamReadEvent)(void * _ObjectData, TObjectHandle Sender, int64_t Offset, TStreamHandle DestStream, int64_t MaxCount, int64_t * Read, int8_t * Last);

typedef void (SB_CALLBACK *TSBProtectedObjectBodyBlockEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBProtectedObjectOutputStreamNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBProtectedObjectReadEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBProtectedObjectMetadataReceivedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pMetadata[], int32_t szMetadata);

typedef void (SB_CALLBACK *TSBProtectedObjectMetadataObjectNameReceivedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcObjName, int32_t szObjName);

#ifdef SB_USE_CLASS_TELPROXYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Read(TElProxyStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Write(TElProxyStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Seek(TElProxyStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Seek_1(TElProxyStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_ClientStream(TElProxyStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_TotalRead(TElProxyStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_OnBeforeRead(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_set_OnBeforeRead(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_OnAfterRead(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_set_OnAfterRead(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_OnBeforeWrite(TElProxyStreamHandle _Handle, TSBProxyStreamBeforeWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_set_OnBeforeWrite(TElProxyStreamHandle _Handle, TSBProxyStreamBeforeWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_get_OnAfterWrite(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_set_OnAfterWrite(TElProxyStreamHandle _Handle, TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Create(TStreamHandle AClientStream, TElProxyStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProxyStream_Create_1(TStreamHandle AClientStream, int64_t StartOffset, int64_t Size, int8_t TreatSizeAsMaxSize, TElProxyStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPROXYSTREAM */

#ifdef SB_USE_CLASS_TELMETADATACACHE
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_Clear(TElMetadataCacheHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_Delete(TElMetadataCacheHandle _Handle, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_GetMetadata(TElMetadataCacheHandle _Handle, const char * pcAObjectID, int32_t szAObjectID, uint8_t pAMetadata[], int32_t * szAMetadata, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_GetMetadataID(TElMetadataCacheHandle _Handle, const char * pcAObjectID, int32_t szAObjectID, char * pcAMetadataID, int32_t * szAMetadataID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_SetMetadata(TElMetadataCacheHandle _Handle, const char * pcAObjectID, int32_t szAObjectID, const uint8_t pAMetadata[], int32_t szAMetadata);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_SetMetadataID(TElMetadataCacheHandle _Handle, const char * pcAObjectID, int32_t szAObjectID, const char * pcAMetadataID, int32_t szAMetadataID);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_get_MaxEntries(TElMetadataCacheHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_set_MaxEntries(TElMetadataCacheHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMetadataCache_Create(int32_t AMaxEntries, TElMetadataCacheHandle * OutResult);
#endif /* SB_USE_CLASS_TELMETADATACACHE */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_Read(TElProtectedObjectUploadStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_Write(TElProtectedObjectUploadStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_Seek(TElProtectedObjectUploadStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_Seek_1(TElProtectedObjectUploadStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_Tag(TElProtectedObjectUploadStreamHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_Tag(TElProtectedObjectUploadStreamHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_OnObjectWriteBegin(TElProtectedObjectUploadStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_OnObjectWriteBegin(TElProtectedObjectUploadStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_OnObjectWriteEnd(TElProtectedObjectUploadStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_OnObjectWriteEnd(TElProtectedObjectUploadStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_OnObjectWrite(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectWriteEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_OnObjectWrite(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectWriteEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_OnMetadataNeeded(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectMetadataNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_OnMetadataNeeded(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_get_OnTrailerNeeded(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectMetadataNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_set_OnTrailerNeeded(TElProtectedObjectUploadStreamHandle _Handle, TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectUploadStream_Create(TStreamHandle SourceStream, TSBProtectedObjectMetadataLocationRaw MetadataLocation, int32_t MaxPrefixSize, int64_t MaxObjectSize, int32_t MaxPostfixSize, const uint8_t pMetadata[], int32_t szMetadata, const char * pcExternalMetadataObjectName, int32_t szExternalMetadataObjectName, int64_t Count, int8_t ReleaseSourceStream, TElProtectedObjectUploadStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_ReadObjectInfo(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectReadStrategyRaw ReadStrategy);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_Write(TElProtectedObjectReaderHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_FlushCachedData(TElProtectedObjectReaderHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_MetadataLocation(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectMetadataLocationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_Metadata(TElProtectedObjectReaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_Trailer(TElProtectedObjectReaderHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_MaxMetadataSize(TElProtectedObjectReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_MaxObjectSize(TElProtectedObjectReaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_ObjectSize(TElProtectedObjectReaderHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_MaxTrailerSize(TElProtectedObjectReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_ExternalMetadataObjectName(TElProtectedObjectReaderHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_MetadataLengthThreshold(TElProtectedObjectReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_MetadataLengthThreshold(TElProtectedObjectReaderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_Tag(TElProtectedObjectReaderHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_Tag(TElProtectedObjectReaderHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_DestStream(TElProtectedObjectReaderHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_ObjectInfoBlockSize(TElProtectedObjectReaderHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_ObjectInfoBlockSize(TElProtectedObjectReaderHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnReadBlock(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectBlockReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnReadBlock(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectBlockReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnReadStream(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectStreamReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnReadStream(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectStreamReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnHeaderProcessed(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnHeaderProcessed(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnMetadataReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnMetadataReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnMetadataObjectNameReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnMetadataObjectNameReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnTrailerReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnTrailerReceived(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnObjectBodyBegin(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnObjectBodyBegin(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnObjectBodyEnd(TElProtectedObjectReaderHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnObjectBodyEnd(TElProtectedObjectReaderHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnObjectBodyBlock(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectBodyBlockEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnObjectBodyBlock(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectBodyBlockEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_get_OnOutputStreamNeeded(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectOutputStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_set_OnOutputStreamNeeded(TElProtectedObjectReaderHandle _Handle, TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_Create(TElProtectedObjectReaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectReader_Create_1(TStreamHandle DestStream, TElProtectedObjectReaderHandle * OutResult);
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_FlushCachedData(TElProtectedObjectDownloadStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_Read(TElProtectedObjectDownloadStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_Write(TElProtectedObjectDownloadStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_Seek(TElProtectedObjectDownloadStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_Seek_1(TElProtectedObjectDownloadStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_DestStream(TElProtectedObjectDownloadStreamHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_Tag(TElProtectedObjectDownloadStreamHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_Tag(TElProtectedObjectDownloadStreamHandle _Handle, TObjectHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_Reader(TElProtectedObjectDownloadStreamHandle _Handle, TElProtectedObjectReaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnHeaderProcessed(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnHeaderProcessed(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnObjectReadBegin(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnObjectReadBegin(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnObjectReadEnd(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnObjectReadEnd(TElProtectedObjectDownloadStreamHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnObjectRead(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnObjectRead(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnMetadataReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnMetadataReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnMetadataObjectNameReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataObjectNameReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnMetadataObjectNameReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataObjectNameReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnTrailerReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnTrailerReceived(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_get_OnOutputStreamNeeded(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectOutputStreamNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_set_OnOutputStreamNeeded(TElProtectedObjectDownloadStreamHandle _Handle, TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElProtectedObjectDownloadStream_Create(TStreamHandle DestStream, int8_t ReleaseDestStream, TElProtectedObjectDownloadStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElProxyStream;
class TElMetadataCache;
class TElProtectedObjectUploadStream;
class TElProtectedObjectReader;
class TElProtectedObjectDownloadStream;

#ifdef SB_USE_CLASS_TELPROXYSTREAM
class TElProxyStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElProxyStream)
		TStream* _Inst_ClientStream;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_ClientStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_ClientStream, TElProxyStream, ClientStream);

		virtual int64_t get_TotalRead();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalRead, TElProxyStream, TotalRead);

		virtual void get_OnBeforeRead(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeRead(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterRead(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterRead(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeWrite(TSBProxyStreamBeforeWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeWrite(TSBProxyStreamBeforeWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterWrite(TSBProxyStreamReadWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterWrite(TSBProxyStreamReadWriteEvent pMethodValue, void * pDataValue);

		TElProxyStream(TElProxyStreamHandle handle, TElOwnHandle ownHandle);

		explicit TElProxyStream(TStream &AClientStream);

		explicit TElProxyStream(TStream *AClientStream);

		TElProxyStream(TStream &AClientStream, int64_t StartOffset, int64_t Size, bool TreatSizeAsMaxSize);

		TElProxyStream(TStream *AClientStream, int64_t StartOffset, int64_t Size, bool TreatSizeAsMaxSize);

		virtual ~TElProxyStream();

};
#endif /* SB_USE_CLASS_TELPROXYSTREAM */

#ifdef SB_USE_CLASS_TELMETADATACACHE
class TElMetadataCache: public TObject
{
	private:
		SB_DISABLE_COPY(TElMetadataCache)
	public:
		void Clear();

		void Delete(int32_t Count);

		bool GetMetadata(const std::string &AObjectID, std::vector<uint8_t> &AMetadata);

		bool GetMetadataID(const std::string &AObjectID, std::string &AMetadataID);

		void SetMetadata(const std::string &AObjectID, const std::vector<uint8_t> &AMetadata);

		void SetMetadataID(const std::string &AObjectID, const std::string &AMetadataID);

		virtual int32_t get_MaxEntries();

		virtual void set_MaxEntries(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxEntries, set_MaxEntries, TElMetadataCache, MaxEntries);

		TElMetadataCache(TElMetadataCacheHandle handle, TElOwnHandle ownHandle);

		explicit TElMetadataCache(int32_t AMaxEntries);

};
#endif /* SB_USE_CLASS_TELMETADATACACHE */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM
class TElProtectedObjectUploadStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElProtectedObjectUploadStream)
		TObject* _Inst_Tag;

		void initInstances();

	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElProtectedObjectUploadStream, Tag);

		virtual void get_OnObjectWriteBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectWriteBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectWriteEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectWriteEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectWrite(TSBProtectedObjectWriteEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectWrite(TSBProtectedObjectWriteEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataNeeded(TSBProtectedObjectMetadataNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataNeeded(TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnTrailerNeeded(TSBProtectedObjectMetadataNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTrailerNeeded(TSBProtectedObjectMetadataNeededEvent pMethodValue, void * pDataValue);

		TElProtectedObjectUploadStream(TElProtectedObjectUploadStreamHandle handle, TElOwnHandle ownHandle);

		TElProtectedObjectUploadStream(TStream &SourceStream, TSBProtectedObjectMetadataLocation MetadataLocation, int32_t MaxPrefixSize, int64_t MaxObjectSize, int32_t MaxPostfixSize, const std::vector<uint8_t> &Metadata, const std::string &ExternalMetadataObjectName, int64_t Count, bool ReleaseSourceStream);

		TElProtectedObjectUploadStream(TStream *SourceStream, TSBProtectedObjectMetadataLocation MetadataLocation, int32_t MaxPrefixSize, int64_t MaxObjectSize, int32_t MaxPostfixSize, const std::vector<uint8_t> &Metadata, const std::string &ExternalMetadataObjectName, int64_t Count, bool ReleaseSourceStream);

		virtual ~TElProtectedObjectUploadStream();

};
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTUPLOADSTREAM */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
class TElProtectedObjectReader: public TObject
{
	private:
		SB_DISABLE_COPY(TElProtectedObjectReader)
		TObject* _Inst_Tag;
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_DestStream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void ReadObjectInfo(TSBProtectedObjectReadStrategy ReadStrategy);

		int32_t Write(void * Buffer, int32_t Size);

		void FlushCachedData();

		virtual TSBProtectedObjectMetadataLocation get_MetadataLocation();

		SB_DECLARE_PROPERTY_GET(TSBProtectedObjectMetadataLocation, get_MetadataLocation, TElProtectedObjectReader, MetadataLocation);

		virtual void get_Metadata(std::vector<uint8_t> &OutResult);

		virtual void get_Trailer(std::vector<uint8_t> &OutResult);

		virtual int32_t get_MaxMetadataSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaxMetadataSize, TElProtectedObjectReader, MaxMetadataSize);

		virtual int64_t get_MaxObjectSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_MaxObjectSize, TElProtectedObjectReader, MaxObjectSize);

		virtual int64_t get_ObjectSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ObjectSize, TElProtectedObjectReader, ObjectSize);

		virtual int32_t get_MaxTrailerSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MaxTrailerSize, TElProtectedObjectReader, MaxTrailerSize);

		virtual void get_ExternalMetadataObjectName(std::string &OutResult);

		virtual int32_t get_MetadataLengthThreshold();

		virtual void set_MetadataLengthThreshold(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MetadataLengthThreshold, set_MetadataLengthThreshold, TElProtectedObjectReader, MetadataLengthThreshold);

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElProtectedObjectReader, Tag);

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElProtectedObjectReader, DestStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t get_ObjectInfoBlockSize();

		virtual void set_ObjectInfoBlockSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ObjectInfoBlockSize, set_ObjectInfoBlockSize, TElProtectedObjectReader, ObjectInfoBlockSize);

		virtual void get_OnReadBlock(TSBProtectedObjectBlockReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadBlock(TSBProtectedObjectBlockReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnReadStream(TSBProtectedObjectStreamReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReadStream(TSBProtectedObjectStreamReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnHeaderProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderProcessed(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataReceived(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataObjectNameReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataObjectNameReceived(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnTrailerReceived(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTrailerReceived(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectBodyBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectBodyBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectBodyEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectBodyEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectBodyBlock(TSBProtectedObjectBodyBlockEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectBodyBlock(TSBProtectedObjectBodyBlockEvent pMethodValue, void * pDataValue);

		virtual void get_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue);

		TElProtectedObjectReader(TElProtectedObjectReaderHandle handle, TElOwnHandle ownHandle);

		TElProtectedObjectReader();

#ifdef SB_USE_CLASS_TSTREAM
		explicit TElProtectedObjectReader(TStream &DestStream);

		explicit TElProtectedObjectReader(TStream *DestStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual ~TElProtectedObjectReader();

};
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM
class TElProtectedObjectDownloadStream: public TStream
{
	private:
		SB_DISABLE_COPY(TElProtectedObjectDownloadStream)
		TStream* _Inst_DestStream;
		TObject* _Inst_Tag;
#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
		TElProtectedObjectReader* _Inst_Reader;
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

		void initInstances();

	public:
		void FlushCachedData();

		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual TStream* get_DestStream();

		SB_DECLARE_PROPERTY_GET(TStream*, get_DestStream, TElProtectedObjectDownloadStream, DestStream);

		virtual TObject* get_Tag();

		virtual void set_Tag(TObject &Value);

		virtual void set_Tag(TObject *Value);

		SB_DECLARE_PROPERTY(TObject*, get_Tag, set_Tag, TElProtectedObjectDownloadStream, Tag);

#ifdef SB_USE_CLASS_TELPROTECTEDOBJECTREADER
		virtual TElProtectedObjectReader* get_Reader();

		SB_DECLARE_PROPERTY_GET(TElProtectedObjectReader*, get_Reader, TElProtectedObjectDownloadStream, Reader);
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTREADER */

		virtual void get_OnHeaderProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnHeaderProcessed(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectReadBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectReadBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectReadEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectReadEnd(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnObjectRead(TSBProtectedObjectReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnObjectRead(TSBProtectedObjectReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataReceived(TSBProtectedObjectMetadataReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataReceived(TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnMetadataObjectNameReceived(TSBProtectedObjectMetadataObjectNameReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnMetadataObjectNameReceived(TSBProtectedObjectMetadataObjectNameReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnTrailerReceived(TSBProtectedObjectMetadataReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTrailerReceived(TSBProtectedObjectMetadataReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOutputStreamNeeded(TSBProtectedObjectOutputStreamNeededEvent pMethodValue, void * pDataValue);

		TElProtectedObjectDownloadStream(TElProtectedObjectDownloadStreamHandle handle, TElOwnHandle ownHandle);

		TElProtectedObjectDownloadStream(TStream &DestStream, bool ReleaseDestStream);

		TElProtectedObjectDownloadStream(TStream *DestStream, bool ReleaseDestStream);

		virtual ~TElProtectedObjectDownloadStream();

};
#endif /* SB_USE_CLASS_TELPROTECTEDOBJECTDOWNLOADSTREAM */

#ifdef SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS

#ifdef SB_USE_CLASS_TSTREAM
int64_t TryGetStreamSize(TStream &Stream);
int64_t TryGetStreamSize(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

void PathAddExtension(const std::string &PathName, const std::string &Extension, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS
SB_IMPORT uint32_t SB_APIENTRY SBDataStorageUtils_TryGetStreamSize(TStreamHandle Stream, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDataStorageUtils_PathAddExtension(const char * pcPathName, int32_t szPathName, const char * pcExtension, int32_t szExtension, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_DATASTORAGEUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDATASTORAGEUTILS */

