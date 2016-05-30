#include "sbcryptoprovutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CryptoProvGetBoolParam(TElRelativeDistinguishedName &Params, const std::vector<uint8_t> &Name, bool Default)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_CryptoProvGetBoolParam(Params.getHandle(), SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), (int8_t)Default, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool CryptoProvGetBoolParam(TElRelativeDistinguishedName *Params, const std::vector<uint8_t> &Name, bool Default)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_CryptoProvGetBoolParam((Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, SB_STD_VECTOR_FRONT_ADR(Name), (int32_t)Name.size(), (int8_t)Default, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

SB_INLINE int32_t GetIntegerPropFromBuffer(const std::vector<uint8_t> &Value, int32_t Default)
{
	int32_t OutResult;
	SBCheckError(SBCryptoProvUtils_GetIntegerPropFromBuffer(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Default, &OutResult));
	return OutResult;
}

SB_INLINE int64_t GetInt64PropFromBuffer(const std::vector<uint8_t> &Value, int32_t Default)
{
	int64_t OutResult;
	SBCheckError(SBCryptoProvUtils_GetInt64PropFromBuffer(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), Default, &OutResult));
	return OutResult;
}

void GetBufferFromInteger(int32_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_GetBufferFromInteger(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1312942614, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void GetBufferFromInt64(int64_t Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_GetBufferFromInt64(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1140203866, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool GetBoolFromBuffer(const std::vector<uint8_t> &Value, bool Default)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_GetBoolFromBuffer(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), (int8_t)Default, &OutResultRaw));
	return (OutResultRaw != 0);
}

void GetBufferFromBool(bool Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_GetBufferFromBool((int8_t)Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(89731480, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void * GetPointerFromBuffer(const std::vector<uint8_t> &Value)
{
	void * OutResult;
	SBCheckError(SBCryptoProvUtils_GetPointerFromBuffer(SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size(), &OutResult));
	return OutResult;
}

void GetBufferFromPointer(void * Value, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_GetBufferFromPointer(Value, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1522195694, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool ExtractSymmetricCipherParams(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t &KeyLen, std::vector<uint8_t> &IV)
{
	int32_t szIV = (int32_t)IV.size();
	int8_t OutResultRaw = 0;
	uint32_t _err = SBCryptoProvUtils_ExtractSymmetricCipherParams(SB_STD_VECTOR_FRONT_ADR(AlgOID), (int32_t)AlgOID.size(), SB_STD_VECTOR_FRONT_ADR(AlgParams), (int32_t)AlgParams.size(), &KeyLen, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IV), &szIV, &OutResultRaw);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		IV.resize(szIV);
		SBCheckError(SBGetLastReturnBuffer(1731458637, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(IV), &szIV));
	}
	else
		SBCheckError(_err);

	IV.resize(szIV);
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void SerializeParams(TElRelativeDistinguishedName &Params, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_SerializeParams(Params.getHandle(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2116481043, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
void SerializeParams(TElRelativeDistinguishedName *Params, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBCryptoProvUtils_SerializeParams((Params != NULL) ? Params->getHandle() : SB_NULL_HANDLE, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-2116481043, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
SB_INLINE TElRelativeDistinguishedNameHandle UnserializeParams(void * Buffer, int32_t Size)
{
	TElRelativeDistinguishedNameHandle OutResult;
	SBCheckError(SBCryptoProvUtils_UnserializeParams(Buffer, Size, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

bool IsKeyDrivenOperation(int32_t OpType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_IsKeyDrivenOperation(OpType, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsSecretKeyOperation(int32_t OpType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_IsSecretKeyOperation(OpType, &OutResultRaw));
	return (OutResultRaw != 0);
}

bool IsAlgorithmIndependentOperation(int32_t OpType)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBCryptoProvUtils_IsAlgorithmIndependentOperation(OpType, &OutResultRaw));
	return (OutResultRaw != 0);
}

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS */

};	/* namespace SecureBlackbox */

