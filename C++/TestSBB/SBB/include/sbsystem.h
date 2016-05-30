#ifndef __INC_SBSYSTEM
#define __INC_SBSYSTEM

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TObjectHandle;

typedef TElClassHandle TBitsHandle;

typedef TElClassHandle TPersistentHandle;

typedef TElClassHandle TStreamHandle;

typedef TElClassHandle THandleStreamHandle;

typedef TElClassHandle TFileStreamHandle;

typedef TElClassHandle TInterfacedObjectHandle;

typedef TElClassHandle TInterfacedPersistentHandle;

typedef TElClassHandle TListHandle;

typedef TElClassHandle TCustomMemoryStreamHandle;

typedef TElClassHandle TComponentHandle;

typedef TElClassHandle TMemoryStreamHandle;

typedef TElClassHandle TStringsHandle;

typedef TElClassHandle TStringListHandle;

typedef TElClassHandle TThreadHandle;

#pragma pack(4)
typedef struct 
{
#ifdef SB_WINDOWS
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} windows_FILETIME;
#else
	union
	{
		struct
		{
			uint32_t s_addr;
		} S1;
		struct
		{
			uint8_t s_bytes[4];
		} S2;
	};
} in_addr;
#endif

#ifdef SB_WINDOWS
#pragma pack(8)
#else
#pragma pack(4)
#endif
typedef struct 
{
	union
	{
		struct
		{
#ifdef SB_WINDOWS
			uint32_t LowPart;
			int32_t HighPart;
#else
			uint16_t sin_family;
			uint16_t sin_port;
			in_addr sin_addr;
			char xpad[8];
#endif
		} S1;
		struct
		{
#ifdef SB_WINDOWS
			int64_t QuadPart;
#else
			uint16_t family;
			uint16_t port;
			uint32_t addr;
			char pad[8];
#endif
		} S2;
	};
#ifdef SB_WINDOWS
} windows_LARGE_INTEGER;
#else
} sockaddr_in;
#endif

typedef uint8_t TByteArray[32768];

typedef TElClassHandle TClassHandle;

typedef uint32_t TDuplicatesRaw;

typedef enum
{
	dupIgnore = 0,
	dupAccept = 1,
	dupError = 2
} TDuplicates;

#pragma pack(4)
typedef struct 
{
	union
	{
		struct
		{
			uint32_t Data1;
			uint16_t Data2;
			uint16_t Data3;
			uint8_t Data4[8];
		} S1;
		struct
		{
			uint32_t D1;
			uint16_t D2;
			uint16_t D3;
			uint8_t D4[8];
		} S2;
		struct
		{
			uint32_t time_low;
			uint16_t time_mid;
			uint16_t time_hi_and_version;
			uint8_t clock_seq_hi_and_reserved;
			uint8_t clock_seq_low;
			uint8_t node[6];
		} S3;
	};
} TGuid;

typedef uint32_t TListAssignOpRaw;

typedef enum
{
	laCopy = 0,
	laAnd = 1,
	laOr = 2,
	laXor = 3,
	laSrcUnique = 4,
	laDestUnique = 5
} TListAssignOp;

typedef uint32_t TSeekOriginRaw;

typedef enum
{
	soBeginning = 0,
	soCurrent = 1,
	soEnd = 2
} TSeekOrigin;

typedef uint32_t TTextLineBreakStyleRaw;

typedef enum
{
	tlbsLF = 0,
	tlbsCRLF = 1,
	tlbsCR = 2
} TTextLineBreakStyle;

typedef uint32_t TThreadPriorityRaw;

typedef enum
{
	tpIdle = 0,
	tpLowest = 1,
	tpLower = 2,
	tpNormal = 3,
	tpHigher = 4,
	tpHighest = 5,
	tpTimeCritical = 6
} TThreadPriority;

#ifdef SB_WINDOWS
typedef int32_t * windows_PBOOL;

#endif
#ifndef LINUX
typedef uint8_t * System_PByte;
#endif

typedef TByteArray * PByteArray;

typedef char * PChar;

#ifdef SB_WINDOWS
typedef uint32_t * PDWord;
#else
typedef void * Pointer;
#endif

#ifdef SB_WINDOWS
typedef uint32_t * windows_PHANDLE;

typedef void * Pointer;

#else
typedef sockaddr_in * psockaddr_in;
#endif

typedef void * PString;

#ifdef SB_WINDOWS
typedef uint32_t * windows_PULONG;

#endif
#ifndef LINUX
typedef sb_char16_t * PWideChar;
#endif

typedef void * PWideString;

#ifdef SB_WINDOWS
typedef uint16_t * System_PWord;
#endif

typedef void (SB_CALLBACK *TListSortCompare)(void * Item1, void * Item2, int32_t * OutResult);

typedef void (SB_CALLBACK *TNotifyEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TStringListSortCompare)(TStringListHandle List, int32_t Index1, int32_t Index2, int32_t * OutResult);

typedef void (SB_CALLBACK *TThreadMethod)(void * _ObjectData);

#ifdef SB_USE_CLASS_TOBJECT
SB_IMPORT uint32_t SB_APIENTRY TObject_Free(TObjectHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TObject_ClassType(TObjectHandle _Handle, TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_ClassName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_ClassName_1(TObjectHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_ClassNameIs(const char * pcname, int32_t szname, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_ClassNameIs_1(TObjectHandle _Handle, const char * pcname, int32_t szname, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_InstanceSize(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_InstanceSize_1(TObjectHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TObject_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TOBJECT */

#ifdef SB_USE_CLASS_TBITS
SB_IMPORT uint32_t SB_APIENTRY TBits_get_Bits(TBitsHandle _Handle, int32_t Bit, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TBits_set_Bits(TBitsHandle _Handle, int32_t bit, int8_t value);
SB_IMPORT uint32_t SB_APIENTRY TBits_get_Size(TBitsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TBits_set_Size(TBitsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TBits_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TBITS */

#ifdef SB_USE_CLASS_TPERSISTENT
SB_IMPORT uint32_t SB_APIENTRY TPersistent_Assign(TPersistentHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TPersistent_GetNamePath(TPersistentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TPersistent_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TPERSISTENT */

#ifdef SB_USE_CLASS_TSTREAM
SB_IMPORT uint32_t SB_APIENTRY TStream_Read(TStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_Write(TStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_Seek(TStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_Seek_1(TStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_ReadBuffer(TStreamHandle _Handle, void * Buffer, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TStream_WriteBuffer(TStreamHandle _Handle, const void * Buffer, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TStream_CopyFrom(TStreamHandle _Handle, TStreamHandle Source, int64_t Count, int64_t * OutResult);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_ReadByte(TStreamHandle _Handle, uint8_t * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_ReadWord(TStreamHandle _Handle, uint16_t * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_ReadDWord(TStreamHandle _Handle, uint32_t * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_ReadAnsiString(TStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_WriteByte(TStreamHandle _Handle, uint8_t b);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_WriteWord(TStreamHandle _Handle, uint16_t w);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_WriteDWord(TStreamHandle _Handle, uint32_t d);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStream_WriteAnsiString(TStreamHandle _Handle, const char * pcS, int32_t szS);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY TStream_get_Position(TStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_set_Position(TStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TStream_get_Size(TStreamHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStream_set_Size(TStreamHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_THANDLESTREAM
SB_IMPORT uint32_t SB_APIENTRY THandleStream_Read(THandleStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY THandleStream_Write(THandleStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY THandleStream_Seek(THandleStreamHandle _Handle, int64_t Offset, TSeekOriginRaw Origin, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY THandleStream_get_Handle(THandleStreamHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY THandleStream_Create(int32_t AHandle, THandleStreamHandle * OutResult);
#endif /* SB_USE_CLASS_THANDLESTREAM */

#ifdef SB_USE_CLASS_TFILESTREAM
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TFileStream_get_FileName(TFileStreamHandle _Handle, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY TFileStream_Create(const char * pcAFileName, int32_t szAFileName, uint16_t Mode, TFileStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TFileStream_Create_1(const char * pcAFileName, int32_t szAFileName, uint16_t Mode, uint32_t Rights, TFileStreamHandle * OutResult);
#endif /* SB_USE_CLASS_TFILESTREAM */

#ifdef SB_USE_CLASS_TINTERFACEDOBJECT
SB_IMPORT uint32_t SB_APIENTRY TInterfacedObject_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TINTERFACEDOBJECT */

#ifdef SB_USE_CLASS_TINTERFACEDPERSISTENT
SB_IMPORT uint32_t SB_APIENTRY TInterfacedPersistent_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TINTERFACEDPERSISTENT */

#ifdef SB_USE_CLASS_TLIST
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TList_AddList(TListHandle _Handle, TListHandle AList);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY TList_Add(TListHandle _Handle, void * Item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_Clear(TListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TList_Delete(TListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TList_Error(const char * pcMsg, int32_t szMsg, int32_t Data);
SB_IMPORT uint32_t SB_APIENTRY TList_Error_1(TListHandle _Handle, const char * pcMsg, int32_t szMsg, int32_t Data);
SB_IMPORT uint32_t SB_APIENTRY TList_Exchange(TListHandle _Handle, int32_t Index1, int32_t Index2);
SB_IMPORT uint32_t SB_APIENTRY TList_Expand(TListHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_Extract(TListHandle _Handle, void * item, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_First(TListHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_IndexOf(TListHandle _Handle, void * Item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_Insert(TListHandle _Handle, int32_t Index, void * Item);
SB_IMPORT uint32_t SB_APIENTRY TList_Last(TListHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_Move(TListHandle _Handle, int32_t CurIndex, int32_t NewIndex);
SB_IMPORT uint32_t SB_APIENTRY TList_Assign(TListHandle _Handle, TListHandle ListA, TListAssignOpRaw AOperator, TListHandle ListB);
SB_IMPORT uint32_t SB_APIENTRY TList_Remove(TListHandle _Handle, void * Item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_Pack(TListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TList_Sort(TListHandle _Handle, void * Compare);
SB_IMPORT uint32_t SB_APIENTRY TList_get_Capacity(TListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_set_Capacity(TListHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TList_get_Count(TListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_set_Count(TListHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TList_get_Items(TListHandle _Handle, int32_t Index, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TList_set_Items(TListHandle _Handle, int32_t Index, void * Item);
SB_IMPORT uint32_t SB_APIENTRY TList_Create(TListHandle * OutResult);
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TCUSTOMMEMORYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_Read(TCustomMemoryStreamHandle _Handle, void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_Seek(TCustomMemoryStreamHandle _Handle, int32_t Offset, uint16_t Origin, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_SaveToStream(TCustomMemoryStreamHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_SaveToFile(TCustomMemoryStreamHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_get_Memory(TCustomMemoryStreamHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TCustomMemoryStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TCUSTOMMEMORYSTREAM */

#ifdef SB_USE_CLASS_TCOMPONENT
SB_IMPORT uint32_t SB_APIENTRY TComponent_GetNamePath(TComponentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TComponent_get_Name(TComponentHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TComponent_set_Name(TComponentHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TComponent_get_Tag(TComponentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TComponent_set_Tag(TComponentHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TComponent_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TCOMPONENT */

#ifdef SB_USE_CLASS_TMEMORYSTREAM
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_Clear(TMemoryStreamHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_LoadFromStream(TMemoryStreamHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_LoadFromFile(TMemoryStreamHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_SetSize(TMemoryStreamHandle _Handle, int32_t NewSize);
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_Write(TMemoryStreamHandle _Handle, const void * Buffer, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TMemoryStream_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

#ifdef SB_USE_CLASS_TSTRINGS
SB_IMPORT uint32_t SB_APIENTRY TStrings_Add(TStringsHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_AddObject(TStringsHandle _Handle, const char * pcS, int32_t szS, TObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Append(TStringsHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TStrings_AddStrings(TStringsHandle _Handle, TStringsHandle TheStrings);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Assign(TStringsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TStrings_BeginUpdate(TStringsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Clear(TStringsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Delete(TStringsHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TStrings_EndUpdate(TStringsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Equals(TStringsHandle _Handle, TStringsHandle TheStrings, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Exchange(TStringsHandle _Handle, int32_t Index1, int32_t Index2);
SB_IMPORT uint32_t SB_APIENTRY TStrings_GetText(TStringsHandle _Handle, char * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_IndexOf(TStringsHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_IndexOfName(TStringsHandle _Handle, const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_IndexOfObject(TStringsHandle _Handle, TObjectHandle AObject, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Insert(TStringsHandle _Handle, int32_t Index, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TStrings_InsertObject(TStringsHandle _Handle, int32_t Index, const char * pcS, int32_t szS, TObjectHandle AObject);
SB_IMPORT uint32_t SB_APIENTRY TStrings_LoadFromFile(TStringsHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TStrings_LoadFromStream(TStringsHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Move(TStringsHandle _Handle, int32_t CurIndex, int32_t NewIndex);
SB_IMPORT uint32_t SB_APIENTRY TStrings_SaveToFile(TStringsHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TStrings_SaveToStream(TStringsHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TStrings_SetText(TStringsHandle _Handle, char * TheText);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStrings_GetNameValue(TStringsHandle _Handle, int32_t Index, char * pcAName, int32_t * szAName, char * pcAValue, int32_t * szAValue);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStrings_ExtractName(TStringsHandle _Handle, const char * pcS, int32_t szS, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_TextLineBreakStyle(TStringsHandle _Handle, TTextLineBreakStyleRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_TextLineBreakStyle(TStringsHandle _Handle, TTextLineBreakStyleRaw Value);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Delimiter(TStringsHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Delimiter(TStringsHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_DelimitedText(TStringsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_DelimitedText(TStringsHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_StrictDelimiter(TStringsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_StrictDelimiter(TStringsHandle _Handle, int8_t Value);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_QuoteChar(TStringsHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_QuoteChar(TStringsHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_NameValueSeparator(TStringsHandle _Handle, char * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_NameValueSeparator(TStringsHandle _Handle, char Value);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_ValueFromIndex(TStringsHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_ValueFromIndex(TStringsHandle _Handle, int32_t Index, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Capacity(TStringsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Capacity(TStringsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_CommaText(TStringsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_CommaText(TStringsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Count(TStringsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Names(TStringsHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Objects(TStringsHandle _Handle, int32_t Index, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Objects(TStringsHandle _Handle, int32_t Index, TObjectHandle AObject);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Values(TStringsHandle _Handle, const char * pcName, int32_t szName, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Values(TStringsHandle _Handle, const char * pcName, int32_t szName, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Strings(TStringsHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Strings(TStringsHandle _Handle, int32_t Index, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TStrings_get_Text(TStringsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStrings_set_Text(TStringsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TStrings_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGLIST
SB_IMPORT uint32_t SB_APIENTRY TStringList_Add(TStringListHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Clear(TStringListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Delete(TStringListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Exchange(TStringListHandle _Handle, int32_t Index1, int32_t Index2);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Find(TStringListHandle _Handle, const char * pcS, int32_t szS, int32_t * Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_IndexOf(TStringListHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Insert(TStringListHandle _Handle, int32_t Index, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Sort(TStringListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TStringList_CustomSort(TStringListHandle _Handle, void * CompareFn);
SB_IMPORT uint32_t SB_APIENTRY TStringList_get_Duplicates(TStringListHandle _Handle, TDuplicatesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_set_Duplicates(TStringListHandle _Handle, TDuplicatesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TStringList_get_Sorted(TStringListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_set_Sorted(TStringListHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TStringList_get_CaseSensitive(TStringListHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_set_CaseSensitive(TStringListHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TStringList_get_OnChange(TStringListHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_set_OnChange(TStringListHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TStringList_get_OnChanging(TStringListHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TStringList_set_OnChanging(TStringListHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TStringList_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TTHREAD
SB_IMPORT uint32_t SB_APIENTRY TThread_Synchronize(TThreadHandle AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);
SB_IMPORT uint32_t SB_APIENTRY TThread_Synchronize_1(TThreadHandle _Handle, TThreadHandle AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);
SB_IMPORT uint32_t SB_APIENTRY TThread_AfterConstruction(TThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TThread_Resume(TThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TThread_Suspend(TThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TThread_Terminate(TThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TThread_WaitFor(TThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_get_FreeOnTerminate(TThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_set_FreeOnTerminate(TThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TThread_get_Priority(TThreadHandle _Handle, TThreadPriorityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_set_Priority(TThreadHandle _Handle, TThreadPriorityRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TThread_get_Suspended(TThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_set_Suspended(TThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TThread_get_FatalException(TThreadHandle _Handle, TObjectHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_get_OnTerminate(TThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TThread_set_OnTerminate(TThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY TThread_Create(int8_t CreateSuspended, uint32_t StackSize, TThreadHandle * OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
#endif /* SB_USE_CLASS_TTHREAD */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TObject;
class TBits;
class TPersistent;
class TStream;
class THandleStream;
class TFileStream;
class TInterfacedObject;
class TInterfacedPersistent;
class TList;
class TCustomMemoryStream;
class TComponent;
class TMemoryStream;
class TStrings;
class TStringList;
class TThread;

#ifdef SB_USE_CLASS_TOBJECT
class TObject
{
	private:
		SB_DISABLE_COPY(TObject)
	protected:
		TElClassHandle _Handle;
		TElOwnHandle _OwnHandle;
	public:
		void Free();

		TClassHandle GetType();

		static void ClassName(std::string &OutResult);

		void ClassName_Inst(std::string &OutResult);

		static bool ClassNameIs(const std::string &name);

		bool ClassNameIs_Inst(const std::string &name);

		static int32_t InstanceSize();

		int32_t InstanceSize_Inst();

		TObject(TObjectHandle handle, TElOwnHandle ownHandle);

		TObject();

		const TElClassHandle getHandle() const
		{
			return _Handle;
		}

		void setHandle(const TElClassHandle handle, const TElOwnHandle ownHandle)
		{
			if (_OwnHandle)
				TObject_Free(_Handle);
			_Handle = handle;
			_OwnHandle = ownHandle;
		}

		void detachHandle()
		{
			_Handle = SB_NULL_HANDLE;
		}

		void updateHandle(const TElClassHandle handle)
		{
			_Handle = handle;
		}

		virtual ~TObject();

};
#endif /* SB_USE_CLASS_TOBJECT */

#ifdef SB_USE_CLASS_TBITS
class TBits: public TObject
{
	private:
		SB_DISABLE_COPY(TBits)
	public:
		virtual bool get_Bits(int32_t Bit);

		virtual void set_Bits(int32_t bit, bool value);

		virtual int32_t get_Size();

		virtual void set_Size(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Size, set_Size, TBits, Size);

		TBits(TBitsHandle handle, TElOwnHandle ownHandle);

		TBits();

};
#endif /* SB_USE_CLASS_TBITS */

#ifdef SB_USE_CLASS_TPERSISTENT
class TPersistent: public TObject
{
	private:
		SB_DISABLE_COPY(TPersistent)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void GetNamePath(std::string &OutResult);

		TPersistent(TPersistentHandle handle, TElOwnHandle ownHandle);

		TPersistent();

};
#endif /* SB_USE_CLASS_TPERSISTENT */

#ifdef SB_USE_CLASS_TSTREAM
class TStream: public TObject
{
	private:
		SB_DISABLE_COPY(TStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		void ReadBuffer(void * Buffer, int32_t Count);

		void WriteBuffer(const void * Buffer, int32_t Count);

		int64_t CopyFrom(TStream &Source, int64_t Count);

		int64_t CopyFrom(TStream *Source, int64_t Count);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		uint8_t ReadByte();
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		uint16_t ReadWord();
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		uint32_t ReadDWord();
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void ReadAnsiString(std::string &OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void WriteByte(uint8_t b);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void WriteWord(uint16_t w);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void WriteDWord(uint32_t d);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void WriteAnsiString(const std::string &S);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		virtual int64_t get_Position();

		virtual void set_Position(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Position, set_Position, TStream, Position);

		virtual int64_t get_Size();

		virtual void set_Size(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Size, set_Size, TStream, Size);

		TStream(TStreamHandle handle, TElOwnHandle ownHandle);

		TStream();

};
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_THANDLESTREAM
class THandleStream: public TStream
{
	private:
		SB_DISABLE_COPY(THandleStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		virtual int64_t Seek(int64_t Offset, TSeekOrigin Origin);

		virtual int32_t get_Handle();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Handle, THandleStream, Handle);

		THandleStream(THandleStreamHandle handle, TElOwnHandle ownHandle);

		explicit THandleStream(int32_t AHandle);

};
#endif /* SB_USE_CLASS_THANDLESTREAM */

#ifdef SB_USE_CLASS_TFILESTREAM
class TFileStream: public THandleStream
{
	private:
		SB_DISABLE_COPY(TFileStream)
	public:
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		virtual void get_FileName(std::string &OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		TFileStream(TFileStreamHandle handle, TElOwnHandle ownHandle);

		TFileStream(const std::string &AFileName, uint16_t Mode);

		TFileStream(const std::string &AFileName, uint16_t Mode, uint32_t Rights);

};
#endif /* SB_USE_CLASS_TFILESTREAM */

#ifdef SB_USE_CLASS_TINTERFACEDOBJECT
class TInterfacedObject: public TObject
{
	private:
		SB_DISABLE_COPY(TInterfacedObject)
	public:
		TInterfacedObject(TInterfacedObjectHandle handle, TElOwnHandle ownHandle);

		TInterfacedObject();

};
#endif /* SB_USE_CLASS_TINTERFACEDOBJECT */

#ifdef SB_USE_CLASS_TINTERFACEDPERSISTENT
class TInterfacedPersistent: public TPersistent
{
	private:
		SB_DISABLE_COPY(TInterfacedPersistent)
	public:
		TInterfacedPersistent(TInterfacedPersistentHandle handle, TElOwnHandle ownHandle);

		TInterfacedPersistent();

};
#endif /* SB_USE_CLASS_TINTERFACEDPERSISTENT */

#ifdef SB_USE_CLASS_TLIST
class TList: public TObject
{
	private:
		SB_DISABLE_COPY(TList)
	public:
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void AddList(TList &AList);

		void AddList(TList *AList);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		int32_t Add(void * Item);

		virtual void Clear();

		void Delete(int32_t Index);

		static void Error(const std::string &Msg, int32_t Data);

		virtual void Error_Inst(const std::string &Msg, int32_t Data);

		void Exchange(int32_t Index1, int32_t Index2);

		TListHandle Expand();

		void * Extract(void * item);

		void * First();

		int32_t IndexOf(void * Item);

		void Insert(int32_t Index, void * Item);

		void * Last();

		void Move(int32_t CurIndex, int32_t NewIndex);

		void Assign(TList &ListA, TListAssignOp AOperator, TList &ListB);

		void Assign(TList *ListA, TListAssignOp AOperator, TList *ListB);

		int32_t Remove(void * Item);

		void Pack();

		void Sort(void * Compare);

		virtual int32_t get_Capacity();

		virtual void set_Capacity(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Capacity, set_Capacity, TList, Capacity);

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TList, Count);

		virtual void * get_Items(int32_t Index);

		virtual void set_Items(int32_t Index, void * Item);

		TList(TListHandle handle, TElOwnHandle ownHandle);

		TList();

};
#endif /* SB_USE_CLASS_TLIST */

#ifdef SB_USE_CLASS_TCUSTOMMEMORYSTREAM
class TCustomMemoryStream: public TStream
{
	private:
		SB_DISABLE_COPY(TCustomMemoryStream)
	public:
		virtual int32_t Read(void * Buffer, int32_t Count);

		virtual int32_t Seek(int32_t Offset, uint16_t Origin);

		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);

		void SaveToFile(const std::string &FileName);

		virtual void * get_Memory();

		SB_DECLARE_PROPERTY_GET(void *, get_Memory, TCustomMemoryStream, Memory);

		TCustomMemoryStream(TCustomMemoryStreamHandle handle, TElOwnHandle ownHandle);

		TCustomMemoryStream();

};
#endif /* SB_USE_CLASS_TCUSTOMMEMORYSTREAM */

#ifdef SB_USE_CLASS_TCOMPONENT
class TComponent: public TPersistent
{
	public:
		virtual void GetNamePath(std::string &OutResult);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual int32_t get_Tag();

		virtual void set_Tag(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Tag, set_Tag, TComponent, Tag);

		TComponent(TComponentHandle handle, TElOwnHandle ownHandle);

		explicit TComponent(TComponent &AOwner);

		explicit TComponent(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TCOMPONENT */

#ifdef SB_USE_CLASS_TMEMORYSTREAM
class TMemoryStream: public TCustomMemoryStream
{
	private:
		SB_DISABLE_COPY(TMemoryStream)
	public:
		void Clear();

		void LoadFromStream(TStream &Stream);

		void LoadFromStream(TStream *Stream);

		void LoadFromFile(const std::string &FileName);

		virtual void SetSize(int32_t NewSize);

		virtual int32_t Write(const void * Buffer, int32_t Count);

		TMemoryStream(TMemoryStreamHandle handle, TElOwnHandle ownHandle);

		TMemoryStream();

};
#endif /* SB_USE_CLASS_TMEMORYSTREAM */

#ifdef SB_USE_CLASS_TSTRINGS
class TStrings: public TPersistent
{
	private:
		SB_DISABLE_COPY(TStrings)
		TObject* _Inst_Objects;

		void initInstances();

	public:
		virtual int32_t Add(const std::string &S);

		virtual int32_t AddObject(const std::string &S, TObject &AObject);

		virtual int32_t AddObject(const std::string &S, TObject *AObject);

		void Append(const std::string &S);

		virtual void AddStrings(TStrings &TheStrings);

		virtual void AddStrings(TStrings *TheStrings);

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void BeginUpdate();

		virtual void Clear();

		virtual void Delete(int32_t Index);

		void EndUpdate();

		bool Equals(TStrings &TheStrings);

		bool Equals(TStrings *TheStrings);

		virtual void Exchange(int32_t Index1, int32_t Index2);

		virtual char * GetText();

		virtual int32_t IndexOf(const std::string &S);

		virtual int32_t IndexOfName(const std::string &Name);

		virtual int32_t IndexOfObject(TObject &AObject);

		virtual int32_t IndexOfObject(TObject *AObject);

		virtual void Insert(int32_t Index, const std::string &S);

		void InsertObject(int32_t Index, const std::string &S, TObject &AObject);

		void InsertObject(int32_t Index, const std::string &S, TObject *AObject);

		virtual void LoadFromFile(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void LoadFromStream(TStream &Stream);

		virtual void LoadFromStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Move(int32_t CurIndex, int32_t NewIndex);

		virtual void SaveToFile(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void SetText(char * TheText);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void GetNameValue(int32_t Index, std::string &AName, std::string &AValue);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		void ExtractName(const std::string &S, std::string &OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		virtual TTextLineBreakStyle get_TextLineBreakStyle();

		virtual void set_TextLineBreakStyle(TTextLineBreakStyle Value);

		SB_DECLARE_PROPERTY(TTextLineBreakStyle, get_TextLineBreakStyle, set_TextLineBreakStyle, TStrings, TextLineBreakStyle);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		virtual char get_Delimiter();

		virtual void set_Delimiter(char Value);

		SB_DECLARE_PROPERTY(char, get_Delimiter, set_Delimiter, TStrings, Delimiter);

		virtual void get_DelimitedText(std::string &OutResult);

		virtual void set_DelimitedText(const std::string &Value);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		virtual bool get_StrictDelimiter();

		virtual void set_StrictDelimiter(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictDelimiter, set_StrictDelimiter, TStrings, StrictDelimiter);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		virtual char get_QuoteChar();

		virtual void set_QuoteChar(char Value);

		SB_DECLARE_PROPERTY(char, get_QuoteChar, set_QuoteChar, TStrings, QuoteChar);

		virtual char get_NameValueSeparator();

		virtual void set_NameValueSeparator(char Value);

		SB_DECLARE_PROPERTY(char, get_NameValueSeparator, set_NameValueSeparator, TStrings, NameValueSeparator);

		virtual void get_ValueFromIndex(int32_t Index, std::string &OutResult);

		virtual void set_ValueFromIndex(int32_t Index, const std::string &Value);

		virtual int32_t get_Capacity();

		virtual void set_Capacity(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Capacity, set_Capacity, TStrings, Capacity);

		virtual void get_CommaText(std::string &OutResult);

		virtual void set_CommaText(const std::string &Value);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TStrings, Count);

		virtual void get_Names(int32_t Index, std::string &OutResult);

		virtual TObject* get_Objects(int32_t Index);

		virtual void set_Objects(int32_t Index, TObject &AObject);

		virtual void set_Objects(int32_t Index, TObject *AObject);

		virtual void get_Values(const std::string &Name, std::string &OutResult);

		virtual void set_Values(const std::string &Name, const std::string &Value);

		virtual void get_Strings(int32_t Index, std::string &OutResult);

		virtual void set_Strings(int32_t Index, const std::string &S);

		virtual void get_Text(std::string &OutResult);

		virtual void set_Text(const std::string &Value);

		TStrings(TStringsHandle handle, TElOwnHandle ownHandle);

		TStrings();

		virtual ~TStrings();

};
#endif /* SB_USE_CLASS_TSTRINGS */

#ifdef SB_USE_CLASS_TSTRINGLIST
class TStringList: public TStrings
{
	private:
		SB_DISABLE_COPY(TStringList)
	public:
		virtual int32_t Add(const std::string &S);

		virtual void Clear();

		virtual void Delete(int32_t Index);

		virtual void Exchange(int32_t Index1, int32_t Index2);

		virtual bool Find(const std::string &S, int32_t &Index);

		virtual int32_t IndexOf(const std::string &S);

		virtual void Insert(int32_t Index, const std::string &S);

		virtual void Sort();

		virtual void CustomSort(void * CompareFn);

		virtual TDuplicates get_Duplicates();

		virtual void set_Duplicates(TDuplicates Value);

		SB_DECLARE_PROPERTY(TDuplicates, get_Duplicates, set_Duplicates, TStringList, Duplicates);

		virtual bool get_Sorted();

		virtual void set_Sorted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Sorted, set_Sorted, TStringList, Sorted);

		virtual bool get_CaseSensitive();

		virtual void set_CaseSensitive(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CaseSensitive, set_CaseSensitive, TStringList, CaseSensitive);

		virtual void get_OnChange(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChange(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnChanging(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnChanging(TNotifyEvent pMethodValue, void * pDataValue);

		TStringList(TStringListHandle handle, TElOwnHandle ownHandle);

		TStringList();

};
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TTHREAD
class TThread: public TObject
{
	private:
		SB_DISABLE_COPY(TThread)
		TObject* _Inst_FatalException;

		void initInstances();

	public:
		static void Synchronize(TThread &AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);

		static void Synchronize(TThread *AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);

		void Synchronize_Inst(TThread &AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);

		void Synchronize_Inst(TThread *AThread, TThreadMethod pMethodAMethod, void * pDataAMethod);

		virtual void AfterConstruction();

		void Resume();

		void Suspend();

		void Terminate();

		int32_t WaitFor();

		virtual bool get_FreeOnTerminate();

		virtual void set_FreeOnTerminate(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FreeOnTerminate, set_FreeOnTerminate, TThread, FreeOnTerminate);

		virtual TThreadPriority get_Priority();

		virtual void set_Priority(TThreadPriority Value);

		SB_DECLARE_PROPERTY(TThreadPriority, get_Priority, set_Priority, TThread, Priority);

		virtual bool get_Suspended();

		virtual void set_Suspended(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Suspended, set_Suspended, TThread, Suspended);

		virtual TObject* get_FatalException();

		SB_DECLARE_PROPERTY_GET(TObject*, get_FatalException, TThread, FatalException);

		virtual void get_OnTerminate(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTerminate(TNotifyEvent pMethodValue, void * pDataValue);

		TThread(TThreadHandle handle, TElOwnHandle ownHandle);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
		TThread(bool CreateSuspended, uint32_t StackSize);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

		virtual ~TThread();

};
#endif /* SB_USE_CLASS_TTHREAD */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSYSTEM */
