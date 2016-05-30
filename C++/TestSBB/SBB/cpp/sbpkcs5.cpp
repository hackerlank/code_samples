#include "sbpkcs5.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPKCS5PBE

SB_INLINE void TElPKCS5PBE::Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Password)
{
	SBCheckError(TElPKCS5PBE_Decrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize, Password.data(), (int32_t)Password.length()));
}

SB_INLINE void TElPKCS5PBE::Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, const std::string &Password)
{
	SBCheckError(TElPKCS5PBE_Encrypt(_Handle, InBuffer, InSize, OutBuffer, &OutSize, Password.data(), (int32_t)Password.length()));
}

void TElPKCS5PBE::DeriveKey(const std::string &Password, int32_t Bits, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS5PBE_DeriveKey(_Handle, Password.data(), (int32_t)Password.length(), Bits, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(898340680, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElPKCS5PBE::IsPRFSupported(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_IsPRFSupported(_Handle, Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS5PBE::IsAlgorithmSupported(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_IsAlgorithmSupported(Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS5PBE::IsAlgorithmSupported_Inst(int32_t Alg)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_IsAlgorithmSupported_1(_Handle, Alg, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS5PBE::IsAlgorithmSupported(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_IsAlgorithmSupported_2(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElPKCS5PBE::IsAlgorithmSupported_Inst(const std::vector<uint8_t> &OID)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_IsAlgorithmSupported_3(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPKCS5PBE::GetAlgorithmByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElPKCS5PBE_GetAlgorithmByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS5PBE::GetAlgorithmByOID_Inst(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(TElPKCS5PBE_GetAlgorithmByOID_1(_Handle, SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPKCS5PBE::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPKCS5PBE_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

TSBPKCS5Version TElPKCS5PBE::get_Version()
{
	TSBPKCS5VersionRaw OutResultRaw = 0;
	SBCheckError(TElPKCS5PBE_get_Version(_Handle, &OutResultRaw));
	return (TSBPKCS5Version)OutResultRaw;
}

void TElPKCS5PBE::get_EncryptionAlgorithmOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS5PBE_get_EncryptionAlgorithmOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-738914672, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS5PBE::get_EncryptionAlgorithmParams(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS5PBE_get_EncryptionAlgorithmParams(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(679244979, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElPKCS5PBE::get_Salt(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElPKCS5PBE_get_Salt(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-180949107, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPKCS5PBE::set_Salt(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElPKCS5PBE_set_Salt(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElPKCS5PBE::get_IterationCount()
{
	int32_t OutResult;
	SBCheckError(TElPKCS5PBE_get_IterationCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS5PBE::set_IterationCount(int32_t Value)
{
	SBCheckError(TElPKCS5PBE_set_IterationCount(_Handle, Value));
}

SB_INLINE int32_t TElPKCS5PBE::get_PseudoRandomFunction()
{
	int32_t OutResult;
	SBCheckError(TElPKCS5PBE_get_PseudoRandomFunction(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPKCS5PBE::set_PseudoRandomFunction(int32_t Value)
{
	SBCheckError(TElPKCS5PBE_set_PseudoRandomFunction(_Handle, Value));
}

TElPKCS5PBE::TElPKCS5PBE(TElPKCS5PBEHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElPKCS5PBE::TElPKCS5PBE(const std::vector<uint8_t> &OID, const std::vector<uint8_t> &Params) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS5PBE_Create(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), SB_STD_VECTOR_FRONT_ADR(Params), (int32_t)Params.size(), &_Handle));
}

TElPKCS5PBE::TElPKCS5PBE(int32_t StreamAlg, int32_t HashAlg, bool UseNewVersion) : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPKCS5PBE_Create_1(StreamAlg, HashAlg, (int8_t)UseNewVersion, &_Handle));
}

#endif /* SB_USE_CLASS_TELPKCS5PBE */

#ifdef SB_USE_GLOBAL_PROCS_PKCS5

void DeriveRouteOneOTP(const std::string &Input, const std::string &Password, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBPKCS5_DeriveRouteOneOTP(Input.data(), (int32_t)Input.length(), Password.data(), (int32_t)Password.length(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1713903262, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_PKCS5 */

};	/* namespace SecureBlackbox */

