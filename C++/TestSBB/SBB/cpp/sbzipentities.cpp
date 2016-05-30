#include "sbzipentities.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELZIPENTITY

SB_INLINE void TElZipEntity::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipEntity_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntity::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipEntity_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntity::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipEntity_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipEntity::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipEntity_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntity::Load(void * UserData)
{
	SBCheckError(TElZipEntity_Load(_Handle, UserData));
}

SB_INLINE void TElZipEntity::Save(void * UserData)
{
	SBCheckError(TElZipEntity_Save(_Handle, UserData));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElZipEntity::SaveToStream(TStream &Stream, void * UserData)
{
	SBCheckError(TElZipEntity_SaveToStream(_Handle, Stream.getHandle(), UserData));
}

SB_INLINE void TElZipEntity::SaveToStream(TStream *Stream, void * UserData)
{
	SBCheckError(TElZipEntity_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, UserData));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElZipEntity::SaveToBuffer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntity_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2024305251, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntity::DataAvailable()
{
	SBCheckError(TElZipEntity_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipEntity::get_BodySize()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntity_get_BodySize(_Handle, &OutResult));
	return OutResult;
}

void TElZipEntity::get_Body(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntity_get_Body(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-965944862, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElZipEntity::get_Loaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntity_get_Loaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntity::get_Signature()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntity_get_Signature(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntity::set_Signature(uint32_t Value)
{
	SBCheckError(TElZipEntity_set_Signature(_Handle, Value));
}

bool TElZipEntity::get_SkipSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntity_get_SkipSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntity::set_SkipSignature(bool Value)
{
	SBCheckError(TElZipEntity_set_SkipSignature(_Handle, (int8_t)Value));
}

bool TElZipEntity::get_Zip64Used()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntity_get_Zip64Used(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntity::set_Zip64Used(bool Value)
{
	SBCheckError(TElZipEntity_set_Zip64Used(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElZipEntity::get_Position()
{
	int64_t OutResult;
	SBCheckError(TElZipEntity_get_Position(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntity::set_Position(int64_t Value)
{
	SBCheckError(TElZipEntity_set_Position(_Handle, Value));
}

SB_INLINE void TElZipEntity::get_OnRead(TSBZipReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipEntity_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipEntity::set_OnRead(TSBZipReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipEntity_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipEntity::get_OnWrite(TSBZipWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipEntity_get_OnWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipEntity::set_OnWrite(TSBZipWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipEntity_set_OnWrite(_Handle, pMethodValue, pDataValue));
}

TElZipEntity::TElZipEntity(TElZipEntityHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElZipEntity::TElZipEntity() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntity_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITY */

#ifdef SB_USE_CLASS_TELZIPLOCALFILEHEADER

SB_INLINE void TElZipLocalFileHeader::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipLocalFileHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipLocalFileHeader::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipLocalFileHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipLocalFileHeader::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipLocalFileHeader_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipLocalFileHeader::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipLocalFileHeader_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipLocalFileHeader::Load(void * UserData)
{
	SBCheckError(TElZipLocalFileHeader_Load(_Handle, UserData));
}

SB_INLINE void TElZipLocalFileHeader::Save(void * UserData)
{
	SBCheckError(TElZipLocalFileHeader_Save(_Handle, UserData));
}

SB_INLINE void TElZipLocalFileHeader::DataAvailable()
{
	SBCheckError(TElZipLocalFileHeader_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_VersionToExtract()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_VersionToExtract(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_VersionToExtract(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_VersionToExtract(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_GeneralBitFlag()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_GeneralBitFlag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_GeneralBitFlag(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_GeneralBitFlag(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPDATADESCRIPTOR
TElZipDataDescriptor* TElZipLocalFileHeader::get_DataDescriptor()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipLocalFileHeader_get_DataDescriptor(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataDescriptor)
		this->_Inst_DataDescriptor = new TElZipDataDescriptor(hOutResult, ohFalse);
	else
		this->_Inst_DataDescriptor->updateHandle(hOutResult);
	return this->_Inst_DataDescriptor;
}

SB_INLINE void TElZipLocalFileHeader::set_DataDescriptor(TElZipDataDescriptor &Value)
{
	SBCheckError(TElZipLocalFileHeader_set_DataDescriptor(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipLocalFileHeader::set_DataDescriptor(TElZipDataDescriptor *Value)
{
	SBCheckError(TElZipLocalFileHeader_set_DataDescriptor(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELZIPDATADESCRIPTOR */

SB_INLINE uint32_t TElZipLocalFileHeader::get_CompressionMethod()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_CompressionMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_CompressionMethod(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_CompressionMethod(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_LastModFileTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_LastModFileTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_LastModFileTime(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_LastModFileTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_LastModFileDate()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_LastModFileDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_LastModFileDate(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_LastModFileDate(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_CRC32(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_CRC32(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_CompressedSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_CompressedSize(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_CompressedSize(_Handle, Value));
}

SB_INLINE uint32_t TElZipLocalFileHeader::get_OriginalSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_OriginalSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_OriginalSize(uint32_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_OriginalSize(_Handle, Value));
}

void TElZipLocalFileHeader::get_FileName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipLocalFileHeader_get_FileName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(914518135, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipLocalFileHeader::set_FileName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipLocalFileHeader_set_FileName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipLocalFileHeader::get_ExtraField(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipLocalFileHeader_get_ExtraField(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-465658070, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipLocalFileHeader::set_ExtraField(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipLocalFileHeader_set_ExtraField(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int64_t TElZipLocalFileHeader::get_DataOffset()
{
	int64_t OutResult;
	SBCheckError(TElZipLocalFileHeader_get_DataOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipLocalFileHeader::set_DataOffset(int64_t Value)
{
	SBCheckError(TElZipLocalFileHeader_set_DataOffset(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
TElZipEntityExtensions* TElZipLocalFileHeader::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipLocalFileHeader_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElZipEntityExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */

bool TElZipLocalFileHeader::get_DataDescriptorUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipLocalFileHeader_get_DataDescriptorUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipLocalFileHeader::set_DataDescriptorUsed(bool Value)
{
	SBCheckError(TElZipLocalFileHeader_set_DataDescriptorUsed(_Handle, (int8_t)Value));
}

void TElZipLocalFileHeader::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPDATADESCRIPTOR
	this->_Inst_DataDescriptor = NULL;
#endif /* SB_USE_CLASS_TELZIPDATADESCRIPTOR */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}

TElZipLocalFileHeader::TElZipLocalFileHeader(TElZipLocalFileHeaderHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
	initInstances();
}

TElZipLocalFileHeader::TElZipLocalFileHeader() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipLocalFileHeader_Create(&_Handle));
}

TElZipLocalFileHeader::~TElZipLocalFileHeader()
{
#ifdef SB_USE_CLASS_TELZIPDATADESCRIPTOR
	delete this->_Inst_DataDescriptor;
	this->_Inst_DataDescriptor = NULL;
#endif /* SB_USE_CLASS_TELZIPDATADESCRIPTOR */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELZIPLOCALFILEHEADER */

#ifdef SB_USE_CLASS_TELZIPCENTRALFILEHEADER

SB_INLINE void TElZipCentralFileHeader::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipCentralFileHeader_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipCentralFileHeader::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipCentralFileHeader_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipCentralFileHeader::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipCentralFileHeader_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipCentralFileHeader::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipCentralFileHeader_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipCentralFileHeader::Load(void * UserData)
{
	SBCheckError(TElZipCentralFileHeader_Load(_Handle, UserData));
}

SB_INLINE void TElZipCentralFileHeader::Save(void * UserData)
{
	SBCheckError(TElZipCentralFileHeader_Save(_Handle, UserData));
}

SB_INLINE void TElZipCentralFileHeader::DataAvailable()
{
	SBCheckError(TElZipCentralFileHeader_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_VersionMadeBy()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_VersionMadeBy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_VersionMadeBy(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_VersionMadeBy(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_VersionToExtract()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_VersionToExtract(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_VersionToExtract(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_VersionToExtract(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_GeneralBitFlag()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_GeneralBitFlag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_GeneralBitFlag(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_GeneralBitFlag(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_CompressionMethod()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_CompressionMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_CompressionMethod(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_CompressionMethod(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_LastModFileTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_LastModFileTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_LastModFileTime(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_LastModFileTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_LastModFileDate()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_LastModFileDate(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_LastModFileDate(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_LastModFileDate(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_CRC32(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_CRC32(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_CompressedSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_CompressedSize(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_CompressedSize(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_OriginalSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_OriginalSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_OriginalSize(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_OriginalSize(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_DiskNumberStart()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_DiskNumberStart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_DiskNumberStart(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_DiskNumberStart(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_InternalFileAttributes()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_InternalFileAttributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_InternalFileAttributes(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_InternalFileAttributes(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_ExternalFileAttributes()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_ExternalFileAttributes(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_ExternalFileAttributes(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_ExternalFileAttributes(_Handle, Value));
}

SB_INLINE uint32_t TElZipCentralFileHeader::get_LocalHeaderOffset()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralFileHeader_get_LocalHeaderOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralFileHeader::set_LocalHeaderOffset(uint32_t Value)
{
	SBCheckError(TElZipCentralFileHeader_set_LocalHeaderOffset(_Handle, Value));
}

void TElZipCentralFileHeader::get_FileName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralFileHeader_get_FileName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-494809799, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralFileHeader::set_FileName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralFileHeader_set_FileName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipCentralFileHeader::get_ExtraField(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralFileHeader_get_ExtraField(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1058334355, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralFileHeader::set_ExtraField(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralFileHeader_set_ExtraField(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipCentralFileHeader::get_Comment(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralFileHeader_get_Comment(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1830159033, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralFileHeader::set_Comment(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralFileHeader_set_Comment(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
TElZipEntityExtensions* TElZipCentralFileHeader::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipCentralFileHeader_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElZipEntityExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */

void TElZipCentralFileHeader::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}

TElZipCentralFileHeader::TElZipCentralFileHeader(TElZipCentralFileHeaderHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
	initInstances();
}

TElZipCentralFileHeader::TElZipCentralFileHeader() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipCentralFileHeader_Create(&_Handle));
}

TElZipCentralFileHeader::~TElZipCentralFileHeader()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELZIPCENTRALFILEHEADER */

#ifdef SB_USE_CLASS_TELZIPDATADESCRIPTOR

SB_INLINE void TElZipDataDescriptor::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipDataDescriptor_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipDataDescriptor::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipDataDescriptor_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipDataDescriptor::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipDataDescriptor_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipDataDescriptor::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipDataDescriptor_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipDataDescriptor::Load(void * UserData)
{
	SBCheckError(TElZipDataDescriptor_Load(_Handle, UserData));
}

SB_INLINE void TElZipDataDescriptor::Save(void * UserData)
{
	SBCheckError(TElZipDataDescriptor_Save(_Handle, UserData));
}

SB_INLINE void TElZipDataDescriptor::DataAvailable()
{
	SBCheckError(TElZipDataDescriptor_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipDataDescriptor::get_CRC32()
{
	uint32_t OutResult;
	SBCheckError(TElZipDataDescriptor_get_CRC32(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDataDescriptor::set_CRC32(uint32_t Value)
{
	SBCheckError(TElZipDataDescriptor_set_CRC32(_Handle, Value));
}

SB_INLINE int64_t TElZipDataDescriptor::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElZipDataDescriptor_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDataDescriptor::set_CompressedSize(int64_t Value)
{
	SBCheckError(TElZipDataDescriptor_set_CompressedSize(_Handle, Value));
}

SB_INLINE int64_t TElZipDataDescriptor::get_OriginalSize()
{
	int64_t OutResult;
	SBCheckError(TElZipDataDescriptor_get_OriginalSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipDataDescriptor::set_OriginalSize(int64_t Value)
{
	SBCheckError(TElZipDataDescriptor_set_OriginalSize(_Handle, Value));
}

bool TElZipDataDescriptor::get_WriteSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipDataDescriptor_get_WriteSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipDataDescriptor::set_WriteSignature(bool Value)
{
	SBCheckError(TElZipDataDescriptor_set_WriteSignature(_Handle, (int8_t)Value));
}

TElZipDataDescriptor::TElZipDataDescriptor(TElZipDataDescriptorHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
}

TElZipDataDescriptor::TElZipDataDescriptor() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipDataDescriptor_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPDATADESCRIPTOR */

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS

SB_INLINE void TElZipEntityExtensions::Assign(TElZipEntityExtensions &Source)
{
	SBCheckError(TElZipEntityExtensions_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityExtensions::Assign(TElZipEntityExtensions *Source)
{
	SBCheckError(TElZipEntityExtensions_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityExtensions::AssignTo(TElZipEntityExtensions &Dest)
{
	SBCheckError(TElZipEntityExtensions_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipEntityExtensions::AssignTo(TElZipEntityExtensions *Dest)
{
	SBCheckError(TElZipEntityExtensions_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityExtensions::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityExtensions_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityExtensions::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityExtensions_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1478363975, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

void TElZipEntityExtensions::Save(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntityExtensions_Save(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1603024002, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElZipEntityExtensions::AddExtension(uint32_t ExtensionType)
{
	int32_t OutResult;
	SBCheckError(TElZipEntityExtensions_AddExtension(_Handle, ExtensionType, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSION
SB_INLINE TElZipEntityExtensionHandle TElZipEntityExtensions::ExtensionByType(uint32_t ExtensionType, int32_t Index)
{
	TElZipEntityExtensionHandle OutResult;
	SBCheckError(TElZipEntityExtensions_ExtensionByType(_Handle, ExtensionType, Index, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSION */

SB_INLINE void TElZipEntityExtensions::RemoveExtension(int32_t Index)
{
	SBCheckError(TElZipEntityExtensions_RemoveExtension(_Handle, Index));
}

SB_INLINE void TElZipEntityExtensions::RemoveExtensionByType(uint32_t ExtensionType, int32_t Index)
{
	SBCheckError(TElZipEntityExtensions_RemoveExtensionByType(_Handle, ExtensionType, Index));
}

SB_INLINE void TElZipEntityExtensions::ClearExtensions()
{
	SBCheckError(TElZipEntityExtensions_ClearExtensions(_Handle));
}

bool TElZipEntityExtensions::get_Size32Bit()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityExtensions_get_Size32Bit(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityExtensions::set_Size32Bit(bool Value)
{
	SBCheckError(TElZipEntityExtensions_set_Size32Bit(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELZIPENTITY
TElZipEntity* TElZipEntityExtensions::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElZipEntity(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}

SB_INLINE void TElZipEntityExtensions::set_Owner(TElZipEntity &Value)
{
	SBCheckError(TElZipEntityExtensions_set_Owner(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipEntityExtensions::set_Owner(TElZipEntity *Value)
{
	SBCheckError(TElZipEntityExtensions_set_Owner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELZIPENTITY */

SB_INLINE int32_t TElZipEntityExtensions::get_ExtensionCount()
{
	int32_t OutResult;
	SBCheckError(TElZipEntityExtensions_get_ExtensionCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSION
TElZipEntityExtension* TElZipEntityExtensions::get_Extensions(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Extensions(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElZipEntityExtension(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSION */

SB_INLINE int32_t TElZipEntityExtensions::get_BodySize()
{
	int32_t OutResult;
	SBCheckError(TElZipEntityExtensions_get_BodySize(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION
TElZipEntityZip64InfoExtension* TElZipEntityExtensions::get_Zip64Info()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Zip64Info(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Zip64Info)
		this->_Inst_Zip64Info = new TElZipEntityZip64InfoExtension(hOutResult, ohFalse);
	else
		this->_Inst_Zip64Info->updateHandle(hOutResult);
	return this->_Inst_Zip64Info;
}
#endif /* SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION
TElZipEntityStrongEncryptionExtension* TElZipEntityExtensions::get_StrongEncryptionHeader()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_StrongEncryptionHeader(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_StrongEncryptionHeader)
		this->_Inst_StrongEncryptionHeader = new TElZipEntityStrongEncryptionExtension(hOutResult, ohFalse);
	else
		this->_Inst_StrongEncryptionHeader->updateHandle(hOutResult);
	return this->_Inst_StrongEncryptionHeader;
}
#endif /* SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION
TElZipEntityWinZipAESExtension* TElZipEntityExtensions::get_WinZipAesInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_WinZipAesInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_WinZipAesInfo)
		this->_Inst_WinZipAesInfo = new TElZipEntityWinZipAESExtension(hOutResult, ohFalse);
	else
		this->_Inst_WinZipAesInfo->updateHandle(hOutResult);
	return this->_Inst_WinZipAesInfo;
}
#endif /* SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION
TElZipEntityCertificateStoreExtension* TElZipEntityExtensions::get_CertificateStore()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_CertificateStore(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertificateStore)
		this->_Inst_CertificateStore = new TElZipEntityCertificateStoreExtension(hOutResult, ohFalse);
	else
		this->_Inst_CertificateStore->updateHandle(hOutResult);
	return this->_Inst_CertificateStore;
}
#endif /* SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION
TElZipEntityCentralDirSignatureExtension* TElZipEntityExtensions::get_CentralDirectorySignature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_CentralDirectorySignature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CentralDirectorySignature)
		this->_Inst_CentralDirectorySignature = new TElZipEntityCentralDirSignatureExtension(hOutResult, ohFalse);
	else
		this->_Inst_CentralDirectorySignature->updateHandle(hOutResult);
	return this->_Inst_CentralDirectorySignature;
}
#endif /* SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION
TElZipEntityExtendedTimestampExtension* TElZipEntityExtensions::get_ExtendedTimestamp()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_ExtendedTimestamp(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ExtendedTimestamp)
		this->_Inst_ExtendedTimestamp = new TElZipEntityExtendedTimestampExtension(hOutResult, ohFalse);
	else
		this->_Inst_ExtendedTimestamp->updateHandle(hOutResult);
	return this->_Inst_ExtendedTimestamp;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION
TElZipEntityUIDAndGIDExtension* TElZipEntityExtensions::get_UIDAndGID()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_UIDAndGID(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_UIDAndGID)
		this->_Inst_UIDAndGID = new TElZipEntityUIDAndGIDExtension(hOutResult, ohFalse);
	else
		this->_Inst_UIDAndGID->updateHandle(hOutResult);
	return this->_Inst_UIDAndGID;
}
#endif /* SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION
TElZipEntityUnix1Extension* TElZipEntityExtensions::get_Unix1()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Unix1(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Unix1)
		this->_Inst_Unix1 = new TElZipEntityUnix1Extension(hOutResult, ohFalse);
	else
		this->_Inst_Unix1->updateHandle(hOutResult);
	return this->_Inst_Unix1;
}
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION
TElZipEntityUnix2Extension* TElZipEntityExtensions::get_Unix2()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Unix2(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Unix2)
		this->_Inst_Unix2 = new TElZipEntityUnix2Extension(hOutResult, ohFalse);
	else
		this->_Inst_Unix2->updateHandle(hOutResult);
	return this->_Inst_Unix2;
}
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION */

SB_INLINE int32_t TElZipEntityExtensions::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElZipEntityExtensions_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION
TElZipEntitySignatureExtension* TElZipEntityExtensions::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtensions_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElZipEntitySignatureExtension(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION */

void TElZipEntityExtensions::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPENTITY
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITY */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSION
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION
	this->_Inst_Zip64Info = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION
	this->_Inst_StrongEncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION
	this->_Inst_WinZipAesInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION
	this->_Inst_CertificateStore = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION
	this->_Inst_CentralDirectorySignature = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION
	this->_Inst_ExtendedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION
	this->_Inst_UIDAndGID = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION
	this->_Inst_Unix1 = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION
	this->_Inst_Unix2 = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION */
}

TElZipEntityExtensions::TElZipEntityExtensions(TElZipEntityExtensionsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElZipEntityExtensions::TElZipEntityExtensions() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipEntityExtensions_Create(&_Handle));
}

TElZipEntityExtensions::~TElZipEntityExtensions()
{
#ifdef SB_USE_CLASS_TELZIPENTITY
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITY */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSION
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION
	delete this->_Inst_Zip64Info;
	this->_Inst_Zip64Info = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION
	delete this->_Inst_StrongEncryptionHeader;
	this->_Inst_StrongEncryptionHeader = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION
	delete this->_Inst_WinZipAesInfo;
	this->_Inst_WinZipAesInfo = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION
	delete this->_Inst_CertificateStore;
	this->_Inst_CertificateStore = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION
	delete this->_Inst_CentralDirectorySignature;
	this->_Inst_CentralDirectorySignature = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION
	delete this->_Inst_ExtendedTimestamp;
	this->_Inst_ExtendedTimestamp = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION
	delete this->_Inst_UIDAndGID;
	this->_Inst_UIDAndGID = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION
	delete this->_Inst_Unix1;
	this->_Inst_Unix1 = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION
	delete this->_Inst_Unix2;
	this->_Inst_Unix2 = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION */
#ifdef SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION */
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */

#ifdef SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE

SB_INLINE void TElZipCentralDirectorySignature::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipCentralDirectorySignature_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipCentralDirectorySignature::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipCentralDirectorySignature_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipCentralDirectorySignature::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipCentralDirectorySignature_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipCentralDirectorySignature::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipCentralDirectorySignature_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipCentralDirectorySignature::Load(void * UserData)
{
	SBCheckError(TElZipCentralDirectorySignature_Load(_Handle, UserData));
}

SB_INLINE void TElZipCentralDirectorySignature::Save(void * UserData)
{
	SBCheckError(TElZipCentralDirectorySignature_Save(_Handle, UserData));
}

SB_INLINE void TElZipCentralDirectorySignature::DataAvailable()
{
	SBCheckError(TElZipCentralDirectorySignature_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipCentralDirectorySignature::get_Version()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralDirectorySignature_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElZipCentralDirectorySignature::get_HashAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipCentralDirectorySignature_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipCentralDirectorySignature::set_HashAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipCentralDirectorySignature_set_HashAlgorithm(_Handle, Value));
}

void TElZipCentralDirectorySignature::get_IssuerName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralDirectorySignature_get_IssuerName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1962124583, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralDirectorySignature::set_IssuerName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralDirectorySignature_set_IssuerName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipCentralDirectorySignature::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralDirectorySignature_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1528552866, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralDirectorySignature::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralDirectorySignature_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipCentralDirectorySignature::get_CentralSignature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipCentralDirectorySignature_get_CentralSignature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1776620704, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipCentralDirectorySignature::set_CentralSignature(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipCentralDirectorySignature_set_CentralSignature(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipCentralDirectorySignature::TElZipCentralDirectorySignature(TElZipCentralDirectorySignatureHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
}

TElZipCentralDirectorySignature::TElZipCentralDirectorySignature() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipCentralDirectorySignature_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE */

#ifdef SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY

SB_INLINE void TElZip64EndOfCentralDirectory::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZip64EndOfCentralDirectory_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZip64EndOfCentralDirectory::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZip64EndOfCentralDirectory_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZip64EndOfCentralDirectory::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZip64EndOfCentralDirectory_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZip64EndOfCentralDirectory::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZip64EndOfCentralDirectory_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZip64EndOfCentralDirectory::Load(void * UserData)
{
	SBCheckError(TElZip64EndOfCentralDirectory_Load(_Handle, UserData));
}

SB_INLINE void TElZip64EndOfCentralDirectory::Save(void * UserData)
{
	SBCheckError(TElZip64EndOfCentralDirectory_Save(_Handle, UserData));
}

SB_INLINE void TElZip64EndOfCentralDirectory::DataAvailable()
{
	SBCheckError(TElZip64EndOfCentralDirectory_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_StructureVersion()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_StructureVersion(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_StructureVersion(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_StructureVersion(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_VersionMadeBy()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_VersionMadeBy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_VersionMadeBy(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_VersionMadeBy(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_VersionToExtract()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_VersionToExtract(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_VersionToExtract(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_VersionToExtract(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_DiskNumber()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_DiskNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_DiskNumber(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_DiskNumber(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_CentralDirStartDisk()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_CentralDirStartDisk(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_CentralDirStartDisk(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_CentralDirStartDisk(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_EntriesOnDiskCount()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_EntriesOnDiskCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_EntriesOnDiskCount(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_EntriesOnDiskCount(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_EntriesCount()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_EntriesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_EntriesCount(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_EntriesCount(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_CentralDirSize()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_CentralDirSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_CentralDirSize(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_CentralDirSize(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_CentralDirOffset()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_CentralDirOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_CentralDirOffset(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_CentralDirOffset(_Handle, Value));
}

void TElZip64EndOfCentralDirectory::get_ExtensibleData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZip64EndOfCentralDirectory_get_ExtensibleData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(238049893, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_ExtensibleData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_ExtensibleData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_CompressionMethod()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_CompressionMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_CompressionMethod(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_CompressionMethod(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_CompressedSize(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_CompressedSize(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectory::get_OriginalSize()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_OriginalSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_OriginalSize(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_OriginalSize(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_EncryptionAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_EncryptionAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_EncryptionAlgorithm(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_EncryptionAlgorithm(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_KeyLength()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_KeyLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_KeyLength(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_KeyLength(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_EncryptionFlags()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_EncryptionFlags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_EncryptionFlags(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_EncryptionFlags(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectory::get_HashAlgortihm()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectory_get_HashAlgortihm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_HashAlgortihm(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_HashAlgortihm(_Handle, Value));
}

void TElZip64EndOfCentralDirectory::get_Hash(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZip64EndOfCentralDirectory_get_Hash(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1709263965, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZip64EndOfCentralDirectory::set_Hash(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZip64EndOfCentralDirectory_set_Hash(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZip64EndOfCentralDirectory::TElZip64EndOfCentralDirectory(TElZip64EndOfCentralDirectoryHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
}

TElZip64EndOfCentralDirectory::TElZip64EndOfCentralDirectory() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZip64EndOfCentralDirectory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY */

#ifdef SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORYLOCATOR

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::Load(void * UserData)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_Load(_Handle, UserData));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::Save(void * UserData)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_Save(_Handle, UserData));
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::DataAvailable()
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectoryLocator::get_DiskNumber()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_get_DiskNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::set_DiskNumber(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_set_DiskNumber(_Handle, Value));
}

SB_INLINE int64_t TElZip64EndOfCentralDirectoryLocator::get_Offset()
{
	int64_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_get_Offset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::set_Offset(int64_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_set_Offset(_Handle, Value));
}

SB_INLINE uint32_t TElZip64EndOfCentralDirectoryLocator::get_TotalDiskCount()
{
	uint32_t OutResult;
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_get_TotalDiskCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZip64EndOfCentralDirectoryLocator::set_TotalDiskCount(uint32_t Value)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_set_TotalDiskCount(_Handle, Value));
}

TElZip64EndOfCentralDirectoryLocator::TElZip64EndOfCentralDirectoryLocator(TElZip64EndOfCentralDirectoryLocatorHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
}

TElZip64EndOfCentralDirectoryLocator::TElZip64EndOfCentralDirectoryLocator() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZip64EndOfCentralDirectoryLocator_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORYLOCATOR */

#ifdef SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY

SB_INLINE void TElZipEndOfCentralDirectory::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipEndOfCentralDirectory_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEndOfCentralDirectory::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipEndOfCentralDirectory_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEndOfCentralDirectory::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipEndOfCentralDirectory_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipEndOfCentralDirectory::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipEndOfCentralDirectory_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEndOfCentralDirectory::Load(void * UserData)
{
	SBCheckError(TElZipEndOfCentralDirectory_Load(_Handle, UserData));
}

SB_INLINE void TElZipEndOfCentralDirectory::Save(void * UserData)
{
	SBCheckError(TElZipEndOfCentralDirectory_Save(_Handle, UserData));
}

SB_INLINE void TElZipEndOfCentralDirectory::DataAvailable()
{
	SBCheckError(TElZipEndOfCentralDirectory_DataAvailable(_Handle));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_DiskNumber()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_DiskNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_DiskNumber(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_DiskNumber(_Handle, Value));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_CentralDirStartDisk()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_CentralDirStartDisk(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_CentralDirStartDisk(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_CentralDirStartDisk(_Handle, Value));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_EntriesOnDiskCount()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_EntriesOnDiskCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_EntriesOnDiskCount(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_EntriesOnDiskCount(_Handle, Value));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_EntriesCount()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_EntriesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_EntriesCount(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_EntriesCount(_Handle, Value));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_CentralDirSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_CentralDirSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_CentralDirSize(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_CentralDirSize(_Handle, Value));
}

SB_INLINE uint32_t TElZipEndOfCentralDirectory::get_CentralDirOffset()
{
	uint32_t OutResult;
	SBCheckError(TElZipEndOfCentralDirectory_get_CentralDirOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEndOfCentralDirectory::set_CentralDirOffset(uint32_t Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_CentralDirOffset(_Handle, Value));
}

void TElZipEndOfCentralDirectory::get_Comment(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEndOfCentralDirectory_get_Comment(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(80875795, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEndOfCentralDirectory::set_Comment(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEndOfCentralDirectory_set_Comment(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipEndOfCentralDirectory::TElZipEndOfCentralDirectory(TElZipEndOfCentralDirectoryHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
}

TElZipEndOfCentralDirectory::TElZipEndOfCentralDirectory() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEndOfCentralDirectory_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY */

#ifdef SB_USE_CLASS_TELZIPARCHIVEEXTRADATA

SB_INLINE void TElZipArchiveExtraData::Assign(TElZipEntity &Source)
{
	SBCheckError(TElZipArchiveExtraData_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipArchiveExtraData::Assign(TElZipEntity *Source)
{
	SBCheckError(TElZipArchiveExtraData_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipArchiveExtraData::AssignTo(TElZipEntity &Dest)
{
	SBCheckError(TElZipArchiveExtraData_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipArchiveExtraData::AssignTo(TElZipEntity *Dest)
{
	SBCheckError(TElZipArchiveExtraData_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipArchiveExtraData::Load(void * UserData)
{
	SBCheckError(TElZipArchiveExtraData_Load(_Handle, UserData));
}

SB_INLINE void TElZipArchiveExtraData::Save(void * UserData)
{
	SBCheckError(TElZipArchiveExtraData_Save(_Handle, UserData));
}

SB_INLINE void TElZipArchiveExtraData::DataAvailable()
{
	SBCheckError(TElZipArchiveExtraData_DataAvailable(_Handle));
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
TElZipEntityExtensions* TElZipArchiveExtraData::get_Extensions()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipArchiveExtraData_get_Extensions(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Extensions)
		this->_Inst_Extensions = new TElZipEntityExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Extensions->updateHandle(hOutResult);
	return this->_Inst_Extensions;
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */

void TElZipArchiveExtraData::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}

TElZipArchiveExtraData::TElZipArchiveExtraData(TElZipArchiveExtraDataHandle handle, TElOwnHandle ownHandle) : TElZipEntity(handle, ownHandle)
{
	initInstances();
}

TElZipArchiveExtraData::TElZipArchiveExtraData() : TElZipEntity(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipArchiveExtraData_Create(&_Handle));
}

TElZipArchiveExtraData::~TElZipArchiveExtraData()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	delete this->_Inst_Extensions;
	this->_Inst_Extensions = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEEXTRADATA */

#ifdef SB_USE_CLASS_TELZIPPROCESSOR

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElZipProcessor::Process(TStream &Stream)
{
	SBCheckError(TElZipProcessor_Process(_Handle, Stream.getHandle()));
}

SB_INLINE void TElZipProcessor::Process(TStream *Stream)
{
	SBCheckError(TElZipProcessor_Process(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELZIPLOCALFILEHEADER_AND_TSTREAM
bool TElZipProcessor::ProcessLocalHeader(TStream &Stream, TElZipLocalFileHeader &Header)
{
	TElClassHandle hHeader = Header.getHandle();
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_ProcessLocalHeader(_Handle, Stream.getHandle(), &hHeader, &OutResultRaw));
	Header.updateHandle(hHeader);
	return (OutResultRaw != 0);
}

bool TElZipProcessor::ProcessLocalHeader(TStream *Stream, TElZipLocalFileHeader &Header)
{
	TElClassHandle hHeader = Header.getHandle();
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_ProcessLocalHeader(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &hHeader, &OutResultRaw));
	Header.updateHandle(hHeader);
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASSES_TELZIPLOCALFILEHEADER_AND_TSTREAM */

SB_INLINE void TElZipProcessor::DataAvailable()
{
	SBCheckError(TElZipProcessor_DataAvailable(_Handle));
}

bool TElZipProcessor::get_Processed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_Processed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipProcessor::get_EndOfData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_EndOfData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipProcessor::get_CentralDirectoryCompressed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_CentralDirectoryCompressed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipProcessor::get_CentralDirectoryEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_CentralDirectoryEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElZipProcessor::get_UseCentralDirectory()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_UseCentralDirectory(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipProcessor::set_UseCentralDirectory(bool Value)
{
	SBCheckError(TElZipProcessor_set_UseCentralDirectory(_Handle, (int8_t)Value));
}

bool TElZipProcessor::get_OnePass()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_OnePass(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipProcessor::set_OnePass(bool Value)
{
	SBCheckError(TElZipProcessor_set_OnePass(_Handle, (int8_t)Value));
}

bool TElZipProcessor::get_Zip64Format()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipProcessor_get_Zip64Format(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY
TElZipEndOfCentralDirectory* TElZipProcessor::get_EndOfCentralDir()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessor_get_EndOfCentralDir(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_EndOfCentralDir)
		this->_Inst_EndOfCentralDir = new TElZipEndOfCentralDirectory(hOutResult, ohFalse);
	else
		this->_Inst_EndOfCentralDir->updateHandle(hOutResult);
	return this->_Inst_EndOfCentralDir;
}
#endif /* SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY */

#ifdef SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY
TElZip64EndOfCentralDirectory* TElZipProcessor::get_Zip64EndOfCentralDir()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessor_get_Zip64EndOfCentralDir(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Zip64EndOfCentralDir)
		this->_Inst_Zip64EndOfCentralDir = new TElZip64EndOfCentralDirectory(hOutResult, ohFalse);
	else
		this->_Inst_Zip64EndOfCentralDir->updateHandle(hOutResult);
	return this->_Inst_Zip64EndOfCentralDir;
}
#endif /* SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY */

#ifdef SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE
TElZipCentralDirectorySignature* TElZipProcessor::get_CentralDirectorySignature()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessor_get_CentralDirectorySignature(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CentralDirectorySignature)
		this->_Inst_CentralDirectorySignature = new TElZipCentralDirectorySignature(hOutResult, ohFalse);
	else
		this->_Inst_CentralDirectorySignature->updateHandle(hOutResult);
	return this->_Inst_CentralDirectorySignature;
}
#endif /* SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE */

SB_INLINE int64_t TElZipProcessor::get_CentralDirectoryEntriesCount()
{
	int64_t OutResult;
	SBCheckError(TElZipProcessor_get_CentralDirectoryEntriesCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElZipProcessor::get_CentralDirectorySize()
{
	int64_t OutResult;
	SBCheckError(TElZipProcessor_get_CentralDirectorySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElZipProcessor::get_CentralDirectoryPosition()
{
	int64_t OutResult;
	SBCheckError(TElZipProcessor_get_CentralDirectoryPosition(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELZIPARCHIVEEXTRADATA
TElZipArchiveExtraData* TElZipProcessor::get_ArchiveExtraData()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipProcessor_get_ArchiveExtraData(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_ArchiveExtraData)
		this->_Inst_ArchiveExtraData = new TElZipArchiveExtraData(hOutResult, ohFalse);
	else
		this->_Inst_ArchiveExtraData->updateHandle(hOutResult);
	return this->_Inst_ArchiveExtraData;
}
#endif /* SB_USE_CLASS_TELZIPARCHIVEEXTRADATA */

SB_INLINE void TElZipProcessor::get_OnLocalFileHeaderLoaded(TSBZipLocalFileHeaderLoadedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnLocalFileHeaderLoaded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnLocalFileHeaderLoaded(TSBZipLocalFileHeaderLoadedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnLocalFileHeaderLoaded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnDataDescriptorLoaded(TSBZipDataDescriptorLoadedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnDataDescriptorLoaded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnDataDescriptorLoaded(TSBZipDataDescriptorLoadedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnDataDescriptorLoaded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnCentralFileHeaderLoaded(TSBZipCentralFileHeaderLoadedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnCentralFileHeaderLoaded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnCentralFileHeaderLoaded(TSBZipCentralFileHeaderLoadedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnCentralFileHeaderLoaded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnFileData(TSBZipFileDataEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnFileData(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnFileData(TSBZipFileDataEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnFileData(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnFileHeadersLoaded(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnFileHeadersLoaded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnFileHeadersLoaded(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnFileHeadersLoaded(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnCentralDirectoryFound(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnCentralDirectoryFound(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnCentralDirectoryFound(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnCentralDirectoryFound(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnProcessCentralDirectory(TSBZipCentralDirectoryProcessEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnProcessCentralDirectory(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnProcessCentralDirectory(TSBZipCentralDirectoryProcessEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnProcessCentralDirectory(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnCentralDirectoryProcessed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnCentralDirectoryProcessed(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnCentralDirectoryProcessed(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnCentralDirectoryProcessed(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElZipProcessor::get_OnArchiveError(TSBZipArchiveErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElZipProcessor_get_OnArchiveError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElZipProcessor::set_OnArchiveError(TSBZipArchiveErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElZipProcessor_set_OnArchiveError(_Handle, pMethodValue, pDataValue));
}

void TElZipProcessor::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY
	this->_Inst_EndOfCentralDir = NULL;
#endif /* SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY */
#ifdef SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY
	this->_Inst_Zip64EndOfCentralDir = NULL;
#endif /* SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY */
#ifdef SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE
	this->_Inst_CentralDirectorySignature = NULL;
#endif /* SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE */
#ifdef SB_USE_CLASS_TELZIPARCHIVEEXTRADATA
	this->_Inst_ArchiveExtraData = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEEXTRADATA */
}

TElZipProcessor::TElZipProcessor(TElZipProcessorHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElZipProcessor::TElZipProcessor() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipProcessor_Create(&_Handle));
}

TElZipProcessor::~TElZipProcessor()
{
#ifdef SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY
	delete this->_Inst_EndOfCentralDir;
	this->_Inst_EndOfCentralDir = NULL;
#endif /* SB_USE_CLASS_TELZIPENDOFCENTRALDIRECTORY */
#ifdef SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY
	delete this->_Inst_Zip64EndOfCentralDir;
	this->_Inst_Zip64EndOfCentralDir = NULL;
#endif /* SB_USE_CLASS_TELZIP64ENDOFCENTRALDIRECTORY */
#ifdef SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE
	delete this->_Inst_CentralDirectorySignature;
	this->_Inst_CentralDirectorySignature = NULL;
#endif /* SB_USE_CLASS_TELZIPCENTRALDIRECTORYSIGNATURE */
#ifdef SB_USE_CLASS_TELZIPARCHIVEEXTRADATA
	delete this->_Inst_ArchiveExtraData;
	this->_Inst_ArchiveExtraData = NULL;
#endif /* SB_USE_CLASS_TELZIPARCHIVEEXTRADATA */
}
#endif /* SB_USE_CLASS_TELZIPPROCESSOR */

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSION

SB_INLINE TElZipEntityExtensionHandle TElZipEntityExtension::CreateByType(uint32_t ExtensionType)
{
	TElZipEntityExtensionHandle OutResult;
	SBCheckError(TElZipEntityExtension_CreateByType(ExtensionType, &OutResult));
	return OutResult;
}

SB_INLINE TElZipEntityExtensionHandle TElZipEntityExtension::CreateByType_Inst(uint32_t ExtensionType)
{
	TElZipEntityExtensionHandle OutResult;
	SBCheckError(TElZipEntityExtension_CreateByType_1(_Handle, ExtensionType, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityExtension::AssignTo(TElZipEntityExtension &Dest)
{
	SBCheckError(TElZipEntityExtension_AssignTo(_Handle, Dest.getHandle()));
}

SB_INLINE void TElZipEntityExtension::AssignTo(TElZipEntityExtension *Dest)
{
	SBCheckError(TElZipEntityExtension_AssignTo(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1192335644, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElZipEntityExtension::get_BodySize()
{
	int32_t OutResult;
	SBCheckError(TElZipEntityExtension_get_BodySize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElZipEntityExtension::get_ExtensionType()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityExtension_get_ExtensionType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityExtension::set_ExtensionType(uint32_t Value)
{
	SBCheckError(TElZipEntityExtension_set_ExtensionType(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
TElZipEntityExtensions* TElZipEntityExtension::get_Owner()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElZipEntityExtension_get_Owner(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Owner)
		this->_Inst_Owner = new TElZipEntityExtensions(hOutResult, ohFalse);
	else
		this->_Inst_Owner->updateHandle(hOutResult);
	return this->_Inst_Owner;
}

SB_INLINE void TElZipEntityExtension::set_Owner(TElZipEntityExtensions &Value)
{
	SBCheckError(TElZipEntityExtension_set_Owner(_Handle, Value.getHandle()));
}

SB_INLINE void TElZipEntityExtension::set_Owner(TElZipEntityExtensions *Value)
{
	SBCheckError(TElZipEntityExtension_set_Owner(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */

void TElZipEntityExtension::initInstances()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}

TElZipEntityExtension::TElZipEntityExtension(TElZipEntityExtensionHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

TElZipEntityExtension::TElZipEntityExtension() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElZipEntityExtension_Create(&_Handle));
}

TElZipEntityExtension::~TElZipEntityExtension()
{
#ifdef SB_USE_CLASS_TELZIPENTITYEXTENSIONS
	delete this->_Inst_Owner;
	this->_Inst_Owner = NULL;
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSIONS */
}
#endif /* SB_USE_CLASS_TELZIPENTITYEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYCUSTOMEXTENSION

SB_INLINE void TElZipEntityCustomExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityCustomExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityCustomExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityCustomExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityCustomExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityCustomExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityCustomExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityCustomExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1197495497, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

void TElZipEntityCustomExtension::get_ExtensionData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntityCustomExtension_get_ExtensionData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2051315642, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntityCustomExtension::set_ExtensionData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntityCustomExtension_set_ExtensionData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipEntityCustomExtension::TElZipEntityCustomExtension(TElZipEntityCustomExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityCustomExtension::TElZipEntityCustomExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityCustomExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYCUSTOMEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION

SB_INLINE void TElZipEntityZip64InfoExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityZip64InfoExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityZip64InfoExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityZip64InfoExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityZip64InfoExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityZip64InfoExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityZip64InfoExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityZip64InfoExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-40110327, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElZipEntityZip64InfoExtension::get_OriginalSize()
{
	int64_t OutResult;
	SBCheckError(TElZipEntityZip64InfoExtension_get_OriginalSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityZip64InfoExtension::set_OriginalSize(int64_t Value)
{
	SBCheckError(TElZipEntityZip64InfoExtension_set_OriginalSize(_Handle, Value));
}

bool TElZipEntityZip64InfoExtension::get_OriginalSizeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityZip64InfoExtension_get_OriginalSizeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElZipEntityZip64InfoExtension::get_CompressedSize()
{
	int64_t OutResult;
	SBCheckError(TElZipEntityZip64InfoExtension_get_CompressedSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityZip64InfoExtension::set_CompressedSize(int64_t Value)
{
	SBCheckError(TElZipEntityZip64InfoExtension_set_CompressedSize(_Handle, Value));
}

bool TElZipEntityZip64InfoExtension::get_CompressedSizeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityZip64InfoExtension_get_CompressedSizeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int64_t TElZipEntityZip64InfoExtension::get_RelativeHeaderOffset()
{
	int64_t OutResult;
	SBCheckError(TElZipEntityZip64InfoExtension_get_RelativeHeaderOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityZip64InfoExtension::set_RelativeHeaderOffset(int64_t Value)
{
	SBCheckError(TElZipEntityZip64InfoExtension_set_RelativeHeaderOffset(_Handle, Value));
}

bool TElZipEntityZip64InfoExtension::get_RelativeHeaderOffsetAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityZip64InfoExtension_get_RelativeHeaderOffsetAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntityZip64InfoExtension::get_DiskStart()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityZip64InfoExtension_get_DiskStart(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityZip64InfoExtension::set_DiskStart(uint32_t Value)
{
	SBCheckError(TElZipEntityZip64InfoExtension_set_DiskStart(_Handle, Value));
}

bool TElZipEntityZip64InfoExtension::get_DiskStartAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityZip64InfoExtension_get_DiskStartAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElZipEntityZip64InfoExtension::TElZipEntityZip64InfoExtension(TElZipEntityZip64InfoExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityZip64InfoExtension::TElZipEntityZip64InfoExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityZip64InfoExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYZIP64INFOEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION

SB_INLINE void TElZipEntityStrongEncryptionExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityStrongEncryptionExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityStrongEncryptionExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(877026828, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_Format()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_Format(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_Format(uint32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_Format(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_AlgorithmID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_AlgorithmID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_AlgorithmID(uint32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_AlgorithmID(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_KeyLength()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_KeyLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_KeyLength(uint32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_KeyLength(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_Flags()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_Flags(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_Flags(uint32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_Flags(_Handle, Value));
}

SB_INLINE int32_t TElZipEntityStrongEncryptionExtension::get_RecipientCount()
{
	int32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_RecipientCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_RecipientCount(int32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_RecipientCount(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_HashAlgorithmID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_HashAlgorithmID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_HashAlgorithmID(uint32_t Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_HashAlgorithmID(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityStrongEncryptionExtension::get_HashSize()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityStrongEncryptionExtension_get_HashSize(_Handle, &OutResult));
	return OutResult;
}

void TElZipEntityStrongEncryptionExtension::get_RecipientHashes(int32_t Index, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntityStrongEncryptionExtension_get_RecipientHashes(_Handle, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1946597905, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntityStrongEncryptionExtension::set_RecipientHashes(int32_t Index, const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_set_RecipientHashes(_Handle, Index, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipEntityStrongEncryptionExtension::TElZipEntityStrongEncryptionExtension(TElZipEntityStrongEncryptionExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityStrongEncryptionExtension::TElZipEntityStrongEncryptionExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityStrongEncryptionExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYSTRONGENCRYPTIONEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION

SB_INLINE void TElZipEntityWinZipAESExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityWinZipAESExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityWinZipAESExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityWinZipAESExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityWinZipAESExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityWinZipAESExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityWinZipAESExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityWinZipAESExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(1430637885, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntityWinZipAESExtension::get_Version()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityWinZipAESExtension_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityWinZipAESExtension::set_Version(uint32_t Value)
{
	SBCheckError(TElZipEntityWinZipAESExtension_set_Version(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityWinZipAESExtension::get_Vendor()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityWinZipAESExtension_get_Vendor(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityWinZipAESExtension::set_Vendor(uint32_t Value)
{
	SBCheckError(TElZipEntityWinZipAESExtension_set_Vendor(_Handle, Value));
}

SB_INLINE uint8_t TElZipEntityWinZipAESExtension::get_KeyStrength()
{
	uint8_t OutResult;
	SBCheckError(TElZipEntityWinZipAESExtension_get_KeyStrength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityWinZipAESExtension::set_KeyStrength(uint8_t Value)
{
	SBCheckError(TElZipEntityWinZipAESExtension_set_KeyStrength(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityWinZipAESExtension::get_ActualCompressionMethod()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityWinZipAESExtension_get_ActualCompressionMethod(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityWinZipAESExtension::set_ActualCompressionMethod(uint32_t Value)
{
	SBCheckError(TElZipEntityWinZipAESExtension_set_ActualCompressionMethod(_Handle, Value));
}

TElZipEntityWinZipAESExtension::TElZipEntityWinZipAESExtension(TElZipEntityWinZipAESExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityWinZipAESExtension::TElZipEntityWinZipAESExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityWinZipAESExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYWINZIPAESEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION

SB_INLINE void TElZipEntityCertificateStoreExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityCertificateStoreExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityCertificateStoreExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityCertificateStoreExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityCertificateStoreExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityCertificateStoreExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityCertificateStoreExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityCertificateStoreExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-480400654, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntityCertificateStoreExtension::get_Version()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityCertificateStoreExtension_get_Version(_Handle, &OutResult));
	return OutResult;
}

void TElZipEntityCertificateStoreExtension::get_StoreData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntityCertificateStoreExtension_get_StoreData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(628867747, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntityCertificateStoreExtension::set_StoreData(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntityCertificateStoreExtension_set_StoreData(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipEntityCertificateStoreExtension::TElZipEntityCertificateStoreExtension(TElZipEntityCertificateStoreExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityCertificateStoreExtension::TElZipEntityCertificateStoreExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityCertificateStoreExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYCERTIFICATESTOREEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION

SB_INLINE void TElZipEntitySignatureExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntitySignatureExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntitySignatureExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntitySignatureExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntitySignatureExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntitySignatureExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntitySignatureExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntitySignatureExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(2011885204, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntitySignatureExtension::get_Version()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntitySignatureExtension_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElZipEntitySignatureExtension::get_HashAlgorithm()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntitySignatureExtension_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntitySignatureExtension::set_HashAlgorithm(uint32_t Value)
{
	SBCheckError(TElZipEntitySignatureExtension_set_HashAlgorithm(_Handle, Value));
}

void TElZipEntitySignatureExtension::get_IssuerName(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntitySignatureExtension_get_IssuerName(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1705639200, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntitySignatureExtension::set_IssuerName(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntitySignatureExtension_set_IssuerName(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipEntitySignatureExtension::get_SerialNumber(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntitySignatureExtension_get_SerialNumber(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(808425604, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntitySignatureExtension::set_SerialNumber(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntitySignatureExtension_set_SerialNumber(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElZipEntitySignatureExtension::get_Signature(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElZipEntitySignatureExtension_get_Signature(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1346749344, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElZipEntitySignatureExtension::set_Signature(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElZipEntitySignatureExtension_set_Signature(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElZipEntitySignatureExtension::TElZipEntitySignatureExtension(TElZipEntitySignatureExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntitySignatureExtension::TElZipEntitySignatureExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntitySignatureExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYSIGNATUREEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION

SB_INLINE void TElZipEntityCentralDirSignatureExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityCentralDirSignatureExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityCentralDirSignatureExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityCentralDirSignatureExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

TElZipEntityCentralDirSignatureExtension::TElZipEntityCentralDirSignatureExtension(TElZipEntityCentralDirSignatureExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntitySignatureExtension(handle, ownHandle)
{
}

TElZipEntityCentralDirSignatureExtension::TElZipEntityCentralDirSignatureExtension() : TElZipEntitySignatureExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityCentralDirSignatureExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYCENTRALDIRSIGNATUREEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION

SB_INLINE void TElZipEntityUnix1Extension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityUnix1Extension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityUnix1Extension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityUnix1Extension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityUnix1Extension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityUnix1Extension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityUnix1Extension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityUnix1Extension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(412875712, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint32_t TElZipEntityUnix1Extension::get_ModifyTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix1Extension_get_ModifyTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix1Extension::set_ModifyTime(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix1Extension_set_ModifyTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityUnix1Extension::get_AccessTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix1Extension_get_AccessTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix1Extension::set_AccessTime(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix1Extension_set_AccessTime(_Handle, Value));
}

bool TElZipEntityUnix1Extension::get_UIDAndGIDAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityUnix1Extension_get_UIDAndGIDAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityUnix1Extension::set_UIDAndGIDAvailable(bool Value)
{
	SBCheckError(TElZipEntityUnix1Extension_set_UIDAndGIDAvailable(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipEntityUnix1Extension::get_UID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix1Extension_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix1Extension::set_UID(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix1Extension_set_UID(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityUnix1Extension::get_GID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix1Extension_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix1Extension::set_GID(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix1Extension_set_GID(_Handle, Value));
}

TElZipEntityUnix1Extension::TElZipEntityUnix1Extension(TElZipEntityUnix1ExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityUnix1Extension::TElZipEntityUnix1Extension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityUnix1Extension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYUNIX1EXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION

SB_INLINE void TElZipEntityUnix2Extension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityUnix2Extension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityUnix2Extension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityUnix2Extension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityUnix2Extension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityUnix2Extension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityUnix2Extension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityUnix2Extension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1998106057, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

bool TElZipEntityUnix2Extension::get_UIDAndGIDAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityUnix2Extension_get_UIDAndGIDAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityUnix2Extension::set_UIDAndGIDAvailable(bool Value)
{
	SBCheckError(TElZipEntityUnix2Extension_set_UIDAndGIDAvailable(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipEntityUnix2Extension::get_UID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix2Extension_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix2Extension::set_UID(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix2Extension_set_UID(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityUnix2Extension::get_GID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUnix2Extension_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUnix2Extension::set_GID(uint32_t Value)
{
	SBCheckError(TElZipEntityUnix2Extension_set_GID(_Handle, Value));
}

TElZipEntityUnix2Extension::TElZipEntityUnix2Extension(TElZipEntityUnix2ExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityUnix2Extension::TElZipEntityUnix2Extension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityUnix2Extension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYUNIX2EXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION

SB_INLINE void TElZipEntityExtendedTimestampExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityExtendedTimestampExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityExtendedTimestampExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1170652717, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

bool TElZipEntityExtendedTimestampExtension::get_ModifyTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_ModifyTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_ModifyTimeAvailable(bool Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_ModifyTimeAvailable(_Handle, (int8_t)Value));
}

bool TElZipEntityExtendedTimestampExtension::get_AccessTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_AccessTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_AccessTimeAvailable(bool Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_AccessTimeAvailable(_Handle, (int8_t)Value));
}

bool TElZipEntityExtendedTimestampExtension::get_CreateTimeAvailable()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_CreateTimeAvailable(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_CreateTimeAvailable(bool Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_CreateTimeAvailable(_Handle, (int8_t)Value));
}

SB_INLINE uint32_t TElZipEntityExtendedTimestampExtension::get_ModifyTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_ModifyTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_ModifyTime(uint32_t Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_ModifyTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityExtendedTimestampExtension::get_AccessTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_AccessTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_AccessTime(uint32_t Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_AccessTime(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityExtendedTimestampExtension::get_CreateTime()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_CreateTime(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityExtendedTimestampExtension::set_CreateTime(uint32_t Value)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_set_CreateTime(_Handle, Value));
}

bool TElZipEntityExtendedTimestampExtension::get_CentralHeader()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElZipEntityExtendedTimestampExtension_get_CentralHeader(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElZipEntityExtendedTimestampExtension::TElZipEntityExtendedTimestampExtension(TElZipEntityExtendedTimestampExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityExtendedTimestampExtension::TElZipEntityExtendedTimestampExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityExtendedTimestampExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYEXTENDEDTIMESTAMPEXTENSION */

#ifdef SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION

SB_INLINE void TElZipEntityUIDAndGIDExtension::Assign(TElZipEntityExtension &Source)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElZipEntityUIDAndGIDExtension::Assign(TElZipEntityExtension *Source)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElZipEntityUIDAndGIDExtension::LoadFromBuffer(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_LoadFromBuffer(_Handle, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

bool TElZipEntityUIDAndGIDExtension::SaveToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int32_t &Size)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = TElZipEntityUIDAndGIDExtension_SaveToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, &Size, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1966902770, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElZipEntityUIDAndGIDExtension::get_Version()
{
	uint8_t OutResult;
	SBCheckError(TElZipEntityUIDAndGIDExtension_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t TElZipEntityUIDAndGIDExtension::get_UID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUIDAndGIDExtension_get_UID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUIDAndGIDExtension::set_UID(uint32_t Value)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_set_UID(_Handle, Value));
}

SB_INLINE uint32_t TElZipEntityUIDAndGIDExtension::get_GID()
{
	uint32_t OutResult;
	SBCheckError(TElZipEntityUIDAndGIDExtension_get_GID(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElZipEntityUIDAndGIDExtension::set_GID(uint32_t Value)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_set_GID(_Handle, Value));
}

TElZipEntityUIDAndGIDExtension::TElZipEntityUIDAndGIDExtension(TElZipEntityUIDAndGIDExtensionHandle handle, TElOwnHandle ownHandle) : TElZipEntityExtension(handle, ownHandle)
{
}

TElZipEntityUIDAndGIDExtension::TElZipEntityUIDAndGIDExtension() : TElZipEntityExtension(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElZipEntityUIDAndGIDExtension_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELZIPENTITYUIDANDGIDEXTENSION */

};	/* namespace SecureBlackbox */

