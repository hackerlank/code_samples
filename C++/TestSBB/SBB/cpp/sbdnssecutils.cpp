#include "sbdnssecutils.h"

namespace SecureBlackbox {

#ifdef SB_USE_GLOBAL_PROCS_DNSSECUTILS

SB_INLINE uint16_t ResourceTypeToCode(TSBDNSResourceType AType)
{
	uint16_t OutResult;
	SBCheckError(SBDNSSECUtils_ResourceTypeToCode((TSBDNSResourceTypeRaw)AType, &OutResult));
	return OutResult;
}

TSBDNSResourceType ResourceCodeToType(uint16_t ACode)
{
	TSBDNSResourceTypeRaw OutResultRaw = 0;
	SBCheckError(SBDNSSECUtils_ResourceCodeToType(ACode, &OutResultRaw));
	return (TSBDNSResourceType)OutResultRaw;
}

void IPv6ToString(const std::vector<uint8_t> &Buffer, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBDNSSECUtils_IPv6ToString(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-1185144435, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void ReadDomainName(const std::vector<uint8_t> &Buffer, uint16_t &Offset, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBDNSSECUtils_ReadDomainName(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), &Offset, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1152854976, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void WriteDomainName(const std::string &Name, TStream &Stream)
{
	SBCheckError(SBDNSSECUtils_WriteDomainName(Name.data(), (int32_t)Name.length(), Stream.getHandle()));
}
SB_INLINE void WriteDomainName(const std::string &Name, TStream *Stream)
{
	SBCheckError(SBDNSSECUtils_WriteDomainName(Name.data(), (int32_t)Name.length(), (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TSTREAM */

void WriteDomainName(const std::string &Name, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBDNSSECUtils_WriteDomainName_1(Name.data(), (int32_t)Name.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-356186367, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void WriteIPv4Address(const std::string &Address, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBDNSSECUtils_WriteIPv4Address(Address.data(), (int32_t)Address.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1490868494, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void WriteIPv6Address(const std::string &Address, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBDNSSECUtils_WriteIPv6Address(Address.data(), (int32_t)Address.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(2108821133, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

void WriteString(const std::string &Str, std::vector<uint8_t> &Buffer, int32_t &Index)
{
	int32_t szBuffer = (int32_t)Buffer.size();
	uint32_t _err = SBDNSSECUtils_WriteString(Str.data(), (int32_t)Str.length(), (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer, &Index);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		Buffer.resize(szBuffer);
		SBCheckError(SBGetLastReturnBuffer(-1433360000, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(Buffer), &szBuffer));
	}
	else
		SBCheckError(_err);

	Buffer.resize(szBuffer);
}

SB_INLINE uint16_t ResponseCodeToRCode(TSBDNSResponseCode ACode)
{
	uint16_t OutResult;
	SBCheckError(SBDNSSECUtils_ResponseCodeToRCode((TSBDNSResponseCodeRaw)ACode, &OutResult));
	return OutResult;
}

TSBDNSResponseCode RCodeToResponseCode(uint16_t ACode, bool UsedInExtensions)
{
	TSBDNSResponseCodeRaw OutResultRaw = 0;
	SBCheckError(SBDNSSECUtils_RCodeToResponseCode(ACode, (int8_t)UsedInExtensions, &OutResultRaw));
	return (TSBDNSResponseCode)OutResultRaw;
}

SB_INLINE uint8_t OperationCodeToOpCode(TSBDNSOperationCode ACode)
{
	uint8_t OutResult;
	SBCheckError(SBDNSSECUtils_OperationCodeToOpCode((TSBDNSOperationCodeRaw)ACode, &OutResult));
	return OutResult;
}

TSBDNSOperationCode OpCodeToOperationCode(uint8_t ACode)
{
	TSBDNSOperationCodeRaw OutResultRaw = 0;
	SBCheckError(SBDNSSECUtils_OpCodeToOperationCode(ACode, &OutResultRaw));
	return (TSBDNSOperationCode)OutResultRaw;
}

SB_INLINE void CheckBufferBounds(const std::vector<uint8_t> &Buffer, uint16_t Offset)
{
	SBCheckError(SBDNSSECUtils_CheckBufferBounds(SB_STD_VECTOR_FRONT_ADR(Buffer), (int32_t)Buffer.size(), Offset));
}

bool IsSubdomain(const std::string &Subdomain, const std::string &Domain)
{
	int8_t OutResultRaw = 0;
	SBCheckError(SBDNSSECUtils_IsSubdomain(Subdomain.data(), (int32_t)Subdomain.length(), Domain.data(), (int32_t)Domain.length(), &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t LabelCount(const std::string &Domain)
{
	int32_t OutResult;
	SBCheckError(SBDNSSECUtils_LabelCount(Domain.data(), (int32_t)Domain.length(), &OutResult));
	return OutResult;
}

void ExtractLabels(const std::string &Domain, int32_t Count, std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = SBDNSSECUtils_ExtractLabels(Domain.data(), (int32_t)Domain.length(), Count, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1161428816, 2, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t CompareDomainNames(const std::string &Name1, const std::string &Name2)
{
	int32_t OutResult;
	SBCheckError(SBDNSSECUtils_CompareDomainNames(Name1.data(), (int32_t)Name1.length(), Name2.data(), (int32_t)Name2.length(), &OutResult));
	return OutResult;
}

#endif /* SB_USE_GLOBAL_PROCS_DNSSECUTILS */

};	/* namespace SecureBlackbox */

