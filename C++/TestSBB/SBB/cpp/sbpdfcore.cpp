#include "sbpdfcore.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPDFOBJECT

SB_INLINE TElPDFObjectHandle TElPDFObject::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFObject_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFObject::Write(TStream &s, bool Assemble)
{
	SBCheckError(TElPDFObject_Write(_Handle, s.getHandle(), (int8_t)Assemble));
}

SB_INLINE void TElPDFObject::Write(TStream *s, bool Assemble)
{
	SBCheckError(TElPDFObject_Write(_Handle, (s != NULL) ? s->getHandle() : SB_NULL_HANDLE, (int8_t)Assemble));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElPDFObject::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFObject_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1737708713, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFObject::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFObject_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFObject::get_After(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFObject_get_After(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2059913761, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFObject::set_After(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFObject_set_After(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFObject::get_Between(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFObject_get_Between(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(296474085, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFObject::set_Between(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFObject_set_Between(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElPDFObject::get_TypeErr()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFObject_get_TypeErr(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElPDFObject* TElPDFObject::get_Parent()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFObject_get_Parent(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Parent)
		this->_Inst_Parent = new TElPDFObject(hOutResult, ohFalse);
	else
		this->_Inst_Parent->updateHandle(hOutResult);
	return this->_Inst_Parent;
}

SB_INLINE int64_t TElPDFObject::get_Offset()
{
	int64_t OutResult;
	SBCheckError(TElPDFObject_get_Offset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPDFObject::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElPDFObject_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPDFObject::get_OrigOffset()
{
	int64_t OutResult;
	SBCheckError(TElPDFObject_get_OrigOffset(_Handle, &OutResult));
	return OutResult;
}

TObject* TElPDFObject::get_Tag()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFObject_get_Tag(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Tag)
		this->_Inst_Tag = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Tag->updateHandle(hOutResult);
	return this->_Inst_Tag;
}

SB_INLINE void TElPDFObject::set_Tag(TObject &Value)
{
	SBCheckError(TElPDFObject_set_Tag(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFObject::set_Tag(TObject *Value)
{
	SBCheckError(TElPDFObject_set_Tag(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

void TElPDFObject::initInstances()
{
	this->_Inst_Parent = NULL;
	this->_Inst_Tag = NULL;
}

TElPDFObject::TElPDFObject(TElPDFObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFObject::TElPDFObject(TElPDFFile &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFObject_Create(Owner.getHandle(), &_Handle));
}

TElPDFObject::TElPDFObject(TElPDFFile *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFObject_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFObject::~TElPDFObject()
{
	delete this->_Inst_Parent;
	this->_Inst_Parent = NULL;
	delete this->_Inst_Tag;
	this->_Inst_Tag = NULL;
}
#endif /* SB_USE_CLASS_TELPDFOBJECT */

#ifdef SB_USE_CLASS_TELPDFFILE

#ifdef SB_USE_CLASS_TELPDFOBJECT
SB_INLINE void TElPDFFile::Add(TElPDFObject &v)
{
	SBCheckError(TElPDFFile_Add(_Handle, v.getHandle()));
}

SB_INLINE void TElPDFFile::Add(TElPDFObject *v)
{
	SBCheckError(TElPDFFile_Add(_Handle, (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFOBJECT */

SB_INLINE void TElPDFFile::Clear(bool ADestroyOwnedObjects)
{
	SBCheckError(TElPDFFile_Clear(_Handle, (int8_t)ADestroyOwnedObjects));
}

SB_INLINE void TElPDFFile::Load()
{
	SBCheckError(TElPDFFile_Load(_Handle));
}

SB_INLINE void TElPDFFile::Save()
{
	SBCheckError(TElPDFFile_Save(_Handle));
}

#ifdef SB_USE_CLASS_TELPDFOBJECT
SB_INLINE int32_t TElPDFFile::GetRootObjectIndex(TElPDFObject &Obj)
{
	int32_t OutResult;
	SBCheckError(TElPDFFile_GetRootObjectIndex(_Handle, Obj.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFFile::GetRootObjectIndex(TElPDFObject *Obj)
{
	int32_t OutResult;
	SBCheckError(TElPDFFile_GetRootObjectIndex(_Handle, (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFOBJECT */

SB_INLINE int32_t TElPDFFile::GetLastObjectNum()
{
	int32_t OutResult;
	SBCheckError(TElPDFFile_GetLastObjectNum(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int64_t TElPDFFile::SearchForEOFOffset(TStream &f, int64_t LastPosition)
{
	int64_t OutResult;
	SBCheckError(TElPDFFile_SearchForEOFOffset(_Handle, f.getHandle(), LastPosition, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElPDFFile::SearchForEOFOffset(TStream *f, int64_t LastPosition)
{
	int64_t OutResult;
	SBCheckError(TElPDFFile_SearchForEOFOffset(_Handle, (f != NULL) ? f->getHandle() : SB_NULL_HANDLE, LastPosition, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFREF
SB_INLINE TElPDFRefHandle TElPDFFile::FindObj(int32_t ObjNumber, int32_t GenNumber)
{
	TElPDFRefHandle OutResult;
	SBCheckError(TElPDFFile_FindObj(_Handle, ObjNumber, GenNumber, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
SB_INLINE TElPDFXrefEntryHandle TElPDFFile::GetXRefEntry(int32_t ObjNumber, int32_t GenNumber)
{
	TElPDFXrefEntryHandle OutResult;
	SBCheckError(TElPDFFile_GetXRefEntry(_Handle, ObjNumber, GenNumber, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

#ifdef SB_USE_CLASS_TSTREAM
TStream* TElPDFFile::get_Stream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFFile_get_Stream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Stream)
		this->_Inst_Stream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_Stream->updateHandle(hOutResult);
	return this->_Inst_Stream;
}

SB_INLINE void TElPDFFile::set_Stream(TStream &Value)
{
	SBCheckError(TElPDFFile_set_Stream(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFFile::set_Stream(TStream *Value)
{
	SBCheckError(TElPDFFile_set_Stream(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELPDFARRAY
TElPDFArray* TElPDFFile::get_Root()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFFile_get_Root(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Root)
		this->_Inst_Root = new TElPDFArray(hOutResult, ohFalse);
	else
		this->_Inst_Root->updateHandle(hOutResult);
	return this->_Inst_Root;
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
TElPDFDictionary* TElPDFFile::get_Trailer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFFile_get_Trailer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trailer)
		this->_Inst_Trailer = new TElPDFDictionary(hOutResult, ohFalse);
	else
		this->_Inst_Trailer->updateHandle(hOutResult);
	return this->_Inst_Trailer;
}

SB_INLINE void TElPDFFile::set_Trailer(TElPDFDictionary &Value)
{
	SBCheckError(TElPDFFile_set_Trailer(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFFile::set_Trailer(TElPDFDictionary *Value)
{
	SBCheckError(TElPDFFile_set_Trailer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

SB_INLINE int32_t TElPDFFile::get_Version()
{
	int32_t OutResult;
	SBCheckError(TElPDFFile_get_Version(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFFile::set_Version(int32_t Value)
{
	SBCheckError(TElPDFFile_set_Version(_Handle, Value));
}

TPDFAssembleType TElPDFFile::get_AssembleType()
{
	TPDFAssembleTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_AssembleType(_Handle, &OutResultRaw));
	return (TPDFAssembleType)OutResultRaw;
}

SB_INLINE void TElPDFFile::set_AssembleType(TPDFAssembleType Value)
{
	SBCheckError(TElPDFFile_set_AssembleType(_Handle, (TPDFAssembleTypeRaw)Value));
}

bool TElPDFFile::get_PromptReassemble()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_PromptReassemble(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFFile::set_PromptReassemble(bool Value)
{
	SBCheckError(TElPDFFile_set_PromptReassemble(_Handle, (int8_t)Value));
}

bool TElPDFFile::get_XRefStreamsUsed()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_XRefStreamsUsed(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFFile::get_ContainsObjectStreams()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_ContainsObjectStreams(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPDFFile::get_SkipObjLoadingFromObjStream()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_SkipObjLoadingFromObjStream(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFFile::set_SkipObjLoadingFromObjStream(bool Value)
{
	SBCheckError(TElPDFFile_set_SkipObjLoadingFromObjStream(_Handle, (int8_t)Value));
}

bool TElPDFFile::get_Encrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFFile_get_Encrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPDFFile::get_NewLine(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFFile_get_NewLine(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1014153039, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFFile::set_NewLine(const std::string &Value)
{
	SBCheckError(TElPDFFile_set_NewLine(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE void TElPDFFile::get_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFFile_get_OnCreateTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFFile::set_OnCreateTemporaryStream(TSBPDFCreateTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFFile_set_OnCreateTemporaryStream(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFFile::get_OnProgress(TSBPDFProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFFile_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFFile::set_OnProgress(TSBPDFProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFFile_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPDFFile::get_OnDecryptStream(TSBPDFCallbackFunc &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPDFFile_get_OnDecryptStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPDFFile::set_OnDecryptStream(TSBPDFCallbackFunc pMethodValue, void * pDataValue)
{
	SBCheckError(TElPDFFile_set_OnDecryptStream(_Handle, pMethodValue, pDataValue));
}

void TElPDFFile::initInstances()
{
#ifdef SB_USE_CLASS_TSTREAM
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPDFARRAY
	this->_Inst_Root = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	this->_Inst_Trailer = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}

TElPDFFile::TElPDFFile(TElPDFFileHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TSTREAM
TElPDFFile::TElPDFFile(TStream &aStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFFile_Create(aStream.getHandle(), &_Handle));
}

TElPDFFile::TElPDFFile(TStream *aStream) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFFile_Create((aStream != NULL) ? aStream->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TSTREAM */

TElPDFFile::~TElPDFFile()
{
#ifdef SB_USE_CLASS_TSTREAM
	delete this->_Inst_Stream;
	this->_Inst_Stream = NULL;
#endif /* SB_USE_CLASS_TSTREAM */
#ifdef SB_USE_CLASS_TELPDFARRAY
	delete this->_Inst_Root;
	this->_Inst_Root = NULL;
#endif /* SB_USE_CLASS_TELPDFARRAY */
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	delete this->_Inst_Trailer;
	this->_Inst_Trailer = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#ifdef SB_USE_CLASS_TELPDFNULL

SB_INLINE TElPDFObjectHandle TElPDFNull::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFNull_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

TElPDFNull::TElPDFNull(TElPDFNullHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFNull::TElPDFNull(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFNull_Create(Owner.getHandle(), &_Handle));
}

TElPDFNull::TElPDFNull(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFNull_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFNULL */

#ifdef SB_USE_CLASS_TELPDFBOOLEAN

SB_INLINE TElPDFObjectHandle TElPDFBoolean::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFBoolean_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

bool TElPDFBoolean::get_Bool()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFBoolean_get_Bool(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFBoolean::set_Bool(bool Value)
{
	SBCheckError(TElPDFBoolean_set_Bool(_Handle, (int8_t)Value));
}

TElPDFBoolean::TElPDFBoolean(TElPDFBooleanHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFBoolean::TElPDFBoolean(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFBoolean_Create(Owner.getHandle(), &_Handle));
}

TElPDFBoolean::TElPDFBoolean(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFBoolean_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFBOOLEAN */

#ifdef SB_USE_CLASS_TELPDFREAL

SB_INLINE TElPDFObjectHandle TElPDFReal::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFReal_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE double TElPDFReal::get_RealValue()
{
	double OutResult;
	SBCheckError(TElPDFReal_get_RealValue(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFReal::set_RealValue(double Value)
{
	SBCheckError(TElPDFReal_set_RealValue(_Handle, Value));
}

SB_INLINE int32_t TElPDFReal::get_IntValue()
{
	int32_t OutResult;
	SBCheckError(TElPDFReal_get_IntValue(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFReal::set_IntValue(int32_t Value)
{
	SBCheckError(TElPDFReal_set_IntValue(_Handle, Value));
}

bool TElPDFReal::get_IsInt()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFReal_get_IsInt(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

TElPDFReal::TElPDFReal(TElPDFRealHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFReal::TElPDFReal(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFReal_Create(Owner.getHandle(), &_Handle));
}

TElPDFReal::TElPDFReal(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFReal_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFREAL */

#ifdef SB_USE_CLASS_TELPDFSTRING

SB_INLINE TElPDFObjectHandle TElPDFString::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFString_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

void TElPDFString::get_Str(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFString_get_Str(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1093416304, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFString::set_Str(const std::string &Value)
{
	SBCheckError(TElPDFString_set_Str(_Handle, Value.data(), (int32_t)Value.length()));
}

void TElPDFString::get_OrigStr(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFString_get_OrigStr(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(758242762, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFString::set_OrigStr(const std::string &Value)
{
	SBCheckError(TElPDFString_set_OrigStr(_Handle, Value.data(), (int32_t)Value.length()));
}

TPDFStringEncoding TElPDFString::get_Encoding()
{
	TPDFStringEncodingRaw OutResultRaw = 0;
	SBCheckError(TElPDFString_get_Encoding(_Handle, &OutResultRaw));
	return (TPDFStringEncoding)OutResultRaw;
}

SB_INLINE void TElPDFString::set_Encoding(TPDFStringEncoding Value)
{
	SBCheckError(TElPDFString_set_Encoding(_Handle, (TPDFStringEncodingRaw)Value));
}

TElPDFString::TElPDFString(TElPDFStringHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFString::TElPDFString(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFString_Create(Owner.getHandle(), &_Handle));
}

TElPDFString::TElPDFString(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFString_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFSTRING */

#ifdef SB_USE_CLASS_TELPDFCOMMENT

SB_INLINE TElPDFObjectHandle TElPDFComment::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFComment_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

void TElPDFComment::get_Comment(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFComment_get_Comment(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1843861475, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFComment::set_Comment(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFComment_set_Comment(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPDFComment::TElPDFComment(TElPDFCommentHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFComment::TElPDFComment(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFComment_Create(Owner.getHandle(), &_Handle));
}

TElPDFComment::TElPDFComment(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFComment_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFCOMMENT */

#ifdef SB_USE_CLASS_TELPDFNAME

SB_INLINE TElPDFObjectHandle TElPDFName::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFName_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

void TElPDFName::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFName_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(79070548, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFName::set_Name(const std::string &Value)
{
	SBCheckError(TElPDFName_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

TElPDFName::TElPDFName(TElPDFNameHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFName::TElPDFName(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFName_Create(Owner.getHandle(), &_Handle));
}

TElPDFName::TElPDFName(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFName_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFNAME */

#ifdef SB_USE_CLASS_TELPDFCPXOBJ

void TElPDFCpxObj::get_Before(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFCpxObj_get_Before(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(2028947625, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFCpxObj::set_Before(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFCpxObj_set_Before(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

TElPDFCpxObj::TElPDFCpxObj(TElPDFCpxObjHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFCpxObj::TElPDFCpxObj(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCpxObj_Create(Owner.getHandle(), &_Handle));
}

TElPDFCpxObj::TElPDFCpxObj(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFCpxObj_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFCPXOBJ */

#ifdef SB_USE_CLASS_TELPDFARRAY

SB_INLINE TElPDFObjectHandle TElPDFArray::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFArray_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFArray::Add(TElPDFObject &v)
{
	SBCheckError(TElPDFArray_Add(_Handle, v.getHandle()));
}

SB_INLINE void TElPDFArray::Add(TElPDFObject *v)
{
	SBCheckError(TElPDFArray_Add(_Handle, (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFArray::Insert(TElPDFObject &v, int32_t Position)
{
	SBCheckError(TElPDFArray_Insert(_Handle, v.getHandle(), Position));
}

SB_INLINE void TElPDFArray::Insert(TElPDFObject *v, int32_t Position)
{
	SBCheckError(TElPDFArray_Insert(_Handle, (v != NULL) ? v->getHandle() : SB_NULL_HANDLE, Position));
}

SB_INLINE void TElPDFArray::Remove(TElPDFObject &v)
{
	SBCheckError(TElPDFArray_Remove(_Handle, v.getHandle()));
}

SB_INLINE void TElPDFArray::Remove(TElPDFObject *v)
{
	SBCheckError(TElPDFArray_Remove(_Handle, (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFArray::Clear()
{
	SBCheckError(TElPDFArray_Clear(_Handle));
}

TElPDFObject* TElPDFArray::get_Items(int64_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFArray_get_Items(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Items)
		this->_Inst_Items = new TElPDFObject(hOutResult, ohFalse);
	else
		this->_Inst_Items->updateHandle(hOutResult);
	return this->_Inst_Items;
}

SB_INLINE void TElPDFArray::set_Items(int64_t Index, TElPDFObject &v)
{
	SBCheckError(TElPDFArray_set_Items(_Handle, Index, v.getHandle()));
}

SB_INLINE void TElPDFArray::set_Items(int64_t Index, TElPDFObject *v)
{
	SBCheckError(TElPDFArray_set_Items(_Handle, Index, (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int64_t TElPDFArray::get_Count()
{
	int64_t OutResult;
	SBCheckError(TElPDFArray_get_Count(_Handle, &OutResult));
	return OutResult;
}

bool TElPDFArray::get_Render()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFArray_get_Render(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPDFArray::set_Render(bool Value)
{
	SBCheckError(TElPDFArray_set_Render(_Handle, (int8_t)Value));
}

void TElPDFArray::initInstances()
{
	this->_Inst_Items = NULL;
}

TElPDFArray::TElPDFArray(TElPDFArrayHandle handle, TElOwnHandle ownHandle) : TElPDFCpxObj(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFArray::TElPDFArray(TElPDFFile &Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFArray_Create(Owner.getHandle(), &_Handle));
}

TElPDFArray::TElPDFArray(TElPDFFile *Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFArray_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFArray::~TElPDFArray()
{
	delete this->_Inst_Items;
	this->_Inst_Items = NULL;
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY

SB_INLINE TElPDFObjectHandle TElPDFDictionary::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFDictionary_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFDictionary::Add(const std::vector<uint8_t> &Name, TElPDFObject &v)
{
	SBCheckError(TElPDFDictionary_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), v.getHandle()));
}

SB_INLINE void TElPDFDictionary::Add(const std::vector<uint8_t> &Name, TElPDFObject *v)
{
	SBCheckError(TElPDFDictionary_Add(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFDictionary::Add(const std::string &Name, TElPDFObject &v)
{
	SBCheckError(TElPDFDictionary_Add_1(_Handle, Name.data(), (int32_t)Name.length(), v.getHandle()));
}

SB_INLINE void TElPDFDictionary::Add(const std::string &Name, TElPDFObject *v)
{
	SBCheckError(TElPDFDictionary_Add_1(_Handle, Name.data(), (int32_t)Name.length(), (v != NULL) ? v->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE TElPDFObjectHandle TElPDFDictionary::GetItemByName(const std::vector<uint8_t> &Name)
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFDictionary_GetItemByName(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), &OutResult));
	return OutResult;
}

SB_INLINE TElPDFObjectHandle TElPDFDictionary::GetItemByName(const std::string &S)
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFDictionary_GetItemByName_1(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFDictionary::SetItemByName(const std::vector<uint8_t> &Name, TElPDFObject &Item)
{
	SBCheckError(TElPDFDictionary_SetItemByName(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), Item.getHandle()));
}

SB_INLINE void TElPDFDictionary::SetItemByName(const std::vector<uint8_t> &Name, TElPDFObject *Item)
{
	SBCheckError(TElPDFDictionary_SetItemByName(_Handle, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFDictionary::SetItemByName(const std::string &S, TElPDFObject &Item)
{
	SBCheckError(TElPDFDictionary_SetItemByName_1(_Handle, S.data(), (int32_t)S.length(), Item.getHandle()));
}

SB_INLINE void TElPDFDictionary::SetItemByName(const std::string &S, TElPDFObject *Item)
{
	SBCheckError(TElPDFDictionary_SetItemByName_1(_Handle, S.data(), (int32_t)S.length(), (Item != NULL) ? Item->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElPDFDictionary::AddString(const std::string &Name, const std::string &Data, TPDFStringEncoding Enc, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddString(_Handle, Name.data(), (int32_t)Name.length(), Data.data(), (int32_t)Data.length(), (TPDFStringEncodingRaw)Enc, (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::AddName(const std::string &Name, const std::string &Data, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddName(_Handle, Name.data(), (int32_t)Name.length(), Data.data(), (int32_t)Data.length(), (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::AddInt(const std::string &Name, int64_t Value, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddInt(_Handle, Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::AddBoolean(const std::string &Name, bool Value, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddBoolean(_Handle, Name.data(), (int32_t)Name.length(), (int8_t)Value, (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::AddReal(const std::string &Name, double Value, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddReal(_Handle, Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::AddRect(const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite)
{
	SBCheckError(TElPDFDictionary_AddRect(_Handle, Name.data(), (int32_t)Name.length(), X1, Y1, X2, Y2, (int8_t)Overwrite));
}

SB_INLINE void TElPDFDictionary::RemoveItemByName(const std::string &S)
{
	SBCheckError(TElPDFDictionary_RemoveItemByName(_Handle, S.data(), (int32_t)S.length()));
}

void TElPDFDictionary::get_Names(int64_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPDFDictionary_get_Names(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(780665126, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TElPDFDictionary::TElPDFDictionary(TElPDFDictionaryHandle handle, TElOwnHandle ownHandle) : TElPDFArray(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFDictionary::TElPDFDictionary(TElPDFFile &Owner) : TElPDFArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFDictionary_Create(Owner.getHandle(), &_Handle));
}

TElPDFDictionary::TElPDFDictionary(TElPDFFile *Owner) : TElPDFArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFDictionary_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFSTREAM

SB_INLINE TElPDFObjectHandle TElPDFStream::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFStream_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPDFStream::Write(TStream &s, bool Assemble)
{
	SBCheckError(TElPDFStream_Write(_Handle, s.getHandle(), (int8_t)Assemble));
}

SB_INLINE void TElPDFStream::Write(TStream *s, bool Assemble)
{
	SBCheckError(TElPDFStream_Write(_Handle, (s != NULL) ? s->getHandle() : SB_NULL_HANDLE, (int8_t)Assemble));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElPDFStream::get_Data(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFStream_get_Data(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1784188018, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFStream::set_Data(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFStream_set_Data(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElPDFStream::set_CR2(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFStream_set_CR2(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFStream::get_Stream(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFStream_get_Stream(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(575874293, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFStream::set_Stream(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFStream_set_Stream(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFStream::get_DecompressedStream(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFStream_get_DecompressedStream(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(561794007, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
TElPDFDictionary* TElPDFStream::get_Dict()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFStream_get_Dict(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Dict)
		this->_Inst_Dict = new TElPDFDictionary(hOutResult, ohFalse);
	else
		this->_Inst_Dict->updateHandle(hOutResult);
	return this->_Inst_Dict;
}

SB_INLINE void TElPDFStream::set_Dict(TElPDFDictionary &Value)
{
	SBCheckError(TElPDFStream_set_Dict(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFStream::set_Dict(TElPDFDictionary *Value)
{
	SBCheckError(TElPDFStream_set_Dict(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

void TElPDFStream::get_OrigStream(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPDFStream_get_OrigStream(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-700377368, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPDFStream::set_OrigStream(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPDFStream_set_OrigStream(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElPDFStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	this->_Inst_Dict = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}

TElPDFStream::TElPDFStream(TElPDFStreamHandle handle, TElOwnHandle ownHandle) : TElPDFCpxObj(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFStream::TElPDFStream(TElPDFFile &Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFStream_Create(Owner.getHandle(), &_Handle));
}

TElPDFStream::TElPDFStream(TElPDFFile *Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFStream_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFStream::~TElPDFStream()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	delete this->_Inst_Dict;
	this->_Inst_Dict = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}
#endif /* SB_USE_CLASS_TELPDFSTREAM */

#ifdef SB_USE_CLASS_TELPDFINDIRECT

SB_INLINE TElPDFObjectHandle TElPDFIndirect::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFIndirect_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFIndirect::XrefAdd()
{
	SBCheckError(TElPDFIndirect_XrefAdd(_Handle));
}

SB_INLINE void TElPDFIndirect::XrefAddOnce()
{
	SBCheckError(TElPDFIndirect_XrefAddOnce(_Handle));
}

SB_INLINE void TElPDFIndirect::XrefFree()
{
	SBCheckError(TElPDFIndirect_XrefFree(_Handle));
}

SB_INLINE int32_t TElPDFIndirect::get_ObjNumber()
{
	int32_t OutResult;
	SBCheckError(TElPDFIndirect_get_ObjNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFIndirect::set_ObjNumber(int32_t Value)
{
	SBCheckError(TElPDFIndirect_set_ObjNumber(_Handle, Value));
}

SB_INLINE int32_t TElPDFIndirect::get_GenNumber()
{
	int32_t OutResult;
	SBCheckError(TElPDFIndirect_get_GenNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFIndirect::set_GenNumber(int32_t Value)
{
	SBCheckError(TElPDFIndirect_set_GenNumber(_Handle, Value));
}

TElPDFObject* TElPDFIndirect::get_Obj()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFIndirect_get_Obj(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Obj)
		this->_Inst_Obj = new TElPDFObject(hOutResult, ohFalse);
	else
		this->_Inst_Obj->updateHandle(hOutResult);
	return this->_Inst_Obj;
}

SB_INLINE void TElPDFIndirect::set_Obj(TElPDFObject &Value)
{
	SBCheckError(TElPDFIndirect_set_Obj(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFIndirect::set_Obj(TElPDFObject *Value)
{
	SBCheckError(TElPDFIndirect_set_Obj(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

bool TElPDFIndirect::get_XrefAdded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFIndirect_get_XrefAdded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPDFIndirect::initInstances()
{
	this->_Inst_Obj = NULL;
}

TElPDFIndirect::TElPDFIndirect(TElPDFIndirectHandle handle, TElOwnHandle ownHandle) : TElPDFCpxObj(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFIndirect::TElPDFIndirect(TElPDFFile &Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFIndirect_Create(Owner.getHandle(), &_Handle));
}

TElPDFIndirect::TElPDFIndirect(TElPDFFile *Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFIndirect_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFIndirect::~TElPDFIndirect()
{
	delete this->_Inst_Obj;
	this->_Inst_Obj = NULL;
}
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

#ifdef SB_USE_CLASS_TELPDFREF

SB_INLINE TElPDFObjectHandle TElPDFRef::CreateCopy()
{
	TElPDFObjectHandle OutResult;
	SBCheckError(TElPDFRef_CreateCopy(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFRef::SetNumbers(int32_t ObjNum, int32_t GenNum)
{
	SBCheckError(TElPDFRef_SetNumbers(_Handle, ObjNum, GenNum));
}

SB_INLINE int32_t TElPDFRef::get_ObjNumber()
{
	int32_t OutResult;
	SBCheckError(TElPDFRef_get_ObjNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFRef::set_ObjNumber(int32_t Value)
{
	SBCheckError(TElPDFRef_set_ObjNumber(_Handle, Value));
}

SB_INLINE int32_t TElPDFRef::get_GenNumber()
{
	int32_t OutResult;
	SBCheckError(TElPDFRef_get_GenNumber(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFRef::set_GenNumber(int32_t Value)
{
	SBCheckError(TElPDFRef_set_GenNumber(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPDFINDIRECT
TElPDFIndirect* TElPDFRef::get_Obj()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFRef_get_Obj(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Obj)
		this->_Inst_Obj = new TElPDFIndirect(hOutResult, ohFalse);
	else
		this->_Inst_Obj->updateHandle(hOutResult);
	return this->_Inst_Obj;
}
#endif /* SB_USE_CLASS_TELPDFINDIRECT */

bool TElPDFRef::get_Loaded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPDFRef_get_Loaded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

void TElPDFRef::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFINDIRECT
	this->_Inst_Obj = NULL;
#endif /* SB_USE_CLASS_TELPDFINDIRECT */
}

TElPDFRef::TElPDFRef(TElPDFRefHandle handle, TElOwnHandle ownHandle) : TElPDFObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFRef::TElPDFRef(TElPDFFile &Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFRef_Create(Owner.getHandle(), &_Handle));
}

TElPDFRef::TElPDFRef(TElPDFFile *Owner) : TElPDFObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFRef_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFRef::~TElPDFRef()
{
#ifdef SB_USE_CLASS_TELPDFINDIRECT
	delete this->_Inst_Obj;
	this->_Inst_Obj = NULL;
#endif /* SB_USE_CLASS_TELPDFINDIRECT */
}
#endif /* SB_USE_CLASS_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFXREF

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
TElPDFDictionary* TElPDFXRef::get_Trailer()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFXRef_get_Trailer(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Trailer)
		this->_Inst_Trailer = new TElPDFDictionary(hOutResult, ohFalse);
	else
		this->_Inst_Trailer->updateHandle(hOutResult);
	return this->_Inst_Trailer;
}

SB_INLINE void TElPDFXRef::set_Trailer(TElPDFDictionary &Value)
{
	SBCheckError(TElPDFXRef_set_Trailer(_Handle, Value.getHandle()));
}

SB_INLINE void TElPDFXRef::set_Trailer(TElPDFDictionary *Value)
{
	SBCheckError(TElPDFXRef_set_Trailer(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

void TElPDFXRef::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	this->_Inst_Trailer = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}

TElPDFXRef::TElPDFXRef(TElPDFXRefHandle handle, TElOwnHandle ownHandle) : TElPDFCpxObj(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFXRef::TElPDFXRef(TElPDFFile &Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFXRef_Create(Owner.getHandle(), &_Handle));
}

TElPDFXRef::TElPDFXRef(TElPDFFile *Owner) : TElPDFCpxObj(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFXRef_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFXRef::~TElPDFXRef()
{
#ifdef SB_USE_CLASS_TELPDFDICTIONARY
	delete this->_Inst_Trailer;
	this->_Inst_Trailer = NULL;
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */
}
#endif /* SB_USE_CLASS_TELPDFXREF */

#ifdef SB_USE_CLASS_TELPDFXREFENTRY

TPDFXrefEntryType TElPDFXrefEntry::get_EntryType()
{
	TPDFXrefEntryTypeRaw OutResultRaw = 0;
	SBCheckError(TElPDFXrefEntry_get_EntryType(_Handle, &OutResultRaw));
	return (TPDFXrefEntryType)OutResultRaw;
}

TElPDFXrefEntry::TElPDFXrefEntry(TElPDFXrefEntryHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFXrefEntry::TElPDFXrefEntry(TElPDFFile &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFXrefEntry_Create(Owner.getHandle(), &_Handle));
}

TElPDFXrefEntry::TElPDFXrefEntry(TElPDFFile *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPDFXrefEntry_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

#ifdef SB_USE_CLASS_TELPDFXREFS

SB_INLINE int32_t TElPDFXRefs::AddXRef(int32_t ObjNumber, int32_t GenNumber, int64_t Offset, bool RaiseExceptionIfExists, bool OverwriteIfExists)
{
	int32_t OutResult;
	SBCheckError(TElPDFXRefs_AddXRef(_Handle, ObjNumber, GenNumber, Offset, (int8_t)RaiseExceptionIfExists, (int8_t)OverwriteIfExists, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPDFXRefs::AddXRef(int32_t ObjNumber, int32_t GenNumber, int32_t StreamObjNumber, int32_t StreamObjIndex, bool RaiseExceptionIfExists, bool OverwriteIfExists)
{
	int32_t OutResult;
	SBCheckError(TElPDFXRefs_AddXRef_1(_Handle, ObjNumber, GenNumber, StreamObjNumber, StreamObjIndex, (int8_t)RaiseExceptionIfExists, (int8_t)OverwriteIfExists, &OutResult));
	return OutResult;
}

SB_INLINE void TElPDFXRefs::RemoveXRef(int32_t Index)
{
	SBCheckError(TElPDFXRefs_RemoveXRef(_Handle, Index));
}

SB_INLINE void TElPDFXRefs::Clear()
{
	SBCheckError(TElPDFXRefs_Clear(_Handle));
}

SB_INLINE int32_t TElPDFXRefs::Find(int32_t ObjNumber, int32_t GenNumber)
{
	int32_t OutResult;
	SBCheckError(TElPDFXRefs_Find(_Handle, ObjNumber, GenNumber, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPDFXREFENTRY
TElPDFXrefEntry* TElPDFXRefs::get_XRefs(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPDFXRefs_get_XRefs(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_XRefs)
		this->_Inst_XRefs = new TElPDFXrefEntry(hOutResult, ohFalse);
	else
		this->_Inst_XRefs->updateHandle(hOutResult);
	return this->_Inst_XRefs;
}
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */

SB_INLINE int32_t TElPDFXRefs::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElPDFXRefs_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElPDFXRefs::initInstances()
{
#ifdef SB_USE_CLASS_TELPDFXREFENTRY
	this->_Inst_XRefs = NULL;
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */
}

TElPDFXRefs::TElPDFXRefs(TElPDFXRefsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELPDFFILE
TElPDFXRefs::TElPDFXRefs(TElPDFFile &Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFXRefs_Create(Owner.getHandle(), &_Handle));
}

TElPDFXRefs::TElPDFXRefs(TElPDFFile *Owner) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPDFXRefs_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELPDFFILE */

TElPDFXRefs::~TElPDFXRefs()
{
#ifdef SB_USE_CLASS_TELPDFXREFENTRY
	delete this->_Inst_XRefs;
	this->_Inst_XRefs = NULL;
#endif /* SB_USE_CLASS_TELPDFXREFENTRY */
}
#endif /* SB_USE_CLASS_TELPDFXREFS */

#ifdef SB_USE_GLOBAL_PROCS_PDFCORE

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void GetNameObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Default, bool RaiseException, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDFCore_GetNameObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Default.data(), (int32_t)Default.length(), (int8_t)RaiseException, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-565889885, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetNameObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Default, bool RaiseException, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDFCore_GetNameObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Default.data(), (int32_t)Default.length(), (int8_t)RaiseException, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-565889885, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE int32_t GetIntObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Default, bool RaiseException)
{
	int32_t OutResult;
	SBCheckError(SBPDFCore_GetIntObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Default, (int8_t)RaiseException, &OutResult));
	return OutResult;
}
SB_INLINE int32_t GetIntObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Default, bool RaiseException)
{
	int32_t OutResult;
	SBCheckError(SBPDFCore_GetIntObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Default, (int8_t)RaiseException, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE double GetRealObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, double Default, bool RaiseException)
{
	double OutResult;
	SBCheckError(SBPDFCore_GetRealObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Default, (int8_t)RaiseException, &OutResult));
	return OutResult;
}
SB_INLINE double GetRealObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, double Default, bool RaiseException)
{
	double OutResult;
	SBCheckError(SBPDFCore_GetRealObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Default, (int8_t)RaiseException, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
void GetStringObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFCore_GetStringObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1690467249, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void GetStringObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFCore_GetStringObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1690467249, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY
SB_INLINE TElPDFArrayHandle GetArrayObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException)
{
	TElPDFArrayHandle OutResult;
	SBCheckError(SBPDFCore_GetArrayObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, &OutResult));
	return OutResult;
}
SB_INLINE TElPDFArrayHandle GetArrayObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException)
{
	TElPDFArrayHandle OutResult;
	SBCheckError(SBPDFCore_GetArrayObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE TElPDFDictionaryHandle GetDictionaryObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool RaiseException)
{
	TElPDFDictionaryHandle OutResult;
	SBCheckError(SBPDFCore_GetDictionaryObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, &OutResult));
	return OutResult;
}
SB_INLINE TElPDFDictionaryHandle GetDictionaryObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool RaiseException)
{
	TElPDFDictionaryHandle OutResult;
	SBCheckError(SBPDFCore_GetDictionaryObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)RaiseException, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
bool GetBooleanObjectFromDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Default, bool RaiseException)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPDFCore_GetBooleanObjectFromDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)Default, (int8_t)RaiseException, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool GetBooleanObjectFromDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Default, bool RaiseException)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPDFCore_GetBooleanObjectFromDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)Default, (int8_t)RaiseException, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddRealObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, double Value)
{
	SBCheckError(SBPDFCore_AddRealObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value));
}
SB_INLINE void AddRealObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, double Value)
{
	SBCheckError(SBPDFCore_AddRealObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddRealObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, double Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddRealObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}
SB_INLINE void AddRealObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, double Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddRealObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddIntObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Value)
{
	SBCheckError(SBPDFCore_AddIntObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value));
}
SB_INLINE void AddIntObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Value)
{
	SBCheckError(SBPDFCore_AddIntObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddIntObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddIntObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}
SB_INLINE void AddIntObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddIntObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddBooleanObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Value)
{
	SBCheckError(SBPDFCore_AddBooleanObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)Value));
}
SB_INLINE void AddBooleanObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Value)
{
	SBCheckError(SBPDFCore_AddBooleanObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)Value));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddBooleanObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, bool Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddBooleanObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), (int8_t)Value, (int8_t)Overwrite));
}
SB_INLINE void AddBooleanObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, bool Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddBooleanObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (int8_t)Value, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFSTRING
SB_INLINE TElPDFStringHandle AddStringObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc)
{
	TElPDFStringHandle OutResult;
	SBCheckError(SBPDFCore_AddStringObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc, &OutResult));
	return OutResult;
}
SB_INLINE TElPDFStringHandle AddStringObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc)
{
	TElPDFStringHandle OutResult;
	SBCheckError(SBPDFCore_AddStringObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFSTRING */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddStringObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddStringObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc, (int8_t)Overwrite));
}
SB_INLINE void AddStringObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddStringObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddNameObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Value)
{
	SBCheckError(SBPDFCore_AddNameObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void AddNameObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Value)
{
	SBCheckError(SBPDFCore_AddNameObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddNameObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, const std::string &Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddNameObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), (int8_t)Overwrite));
}
SB_INLINE void AddNameObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, const std::string &Value, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddNameObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length(), (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY
SB_INLINE TElPDFArrayHandle AddRectangleObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2)
{
	TElPDFArrayHandle OutResult;
	SBCheckError(SBPDFCore_AddRectangleObjectToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), X1, Y1, X2, Y2, &OutResult));
	return OutResult;
}
SB_INLINE TElPDFArrayHandle AddRectangleObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2)
{
	TElPDFArrayHandle OutResult;
	SBCheckError(SBPDFCore_AddRectangleObjectToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), X1, Y1, X2, Y2, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPDFARRAY_AND_TELPDFDICTIONARY */

#ifdef SB_USE_CLASS_TELPDFDICTIONARY
SB_INLINE void AddRectangleObjectToDictionary(TElPDFDictionary &Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddRectangleObjectToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), X1, Y1, X2, Y2, (int8_t)Overwrite));
}
SB_INLINE void AddRectangleObjectToDictionary(TElPDFDictionary *Dict, const std::string &Name, int32_t X1, int32_t Y1, int32_t X2, int32_t Y2, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddRectangleObjectToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), X1, Y1, X2, Y2, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASS_TELPDFDICTIONARY */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF
SB_INLINE void AddReferenceToDictionary(TElPDFDictionary &Dict, const std::string &Name, TElPDFRef &Obj)
{
	SBCheckError(SBPDFCore_AddReferenceToDictionary(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Obj.getHandle()));
}
SB_INLINE void AddReferenceToDictionary(TElPDFDictionary *Dict, const std::string &Name, TElPDFRef *Obj)
{
	SBCheckError(SBPDFCore_AddReferenceToDictionary((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF */

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF
SB_INLINE void AddReferenceToDictionary(TElPDFDictionary &Dict, const std::string &Name, TElPDFRef &Obj, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddReferenceToDictionary_1(Dict.getHandle(), Name.data(), (int32_t)Name.length(), Obj.getHandle(), (int8_t)Overwrite));
}
SB_INLINE void AddReferenceToDictionary(TElPDFDictionary *Dict, const std::string &Name, TElPDFRef *Obj, bool Overwrite)
{
	SBCheckError(SBPDFCore_AddReferenceToDictionary_1((Dict != NULL) ? Dict->getHandle() : SB_NULL_HANDLE, Name.data(), (int32_t)Name.length(), (Obj != NULL) ? Obj->getHandle() : SB_NULL_HANDLE, (int8_t)Overwrite));
}
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TELPDFREF */

#ifdef SB_USE_CLASS_TELPDFARRAY
SB_INLINE void AddRealObjectToArray(TElPDFArray &Arr, double Value)
{
	SBCheckError(SBPDFCore_AddRealObjectToArray(Arr.getHandle(), Value));
}
SB_INLINE void AddRealObjectToArray(TElPDFArray *Arr, double Value)
{
	SBCheckError(SBPDFCore_AddRealObjectToArray((Arr != NULL) ? Arr->getHandle() : SB_NULL_HANDLE, Value));
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
SB_INLINE void AddIntObjectToArray(TElPDFArray &Arr, int32_t Value)
{
	SBCheckError(SBPDFCore_AddIntObjectToArray(Arr.getHandle(), Value));
}
SB_INLINE void AddIntObjectToArray(TElPDFArray *Arr, int32_t Value)
{
	SBCheckError(SBPDFCore_AddIntObjectToArray((Arr != NULL) ? Arr->getHandle() : SB_NULL_HANDLE, Value));
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
SB_INLINE void AddNameObjectToArray(TElPDFArray &Arr, const std::string &Value)
{
	SBCheckError(SBPDFCore_AddNameObjectToArray(Arr.getHandle(), Value.data(), (int32_t)Value.length()));
}
SB_INLINE void AddNameObjectToArray(TElPDFArray *Arr, const std::string &Value)
{
	SBCheckError(SBPDFCore_AddNameObjectToArray((Arr != NULL) ? Arr->getHandle() : SB_NULL_HANDLE, Value.data(), (int32_t)Value.length()));
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASS_TELPDFARRAY
SB_INLINE void AddStringObjectToArray(TElPDFArray &Arr, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc)
{
	SBCheckError(SBPDFCore_AddStringObjectToArray(Arr.getHandle(), SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc));
}
SB_INLINE void AddStringObjectToArray(TElPDFArray *Arr, const std::vector<uint8_t> &Value, TPDFStringEncoding Enc)
{
	SBCheckError(SBPDFCore_AddStringObjectToArray((Arr != NULL) ? Arr->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (TPDFStringEncodingRaw)Enc));
}
#endif /* SB_USE_CLASS_TELPDFARRAY */

#ifdef SB_USE_CLASSES_TELPDFFILE_AND_TELPDFSTREAM
SB_INLINE TElPDFStreamHandle CreateStream(TElPDFFile &Owner)
{
	TElPDFStreamHandle OutResult;
	SBCheckError(SBPDFCore_CreateStream(Owner.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE TElPDFStreamHandle CreateStream(TElPDFFile *Owner)
{
	TElPDFStreamHandle OutResult;
	SBCheckError(SBPDFCore_CreateStream((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASSES_TELPDFFILE_AND_TELPDFSTREAM */

#ifdef SB_USE_CLASS_TELPDFSTREAM
SB_INLINE void CompressStream(TElPDFStream &Strm, bool AddCRLF)
{
	SBCheckError(SBPDFCore_CompressStream(Strm.getHandle(), (int8_t)AddCRLF));
}
SB_INLINE void CompressStream(TElPDFStream *Strm, bool AddCRLF)
{
	SBCheckError(SBPDFCore_CompressStream((Strm != NULL) ? Strm->getHandle() : SB_NULL_HANDLE, (int8_t)AddCRLF));
}
#endif /* SB_USE_CLASS_TELPDFSTREAM */

void EncodePDFDate(int64_t D, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDFCore_EncodePDFDate(D, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-807044135, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void EncodePDFDate(int64_t D, bool AddUTCPostfix, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDFCore_EncodePDFDate_1(D, (int8_t)AddUTCPostfix, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1321059517, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t DecodePDFDate(const std::string &S)
{
	int64_t OutResult;
	SBCheckError(SBPDFCore_DecodePDFDate(S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

void EncodeTextString(const std::string &Str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFCore_EncodeTextString(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1131210513, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void EncodeTextStringUnicode(const std::string &Str, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPDFCore_EncodeTextStringUnicode(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(67706360, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void DecodeTextString(const std::vector<uint8_t> &Buf, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPDFCore_DecodeTextString(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-17947006, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASSES_TELPDFDICTIONARY_AND_TSTRINGLIST
SB_INLINE void GetSortedKeyList(TElPDFDictionary &Dictionary, TStringList &List)
{
	SBCheckError(SBPDFCore_GetSortedKeyList(Dictionary.getHandle(), List.getHandle()));
}
SB_INLINE void GetSortedKeyList(TElPDFDictionary *Dictionary, TStringList *List)
{
	SBCheckError(SBPDFCore_GetSortedKeyList((Dictionary != NULL) ? Dictionary->getHandle() : SB_NULL_HANDLE, (List != NULL) ? List->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASSES_TELPDFDICTIONARY_AND_TSTRINGLIST */

#endif /* SB_USE_GLOBAL_PROCS_PDFCORE */

};	/* namespace SecureBlackbox */

