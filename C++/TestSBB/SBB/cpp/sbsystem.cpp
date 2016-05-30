#include "sbsystem.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TOBJECT

SB_INLINE void TObject::Free()
{
	SBCheckError(TObject_Free(_Handle));
}

SB_INLINE TClassHandle TObject::GetType()
{
	TClassHandle OutResult;
	SBCheckError(TObject_ClassType(_Handle, &OutResult));
	return OutResult;
}

void TObject::ClassName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TObject_ClassName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1710345970, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TObject::ClassName_Inst(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TObject_ClassName_1(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1710345970, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TObject::ClassNameIs(const std::string &name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TObject_ClassNameIs(name.data(), (int32_t)name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TObject::ClassNameIs_Inst(const std::string &name)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TObject_ClassNameIs_1(_Handle, name.data(), (int32_t)name.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TObject::InstanceSize()
{
	int32_t OutResult;
	SBCheckError(TObject_InstanceSize(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TObject::InstanceSize_Inst()
{
	int32_t OutResult;
	SBCheckError(TObject_InstanceSize_1(_Handle, &OutResult));
	return OutResult;
}

TObject::TObject(TObjectHandle handle, TElOwnHandle ownHandle)
{
	_Handle = handle;
	_OwnHandle = ownHandle;
}

TObject::TObject()
{
	SBCheckError(TObject_Create(&_Handle));
}

TObject::~TObject()
{
	if (_OwnHandle)
		TObject_Free(_Handle);
	_Handle = SB_NULL_HANDLE;
}
#endif /* SB_USE_CLASS_TOBJECT */

#ifdef SB_USE_CLASS_TBITS

bool TBits::get_Bits(int32_t Bit)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TBits_get_Bits(_Handle, Bit, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TBits::set_Bits(int32_t bit, bool value)
{
	SBCheckError(TBits_set_Bits(_Handle, bit, (int8_t)value));
}

SB_INLINE int32_t TBits::get_Size()
{
	int32_t OutResult;
	SBCheckError(TBits_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TBits::set_Size(int32_t Value)
{
	SBCheckError(TBits_set_Size(_Handle, Value));
}

TBits::TBits(TBitsHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TBits::TBits() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TBits_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TBITS */

#ifdef SB_USE_CLASS_TPERSISTENT

SB_INLINE void TPersistent::Assign(TPersistent &Source)
{
	SBCheckError(TPersistent_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TPersistent::Assign(TPersistent *Source)
{
	SBCheckError(TPersistent_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

void TPersistent::GetNamePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TPersistent_GetNamePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1117717680, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TPersistent::TPersistent(TPersistentHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TPersistent::TPersistent() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TPersistent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TPERSISTENT */

#ifdef SB_USE_CLASS_TSTREAM

SB_INLINE int32_t TStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TStream::ReadBuffer(void * Buffer, int32_t Count)
{
	SBCheckError(TStream_ReadBuffer(_Handle, Buffer, Count));
}

SB_INLINE void TStream::WriteBuffer(const void * Buffer, int32_t Count)
{
	SBCheckError(TStream_WriteBuffer(_Handle, Buffer, Count));
}

SB_INLINE int64_t TStream::CopyFrom(TStream &Source, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TStream_CopyFrom(_Handle, Source.getHandle(), Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TStream::CopyFrom(TStream *Source, int64_t Count)
{
	int64_t OutResult;
	SBCheckError(TStream_CopyFrom(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, Count, &OutResult));
	return OutResult;
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE uint8_t TStream::ReadByte()
{
	uint8_t OutResult;
	SBCheckError(TStream_ReadByte(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE uint16_t TStream::ReadWord()
{
	uint16_t OutResult;
	SBCheckError(TStream_ReadWord(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE uint32_t TStream::ReadDWord()
{
	uint32_t OutResult;
	SBCheckError(TStream_ReadDWord(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void TStream::ReadAnsiString(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStream_ReadAnsiString(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1286935347, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE void TStream::WriteByte(uint8_t b)
{
	SBCheckError(TStream_WriteByte(_Handle, b));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE void TStream::WriteWord(uint16_t w)
{
	SBCheckError(TStream_WriteWord(_Handle, w));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE void TStream::WriteDWord(uint32_t d)
{
	SBCheckError(TStream_WriteDWord(_Handle, d));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE void TStream::WriteAnsiString(const std::string &S)
{
	SBCheckError(TStream_WriteAnsiString(_Handle, S.data(), (int32_t)S.length()));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

SB_INLINE int64_t TStream::get_Position()
{
	int64_t OutResult;
	SBCheckError(TStream_get_Position(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStream::set_Position(int64_t Value)
{
	SBCheckError(TStream_set_Position(_Handle, Value));
}

SB_INLINE int64_t TStream::get_Size()
{
	int64_t OutResult;
	SBCheckError(TStream_get_Size(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStream::set_Size(int64_t Value)
{
	SBCheckError(TStream_set_Size(_Handle, Value));
}

TStream::TStream(TStreamHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TStream::TStream() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_THANDLESTREAM

SB_INLINE int32_t THandleStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(THandleStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t THandleStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(THandleStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int64_t THandleStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(THandleStream_Seek(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int32_t THandleStream::get_Handle()
{
	int32_t OutResult;
	SBCheckError(THandleStream_get_Handle(_Handle, &OutResult));
	return OutResult;
}

THandleStream::THandleStream(THandleStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

THandleStream::THandleStream(int32_t AHandle) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(THandleStream_Create(AHandle, &_Handle));
}

#endif /* SB_USE_CLASS_THANDLESTREAM */

#ifdef SB_USE_CLASS_TFILESTREAM

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void TFileStream::get_FileName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TFileStream_get_FileName(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(124299016, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

TFileStream::TFileStream(TFileStreamHandle handle, TElOwnHandle ownHandle) : THandleStream(handle, ownHandle)
{
}

TFileStream::TFileStream(const std::string &AFileName, uint16_t Mode) : THandleStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TFileStream_Create(AFileName.data(), (int32_t)AFileName.length(), Mode, &_Handle));
}

TFileStream::TFileStream(const std::string &AFileName, uint16_t Mode, uint32_t Rights) : THandleStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TFileStream_Create_1(AFileName.data(), (int32_t)AFileName.length(), Mode, Rights, &_Handle));
}

#endif /* SB_USE_CLASS_TFILESTREAM */

#ifdef SB_USE_CLASS_TINTERFACEDOBJECT

TInterfacedObject::TInterfacedObject(TInterfacedObjectHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TInterfacedObject::TInterfacedObject() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TInterfacedObject_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TINTERFACEDOBJECT */

#ifdef SB_USE_CLASS_TINTERFACEDPERSISTENT

TInterfacedPersistent::TInterfacedPersistent(TInterfacedPersistentHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TInterfacedPersistent::TInterfacedPersistent() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TInterfacedPersistent_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TINTERFACEDPERSISTENT */

#ifdef SB_USE_CLASS_TLIST

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_INLINE void TList::AddList(TList &AList)
{
	SBCheckError(TList_AddList(_Handle, AList.getHandle()));
}

SB_INLINE void TList::AddList(TList *AList)
{
	SBCheckError(TList_AddList(_Handle, (AList != NULL) ? AList->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

SB_INLINE int32_t TList::Add(void * Item)
{
	int32_t OutResult;
	SBCheckError(TList_Add(_Handle, Item, &OutResult));
	return OutResult;
}

SB_INLINE void TList::Clear()
{
	SBCheckError(TList_Clear(_Handle));
}

SB_INLINE void TList::Delete(int32_t Index)
{
	SBCheckError(TList_Delete(_Handle, Index));
}

SB_INLINE void TList::Error(const std::string &Msg, int32_t Data)
{
	SBCheckError(TList_Error(Msg.data(), (int32_t)Msg.length(), Data));
}

SB_INLINE void TList::Error_Inst(const std::string &Msg, int32_t Data)
{
	SBCheckError(TList_Error_1(_Handle, Msg.data(), (int32_t)Msg.length(), Data));
}

SB_INLINE void TList::Exchange(int32_t Index1, int32_t Index2)
{
	SBCheckError(TList_Exchange(_Handle, Index1, Index2));
}

SB_INLINE TListHandle TList::Expand()
{
	TListHandle OutResult;
	SBCheckError(TList_Expand(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void * TList::Extract(void * item)
{
	void * OutResult;
	SBCheckError(TList_Extract(_Handle, item, &OutResult));
	return OutResult;
}

SB_INLINE void * TList::First()
{
	void * OutResult;
	SBCheckError(TList_First(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TList::IndexOf(void * Item)
{
	int32_t OutResult;
	SBCheckError(TList_IndexOf(_Handle, Item, &OutResult));
	return OutResult;
}

SB_INLINE void TList::Insert(int32_t Index, void * Item)
{
	SBCheckError(TList_Insert(_Handle, Index, Item));
}

SB_INLINE void * TList::Last()
{
	void * OutResult;
	SBCheckError(TList_Last(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TList::Move(int32_t CurIndex, int32_t NewIndex)
{
	SBCheckError(TList_Move(_Handle, CurIndex, NewIndex));
}

SB_INLINE void TList::Assign(TList &ListA, TListAssignOp AOperator, TList &ListB)
{
	SBCheckError(TList_Assign(_Handle, ListA.getHandle(), (TListAssignOpRaw)AOperator, ListB.getHandle()));
}

SB_INLINE void TList::Assign(TList *ListA, TListAssignOp AOperator, TList *ListB)
{
	SBCheckError(TList_Assign(_Handle, (ListA != NULL) ? ListA->getHandle() : SB_NULL_HANDLE, (TListAssignOpRaw)AOperator, (ListB != NULL) ? ListB->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE int32_t TList::Remove(void * Item)
{
	int32_t OutResult;
	SBCheckError(TList_Remove(_Handle, Item, &OutResult));
	return OutResult;
}

SB_INLINE void TList::Pack()
{
	SBCheckError(TList_Pack(_Handle));
}

SB_INLINE void TList::Sort(void * Compare)
{
	SBCheckError(TList_Sort(_Handle, Compare));
}

SB_INLINE int32_t TList::get_Capacity()
{
	int32_t OutResult;
	SBCheckError(TList_get_Capacity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TList::set_Capacity(int32_t Value)
{
	SBCheckError(TList_set_Capacity(_Handle, Value));
}

SB_INLINE int32_t TList::get_Count()
{
	int32_t OutResult;
	SBCheckError(TList_get_Count(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TList::set_Count(int32_t Value)
{
	SBCheckError(TList_set_Count(_Handle, Value));
}

SB_INLINE void * TList::get_Items(int32_t Index)
{
	void * OutResult;
	SBCheckError(TList_get_Items(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TList::set_Items(int32_t Index, void * Item)
{
	SBCheckError(TList_set_Items(_Handle, Index, Item));
}

TList::TList(TListHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TList::TList() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TCUSTOMMEMORYSTREAM

SB_INLINE int32_t TCustomMemoryStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TCustomMemoryStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TCustomMemoryStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TCustomMemoryStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE void TCustomMemoryStream::SaveToStream(TStream &Stream)
{
	SBCheckError(TCustomMemoryStream_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TCustomMemoryStream::SaveToStream(TStream *Stream)
{
	SBCheckError(TCustomMemoryStream_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TCustomMemoryStream::SaveToFile(const std::string &FileName)
{
	SBCheckError(TCustomMemoryStream_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void * TCustomMemoryStream::get_Memory()
{
	void * OutResult;
	SBCheckError(TCustomMemoryStream_get_Memory(_Handle, &OutResult));
	return OutResult;
}

TCustomMemoryStream::TCustomMemoryStream(TCustomMemoryStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
}

TCustomMemoryStream::TCustomMemoryStream() : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TCustomMemoryStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TCUSTOMMEMORYSTREAM */

#ifdef SB_USE_CLASS_TCOMPONENT

void TComponent::GetNamePath(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TComponent_GetNamePath(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1591861097, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TComponent::get_Name(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TComponent_get_Name(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-423129050, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TComponent::set_Name(const std::string &Value)
{
	SBCheckError(TComponent_set_Name(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TComponent::get_Tag()
{
	int32_t OutResult;
	SBCheckError(TComponent_get_Tag(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TComponent::set_Tag(int32_t Value)
{
	SBCheckError(TComponent_set_Tag(_Handle, Value));
}

TComponent::TComponent(TComponentHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
}

TComponent::TComponent(TComponent &AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TComponent_Create(AOwner.getHandle(), &_Handle));
}

TComponent::TComponent(TComponent *AOwner) : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TComponent_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TCOMPONENT */

#ifdef SB_USE_CLASS_TMEMORYSTREAM

SB_INLINE void TMemoryStream::Clear()
{
	SBCheckError(TMemoryStream_Clear(_Handle));
}

SB_INLINE void TMemoryStream::LoadFromStream(TStream &Stream)
{
	SBCheckError(TMemoryStream_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TMemoryStream::LoadFromStream(TStream *Stream)
{
	SBCheckError(TMemoryStream_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TMemoryStream::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TMemoryStream_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

SB_INLINE void TMemoryStream::SetSize(int32_t NewSize)
{
	SBCheckError(TMemoryStream_SetSize(_Handle, NewSize));
}

SB_INLINE int32_t TMemoryStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TMemoryStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

TMemoryStream::TMemoryStream(TMemoryStreamHandle handle, TElOwnHandle ownHandle) : TCustomMemoryStream(handle, ownHandle)
{
}

TMemoryStream::TMemoryStream() : TCustomMemoryStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TMemoryStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TMEMORYSTREAM */

#ifdef SB_USE_CLASS_TSTRINGS

SB_INLINE int32_t TStrings::Add(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TStrings_Add(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::AddObject(const std::string &S, TObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TStrings_AddObject(_Handle, S.data(), (int32_t)S.length(), AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::AddObject(const std::string &S, TObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TStrings_AddObject(_Handle, S.data(), (int32_t)S.length(), (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::Append(const std::string &S)
{
	SBCheckError(TStrings_Append(_Handle, S.data(), (int32_t)S.length()));
}

SB_INLINE void TStrings::AddStrings(TStrings &TheStrings)
{
	SBCheckError(TStrings_AddStrings(_Handle, TheStrings.getHandle()));
}

SB_INLINE void TStrings::AddStrings(TStrings *TheStrings)
{
	SBCheckError(TStrings_AddStrings(_Handle, (TheStrings != NULL) ? TheStrings->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TStrings::Assign(TPersistent &Source)
{
	SBCheckError(TStrings_Assign(_Handle, Source.getHandle()));
}

SB_INLINE void TStrings::Assign(TPersistent *Source)
{
	SBCheckError(TStrings_Assign(_Handle, (Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TStrings::BeginUpdate()
{
	SBCheckError(TStrings_BeginUpdate(_Handle));
}

SB_INLINE void TStrings::Clear()
{
	SBCheckError(TStrings_Clear(_Handle));
}

SB_INLINE void TStrings::Delete(int32_t Index)
{
	SBCheckError(TStrings_Delete(_Handle, Index));
}

SB_INLINE void TStrings::EndUpdate()
{
	SBCheckError(TStrings_EndUpdate(_Handle));
}

bool TStrings::Equals(TStrings &TheStrings)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStrings_Equals(_Handle, TheStrings.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TStrings::Equals(TStrings *TheStrings)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStrings_Equals(_Handle, (TheStrings != NULL) ? TheStrings->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TStrings::Exchange(int32_t Index1, int32_t Index2)
{
	SBCheckError(TStrings_Exchange(_Handle, Index1, Index2));
}

SB_INLINE char * TStrings::GetText()
{
	char * OutResult;
	SBCheckError(TStrings_GetText(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::IndexOf(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TStrings_IndexOf(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::IndexOfName(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(TStrings_IndexOfName(_Handle, Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::IndexOfObject(TObject &AObject)
{
	int32_t OutResult;
	SBCheckError(TStrings_IndexOfObject(_Handle, AObject.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TStrings::IndexOfObject(TObject *AObject)
{
	int32_t OutResult;
	SBCheckError(TStrings_IndexOfObject(_Handle, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::Insert(int32_t Index, const std::string &S)
{
	SBCheckError(TStrings_Insert(_Handle, Index, S.data(), (int32_t)S.length()));
}

SB_INLINE void TStrings::InsertObject(int32_t Index, const std::string &S, TObject &AObject)
{
	SBCheckError(TStrings_InsertObject(_Handle, Index, S.data(), (int32_t)S.length(), AObject.getHandle()));
}

SB_INLINE void TStrings::InsertObject(int32_t Index, const std::string &S, TObject *AObject)
{
	SBCheckError(TStrings_InsertObject(_Handle, Index, S.data(), (int32_t)S.length(), (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE));
}

SB_INLINE void TStrings::LoadFromFile(const std::string &FileName)
{
	SBCheckError(TStrings_LoadFromFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TStrings::LoadFromStream(TStream &Stream)
{
	SBCheckError(TStrings_LoadFromStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TStrings::LoadFromStream(TStream *Stream)
{
	SBCheckError(TStrings_LoadFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TStrings::Move(int32_t CurIndex, int32_t NewIndex)
{
	SBCheckError(TStrings_Move(_Handle, CurIndex, NewIndex));
}

SB_INLINE void TStrings::SaveToFile(const std::string &FileName)
{
	SBCheckError(TStrings_SaveToFile(_Handle, FileName.data(), (int32_t)FileName.length()));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TStrings::SaveToStream(TStream &Stream)
{
	SBCheckError(TStrings_SaveToStream(_Handle, Stream.getHandle()));
}

SB_INLINE void TStrings::SaveToStream(TStream *Stream)
{
	SBCheckError(TStrings_SaveToStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE void TStrings::SetText(char * TheText)
{
	SBCheckError(TStrings_SetText(_Handle, TheText));
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void TStrings::GetNameValue(int32_t Index, std::string &AName, std::string &AValue)
{
	int32_t szAName = (int32_t)AName.length();
	int32_t szAValue = (int32_t)AValue.length();
	uint32_t _err = TStrings_GetNameValue(_Handle, Index, (char *)AName.data(), &szAName, (char *)AValue.data(), &szAValue);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		AName.resize(szAName);
		SBCheckError(SBGetLastReturnStringA(270557200, 2, (char *)AName.data(), &szAName));
		AValue.resize(szAValue);
		SBCheckError(SBGetLastReturnStringA(270557200, 3, (char *)AValue.data(), &szAValue));
	}
	else
		SBCheckError(_err);

	AName.resize(szAName);
	AValue.resize(szAValue);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void TStrings::ExtractName(const std::string &S, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_ExtractName(_Handle, S.data(), (int32_t)S.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1966447779, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
TTextLineBreakStyle TStrings::get_TextLineBreakStyle()
{
	TTextLineBreakStyleRaw OutResultRaw = 0;
	SBCheckError(TStrings_get_TextLineBreakStyle(_Handle, &OutResultRaw));
	return (TTextLineBreakStyle)OutResultRaw;
}

SB_INLINE void TStrings::set_TextLineBreakStyle(TTextLineBreakStyle Value)
{
	SBCheckError(TStrings_set_TextLineBreakStyle(_Handle, (TTextLineBreakStyleRaw)Value));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

SB_INLINE char TStrings::get_Delimiter()
{
	char OutResult;
	SBCheckError(TStrings_get_Delimiter(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::set_Delimiter(char Value)
{
	SBCheckError(TStrings_set_Delimiter(_Handle, Value));
}

void TStrings::get_DelimitedText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_DelimitedText(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(2129710752, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_DelimitedText(const std::string &Value)
{
	SBCheckError(TStrings_set_DelimitedText(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
bool TStrings::get_StrictDelimiter()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStrings_get_StrictDelimiter(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TStrings::set_StrictDelimiter(bool Value)
{
	SBCheckError(TStrings_set_StrictDelimiter(_Handle, (int8_t)Value));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

SB_INLINE char TStrings::get_QuoteChar()
{
	char OutResult;
	SBCheckError(TStrings_get_QuoteChar(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::set_QuoteChar(char Value)
{
	SBCheckError(TStrings_set_QuoteChar(_Handle, Value));
}

SB_INLINE char TStrings::get_NameValueSeparator()
{
	char OutResult;
	SBCheckError(TStrings_get_NameValueSeparator(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::set_NameValueSeparator(char Value)
{
	SBCheckError(TStrings_set_NameValueSeparator(_Handle, Value));
}

void TStrings::get_ValueFromIndex(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_ValueFromIndex(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1510370980, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_ValueFromIndex(int32_t Index, const std::string &Value)
{
	SBCheckError(TStrings_set_ValueFromIndex(_Handle, Index, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TStrings::get_Capacity()
{
	int32_t OutResult;
	SBCheckError(TStrings_get_Capacity(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TStrings::set_Capacity(int32_t Value)
{
	SBCheckError(TStrings_set_Capacity(_Handle, Value));
}

void TStrings::get_CommaText(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_CommaText(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(525737204, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_CommaText(const std::string &Value)
{
	SBCheckError(TStrings_set_CommaText(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int32_t TStrings::get_Count()
{
	int32_t OutResult;
	SBCheckError(TStrings_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TStrings::get_Names(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_Names(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1975535806, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TObject* TStrings::get_Objects(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TStrings_get_Objects(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Objects)
		this->_Inst_Objects = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_Objects->updateHandle(hOutResult);
	return this->_Inst_Objects;
}

SB_INLINE void TStrings::set_Objects(int32_t Index, TObject &AObject)
{
	SBCheckError(TStrings_set_Objects(_Handle, Index, AObject.getHandle()));
}

SB_INLINE void TStrings::set_Objects(int32_t Index, TObject *AObject)
{
	SBCheckError(TStrings_set_Objects(_Handle, Index, (AObject != NULL) ? AObject->getHandle() : SB_NULL_HANDLE));
}

void TStrings::get_Values(const std::string &Name, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_Values(_Handle, Name.data(), (int32_t)Name.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1478360830, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_Values(const std::string &Name, const std::string &Value)
{
	SBCheckError(TStrings_set_Values(_Handle, Name.data(), (int32_t)Name.length(), Value.data(), (int32_t)Value.length()));
}

void TStrings::get_Strings(int32_t Index, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_Strings(_Handle, Index, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(181721504, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_Strings(int32_t Index, const std::string &S)
{
	SBCheckError(TStrings_set_Strings(_Handle, Index, S.data(), (int32_t)S.length()));
}

void TStrings::get_Text(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TStrings_get_Text(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1043818127, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TStrings::set_Text(const std::string &Value)
{
	SBCheckError(TStrings_set_Text(_Handle, Value.data(), (int32_t)Value.length()));
}

void TStrings::initInstances()
{
	this->_Inst_Objects = NULL;
}

TStrings::TStrings(TStringsHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TStrings::TStrings() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TStrings_Create(&_Handle));
}

TStrings::~TStrings()
{
	delete this->_Inst_Objects;
	this->_Inst_Objects = NULL;
}
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGLIST

SB_INLINE int32_t TStringList::Add(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TStringList_Add(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TStringList::Clear()
{
	SBCheckError(TStringList_Clear(_Handle));
}

SB_INLINE void TStringList::Delete(int32_t Index)
{
	SBCheckError(TStringList_Delete(_Handle, Index));
}

SB_INLINE void TStringList::Exchange(int32_t Index1, int32_t Index2)
{
	SBCheckError(TStringList_Exchange(_Handle, Index1, Index2));
}

bool TStringList::Find(const std::string &S, int32_t &Index)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStringList_Find(_Handle, S.data(), (int32_t)S.length(), &Index, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TStringList::IndexOf(const std::string &S)
{
	int32_t OutResult;
	SBCheckError(TStringList_IndexOf(_Handle, S.data(), (int32_t)S.length(), &OutResult));
	return OutResult;
}

SB_INLINE void TStringList::Insert(int32_t Index, const std::string &S)
{
	SBCheckError(TStringList_Insert(_Handle, Index, S.data(), (int32_t)S.length()));
}

SB_INLINE void TStringList::Sort()
{
	SBCheckError(TStringList_Sort(_Handle));
}

SB_INLINE void TStringList::CustomSort(void * CompareFn)
{
	SBCheckError(TStringList_CustomSort(_Handle, CompareFn));
}

TDuplicates TStringList::get_Duplicates()
{
	TDuplicatesRaw OutResultRaw = 0;
	SBCheckError(TStringList_get_Duplicates(_Handle, &OutResultRaw));
	return (TDuplicates)OutResultRaw;
}

SB_INLINE void TStringList::set_Duplicates(TDuplicates Value)
{
	SBCheckError(TStringList_set_Duplicates(_Handle, (TDuplicatesRaw)Value));
}

bool TStringList::get_Sorted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStringList_get_Sorted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TStringList::set_Sorted(bool Value)
{
	SBCheckError(TStringList_set_Sorted(_Handle, (int8_t)Value));
}

bool TStringList::get_CaseSensitive()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TStringList_get_CaseSensitive(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TStringList::set_CaseSensitive(bool Value)
{
	SBCheckError(TStringList_set_CaseSensitive(_Handle, (int8_t)Value));
}

SB_INLINE void TStringList::get_OnChange(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TStringList_get_OnChange(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TStringList::set_OnChange(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TStringList_set_OnChange(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TStringList::get_OnChanging(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TStringList_get_OnChanging(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TStringList::set_OnChanging(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TStringList_set_OnChanging(_Handle, pMethodValue, pDataValue));
}

TStringList::TStringList(TStringListHandle handle, TElOwnHandle ownHandle) : TStrings(handle, ownHandle)
{
}

TStringList::TStringList() : TStrings(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TStringList_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TTHREAD

SB_INLINE void TThread::Synchronize(TThread &AThread, TThreadMethod pMethodAMethod, void * pDataAMethod)
{
	SBCheckError(TThread_Synchronize(AThread.getHandle(), pMethodAMethod, pDataAMethod));
}

SB_INLINE void TThread::Synchronize(TThread *AThread, TThreadMethod pMethodAMethod, void * pDataAMethod)
{
	SBCheckError(TThread_Synchronize((AThread != NULL) ? AThread->getHandle() : SB_NULL_HANDLE, pMethodAMethod, pDataAMethod));
}

SB_INLINE void TThread::Synchronize_Inst(TThread &AThread, TThreadMethod pMethodAMethod, void * pDataAMethod)
{
	SBCheckError(TThread_Synchronize_1(_Handle, AThread.getHandle(), pMethodAMethod, pDataAMethod));
}

SB_INLINE void TThread::Synchronize_Inst(TThread *AThread, TThreadMethod pMethodAMethod, void * pDataAMethod)
{
	SBCheckError(TThread_Synchronize_1(_Handle, (AThread != NULL) ? AThread->getHandle() : SB_NULL_HANDLE, pMethodAMethod, pDataAMethod));
}

SB_INLINE void TThread::AfterConstruction()
{
	SBCheckError(TThread_AfterConstruction(_Handle));
}

SB_INLINE void TThread::Resume()
{
	SBCheckError(TThread_Resume(_Handle));
}

SB_INLINE void TThread::Suspend()
{
	SBCheckError(TThread_Suspend(_Handle));
}

SB_INLINE void TThread::Terminate()
{
	SBCheckError(TThread_Terminate(_Handle));
}

SB_INLINE int32_t TThread::WaitFor()
{
	int32_t OutResult;
	SBCheckError(TThread_WaitFor(_Handle, &OutResult));
	return OutResult;
}

bool TThread::get_FreeOnTerminate()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TThread_get_FreeOnTerminate(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TThread::set_FreeOnTerminate(bool Value)
{
	SBCheckError(TThread_set_FreeOnTerminate(_Handle, (int8_t)Value));
}

TThreadPriority TThread::get_Priority()
{
	TThreadPriorityRaw OutResultRaw = 0;
	SBCheckError(TThread_get_Priority(_Handle, &OutResultRaw));
	return (TThreadPriority)OutResultRaw;
}

SB_INLINE void TThread::set_Priority(TThreadPriority Value)
{
	SBCheckError(TThread_set_Priority(_Handle, (TThreadPriorityRaw)Value));
}

bool TThread::get_Suspended()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TThread_get_Suspended(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TThread::set_Suspended(bool Value)
{
	SBCheckError(TThread_set_Suspended(_Handle, (int8_t)Value));
}

TObject* TThread::get_FatalException()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TThread_get_FatalException(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_FatalException)
		this->_Inst_FatalException = new TObject(hOutResult, ohFalse);
	else
		this->_Inst_FatalException->updateHandle(hOutResult);
	return this->_Inst_FatalException;
}

SB_INLINE void TThread::get_OnTerminate(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TThread_get_OnTerminate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TThread::set_OnTerminate(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TThread_set_OnTerminate(_Handle, pMethodValue, pDataValue));
}

void TThread::initInstances()
{
	this->_Inst_FatalException = NULL;
}

TThread::TThread(TThreadHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
TThread::TThread(bool CreateSuspended, uint32_t StackSize) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TThread_Create((int8_t)CreateSuspended, StackSize, &_Handle));
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

TThread::~TThread()
{
	delete this->_Inst_FatalException;
	this->_Inst_FatalException = NULL;
}
#endif /* SB_USE_CLASS_TTHREAD */

};	/* namespace SecureBlackbox */

