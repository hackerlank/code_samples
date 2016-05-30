#include "sbgssapibase.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_GSSAPIBASE

SB_INLINE uint32_t GSS_CALLING_ERROR(uint32_t x)
{
	uint32_t OutResult;
	SBCheckError(SBGSSAPIBase_GSS_CALLING_ERROR(x, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t GSS_ROUTINE_ERROR(uint32_t x)
{
	uint32_t OutResult;
	SBCheckError(SBGSSAPIBase_GSS_ROUTINE_ERROR(x, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t GSS_SUPPLEMENTARY_INFO(uint32_t x)
{
	uint32_t OutResult;
	SBCheckError(SBGSSAPIBase_GSS_SUPPLEMENTARY_INFO(x, &OutResult));
	return OutResult;
}

SB_INLINE uint32_t GSS_ERROR(uint32_t x)
{
	uint32_t OutResult;
	SBCheckError(SBGSSAPIBase_GSS_ERROR(x, &OutResult));
	return OutResult;
}

void DecodeMechOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBGSSAPIBase_DecodeMechOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1351336095, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void EncodeMechOID(const std::vector<uint8_t> &OID, std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = SBGSSAPIBase_EncodeMechOID(SB_STD_VECTOR_FRONT_ADR(OID), (int32_t)OID.size(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1282567303, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#endif /* SB_USE_GLOBAL_PROCS_GSSAPIBASE */

};	/* namespace SecureBlackbox */

