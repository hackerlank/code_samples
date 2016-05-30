#ifndef __INC_SBBZIP2UTILS
#define __INC_SBBZIP2UTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbbzip2basetypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TSBDataArrayHandle;

typedef TElClassHandle TSBByteDataArrayHandle;

typedef TElClassHandle TSBByteArrayHandle;

typedef TElClassHandle TSBInt16ArrayHandle;

typedef TElClassHandle TSBUInt16ArrayHandle;

typedef TElClassHandle TSBInt32ArrayHandle;

typedef TElClassHandle TSBUInt32ArrayHandle;

typedef TElClassHandle TSBUInt16onByteArrayHandle;

typedef TElClassHandle TSBByteonUInt32ArrayHandle;

typedef TElClassHandle TSBUInt16onUInt32ArrayHandle;

typedef TElClassHandle TSBArrayPointerHandle;

typedef TElClassHandle TSBInt32ArrayPointerHandle;

typedef TElClassHandle TSBUInt32ArrayPointerHandle;

typedef TElClassHandle TSBByteArrayPointerHandle;

#ifdef SB_USE_CLASS_TSBDATAARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBDataArray_GetArrayData(TSBDataArrayHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBDataArray_SetArrayData(TSBDataArrayHandle _Handle, int64_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBDataArray_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEDATAARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBByteDataArray_GetArrayData(TSBByteDataArrayHandle _Handle, int32_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBByteDataArray_SetArrayData(TSBByteDataArrayHandle _Handle, uint8_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBByteDataArray_Create(int32_t Len, TSBByteDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBBYTEDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBByteArray_GetData(TSBByteArrayHandle _Handle, int32_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBByteArray_SetData(TSBByteArrayHandle _Handle, uint8_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBByteArray_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#ifdef SB_USE_CLASS_TSBINT16ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBInt16Array_GetData(TSBInt16ArrayHandle _Handle, int32_t Index, int16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBInt16Array_SetData(TSBInt16ArrayHandle _Handle, int16_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBInt16Array_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBINT16ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16Array_GetData(TSBUInt16ArrayHandle _Handle, int32_t Index, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16Array_SetData(TSBUInt16ArrayHandle _Handle, uint16_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16Array_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBUINT16ARRAY */

#ifdef SB_USE_CLASS_TSBINT32ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBInt32Array_GetData(TSBInt32ArrayHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32Array_SetData(TSBInt32ArrayHandle _Handle, int32_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32Array_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32Array_GetData(TSBUInt32ArrayHandle _Handle, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32Array_SetData(TSBUInt32ArrayHandle _Handle, uint32_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32Array_Create(int32_t Len, TSBDataArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONBYTEARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onByteArray_GetData(TSBUInt16onByteArrayHandle _Handle, int32_t Index, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onByteArray_SetData(TSBUInt16onByteArrayHandle _Handle, uint16_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onByteArray_Create(TSBByteArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBUInt16onByteArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBUINT16ONBYTEARRAY */

