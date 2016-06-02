#ifndef __INC_SBOFFICEPACKAGE
#define __INC_SBOFFICEPACKAGE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbofficecommon.h"
#include "sbofficexmlcore.h"
#include "sbarczip.h"
#include "sbziputils.h"
#include "sbxmlcore.h"
#include "sbxmldefs.h"
#include "sbxmlsec.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOfficePackagePartHandle;

typedef TElClassHandle TElOfficePackageHandle;

typedef TElClassHandle TElOfficeZipPackageHandle;

typedef TElClassHandle TElOpenOfficePackageHandle;

typedef void (SB_CALLBACK *TSBOfficeGetDataStreamEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPath, int32_t szPath, TStreamHandle * Stream);

typedef void (SB_CALLBACK *TSBOfficeCloseDataStreamEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle Stream);

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_GetStream(TElOfficePackagePartHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_GetStream_1(TElOfficePackagePartHandle _Handle, int8_t ReadOnly, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_CloseStream(TElOfficePackagePartHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_GetRelationshipsStream(TElOfficePackagePartHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_CloseRelationshipsStream(TElOfficePackagePartHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_Package(TElOfficePackagePartHandle _Handle, TElOfficePackageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_Relationships(TElOfficePackagePartHandle _Handle, TElOfficeOpenXMLRelationshipsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_ContentType(TElOfficePackagePartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_URI(TElOfficePackagePartHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_IsInterleavedPart(TElOfficePackagePartHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_get_PieceCount(TElOfficePackagePartHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackagePart_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_Close(TElOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_Flush(TElOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_FlushCoreProperties(TElOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_CreatePart(TElOfficePackageHandle _Handle, const char * pcURI, int32_t szURI, const char * pcContentType, int32_t szContentType, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_CreatePart_1(TElOfficePackageHandle _Handle, const char * pcURI, int32_t szURI, const char * pcContentType, int32_t szContentType, int64_t ExpectedStreamSize, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_DeletePart(TElOfficePackageHandle _Handle, const char * pcURI, int32_t szURI);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_GetPart(TElOfficePackageHandle _Handle, const char * pcURI, int32_t szURI, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_GetPackageRelatedPartByType(TElOfficePackageHandle _Handle, const sb_char16_t * pcRelType, int32_t szRelType, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_GetRelatedPartByType(TElOfficePackageHandle _Handle, TElOfficePackagePartHandle Part, const sb_char16_t * pcRelType, int32_t szRelType, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_GetZipPackageStream(TElOfficePackageHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_CloseZipPackageStream(TElOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_GetPackageRelationshipsStream(TElOfficePackageHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_ClosePackageRelationshipsStream(TElOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_IsReadOnly(TElOfficePackageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_ContentTypes(TElOfficePackageHandle _Handle, TElOfficeOpenXMLContentTypesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_CoreProperties(TElOfficePackageHandle _Handle, TElOfficeOpenXMLCorePropertiesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_Relationships(TElOfficePackageHandle _Handle, TElOfficeOpenXMLRelationshipsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_PartCount(TElOfficePackageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_Parts(TElOfficePackageHandle _Handle, int32_t Index, TElOfficePackagePartHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_OnCreateTemporaryStream(TElOfficePackageHandle _Handle, TSBOfficeCreateTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_set_OnCreateTemporaryStream(TElOfficePackageHandle _Handle, TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_get_OnCloseTemporaryStream(TElOfficePackageHandle _Handle, TSBOfficeCloseTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_set_OnCloseTemporaryStream(TElOfficePackageHandle _Handle, TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOfficePackage_Create(TElOfficePackageHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEZIPPACKAGE
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Open(TElOfficeZipPackageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Open_1(TElOfficeZipPackageHandle _Handle, TStreamHandle Stream, int8_t OwnStream);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Open_2(TElOfficeZipPackageHandle _Handle, TStreamHandle Stream, int8_t OwnStream, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Open_3(TElOfficeZipPackageHandle _Handle, TStreamHandle Stream, int64_t StreamOffset, int8_t OwnStream, int8_t ReadOnly, TElZipReaderHandle ZipReader);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Flush(TElOfficeZipPackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Close(TElOfficeZipPackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_GetZipPackageStream(TElOfficeZipPackageHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_CloseZipPackageStream(TElOfficeZipPackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_get_CompressionLevel(TElOfficeZipPackageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_set_CompressionLevel(TElOfficeZipPackageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_get_ZipReader(TElOfficeZipPackageHandle _Handle, TElZipReaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOfficeZipPackage_Create(TElOfficeZipPackageHandle * OutResult);
#endif /* SB_USE_CLASS_TELOFFICEZIPPACKAGE */

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_CreateNew(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream, int8_t OwnStream);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Open(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Open_1(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream, int8_t OwnStream);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Open_2(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream, int8_t OwnStream, int8_t ReadOnly);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Open_3(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream, int64_t StreamOffset, int8_t OwnStream, int8_t ReadOnly, TElZipReaderHandle ZipReader);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Flush(TElOpenOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_FlushManifest(TElOpenOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Close(TElOpenOfficePackageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_CreateEntry(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_CreateStream(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath, int64_t ExpectedStreamSize, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_GetStream(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_GetStream_1(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath, int8_t ReadOnly, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_CloseStream(TElOpenOfficePackageHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_CloseStream_1(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_DeleteStream(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_StreamExists(TElOpenOfficePackageHandle _Handle, const char * pcPath, int32_t szPath, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_IsReadOnly(TElOpenOfficePackageHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_MimeType(TElOpenOfficePackageHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_MimeType(TElOpenOfficePackageHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_Manifest(TElOpenOfficePackageHandle _Handle, TElOpenOfficeXMLManifestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_CompressionLevel(TElOpenOfficePackageHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_CompressionLevel(TElOpenOfficePackageHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_ZipReader(TElOpenOfficePackageHandle _Handle, TElZipReaderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_OnCreateTemporaryStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCreateTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_OnCreateTemporaryStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_OnCloseTemporaryStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCloseTemporaryStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_OnCloseTemporaryStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_OnGetDataStream(TElOpenOfficePackageHandle _Handle, TSBOfficeGetDataStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_OnGetDataStream(TElOpenOfficePackageHandle _Handle, TSBOfficeGetDataStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_get_OnCloseDataStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCloseDataStreamEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_set_OnCloseDataStream(TElOpenOfficePackageHandle _Handle, TSBOfficeCloseDataStreamEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOpenOfficePackage_Create(TElOpenOfficePackageHandle * OutResult);
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOfficePackagePart;
class TElOfficePackage;
class TElOfficeZipPackage;
class TElOpenOfficePackage;

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
class TElOfficePackagePart: public TObject
{
	private:
		SB_DISABLE_COPY(TElOfficePackagePart)
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
		TElOfficePackage* _Inst_Package;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
		TElOfficeOpenXMLRelationships* _Inst_Relationships;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetStream();
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetStream(bool ReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

		void CloseStream();

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetRelationshipsStream();
#endif /* SB_USE_CLASS_TSTREAM */

		void CloseRelationshipsStream();

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
		virtual TElOfficePackage* get_Package();

		SB_DECLARE_PROPERTY_GET(TElOfficePackage*, get_Package, TElOfficePackagePart, Package);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
		virtual TElOfficeOpenXMLRelationships* get_Relationships();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLRelationships*, get_Relationships, TElOfficePackagePart, Relationships);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

		virtual void get_ContentType(std::string &OutResult);

		virtual void get_URI(std::string &OutResult);

		virtual bool get_IsInterleavedPart();

		SB_DECLARE_PROPERTY_GET(bool, get_IsInterleavedPart, TElOfficePackagePart, IsInterleavedPart);

		virtual int32_t get_PieceCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PieceCount, TElOfficePackagePart, PieceCount);

		TElOfficePackagePart(TElOfficePackagePartHandle handle, TElOwnHandle ownHandle);

		TElOfficePackagePart();

		virtual ~TElOfficePackagePart();

};
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
class TElOfficePackage: public TObject
{
	private:
		SB_DISABLE_COPY(TElOfficePackage)
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
		TElOfficeOpenXMLContentTypes* _Inst_ContentTypes;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
		TElOfficeOpenXMLCoreProperties* _Inst_CoreProperties;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
		TElOfficeOpenXMLRelationships* _Inst_Relationships;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePart* _Inst_Parts;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

		void initInstances();

	public:
		virtual void Close();

		virtual void Flush();

		void FlushCoreProperties();

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePartHandle CreatePart(const std::string &URI, const std::string &ContentType);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePartHandle CreatePart(const std::string &URI, const std::string &ContentType, int64_t ExpectedStreamSize);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

		void DeletePart(const std::string &URI);

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePartHandle GetPart(const std::string &URI);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePartHandle GetPackageRelatedPartByType(const sb_u16string &RelType);
#ifdef SB_U16STRING_USED
		TElOfficePackagePartHandle GetPackageRelatedPartByType(const std::wstring &RelType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		TElOfficePackagePartHandle GetRelatedPartByType(TElOfficePackagePart &Part, const sb_u16string &RelType);

		TElOfficePackagePartHandle GetRelatedPartByType(TElOfficePackagePart *Part, const sb_u16string &RelType);
#ifdef SB_U16STRING_USED
		TElOfficePackagePartHandle GetRelatedPartByType(TElOfficePackagePart &Part, const std::wstring &RelType);

		TElOfficePackagePartHandle GetRelatedPartByType(TElOfficePackagePart *Part, const std::wstring &RelType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStreamHandle GetZipPackageStream();
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void CloseZipPackageStream();

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetPackageRelationshipsStream();
#endif /* SB_USE_CLASS_TSTREAM */

		void ClosePackageRelationshipsStream();

		virtual bool get_IsReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_IsReadOnly, TElOfficePackage, IsReadOnly);

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
		virtual TElOfficeOpenXMLContentTypes* get_ContentTypes();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLContentTypes*, get_ContentTypes, TElOfficePackage, ContentTypes);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
		virtual TElOfficeOpenXMLCoreProperties* get_CoreProperties();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLCoreProperties*, get_CoreProperties, TElOfficePackage, CoreProperties);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
		virtual TElOfficeOpenXMLRelationships* get_Relationships();

		SB_DECLARE_PROPERTY_GET(TElOfficeOpenXMLRelationships*, get_Relationships, TElOfficePackage, Relationships);
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

		virtual int32_t get_PartCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PartCount, TElOfficePackage, PartCount);

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
		virtual TElOfficePackagePart* get_Parts(int32_t Index);
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

		virtual void get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue);

		TElOfficePackage(TElOfficePackageHandle handle, TElOwnHandle ownHandle);

		TElOfficePackage();

		virtual ~TElOfficePackage();

};
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEZIPPACKAGE
class TElOfficeZipPackage: public TElOfficePackage
{
	private:
		SB_DISABLE_COPY(TElOfficeZipPackage)
#ifdef SB_USE_CLASS_TELZIPREADER
		TElZipReader* _Inst_ZipReader;
#endif /* SB_USE_CLASS_TELZIPREADER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream);

		void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream);

		void Open(TStream *Stream, bool OwnStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream, bool ReadOnly);

		void Open(TStream *Stream, bool OwnStream, bool ReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM
		void Open(TStream &Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader &ZipReader);

		void Open(TStream *Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader *ZipReader);
#endif /* SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM */

		virtual void Flush();

		virtual void Close();

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStreamHandle GetZipPackageStream();
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void CloseZipPackageStream();

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElOfficeZipPackage, CompressionLevel);

#ifdef SB_USE_CLASS_TELZIPREADER
		virtual TElZipReader* get_ZipReader();

		SB_DECLARE_PROPERTY_GET(TElZipReader*, get_ZipReader, TElOfficeZipPackage, ZipReader);
#endif /* SB_USE_CLASS_TELZIPREADER */

		TElOfficeZipPackage(TElOfficeZipPackageHandle handle, TElOwnHandle ownHandle);

		TElOfficeZipPackage();

		virtual ~TElOfficeZipPackage();

};
#endif /* SB_USE_CLASS_TELOFFICEZIPPACKAGE */

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE
class TElOpenOfficePackage: public TObject
{
	private:
		SB_DISABLE_COPY(TElOpenOfficePackage)
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
		TElOpenOfficeXMLManifest* _Inst_Manifest;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */
#ifdef SB_USE_CLASS_TELZIPREADER
		TElZipReader* _Inst_ZipReader;
#endif /* SB_USE_CLASS_TELZIPREADER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TSTREAM
		void CreateNew(TStream &Stream, bool OwnStream);

		void CreateNew(TStream *Stream, bool OwnStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream);

		void Open(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream);

		void Open(TStream *Stream, bool OwnStream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Open(TStream &Stream, bool OwnStream, bool ReadOnly);

		void Open(TStream *Stream, bool OwnStream, bool ReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM
		void Open(TStream &Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader &ZipReader);

		void Open(TStream *Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader *ZipReader);
#endif /* SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM */

		void Flush();

		void FlushManifest();

		void Close();

		void CreateEntry(const std::string &Path);

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle CreateStream(const std::string &Path, int64_t ExpectedStreamSize);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetStream(const std::string &Path);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TStreamHandle GetStream(const std::string &Path, bool ReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void CloseStream(TStream &Stream);

		void CloseStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void CloseStream(const std::string &Path);

		void DeleteStream(const std::string &Path);

		bool StreamExists(const std::string &Path);

		virtual bool get_IsReadOnly();

		SB_DECLARE_PROPERTY_GET(bool, get_IsReadOnly, TElOpenOfficePackage, IsReadOnly);

		virtual void get_MimeType(std::string &OutResult);

		virtual void set_MimeType(const std::string &Value);

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
		virtual TElOpenOfficeXMLManifest* get_Manifest();

		SB_DECLARE_PROPERTY_GET(TElOpenOfficeXMLManifest*, get_Manifest, TElOpenOfficePackage, Manifest);
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElOpenOfficePackage, CompressionLevel);

#ifdef SB_USE_CLASS_TELZIPREADER
		virtual TElZipReader* get_ZipReader();

		SB_DECLARE_PROPERTY_GET(TElZipReader*, get_ZipReader, TElOpenOfficePackage, ZipReader);
#endif /* SB_USE_CLASS_TELZIPREADER */

		virtual void get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnGetDataStream(TSBOfficeGetDataStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetDataStream(TSBOfficeGetDataStreamEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseDataStream(TSBOfficeCloseDataStreamEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseDataStream(TSBOfficeCloseDataStreamEvent pMethodValue, void * pDataValue);

		TElOpenOfficePackage(TElOpenOfficePackageHandle handle, TElOwnHandle ownHandle);

		TElOpenOfficePackage();

		virtual ~TElOpenOfficePackage();

};
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOFFICEPACKAGE */

