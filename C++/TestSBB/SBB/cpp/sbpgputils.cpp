#include "sbpgputils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_PGPUTILS

SB_INLINE int64_t UTCTime()
{
	int64_t OutResult;
	SBCheckError(SBPGPUtils_UTCTime(&OutResult));
	return OutResult;
}

SB_INLINE int64_t TimestampToDateTime(uint32_t Timestamp)
{
	int64_t OutResult;
	SBCheckError(SBPGPUtils_TimestampToDateTime(Timestamp, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t DateTimeToTimestamp(int64_t DateTime)
{
	uint32_t OutResult;
	SBCheckError(SBPGPUtils_DateTimeToTimestamp(DateTime, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ReadMPInt(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, PLInt &Dest)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_ReadMPInt(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &Dest, &OutResult));
	return OutResult;
}

void WriteMPInt(PLInt Src, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_WriteMPInt(Src, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(296691847, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void WriteMPInt2(const std::vector<uint8_t> &Src, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_WriteMPInt2(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-967208149, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

SB_INLINE int32_t GetPGPPacketHeaderSize(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_GetPGPPacketHeaderSize(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE uint8_t GetSigSubpktTypeByExtension(TSBPGPSignatureExtension ExtType)
{
	uint8_t OutResult;
	SBCheckError(SBPGPUtils_GetSigSubpktTypeByExtension((TSBPGPSignatureExtensionRaw)ExtType, &OutResult));
	return OutResult;
}

SB_INLINE void WriteSizeInt(uint32_t Size, void * Buffer, int32_t &ResSize)
{
	SBCheckError(SBPGPUtils_WriteSizeInt(Size, Buffer, &ResSize));
}

void MPIntToByteArray(const std::vector<uint8_t> &Src, std::vector<uint8_t> &Dest, int32_t &OutSize)
{
	int32_t szDest = (int32_t)Dest.size();
	uint32_t _err = SBPGPUtils_MPIntToByteArray(SB_STD_VECTOR_FRONT_ADR(Src), (int32_t)Src.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Dest), &szDest, &OutSize);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Dest.resize(szDest);
		SBCheckError(SBGetLastReturnBuffer(-165285324, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Dest), &szDest));
	}
	else
		SBCheckError(_err);

	Dest.resize(szDest);
}

bool IsCorrectHashAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsCorrectHashAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsCorrectSymmetricAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsCorrectSymmetricAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool AlgorithmCanSign(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_AlgorithmCanSign(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool AlgorithmCanEncrypt(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_AlgorithmCanEncrypt(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TranslateMDAlgorithmFromPGP(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_TranslateMDAlgorithmFromPGP(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TranslateMDAlgorithmToPGP(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_TranslateMDAlgorithmToPGP(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TranslateSKAlgorithmFromPGP(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_TranslateSKAlgorithmFromPGP(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TranslateSKAlgorithmToPGP(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_TranslateSKAlgorithmToPGP(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TranslateMDAlgorithmToECDSA(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_TranslateMDAlgorithmToECDSA(Algorithm, &OutResult));
	return OutResult;
}

void AddPKCS1Prefix(const std::vector<uint8_t> &Hash, int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_AddPKCS1Prefix(SB_STD_VECTOR_FRONT_ADR(Hash), (int32_t)Hash.size(), Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(788156586, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
void SymmetricInitialize(int32_t Algorithm, TElSymmetricCrypto &Crypto, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &InitialVector)
{
	TElClassHandle hCrypto = Crypto.getHandle();
	SBCheckError(SBPGPUtils_SymmetricInitialize(Algorithm, &hCrypto, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(InitialVector), (int32_t)InitialVector.size()));
	Crypto.updateHandle(hCrypto);
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

#ifdef SB_USE_CLASS_TELSYMMETRICCRYPTO
void SymmetricFinalize(TElSymmetricCrypto &Crypto)
{
	TElClassHandle hCrypto = Crypto.getHandle();
	SBCheckError(SBPGPUtils_SymmetricFinalize(&hCrypto));
	Crypto.updateHandle(hCrypto);
}
#endif /* SB_USE_CLASS_TELSYMMETRICCRYPTO */

SB_INLINE int32_t MPIntSize(const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_MPIntSize(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t MPIntBitCount(const std::vector<uint8_t> &MPInt)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_MPIntBitCount(SB_STD_VECTOR_FRONT_ADR(MPInt), (int32_t)MPInt.size(), &OutResult));
	return OutResult;
}

SB_INLINE uint32_t CRC24(void * Buffer, int32_t Size, uint32_t Init)
{
	uint32_t OutResult;
	SBCheckError(SBPGPUtils_CRC24(Buffer, Size, Init, &OutResult));
	return OutResult;
}

SB_INLINE uint16_t CalculateChecksum(const std::vector<uint8_t> &Buffer)
{
	uint16_t OutResult;
	SBCheckError(SBPGPUtils_CalculateChecksum(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &OutResult));
	return OutResult;
}

void ToBase64_3(const PByteArray InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBPGPUtils_ToBase64_3(InBuffer, Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-2109674466, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

#ifdef SB_DEFINE_FPC_SPECIFIC_METHODS
void ToBase64_32(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBPGPUtils_ToBase64_32(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-158631730, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}
#endif /* SB_DEFINE_FPC_SPECIFIC_METHODS */

void ToBase64_2(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBPGPUtils_ToBase64_2(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(1092323195, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

void ToBase64_1(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBPGPUtils_ToBase64_1(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(-468456425, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

void FromBase64(const std::vector<uint8_t> &InBuffer, int32_t Index, std::vector<uint8_t> &OutBuffer)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBPGPUtils_FromBase64(SB_STD_VECTOR_FRONT_ADR(InBuffer), (int32_t)InBuffer.size(), Index, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(85218919, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

SB_INLINE void FromBase64(PByteArray InBuffer, PByteArray OutBuffer, int32_t &OutSize)
{
	SBCheckError(SBPGPUtils_FromBase64_1(InBuffer, OutBuffer, &OutSize));
}

SB_INLINE void FromBase64(uint8_t A, uint8_t B, uint8_t C, uint8_t D, void * Buffer, int32_t &Size)
{
	SBCheckError(SBPGPUtils_FromBase64_2(A, B, C, D, Buffer, &Size));
}

SB_INLINE int32_t SKGetBlockSize(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_SKGetBlockSize(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SKGetKeySize(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_SKGetKeySize(Algorithm, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELRANDOM
SB_INLINE TElRandomHandle CreateAndInitRandom()
{
	TElRandomHandle OutResult;
	SBCheckError(SBPGPUtils_CreateAndInitRandom(&OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRANDOM */

SB_INLINE int64_t Max64(int64_t X, int64_t Y)
{
	int64_t OutResult;
	SBCheckError(SBPGPUtils_Max64(X, Y, &OutResult));
	return OutResult;
}

SB_INLINE int64_t Min64(int64_t X, int64_t Y)
{
	int64_t OutResult;
	SBCheckError(SBPGPUtils_Min64(X, Y, &OutResult));
	return OutResult;
}

bool IsPublicKeyEncryptionAlgorithm(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsPublicKeyEncryptionAlgorithm(Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsPublicKeySigningAlgorithm(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsPublicKeySigningAlgorithm(Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t AlgorithmMPIntsPublic(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_AlgorithmMPIntsPublic(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t AlgorithmMPIntsSecret(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_AlgorithmMPIntsSecret(Algorithm, &OutResult));
	return OutResult;
}

bool CompareKeyID(const TSBKeyID &ID1, const TSBKeyID &ID2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_CompareKeyID(&ID1, &ID2, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareKeyFP(const std::vector<uint8_t> &FP1, const std::vector<uint8_t> &FP2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_CompareKeyFP(SB_STD_VECTOR_FRONT_ADR(FP1), (int32_t)FP1.size(), SB_STD_VECTOR_FRONT_ADR(FP2), (int32_t)FP2.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool CompareKeyIDArrays(const std::vector<uint8_t> &ID1, const std::vector<uint8_t> &ID2)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_CompareKeyIDArrays(SB_STD_VECTOR_FRONT_ADR(ID1), (int32_t)ID1.size(), SB_STD_VECTOR_FRONT_ADR(ID2), (int32_t)ID2.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void GetSymmetricKeyAlgorithmName(int32_t Alg, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_GetSymmetricKeyAlgorithmName(Alg, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1734895530, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetSymmetricKeyAlgorithmByName(const std::string &Name)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_GetSymmetricKeyAlgorithmByName(Name.data(), (int32_t)Name.length(), &OutResult));
	return OutResult;
}

void FormatPKCS1(const std::vector<uint8_t> &Modulus, const std::vector<uint8_t> &Data, uint8_t BlockType, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_FormatPKCS1(SB_STD_VECTOR_FRONT_ADR(Modulus), (int32_t)Modulus.size(), SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), BlockType, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(299555139, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void FormatPKCS1(PLInt Modulus, const std::vector<uint8_t> &Data, uint8_t BlockType, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_FormatPKCS1_1(Modulus, SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), BlockType, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(264231217, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnformatPKCS1(const std::vector<uint8_t> &Data, uint8_t &BlockType, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_UnformatPKCS1(SB_STD_VECTOR_FRONT_ADR(Data), (int32_t)Data.size(), &BlockType, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(132469661, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void UnformatPKCS1(PLInt Data, uint8_t &BlockType, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_UnformatPKCS1_1(Data, &BlockType, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-489064504, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t PGPCurveByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_PGPCurveByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void OIDByPGPCurve(int32_t Curve, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_OIDByPGPCurve(Curve, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1256322168, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t PGPCurveByBits(int32_t Bits)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_PGPCurveByBits(Bits, &OutResult));
	return OutResult;
}

SB_INLINE int32_t BitsInPGPCurve(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_BitsInPGPCurve(Curve, &OutResult));
	return OutResult;
}

SB_INLINE int32_t HashAlgorithmByPGPCurve(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_HashAlgorithmByPGPCurve(Curve, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SymmetricAlgorithmByPGPCurve(int32_t Curve)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_SymmetricAlgorithmByPGPCurve(Curve, &OutResult));
	return OutResult;
}

SB_INLINE int32_t DetectMessageEncoding(const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size, int32_t &BOMSize)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_DetectMessageEncoding(SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), Index, Size, &BOMSize, &OutResult));
	return OutResult;
}

SB_INLINE int32_t BytesInEncoding(int32_t Encoding)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_BytesInEncoding(Encoding, &OutResult));
	return OutResult;
}

SB_INLINE void UnicodeMessageToUtf8(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t &Size, const std::vector<uint8_t> &OutBuf, int32_t OutIndex, int32_t &OutSize)
{
	SBCheckError(SBPGPUtils_UnicodeMessageToUtf8(Encoding, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), Index, &Size, SB_STD_VECTOR_FRONT_ADR(OutBuf), (int32_t)OutBuf.size(), OutIndex, &OutSize));
}

SB_INLINE int32_t IsCleartextMessage(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_IsCleartextMessage(Encoding, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), Index, Size, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SizeOfMessageInEncoding(int32_t Encoding, const std::vector<uint8_t> &Msg, int32_t Index, int32_t Size)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_SizeOfMessageInEncoding(Encoding, SB_STD_VECTOR_FRONT_ADR(Msg), (int32_t)Msg.size(), Index, Size, &OutResult));
	return OutResult;
}

bool SBPGPUtils_IsWhitespace(uint8_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsWhitespace(B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsEOL(uint8_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsEOL(B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsEmailChar(uint8_t B)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_IsEmailChar(B, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool UserIDCorrespondsToEmail(const std::string &UserID, const std::string &Email)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBPGPUtils_UserIDCorrespondsToEmail(UserID.data(), (int32_t)UserID.length(), Email.data(), (int32_t)Email.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

void KeyID2Str(const TSBKeyID &KeyID, bool OnlyLowBytes, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_KeyID2Str(&KeyID, (int8_t)OnlyLowBytes, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1382129249, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void KeyID2Array(const TSBKeyID &KeyID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_KeyID2Array(&KeyID, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-62333045, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void KeyFP2Str(const std::vector<uint8_t> &KeyFP, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_KeyFP2Str(SB_STD_VECTOR_FRONT_ADR(KeyFP), (int32_t)KeyFP.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-213283502, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void PKAlg2Str(int32_t Alg, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_PKAlg2Str(Alg, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1765591422, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void HashAlg2Str(int32_t Alg, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_HashAlg2Str(Alg, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(480117847, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t Str2HashAlg(const std::string &Alg)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_Str2HashAlg(Alg.data(), (int32_t)Alg.length(), &OutResult));
	return OutResult;
}

void ComprAlg2Str(int32_t Alg, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_ComprAlg2Str(Alg, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1777262187, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t ConvertDaysToSeconds(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_ConvertDaysToSeconds(Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ConvertSecondsToDays(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(SBPGPUtils_ConvertSecondsToDays(Value, &OutResult));
	return OutResult;
}

void EncodePassword(const std::string &Password, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBPGPUtils_EncodePassword(Password.data(), (int32_t)Password.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-821304808, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetOpenPGPPasswordCharset(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPGPUtils_GetOpenPGPPasswordCharset((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1630014405, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void SetOpenPGPPasswordCharset(const std::string &Value)
{
	SBCheckError(SBPGPUtils_SetOpenPGPPasswordCharset(Value.data(), (int32_t)Value.length()));
}

#endif /* SB_USE_GLOBAL_PROCS_PGPUTILS */

};	/* namespace SecureBlackbox */