#ifdef SB_USE_CLASS_TSBBYTEONUINT32ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBByteonUInt32Array_GetData(TSBByteonUInt32ArrayHandle _Handle, int32_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBByteonUInt32Array_SetData(TSBByteonUInt32ArrayHandle _Handle, uint8_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBByteonUInt32Array_Create(TSBUInt32ArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBByteonUInt32ArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBBYTEONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONUINT32ARRAY
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onUInt32Array_GetData(TSBUInt16onUInt32ArrayHandle _Handle, int32_t Index, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onUInt32Array_SetData(TSBUInt16onUInt32ArrayHandle _Handle, uint16_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt16onUInt32Array_Create(TSBUInt32ArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBUInt16onUInt32ArrayHandle * OutResult);
#endif /* SB_USE_CLASS_TSBUINT16ONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBARRAYPOINTER
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_SetData(TSBArrayPointerHandle _Handle, int64_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_IncOffset(TSBArrayPointerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_SetOffset(TSBArrayPointerHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_GetData(TSBArrayPointerHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_GetAtPtr(TSBArrayPointerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_SetAtPtr(TSBArrayPointerHandle _Handle, int64_t Data);
SB_IMPORT uint32_t SB_APIENTRY TSBArrayPointer_Create(TSBDataArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBArrayPointerHandle * OutResult);
#endif /* SB_USE_CLASS_TSBARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBINT32ARRAYPOINTER
SB_IMPORT uint32_t SB_APIENTRY TSBInt32ArrayPointer_SetData(TSBInt32ArrayPointerHandle _Handle, int32_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32ArrayPointer_GetData(TSBInt32ArrayPointerHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32ArrayPointer_GetAtPtr(TSBInt32ArrayPointerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32ArrayPointer_SetAtPtr(TSBInt32ArrayPointerHandle _Handle, int32_t Data);
SB_IMPORT uint32_t SB_APIENTRY TSBInt32ArrayPointer_Create(TSBDataArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBArrayPointerHandle * OutResult);
#endif /* SB_USE_CLASS_TSBINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBUINT32ARRAYPOINTER
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32ArrayPointer_SetData(TSBUInt32ArrayPointerHandle _Handle, uint32_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32ArrayPointer_GetData(TSBUInt32ArrayPointerHandle _Handle, int32_t Index, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32ArrayPointer_GetAtPtr(TSBUInt32ArrayPointerHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32ArrayPointer_SetAtPtr(TSBUInt32ArrayPointerHandle _Handle, uint32_t Data);
SB_IMPORT uint32_t SB_APIENTRY TSBUInt32ArrayPointer_Create(TSBDataArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBArrayPointerHandle * OutResult);
#endif /* SB_USE_CLASS_TSBUINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBBYTEARRAYPOINTER
SB_IMPORT uint32_t SB_APIENTRY TSBByteArrayPointer_SetData(TSBByteArrayPointerHandle _Handle, uint8_t Data, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TSBByteArrayPointer_GetData(TSBByteArrayPointerHandle _Handle, int32_t Index, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBByteArrayPointer_GetAtPtr(TSBByteArrayPointerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TSBByteArrayPointer_Create(TSBDataArrayHandle Base, const char * pcParentName, int32_t szParentName, TSBArrayPointerHandle * OutResult);
#endif /* SB_USE_CLASS_TSBBYTEARRAYPOINTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TSBDataArray;
class TSBByteDataArray;
class TSBByteArray;
class TSBInt16Array;
class TSBUInt16Array;
class TSBInt32Array;
class TSBUInt32Array;
class TSBUInt16onByteArray;
class TSBByteonUInt32Array;
class TSBUInt16onUInt32Array;
class TSBArrayPointer;
class TSBInt32ArrayPointer;
class TSBUInt32ArrayPointer;
class TSBByteArrayPointer;

#ifdef SB_USE_CLASS_TSBDATAARRAY
class TSBDataArray: public TObject
{
	private:
		SB_DISABLE_COPY(TSBDataArray)
	public:
		int64_t GetArrayData(int32_t Index);

		void SetArrayData(int64_t Data, int32_t Index);

		TSBDataArray(TSBDataArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBDataArray(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEDATAARRAY
class TSBByteDataArray: public TObject
{
	private:
		SB_DISABLE_COPY(TSBByteDataArray)
	public:
		uint8_t GetArrayData(int32_t Index);

		void SetArrayData(uint8_t Data, int32_t Index);

		TSBByteDataArray(TSBByteDataArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBByteDataArray(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBBYTEDATAARRAY */

#ifdef SB_USE_CLASS_TSBBYTEARRAY
class TSBByteArray: public TSBDataArray
{
	private:
		SB_DISABLE_COPY(TSBByteArray)
	public:
		uint8_t GetData(int32_t Index);

		void SetData(uint8_t Data, int32_t Index);

		TSBByteArray(TSBByteArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBByteArray(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

#ifdef SB_USE_CLASS_TSBINT16ARRAY
class TSBInt16Array: public TSBDataArray
{
	private:
		SB_DISABLE_COPY(TSBInt16Array)
	public:
		int16_t GetData(int32_t Index);

		void SetData(int16_t Data, int32_t Index);

		TSBInt16Array(TSBInt16ArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBInt16Array(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBINT16ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ARRAY
class TSBUInt16Array: public TSBDataArray
{
	private:
		SB_DISABLE_COPY(TSBUInt16Array)
	public:
		uint16_t GetData(int32_t Index);

		void SetData(uint16_t Data, int32_t Index);

		TSBUInt16Array(TSBUInt16ArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBUInt16Array(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBUINT16ARRAY */

#ifdef SB_USE_CLASS_TSBINT32ARRAY
class TSBInt32Array: public TSBDataArray
{
	private:
		SB_DISABLE_COPY(TSBInt32Array)
	public:
		int32_t GetData(int32_t Index);

		void SetData(int32_t Data, int32_t Index);

		TSBInt32Array(TSBInt32ArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBInt32Array(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
class TSBUInt32Array: public TSBDataArray
{
	private:
		SB_DISABLE_COPY(TSBUInt32Array)
	public:
		uint32_t GetData(int32_t Index);

		void SetData(uint32_t Data, int32_t Index);

		TSBUInt32Array(TSBUInt32ArrayHandle handle, TElOwnHandle ownHandle);

		explicit TSBUInt32Array(int32_t Len);

};
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONBYTEARRAY
class TSBUInt16onByteArray: public TObject
{
	private:
		SB_DISABLE_COPY(TSBUInt16onByteArray)
	public:
		uint16_t GetData(int32_t Index);

		void SetData(uint16_t Data, int32_t Index);

		TSBUInt16onByteArray(TSBUInt16onByteArrayHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBBYTEARRAY
		TSBUInt16onByteArray(TSBByteArray &Base, const std::string &ParentName);

		TSBUInt16onByteArray(TSBByteArray *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBBYTEARRAY */

};
#endif /* SB_USE_CLASS_TSBUINT16ONBYTEARRAY */

#ifdef SB_USE_CLASS_TSBBYTEONUINT32ARRAY
class TSBByteonUInt32Array: public TObject
{
	private:
		SB_DISABLE_COPY(TSBByteonUInt32Array)
	public:
		uint8_t GetData(int32_t Index);

		void SetData(uint8_t Data, int32_t Index);

		TSBByteonUInt32Array(TSBByteonUInt32ArrayHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
		TSBByteonUInt32Array(TSBUInt32Array &Base, const std::string &ParentName);

		TSBByteonUInt32Array(TSBUInt32Array *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

};
#endif /* SB_USE_CLASS_TSBBYTEONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBUINT16ONUINT32ARRAY
class TSBUInt16onUInt32Array: public TObject
{
	private:
		SB_DISABLE_COPY(TSBUInt16onUInt32Array)
	public:
		uint16_t GetData(int32_t Index);

		void SetData(uint16_t Data, int32_t Index);

		TSBUInt16onUInt32Array(TSBUInt16onUInt32ArrayHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBUINT32ARRAY
		TSBUInt16onUInt32Array(TSBUInt32Array &Base, const std::string &ParentName);

		TSBUInt16onUInt32Array(TSBUInt32Array *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBUINT32ARRAY */

};
#endif /* SB_USE_CLASS_TSBUINT16ONUINT32ARRAY */

#ifdef SB_USE_CLASS_TSBARRAYPOINTER
class TSBArrayPointer: public TObject
{
	private:
		SB_DISABLE_COPY(TSBArrayPointer)
	public:
		void SetData(int64_t Data, int32_t Index);

		void IncOffset(int32_t Index);

		void SetOffset(int32_t Index);

		int64_t GetData(int32_t Index);

		int64_t GetAtPtr();

		void SetAtPtr(int64_t Data);

		TSBArrayPointer(TSBArrayPointerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBDATAARRAY
		TSBArrayPointer(TSBDataArray &Base, const std::string &ParentName);

		TSBArrayPointer(TSBDataArray *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBDATAARRAY */

};
#endif /* SB_USE_CLASS_TSBARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBINT32ARRAYPOINTER
class TSBInt32ArrayPointer: public TSBArrayPointer
{
	private:
		SB_DISABLE_COPY(TSBInt32ArrayPointer)
	public:
		void SetData(int32_t Data, int32_t Index);

		void GetData(int32_t Index, int32_t &OutResult);

		void GetAtPtr(int32_t &OutResult);

		void SetAtPtr(int32_t Data);

		TSBInt32ArrayPointer(TSBInt32ArrayPointerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBDATAARRAY
		TSBInt32ArrayPointer(TSBDataArray &Base, const std::string &ParentName);

		TSBInt32ArrayPointer(TSBDataArray *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBDATAARRAY */

};
#endif /* SB_USE_CLASS_TSBINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBUINT32ARRAYPOINTER
class TSBUInt32ArrayPointer: public TSBArrayPointer
{
	private:
		SB_DISABLE_COPY(TSBUInt32ArrayPointer)
	public:
		void SetData(uint32_t Data, int32_t Index);

		void GetData(int32_t Index, uint32_t &OutResult);

		void GetAtPtr(uint32_t &OutResult);

		void SetAtPtr(uint32_t Data);

		TSBUInt32ArrayPointer(TSBUInt32ArrayPointerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBDATAARRAY
		TSBUInt32ArrayPointer(TSBDataArray &Base, const std::string &ParentName);

		TSBUInt32ArrayPointer(TSBDataArray *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBDATAARRAY */

};
#endif /* SB_USE_CLASS_TSBUINT32ARRAYPOINTER */

#ifdef SB_USE_CLASS_TSBBYTEARRAYPOINTER
class TSBByteArrayPointer: public TSBArrayPointer
{
	private:
		SB_DISABLE_COPY(TSBByteArrayPointer)
	public:
		void SetData(uint8_t Data, int32_t Index);

		void GetData(int32_t Index, uint8_t &OutResult);

		void GetAtPtr(uint8_t &OutResult);

		TSBByteArrayPointer(TSBByteArrayPointerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TSBDATAARRAY
		TSBByteArrayPointer(TSBDataArray &Base, const std::string &ParentName);

		TSBByteArrayPointer(TSBDataArray *Base, const std::string &ParentName);
#endif /* SB_USE_CLASS_TSBDATAARRAY */

};
#endif /* SB_USE_CLASS_TSBBYTEARRAYPOINTER */

#ifdef SB_USE_GLOBAL_PROCS_BZIP2UTILS

int32_t IfThenInt(bool AValue, int32_t ATrue, int32_t AFalse);

int64_t IfThenInt64(bool AValue, int64_t ATrue, int64_t AFalse);

double IfThenDouble(bool AValue, double ATrue, double AFalse);

uint32_t IfThenUInt32(bool AValue, uint32_t ATrue, uint32_t AFalse);

#endif /* SB_USE_GLOBAL_PROCS_BZIP2UTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_BZIP2UTILS
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Utils_IfThenInt(int8_t AValue, int32_t ATrue, int32_t AFalse, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Utils_IfThenInt64(int8_t AValue, int64_t ATrue, int64_t AFalse, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Utils_IfThenDouble(int8_t AValue, double ATrue, double AFalse, double * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBBzip2Utils_IfThenUInt32(int8_t AValue, uint32_t ATrue, uint32_t AFalse, uint32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_BZIP2UTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBBZIP2UTILS */

