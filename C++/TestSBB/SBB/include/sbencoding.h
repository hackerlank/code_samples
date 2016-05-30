#ifndef __INC_SBENCODING
#define __INC_SBENCODING

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_BASE64_DECODE_OK 	0
#define SB_BASE64_DECODE_INVALID_CHARACTER 	1
#define SB_BASE64_DECODE_WRONG_DATA_SIZE 	2
#define SB_BASE64_DECODE_NOT_ENOUGH_SPACE 	3
#define SB_base64PadByte 	61
#define SB_BASE32_ERROR_BASE 	288
#define SB_BASE32_INVALID_DATA_SIZE 	289
#define SB_BASE32_INVALID_DATA 	290

#pragma pack(4)
typedef struct 
{
	uint8_t Tail[4];
	int32_t TailBytes;
	int32_t LineWritten;
	int32_t LineSize;
	int8_t TrailingEol;
	int8_t PutFirstEol;
	int8_t LiberalMode;
	uint8_t fEOL[4];
	int8_t _dummy0;
	int32_t EOLSize;
	uint8_t OutBuf[4];
	int32_t EQUCount;
} TSBBase64Context;

#pragma pack(4)
typedef struct 
{
	void * Tail;
	int32_t TailSize;
	int8_t UseExtAlphabet;
} TSBBase32Context;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_ENCODING

int32_t B64EstimateEncodedSize(TSBBase64Context &Ctx, int32_t InSize);

bool B64InitializeEncoding(TSBBase64Context &Ctx, int32_t LineSize, TSBEOLMarker fEOL, bool TrailingEOL);

bool B64InitializeDecoding(TSBBase64Context &Ctx);

bool B64InitializeDecoding(TSBBase64Context &Ctx, bool LiberalMode);

bool B64Encode(TSBBase64Context &Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize);

bool B64Decode(TSBBase64Context &Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize);

bool B64FinalizeEncoding(TSBBase64Context &Ctx, void * OutBuffer, int32_t &OutSize);

bool B64FinalizeDecoding(TSBBase64Context &Ctx, void * OutBuffer, int32_t &OutSize);

int32_t Base64UnicodeDecode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

int32_t Base64Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

int32_t Base64Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool LiberalMode);

bool Base64Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool WrapLines);

void Base64EncodeString(const std::string &InText, bool WrapLines, std::string &OutResult);

void Base64DecodeString(const std::string &InText, std::string &OutResult);

void Base64EncodeArray(const std::vector<uint8_t> &InBuf, bool WrapLines, std::string &OutResult);

void Base64DecodeArray(const std::string &InBuf, std::vector<uint8_t> &OutResult);

int32_t B32EstimateEncodedSize(const TSBBase32Context &Context, int32_t InSize);

void B32InitializeEncoding(TSBBase32Context &Context, bool UseExtendedAlphabet);

bool B32Encode(TSBBase32Context &Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize);

bool B32Encode(TSBBase32Context &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize);

bool B32FinalizeEncoding(TSBBase32Context &Context, void * OutBuffer, int32_t &OutSize);

bool B32FinalizeEncoding(TSBBase32Context &Context, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize);

bool Base32Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool UseExtendedAlphabet);

bool Base32Encode(const std::vector<uint8_t> &InBuffer, int32_t InIndex, int32_t InSize, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize, bool UseExtendedAlphabet);

void Base32EncodeBuffer(const std::vector<uint8_t> &Data, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult);

void Base32EncodeString(const std::string &Data, bool UseExtendedAlphabet, std::string &OutResult);

int32_t B32EstimateDecodedSize(const TSBBase32Context &Context, int32_t InSize);

void B32InitializeDecoding(TSBBase32Context &Context, bool UseExtendedAlphabet);

bool B32Decode(TSBBase32Context &Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize);

bool B32Decode(TSBBase32Context &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize);

bool Base32Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool UseExtendedAlphabet);

bool Base32Decode(const std::vector<uint8_t> &InBuffer, int32_t InIndex, int32_t InSize, std::vector<uint8_t> &OutBuffer, int32_t OutIndex, int32_t &OutSize, bool UseExtendedAlphabet);

bool B32FinalizeDecoding(TSBBase32Context &Context);

void Base32DecodeBuffer(const std::vector<uint8_t> &Data, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult);

void Base32DecodeString(const std::string &Data, bool UseExtendedAlphabet, std::string &OutResult);

