#ifndef __INC_SBASN1
#define __INC_SBASN1

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_asn1Boolean 	1
#define SB_asn1Integer 	2
#define SB_asn1BitStr 	3
#define SB_asn1OctetStr 	4
#define SB_asn1NULL 	5
#define SB_asn1Object 	6
#define SB_asn1Real 	9
#define SB_asn1Enumerated 	10
#define SB_asn1UTF8String 	12
#define SB_asn1Sequence 	16
#define SB_asn1Set 	17
#define SB_asn1NumericStr 	18
#define SB_asn1PrintableStr 	19
#define SB_asn1T61String 	20
#define SB_asn1TeletexStr 	20
#define SB_asn1IA5String 	22
#define SB_asn1UTCTime 	23
#define SB_asn1GeneralizedTime 	24
#define SB_asn1VisibleStr 	26
#define SB_asn1GeneralStr 	27
#define SB_asn1A0 	0
#define SB_asn1A1 	1
#define SB_asn1A2 	2
#define SB_asn1A3 	3
#define SB_asn1A4 	4
#define SB_asn1A5 	5
#define SB_asn1A6 	6
#define SB_asn1A7 	7
#define SB_asn1A8 	8
#define SB_ERROR_FACILITY_ASN1 	512
#define SB_ERROR_ASN1_INVALID_STRUCTURE 	513
#define SB_ERROR_ASN1_INVALID_LENGTH_VALUE 	514
#define SB_ERROR_ASN1_TAG_DEPTH_OVER_LIMIT 	515
#define SB_ERROR_ASN1_INVALID_STREAM_DATA 	516
#define SB_ERROR_ASN1_UNEXPECTED_STREAM_END 	517
#define SB_ERROR_ASN1_BUFFER_LENGTH_OVER_LIMIT 	518

typedef TElClassHandle TElASN1ParserHandle;

typedef uint8_t * SBASN1_PByte;

typedef uint8_t asn1TagTypeRaw;

typedef enum
{
	asn1tUniversal = 0,
	asn1tApplication = 1,
	asn1tSpecific = 2,
	asn1tPrivate = 3,
	asn1tEOC = 4
} asn1TagType;

typedef void (SB_CALLBACK *asn1tReadFunc)(void * Stream, void * Data, int32_t Size, int32_t * OutResult);

typedef void (SB_CALLBACK *asn1tWriteFunc)(void * Stream, void * Data, int32_t Size);

typedef void (SB_CALLBACK *asn1tCallBackFunc)(void * _ObjectData, void * Stream, asn1TagTypeRaw TagType, int8_t TagConstrained, void * Tag, int32_t TagSize, int32_t Size, void * Data, int32_t BitRest, int8_t * OutResult);

typedef void (SB_CALLBACK *TSBASN1ReadEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t * Size);

typedef void (SB_CALLBACK *TSBASN1TagEvent)(void * _ObjectData, TObjectHandle Sender, asn1TagTypeRaw TagType, int8_t TagConstrained, void * Tag, int32_t TagSize, int64_t Size, void * Data, int32_t BitRest, int8_t * Valid);

typedef void (SB_CALLBACK *TSBASN1TagHeaderEvent)(void * _ObjectData, TObjectHandle Sender, uint8_t TagID, int64_t TagLen, int32_t HeaderLen, int8_t UndefLen);

typedef void (SB_CALLBACK *TSBASN1SkipEvent)(void * _ObjectData, TObjectHandle Sender, int64_t * Count);

#ifdef SB_USE_CLASS_TELASN1PARSER
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_Parse(TElASN1ParserHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_RaiseOnEOC(TElASN1ParserHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_RaiseOnEOC(TElASN1ParserHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_MaxDataLength(TElASN1ParserHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_MaxDataLength(TElASN1ParserHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_MaxSimpleTagLength(TElASN1ParserHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_MaxSimpleTagLength(TElASN1ParserHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_OnRead(TElASN1ParserHandle _Handle, TSBASN1ReadEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_OnRead(TElASN1ParserHandle _Handle, TSBASN1ReadEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_OnTag(TElASN1ParserHandle _Handle, TSBASN1TagEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_OnTag(TElASN1ParserHandle _Handle, TSBASN1TagEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_OnTagHeader(TElASN1ParserHandle _Handle, TSBASN1TagHeaderEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_OnTagHeader(TElASN1ParserHandle _Handle, TSBASN1TagHeaderEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_get_OnSkip(TElASN1ParserHandle _Handle, TSBASN1SkipEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_set_OnSkip(TElASN1ParserHandle _Handle, TSBASN1SkipEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElASN1Parser_Create(TElASN1ParserHandle * OutResult);
#endif /* SB_USE_CLASS_TELASN1PARSER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElASN1Parser;

#ifdef SB_USE_CLASS_TELASN1PARSER
class TElASN1Parser: public TObject
{
	private:
		SB_DISABLE_COPY(TElASN1Parser)
	public:
		void Parse();

		virtual bool get_RaiseOnEOC();

		virtual void set_RaiseOnEOC(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RaiseOnEOC, set_RaiseOnEOC, TElASN1Parser, RaiseOnEOC);

		virtual int64_t get_MaxDataLength();

		virtual void set_MaxDataLength(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_MaxDataLength, set_MaxDataLength, TElASN1Parser, MaxDataLength);

		virtual int32_t get_MaxSimpleTagLength();

		virtual void set_MaxSimpleTagLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSimpleTagLength, set_MaxSimpleTagLength, TElASN1Parser, MaxSimpleTagLength);

		virtual void get_OnRead(TSBASN1ReadEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRead(TSBASN1ReadEvent pMethodValue, void * pDataValue);

		virtual void get_OnTag(TSBASN1TagEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTag(TSBASN1TagEvent pMethodValue, void * pDataValue);

		virtual void get_OnTagHeader(TSBASN1TagHeaderEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTagHeader(TSBASN1TagHeaderEvent pMethodValue, void * pDataValue);

		virtual void get_OnSkip(TSBASN1SkipEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSkip(TSBASN1SkipEvent pMethodValue, void * pDataValue);

		TElASN1Parser(TElASN1ParserHandle handle, TElOwnHandle ownHandle);

		TElASN1Parser();

};
#endif /* SB_USE_CLASS_TELASN1PARSER */

#ifdef SB_USE_GLOBAL_PROCS_ASN1

bool asn1AddTag(void * Stream, asn1TagType TagType, bool TagConstrained, void * Tag, int32_t TagSize, int32_t Size, void * Data, bool Revert, int32_t BitRest);

bool asn1AddTag(void * Stream, asn1TagType TagType, bool TagConstrained, uint8_t Tag, int32_t Size, void * Data, bool Revert, int32_t BitRest);

void asn1ParseStream(void * Stream, asn1tCallBackFunc pMethodCallBack, void * pDataCallBack);

bool asn1AddInt(void * Stream, int32_t Value, bool Revert);

bool asn1AddBool(void * Stream, bool Value);

bool asn1AddBuf(void * Stream, void * Value, int32_t Size);

bool asn1AddSeq(void * Stream);

bool asn1AddSet(void * Stream);

bool asn1AddConstrained(void * Stream, asn1TagType TagType, void * Tag, int32_t TagSize, int32_t Size);

bool asn1AddConstrained(void * Stream, asn1TagType TagType, uint8_t Tag, int32_t Size);

void asn1CloseConstrained(void * Stream);

void asn1AddTypeEqu(asn1TagType TagType1, void * Tag1, int32_t TagSize1, asn1TagType TagType2, void * Tag2, int32_t TagSize2);

void asn1AddTypeEqu(asn1TagType TagType1, void * Tag1, int32_t TagSize1, uint8_t Tag2);

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
void WriteListSequence(const TElByteArrayList &Strings, std::vector<uint8_t> &OutResult);
void WriteListSequence(const TElByteArrayList *Strings, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
void WritePrimitiveListSeq(uint8_t Tag, TElByteArrayList &Strings, std::vector<uint8_t> &OutResult);
void WritePrimitiveListSeq(uint8_t Tag, TElByteArrayList *Strings, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void WriteExplicit(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteInteger(const std::vector<uint8_t> &Data, uint8_t TagID, std::vector<uint8_t> &OutResult);

void WriteInteger(int32_t Number, uint8_t TagID, std::vector<uint8_t> &OutResult);

void WriteOID(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WritePrintableString(const std::string &Data, std::vector<uint8_t> &OutResult);

void WritePrintableString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteUTF8String(const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteUTF8String(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteIA5String(const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteIA5String(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteUTCTime(const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteGeneralizedTime(int64_t T, std::vector<uint8_t> &OutResult);

void WriteSize(uint32_t Size, std::vector<uint8_t> &OutResult);

void WriteBitString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteOctetString(const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteOctetString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteVisibleString(const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteBoolean(bool Data, std::vector<uint8_t> &OutResult);

void WriteNULL(std::vector<uint8_t> &OutResult);

void WritePrimitive(uint8_t Tag, const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

void WriteStringPrimitive(uint8_t Tag, const std::string &Data, std::vector<uint8_t> &OutResult);

void WriteStringPrimitive(uint8_t Tag, const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_ASN1 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ASN1
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddTag(void * Stream, asn1TagTypeRaw TagType, int8_t TagConstrained, void * Tag, int32_t TagSize, int32_t Size, void * Data, int8_t Revert, int32_t BitRest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddTag_1(void * Stream, asn1TagTypeRaw TagType, int8_t TagConstrained, uint8_t Tag, int32_t Size, void * Data, int8_t Revert, int32_t BitRest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1ParseStream(void * Stream, asn1tCallBackFunc pMethodCallBack, void * pDataCallBack);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddInt(void * Stream, int32_t Value, int8_t Revert, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddBool(void * Stream, int8_t Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddBuf(void * Stream, void * Value, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddSeq(void * Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddSet(void * Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddConstrained(void * Stream, asn1TagTypeRaw TagType, void * Tag, int32_t TagSize, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddConstrained_1(void * Stream, asn1TagTypeRaw TagType, uint8_t Tag, int32_t Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1CloseConstrained(void * Stream);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddTypeEqu(asn1TagTypeRaw TagType1, void * Tag1, int32_t TagSize1, asn1TagTypeRaw TagType2, void * Tag2, int32_t TagSize2);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_asn1AddTypeEqu_1(asn1TagTypeRaw TagType1, void * Tag1, int32_t TagSize1, uint8_t Tag2);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteListSequence(const TElByteArrayListHandle Strings, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WritePrimitiveListSeq(uint8_t Tag, TElByteArrayListHandle Strings, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteExplicit(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteInteger(const uint8_t pData[], int32_t szData, uint8_t TagID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteInteger_1(int32_t Number, uint8_t TagID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteOID(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WritePrintableString(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WritePrintableString_1(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteUTF8String(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteUTF8String_1(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteIA5String(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteIA5String_1(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteUTCTime(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteGeneralizedTime(int64_t T, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteSize(uint32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteBitString(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteOctetString(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteOctetString_1(const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteVisibleString(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteBoolean(int8_t Data, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteNULL(uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WritePrimitive(uint8_t Tag, const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteStringPrimitive(uint8_t Tag, const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBASN1_WriteStringPrimitive_1(uint8_t Tag, const uint8_t pData[], int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_ASN1 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASN1 */

