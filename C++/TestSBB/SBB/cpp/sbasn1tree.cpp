#include "sbasn1tree.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG

bool TElASN1CustomTag::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_LoadFromBuffer(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1CustomTag::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1CustomTag::CheckType(uint8_t TagId, bool Constrained)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_CheckType(_Handle, TagId, (int8_t)Constrained, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElASN1CustomTag::LoadFromStream(TStream &Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1CustomTag::LoadFromStream(TStream *Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASN1CustomTag::SaveToStream(TStream &Stream)
{
	SBCheckError(TElASN1CustomTag_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElASN1CustomTag::SaveToStream(TStream *Stream)
{
	SBCheckError(TElASN1CustomTag_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE uint8_t TElASN1CustomTag::get_TagId()
{
	uint8_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagId(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1CustomTag::set_TagId(uint8_t Value)
{
	SBCheckError(TElASN1CustomTag_set_TagId(_Handle, Value));
}

bool TElASN1CustomTag::get_UndefSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_get_UndefSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElASN1CustomTag::set_UndefSize(bool Value)
{
	SBCheckError(TElASN1CustomTag_set_UndefSize(_Handle, (int8_t)Value));
}

bool TElASN1CustomTag::get_WriteHeader()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_get_WriteHeader(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElASN1CustomTag::set_WriteHeader(bool Value)
{
	SBCheckError(TElASN1CustomTag_set_WriteHeader(_Handle, (int8_t)Value));
}

bool TElASN1CustomTag::get_IsConstrained()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1CustomTag_get_IsConstrained(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE uint8_t TElASN1CustomTag::get_TagNum()
{
	uint8_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagNum(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElASN1CustomTag::get_TagOffset()
{
	int64_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagOffset(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElASN1CustomTag::get_TagSize()
{
	int64_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElASN1CustomTag::get_TagHeaderSize()
{
	int32_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagHeaderSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElASN1CustomTag::get_TagContentSize()
{
	int64_t OutResult;
	SBCheckError(TElASN1CustomTag_get_TagContentSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElASN1CustomTag::get_Depth()
{
	int32_t OutResult;
	SBCheckError(TElASN1CustomTag_get_Depth(_Handle, &OutResult));
	return OutResult;
}

TElASN1CustomTag::TElASN1CustomTag(TElASN1CustomTagHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElASN1CustomTag::TElASN1CustomTag() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASN1CustomTag_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE

SB_INLINE void TElASN1DataSource::Init(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElASN1DataSource_Init(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASN1DataSource::Init(TStream &Stream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElASN1DataSource_Init_1(_Handle, Stream.getHandle(), Offset, Size));
}

SB_INLINE void TElASN1DataSource::Init(TStream *Stream, int64_t Offset, int64_t Size)
{
	SBCheckError(TElASN1DataSource_Init_1(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Offset, Size));
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASN1DataSource::Init(TStream &Stream, bool UnknownSize)
{
	SBCheckError(TElASN1DataSource_Init_2(_Handle, Stream.getHandle(), (int8_t)UnknownSize));
}

SB_INLINE void TElASN1DataSource::Init(TStream *Stream, bool UnknownSize)
{
	SBCheckError(TElASN1DataSource_Init_2(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, (int8_t)UnknownSize));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TElASN1DataSource::Init(void * Buffer, int32_t Size)
{
	SBCheckError(TElASN1DataSource_Init_3(_Handle, Buffer, Size));
}

SB_INLINE void TElASN1DataSource::InitVirtual(int64_t Size)
{
	SBCheckError(TElASN1DataSource_InitVirtual(_Handle, Size));
}

SB_INLINE int32_t TElASN1DataSource::Read(void * Buffer, int32_t Size, int64_t Offset)
{
	int32_t OutResult;
	SBCheckError(TElASN1DataSource_Read(_Handle, Buffer, Size, Offset, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1DataSource::Clone(TElASN1DataSource &Dest)
{
	SBCheckError(TElASN1DataSource_Clone(_Handle, Dest.getHandle()));
}

SB_INLINE void TElASN1DataSource::Clone(TElASN1DataSource *Dest)
{
	SBCheckError(TElASN1DataSource_Clone(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TElASN1DataSource::CloneVirtual(TElASN1DataSource &Dest)
{
	SBCheckError(TElASN1DataSource_CloneVirtual(_Handle, Dest.getHandle()));
}

SB_INLINE void TElASN1DataSource::CloneVirtual(TElASN1DataSource *Dest)
{
	SBCheckError(TElASN1DataSource_CloneVirtual(_Handle, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE));
}

void TElASN1DataSource::ToBuffer(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElASN1DataSource_ToBuffer(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(226961468, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElASN1DataSource::get_Size()
{
	int64_t OutResult;
	SBCheckError(TElASN1DataSource_get_Size(_Handle, &OutResult));
	return OutResult;
}

bool TElASN1DataSource::get_UnknownSize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1DataSource_get_UnknownSize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1DataSource::get_SkipVirtualData()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1DataSource_get_SkipVirtualData(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElASN1DataSource::set_SkipVirtualData(bool Value)
{
	SBCheckError(TElASN1DataSource_set_SkipVirtualData(_Handle, (int8_t)Value));
}

TSBASN1DataSourceType TElASN1DataSource::get_SourceType()
{
	TSBASN1DataSourceTypeRaw OutResultRaw = 0;
	SBCheckError(TElASN1DataSource_get_SourceType(_Handle, &OutResultRaw));
	return (TSBASN1DataSourceType)OutResultRaw;
}

SB_INLINE void TElASN1DataSource::get_OnVirtualDataNeeded(TSBASN1VirtualDataNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1DataSource_get_OnVirtualDataNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1DataSource::set_OnVirtualDataNeeded(TSBASN1VirtualDataNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1DataSource_set_OnVirtualDataNeeded(_Handle, pMethodValue, pDataValue));
}

TElASN1DataSource::TElASN1DataSource(TElASN1DataSourceHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElASN1DataSource::TElASN1DataSource() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASN1DataSource_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG

SB_INLINE TElASN1SimpleTagHandle TElASN1SimpleTag::CreateInstance()
{
	TElASN1SimpleTagHandle OutResult;
	SBCheckError(TElASN1SimpleTag_CreateInstance(&OutResult));
	return OutResult;
}

SB_INLINE TElASN1SimpleTagHandle TElASN1SimpleTag::CreateInstance_Inst()
{
	TElASN1SimpleTagHandle OutResult;
	SBCheckError(TElASN1SimpleTag_CreateInstance_1(_Handle, &OutResult));
	return OutResult;
}

bool TElASN1SimpleTag::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1SimpleTag_LoadFromBuffer(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1SimpleTag::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1SimpleTag_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElASN1SimpleTag::LoadFromStream(TStream &Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1SimpleTag_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1SimpleTag::LoadFromStream(TStream *Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1SimpleTag_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASN1SimpleTag::SaveToStream(TStream &Stream)
{
	SBCheckError(TElASN1SimpleTag_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElASN1SimpleTag::SaveToStream(TStream *Stream)
{
	SBCheckError(TElASN1SimpleTag_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void TElASN1SimpleTag::get_Content(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElASN1SimpleTag_get_Content(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1627703137, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElASN1SimpleTag::set_Content(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElASN1SimpleTag_set_Content(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
TElASN1DataSource* TElASN1SimpleTag::get_DataSource()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElASN1SimpleTag_get_DataSource(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DataSource)
		this->_Inst_DataSource = new TElASN1DataSource(hOutResult, ohFalse);
	else
		this->_Inst_DataSource->updateHandle(hOutResult);
	return this->_Inst_DataSource;
}
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

SB_INLINE int32_t TElASN1SimpleTag::get_FragmentSize()
{
	int32_t OutResult;
	SBCheckError(TElASN1SimpleTag_get_FragmentSize(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1SimpleTag::set_FragmentSize(int32_t Value)
{
	SBCheckError(TElASN1SimpleTag_set_FragmentSize(_Handle, Value));
}

SB_INLINE void TElASN1SimpleTag::get_OnContentWriteBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1SimpleTag_get_OnContentWriteBegin(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1SimpleTag::set_OnContentWriteBegin(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1SimpleTag_set_OnContentWriteBegin(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElASN1SimpleTag::get_OnContentWriteEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1SimpleTag_get_OnContentWriteEnd(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1SimpleTag::set_OnContentWriteEnd(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1SimpleTag_set_OnContentWriteEnd(_Handle, pMethodValue, pDataValue));
}

void TElASN1SimpleTag::initInstances()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}

TElASN1SimpleTag::TElASN1SimpleTag(TElASN1SimpleTagHandle handle, TElOwnHandle ownHandle) : TElASN1CustomTag(handle, ownHandle)
{
	initInstances();
}

TElASN1SimpleTag::TElASN1SimpleTag() : TElASN1CustomTag(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElASN1SimpleTag_Create(&_Handle));
}

TElASN1SimpleTag::~TElASN1SimpleTag()
{
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
	delete this->_Inst_DataSource;
	this->_Inst_DataSource = NULL;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG

SB_INLINE TElASN1ConstrainedTagHandle TElASN1ConstrainedTag::CreateInstance()
{
	TElASN1ConstrainedTagHandle OutResult;
	SBCheckError(TElASN1ConstrainedTag_CreateInstance(&OutResult));
	return OutResult;
}

SB_INLINE TElASN1ConstrainedTagHandle TElASN1ConstrainedTag::CreateInstance_Inst()
{
	TElASN1ConstrainedTagHandle OutResult;
	SBCheckError(TElASN1ConstrainedTag_CreateInstance_1(_Handle, &OutResult));
	return OutResult;
}

bool TElASN1ConstrainedTag::LoadFromBuffer(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_LoadFromBuffer(_Handle, Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElASN1ConstrainedTag::LoadFromBufferSingle(void * Buffer, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(TElASN1ConstrainedTag_LoadFromBufferSingle(_Handle, Buffer, Size, &OutResult));
	return OutResult;
}

bool TElASN1ConstrainedTag::SaveToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_SaveToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1ConstrainedTag::SaveContentToBuffer(void * Buffer, int32_t &Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_SaveContentToBuffer(_Handle, Buffer, &Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TSTREAM
bool TElASN1ConstrainedTag::LoadFromStream(TStream &Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_LoadFromStream(_Handle, Stream.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1ConstrainedTag::LoadFromStream(TStream *Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
bool TElASN1ConstrainedTag::LoadFromStreamSingle(TStream &Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_LoadFromStreamSingle(_Handle, Stream.getHandle(), Count, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElASN1ConstrainedTag::LoadFromStreamSingle(TStream *Stream, int64_t Count)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_LoadFromStreamSingle(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, Count, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElASN1ConstrainedTag::SaveToStream(TStream &Stream)
{
	SBCheckError(TElASN1ConstrainedTag_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TElASN1ConstrainedTag::SaveToStream(TStream *Stream)
{
	SBCheckError(TElASN1ConstrainedTag_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE int32_t TElASN1ConstrainedTag::AddField(bool Constrained)
{
	int32_t OutResult;
	SBCheckError(TElASN1ConstrainedTag_AddField(_Handle, (int8_t)Constrained, &OutResult));
	return OutResult;
}

bool TElASN1ConstrainedTag::RemoveField(int32_t Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_RemoveField(_Handle, Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TElASN1CustomTagHandle TElASN1ConstrainedTag::GetField(int32_t Index)
{
	TElASN1CustomTagHandle OutResult;
	SBCheckError(TElASN1ConstrainedTag_GetField(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1ConstrainedTag::Clear()
{
	SBCheckError(TElASN1ConstrainedTag_Clear(_Handle));
}

SB_INLINE int32_t TElASN1ConstrainedTag::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElASN1ConstrainedTag_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElASN1ConstrainedTag::get_MaxSimpleTagLength()
{
	int32_t OutResult;
	SBCheckError(TElASN1ConstrainedTag_get_MaxSimpleTagLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1ConstrainedTag::set_MaxSimpleTagLength(int32_t Value)
{
	SBCheckError(TElASN1ConstrainedTag_set_MaxSimpleTagLength(_Handle, Value));
}

TSBASN1StreamAccess TElASN1ConstrainedTag::get_StreamAccess()
{
	TSBASN1StreamAccessRaw OutResultRaw = 0;
	SBCheckError(TElASN1ConstrainedTag_get_StreamAccess(_Handle, &OutResultRaw));
	return (TSBASN1StreamAccess)OutResultRaw;
}

SB_INLINE void TElASN1ConstrainedTag::set_StreamAccess(TSBASN1StreamAccess Value)
{
	SBCheckError(TElASN1ConstrainedTag_set_StreamAccess(_Handle, (TSBASN1StreamAccessRaw)Value));
}

TElASN1ConstrainedTag::TElASN1ConstrainedTag(TElASN1ConstrainedTagHandle handle, TElOwnHandle ownHandle) : TElASN1CustomTag(handle, ownHandle)
{
}

TElASN1ConstrainedTag::TElASN1ConstrainedTag() : TElASN1CustomTag(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASN1ConstrainedTag_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_GLOBAL_PROCS_ASN1TREE

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE void asymWriteInteger(TElASN1SimpleTag &Tag, void * Buffer, int32_t Size)
{
	SBCheckError(SBASN1Tree_asymWriteInteger(Tag.getHandle(), Buffer, Size));
}
SB_INLINE void asymWriteInteger(TElASN1SimpleTag *Tag, void * Buffer, int32_t Size)
{
	SBCheckError(SBASN1Tree_asymWriteInteger((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, Buffer, Size));
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE int32_t ASN1ReadInteger(TElASN1SimpleTag &Tag)
{
	int32_t OutResult;
	SBCheckError(SBASN1Tree_ASN1ReadInteger(Tag.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int32_t ASN1ReadInteger(TElASN1SimpleTag *Tag)
{
	int32_t OutResult;
	SBCheckError(SBASN1Tree_ASN1ReadInteger((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE int64_t ASN1ReadInteger64(TElASN1SimpleTag &Tag)
{
	int64_t OutResult;
	SBCheckError(SBASN1Tree_ASN1ReadInteger64(Tag.getHandle(), &OutResult));
	return OutResult;
}
SB_INLINE int64_t ASN1ReadInteger64(TElASN1SimpleTag *Tag)
{
	int64_t OutResult;
	SBCheckError(SBASN1Tree_ASN1ReadInteger64((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE void ASN1WriteInteger(TElASN1SimpleTag &Tag, int32_t Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteInteger(Tag.getHandle(), Value));
}
SB_INLINE void ASN1WriteInteger(TElASN1SimpleTag *Tag, int32_t Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteInteger((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, Value));
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE void ASN1WriteInteger64(TElASN1SimpleTag &Tag, int64_t Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteInteger64(Tag.getHandle(), Value));
}
SB_INLINE void ASN1WriteInteger64(TElASN1SimpleTag *Tag, int64_t Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteInteger64((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, Value));
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

void ASN1ReadSimpleValue(const std::vector<uint8_t> &Data, int32_t &TagID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1Tree_ASN1ReadSimpleValue(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &TagID, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-457708827, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ASN1WriteTagAndLength(int32_t Tag, int64_t Len, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1Tree_ASN1WriteTagAndLength(Tag, Len, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1772507958, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
bool ASN1ReadBoolean(TElASN1SimpleTag &Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1Tree_ASN1ReadBoolean(Tag.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}
bool ASN1ReadBoolean(TElASN1SimpleTag *Tag)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1Tree_ASN1ReadBoolean((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_INLINE void ASN1WriteBoolean(TElASN1SimpleTag &Tag, bool Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteBoolean(Tag.getHandle(), (int8_t)Value));
}
SB_INLINE void ASN1WriteBoolean(TElASN1SimpleTag *Tag, bool Value)
{
	SBCheckError(SBASN1Tree_ASN1WriteBoolean((Tag != NULL) ? Tag->getHandle() : SB_NULL_HANDLE, (int8_t)Value));
}
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

void ASN1ReadString(const std::vector<uint8_t> &Data, int32_t TagId, sb_u16string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBASN1Tree_ASN1ReadString(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), TagId, (sb_char16_t *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringW(-1327107858, 2, (sb_char16_t *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#ifdef SB_U16STRING_USED
void ASN1ReadString(const std::vector<uint8_t> &Data, int32_t TagId, std::wstring &OutResult)
{
	std::string u16OutResult;
	int32_t szOutResult = 0;
	uint32_t _err = SBASN1Tree_ASN1ReadString(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), TagId, NULL, &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		u16OutResult.resize(szOutResult << 1);
		SBCheckError(SBGetLastReturnStringW(-1327107858, 2, reinterpret_cast<sb_char16_t*>((char*)u16OutResult.data()), &szOutResult));
	}
	else
		SBCheckError(_err);

	u16OutResult.resize(szOutResult << 1);
	sb_u16_to_wstring(u16OutResult, OutResult);
}
#endif /* SB_U16STRING_USED */

void ASN1ReadStringAnsi(const std::vector<uint8_t> &Data, int32_t TagId, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBASN1Tree_ASN1ReadStringAnsi(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), TagId, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-2139646446, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void FormatAttributeValue(int32_t TagID, const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1Tree_FormatAttributeValue(TagID, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1563218394, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnformatAttributeValue(const std::vector<uint8_t> &Value, int32_t &TagID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1Tree_UnformatAttributeValue(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &TagID, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-705886238, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetMaxASN1TreeDepth()
{
	int32_t OutResult;
	SBCheckError(SBASN1Tree_GetMaxASN1TreeDepth(&OutResult));
	return OutResult;
}

SB_INLINE void SetMaxASN1TreeDepth(int32_t Value)
{
	SBCheckError(SBASN1Tree_SetMaxASN1TreeDepth(Value));
}

SB_INLINE int32_t GetMaxASN1BufferLength()
{
	int32_t OutResult;
	SBCheckError(SBASN1Tree_GetMaxASN1BufferLength(&OutResult));
	return OutResult;
}

SB_INLINE void SetMaxASN1BufferLength(int32_t Value)
{
	SBCheckError(SBASN1Tree_SetMaxASN1BufferLength(Value));
}

#endif /* SB_USE_GLOBAL_PROCS_ASN1TREE */

};	/* namespace SecureBlackbox */