void Base32Extract(const std::vector<uint8_t> &Data, int32_t Start, int32_t Size, bool UseExtendedAlphabet, std::vector<uint8_t> &OutResult);

void Base32Extract(const std::string &Data, int32_t Start, int32_t Size, bool UseExtendedAlphabet, std::string &OutResult);

void URLEncode(const std::string &Data, std::string &OutResult);

void URLEncode(const std::string &Data, const std::string &Charset, std::string &OutResult);

void URLEncode(const std::string &Data, const std::string &Charset, bool EncodeSlash, std::string &OutResult);

void URLDecode(const std::string &Data, bool FormEncoded, std::string &OutResult);

void URLDecode(const std::string &Data, const std::string &Charset, bool FormEncoded, std::string &OutResult);

void Base16DecodeString(const std::string &Data, std::vector<uint8_t> &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_ENCODING */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ENCODING
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64EstimateEncodedSize(TSBBase64Context * Ctx, int32_t InSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64InitializeEncoding(TSBBase64Context * Ctx, int32_t LineSize, TSBEOLMarkerRaw fEOL, int8_t TrailingEOL, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64InitializeDecoding(TSBBase64Context * Ctx, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64InitializeDecoding_1(TSBBase64Context * Ctx, int8_t LiberalMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64Encode(TSBBase64Context * Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64Decode(TSBBase64Context * Ctx, void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64FinalizeEncoding(TSBBase64Context * Ctx, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B64FinalizeDecoding(TSBBase64Context * Ctx, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64UnicodeDecode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64Decode_1(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t LiberalMode, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t WrapLines, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64EncodeString(const char * pcInText, int32_t szInText, int8_t WrapLines, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64DecodeString(const char * pcInText, int32_t szInText, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64EncodeArray(const uint8_t pInBuf[], int32_t szInBuf, int8_t WrapLines, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base64DecodeArray(const char * pcInBuf, int32_t szInBuf, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32EstimateEncodedSize(const TSBBase32Context * Context, int32_t InSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32InitializeEncoding(TSBBase32Context * Context, int8_t UseExtendedAlphabet);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32Encode(TSBBase32Context * Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32Encode_1(TSBBase32Context * Context, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32FinalizeEncoding(TSBBase32Context * Context, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32FinalizeEncoding_1(TSBBase32Context * Context, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Encode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t UseExtendedAlphabet, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Encode_1(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t InIndex, int32_t InSize, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex, int32_t * OutSize, int8_t UseExtendedAlphabet, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32EncodeBuffer(const uint8_t pData[], int32_t szData, int8_t UseExtendedAlphabet, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32EncodeString(const char * pcData, int32_t szData, int8_t UseExtendedAlphabet, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32EstimateDecodedSize(const TSBBase32Context * Context, int32_t InSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32InitializeDecoding(TSBBase32Context * Context, int8_t UseExtendedAlphabet);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32Decode(TSBBase32Context * Context, void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32Decode_1(TSBBase32Context * Context, const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Decode(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t UseExtendedAlphabet, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Decode_1(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t InIndex, int32_t InSize, uint8_t pOutBuffer[], int32_t * szOutBuffer, int32_t OutIndex, int32_t * OutSize, int8_t UseExtendedAlphabet, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_B32FinalizeDecoding(TSBBase32Context * Context, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32DecodeBuffer(const uint8_t pData[], int32_t szData, int8_t UseExtendedAlphabet, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32DecodeString(const char * pcData, int32_t szData, int8_t UseExtendedAlphabet, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Extract(const uint8_t pData[], int32_t szData, int32_t Start, int32_t Size, int8_t UseExtendedAlphabet, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base32Extract_1(const char * pcData, int32_t szData, int32_t Start, int32_t Size, int8_t UseExtendedAlphabet, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_URLEncode(const char * pcData, int32_t szData, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_URLEncode_1(const char * pcData, int32_t szData, const char * pcCharset, int32_t szCharset, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_URLEncode_2(const char * pcData, int32_t szData, const char * pcCharset, int32_t szCharset, int8_t EncodeSlash, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_URLDecode(const char * pcData, int32_t szData, int8_t FormEncoded, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_URLDecode_1(const char * pcData, int32_t szData, const char * pcCharset, int32_t szCharset, int8_t FormEncoded, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBEncoding_Base16DecodeString(const char * pcData, int32_t szData, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_ENCODING */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBENCODING */

