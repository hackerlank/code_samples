#include "sbbzip2utils.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TSBDATAARRAY

SB_INLINE int64_t TSBDataArray::GetArrayData(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TSBDataArray_GetArrayData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBDataArray::SetArrayData(int64_t Data, int32_t Index)
{
	SBCheckError(TSBDataArray_SetArrayData(_Handle, Data, Index));
}

TSBDataArray::TSBDataArray(TSBDataArrayHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TSBDataArray::TSBDataArray(int32_t Len) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBDataArray_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEDATAARRAY

SB_INLINE uint8_t TSBByteDataArray::GetArrayData(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TSBByteDataArray_GetArrayData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBByteDataArray::SetArrayData(uint8_t Data, int32_t Index)
{
	SBCheckError(TSBByteDataArray_SetArrayData(_Handle, Data, Index));
}

TSBByteDataArray::TSBByteDataArray(TSBByteDataArrayHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TSBByteDataArray::TSBByteDataArray(int32_t Len) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteDataArray_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBBYTEDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEARRAY

SB_INLINE uint8_t TSBByteArray::GetData(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TSBByteArray_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBByteArray::SetData(uint8_t Data, int32_t Index)
{
	SBCheckError(TSBByteArray_SetData(_Handle, Data, Index));
}

TSBByteArray::TSBByteArray(TSBByteArrayHandle handle, TElOwnHandle ownHandle) : TSBDataArray(handle, ownHandle)
{
}

TSBByteArray::TSBByteArray(int32_t Len) : TSBDataArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteArray_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#ifdef SB_USE_CLASS_TSBINT16ARRAY

SB_INLINE int16_t TSBInt16Array::GetData(int32_t Index)
{
	int16_t OutResult;
	SBCheckError(TSBInt16Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBInt16Array::SetData(int16_t Data, int32_t Index)
{
	SBCheckError(TSBInt16Array_SetData(_Handle, Data, Index));
}

TSBInt16Array::TSBInt16Array(TSBInt16ArrayHandle handle, TElOwnHandle ownHandle) : TSBDataArray(handle, ownHandle)
{
}

TSBInt16Array::TSBInt16Array(int32_t Len) : TSBDataArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBInt16Array_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBINT16ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ARRAY

SB_INLINE uint16_t TSBUInt16Array::GetData(int32_t Index)
{
	uint16_t OutResult;
	SBCheckError(TSBUInt16Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBUInt16Array::SetData(uint16_t Data, int32_t Index)
{
	SBCheckError(TSBUInt16Array_SetData(_Handle, Data, Index));
}

TSBUInt16Array::TSBUInt16Array(TSBUInt16ArrayHandle handle, TElOwnHandle ownHandle) : TSBDataArray(handle, ownHandle)
{
}

TSBUInt16Array::TSBUInt16Array(int32_t Len) : TSBDataArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt16Array_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBUINT16ARRAY */

#ifdef SB_USE_CLASS_TSBINT32ARRAY

SB_INLINE int32_t TSBInt32Array::GetData(int32_t Index)
{
	int32_t OutResult;
	SBCheckError(TSBInt32Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBInt32Array::SetData(int32_t Data, int32_t Index)
{
	SBCheckError(TSBInt32Array_SetData(_Handle, Data, Index));
}

TSBInt32Array::TSBInt32Array(TSBInt32ArrayHandle handle, TElOwnHandle ownHandle) : TSBDataArray(handle, ownHandle)
{
}

TSBInt32Array::TSBInt32Array(int32_t Len) : TSBDataArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBInt32Array_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT32ARRAY

SB_INLINE uint32_t TSBUInt32Array::GetData(int32_t Index)
{
	uint32_t OutResult;
	SBCheckError(TSBUInt32Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBUInt32Array::SetData(uint32_t Data, int32_t Index)
{
	SBCheckError(TSBUInt32Array_SetData(_Handle, Data, Index));
}

TSBUInt32Array::TSBUInt32Array(TSBUInt32ArrayHandle handle, TElOwnHandle ownHandle) : TSBDataArray(handle, ownHandle)
{
}

TSBUInt32Array::TSBUInt32Array(int32_t Len) : TSBDataArray(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt32Array_Create(Len, &_Handle));
}

#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONBYTEARRAY

SB_INLINE uint16_t TSBUInt16onByteArray::GetData(int32_t Index)
{
	uint16_t OutResult;
	SBCheckError(TSBUInt16onByteArray_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBUInt16onByteArray::SetData(uint16_t Data, int32_t Index)
{
	SBCheckError(TSBUInt16onByteArray_SetData(_Handle, Data, Index));
}

TSBUInt16onByteArray::TSBUInt16onByteArray(TSBUInt16onByteArrayHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBBYTEARRAY
TSBUInt16onByteArray::TSBUInt16onByteArray(TSBByteArray &Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt16onByteArray_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBUInt16onByteArray::TSBUInt16onByteArray(TSBByteArray *Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt16onByteArray_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#endif /* SB_USE_CLASS_TSBUINT16ONBYTEARRAY */

#ifdef SB_USE_CLASS_TSBBYTEONUINT32ARRAY

SB_INLINE uint8_t TSBByteonUInt32Array::GetData(int32_t Index)
{
	uint8_t OutResult;
	SBCheckError(TSBByteonUInt32Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBByteonUInt32Array::SetData(uint8_t Data, int32_t Index)
{
	SBCheckError(TSBByteonUInt32Array_SetData(_Handle, Data, Index));
}

TSBByteonUInt32Array::TSBByteonUInt32Array(TSBByteonUInt32ArrayHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
TSBByteonUInt32Array::TSBByteonUInt32Array(TSBUInt32Array &Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteonUInt32Array_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBByteonUInt32Array::TSBByteonUInt32Array(TSBUInt32Array *Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteonUInt32Array_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

#endif /* SB_USE_CLASS_TSBBYTEONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONUINT32ARRAY

SB_INLINE uint16_t TSBUInt16onUInt32Array::GetData(int32_t Index)
{
	uint16_t OutResult;
	SBCheckError(TSBUInt16onUInt32Array_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE void TSBUInt16onUInt32Array::SetData(uint16_t Data, int32_t Index)
{
	SBCheckError(TSBUInt16onUInt32Array_SetData(_Handle, Data, Index));
}

TSBUInt16onUInt32Array::TSBUInt16onUInt32Array(TSBUInt16onUInt32ArrayHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
TSBUInt16onUInt32Array::TSBUInt16onUInt32Array(TSBUInt32Array &Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt16onUInt32Array_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBUInt16onUInt32Array::TSBUInt16onUInt32Array(TSBUInt32Array *Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt16onUInt32Array_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

#endif /* SB_USE_CLASS_TSBUINT16ONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBARRAYPOINTER

SB_INLINE void TSBArrayPointer::SetData(int64_t Data, int32_t Index)
{
	SBCheckError(TSBArrayPointer_SetData(_Handle, Data, Index));
}

SB_INLINE void TSBArrayPointer::IncOffset(int32_t Index)
{
	SBCheckError(TSBArrayPointer_IncOffset(_Handle, Index));
}

SB_INLINE void TSBArrayPointer::SetOffset(int32_t Index)
{
	SBCheckError(TSBArrayPointer_SetOffset(_Handle, Index));
}

SB_INLINE int64_t TSBArrayPointer::GetData(int32_t Index)
{
	int64_t OutResult;
	SBCheckError(TSBArrayPointer_GetData(_Handle, Index, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TSBArrayPointer::GetAtPtr()
{
	int64_t OutResult;
	SBCheckError(TSBArrayPointer_GetAtPtr(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TSBArrayPointer::SetAtPtr(int64_t Data)
{
	SBCheckError(TSBArrayPointer_SetAtPtr(_Handle, Data));
}

TSBArrayPointer::TSBArrayPointer(TSBArrayPointerHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBDATAARRAY
TSBArrayPointer::TSBArrayPointer(TSBDataArray &Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBArrayPointer_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBArrayPointer::TSBArrayPointer(TSBDataArray *Base, const std::string &ParentName) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBArrayPointer_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#endif /* SB_USE_CLASS_TSBARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBINT32ARRAYPOINTER

SB_INLINE void TSBInt32ArrayPointer::SetData(int32_t Data, int32_t Index)
{
	SBCheckError(TSBInt32ArrayPointer_SetData(_Handle, Data, Index));
}

SB_INLINE void TSBInt32ArrayPointer::GetData(int32_t Index, int32_t &OutResult)
{
	SBCheckError(TSBInt32ArrayPointer_GetData(_Handle, Index, &OutResult));
}

SB_INLINE void TSBInt32ArrayPointer::GetAtPtr(int32_t &OutResult)
{
	SBCheckError(TSBInt32ArrayPointer_GetAtPtr(_Handle, &OutResult));
}

SB_INLINE void TSBInt32ArrayPointer::SetAtPtr(int32_t Data)
{
	SBCheckError(TSBInt32ArrayPointer_SetAtPtr(_Handle, Data));
}

TSBInt32ArrayPointer::TSBInt32ArrayPointer(TSBInt32ArrayPointerHandle handle, TElOwnHandle ownHandle) : TSBArrayPointer(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBDATAARRAY
TSBInt32ArrayPointer::TSBInt32ArrayPointer(TSBDataArray &Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBInt32ArrayPointer_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBInt32ArrayPointer::TSBInt32ArrayPointer(TSBDataArray *Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBInt32ArrayPointer_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#endif /* SB_USE_CLASS_TSBINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBUINT32ARRAYPOINTER

SB_INLINE void TSBUInt32ArrayPointer::SetData(uint32_t Data, int32_t Index)
{
	SBCheckError(TSBUInt32ArrayPointer_SetData(_Handle, Data, Index));
}

SB_INLINE void TSBUInt32ArrayPointer::GetData(int32_t Index, uint32_t &OutResult)
{
	SBCheckError(TSBUInt32ArrayPointer_GetData(_Handle, Index, &OutResult));
}

SB_INLINE void TSBUInt32ArrayPointer::GetAtPtr(uint32_t &OutResult)
{
	SBCheckError(TSBUInt32ArrayPointer_GetAtPtr(_Handle, &OutResult));
}

SB_INLINE void TSBUInt32ArrayPointer::SetAtPtr(uint32_t Data)
{
	SBCheckError(TSBUInt32ArrayPointer_SetAtPtr(_Handle, Data));
}

TSBUInt32ArrayPointer::TSBUInt32ArrayPointer(TSBUInt32ArrayPointerHandle handle, TElOwnHandle ownHandle) : TSBArrayPointer(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBDATAARRAY
TSBUInt32ArrayPointer::TSBUInt32ArrayPointer(TSBDataArray &Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt32ArrayPointer_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBUInt32ArrayPointer::TSBUInt32ArrayPointer(TSBDataArray *Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBUInt32ArrayPointer_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#endif /* SB_USE_CLASS_TSBUINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBBYTEARRAYPOINTER

SB_INLINE void TSBByteArrayPointer::SetData(uint8_t Data, int32_t Index)
{
	SBCheckError(TSBByteArrayPointer_SetData(_Handle, Data, Index));
}

SB_INLINE void TSBByteArrayPointer::GetData(int32_t Index, uint8_t &OutResult)
{
	SBCheckError(TSBByteArrayPointer_GetData(_Handle, Index, &OutResult));
}

SB_INLINE void TSBByteArrayPointer::GetAtPtr(uint8_t &OutResult)
{
	SBCheckError(TSBByteArrayPointer_GetAtPtr(_Handle, &OutResult));
}

TSBByteArrayPointer::TSBByteArrayPointer(TSBByteArrayPointerHandle handle, TElOwnHandle ownHandle) : TSBArrayPointer(handle, ownHandle)
{
}

#ifdef SB_USE_CLASS_TSBDATAARRAY
TSBByteArrayPointer::TSBByteArrayPointer(TSBDataArray &Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteArrayPointer_Create(Base.getHandle(), ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}

TSBByteArrayPointer::TSBByteArrayPointer(TSBDataArray *Base, const std::string &ParentName) : TSBArrayPointer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TSBByteArrayPointer_Create((Base != NULL) ? Base->getHandle() : SB_NULL_HANDLE, ParentName.data(), (int32_t)ParentName.length(), &_Handle));
}
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#endif /* SB_USE_CLASS_TSBBYTEARRAYPOINTER */

#ifdef SB_USE_GLOBAL_PROCS_BZIP2UTILS

SB_INLINE int32_t IfThenInt(bool AValue, int32_t ATrue, int32_t AFalse)
{
	int32_t OutResult;
	SBCheckError(SBBzip2Utils_IfThenInt((int8_t)AValue, ATrue, AFalse, &OutResult));
	return OutResult;
}

SB_INLINE int64_t IfThenInt64(bool AValue, int64_t ATrue, int64_t AFalse)
{
	int64_t OutResult;
	SBCheckError(SBBzip2Utils_IfThenInt64((int8_t)AValue, ATrue, AFalse, &OutResult));
	return OutResult;
}

SB_INLINE double IfThenDouble(bool AValue, double ATrue, double AFalse)
{
	double OutResult;
	SBCheckError(SBBzip2Utils_IfThenDouble((int8_t)AValue, ATrue, AFalse, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t IfThenUInt32(bool AValue, uint32_t ATrue, uint32_t AFalse)
{
	uint32_t OutResult;
	SBCheckError(SBBzip2Utils_IfThenUInt32((int8_t)AValue, ATrue, AFalse, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_BZIP2UTILS */

};	/* namespace SecureBlackbox */

