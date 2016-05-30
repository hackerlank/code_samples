#include "sbsshutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_SSHUTILS

void WriteString(const std::vector<uint8_t> &S, bool AddZero, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_WriteString(SB_STD_VECTOR_FRONT_ADR(S), (int32_t)S.size(), (int8_t)AddZero, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(113192368, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void WriteBitCount(void * P, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_WriteBitCount(P, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(810882978, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReadSSH2MPInt(void * P, int32_t Size, int32_t &HeaderSz, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_ReadSSH2MPInt(P, Size, &HeaderSz, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(318034406, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ReadBoolean(void * P, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBSSHUtils_ReadBoolean(P, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

void ReadString(void * Buffer, int32_t Size, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBSSHUtils_ReadString(Buffer, Size, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(180783279, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReadBuffer(void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_ReadBuffer(Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(780676395, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReadBuffer(const std::vector<uint8_t> &Buffer, int32_t AIndex, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_ReadBuffer_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), AIndex, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1382962299, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReadSSH1MPInt(void * Buffer, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_ReadSSH1MPInt(Buffer, Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1406979880, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE uint32_t ReadLength(void * Buffer, int32_t Size)
{
	uint32_t OutResult;
	SBCheckError(SBSSHUtils_ReadLength(Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t ReadLength(const std::vector<uint8_t> &Buffer, int32_t AIndex, int32_t Size)
{
	uint32_t OutResult;
	SBCheckError(SBSSHUtils_ReadLength_1(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), AIndex, Size, &OutResult));
	return OutResult;
}

SB_INLINE uint16_t ReadUINT16(void * Buffer, int32_t Size)
{
	uint16_t OutResult;
	SBCheckError(SBSSHUtils_ReadUINT16(Buffer, Size, &OutResult));
	return OutResult;
}

SB_INLINE int64_t ReadUINT64(void * Buffer, int32_t Size)
{
	int64_t OutResult;
	SBCheckError(SBSSHUtils_ReadUINT64(Buffer, Size, &OutResult));
	return OutResult;
}

void WriteSSH2MPInt(const std::vector<uint8_t> &P, int32_t Size, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_WriteSSH2MPInt(SB_STD_VECTOR_FRONT_ADR(P), (int32_t)P.size(), Size, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-748098752, 2, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void SBSSHUtils_WriteBoolean(bool B, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBSSHUtils_WriteBoolean((int8_t)B, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-315512702, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_SSHUTILS */

};	/* namespace SecureBlackbox */

