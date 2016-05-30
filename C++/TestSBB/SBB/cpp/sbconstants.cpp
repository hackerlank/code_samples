#include "sbconstants.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CONSTANTS

SB_INLINE int32_t GetPBEAlgorithmByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetPBEAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void GetOIDByPBEAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBConstants_GetOIDByPBEAlgorithm(Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1815167678, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetPKAlgorithmByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetPKAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void GetOIDByPKAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBConstants_GetOIDByPKAlgorithm(Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1286390345, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetSigAlgorithmByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetSigAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void GetOIDBySigAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBConstants_GetOIDBySigAlgorithm(Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1066365765, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetHashAlgorithmByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetHashAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void GetOIDByHashAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBConstants_GetOIDByHashAlgorithm(Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1390522277, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetAlgorithmByOID(const std::vector<uint8_t> &OID, bool UseCryptoProvConstants)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (int8_t)UseCryptoProvConstants, &OutResult));
	return OutResult;
}

void GetOIDByAlgorithm(int32_t Algorithm, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBConstants_GetOIDByAlgorithm(Algorithm, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1119177741, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetAlgorithmNameByAlgorithm(int32_t Algorithm, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBConstants_GetAlgorithmNameByAlgorithm(Algorithm, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1166610951, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetAlgorithmNameByOID(const std::vector<uint8_t> &OID, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBConstants_GetAlgorithmNameByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-811215565, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t GetHashAlgorithmBySigAlgorithm(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetHashAlgorithmBySigAlgorithm(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetHMACAlgorithmByHashAlgorithm(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetHMACAlgorithmByHashAlgorithm(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetHashAlgorithmByHMACAlgorithm(int32_t Algorithm)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetHashAlgorithmByHMACAlgorithm(Algorithm, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetSigAlgorithmByHashAlgorithm(int32_t BasePKAlg, int32_t HashAlg)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetSigAlgorithmByHashAlgorithm(BasePKAlg, HashAlg, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetKeyAlgorithmBySigAlgorithm(int32_t SigAlg)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetKeyAlgorithmBySigAlgorithm(SigAlg, &OutResult));
	return OutResult;
}

SB_INLINE int32_t GetSigAlgorithmByKeyAlgorithm(int32_t KeyAlg)
{
	int32_t OutResult;
	SBCheckError(SBConstants_GetSigAlgorithmByKeyAlgorithm(KeyAlg, &OutResult));
	return OutResult;
}

bool IsSymmetricKeyAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBConstants_IsSymmetricKeyAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsHashAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBConstants_IsHashAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsMACAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBConstants_IsMACAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsPublicKeyAlgorithm(int32_t Algorithm)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBConstants_IsPublicKeyAlgorithm(Algorithm, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t NormalizeAlgorithmConstant(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(SBConstants_NormalizeAlgorithmConstant(Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t MGF1AlgorithmByHash(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(SBConstants_MGF1AlgorithmByHash(Value, &OutResult));
	return OutResult;
}

SB_INLINE int32_t HashAlgorithmByMGF1(int32_t Value)
{
	int32_t OutResult;
	SBCheckError(SBConstants_HashAlgorithmByMGF1(Value, &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_CONSTANTS */

};	/* namespace SecureBlackbox */

