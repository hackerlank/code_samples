#ifndef __INC_SBDNSSECTYPES
#define __INC_SBDNSSECTYPES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDNSResourceRecordHandle;

typedef TElClassHandle TElDNSIPv4AddressRecordHandle;

typedef TElClassHandle TElDNSNameServerRecordHandle;

typedef TElClassHandle TElDNSCanonicalNameRecordHandle;

typedef TElClassHandle TElDNSStartOfAuthorityRecordHandle;

typedef TElClassHandle TElDNSWellKnownServiceRecordHandle;

typedef TElClassHandle TElDNSDomainNamePointerRecordHandle;

typedef TElClassHandle TElDNSHostInfoRecordHandle;

typedef TElClassHandle TElDNSMailInfoRecordHandle;

typedef TElClassHandle TElDNSMailExchangeRecordHandle;

typedef TElClassHandle TElDNSTextStringsRecordHandle;

typedef TElClassHandle TElDNSIPv6AddressRecordHandle;

typedef TElClassHandle TElDNSServiceLocationRecordHandle;

typedef TElClassHandle TElDNSExtensionsRecordHandle;

typedef TElClassHandle TElDNSPublicKeyRecordHandle;

typedef TElClassHandle TElDNSDelegationSignerRecordHandle;

typedef TElClassHandle TElDNSSignatureRecordHandle;

typedef TElClassHandle TElDNSNextSecureRecordHandle;

typedef TElClassHandle TElDNSNextSecure3RecordHandle;

typedef TElClassHandle TElDNSNextSecure3ParamRecordHandle;

typedef TElClassHandle TElDNSResourceRecordSetHandle;

typedef uint8_t TSBDNSMessageTypeRaw;

typedef enum
{
	dnsQuery = 0,
	dnsResponse = 1
} TSBDNSMessageType;

typedef uint8_t TSBDNSOperationCodeRaw;

typedef enum
{
	dnsUnknownOperation = 0,
	dnsStandardQuery = 1,
	dnsInverseQuery = 2,
	dnsStatusRequest = 3,
	dnsNotification = 4,
	dnsUpdate = 5
} TSBDNSOperationCode;

typedef uint8_t TSBDNSResponseCodeRaw;

typedef enum
{
	dnsUnknownResponse = 0,
	dnsNoError = 1,
	dnsInvalidRequest = 2,
	dnsServerError = 3,
	dnsNameError = 4,
	dnsNotImplemented = 5,
	dnsQueryRefused = 6,
	dnsNameExists = 7,
	dnsRRSetExists = 8,
	dnsRRSetNotExists = 9,
	dnsNotAuthoritative = 10,
	dnsNotInZone = 11,
	dnsInvalidVersion = 12,
	dnsSignatureFailure = 13,
	dnsKeyNotRecognized = 14,
	dnsSignatureTimeout = 15,
	dnsInvalidKeyMode = 16,
	dnsDuplicateKeyName = 17,
	dnsAlgorithmNotSupported = 18,
	dnsBadTruncation = 19,
	dnsPrivate = 20
} TSBDNSResponseCode;

typedef uint8_t TSBDNSResourceTypeRaw;

typedef enum
{
	dnsUnknownResource = 0,
	dnsIPv4Address = 1,
	dnsNameServer = 2,
	dnsCanonicalName = 3,
	dnsStartOfAuthority = 4,
	dnsWellKnownService = 5,
	dnsDomainNamePointer = 6,
	dnsHostInfo = 7,
	dnsMailInfo = 8,
	dnsMailExchange = 9,
	dnsTextStrings = 10,
	dnsIPv6Address = 11,
	dnsServiceLocation = 12,
	dnsExtensions = 13,
	dnsDelegationSigner = 14,
	dnsSignature = 15,
	dnsNextSecure = 16,
	dnsPublicKey = 17,
	dnsNextSecure3 = 18,
	dnsNextSecure3Param = 19,
	dnsAll = 20
} TSBDNSResourceType;

typedef uint8_t TSBDNSSecurityStatusRaw;

typedef enum
{
	dnsInsecure = 0,
	dnsIndeterminate = 1,
	dnsBogus = 2,
	dnsSecure = 3
} TSBDNSSecurityStatus;

typedef uint32_t TSBDNSSecurityStatusesRaw;

typedef enum 
{
	f_dnsInsecure = 1,
	f_dnsIndeterminate = 2,
	f_dnsBogus = 4,
	f_dnsSecure = 8
} TSBDNSSecurityStatuses;

typedef void (SB_CALLBACK *TSBDNSKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcOwner, int32_t szOwner, uint16_t KeyTag, uint8_t Algorithm, TElDNSPublicKeyRecordHandle * Key, int8_t * ReleaseKey);

