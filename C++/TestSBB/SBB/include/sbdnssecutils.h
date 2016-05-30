#ifndef __INC_SBDNSSECUTILS
#define __INC_SBDNSSECUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbstrutils.h"
#include "sbdnssecconsts.h"
#include "sbdnssectypes.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_DNSSECUTILS

uint16_t ResourceTypeToCode(TSBDNSResourceType AType);

TSBDNSResourceType ResourceCodeToType(uint16_t ACode);

void IPv6ToString(const std::vector<uint8_t> &Buffer, std::string &OutResult);

void ReadDomainName(const std::vector<uint8_t> &Buffer, uint16_t &Offset, std::string &OutResult);

#ifdef SB_USE_CLASS_TSTREAM
void WriteDomainName(const std::string &Name, TStream &Stream);
void WriteDomainName(const std::string &Name, TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

void WriteDomainName(const std::string &Name, std::vector<uint8_t> &Buffer, int32_t &Index);

void WriteIPv4Address(const std::string &Address, std::vector<uint8_t> &Buffer, int32_t &Index);

void WriteIPv6Address(const std::string &Address, std::vector<uint8_t> &Buffer, int32_t &Index);

void WriteString(const std::string &Str, std::vector<uint8_t> &Buffer, int32_t &Index);

uint16_t ResponseCodeToRCode(TSBDNSResponseCode ACode);

TSBDNSResponseCode RCodeToResponseCode(uint16_t ACode, bool UsedInExtensions);

uint8_t OperationCodeToOpCode(TSBDNSOperationCode ACode);

TSBDNSOperationCode OpCodeToOperationCode(uint8_t ACode);

void CheckBufferBounds(const std::vector<uint8_t> &Buffer, uint16_t Offset);

bool IsSubdomain(const std::string &Subdomain, const std::string &Domain);

int32_t LabelCount(const std::string &Domain);

void ExtractLabels(const std::string &Domain, int32_t Count, std::string &OutResult);

int32_t CompareDomainNames(const std::string &Name1, const std::string &Name2);

#endif /* SB_USE_GLOBAL_PROCS_DNSSECUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DNSSECUTILS
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_ResourceTypeToCode(TSBDNSResourceTypeRaw AType, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_ResourceCodeToType(uint16_t ACode, TSBDNSResourceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_IPv6ToString(const uint8_t pBuffer[], int32_t szBuffer, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_ReadDomainName(const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_WriteDomainName(const char * pcName, int32_t szName, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_WriteDomainName_1(const char * pcName, int32_t szName, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_WriteIPv4Address(const char * pcAddress, int32_t szAddress, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_WriteIPv6Address(const char * pcAddress, int32_t szAddress, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_WriteString(const char * pcStr, int32_t szStr, uint8_t pBuffer[], int32_t * szBuffer, int32_t * Index);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_ResponseCodeToRCode(TSBDNSResponseCodeRaw ACode, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_RCodeToResponseCode(uint16_t ACode, int8_t UsedInExtensions, TSBDNSResponseCodeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_OperationCodeToOpCode(TSBDNSOperationCodeRaw ACode, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_OpCodeToOperationCode(uint8_t ACode, TSBDNSOperationCodeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_CheckBufferBounds(const uint8_t pBuffer[], int32_t szBuffer, uint16_t Offset);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_IsSubdomain(const char * pcSubdomain, int32_t szSubdomain, const char * pcDomain, int32_t szDomain, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_LabelCount(const char * pcDomain, int32_t szDomain, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_ExtractLabels(const char * pcDomain, int32_t szDomain, int32_t Count, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDNSSECUtils_CompareDomainNames(const char * pcName1, int32_t szName1, const char * pcName2, int32_t szName2, int32_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DNSSECUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDNSSECUTILS */

