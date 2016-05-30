#ifndef __INC_SBPGPUTILS
#define __INC_SBPGPUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbrandom.h"
#include "sbdsa.h"
#include "sbrsa.h"
#include "sbsymmetriccrypto.h"
#include "sbpgpconstants.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_PGP_FILE_CREATE 	1
#define SB_PGP_FILE_READ 	2
#define SB_PGP_FILE_WRITE 	4

typedef uint8_t TSBKeyID[8];

#pragma pack(4)
typedef struct 
{
	void * Value0;
	void * Value1;
} TSBPGPSignatureMaterial;

#pragma pack(4)
typedef struct 
{
	void * Value0;
	void * Value1;
} TSBPGPEncryptedSymmetricKey;

typedef uint8_t TSBPGPSignatureTypeRaw;

typedef enum
{
	stNormal = 0,
	stOnePass = 1,
	stDetached = 2,
	stCleartext = 3
} TSBPGPSignatureType;

typedef uint8_t TSBPGPSignatureExtensionRaw;

typedef enum
{
	seUndefined = 0,
	seCreationTime = 1,
	seExpirationTime = 2,
	seExportable = 3,
	seTrust = 4,
	seRegExp = 5,
	seRevocable = 6,
	seKeyExpirationTime = 7,
	sePreferredSymAlg = 8,
	seRevocationKey = 9,
	seIssuerKeyID = 10,
	seNotationData = 11,
	sePreferredHashAlg = 12,
	sePreferredComprAlg = 13,
	seKeyServerPreferences = 14,
	sePreferredKeyServer = 15,
	sePrimaryUserID = 16,
	sePolicyURL = 17,
	seKeyFlags = 18,
	seSignerUserID = 19,
	seReasonForRevocation = 20,
	seFeatures = 21,
	seTarget = 22,
	seEmbeddedSig = 23,
	seX509Certificate = 24
} TSBPGPSignatureExtension;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_PGPUTILS

int64_t UTCTime();

int64_t TimestampToDateTime(uint32_t Timestamp);

uint32_t DateTimeToTimestamp(int64_t DateTime);

int32_t ReadMPInt(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, PLInt &Dest);

