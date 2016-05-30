#include "sbasn1.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELASN1PARSER

SB_INLINE void TElASN1Parser::Parse()
{
	SBCheckError(TElASN1Parser_Parse(_Handle));
}

bool TElASN1Parser::get_RaiseOnEOC()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElASN1Parser_get_RaiseOnEOC(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElASN1Parser::set_RaiseOnEOC(bool Value)
{
	SBCheckError(TElASN1Parser_set_RaiseOnEOC(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElASN1Parser::get_MaxDataLength()
{
	int64_t OutResult;
	SBCheckError(TElASN1Parser_get_MaxDataLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1Parser::set_MaxDataLength(int64_t Value)
{
	SBCheckError(TElASN1Parser_set_MaxDataLength(_Handle, Value));
}

SB_INLINE int32_t TElASN1Parser::get_MaxSimpleTagLength()
{
	int32_t OutResult;
	SBCheckError(TElASN1Parser_get_MaxSimpleTagLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElASN1Parser::set_MaxSimpleTagLength(int32_t Value)
{
	SBCheckError(TElASN1Parser_set_MaxSimpleTagLength(_Handle, Value));
}

SB_INLINE void TElASN1Parser::get_OnRead(TSBASN1ReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1Parser_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1Parser::set_OnRead(TSBASN1ReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1Parser_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElASN1Parser::get_OnTag(TSBASN1TagEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1Parser_get_OnTag(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1Parser::set_OnTag(TSBASN1TagEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1Parser_set_OnTag(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElASN1Parser::get_OnTagHeader(TSBASN1TagHeaderEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1Parser_get_OnTagHeader(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1Parser::set_OnTagHeader(TSBASN1TagHeaderEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1Parser_set_OnTagHeader(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElASN1Parser::get_OnSkip(TSBASN1SkipEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElASN1Parser_get_OnSkip(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElASN1Parser::set_OnSkip(TSBASN1SkipEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElASN1Parser_set_OnSkip(_Handle, pMethodValue, pDataValue));
}

TElASN1Parser::TElASN1Parser(TElASN1ParserHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElASN1Parser::TElASN1Parser() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElASN1Parser_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELASN1PARSER */

#ifdef SB_USE_GLOBAL_PROCS_ASN1

bool asn1AddTag(void * Stream, asn1TagType TagType, bool TagConstrained, void * Tag, int32_t TagSize, int32_t Size, void * Data, bool Revert, int32_t BitRest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddTag(Stream, (asn1TagTypeRaw)TagType, (int8_t)TagConstrained, Tag, TagSize, Size, Data, (int8_t)Revert, BitRest, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddTag(void * Stream, asn1TagType TagType, bool TagConstrained, uint8_t Tag, int32_t Size, void * Data, bool Revert, int32_t BitRest)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddTag_1(Stream, (asn1TagTypeRaw)TagType, (int8_t)TagConstrained, Tag, Size, Data, (int8_t)Revert, BitRest, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void asn1ParseStream(void * Stream, asn1tCallBackFunc pMethodCallBack, void * pDataCallBack)
{
	SBCheckError(SBASN1_asn1ParseStream(Stream, pMethodCallBack, pDataCallBack));
}

bool asn1AddInt(void * Stream, int32_t Value, bool Revert)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddInt(Stream, Value, (int8_t)Revert, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddBool(void * Stream, bool Value)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddBool(Stream, (int8_t)Value, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddBuf(void * Stream, void * Value, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddBuf(Stream, Value, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddSeq(void * Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddSeq(Stream, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddSet(void * Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddSet(Stream, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddConstrained(void * Stream, asn1TagType TagType, void * Tag, int32_t TagSize, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddConstrained(Stream, (asn1TagTypeRaw)TagType, Tag, TagSize, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool asn1AddConstrained(void * Stream, asn1TagType TagType, uint8_t Tag, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBASN1_asn1AddConstrained_1(Stream, (asn1TagTypeRaw)TagType, Tag, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void asn1CloseConstrained(void * Stream)
{
	SBCheckError(SBASN1_asn1CloseConstrained(Stream));
}

SB_INLINE void asn1AddTypeEqu(asn1TagType TagType1, void * Tag1, int32_t TagSize1, asn1TagType TagType2, void * Tag2, int32_t TagSize2)
{
	SBCheckError(SBASN1_asn1AddTypeEqu((asn1TagTypeRaw)TagType1, Tag1, TagSize1, (asn1TagTypeRaw)TagType2, Tag2, TagSize2));
}

SB_INLINE void asn1AddTypeEqu(asn1TagType TagType1, void * Tag1, int32_t TagSize1, uint8_t Tag2)
{
	SBCheckError(SBASN1_asn1AddTypeEqu_1((asn1TagTypeRaw)TagType1, Tag1, TagSize1, Tag2));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
void WriteListSequence(const TElByteArrayList &Strings, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteListSequence(Strings.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1525758728, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void WriteListSequence(const TElByteArrayList *Strings, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteListSequence((Strings != NULL) ? Strings->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1525758728, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
void WritePrimitiveListSeq(uint8_t Tag, TElByteArrayList &Strings, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WritePrimitiveListSeq(Tag, Strings.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1046311541, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void WritePrimitiveListSeq(uint8_t Tag, TElByteArrayList *Strings, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WritePrimitiveListSeq(Tag, (Strings != NULL) ? Strings->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1046311541, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

void WriteExplicit(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteExplicit(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1409445467, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteInteger(const std::vector<uint8_t> &Data, uint8_t TagID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteInteger(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), TagID, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1992790702, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteInteger(int32_t Number, uint8_t TagID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteInteger_1(Number, TagID, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-732376845, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteOID(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteOID(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1090962388, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WritePrintableString(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WritePrintableString(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-973319837, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WritePrintableString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WritePrintableString_1(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-721553012, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteUTF8String(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteUTF8String(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2016027842, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteUTF8String(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteUTF8String_1(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1341114533, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteIA5String(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteIA5String(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1880773778, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteIA5String(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteIA5String_1(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-499697359, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteUTCTime(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteUTCTime(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1942559608, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteGeneralizedTime(int64_t T, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteGeneralizedTime(T, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(155410368, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteSize(uint32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteSize(Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(520404123, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteBitString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteBitString(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(517762275, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteOctetString(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteOctetString(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(653348048, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteOctetString(const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteOctetString_1(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1158981628, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteVisibleString(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteVisibleString(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1518160340, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteBoolean(bool Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteBoolean((int8_t)Data, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(928009551, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteNULL(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteNULL((uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1140307095, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WritePrimitive(uint8_t Tag, const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WritePrimitive(Tag, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(569238472, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteStringPrimitive(uint8_t Tag, const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteStringPrimitive(Tag, Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-497425069, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteStringPrimitive(uint8_t Tag, const std::vector<uint8_t> &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBASN1_WriteStringPrimitive_1(Tag, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1929929725, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_ASN1 */

};	/* namespace SecureBlackbox */

