#include "sbencoding.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ENCODING

SB_INLINE int32_t B64EstimateEncodedSize(TSBBase64Context &Ctx, int32_t InSize)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_B64EstimateEncodedSize(&Ctx, InSize, &OutResult));
	return OutResult;
}

bool B64InitializeEncoding(TSBBase64Context &Ctx, int32_t LineSize, TSBEOLMarker fEOL, bool TrailingEOL)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64InitializeEncoding(&Ctx, LineSize, (TSBEOLMarkerRaw)fEOL, (int8_t)TrailingEOL, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64InitializeDecoding(TSBBase64Context &Ctx)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64InitializeDecoding(&Ctx, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64InitializeDecoding(TSBBase64Context &Ctx, bool LiberalMode)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64InitializeDecoding_1(&Ctx, (int8_t)LiberalMode, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64Encode(TSBBase64Context &Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64Encode(&Ctx, Buffer, Size, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64Decode(TSBBase64Context &Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64Decode(&Ctx, Buffer, Size, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64FinalizeEncoding(TSBBase64Context &Ctx, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64FinalizeEncoding(&Ctx, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B64FinalizeDecoding(TSBBase64Context &Ctx, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B64FinalizeDecoding(&Ctx, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t Base64UnicodeDecode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_Base64UnicodeDecode(InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t Base64Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_Base64Decode(InBuffer, InSize, OutBuffer, &OutSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t Base64Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool LiberalMode)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_Base64Decode_1(InBuffer, InSize, OutBuffer, &OutSize, (int8_t)LiberalMode, &OutResult));
	return OutResult;
}

bool Base64Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool WrapLines)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_Base64Encode(InBuffer, InSize, OutBuffer, &OutSize, (int8_t)WrapLines, &OutResultRaw));
	return (OutResultRaw != 0);
}

void Base64EncodeString(const std::string &InText, bool WrapLines, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base64EncodeString(InText.data(), (int32_t)InText.length(), (int8_t)WrapLines, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1634586890, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base64DecodeString(const std::string &InText, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base64DecodeString(InText.data(), (int32_t)InText.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-168055631, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base64EncodeArray(const std::vector<uint8_t> &InBuf, bool WrapLines, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base64EncodeArray(SB_STD_VECTOR_FRONT_ADR(InBuf), (int32_t)InBuf.size(), (int8_t)WrapLines, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(452873298, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base64DecodeArray(const std::string &InBuf, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBEncoding_Base64DecodeArray(InBuf.data(), (int32_t)InBuf.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(987937500, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t B32EstimateEncodedSize(const TSBBase32Context &Context, int32_t InSize)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_B32EstimateEncodedSize(&Context, InSize, &OutResult));
	return OutResult;
}

SB_INLINE void B32InitializeEncoding(TSBBase32Context &Context, bool UseExtendedAlphabet)
{
	SBCheckError(SBEncoding_B32InitializeEncoding(&Context, (int8_t)UseExtendedAlphabet));
}

bool B32Encode(TSBBase32Context &Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B32Encode(&Context, Buffer, Size, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B32Encode(TSBBase32Context &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBEncoding_B32Encode_1(&Context, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex, &OutSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1340161507, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

bool B32FinalizeEncoding(TSBBase32Context &Context, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B32FinalizeEncoding(&Context, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B32FinalizeEncoding(TSBBase32Context &Context, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBEncoding_B32FinalizeEncoding_1(&Context, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex, &OutSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(960089823, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

bool Base32Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool UseExtendedAlphabet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_Base32Encode(InBuffer, InSize, OutBuffer, &OutSize, (int8_t)UseExtendedAlphabet, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Base32Encode(const std::vector<uint8_t> &InBuffer, int32_t InIndex, int32_t InSize, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize, bool UseExtendedAlphabet)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBEncoding_Base32Encode_1(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), InIndex, InSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex, &OutSize, (int8_t)UseExtendedAlphabet, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(2091718458, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

void Base32EncodeBuffer(const std::vector<uint8_t> &Data, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBEncoding_Base32EncodeBuffer(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (int8_t)UseExtendedAlphabet, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-43335181, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base32EncodeString(const std::string &Data, bool UseExtendedAlphabet, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base32EncodeString(Data.data(), (int32_t)Data.length(), (int8_t)UseExtendedAlphabet, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1426310981, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t B32EstimateDecodedSize(const TSBBase32Context &Context, int32_t InSize)
{
	int32_t OutResult;
	SBCheckError(SBEncoding_B32EstimateDecodedSize(&Context, InSize, &OutResult));
	return OutResult;
}

SB_INLINE void B32InitializeDecoding(TSBBase32Context &Context, bool UseExtendedAlphabet)
{
	SBCheckError(SBEncoding_B32InitializeDecoding(&Context, (int8_t)UseExtendedAlphabet));
}

bool B32Decode(TSBBase32Context &Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B32Decode(&Context, Buffer, Size, OutBuffer, &OutSize, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool B32Decode(TSBBase32Context &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBEncoding_B32Decode_1(&Context, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex, &OutSize, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-888658432, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

bool Base32Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool UseExtendedAlphabet)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_Base32Decode(InBuffer, InSize, OutBuffer, &OutSize, (int8_t)UseExtendedAlphabet, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool Base32Decode(const std::vector<uint8_t> &InBuffer, int32_t InIndex, int32_t InSize, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize, bool UseExtendedAlphabet)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBEncoding_Base32Decode_1(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), InIndex, InSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex, &OutSize, (int8_t)UseExtendedAlphabet, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1956516538, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
	return (OutResultRaw != 0);
}

bool B32FinalizeDecoding(TSBBase32Context &Context)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBEncoding_B32FinalizeDecoding(&Context, &OutResultRaw));
	return (OutResultRaw != 0);
}

void Base32DecodeBuffer(const std::vector<uint8_t> &Data, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBEncoding_Base32DecodeBuffer(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), (int8_t)UseExtendedAlphabet, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1737615164, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base32DecodeString(const std::string &Data, bool UseExtendedAlphabet, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base32DecodeString(Data.data(), (int32_t)Data.length(), (int8_t)UseExtendedAlphabet, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-973826053, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base32Extract(const std::vector<uint8_t> &Data, int32_t Start, int32_t Size, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBEncoding_Base32Extract(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), Start, Size, (int8_t)UseExtendedAlphabet, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1289600535, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base32Extract(const std::string &Data, int32_t Start, int32_t Size, bool UseExtendedAlphabet, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_Base32Extract_1(Data.data(), (int32_t)Data.length(), Start, Size, (int8_t)UseExtendedAlphabet, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1530993079, 4, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLEncode(const std::string &Data, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_URLEncode(Data.data(), (int32_t)Data.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1746583145, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLEncode(const std::string &Data, const std::string &Charset, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_URLEncode_1(Data.data(), (int32_t)Data.length(), Charset.data(), (int32_t)Charset.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1295390874, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLEncode(const std::string &Data, const std::string &Charset, bool EncodeSlash, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_URLEncode_2(Data.data(), (int32_t)Data.length(), Charset.data(), (int32_t)Charset.length(), (int8_t)EncodeSlash, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-405798349, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLDecode(const std::string &Data, bool FormEncoded, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_URLDecode(Data.data(), (int32_t)Data.length(), (int8_t)FormEncoded, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1573117443, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void URLDecode(const std::string &Data, const std::string &Charset, bool FormEncoded, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBEncoding_URLDecode_1(Data.data(), (int32_t)Data.length(), Charset.data(), (int32_t)Charset.length(), (int8_t)FormEncoded, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1180530169, 3, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void Base16DecodeString(const std::string &Data, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBEncoding_Base16DecodeString(Data.data(), (int32_t)Data.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(938624788, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_ENCODING */

};	/* namespace SecureBlackbox */