void WriteMPInt(PLInt Src, std::vector<uint8_t> &OutResult);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void WriteMPInt2(const std::vector<uint8_t> &Src, std::vector<uint8_t> &OutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

int32_t GetPGPPacketHeaderSize(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

uint8_t GetSigSubpktTypeByExtension(TSBPGPSignatureExtension ExtType);

void WriteSizeInt(uint32_t Size, void * Buffer, int32_t &ResSize);

void MPIntToByteArray(const std::vector<uint8_t> &Src, std::vector<uint8_t> &Dest, int32_t &OutSize);

bool IsCorrectHashAlgorithm(int32_t Algorithm);

bool IsCorrectSymmetricAlgorithm(int32_t Algorithm);

bool AlgorithmCanSign(int32_t Algorithm);

bool AlgorithmCanEncrypt(int32_t Algorithm);

int32_t TranslateMDAlgorithmFromPGP(int32_t Algorithm);

int32_t TranslateMDAlgorithmToPGP(int32_t Algorithm);

int32_t TranslateSKAlgorithmFromPGP(int32_t Algorithm);

int32_t TranslateSKAlgorithmToPGP(int32_t Algorithm);

int32_t TranslateMDAlgorithmToECDSA(int32_t Algorithm);

void AddPKCS1Prefix(const std::vector<uint8_t> &Hash, int32_t Algorithm, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
void SymmetricInitialize(int32_t Algorithm, TElSymmetricCrypto &Crypto, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &InitialVector);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
void SymmetricFinalize(TElSymmetricCrypto &Crypto);
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

int32_t MPIntSize(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size);

int32_t MPIntBitCount(const std::vector<uint8_t> &MPInt);

uint32_t CRC24(void * Buffer, int32_t Size, uint32_t Init);

uint16_t CalculateChecksum(const std::vector<uint8_t> &Buffer);

void ToBase64_3(const PByteArray InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer);

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void ToBase64_32(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

void ToBase64_2(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer);

void ToBase64_1(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer);

void FromBase64(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer);

void FromBase64(PByteArray InBuffer, PByteArray OutBuffer, int32_t &OutSize);

void FromBase64(uint8_t A, uint8_t B, uint8_t C, uint8_t D, void * Buffer, int32_t &Size);

int32_t SKGetBlockSize(int32_t Algorithm);

int32_t SKGetKeySize(int32_t Algorithm);

#ifdef SB_USE_CLASS_TELRANDOM
TElRandomHandle CreateAndInitRandom();
#endif /* SB_USE_CLASS_TELRANDOM */

int64_t Max64(int64_t X, int64_t Y);

int64_t Min64(int64_t X, int64_t Y);

bool IsPublicKeyEncryptionAlgorithm(int32_t Alg);

bool IsPublicKeySigningAlgorithm(int32_t Alg);

int32_t AlgorithmMPIntsPublic(int32_t Algorithm);

int32_t AlgorithmMPIntsSecret(int32_t Algorithm);

bool CompareKeyID(const TSBKeyID &ID1, const TSBKeyID &ID2);

bool CompareKeyFP(const std::vector<uint8_t> &FP1, const std::vector<uint8_t> &FP2);

bool CompareKeyIDArrays(const std::vector<uint8_t> &ID1, const std::vector<uint8_t> &ID2);

void GetSymmetricKeyAlgorithmName(int32_t Alg, std::string &OutResult);

int32_t GetSymmetricKeyAlgorithmByName(const std::string &Name);

void FormatPKCS1(const std::vector<uint8_t> &Modulus, const std::vector<uint8_t> &Data, uint8_t BlockType, std::vector<uint8_t> &OutResult);

void FormatPKCS1(PLInt Modulus, const std::vector<uint8_t> &Data, uint8_t BlockType, std::vector<uint8_t> &OutResult);

void UnformatPKCS1(const std::vector<uint8_t> &Data, uint8_t &BlockType, std::vector<uint8_t> &OutResult);

void UnformatPKCS1(PLInt Data, uint8_t &BlockType, std::vector<uint8_t> &OutResult);

int32_t PGPCurveByOID(const std::vector<uint8_t> &OID);

void OIDByPGPCurve(int32_t Curve, std::vector<uint8_t> &OutResult);

int32_t PGPCurveByBits(int32_t Bits);

int32_t BitsInPGPCurve(int32_t Curve);

int32_t HashAlgorithmByPGPCurve(int32_t Curve);

int32_t SymmetricAlgorithmByPGPCurve(int32_t Curve);

int32_t DetectMessageEncoding(const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size, int32_t &BOMSize);

int32_t BytesInEncoding(int32_t Encoding);

void UnicodeMessageToUtf8(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t &Size, const std::vector<uint8_t> &OutBuf, int32_t OutIndex, int32_t &OutSize);

int32_t IsCleartextMessage(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size);

int32_t SizeOfMessageInEncoding(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size);

bool SBPGPUtils_IsWhitespace(uint8_t B);

bool IsEOL(uint8_t B);

bool IsEmailChar(uint8_t B);

bool UserIDCorrespondsToEmail(const std::string &UserID, const std::string &Email);

void KeyID2Str(const TSBKeyID &KeyID, bool OnlyLowBytes, std::string &OutResult);

void KeyID2Array(const TSBKeyID &KeyID, std::vector<uint8_t> &OutResult);

void KeyFP2Str(const std::vector<uint8_t> &KeyFP, std::string &OutResult);

void PKAlg2Str(int32_t Alg, std::string &OutResult);

void HashAlg2Str(int32_t Alg, std::string &OutResult);

int32_t Str2HashAlg(const std::string &Alg);

void ComprAlg2Str(int32_t Alg, std::string &OutResult);

int32_t ConvertDaysToSeconds(int32_t Value);

int32_t ConvertSecondsToDays(int32_t Value);

void EncodePassword(const std::string &Password, std::vector<uint8_t> &OutResult);

void GetOpenPGPPasswordCharset(std::string &OutResult);

void SetOpenPGPPasswordCharset(const std::string &Value);

#endif /* SB_USE_GLOBAL_PROCS_PGPUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PGPUTILS
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_UTCTime(int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TimestampToDateTime(uint32_t Timestamp, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_DateTimeToTimestamp(int64_t DateTime, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ReadMPInt(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, PLInt * Dest, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_WriteMPInt(PLInt Src, uint8_t pOutResult[], int32_t * szOutResult);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_WriteMPInt2(const uint8_t pSrc[], int32_t szSrc, uint8_t pOutResult[], int32_t * szOutResult);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_GetPGPPacketHeaderSize(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_GetSigSubpktTypeByExtension(TSBPGPSignatureExtensionRaw ExtType, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_WriteSizeInt(uint32_t Size, void * Buffer, int32_t * ResSize);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_MPIntToByteArray(const uint8_t pSrc[], int32_t szSrc, uint8_t pDest[], int32_t * szDest, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsCorrectHashAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsCorrectSymmetricAlgorithm(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_AlgorithmCanSign(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_AlgorithmCanEncrypt(int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TranslateMDAlgorithmFromPGP(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TranslateMDAlgorithmToPGP(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TranslateSKAlgorithmFromPGP(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TranslateSKAlgorithmToPGP(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_TranslateMDAlgorithmToECDSA(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_AddPKCS1Prefix(const uint8_t pHash[], int32_t szHash, int32_t Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SymmetricInitialize(int32_t Algorithm, TElSymmetricCryptoHandle * Crypto, const uint8_t pKey[], int32_t szKey, const uint8_t pInitialVector[], int32_t szInitialVector);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SymmetricFinalize(TElSymmetricCryptoHandle * Crypto);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_MPIntSize(const uint8_t pBuffer[], int32_t szBuffer, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_MPIntBitCount(const uint8_t pMPInt[], int32_t szMPInt, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CRC24(void * Buffer, int32_t Size, uint32_t Init, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CalculateChecksum(const uint8_t pBuffer[], int32_t szBuffer, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ToBase64_3(const PByteArray InBuffer, int32_t Index, uint8_t pOutBuffer[], int32_t * szOutBuffer);
#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ToBase64_32(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t Index, uint8_t pOutBuffer[], int32_t * szOutBuffer);
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ToBase64_2(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t Index, uint8_t pOutBuffer[], int32_t * szOutBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ToBase64_1(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t Index, uint8_t pOutBuffer[], int32_t * szOutBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_FromBase64(const uint8_t pInBuffer[], int32_t szInBuffer, int32_t Index, uint8_t pOutBuffer[], int32_t * szOutBuffer);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_FromBase64_1(PByteArray InBuffer, PByteArray OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_FromBase64_2(uint8_t A, uint8_t B, uint8_t C, uint8_t D, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SKGetBlockSize(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SKGetKeySize(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CreateAndInitRandom(TElRandomHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_Max64(int64_t X, int64_t Y, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_Min64(int64_t X, int64_t Y, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsPublicKeyEncryptionAlgorithm(int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsPublicKeySigningAlgorithm(int32_t Alg, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_AlgorithmMPIntsPublic(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_AlgorithmMPIntsSecret(int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CompareKeyID(const TSBKeyID * ID1, const TSBKeyID * ID2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CompareKeyFP(const uint8_t pFP1[], int32_t szFP1, const uint8_t pFP2[], int32_t szFP2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_CompareKeyIDArrays(const uint8_t pID1[], int32_t szID1, const uint8_t pID2[], int32_t szID2, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_GetSymmetricKeyAlgorithmName(int32_t Alg, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_GetSymmetricKeyAlgorithmByName(const char * pcName, int32_t szName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_FormatPKCS1(const uint8_t pModulus[], int32_t szModulus, const uint8_t pData[], int32_t szData, uint8_t BlockType, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_FormatPKCS1_1(PLInt Modulus, const uint8_t pData[], int32_t szData, uint8_t BlockType, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_UnformatPKCS1(const uint8_t pData[], int32_t szData, uint8_t * BlockType, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_UnformatPKCS1_1(PLInt Data, uint8_t * BlockType, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_PGPCurveByOID(const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_OIDByPGPCurve(int32_t Curve, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_PGPCurveByBits(int32_t Bits, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_BitsInPGPCurve(int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_HashAlgorithmByPGPCurve(int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SymmetricAlgorithmByPGPCurve(int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_DetectMessageEncoding(const uint8_t pMsg[], int32_t szMsg, int32_t Index, int32_t Size, int32_t * BOMSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_BytesInEncoding(int32_t Encoding, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_UnicodeMessageToUtf8(int32_t Encoding, const uint8_t pMsg[], int32_t szMsg, int32_t Index, int32_t * Size, const uint8_t pOutBuf[], int32_t szOutBuf, int32_t OutIndex, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsCleartextMessage(int32_t Encoding, const uint8_t pMsg[], int32_t szMsg, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SizeOfMessageInEncoding(int32_t Encoding, const uint8_t pMsg[], int32_t szMsg, int32_t Index, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsWhitespace(uint8_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsEOL(uint8_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_IsEmailChar(uint8_t B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_UserIDCorrespondsToEmail(const char * pcUserID, int32_t szUserID, const char * pcEmail, int32_t szEmail, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_KeyID2Str(const TSBKeyID * KeyID, int8_t OnlyLowBytes, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_KeyID2Array(const TSBKeyID * KeyID, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_KeyFP2Str(const uint8_t pKeyFP[], int32_t szKeyFP, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_PKAlg2Str(int32_t Alg, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_HashAlg2Str(int32_t Alg, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_Str2HashAlg(const char * pcAlg, int32_t szAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ComprAlg2Str(int32_t Alg, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ConvertDaysToSeconds(int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_ConvertSecondsToDays(int32_t Value, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_EncodePassword(const char * pcPassword, int32_t szPassword, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_GetOpenPGPPasswordCharset(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBPGPUtils_SetOpenPGPPasswordCharset(const char * pcValue, int32_t szValue);
#endif /* SB_USE_GLOBAL_PROCS_PGPUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPUTILS */

