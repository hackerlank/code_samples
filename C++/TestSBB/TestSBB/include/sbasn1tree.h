#ifndef __INC_SBASN1TREE
#define __INC_SBASN1TREE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbasn1.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ASN1_BOOLEAN 	1
#define SB_ASN1_INTEGER 	2
#define SB_ASN1_BITSTRING 	3
#define SB_ASN1_OCTETSTRING 	4
#define SB_ASN1_NULL 	5
#define SB_ASN1_OBJECT 	6
#define SB_ASN1_REAL 	9
#define SB_ASN1_ENUMERATED 	10
#define SB_ASN1_UTF8STRING 	12
#define SB_ASN1_NUMERICSTR 	18
#define SB_ASN1_PRINTABLESTRING 	19
#define SB_ASN1_T61STRING 	20
#define SB_ASN1_TELETEXSTRING 	20
#define SB_ASN1_VIDEOTEXSTRING 	21
#define SB_ASN1_IA5STRING 	22
#define SB_ASN1_UTCTIME 	23
#define SB_ASN1_GENERALIZEDTIME 	24
#define SB_ASN1_GRAPHICSTRING 	25
#define SB_ASN1_VISIBLESTRING 	26
#define SB_ASN1_GENERALSTRING 	27
#define SB_ASN1_UNIVERSALSTRING 	28
#define SB_ASN1_BMPSTRING 	30
#define SB_ASN1_SEQUENCE 	48
#define SB_ASN1_SET 	49
#define SB_ASN1_A0_PRIMITIVE 	128
#define SB_ASN1_A0 	160
#define SB_ASN1_A1_PRIMITIVE 	129
#define SB_ASN1_A1 	161
#define SB_ASN1_A2_PRIMITIVE 	130
#define SB_ASN1_A2 	162
#define SB_ASN1_A3_PRIMITIVE 	131
#define SB_ASN1_A3 	163
#define SB_ASN1_A4_PRIMITIVE 	132
#define SB_ASN1_A4 	164
#define SB_ASN1_A5_PRIMITIVE 	133
#define SB_ASN1_A5 	165
#define SB_ASN1_A6_PRIMITIVE 	134
#define SB_ASN1_A6 	166
#define SB_ASN1_A7_PRIMITIVE 	135
#define SB_ASN1_A7 	167
#define SB_ASN1_A8_PRIMITIVE 	136
#define SB_ASN1_A8 	168
#define SB_ASN1_A9_PRIMITIVE 	137
#define SB_ASN1_A9 	169
#define SB_ASN1_CONSTRAINED_FLAG 	32

typedef TElClassHandle TElASN1CustomTagHandle;

typedef TElClassHandle TElASN1DataSourceHandle;

typedef TElClassHandle TElASN1SimpleTagHandle;

typedef TElClassHandle TElASN1ConstrainedTagHandle;

typedef uint8_t TSBASN1DataSourceTypeRaw;

typedef enum
{
	dstBuffer = 0,
	dstStream = 1,
	dstVirtual = 2
} TSBASN1DataSourceType;

typedef void (SB_CALLBACK *TSBASN1VirtualDataNeededEvent)(void * _ObjectData, TObjectHandle Sender, int64_t StartIndex, void * Buffer, int32_t MaxSize, int32_t * Read);

typedef uint8_t TSBASN1StreamAccessRaw;

typedef enum
{
	saStoreStream = 0
} TSBASN1StreamAccess;

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_LoadFromBuffer(TElASN1CustomTagHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_SaveToBuffer(TElASN1CustomTagHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_CheckType(TElASN1CustomTagHandle _Handle, uint8_t TagId, int8_t Constrained, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_LoadFromStream(TElASN1CustomTagHandle _Handle, TStreamHandle Stream, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_SaveToStream(TElASN1CustomTagHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagId(TElASN1CustomTagHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_set_TagId(TElASN1CustomTagHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_UndefSize(TElASN1CustomTagHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_set_UndefSize(TElASN1CustomTagHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_WriteHeader(TElASN1CustomTagHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_set_WriteHeader(TElASN1CustomTagHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_IsConstrained(TElASN1CustomTagHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagNum(TElASN1CustomTagHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagOffset(TElASN1CustomTagHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagSize(TElASN1CustomTagHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagHeaderSize(TElASN1CustomTagHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_TagContentSize(TElASN1CustomTagHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_get_Depth(TElASN1CustomTagHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1CustomTag_Create(TElASN1CustomTagHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Init(TElASN1DataSourceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Init_1(TElASN1DataSourceHandle _Handle, TStreamHandle Stream, int64_t Offset, int64_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Init_2(TElASN1DataSourceHandle _Handle, TStreamHandle Stream, int8_t UnknownSize);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Init_3(TElASN1DataSourceHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_InitVirtual(TElASN1DataSourceHandle _Handle, int64_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Read(TElASN1DataSourceHandle _Handle, void * Buffer, int32_t Size, int64_t Offset, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Clone(TElASN1DataSourceHandle _Handle, TElASN1DataSourceHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_CloneVirtual(TElASN1DataSourceHandle _Handle, TElASN1DataSourceHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_ToBuffer(TElASN1DataSourceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_get_Size(TElASN1DataSourceHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_get_UnknownSize(TElASN1DataSourceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_get_SkipVirtualData(TElASN1DataSourceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_set_SkipVirtualData(TElASN1DataSourceHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_get_SourceType(TElASN1DataSourceHandle _Handle, TSBASN1DataSourceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_get_OnVirtualDataNeeded(TElASN1DataSourceHandle _Handle, TSBASN1VirtualDataNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_set_OnVirtualDataNeeded(TElASN1DataSourceHandle _Handle, TSBASN1VirtualDataNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1DataSource_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_CreateInstance(TElASN1SimpleTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_CreateInstance_1(TElASN1SimpleTagHandle _Handle, TElASN1SimpleTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_LoadFromBuffer(TElASN1SimpleTagHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_SaveToBuffer(TElASN1SimpleTagHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_LoadFromStream(TElASN1SimpleTagHandle _Handle, TStreamHandle Stream, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_SaveToStream(TElASN1SimpleTagHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_get_Content(TElASN1SimpleTagHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_set_Content(TElASN1SimpleTagHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_get_DataSource(TElASN1SimpleTagHandle _Handle, TElASN1DataSourceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_get_FragmentSize(TElASN1SimpleTagHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_set_FragmentSize(TElASN1SimpleTagHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_get_OnContentWriteBegin(TElASN1SimpleTagHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_set_OnContentWriteBegin(TElASN1SimpleTagHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_get_OnContentWriteEnd(TElASN1SimpleTagHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_set_OnContentWriteEnd(TElASN1SimpleTagHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1SimpleTag_Create(TElASN1SimpleTagHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_CreateInstance(TElASN1ConstrainedTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_CreateInstance_1(TElASN1ConstrainedTagHandle _Handle, TElASN1ConstrainedTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_LoadFromBuffer(TElASN1ConstrainedTagHandle _Handle, void * Buffer, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_LoadFromBufferSingle(TElASN1ConstrainedTagHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_SaveToBuffer(TElASN1ConstrainedTagHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_SaveContentToBuffer(TElASN1ConstrainedTagHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_LoadFromStream(TElASN1ConstrainedTagHandle _Handle, TStreamHandle Stream, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_LoadFromStreamSingle(TElASN1ConstrainedTagHandle _Handle, TStreamHandle Stream, int64_t Count, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_SaveToStream(TElASN1ConstrainedTagHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_AddField(TElASN1ConstrainedTagHandle _Handle, int8_t Constrained, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_RemoveField(TElASN1ConstrainedTagHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_GetField(TElASN1ConstrainedTagHandle _Handle, int32_t Index, TElASN1CustomTagHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_Clear(TElASN1ConstrainedTagHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_get_Count(TElASN1ConstrainedTagHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_get_MaxSimpleTagLength(TElASN1ConstrainedTagHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_set_MaxSimpleTagLength(TElASN1ConstrainedTagHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_get_StreamAccess(TElASN1ConstrainedTagHandle _Handle, TSBASN1StreamAccessRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_set_StreamAccess(TElASN1ConstrainedTagHandle _Handle, TSBASN1StreamAccessRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1ConstrainedTag_Create(TElASN1ConstrainedTagHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElASN1CustomTag;
class TElASN1DataSource;
class TElASN1SimpleTag;
class TElASN1ConstrainedTag;

#ifdef SB_USE_CLASS_TELASN1CUSTOMTAG
class TElASN1CustomTag: public TObject
{
	private:
		SB_DISABLE_COPY(TElASN1CustomTag)
	public:
		virtual bool LoadFromBuffer(void * Buffer, int32_t Size);

		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		bool CheckType(uint8_t TagId, bool Constrained);

#ifdef SB_USE_CLASS_TSTREAM
		virtual bool LoadFromStream(TStream &Stream, int64_t Count);

		virtual bool LoadFromStream(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual uint8_t get_TagId();

		virtual void set_TagId(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_TagId, set_TagId, TElASN1CustomTag, TagId);

		virtual bool get_UndefSize();

		virtual void set_UndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UndefSize, set_UndefSize, TElASN1CustomTag, UndefSize);

		virtual bool get_WriteHeader();

		virtual void set_WriteHeader(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteHeader, set_WriteHeader, TElASN1CustomTag, WriteHeader);

		virtual bool get_IsConstrained();

		SB_DECLARE_PROPERTY_GET(bool, get_IsConstrained, TElASN1CustomTag, IsConstrained);

		virtual uint8_t get_TagNum();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_TagNum, TElASN1CustomTag, TagNum);

		virtual int64_t get_TagOffset();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TagOffset, TElASN1CustomTag, TagOffset);

		virtual int64_t get_TagSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TagSize, TElASN1CustomTag, TagSize);

		virtual int32_t get_TagHeaderSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TagHeaderSize, TElASN1CustomTag, TagHeaderSize);

		virtual int64_t get_TagContentSize();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TagContentSize, TElASN1CustomTag, TagContentSize);

		virtual int32_t get_Depth();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Depth, TElASN1CustomTag, Depth);

		TElASN1CustomTag(TElASN1CustomTagHandle handle, TElOwnHandle ownHandle);

		TElASN1CustomTag();

};
#endif /* SB_USE_CLASS_TELASN1CUSTOMTAG */

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
class TElASN1DataSource: public TObject
{
	private:
		SB_DISABLE_COPY(TElASN1DataSource)
	public:
		void Init(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TSTREAM
		void Init(TStream &Stream, int64_t Offset, int64_t Size);

		void Init(TStream *Stream, int64_t Offset, int64_t Size);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Init(TStream &Stream, bool UnknownSize);

		void Init(TStream *Stream, bool UnknownSize);
#endif /* SB_USE_CLASS_TSTREAM */

		void Init(void * Buffer, int32_t Size);

		void InitVirtual(int64_t Size);

		int32_t Read(void * Buffer, int32_t Size, int64_t Offset);

		void Clone(TElASN1DataSource &Dest);

		void Clone(TElASN1DataSource *Dest);

		void CloneVirtual(TElASN1DataSource &Dest);

		void CloneVirtual(TElASN1DataSource *Dest);

		void ToBuffer(std::vector<uint8_t> &OutResult);

		virtual int64_t get_Size();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Size, TElASN1DataSource, Size);

		virtual bool get_UnknownSize();

		SB_DECLARE_PROPERTY_GET(bool, get_UnknownSize, TElASN1DataSource, UnknownSize);

		virtual bool get_SkipVirtualData();

		virtual void set_SkipVirtualData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SkipVirtualData, set_SkipVirtualData, TElASN1DataSource, SkipVirtualData);

		virtual TSBASN1DataSourceType get_SourceType();

		SB_DECLARE_PROPERTY_GET(TSBASN1DataSourceType, get_SourceType, TElASN1DataSource, SourceType);

		virtual void get_OnVirtualDataNeeded(TSBASN1VirtualDataNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnVirtualDataNeeded(TSBASN1VirtualDataNeededEvent pMethodValue, void * pDataValue);

		TElASN1DataSource(TElASN1DataSourceHandle handle, TElOwnHandle ownHandle);

		TElASN1DataSource();

};
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
class TElASN1SimpleTag: public TElASN1CustomTag
{
	private:
		SB_DISABLE_COPY(TElASN1SimpleTag)
#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		TElASN1DataSource* _Inst_DataSource;
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		void initInstances();

	public:
		static TElASN1SimpleTagHandle CreateInstance();

		TElASN1SimpleTagHandle CreateInstance_Inst();

		virtual bool LoadFromBuffer(void * Buffer, int32_t Size);

		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual bool LoadFromStream(TStream &Stream, int64_t Count);

		virtual bool LoadFromStream(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Content(std::vector<uint8_t> &OutResult);

		virtual void set_Content(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELASN1DATASOURCE
		virtual TElASN1DataSource* get_DataSource();

		SB_DECLARE_PROPERTY_GET(TElASN1DataSource*, get_DataSource, TElASN1SimpleTag, DataSource);
#endif /* SB_USE_CLASS_TELASN1DATASOURCE */

		virtual int32_t get_FragmentSize();

		virtual void set_FragmentSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FragmentSize, set_FragmentSize, TElASN1SimpleTag, FragmentSize);

		virtual void get_OnContentWriteBegin(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnContentWriteBegin(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnContentWriteEnd(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnContentWriteEnd(TNotifyEvent pMethodValue, void * pDataValue);

		TElASN1SimpleTag(TElASN1SimpleTagHandle handle, TElOwnHandle ownHandle);

		TElASN1SimpleTag();

		virtual ~TElASN1SimpleTag();

};
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
class TElASN1ConstrainedTag: public TElASN1CustomTag
{
	private:
		SB_DISABLE_COPY(TElASN1ConstrainedTag)
	public:
		static TElASN1ConstrainedTagHandle CreateInstance();

		TElASN1ConstrainedTagHandle CreateInstance_Inst();

		virtual bool LoadFromBuffer(void * Buffer, int32_t Size);

		int32_t LoadFromBufferSingle(void * Buffer, int32_t Size);

		virtual bool SaveToBuffer(void * Buffer, int32_t &Size);

		bool SaveContentToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		virtual bool LoadFromStream(TStream &Stream, int64_t Count);

		virtual bool LoadFromStream(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool LoadFromStreamSingle(TStream &Stream, int64_t Count);

		bool LoadFromStreamSingle(TStream *Stream, int64_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void SaveToStream(TStream &Stream);

		virtual void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t AddField(bool Constrained);

		bool RemoveField(int32_t Index);

		TElASN1CustomTagHandle GetField(int32_t Index);

		void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElASN1ConstrainedTag, Count);

		virtual int32_t get_MaxSimpleTagLength();

		virtual void set_MaxSimpleTagLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSimpleTagLength, set_MaxSimpleTagLength, TElASN1ConstrainedTag, MaxSimpleTagLength);

		virtual TSBASN1StreamAccess get_StreamAccess();

		virtual void set_StreamAccess(TSBASN1StreamAccess Value);

		SB_DECLARE_PROPERTY(TSBASN1StreamAccess, get_StreamAccess, set_StreamAccess, TElASN1ConstrainedTag, StreamAccess);

		TElASN1ConstrainedTag(TElASN1ConstrainedTagHandle handle, TElOwnHandle ownHandle);

		TElASN1ConstrainedTag();

};
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_GLOBAL_PROCS_ASN1TREE

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
void asymWriteInteger(TElASN1SimpleTag &Tag, void * Buffer, int32_t Size);
void asymWriteInteger(TElASN1SimpleTag *Tag, void * Buffer, int32_t Size);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
int32_t ASN1ReadInteger(TElASN1SimpleTag &Tag);
int32_t ASN1ReadInteger(TElASN1SimpleTag *Tag);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
int64_t ASN1ReadInteger64(TElASN1SimpleTag &Tag);
int64_t ASN1ReadInteger64(TElASN1SimpleTag *Tag);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
void ASN1WriteInteger(TElASN1SimpleTag &Tag, int32_t Value);
void ASN1WriteInteger(TElASN1SimpleTag *Tag, int32_t Value);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
void ASN1WriteInteger64(TElASN1SimpleTag &Tag, int64_t Value);
void ASN1WriteInteger64(TElASN1SimpleTag *Tag, int64_t Value);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

void ASN1ReadSimpleValue(const std::vector<uint8_t> &Data, int32_t &TagID, std::vector<uint8_t> &OutResult);

void ASN1WriteTagAndLength(int32_t Tag, int64_t Len, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
bool ASN1ReadBoolean(TElASN1SimpleTag &Tag);
bool ASN1ReadBoolean(TElASN1SimpleTag *Tag);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

#ifdef SB_USE_CLASS_TELASN1SIMPLETAG
void ASN1WriteBoolean(TElASN1SimpleTag &Tag, bool Value);
void ASN1WriteBoolean(TElASN1SimpleTag *Tag, bool Value);
#endif /* SB_USE_CLASS_TELASN1SIMPLETAG */

void ASN1ReadString(const std::vector<uint8_t> &Data, int32_t TagId, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void ASN1ReadString(const std::vector<uint8_t> &Data, int32_t TagId, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

void ASN1ReadStringAnsi(const std::vector<uint8_t> &Data, int32_t TagId, std::string &OutResult);

void FormatAttributeValue(int32_t TagID, const std::vector<uint8_t> &Value, std::vector<uint8_t> &OutResult);

void UnformatAttributeValue(const std::vector<uint8_t> &Value, int32_t &TagID, std::vector<uint8_t> &OutResult);

int32_t GetMaxASN1TreeDepth();

void SetMaxASN1TreeDepth(int32_t Value);

int32_t GetMaxASN1BufferLength();

void SetMaxASN1BufferLength(int32_t Value);

#endif /* SB_USE_GLOBAL_PROCS_ASN1TREE */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ASN1TREE
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_asymWriteInteger(TElASN1SimpleTagHandle Tag, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadInteger(TElASN1SimpleTagHandle Tag, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadInteger64(TElASN1SimpleTagHandle Tag, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1WriteInteger(TElASN1SimpleTagHandle Tag, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1WriteInteger64(TElASN1SimpleTagHandle Tag, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadSimpleValue(const uint8_t pData[], int32_t szData, int32_t * TagID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1WriteTagAndLength(int32_t Tag, int64_t Len, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadBoolean(TElASN1SimpleTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1WriteBoolean(TElASN1SimpleTagHandle Tag, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadString(const uint8_t pData[], int32_t szData, int32_t TagId, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_ASN1ReadStringAnsi(const uint8_t pData[], int32_t szData, int32_t TagId, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_FormatAttributeValue(int32_t TagID, const uint8_t pValue[], int32_t szValue, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_UnformatAttributeValue(const uint8_t pValue[], int32_t szValue, int32_t * TagID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_GetMaxASN1TreeDepth(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_SetMaxASN1TreeDepth(int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_GetMaxASN1BufferLength(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1Tree_SetMaxASN1BufferLength(int32_t Value);
#endif /* SB_USE_GLOBAL_PROCS_ASN1TREE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASN1TREE */

