#include "sbziputils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_ZIPUTILS

SB_INLINE uint32_t BufferToUINT16(const std::vector<uint8_t> &Buffer, int32_t Index)
{
	uint32_t OutResult;
	SBCheckError(SBZipUtils_BufferToUINT16(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, &OutResult));
	return OutResult;
}

void UINT16ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, uint32_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBZipUtils_UINT16ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-502955716, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE uint32_t BufferToUINT32(const std::vector<uint8_t> &Buffer, int32_t Index)
{
	uint32_t OutResult;
	SBCheckError(SBZipUtils_BufferToUINT32(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, &OutResult));
	return OutResult;
}

void SBZipUtils_UINT32ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, uint32_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBZipUtils_UINT32ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(12906964, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE int64_t BufferToUINT64(const std::vector<uint8_t> &Buffer, int32_t Index)
{
	int64_t OutResult;
	SBCheckError(SBZipUtils_BufferToUINT64(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, &OutResult));
	return OutResult;
}

void UINT64ToBuffer(std::vector<uint8_t> &Buffer, int32_t Index, int64_t Value)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBZipUtils_UINT64ToBuffer((uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, Index, Value);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-118474735, 0, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void ReverseBuffer(const std::vector<uint8_t> &Buffer, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBZipUtils_ReverseBuffer(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-108175947, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void ZipInitializeEncryption(TSBZIPEncryptionContext &Context)
{
	SBCheckError(SBZipUtils_ZipInitializeEncryption(&Context));
}

SB_INLINE void ZipUpdateKeys(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size)
{
	SBCheckError(SBZipUtils_ZipUpdateKeys(&Context, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size));
}

void ZipEncrypt(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBZipUtils_ZipEncrypt(&Context, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(1326814311, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

void ZipDecrypt(TSBZIPEncryptionContext &Context, const std::vector<uint8_t> &Buffer, int32_t Index, int32_t Size, std::vector<uint8_t> &OutBuffer, int32_t OutIndex)
{
	int32_t szOutBuffer = (int32_t)OutBuffer.size();
	uint32_t _err = SBZipUtils_ZipDecrypt(&Context, SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Index, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer, OutIndex);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutBuffer.resize(szOutBuffer);
		SBCheckError(SBGetLastReturnBuffer(374433162, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutBuffer), &szOutBuffer));
	}
	else
		SBCheckError(_err);

	OutBuffer.resize(szOutBuffer);
}

SB_INLINE int32_t ZipHashAlgorithmToSBB(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBZipUtils_ZipHashAlgorithmToSBB(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t SBBHashAlgorithmToZip(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBZipUtils_SBBHashAlgorithmToZip(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ZipSymmetricAlgorithmToSBB(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBZipUtils_ZipSymmetricAlgorithmToSBB(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ZipCipherDefaultKeySize(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBZipUtils_ZipCipherDefaultKeySize(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t ZipCipherIVSize(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBZipUtils_ZipCipherIVSize(Algorithm, &OutResult));
	return OutResult;
}

void ZipCompressionMethodName(uint32_t CompressionMethod, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBZipUtils_ZipCompressionMethodName(CompressionMethod, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(503592161, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipEncryptionAlgorithmName(uint32_t EncryptionAlgorithm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBZipUtils_ZipEncryptionAlgorithmName(EncryptionAlgorithm, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1432719622, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ZipVersionStr(uint32_t Version, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBZipUtils_ZipVersionStr(Version, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1411239658, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void OEMEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBZipUtils_OEMEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1478486678, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ANSIEncodingName(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBZipUtils_ANSIEncodingName((char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-184804594, 0, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void CopyStreamPart(TStream &Source, int64_t SourcePosition, TStream &Dest, int64_t DestPosition, int64_t Size)
{
	SBCheckError(SBZipUtils_CopyStreamPart(Source.getHandle(), SourcePosition, Dest.getHandle(), DestPosition, Size));
}
SB_INLINE void CopyStreamPart(TStream *Source, int64_t SourcePosition, TStream *Dest, int64_t DestPosition, int64_t Size)
{
	SBCheckError(SBZipUtils_CopyStreamPart((Source != NULL) ? Source->getHandle() : SB_NULL_HANDLE, SourcePosition, (Dest != NULL) ? Dest->getHandle() : SB_NULL_HANDLE, DestPosition, Size));
}
#endif /* SB_USE_CLASS_TSTREAM */

#endif /* SB_USE_GLOBAL_PROCS_ZIPUTILS */

};	/* namespace SecureBlackbox */

