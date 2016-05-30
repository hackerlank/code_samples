#include "sbeccommon.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS

SB_INLINE void TElECDomainParameters::SetupCurveParameters(int32_t Curve)
{
	SBCheckError(TElECDomainParameters_SetupCurveParameters(_Handle, Curve));
}

SB_INLINE void TElECDomainParameters::SetP(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_SetP(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElECDomainParameters::UpdateP()
{
	SBCheckError(TElECDomainParameters_UpdateP(_Handle));
}

SB_INLINE void TElECDomainParameters::SetM(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetM(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetK1(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetK1(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetK2(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetK2(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetK3(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetK3(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetField(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetField(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetCurve(int32_t Value)
{
	SBCheckError(TElECDomainParameters_SetCurve(_Handle, Value));
}

SB_INLINE void TElECDomainParameters::SetCurveOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_SetCurveOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElECDomainParameters::SetSeed(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_SetSeed(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE void TElECDomainParameters::SetA(const std::vector<uint8_t> &V)
{
	SBCheckError(TElECDomainParameters_SetA(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElECDomainParameters::SetB(const std::vector<uint8_t> &V)
{
	SBCheckError(TElECDomainParameters_SetB(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElECDomainParameters::SetN(const std::vector<uint8_t> &V)
{
	SBCheckError(TElECDomainParameters_SetN(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElECDomainParameters::SetX(const std::vector<uint8_t> &V)
{
	SBCheckError(TElECDomainParameters_SetX(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE void TElECDomainParameters::SetY(const std::vector<uint8_t> &V)
{
	SBCheckError(TElECDomainParameters_SetY(_Handle, SB_STD_VECTOR_FRONT_ADR(V), (int32_t)V.size()));
}

SB_INLINE int32_t TElECDomainParameters::GetFieldBits()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_GetFieldBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECDomainParameters::GetSubgroupBits()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_GetSubgroupBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::Reset()
{
	SBCheckError(TElECDomainParameters_Reset(_Handle));
}

bool TElECDomainParameters::Check()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElECDomainParameters_Check(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElECDomainParameters::get_Curve()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_Curve(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_Curve(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_Curve(_Handle, Value));
}

void TElECDomainParameters::get_CurveOID(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_CurveOID(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1799319650, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_CurveOID(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_CurveOID(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_P(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_P(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-620394513, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_P(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_P(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_A(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_A(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1313495267, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_A(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_A(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_B(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_B(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(683472551, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_B(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_B(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_N(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_N(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(554351244, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_N(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_N(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECDomainParameters::get_H()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_H(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_H(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_H(_Handle, Value));
}

void TElECDomainParameters::get_X(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_X(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-706867235, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_X(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_X(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_Y(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_Y(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1562820789, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_Y(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_Y(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

void TElECDomainParameters::get_Seed(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElECDomainParameters_get_Seed(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1460997693, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElECDomainParameters::set_Seed(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElECDomainParameters_set_Seed(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElECDomainParameters::get_FieldType()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_FieldType(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_FieldType(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_FieldType(_Handle, Value));
}

SB_INLINE int32_t TElECDomainParameters::get_Field()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_Field(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_Field(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_Field(_Handle, Value));
}

SB_INLINE int32_t TElECDomainParameters::get_FieldBits()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_FieldBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECDomainParameters::get_SubgroupBits()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_SubgroupBits(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElECDomainParameters::get_M()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_M(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_M(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_M(_Handle, Value));
}

SB_INLINE int32_t TElECDomainParameters::get_K1()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_K1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_K1(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_K1(_Handle, Value));
}

SB_INLINE int32_t TElECDomainParameters::get_K2()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_K2(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_K2(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_K2(_Handle, Value));
}

SB_INLINE int32_t TElECDomainParameters::get_K3()
{
	int32_t OutResult;
	SBCheckError(TElECDomainParameters_get_K3(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElECDomainParameters::set_K3(int32_t Value)
{
	SBCheckError(TElECDomainParameters_set_K3(_Handle, Value));
}

TElECDomainParameters::TElECDomainParameters(TElECDomainParametersHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElECDomainParameters::TElECDomainParameters() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElECDomainParameters_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_GLOBAL_PROCS_ECCOMMON

SB_INLINE int32_t GetCurveByOID(const std::vector<uint8_t> &OID)
{
	int32_t OutResult;
	SBCheckError(SBECCommon_GetCurveByOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), &OutResult));
	return OutResult;
}

void GetOIDByCurve(int32_t Curve, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBECCommon_GetOIDByCurve(Curve, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1430321745, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool IsPointCompressed(void * Buffer, int32_t Size)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_IsPointCompressed(Buffer, Size, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool BufferToPoint(void * Buffer, int32_t Size, TElECDomainParameters &DomainParams, void * X, int32_t &XSize, void * Y, int32_t &YSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_BufferToPoint(Buffer, Size, DomainParams.getHandle(), X, &XSize, Y, &YSize, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool BufferToPoint(void * Buffer, int32_t Size, TElECDomainParameters *DomainParams, void * X, int32_t &XSize, void * Y, int32_t &YSize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_BufferToPoint(Buffer, Size, (DomainParams != NULL) ? DomainParams->getHandle() : SB_NULL_HANDLE, X, &XSize, Y, &YSize, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool PointToBuffer(void * X, int32_t XSize, void * Y, int32_t YSize, TElECDomainParameters &DomainParams, void * Buffer, int32_t &Size, bool Compress, bool Hybrid)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_PointToBuffer(X, XSize, Y, YSize, DomainParams.getHandle(), Buffer, &Size, (int8_t)Compress, (int8_t)Hybrid, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool PointToBuffer(void * X, int32_t XSize, void * Y, int32_t YSize, TElECDomainParameters *DomainParams, void * Buffer, int32_t &Size, bool Compress, bool Hybrid)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_PointToBuffer(X, XSize, Y, YSize, (DomainParams != NULL) ? DomainParams->getHandle() : SB_NULL_HANDLE, Buffer, &Size, (int8_t)Compress, (int8_t)Hybrid, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

#ifdef SB_USE_CLASS_TELECDOMAINPARAMETERS
bool ValidateKey(TElECDomainParameters &DomainParams, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_ValidateKey(DomainParams.getHandle(), D, DSize, Qx, QxSize, Qy, QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}
bool ValidateKey(TElECDomainParameters *DomainParams, void * D, int32_t DSize, void * Qx, int32_t QxSize, void * Qy, int32_t QySize)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBECCommon_ValidateKey((DomainParams != NULL) ? DomainParams->getHandle() : SB_NULL_HANDLE, D, DSize, Qx, QxSize, Qy, QySize, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TELECDOMAINPARAMETERS */

void HexStrToFieldElement(const std::string &Src, bool LittleEndian, int32_t PSize, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBECCommon_HexStrToFieldElement(Src.data(), (int32_t)Src.length(), (int8_t)LittleEndian, PSize, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1674007267, 3, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void BufferToFieldElement(const std::vector<uint8_t> &Buf, PLInt &A, PLInt P)
{
	SBCheckError(SBECCommon_BufferToFieldElement(SB_STD_VECTOR_FRONT_ADR(Buf), (int32_t)Buf.size(), &A, P));
}

SB_INLINE void BufferToFieldElement(void * Buf, int32_t Size, PLInt &A, PLInt P)
{
	SBCheckError(SBECCommon_BufferToFieldElement_1(Buf, Size, &A, P));
}

#endif /* SB_USE_GLOBAL_PROCS_ECCOMMON */

};	/* namespace SecureBlackbox */

