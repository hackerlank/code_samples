#include "sbofficepackage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficePackagePart::GetStream()
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficePackagePart_GetStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficePackagePart::GetStream(bool ReadOnly)
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficePackagePart_GetStream_1(_Handle, (int8_t)ReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficePackagePart::CloseStream()
{
	SBCheckError(TElOfficePackagePart_CloseStream(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficePackagePart::GetRelationshipsStream()
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficePackagePart_GetRelationshipsStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficePackagePart::CloseRelationshipsStream()
{
	SBCheckError(TElOfficePackagePart_CloseRelationshipsStream(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
TElOfficePackage* TElOfficePackagePart::get_Package()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackagePart_get_Package(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Package)
		this->_Inst_Package = new TElOfficePackage(hOutResult, ohFalse);
	else
		this->_Inst_Package->updateHandle(hOutResult);
	return this->_Inst_Package;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
TElOfficeOpenXMLRelationships* TElOfficePackagePart::get_Relationships()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackagePart_get_Relationships(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Relationships)
		this->_Inst_Relationships = new TElOfficeOpenXMLRelationships(hOutResult, ohFalse);
	else
		this->_Inst_Relationships->updateHandle(hOutResult);
	return this->_Inst_Relationships;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

void TElOfficePackagePart::get_ContentType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficePackagePart_get_ContentType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1869010986, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElOfficePackagePart::get_URI(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOfficePackagePart_get_URI(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2008714719, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElOfficePackagePart::get_IsInterleavedPart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficePackagePart_get_IsInterleavedPart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElOfficePackagePart::get_PieceCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficePackagePart_get_PieceCount(_Handle, &OutResult));
	return OutResult;
}

void TElOfficePackagePart::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */
}

TElOfficePackagePart::TElOfficePackagePart(TElOfficePackagePartHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficePackagePart::TElOfficePackagePart() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficePackagePart_Create(&_Handle));
}

TElOfficePackagePart::~TElOfficePackagePart()
{
#ifdef SB_USE_CLASS_TELOFFICEPACKAGE
	delete this->_Inst_Package;
	this->_Inst_Package = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
	delete this->_Inst_Relationships;
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGE

SB_INLINE void TElOfficePackage::Close()
{
	SBCheckError(TElOfficePackage_Close(_Handle));
}

SB_INLINE void TElOfficePackage::Flush()
{
	SBCheckError(TElOfficePackage_Flush(_Handle));
}

SB_INLINE void TElOfficePackage::FlushCoreProperties()
{
	SBCheckError(TElOfficePackage_FlushCoreProperties(_Handle));
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::CreatePart(const std::string &URI, const std::string &ContentType)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_CreatePart(_Handle, URI.data(), (int32_t)URI.length(), ContentType.data(), (int32_t)ContentType.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::CreatePart(const std::string &URI, const std::string &ContentType, int64_t ExpectedStreamSize)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_CreatePart_1(_Handle, URI.data(), (int32_t)URI.length(), ContentType.data(), (int32_t)ContentType.length(), ExpectedStreamSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

SB_INLINE void TElOfficePackage::DeletePart(const std::string &URI)
{
	SBCheckError(TElOfficePackage_DeletePart(_Handle, URI.data(), (int32_t)URI.length()));
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetPart(const std::string &URI)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_GetPart(_Handle, URI.data(), (int32_t)URI.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetPackageRelatedPartByType(const sb_u16string &RelType)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_GetPackageRelatedPartByType(_Handle, RelType.data(), (int32_t)RelType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetPackageRelatedPartByType(const std::wstring &RelType)
{
	TElOfficePackagePartHandle OutResult;
	std::string u16RelType;
	sb_to_u16string(RelType, u16RelType);
	SBCheckError(TElOfficePackage_GetPackageRelatedPartByType(_Handle, reinterpret_cast<const sb_char16_t*>(u16RelType.data()), (int32_t)u16RelType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetRelatedPartByType(TElOfficePackagePart &Part, const sb_u16string &RelType)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_GetRelatedPartByType(_Handle, Part.getHandle(), RelType.data(), (int32_t)RelType.length(), &OutResult));
	return OutResult;
}

SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetRelatedPartByType(TElOfficePackagePart *Part, const sb_u16string &RelType)
{
	TElOfficePackagePartHandle OutResult;
	SBCheckError(TElOfficePackage_GetRelatedPartByType(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, RelType.data(), (int32_t)RelType.length(), &OutResult));
	return OutResult;
}
#ifdef SB_U16STRING_USED
SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetRelatedPartByType(TElOfficePackagePart &Part, const std::wstring &RelType)
{
	TElOfficePackagePartHandle OutResult;
	std::string u16RelType;
	sb_to_u16string(RelType, u16RelType);
	SBCheckError(TElOfficePackage_GetRelatedPartByType(_Handle, Part.getHandle(), reinterpret_cast<const sb_char16_t*>(u16RelType.data()), (int32_t)u16RelType.length() >> 1, &OutResult));
	return OutResult;
}

SB_INLINE TElOfficePackagePartHandle TElOfficePackage::GetRelatedPartByType(TElOfficePackagePart *Part, const std::wstring &RelType)
{
	TElOfficePackagePartHandle OutResult;
	std::string u16RelType;
	sb_to_u16string(RelType, u16RelType);
	SBCheckError(TElOfficePackage_GetRelatedPartByType(_Handle, (Part != NULL) ? Part->getHandle() : SB_NULL_HANDLE, reinterpret_cast<const sb_char16_t*>(u16RelType.data()), (int32_t)u16RelType.length() >> 1, &OutResult));
	return OutResult;
}
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficePackage::GetZipPackageStream()
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficePackage_GetZipPackageStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficePackage::CloseZipPackageStream()
{
	SBCheckError(TElOfficePackage_CloseZipPackageStream(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficePackage::GetPackageRelationshipsStream()
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficePackage_GetPackageRelationshipsStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficePackage::ClosePackageRelationshipsStream()
{
	SBCheckError(TElOfficePackage_ClosePackageRelationshipsStream(_Handle));
}

bool TElOfficePackage::get_IsReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOfficePackage_get_IsReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
TElOfficeOpenXMLContentTypes* TElOfficePackage::get_ContentTypes()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackage_get_ContentTypes(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ContentTypes)
		this->_Inst_ContentTypes = new TElOfficeOpenXMLContentTypes(hOutResult, ohFalse);
	else
		this->_Inst_ContentTypes->updateHandle(hOutResult);
	return this->_Inst_ContentTypes;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
TElOfficeOpenXMLCoreProperties* TElOfficePackage::get_CoreProperties()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackage_get_CoreProperties(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CoreProperties)
		this->_Inst_CoreProperties = new TElOfficeOpenXMLCoreProperties(hOutResult, ohFalse);
	else
		this->_Inst_CoreProperties->updateHandle(hOutResult);
	return this->_Inst_CoreProperties;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */

#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
TElOfficeOpenXMLRelationships* TElOfficePackage::get_Relationships()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackage_get_Relationships(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Relationships)
		this->_Inst_Relationships = new TElOfficeOpenXMLRelationships(hOutResult, ohFalse);
	else
		this->_Inst_Relationships->updateHandle(hOutResult);
	return this->_Inst_Relationships;
}
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */

SB_INLINE int32_t TElOfficePackage::get_PartCount()
{
	int32_t OutResult;
	SBCheckError(TElOfficePackage_get_PartCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
TElOfficePackagePart* TElOfficePackage::get_Parts(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficePackage_get_Parts(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parts)
		this->_Inst_Parts = new TElOfficePackagePart(hOutResult, ohFalse);
	else
		this->_Inst_Parts->updateHandle(hOutResult);
	return this->_Inst_Parts;
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */

SB_INLINE void TElOfficePackage::get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficePackage_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficePackage::set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficePackage_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOfficePackage::get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOfficePackage_get_OnCloseTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOfficePackage::set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOfficePackage_set_OnCloseTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElOfficePackage::initInstances()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
	this->_Inst_ContentTypes = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
	this->_Inst_CoreProperties = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	this->_Inst_Parts = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}

TElOfficePackage::TElOfficePackage(TElOfficePackageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOfficePackage::TElOfficePackage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficePackage_Create(&_Handle));
}

TElOfficePackage::~TElOfficePackage()
{
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES
	delete this->_Inst_ContentTypes;
	this->_Inst_ContentTypes = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCONTENTTYPES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES
	delete this->_Inst_CoreProperties;
	this->_Inst_CoreProperties = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLCOREPROPERTIES */
#ifdef SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS
	delete this->_Inst_Relationships;
	this->_Inst_Relationships = NULL;
#endif /* SB_USE_CLASS_TELOFFICEOPENXMLRELATIONSHIPS */
#ifdef SB_USE_CLASS_TELOFFICEPACKAGEPART
	delete this->_Inst_Parts;
	this->_Inst_Parts = NULL;
#endif /* SB_USE_CLASS_TELOFFICEPACKAGEPART */
}
#endif /* SB_USE_CLASS_TELOFFICEPACKAGE */

#ifdef SB_USE_CLASS_TELOFFICEZIPPACKAGE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeZipPackage::Open(TStream &Stream)
{
	SBCheckError(TElOfficeZipPackage_Open(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOfficeZipPackage::Open(TStream *Stream)
{
	SBCheckError(TElOfficeZipPackage_Open(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeZipPackage::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOfficeZipPackage_Open_1(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOfficeZipPackage::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOfficeZipPackage_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOfficeZipPackage::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeZipPackage_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOfficeZipPackage::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOfficeZipPackage_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM
SB_INLINE void TElOfficeZipPackage::Open(TStream &Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader &ZipReader)
{
	SBCheckError(TElOfficeZipPackage_Open_3(_Handle, Stream.getHandle(), StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, ZipReader.getHandle()));
}

SB_INLINE void TElOfficeZipPackage::Open(TStream *Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader *ZipReader)
{
	SBCheckError(TElOfficeZipPackage_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, (ZipReader != NULL) ? ZipReader->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM */

SB_INLINE void TElOfficeZipPackage::Flush()
{
	SBCheckError(TElOfficeZipPackage_Flush(_Handle));
}

SB_INLINE void TElOfficeZipPackage::Close()
{
	SBCheckError(TElOfficeZipPackage_Close(_Handle));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOfficeZipPackage::GetZipPackageStream()
{
	TStreamHandle OutResult;
	SBCheckError(TElOfficeZipPackage_GetZipPackageStream(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOfficeZipPackage::CloseZipPackageStream()
{
	SBCheckError(TElOfficeZipPackage_CloseZipPackageStream(_Handle));
}

SB_INLINE int32_t TElOfficeZipPackage::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElOfficeZipPackage_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOfficeZipPackage::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElOfficeZipPackage_set_CompressionLevel(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPREADER
TElZipReader* TElOfficeZipPackage::get_ZipReader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOfficeZipPackage_get_ZipReader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ZipReader)
		this->_Inst_ZipReader = new TElZipReader(hOutResult, ohFalse);
	else
		this->_Inst_ZipReader->updateHandle(hOutResult);
	return this->_Inst_ZipReader;
}
#endif /* SB_USE_CLASS_TELZIPREADER */

void TElOfficeZipPackage::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPREADER
	this->_Inst_ZipReader = NULL;
#endif /* SB_USE_CLASS_TELZIPREADER */
}

TElOfficeZipPackage::TElOfficeZipPackage(TElOfficeZipPackageHandle handle, TElOwnHandle ownHandle) : TElOfficePackage(handle, ownHandle)
{
	initInstances();
}

TElOfficeZipPackage::TElOfficeZipPackage() : TElOfficePackage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOfficeZipPackage_Create(&_Handle));
}

TElOfficeZipPackage::~TElOfficeZipPackage()
{
#ifdef SB_USE_CLASS_TELZIPREADER
	delete this->_Inst_ZipReader;
	this->_Inst_ZipReader = NULL;
#endif /* SB_USE_CLASS_TELZIPREADER */
}
#endif /* SB_USE_CLASS_TELOFFICEZIPPACKAGE */

#ifdef SB_USE_CLASS_TELOPENOFFICEPACKAGE

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficePackage::CreateNew(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficePackage_CreateNew(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOpenOfficePackage::CreateNew(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficePackage_CreateNew(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficePackage::Open(TStream &Stream)
{
	SBCheckError(TElOpenOfficePackage_Open(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOpenOfficePackage::Open(TStream *Stream)
{
	SBCheckError(TElOpenOfficePackage_Open(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficePackage::Open(TStream &Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficePackage_Open_1(_Handle, Stream.getHandle(), (int8_t)OwnStream));
}

SB_INLINE void TElOpenOfficePackage::Open(TStream *Stream, bool OwnStream)
{
	SBCheckError(TElOpenOfficePackage_Open_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficePackage::Open(TStream &Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOpenOfficePackage_Open_2(_Handle, Stream.getHandle(), (int8_t)OwnStream, (int8_t)ReadOnly));
}

SB_INLINE void TElOpenOfficePackage::Open(TStream *Stream, bool OwnStream, bool ReadOnly)
{
	SBCheckError(TElOpenOfficePackage_Open_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)OwnStream, (int8_t)ReadOnly));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM
SB_INLINE void TElOpenOfficePackage::Open(TStream &Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader &ZipReader)
{
	SBCheckError(TElOpenOfficePackage_Open_3(_Handle, Stream.getHandle(), StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, ZipReader.getHandle()));
}

SB_INLINE void TElOpenOfficePackage::Open(TStream *Stream, int64_t StreamOffset, bool OwnStream, bool ReadOnly, TElZipReader *ZipReader)
{
	SBCheckError(TElOpenOfficePackage_Open_3(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, StreamOffset, (int8_t)OwnStream, (int8_t)ReadOnly, (ZipReader != NULL) ? ZipReader->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELZIPREADER_AND_TSTREAM */

SB_INLINE void TElOpenOfficePackage::Flush()
{
	SBCheckError(TElOpenOfficePackage_Flush(_Handle));
}

SB_INLINE void TElOpenOfficePackage::FlushManifest()
{
	SBCheckError(TElOpenOfficePackage_FlushManifest(_Handle));
}

SB_INLINE void TElOpenOfficePackage::Close()
{
	SBCheckError(TElOpenOfficePackage_Close(_Handle));
}

SB_INLINE void TElOpenOfficePackage::CreateEntry(const std::string &Path)
{
	SBCheckError(TElOpenOfficePackage_CreateEntry(_Handle, Path.data(), (int32_t)Path.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOpenOfficePackage::CreateStream(const std::string &Path, int64_t ExpectedStreamSize)
{
	TStreamHandle OutResult;
	SBCheckError(TElOpenOfficePackage_CreateStream(_Handle, Path.data(), (int32_t)Path.length(), ExpectedStreamSize, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOpenOfficePackage::GetStream(const std::string &Path)
{
	TStreamHandle OutResult;
	SBCheckError(TElOpenOfficePackage_GetStream(_Handle, Path.data(), (int32_t)Path.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE TStreamHandle TElOpenOfficePackage::GetStream(const std::string &Path, bool ReadOnly)
{
	TStreamHandle OutResult;
	SBCheckError(TElOpenOfficePackage_GetStream_1(_Handle, Path.data(), (int32_t)Path.length(), (int8_t)ReadOnly, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElOpenOfficePackage::CloseStream(TStream &Stream)
{
	SBCheckError(TElOpenOfficePackage_CloseStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElOpenOfficePackage::CloseStream(TStream *Stream)
{
	SBCheckError(TElOpenOfficePackage_CloseStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElOpenOfficePackage::CloseStream(const std::string &Path)
{
	SBCheckError(TElOpenOfficePackage_CloseStream_1(_Handle, Path.data(), (int32_t)Path.length()));
}

SB_INLINE void TElOpenOfficePackage::DeleteStream(const std::string &Path)
{
	SBCheckError(TElOpenOfficePackage_DeleteStream(_Handle, Path.data(), (int32_t)Path.length()));
}

bool TElOpenOfficePackage::StreamExists(const std::string &Path)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficePackage_StreamExists(_Handle, Path.data(), (int32_t)Path.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElOpenOfficePackage::get_IsReadOnly()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElOpenOfficePackage_get_IsReadOnly(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElOpenOfficePackage::get_MimeType(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElOpenOfficePackage_get_MimeType(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1846707862, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElOpenOfficePackage::set_MimeType(const std::string &Value)
{
	SBCheckError(TElOpenOfficePackage_set_MimeType(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
TElOpenOfficeXMLManifest* TElOpenOfficePackage::get_Manifest()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficePackage_get_Manifest(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Manifest)
		this->_Inst_Manifest = new TElOpenOfficeXMLManifest(hOutResult, ohFalse);
	else
		this->_Inst_Manifest->updateHandle(hOutResult);
	return this->_Inst_Manifest;
}
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */

SB_INLINE int32_t TElOpenOfficePackage::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElOpenOfficePackage_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOpenOfficePackage::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElOpenOfficePackage_set_CompressionLevel(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPREADER
TElZipReader* TElOpenOfficePackage::get_ZipReader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOpenOfficePackage_get_ZipReader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ZipReader)
		this->_Inst_ZipReader = new TElZipReader(hOutResult, ohFalse);
	else
		this->_Inst_ZipReader->updateHandle(hOutResult);
	return this->_Inst_ZipReader;
}
#endif /* SB_USE_CLASS_TELZIPREADER */

SB_INLINE void TElOpenOfficePackage::get_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficePackage_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficePackage::set_OnCreateTemporaryStream(TSBOfficeCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficePackage_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficePackage::get_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficePackage_get_OnCloseTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficePackage::set_OnCloseTemporaryStream(TSBOfficeCloseTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficePackage_set_OnCloseTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficePackage::get_OnGetDataStream(TSBOfficeGetDataStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficePackage_get_OnGetDataStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficePackage::set_OnGetDataStream(TSBOfficeGetDataStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficePackage_set_OnGetDataStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElOpenOfficePackage::get_OnCloseDataStream(TSBOfficeCloseDataStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElOpenOfficePackage_get_OnCloseDataStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElOpenOfficePackage::set_OnCloseDataStream(TSBOfficeCloseDataStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElOpenOfficePackage_set_OnCloseDataStream(_Handle, pMethodValue, pDataValue));
}

void TElOpenOfficePackage::initInstances()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
	this->_Inst_Manifest = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */
#ifdef SB_USE_CLASS_TELZIPREADER
	this->_Inst_ZipReader = NULL;
#endif /* SB_USE_CLASS_TELZIPREADER */
}

TElOpenOfficePackage::TElOpenOfficePackage(TElOpenOfficePackageHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElOpenOfficePackage::TElOpenOfficePackage() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOpenOfficePackage_Create(&_Handle));
}

TElOpenOfficePackage::~TElOpenOfficePackage()
{
#ifdef SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST
	delete this->_Inst_Manifest;
	this->_Inst_Manifest = NULL;
#endif /* SB_USE_CLASS_TELOPENOFFICEXMLMANIFEST */
#ifdef SB_USE_CLASS_TELZIPREADER
	delete this->_Inst_ZipReader;
	this->_Inst_ZipReader = NULL;
#endif /* SB_USE_CLASS_TELZIPREADER */
}
#endif /* SB_USE_CLASS_TELOPENOFFICEPACKAGE */

};	/* namespace SecureBlackbox */

