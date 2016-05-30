#include "sbfiledatastorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELFILEDATASTORAGEOBJECT

SB_INLINE void TElFileDataStorageObject::Assign(TElCustomDataStorageObject &Source)
{
	SBCheckError(TElFileDataStorageObject_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TElFileDataStorageObject::Assign(TElCustomDataStorageObject *Source)
{
	SBCheckError(TElFileDataStorageObject_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElCustomDataStorageObjectHandle TElFileDataStorageObject::Clone()
{
	TElCustomDataStorageObjectHandle OutResult;
	SBCheckError(TElFileDataStorageObject_Clone(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElFileDataStorageObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElFileDataStorageObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElFileDataStorageObject::get_ModificationTime()
{
	int64_t OutResult;
	SBCheckError(TElFileDataStorageObject_get_ModificationTime(_Handle, &OutResult));
	return OutResult;
}

void TElFileDataStorageObject::get_ETag(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElFileDataStorageObject_get_ETag(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1554210822, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElFileDataStorageObject::TElFileDataStorageObject(TElFileDataStorageObjectHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorageObject(handle, ownHandle)
{
}

TElFileDataStorageObject::TElFileDataStorageObject() : TElCustomDataStorageObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileDataStorageObject_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELFILEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELFILEDATASTORAGE

#ifdef SB_USE_CLASS_TELFILEDATASTORAGEOBJECT
SB_INLINE TElFileDataStorageObjectHandle TElFileDataStorage::AcquireObject(const std::string &ObjName)
{
	TElFileDataStorageObjectHandle OutResult;
	SBCheckError(TElFileDataStorage_AcquireObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELFILEDATASTORAGEOBJECT */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, const std::string &Data, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), Data.data(), (int32_t)Data.length(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, const std::string &Data, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), Data.data(), (int32_t)Data.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_2(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler, std::vector<uint8_t> &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.size();
	uint32_t _err = TElFileDataStorage_WriteObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), Handler.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(NewETag), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnBuffer(-1125844992, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(NewETag), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}

void TElFileDataStorage::WriteObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler, std::vector<uint8_t> &NewETag)
{
	int32_t szNewETag = (int32_t)NewETag.size();
	uint32_t _err = TElFileDataStorage_WriteObject_3(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(NewETag), &szNewETag);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		NewETag.resize(szNewETag);
		SBCheckError(SBGetLastReturnBuffer(-1125844992, 5, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(NewETag), &szNewETag));
	}
	else
		SBCheckError(_err);

	NewETag.resize(szNewETag);
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElFileDataStorage::WriteObject(TElFileDataStorageObject &Obj, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_4(_Handle, Obj.getHandle(), Strm.getHandle(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::WriteObject(TElFileDataStorageObject *Obj, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_4(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElFileDataStorage::WriteObject(TElFileDataStorageObject &Obj, TStream &Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_5(_Handle, Obj.getHandle(), Strm.getHandle(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::WriteObject(TElFileDataStorageObject *Obj, TStream *Strm, const std::vector<uint8_t> &ETag, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_WriteObject_5(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM
SB_INLINE void TElFileDataStorage::WriteBlock(const std::string &ObjName, TStream &Strm, TElCustomDataStorageSecurityHandler &Handler, int64_t Offset, int64_t &Written)
{
	SBCheckError(TElFileDataStorage_WriteBlock(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle(), Handler.getHandle(), Offset, &Written));
}

SB_INLINE void TElFileDataStorage::WriteBlock(const std::string &ObjName, TStream *Strm, TElCustomDataStorageSecurityHandler *Handler, int64_t Offset, int64_t &Written)
{
	SBCheckError(TElFileDataStorage_WriteBlock(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE, Offset, &Written));
}
#endif /* SB_USE_CLASSES_TELCUSTOMDATASTORAGESECURITYHANDLER_AND_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFileDataStorage::ReadObject(const std::string &ObjName, TStream &Strm)
{
	SBCheckError(TElFileDataStorage_ReadObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle()));
}

SB_INLINE void TElFileDataStorage::ReadObject(const std::string &ObjName, TStream *Strm)
{
	SBCheckError(TElFileDataStorage_ReadObject(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElFileDataStorage::ReadObject(const std::string &ObjName, TStream &Strm, const std::vector<uint8_t> &ETag)
{
	SBCheckError(TElFileDataStorage_ReadObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), Strm.getHandle(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size()));
}

SB_INLINE void TElFileDataStorage::ReadObject(const std::string &ObjName, TStream *Strm, const std::vector<uint8_t> &ETag)
{
	SBCheckError(TElFileDataStorage_ReadObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size()));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElFileDataStorage::ReadObject(TElFileDataStorageObject &Obj, TStream &Strm)
{
	SBCheckError(TElFileDataStorage_ReadObject_2(_Handle, Obj.getHandle(), Strm.getHandle()));
}

SB_INLINE void TElFileDataStorage::ReadObject(TElFileDataStorageObject *Obj, TStream *Strm)
{
	SBCheckError(TElFileDataStorage_ReadObject_2(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM
SB_INLINE void TElFileDataStorage::ReadObject(TElFileDataStorageObject &Obj, TStream &Strm, const std::vector<uint8_t> &ETag)
{
	SBCheckError(TElFileDataStorage_ReadObject_3(_Handle, Obj.getHandle(), Strm.getHandle(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size()));
}

SB_INLINE void TElFileDataStorage::ReadObject(TElFileDataStorageObject *Obj, TStream *Strm, const std::vector<uint8_t> &ETag)
{
	SBCheckError(TElFileDataStorage_ReadObject_3(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size()));
}
#endif /* SB_USE_CLASSES_TELFILEDATASTORAGEOBJECT_AND_TSTREAM */

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE void TElFileDataStorage::CopyObject(const std::string &SrcObjName, const std::string &DestObjName, TElCustomDataStorageSecurityHandler &Handler)
{
	SBCheckError(TElFileDataStorage_CopyObject(_Handle, SrcObjName.data(), (int32_t)SrcObjName.length(), DestObjName.data(), (int32_t)DestObjName.length(), Handler.getHandle()));
}

SB_INLINE void TElFileDataStorage::CopyObject(const std::string &SrcObjName, const std::string &DestObjName, TElCustomDataStorageSecurityHandler *Handler)
{
	SBCheckError(TElFileDataStorage_CopyObject(_Handle, SrcObjName.data(), (int32_t)SrcObjName.length(), DestObjName.data(), (int32_t)DestObjName.length(), (Handler != NULL) ? Handler->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

SB_INLINE void TElFileDataStorage::DeleteObject(const std::string &ObjName)
{
	SBCheckError(TElFileDataStorage_DeleteObject(_Handle, ObjName.data(), (int32_t)ObjName.length()));
}

SB_INLINE void TElFileDataStorage::DeleteObject(const std::string &ObjName, const std::vector<uint8_t> &ETag)
{
	SBCheckError(TElFileDataStorage_DeleteObject_1(_Handle, ObjName.data(), (int32_t)ObjName.length(), SB_STD_VECTOR_FRONT_ADR(ETag), (int32_t)ETag.size()));
}

bool TElFileDataStorage::ObjectExists(const std::string &ObjName)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileDataStorage_ObjectExists(_Handle, ObjName.data(), (int32_t)ObjName.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER
SB_INLINE TElCustomDataStorageSecurityHandlerHandle TElFileDataStorage::GetProtectionInfo(const std::string &ObjName)
{
	TElCustomDataStorageSecurityHandlerHandle OutResult;
	SBCheckError(TElFileDataStorage_GetProtectionInfo(_Handle, ObjName.data(), (int32_t)ObjName.length(), &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELCUSTOMDATASTORAGESECURITYHANDLER */

void TElFileDataStorage::get_DataFileExtension(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFileDataStorage_get_DataFileExtension(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1946407155, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFileDataStorage::set_DataFileExtension(const std::string &Value)
{
	SBCheckError(TElFileDataStorage_set_DataFileExtension(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElFileDataStorage::get_Directory(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFileDataStorage_get_Directory(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(197147386, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFileDataStorage::set_Directory(const std::string &Value)
{
	SBCheckError(TElFileDataStorage_set_Directory(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElFileDataStorage::get_EmbeddedMetadataMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileDataStorage_get_EmbeddedMetadataMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFileDataStorage::set_EmbeddedMetadataMode(bool Value)
{
	SBCheckError(TElFileDataStorage_set_EmbeddedMetadataMode(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
TElCustomFileSystemAdapter* TElFileDataStorage::get_FileSystemAdapter()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElFileDataStorage_get_FileSystemAdapter(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FileSystemAdapter)
		this->_Inst_FileSystemAdapter = new TElCustomFileSystemAdapter(hOutResult, ohFalse);
	else
		this->_Inst_FileSystemAdapter->updateHandle(hOutResult);
	return this->_Inst_FileSystemAdapter;
}

SB_INLINE void TElFileDataStorage::set_FileSystemAdapter(TElCustomFileSystemAdapter &Value)
{
	SBCheckError(TElFileDataStorage_set_FileSystemAdapter(_Handle, Value.getHandle()));
}

SB_INLINE void TElFileDataStorage::set_FileSystemAdapter(TElCustomFileSystemAdapter *Value)
{
	SBCheckError(TElFileDataStorage_set_FileSystemAdapter(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */

void TElFileDataStorage::get_MedataFileExtension(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElFileDataStorage_get_MedataFileExtension(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(84739464, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElFileDataStorage::set_MedataFileExtension(const std::string &Value)
{
	SBCheckError(TElFileDataStorage_set_MedataFileExtension(_Handle, Value.data(), (int32_t)Value.length()));
}

bool TElFileDataStorage::get_Overwrite()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileDataStorage_get_Overwrite(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFileDataStorage::set_Overwrite(bool Value)
{
	SBCheckError(TElFileDataStorage_set_Overwrite(_Handle, (int8_t)Value));
}

bool TElFileDataStorage::get_PassthroughMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileDataStorage_get_PassthroughMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFileDataStorage::set_PassthroughMode(bool Value)
{
	SBCheckError(TElFileDataStorage_set_PassthroughMode(_Handle, (int8_t)Value));
}

void TElFileDataStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}

TElFileDataStorage::TElFileDataStorage(TElFileDataStorageHandle handle, TElOwnHandle ownHandle) : TElCustomDataStorage(handle, ownHandle)
{
	initInstances();
}

TElFileDataStorage::TElFileDataStorage(TComponent &AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFileDataStorage_Create(AOwner.getHandle(), &_Handle));
}

TElFileDataStorage::TElFileDataStorage(TComponent *AOwner) : TElCustomDataStorage(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElFileDataStorage_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElFileDataStorage::~TElFileDataStorage()
{
#ifdef SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER
	delete this->_Inst_FileSystemAdapter;
	this->_Inst_FileSystemAdapter = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMFILESYSTEMADAPTER */
}
#endif /* SB_USE_CLASS_TELFILEDATASTORAGE */

#ifdef SB_USE_GLOBAL_PROCS_FILEDATASTORAGE

void ComposeETag(int64_t ModTime, int64_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBFileDataStorage_ComposeETag(ModTime, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1441170903, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_FILEDATASTORAGE */

};	/* namespace SecureBlackbox */