typedef void (SB_CALLBACK *TSBDNSKeyValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElDNSPublicKeyRecordHandle Key, int8_t * Valid);

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_Assign(TElDNSResourceRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_Prepare(TElDNSResourceRecordHandle _Handle, const char * pcCanonicalName, int32_t szCanonicalName, uint32_t OriginalTTL);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_Read(TElDNSResourceRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_Write(TElDNSResourceRecordHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_Data(TElDNSResourceRecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_Name(TElDNSResourceRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_set_Name(TElDNSResourceRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_ResourceClass(TElDNSResourceRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_set_ResourceClass(TElDNSResourceRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_ResourceCode(TElDNSResourceRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_set_ResourceCode(TElDNSResourceRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_ResourceType(TElDNSResourceRecordHandle _Handle, TSBDNSResourceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_set_ResourceType(TElDNSResourceRecordHandle _Handle, TSBDNSResourceTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_get_TimeToLive(TElDNSResourceRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_set_TimeToLive(TElDNSResourceRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecord_Create(TElDNSResourceRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv4AddressRecord_Assign(TElDNSIPv4AddressRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv4AddressRecord_Read(TElDNSIPv4AddressRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv4AddressRecord_get_Address(TElDNSIPv4AddressRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv4AddressRecord_set_Address(TElDNSIPv4AddressRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv4AddressRecord_Create(TElDNSIPv4AddressRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSNAMESERVERRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSNameServerRecord_Assign(TElDNSNameServerRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNameServerRecord_Read(TElDNSNameServerRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNameServerRecord_get_HostName(TElDNSNameServerRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNameServerRecord_set_HostName(TElDNSNameServerRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNameServerRecord_Create(TElDNSNameServerRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSNAMESERVERRECORD */

#ifdef SB_USE_CLASS_TELDNSCANONICALNAMERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSCanonicalNameRecord_Assign(TElDNSCanonicalNameRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSCanonicalNameRecord_Read(TElDNSCanonicalNameRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSCanonicalNameRecord_get_Domain(TElDNSCanonicalNameRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSCanonicalNameRecord_set_Domain(TElDNSCanonicalNameRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSCanonicalNameRecord_Create(TElDNSCanonicalNameRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSCANONICALNAMERECORD */

#ifdef SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_Assign(TElDNSStartOfAuthorityRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_Read(TElDNSStartOfAuthorityRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_Expire(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_Expire(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_MinimumTTL(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_MinimumTTL(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_Person(TElDNSStartOfAuthorityRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_Person(TElDNSStartOfAuthorityRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_Refresh(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_Refresh(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_RefreshRetry(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_RefreshRetry(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_Serial(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_Serial(TElDNSStartOfAuthorityRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_get_Server(TElDNSStartOfAuthorityRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_set_Server(TElDNSStartOfAuthorityRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSStartOfAuthorityRecord_Create(TElDNSStartOfAuthorityRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD */

#ifdef SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_Assign(TElDNSWellKnownServiceRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_Clear(TElDNSWellKnownServiceRecordHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_Read(TElDNSWellKnownServiceRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_get_Address(TElDNSWellKnownServiceRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_set_Address(TElDNSWellKnownServiceRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_get_Count(TElDNSWellKnownServiceRecordHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_get_Bits(TElDNSWellKnownServiceRecordHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_set_Bits(TElDNSWellKnownServiceRecordHandle _Handle, int32_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_get_Protocol(TElDNSWellKnownServiceRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_set_Protocol(TElDNSWellKnownServiceRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSWellKnownServiceRecord_Create(TElDNSWellKnownServiceRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD */

#ifdef SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSDomainNamePointerRecord_Assign(TElDNSDomainNamePointerRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDomainNamePointerRecord_Read(TElDNSDomainNamePointerRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDomainNamePointerRecord_get_Domain(TElDNSDomainNamePointerRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDomainNamePointerRecord_set_Domain(TElDNSDomainNamePointerRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDomainNamePointerRecord_Create(TElDNSDomainNamePointerRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD */

#ifdef SB_USE_CLASS_TELDNSHOSTINFORECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_Assign(TElDNSHostInfoRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_Read(TElDNSHostInfoRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_get_CPU(TElDNSHostInfoRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_set_CPU(TElDNSHostInfoRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_get_OS(TElDNSHostInfoRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_set_OS(TElDNSHostInfoRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSHostInfoRecord_Create(TElDNSHostInfoRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSHOSTINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILINFORECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_Assign(TElDNSMailInfoRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_Read(TElDNSMailInfoRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_get_MailboxForErrors(TElDNSMailInfoRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_set_MailboxForErrors(TElDNSMailInfoRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_get_ResponsibleMailbox(TElDNSMailInfoRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_set_ResponsibleMailbox(TElDNSMailInfoRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailInfoRecord_Create(TElDNSMailInfoRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSMAILINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILEXCHANGERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_Assign(TElDNSMailExchangeRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_Read(TElDNSMailExchangeRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_get_Exchange(TElDNSMailExchangeRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_set_Exchange(TElDNSMailExchangeRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_get_Preference(TElDNSMailExchangeRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_set_Preference(TElDNSMailExchangeRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSMailExchangeRecord_Create(TElDNSMailExchangeRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSMAILEXCHANGERECORD */

#ifdef SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Assign(TElDNSTextStringsRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Read(TElDNSTextStringsRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Add(TElDNSTextStringsRecordHandle _Handle, const char * pcS, int32_t szS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Clear(TElDNSTextStringsRecordHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Delete(TElDNSTextStringsRecordHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_get_Count(TElDNSTextStringsRecordHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_get_Lines(TElDNSTextStringsRecordHandle _Handle, int32_t Index, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_set_Lines(TElDNSTextStringsRecordHandle _Handle, int32_t Index, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSTextStringsRecord_Create(TElDNSTextStringsRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD */

#ifdef SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv6AddressRecord_Assign(TElDNSIPv6AddressRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv6AddressRecord_Read(TElDNSIPv6AddressRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv6AddressRecord_get_Address(TElDNSIPv6AddressRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv6AddressRecord_set_Address(TElDNSIPv6AddressRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSIPv6AddressRecord_Create(TElDNSIPv6AddressRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_Assign(TElDNSServiceLocationRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_Read(TElDNSServiceLocationRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Domain(TElDNSServiceLocationRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Domain(TElDNSServiceLocationRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Port(TElDNSServiceLocationRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Port(TElDNSServiceLocationRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Priority(TElDNSServiceLocationRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Priority(TElDNSServiceLocationRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Protocol(TElDNSServiceLocationRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Protocol(TElDNSServiceLocationRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Service(TElDNSServiceLocationRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Service(TElDNSServiceLocationRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Target(TElDNSServiceLocationRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Target(TElDNSServiceLocationRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_get_Weight(TElDNSServiceLocationRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_set_Weight(TElDNSServiceLocationRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSServiceLocationRecord_Create(TElDNSServiceLocationRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD */

#ifdef SB_USE_CLASS_TELDNSEXTENSIONSRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_Assign(TElDNSExtensionsRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_Read(TElDNSExtensionsRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_Write(TElDNSExtensionsRecordHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_get_DNSSECOK(TElDNSExtensionsRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_set_DNSSECOK(TElDNSExtensionsRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_get_Flags(TElDNSExtensionsRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_set_Flags(TElDNSExtensionsRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_get_PayloadSize(TElDNSExtensionsRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_set_PayloadSize(TElDNSExtensionsRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_get_ResponseCode(TElDNSExtensionsRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_set_ResponseCode(TElDNSExtensionsRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_get_Version(TElDNSExtensionsRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_set_Version(TElDNSExtensionsRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSExtensionsRecord_Create(TElDNSExtensionsRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSEXTENSIONSRECORD */

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_Assign(TElDNSPublicKeyRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_Read(TElDNSPublicKeyRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_Algorithm(TElDNSPublicKeyRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_Algorithm(TElDNSPublicKeyRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_Flags(TElDNSPublicKeyRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_Flags(TElDNSPublicKeyRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_KeyTag(TElDNSPublicKeyRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_Protocol(TElDNSPublicKeyRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_Protocol(TElDNSPublicKeyRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_PublicKey(TElDNSPublicKeyRecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_PublicKey(TElDNSPublicKeyRecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_SecureEntryPoint(TElDNSPublicKeyRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_SecureEntryPoint(TElDNSPublicKeyRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_get_ZoneKey(TElDNSPublicKeyRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_set_ZoneKey(TElDNSPublicKeyRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSPublicKeyRecord_Create(TElDNSPublicKeyRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

#ifdef SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_Assign(TElDNSDelegationSignerRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_Read(TElDNSDelegationSignerRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_Validate(TElDNSDelegationSignerRecordHandle _Handle, TElDNSPublicKeyRecordHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_get_Algorithm(TElDNSDelegationSignerRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_set_Algorithm(TElDNSDelegationSignerRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_get_Digest(TElDNSDelegationSignerRecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_set_Digest(TElDNSDelegationSignerRecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_get_DigestType(TElDNSDelegationSignerRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_set_DigestType(TElDNSDelegationSignerRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_get_KeyTag(TElDNSDelegationSignerRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_set_KeyTag(TElDNSDelegationSignerRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSDelegationSignerRecord_Create(TElDNSDelegationSignerRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD */

#ifdef SB_USE_CLASS_TELDNSSIGNATURERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_Assign(TElDNSSignatureRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_Prepare(TElDNSSignatureRecordHandle _Handle, const char * pcCanonicalName, int32_t szCanonicalName, uint32_t AOriginalTTL);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_Read(TElDNSSignatureRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_Validate(TElDNSSignatureRecordHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Algorithm(TElDNSSignatureRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Algorithm(TElDNSSignatureRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_CoveredCode(TElDNSSignatureRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_CoveredCode(TElDNSSignatureRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_CoveredType(TElDNSSignatureRecordHandle _Handle, TSBDNSResourceTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_CoveredType(TElDNSSignatureRecordHandle _Handle, TSBDNSResourceTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Expiration(TElDNSSignatureRecordHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Expiration(TElDNSSignatureRecordHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Inception(TElDNSSignatureRecordHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Inception(TElDNSSignatureRecordHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_KeyTag(TElDNSSignatureRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_KeyTag(TElDNSSignatureRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Labels(TElDNSSignatureRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Labels(TElDNSSignatureRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_OriginalTTL(TElDNSSignatureRecordHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_OriginalTTL(TElDNSSignatureRecordHandle _Handle, uint32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Signature(TElDNSSignatureRecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Signature(TElDNSSignatureRecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_get_Signer(TElDNSSignatureRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_set_Signer(TElDNSSignatureRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSSignatureRecord_Create(TElDNSSignatureRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSSIGNATURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURERECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_Assign(TElDNSNextSecureRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_Read(TElDNSNextSecureRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_get_NextDomainName(TElDNSNextSecureRecordHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_set_NextDomainName(TElDNSNextSecureRecordHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_get_ResourceByCode(TElDNSNextSecureRecordHandle _Handle, uint16_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_set_ResourceByCode(TElDNSNextSecureRecordHandle _Handle, uint16_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_get_ResourceByType(TElDNSNextSecureRecordHandle _Handle, TSBDNSResourceTypeRaw Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_set_ResourceByType(TElDNSNextSecureRecordHandle _Handle, TSBDNSResourceTypeRaw Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecureRecord_Create(TElDNSNextSecureRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSNEXTSECURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3RECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_Assign(TElDNSNextSecure3RecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_Read(TElDNSNextSecure3RecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_Algorithm(TElDNSNextSecure3RecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_Algorithm(TElDNSNextSecure3RecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_Flags(TElDNSNextSecure3RecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_Flags(TElDNSNextSecure3RecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_Iterations(TElDNSNextSecure3RecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_Iterations(TElDNSNextSecure3RecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_NextOwnerName(TElDNSNextSecure3RecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_NextOwnerName(TElDNSNextSecure3RecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_OptOut(TElDNSNextSecure3RecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_OptOut(TElDNSNextSecure3RecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_ResourceByCode(TElDNSNextSecure3RecordHandle _Handle, uint16_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_ResourceByCode(TElDNSNextSecure3RecordHandle _Handle, uint16_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_ResourceByType(TElDNSNextSecure3RecordHandle _Handle, TSBDNSResourceTypeRaw Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_ResourceByType(TElDNSNextSecure3RecordHandle _Handle, TSBDNSResourceTypeRaw Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_get_Salt(TElDNSNextSecure3RecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_set_Salt(TElDNSNextSecure3RecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3Record_Create(TElDNSNextSecure3RecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3RECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_Assign(TElDNSNextSecure3ParamRecordHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_Read(TElDNSNextSecure3ParamRecordHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, uint16_t * Offset);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_get_Algorithm(TElDNSNextSecure3ParamRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_set_Algorithm(TElDNSNextSecure3ParamRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_get_Flags(TElDNSNextSecure3ParamRecordHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_set_Flags(TElDNSNextSecure3ParamRecordHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_get_Iterations(TElDNSNextSecure3ParamRecordHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_set_Iterations(TElDNSNextSecure3ParamRecordHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_get_OptOut(TElDNSNextSecure3ParamRecordHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_set_OptOut(TElDNSNextSecure3ParamRecordHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_get_Salt(TElDNSNextSecure3ParamRecordHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_set_Salt(TElDNSNextSecure3ParamRecordHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDNSNextSecure3ParamRecord_Create(TElDNSNextSecure3ParamRecordHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Add(TElDNSResourceRecordSetHandle _Handle, TSBDNSResourceTypeRaw ResourceType, TElDNSResourceRecordHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Add_1(TElDNSResourceRecordSetHandle _Handle, TElDNSResourceRecordHandle ResourceRecord, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_AddCopy(TElDNSResourceRecordSetHandle _Handle, TElDNSResourceRecordHandle ResourceRecord, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Assign(TElDNSResourceRecordSetHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Clear(TElDNSResourceRecordSetHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Delete(TElDNSResourceRecordSetHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Find(TElDNSResourceRecordSetHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw ResourceType, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindAny(TElDNSResourceRecordSetHandle _Handle, TSBDNSResourceTypeRaw ResourceType, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindKey(TElDNSResourceRecordSetHandle _Handle, const char * pcOwner, int32_t szOwner, uint16_t KeyTag, uint8_t Algorithm, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindSelfSignedSignature(TElDNSResourceRecordSetHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw CoveredType, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindSignature(TElDNSResourceRecordSetHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw CoveredType, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindSignature_1(TElDNSResourceRecordSetHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw CoveredType, TElDNSPublicKeyRecordHandle Key, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_FindSignatureByUpperLevel(TElDNSResourceRecordSetHandle _Handle, const char * pcCriteria, int32_t szCriteria, TSBDNSResourceTypeRaw CoveredType, int32_t Start, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_IndexOf(TElDNSResourceRecordSetHandle _Handle, TElDNSResourceRecordHandle Resource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Insert(TElDNSResourceRecordSetHandle _Handle, int32_t Index, TSBDNSResourceTypeRaw ResourceType, TElDNSResourceRecordHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Remove(TElDNSResourceRecordSetHandle _Handle, TElDNSResourceRecordHandle Resource, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Sort(TElDNSResourceRecordSetHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Verify(TElDNSResourceRecordSetHandle _Handle, TElDNSSignatureRecordHandle Signature, TElDNSPublicKeyRecordHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_get_Count(TElDNSResourceRecordSetHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_get_Items(TElDNSResourceRecordSetHandle _Handle, int32_t Index, TElDNSResourceRecordHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_get_OwnRecords(TElDNSResourceRecordSetHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_set_OwnRecords(TElDNSResourceRecordSetHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDNSResourceRecordSet_Create(TElDNSResourceRecordSetHandle * OutResult);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDNSResourceRecord;
class TElDNSIPv4AddressRecord;
class TElDNSNameServerRecord;
class TElDNSCanonicalNameRecord;
class TElDNSStartOfAuthorityRecord;
class TElDNSWellKnownServiceRecord;
class TElDNSDomainNamePointerRecord;
class TElDNSHostInfoRecord;
class TElDNSMailInfoRecord;
class TElDNSMailExchangeRecord;
class TElDNSTextStringsRecord;
class TElDNSIPv6AddressRecord;
class TElDNSServiceLocationRecord;
class TElDNSExtensionsRecord;
class TElDNSPublicKeyRecord;
class TElDNSDelegationSignerRecord;
class TElDNSSignatureRecord;
class TElDNSNextSecureRecord;
class TElDNSNextSecure3Record;
class TElDNSNextSecure3ParamRecord;
class TElDNSResourceRecordSet;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBDNSSecurityStatuses)

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
class TElDNSResourceRecord: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSResourceRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Prepare(const std::string &CanonicalName, uint32_t OriginalTTL);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &Stream);

		virtual void Write(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		virtual uint16_t get_ResourceClass();

		virtual void set_ResourceClass(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ResourceClass, set_ResourceClass, TElDNSResourceRecord, ResourceClass);

		virtual uint16_t get_ResourceCode();

		virtual void set_ResourceCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ResourceCode, set_ResourceCode, TElDNSResourceRecord, ResourceCode);

		virtual TSBDNSResourceType get_ResourceType();

		virtual void set_ResourceType(TSBDNSResourceType Value);

		SB_DECLARE_PROPERTY(TSBDNSResourceType, get_ResourceType, set_ResourceType, TElDNSResourceRecord, ResourceType);

		virtual uint32_t get_TimeToLive();

		virtual void set_TimeToLive(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_TimeToLive, set_TimeToLive, TElDNSResourceRecord, TimeToLive);

		TElDNSResourceRecord(TElDNSResourceRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSResourceRecord();

};
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD
class TElDNSIPv4AddressRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSIPv4AddressRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		TElDNSIPv4AddressRecord(TElDNSIPv4AddressRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSIPv4AddressRecord();

};
#endif /* SB_USE_CLASS_TELDNSIPV4ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSNAMESERVERRECORD
class TElDNSNameServerRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSNameServerRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_HostName(std::string &OutResult);

		virtual void set_HostName(const std::string &Value);

		TElDNSNameServerRecord(TElDNSNameServerRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSNameServerRecord();

};
#endif /* SB_USE_CLASS_TELDNSNAMESERVERRECORD */

#ifdef SB_USE_CLASS_TELDNSCANONICALNAMERECORD
class TElDNSCanonicalNameRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSCanonicalNameRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		TElDNSCanonicalNameRecord(TElDNSCanonicalNameRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSCanonicalNameRecord();

};
#endif /* SB_USE_CLASS_TELDNSCANONICALNAMERECORD */

#ifdef SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD
class TElDNSStartOfAuthorityRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSStartOfAuthorityRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual uint32_t get_Expire();

		virtual void set_Expire(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Expire, set_Expire, TElDNSStartOfAuthorityRecord, Expire);

		virtual uint32_t get_MinimumTTL();

		virtual void set_MinimumTTL(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_MinimumTTL, set_MinimumTTL, TElDNSStartOfAuthorityRecord, MinimumTTL);

		virtual void get_Person(std::string &OutResult);

		virtual void set_Person(const std::string &Value);

		virtual uint32_t get_Refresh();

		virtual void set_Refresh(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Refresh, set_Refresh, TElDNSStartOfAuthorityRecord, Refresh);

		virtual uint32_t get_RefreshRetry();

		virtual void set_RefreshRetry(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_RefreshRetry, set_RefreshRetry, TElDNSStartOfAuthorityRecord, RefreshRetry);

		virtual uint32_t get_Serial();

		virtual void set_Serial(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_Serial, set_Serial, TElDNSStartOfAuthorityRecord, Serial);

		virtual void get_Server(std::string &OutResult);

		virtual void set_Server(const std::string &Value);

		TElDNSStartOfAuthorityRecord(TElDNSStartOfAuthorityRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSStartOfAuthorityRecord();

};
#endif /* SB_USE_CLASS_TELDNSSTARTOFAUTHORITYRECORD */

#ifdef SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD
class TElDNSWellKnownServiceRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSWellKnownServiceRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDNSWellKnownServiceRecord, Count);

		virtual bool get_Bits(int32_t Index);

		virtual void set_Bits(int32_t Index, bool Value);

		virtual uint8_t get_Protocol();

		virtual void set_Protocol(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Protocol, set_Protocol, TElDNSWellKnownServiceRecord, Protocol);

		TElDNSWellKnownServiceRecord(TElDNSWellKnownServiceRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSWellKnownServiceRecord();

};
#endif /* SB_USE_CLASS_TELDNSWELLKNOWNSERVICERECORD */

#ifdef SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD
class TElDNSDomainNamePointerRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSDomainNamePointerRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		TElDNSDomainNamePointerRecord(TElDNSDomainNamePointerRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSDomainNamePointerRecord();

};
#endif /* SB_USE_CLASS_TELDNSDOMAINNAMEPOINTERRECORD */

#ifdef SB_USE_CLASS_TELDNSHOSTINFORECORD
class TElDNSHostInfoRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSHostInfoRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_CPU(std::string &OutResult);

		virtual void set_CPU(const std::string &Value);

		virtual void get_OS(std::string &OutResult);

		virtual void set_OS(const std::string &Value);

		TElDNSHostInfoRecord(TElDNSHostInfoRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSHostInfoRecord();

};
#endif /* SB_USE_CLASS_TELDNSHOSTINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILINFORECORD
class TElDNSMailInfoRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSMailInfoRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_MailboxForErrors(std::string &OutResult);

		virtual void set_MailboxForErrors(const std::string &Value);

		virtual void get_ResponsibleMailbox(std::string &OutResult);

		virtual void set_ResponsibleMailbox(const std::string &Value);

		TElDNSMailInfoRecord(TElDNSMailInfoRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSMailInfoRecord();

};
#endif /* SB_USE_CLASS_TELDNSMAILINFORECORD */

#ifdef SB_USE_CLASS_TELDNSMAILEXCHANGERECORD
class TElDNSMailExchangeRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSMailExchangeRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Exchange(std::string &OutResult);

		virtual void set_Exchange(const std::string &Value);

		virtual uint16_t get_Preference();

		virtual void set_Preference(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Preference, set_Preference, TElDNSMailExchangeRecord, Preference);

		TElDNSMailExchangeRecord(TElDNSMailExchangeRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSMailExchangeRecord();

};
#endif /* SB_USE_CLASS_TELDNSMAILEXCHANGERECORD */

#ifdef SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD
class TElDNSTextStringsRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSTextStringsRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		int32_t Add(const std::string &S);

		void Clear();

		void Delete(int32_t Index);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDNSTextStringsRecord, Count);

		virtual void get_Lines(int32_t Index, std::string &OutResult);

		virtual void set_Lines(int32_t Index, const std::string &Value);

		TElDNSTextStringsRecord(TElDNSTextStringsRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSTextStringsRecord();

};
#endif /* SB_USE_CLASS_TELDNSTEXTSTRINGSRECORD */

#ifdef SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD
class TElDNSIPv6AddressRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSIPv6AddressRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Address(std::string &OutResult);

		virtual void set_Address(const std::string &Value);

		TElDNSIPv6AddressRecord(TElDNSIPv6AddressRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSIPv6AddressRecord();

};
#endif /* SB_USE_CLASS_TELDNSIPV6ADDRESSRECORD */

#ifdef SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD
class TElDNSServiceLocationRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSServiceLocationRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_Domain(std::string &OutResult);

		virtual void set_Domain(const std::string &Value);

		virtual uint16_t get_Port();

		virtual void set_Port(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Port, set_Port, TElDNSServiceLocationRecord, Port);

		virtual uint16_t get_Priority();

		virtual void set_Priority(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Priority, set_Priority, TElDNSServiceLocationRecord, Priority);

		virtual void get_Protocol(std::string &OutResult);

		virtual void set_Protocol(const std::string &Value);

		virtual void get_Service(std::string &OutResult);

		virtual void set_Service(const std::string &Value);

		virtual void get_Target(std::string &OutResult);

		virtual void set_Target(const std::string &Value);

		virtual uint16_t get_Weight();

		virtual void set_Weight(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Weight, set_Weight, TElDNSServiceLocationRecord, Weight);

		TElDNSServiceLocationRecord(TElDNSServiceLocationRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSServiceLocationRecord();

};
#endif /* SB_USE_CLASS_TELDNSSERVICELOCATIONRECORD */

#ifdef SB_USE_CLASS_TELDNSEXTENSIONSRECORD
class TElDNSExtensionsRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSExtensionsRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Write(TStream &Stream);

		virtual void Write(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual bool get_DNSSECOK();

		virtual void set_DNSSECOK(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DNSSECOK, set_DNSSECOK, TElDNSExtensionsRecord, DNSSECOK);

		virtual uint16_t get_Flags();

		virtual void set_Flags(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Flags, set_Flags, TElDNSExtensionsRecord, Flags);

		virtual uint16_t get_PayloadSize();

		virtual void set_PayloadSize(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_PayloadSize, set_PayloadSize, TElDNSExtensionsRecord, PayloadSize);

		virtual uint16_t get_ResponseCode();

		virtual void set_ResponseCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_ResponseCode, set_ResponseCode, TElDNSExtensionsRecord, ResponseCode);

		virtual uint8_t get_Version();

		virtual void set_Version(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Version, set_Version, TElDNSExtensionsRecord, Version);

		TElDNSExtensionsRecord(TElDNSExtensionsRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSExtensionsRecord();

};
#endif /* SB_USE_CLASS_TELDNSEXTENSIONSRECORD */

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
class TElDNSPublicKeyRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSPublicKeyRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual uint8_t get_Algorithm();

		virtual void set_Algorithm(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Algorithm, set_Algorithm, TElDNSPublicKeyRecord, Algorithm);

		virtual uint16_t get_Flags();

		virtual void set_Flags(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Flags, set_Flags, TElDNSPublicKeyRecord, Flags);

		virtual uint16_t get_KeyTag();

		SB_DECLARE_PROPERTY_GET(uint16_t, get_KeyTag, TElDNSPublicKeyRecord, KeyTag);

		virtual uint8_t get_Protocol();

		virtual void set_Protocol(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Protocol, set_Protocol, TElDNSPublicKeyRecord, Protocol);

		virtual void get_PublicKey(std::vector<uint8_t> &OutResult);

		virtual void set_PublicKey(const std::vector<uint8_t> &Value);

		virtual bool get_SecureEntryPoint();

		virtual void set_SecureEntryPoint(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SecureEntryPoint, set_SecureEntryPoint, TElDNSPublicKeyRecord, SecureEntryPoint);

		virtual bool get_ZoneKey();

		virtual void set_ZoneKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ZoneKey, set_ZoneKey, TElDNSPublicKeyRecord, ZoneKey);

		TElDNSPublicKeyRecord(TElDNSPublicKeyRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSPublicKeyRecord();

};
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

#ifdef SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD
class TElDNSDelegationSignerRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSDelegationSignerRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
		int32_t Validate(TElDNSPublicKeyRecord &Key);

		int32_t Validate(TElDNSPublicKeyRecord *Key);
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

		virtual uint8_t get_Algorithm();

		virtual void set_Algorithm(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Algorithm, set_Algorithm, TElDNSDelegationSignerRecord, Algorithm);

		virtual void get_Digest(std::vector<uint8_t> &OutResult);

		virtual void set_Digest(const std::vector<uint8_t> &Value);

		virtual uint8_t get_DigestType();

		virtual void set_DigestType(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_DigestType, set_DigestType, TElDNSDelegationSignerRecord, DigestType);

		virtual uint16_t get_KeyTag();

		virtual void set_KeyTag(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_KeyTag, set_KeyTag, TElDNSDelegationSignerRecord, KeyTag);

		TElDNSDelegationSignerRecord(TElDNSDelegationSignerRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSDelegationSignerRecord();

};
#endif /* SB_USE_CLASS_TELDNSDELEGATIONSIGNERRECORD */

#ifdef SB_USE_CLASS_TELDNSSIGNATURERECORD
class TElDNSSignatureRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSSignatureRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Prepare(const std::string &CanonicalName, uint32_t AOriginalTTL);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		int32_t Validate();

		virtual uint8_t get_Algorithm();

		virtual void set_Algorithm(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Algorithm, set_Algorithm, TElDNSSignatureRecord, Algorithm);

		virtual uint16_t get_CoveredCode();

		virtual void set_CoveredCode(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_CoveredCode, set_CoveredCode, TElDNSSignatureRecord, CoveredCode);

		virtual TSBDNSResourceType get_CoveredType();

		virtual void set_CoveredType(TSBDNSResourceType Value);

		SB_DECLARE_PROPERTY(TSBDNSResourceType, get_CoveredType, set_CoveredType, TElDNSSignatureRecord, CoveredType);

		virtual int64_t get_Expiration();

		virtual void set_Expiration(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Expiration, set_Expiration, TElDNSSignatureRecord, Expiration);

		virtual int64_t get_Inception();

		virtual void set_Inception(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_Inception, set_Inception, TElDNSSignatureRecord, Inception);

		virtual uint16_t get_KeyTag();

		virtual void set_KeyTag(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_KeyTag, set_KeyTag, TElDNSSignatureRecord, KeyTag);

		virtual uint8_t get_Labels();

		virtual void set_Labels(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Labels, set_Labels, TElDNSSignatureRecord, Labels);

		virtual uint32_t get_OriginalTTL();

		virtual void set_OriginalTTL(uint32_t Value);

		SB_DECLARE_PROPERTY(uint32_t, get_OriginalTTL, set_OriginalTTL, TElDNSSignatureRecord, OriginalTTL);

		virtual void get_Signature(std::vector<uint8_t> &OutResult);

		virtual void set_Signature(const std::vector<uint8_t> &Value);

		virtual void get_Signer(std::string &OutResult);

		virtual void set_Signer(const std::string &Value);

		TElDNSSignatureRecord(TElDNSSignatureRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSSignatureRecord();

};
#endif /* SB_USE_CLASS_TELDNSSIGNATURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURERECORD
class TElDNSNextSecureRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSNextSecureRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual void get_NextDomainName(std::string &OutResult);

		virtual void set_NextDomainName(const std::string &Value);

		virtual bool get_ResourceByCode(uint16_t Index);

		virtual void set_ResourceByCode(uint16_t Index, bool Value);

		virtual bool get_ResourceByType(TSBDNSResourceType Index);

		virtual void set_ResourceByType(TSBDNSResourceType Index, bool Value);

		TElDNSNextSecureRecord(TElDNSNextSecureRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSNextSecureRecord();

};
#endif /* SB_USE_CLASS_TELDNSNEXTSECURERECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3RECORD
class TElDNSNextSecure3Record: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSNextSecure3Record)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual uint8_t get_Algorithm();

		virtual void set_Algorithm(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Algorithm, set_Algorithm, TElDNSNextSecure3Record, Algorithm);

		virtual uint8_t get_Flags();

		virtual void set_Flags(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Flags, set_Flags, TElDNSNextSecure3Record, Flags);

		virtual uint16_t get_Iterations();

		virtual void set_Iterations(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Iterations, set_Iterations, TElDNSNextSecure3Record, Iterations);

		virtual void get_NextOwnerName(std::vector<uint8_t> &OutResult);

		virtual void set_NextOwnerName(const std::vector<uint8_t> &Value);

		virtual bool get_OptOut();

		virtual void set_OptOut(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OptOut, set_OptOut, TElDNSNextSecure3Record, OptOut);

		virtual bool get_ResourceByCode(uint16_t Index);

		virtual void set_ResourceByCode(uint16_t Index, bool Value);

		virtual bool get_ResourceByType(TSBDNSResourceType Index);

		virtual void set_ResourceByType(TSBDNSResourceType Index, bool Value);

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void set_Salt(const std::vector<uint8_t> &Value);

		TElDNSNextSecure3Record(TElDNSNextSecure3RecordHandle handle, TElOwnHandle ownHandle);

		TElDNSNextSecure3Record();

};
#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3RECORD */

#ifdef SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD
class TElDNSNextSecure3ParamRecord: public TElDNSResourceRecord
{
	private:
		SB_DISABLE_COPY(TElDNSNextSecure3ParamRecord)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Read(const std::vector<uint8_t> &Buffer, uint16_t &Offset);

		virtual uint8_t get_Algorithm();

		virtual void set_Algorithm(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Algorithm, set_Algorithm, TElDNSNextSecure3ParamRecord, Algorithm);

		virtual uint8_t get_Flags();

		virtual void set_Flags(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Flags, set_Flags, TElDNSNextSecure3ParamRecord, Flags);

		virtual uint16_t get_Iterations();

		virtual void set_Iterations(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_Iterations, set_Iterations, TElDNSNextSecure3ParamRecord, Iterations);

		virtual bool get_OptOut();

		virtual void set_OptOut(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OptOut, set_OptOut, TElDNSNextSecure3ParamRecord, OptOut);

		virtual void get_Salt(std::vector<uint8_t> &OutResult);

		virtual void set_Salt(const std::vector<uint8_t> &Value);

		TElDNSNextSecure3ParamRecord(TElDNSNextSecure3ParamRecordHandle handle, TElOwnHandle ownHandle);

		TElDNSNextSecure3ParamRecord();

};
#endif /* SB_USE_CLASS_TELDNSNEXTSECURE3PARAMRECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORDSET
class TElDNSResourceRecordSet: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElDNSResourceRecordSet)
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		TElDNSResourceRecord* _Inst_Items;
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		TElDNSResourceRecordHandle Add(TSBDNSResourceType ResourceType);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		int32_t Add(TElDNSResourceRecord &ResourceRecord);

		int32_t Add(TElDNSResourceRecord *ResourceRecord);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		int32_t AddCopy(TElDNSResourceRecord &ResourceRecord);

		int32_t AddCopy(TElDNSResourceRecord *ResourceRecord);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		void Delete(int32_t Index);

		int32_t Find(const std::string &Criteria, TSBDNSResourceType ResourceType, int32_t Start);

		int32_t FindAny(TSBDNSResourceType ResourceType, int32_t Start);

		int32_t FindKey(const std::string &Owner, uint16_t KeyTag, uint8_t Algorithm, int32_t Start);

		int32_t FindSelfSignedSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start);

		int32_t FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start);

#ifdef SB_USE_CLASS_TELDNSPUBLICKEYRECORD
		int32_t FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, TElDNSPublicKeyRecord &Key, int32_t Start);

		int32_t FindSignature(const std::string &Criteria, TSBDNSResourceType CoveredType, TElDNSPublicKeyRecord *Key, int32_t Start);
#endif /* SB_USE_CLASS_TELDNSPUBLICKEYRECORD */

		int32_t FindSignatureByUpperLevel(const std::string &Criteria, TSBDNSResourceType CoveredType, int32_t Start);

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		int32_t IndexOf(TElDNSResourceRecord &Resource);

		int32_t IndexOf(TElDNSResourceRecord *Resource);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		TElDNSResourceRecordHandle Insert(int32_t Index, TSBDNSResourceType ResourceType);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		int32_t Remove(TElDNSResourceRecord &Resource);

		int32_t Remove(TElDNSResourceRecord *Resource);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

		void Sort();

#ifdef SB_USE_CLASSES_TELDNSPUBLICKEYRECORD_AND_TELDNSSIGNATURERECORD
		int32_t Verify(TElDNSSignatureRecord &Signature, TElDNSPublicKeyRecord &Key);

		int32_t Verify(TElDNSSignatureRecord *Signature, TElDNSPublicKeyRecord *Key);
#endif /* SB_USE_CLASSES_TELDNSPUBLICKEYRECORD_AND_TELDNSSIGNATURERECORD */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElDNSResourceRecordSet, Count);

#ifdef SB_USE_CLASS_TELDNSRESOURCERECORD
		virtual TElDNSResourceRecord* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORD */

		virtual bool get_OwnRecords();

		virtual void set_OwnRecords(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnRecords, set_OwnRecords, TElDNSResourceRecordSet, OwnRecords);

		TElDNSResourceRecordSet(TElDNSResourceRecordSetHandle handle, TElOwnHandle ownHandle);

		TElDNSResourceRecordSet();

		virtual ~TElDNSResourceRecordSet();

};
#endif /* SB_USE_CLASS_TELDNSRESOURCERECORDSET */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDNSSECTYPES */

