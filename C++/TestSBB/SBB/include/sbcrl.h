#ifndef __INC_SBCRL
#define __INC_SBCRL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbx509.h"
#include "sbpem.h"
#include "sbx509ext.h"
#include "sbrdn.h"
#include "sbsharedresource.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbhashfunction.h"
#include "sbalgorithmidentifier.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CRL_ERROR_INVALID_FORMAT 	8705
#define SB_CRL_ERROR_BAD_SIGNATURE_ALGORITHM 	8706
#define SB_CRL_ERROR_INVALID_ISSUER 	8707
#define SB_CRL_ERROR_INVALID_SIGNATURE 	8708
#define SB_CRL_ERROR_UNSUPPORTED_VERSION 	8709
#define SB_CRL_ERROR_UNSUPPORTED_ALGORITHM 	8710
#define SB_CRL_ERROR_INVALID_CERTIFICATE 	8711
#define SB_CRL_ERROR_ALREADY_EXISTS 	8712
#define SB_CRL_ERROR_NOT_FOUND 	8713
#define SB_CRL_ERROR_PRIVATE_KEY_NOT_FOUND 	8714
#define SB_CRL_ERROR_UNSUPPORTED_CERTIFICATE 	8715
#define SB_CRL_ERROR_INTERNAL_ERROR 	8716
#define SB_CRL_ERROR_BUFFER_TOO_SMALL 	8717
#define SB_CRL_ERROR_NOTHING_TO_VERIFY 	8718
#define SB_CRL_ERROR_NO_SIGNED_CRL_FOUND 	8719

typedef TElCustomExtensionHandle TElCRLExtensionHandle;

typedef TElCustomExtensionHandle ElCRLExtensionHandle;

typedef TElClassHandle TElAuthorityKeyIdentifierCRLExtensionHandle;

typedef TElAuthorityKeyIdentifierCRLExtensionHandle ElAuthorityKeyIdentifierCRLExtensionHandle;

typedef TElClassHandle TElCRLNumberCRLExtensionHandle;

typedef TElCRLNumberCRLExtensionHandle ElCRLNumberCRLExtensionHandle;

typedef TElClassHandle TElDeltaCRLIndicatorCRLExtensionHandle;

typedef TElDeltaCRLIndicatorCRLExtensionHandle ElDeltaCRLIndicatorCRLExtensionHandle;

typedef TElClassHandle TElReasonCodeCRLExtensionHandle;

typedef TElReasonCodeCRLExtensionHandle ElReasonCodeCRLExtensionHandle;

typedef TElClassHandle TElHoldInstructionCodeCRLExtensionHandle;

typedef TElHoldInstructionCodeCRLExtensionHandle ElHoldInstructionCodeCRLExtensionHandle;

typedef TElClassHandle TElInvalidityDateCRLExtensionHandle;

typedef TElInvalidityDateCRLExtensionHandle ElInvalidityDateCRLExtensionHandle;

typedef TElClassHandle TElCertificateIssuerCRLExtensionHandle;

typedef TElCertificateIssuerCRLExtensionHandle ElCertificateIssuerCRLExtensionHandle;

typedef TElClassHandle TElIssuingDistributionPointCRLExtensionHandle;

typedef TElClassHandle TElCRLExtensionsHandle;

typedef TElCRLExtensionsHandle ElCRLExtensionsHandle;

typedef TElClassHandle TElCRLEntryExtensionsHandle;

typedef TElCRLEntryExtensionsHandle ElCRLEntryExtensionsHandle;

typedef TElClassHandle TElRevocationItemHandle;

typedef TElRevocationItemHandle ElRevocationItemHandle;

typedef TElClassHandle TElCertificateRevocationListHandle;

typedef TElCertificateRevocationListHandle ElCertificateRevocationListHandle;

typedef uint8_t TSBCRLFileFormatRaw;

typedef enum
{
	crlfUnknown = 0,
	crlfDER = 1,
	crlfPEM = 2
} TSBCRLFileFormat;

typedef uint8_t TElInstructionCodeRaw;

typedef enum
{
	icNone = 0,
	icCallIssuer = 1,
	icReject = 2
} TElInstructionCode;

typedef uint8_t TSBCRLExtensionRaw;

typedef enum
{
	crlAuthorityKeyIdentifier = 0,
	crlIssuerAlternativeName = 1,
	crlCRLNumber = 2,
	crlDeltaCRLIndicator = 3,
	crlIssuingDistributionPoint = 4
} TSBCRLExtension;

typedef uint32_t TSBCRLExtensionsRaw;

typedef enum 
{
	f_crlAuthorityKeyIdentifier = 1,
	f_crlIssuerAlternativeName = 2,
	f_crlCRLNumber = 4,
	f_crlDeltaCRLIndicator = 8,
	f_crlIssuingDistributionPoint = 16
} TSBCRLExtensions;

typedef uint8_t TSBCRLEntryExtensionRaw;

typedef enum
{
	crlReasonCode = 0,
	crlHoldInstructionCode = 1,
	crlInvalidityDate = 2,
	crlCertificateIssuer = 3
} TSBCRLEntryExtension;

typedef uint32_t TSBCRLEntryExtensionsRaw;

typedef enum 
{
	f_crlReasonCode = 1,
	f_crlHoldInstructionCode = 2,
	f_crlInvalidityDate = 4,
	f_crlCertificateIssuer = 8
} TSBCRLEntryExtensions;

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_get_KeyIdentifier(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_set_KeyIdentifier(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_get_AuthorityCertIssuer(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_get_AuthorityCertSerial(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_set_AuthorityCertSerial(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_get_IssuerSet(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_set_IssuerSet(TElAuthorityKeyIdentifierCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthorityKeyIdentifierCRLExtension_Create(TElAuthorityKeyIdentifierCRLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCRLNumberCRLExtension_get_Number(TElCRLNumberCRLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLNumberCRLExtension_set_Number(TElCRLNumberCRLExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLNumberCRLExtension_get_BinaryNumber(TElCRLNumberCRLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLNumberCRLExtension_set_BinaryNumber(TElCRLNumberCRLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCRLNumberCRLExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElDeltaCRLIndicatorCRLExtension_get_Number(TElDeltaCRLIndicatorCRLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDeltaCRLIndicatorCRLExtension_set_Number(TElDeltaCRLIndicatorCRLExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDeltaCRLIndicatorCRLExtension_get_BinaryNumber(TElDeltaCRLIndicatorCRLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDeltaCRLIndicatorCRLExtension_set_BinaryNumber(TElDeltaCRLIndicatorCRLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDeltaCRLIndicatorCRLExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */

#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElReasonCodeCRLExtension_get_Reason(TElReasonCodeCRLExtensionHandle _Handle, TSBCRLReasonFlagRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReasonCodeCRLExtension_set_Reason(TElReasonCodeCRLExtensionHandle _Handle, TSBCRLReasonFlagRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElReasonCodeCRLExtension_get_RemoveFromCRL(TElReasonCodeCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElReasonCodeCRLExtension_set_RemoveFromCRL(TElReasonCodeCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElReasonCodeCRLExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElHoldInstructionCodeCRLExtension_get_Code(TElHoldInstructionCodeCRLExtensionHandle _Handle, TElInstructionCodeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHoldInstructionCodeCRLExtension_set_Code(TElHoldInstructionCodeCRLExtensionHandle _Handle, TElInstructionCodeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElHoldInstructionCodeCRLExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElInvalidityDateCRLExtension_get_InvalidityDate(TElInvalidityDateCRLExtensionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElInvalidityDateCRLExtension_set_InvalidityDate(TElInvalidityDateCRLExtensionHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElInvalidityDateCRLExtension_Create(TElCustomExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCertificateIssuerCRLExtension_get_Issuer(TElCertificateIssuerCRLExtensionHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateIssuerCRLExtension_Create(TElCertificateIssuerCRLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_DistributionPoint(TElIssuingDistributionPointCRLExtensionHandle _Handle, TElGeneralNamesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_OnlySomeReasons(TElIssuingDistributionPointCRLExtensionHandle _Handle, TSBCRLReasonFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_OnlySomeReasons(TElIssuingDistributionPointCRLExtensionHandle _Handle, TSBCRLReasonFlagsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_OnlyContainsUserCerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_OnlyContainsUserCerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_OnlyContainsCACerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_OnlyContainsCACerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_OnlyContainsAttributeCerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_OnlyContainsAttributeCerts(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_IndirectCRL(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_IndirectCRL(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_get_ReasonFlagsIncluded(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_set_ReasonFlagsIncluded(TElIssuingDistributionPointCRLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElIssuingDistributionPointCRLExtension_Create(TElIssuingDistributionPointCRLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_AuthorityKeyIdentifier(TElCRLExtensionsHandle _Handle, TElAuthorityKeyIdentifierCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_IssuerAlternativeName(TElCRLExtensionsHandle _Handle, TElAlternativeNameExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_CRLNumber(TElCRLExtensionsHandle _Handle, TElCRLNumberCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_DeltaCRLIndicator(TElCRLExtensionsHandle _Handle, TElDeltaCRLIndicatorCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_IssuingDistributionPoint(TElCRLExtensionsHandle _Handle, TElIssuingDistributionPointCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_OtherExtensions(TElCRLExtensionsHandle _Handle, int32_t Index, TElCustomExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_OtherCount(TElCRLExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_set_OtherCount(TElCRLExtensionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_Included(TElCRLExtensionsHandle _Handle, TSBCRLExtensionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_set_Included(TElCRLExtensionsHandle _Handle, TSBCRLExtensionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_get_SaveDefaultASN1Tags(TElCRLExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_set_SaveDefaultASN1Tags(TElCRLExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLExtensions_Create(TElCRLExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_ReasonCode(TElCRLEntryExtensionsHandle _Handle, TElReasonCodeCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_HoldInstructionCode(TElCRLEntryExtensionsHandle _Handle, TElHoldInstructionCodeCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_InvalidityDate(TElCRLEntryExtensionsHandle _Handle, TElInvalidityDateCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_CertificateIssuer(TElCRLEntryExtensionsHandle _Handle, TElCertificateIssuerCRLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_OtherExtensions(TElCRLEntryExtensionsHandle _Handle, int32_t Index, TElCustomExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_OtherCount(TElCRLEntryExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_set_OtherCount(TElCRLEntryExtensionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_Included(TElCRLEntryExtensionsHandle _Handle, TSBCRLEntryExtensionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_set_Included(TElCRLEntryExtensionsHandle _Handle, TSBCRLEntryExtensionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_get_SaveDefaultASN1Tags(TElCRLEntryExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_set_SaveDefaultASN1Tags(TElCRLEntryExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCRLEntryExtensions_Create(TElCRLEntryExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

#ifdef SB_USE_CLASS_TELREVOCATIONITEM
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_get_SerialNumber(TElRevocationItemHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_set_SerialNumber(TElRevocationItemHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_get_RevocationDate(TElRevocationItemHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_set_RevocationDate(TElRevocationItemHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_get_Extensions(TElRevocationItemHandle _Handle, TElCRLEntryExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRevocationItem_Create(TElRevocationItemHandle * OutResult);
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat(const char * pcFileName, int32_t szFileName, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat_1(TElCertificateRevocationListHandle _Handle, const char * pcFileName, int32_t szFileName, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat_2(TStreamHandle Stream, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat_3(TElCertificateRevocationListHandle _Handle, TStreamHandle Stream, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat_4(void * Buffer, int32_t Size, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_DetectCRLFileFormat_5(TElCertificateRevocationListHandle _Handle, void * Buffer, int32_t Size, TSBCRLFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Add(TElCertificateRevocationListHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Add_1(TElCertificateRevocationListHandle _Handle, const uint8_t pSerialNumber[], int32_t szSerialNumber, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Assign(TElCertificateRevocationListHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Remove(TElCertificateRevocationListHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Remove_1(TElCertificateRevocationListHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_IsPresent(TElCertificateRevocationListHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_IndexOf(TElCertificateRevocationListHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Clear(TElCertificateRevocationListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_LoadFromBuffer(TElCertificateRevocationListHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_SaveToBuffer(TElCertificateRevocationListHandle _Handle, void * Buffer, int32_t * Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_LoadFromBufferPEM(TElCertificateRevocationListHandle _Handle, void * Buffer, int32_t Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_SaveToBufferPEM(TElCertificateRevocationListHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_LoadFromStream(TElCertificateRevocationListHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_LoadFromStreamPEM(TElCertificateRevocationListHandle _Handle, TStreamHandle Stream, const char * pcPassphrase, int32_t szPassphrase, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_SameCRL(TElCertificateRevocationListHandle _Handle, TElCertificateRevocationListHandle CRL, int8_t CheckUpdateTime, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Validate(TElCertificateRevocationListHandle _Handle, TElX509CertificateHandle Certificate, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_GetCRLHash(TElCertificateRevocationListHandle _Handle, int32_t Alg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Location(TElCertificateRevocationListHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_set_Location(TElCertificateRevocationListHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Issuer(TElCertificateRevocationListHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_ThisUpdate(TElCertificateRevocationListHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_set_ThisUpdate(TElCertificateRevocationListHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_NextUpdate(TElCertificateRevocationListHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_set_NextUpdate(TElCertificateRevocationListHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_SignatureAlgorithm(TElCertificateRevocationListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_SignatureAlgorithmIdentifier(TElCertificateRevocationListHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Signature(TElCertificateRevocationListHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_TBS(TElCertificateRevocationListHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Items(TElCertificateRevocationListHandle _Handle, int32_t Index, TElRevocationItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Count(TElCertificateRevocationListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_Extensions(TElCertificateRevocationListHandle _Handle, TElCRLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_get_CRLSize(TElCertificateRevocationListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRevocationList_Create(TComponentHandle Owner, TElCertificateRevocationListHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
typedef TElCustomExtension TElCRLExtension;
typedef TElCustomExtension ElCRLExtension;
class TElAuthorityKeyIdentifierCRLExtension;
typedef TElAuthorityKeyIdentifierCRLExtension ElAuthorityKeyIdentifierCRLExtension;
class TElCRLNumberCRLExtension;
typedef TElCRLNumberCRLExtension ElCRLNumberCRLExtension;
class TElDeltaCRLIndicatorCRLExtension;
typedef TElDeltaCRLIndicatorCRLExtension ElDeltaCRLIndicatorCRLExtension;
class TElReasonCodeCRLExtension;
typedef TElReasonCodeCRLExtension ElReasonCodeCRLExtension;
class TElHoldInstructionCodeCRLExtension;
typedef TElHoldInstructionCodeCRLExtension ElHoldInstructionCodeCRLExtension;
class TElInvalidityDateCRLExtension;
typedef TElInvalidityDateCRLExtension ElInvalidityDateCRLExtension;
class TElCertificateIssuerCRLExtension;
typedef TElCertificateIssuerCRLExtension ElCertificateIssuerCRLExtension;
class TElIssuingDistributionPointCRLExtension;
class TElCRLExtensions;
typedef TElCRLExtensions ElCRLExtensions;
class TElCRLEntryExtensions;
typedef TElCRLEntryExtensions ElCRLEntryExtensions;
class TElRevocationItem;
typedef TElRevocationItem ElRevocationItem;
class TElCertificateRevocationList;
typedef TElCertificateRevocationList ElCertificateRevocationList;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCRLExtensions)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCRLEntryExtensions)

#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
class TElAuthorityKeyIdentifierCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElAuthorityKeyIdentifierCRLExtension)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_AuthorityCertIssuer;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
		virtual void get_KeyIdentifier(std::vector<uint8_t> &OutResult);

		virtual void set_KeyIdentifier(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_AuthorityCertIssuer();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_AuthorityCertIssuer, TElAuthorityKeyIdentifierCRLExtension, AuthorityCertIssuer);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual void get_AuthorityCertSerial(std::vector<uint8_t> &OutResult);

		virtual void set_AuthorityCertSerial(const std::vector<uint8_t> &Value);

		virtual bool get_IssuerSet();

		virtual void set_IssuerSet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IssuerSet, set_IssuerSet, TElAuthorityKeyIdentifierCRLExtension, IssuerSet);

		TElAuthorityKeyIdentifierCRLExtension(TElAuthorityKeyIdentifierCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElAuthorityKeyIdentifierCRLExtension();

		virtual ~TElAuthorityKeyIdentifierCRLExtension();

};
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
class TElCRLNumberCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElCRLNumberCRLExtension)
	public:
		virtual int32_t get_Number();

		virtual void set_Number(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Number, set_Number, TElCRLNumberCRLExtension, Number);

		virtual void get_BinaryNumber(std::vector<uint8_t> &OutResult);

		virtual void set_BinaryNumber(const std::vector<uint8_t> &Value);

		TElCRLNumberCRLExtension(TElCRLNumberCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElCRLNumberCRLExtension();

};
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
class TElDeltaCRLIndicatorCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElDeltaCRLIndicatorCRLExtension)
	public:
		virtual int32_t get_Number();

		virtual void set_Number(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Number, set_Number, TElDeltaCRLIndicatorCRLExtension, Number);

		virtual void get_BinaryNumber(std::vector<uint8_t> &OutResult);

		virtual void set_BinaryNumber(const std::vector<uint8_t> &Value);

		TElDeltaCRLIndicatorCRLExtension(TElDeltaCRLIndicatorCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElDeltaCRLIndicatorCRLExtension();

};
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */

#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
class TElReasonCodeCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElReasonCodeCRLExtension)
	public:
		virtual TSBCRLReasonFlag get_Reason();

		virtual void set_Reason(TSBCRLReasonFlag Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlag, get_Reason, set_Reason, TElReasonCodeCRLExtension, Reason);

		virtual bool get_RemoveFromCRL();

		virtual void set_RemoveFromCRL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RemoveFromCRL, set_RemoveFromCRL, TElReasonCodeCRLExtension, RemoveFromCRL);

		TElReasonCodeCRLExtension(TElReasonCodeCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElReasonCodeCRLExtension();

};
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
class TElHoldInstructionCodeCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElHoldInstructionCodeCRLExtension)
	public:
		virtual TElInstructionCode get_Code();

		virtual void set_Code(TElInstructionCode Value);

		SB_DECLARE_PROPERTY(TElInstructionCode, get_Code, set_Code, TElHoldInstructionCodeCRLExtension, Code);

		TElHoldInstructionCodeCRLExtension(TElHoldInstructionCodeCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElHoldInstructionCodeCRLExtension();

};
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
class TElInvalidityDateCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElInvalidityDateCRLExtension)
	public:
		virtual int64_t get_InvalidityDate();

		virtual void set_InvalidityDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_InvalidityDate, set_InvalidityDate, TElInvalidityDateCRLExtension, InvalidityDate);

		TElInvalidityDateCRLExtension(TElInvalidityDateCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElInvalidityDateCRLExtension();

};
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
class TElCertificateIssuerCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElCertificateIssuerCRLExtension)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_Issuer, TElCertificateIssuerCRLExtension, Issuer);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		TElCertificateIssuerCRLExtension(TElCertificateIssuerCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElCertificateIssuerCRLExtension();

		virtual ~TElCertificateIssuerCRLExtension();

};
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
class TElIssuingDistributionPointCRLExtension: public TElCustomExtension
{
	private:
		SB_DISABLE_COPY(TElIssuingDistributionPointCRLExtension)
#ifdef SB_USE_CLASS_TELGENERALNAMES
		TElGeneralNames* _Inst_DistributionPoint;
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELGENERALNAMES
		virtual TElGeneralNames* get_DistributionPoint();

		SB_DECLARE_PROPERTY_GET(TElGeneralNames*, get_DistributionPoint, TElIssuingDistributionPointCRLExtension, DistributionPoint);
#endif /* SB_USE_CLASS_TELGENERALNAMES */

		virtual TSBCRLReasonFlags get_OnlySomeReasons();

		virtual void set_OnlySomeReasons(TSBCRLReasonFlags Value);

		SB_DECLARE_PROPERTY(TSBCRLReasonFlags, get_OnlySomeReasons, set_OnlySomeReasons, TElIssuingDistributionPointCRLExtension, OnlySomeReasons);

		virtual bool get_OnlyContainsUserCerts();

		virtual void set_OnlyContainsUserCerts(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OnlyContainsUserCerts, set_OnlyContainsUserCerts, TElIssuingDistributionPointCRLExtension, OnlyContainsUserCerts);

		virtual bool get_OnlyContainsCACerts();

		virtual void set_OnlyContainsCACerts(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OnlyContainsCACerts, set_OnlyContainsCACerts, TElIssuingDistributionPointCRLExtension, OnlyContainsCACerts);

		virtual bool get_OnlyContainsAttributeCerts();

		virtual void set_OnlyContainsAttributeCerts(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OnlyContainsAttributeCerts, set_OnlyContainsAttributeCerts, TElIssuingDistributionPointCRLExtension, OnlyContainsAttributeCerts);

		virtual bool get_IndirectCRL();

		virtual void set_IndirectCRL(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IndirectCRL, set_IndirectCRL, TElIssuingDistributionPointCRLExtension, IndirectCRL);

		virtual bool get_ReasonFlagsIncluded();

		virtual void set_ReasonFlagsIncluded(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReasonFlagsIncluded, set_ReasonFlagsIncluded, TElIssuingDistributionPointCRLExtension, ReasonFlagsIncluded);

		TElIssuingDistributionPointCRLExtension(TElIssuingDistributionPointCRLExtensionHandle handle, TElOwnHandle ownHandle);

		TElIssuingDistributionPointCRLExtension();

		virtual ~TElIssuingDistributionPointCRLExtension();

};
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
class TElCRLExtensions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCRLExtensions)
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
		TElAuthorityKeyIdentifierCRLExtension* _Inst_AuthorityKeyIdentifier;
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		TElAlternativeNameExtension* _Inst_IssuerAlternativeName;
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */
#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
		TElCRLNumberCRLExtension* _Inst_CRLNumber;
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
		TElDeltaCRLIndicatorCRLExtension* _Inst_DeltaCRLIndicator;
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */
#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
		TElIssuingDistributionPointCRLExtension* _Inst_IssuingDistributionPoint;
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		TElCustomExtension* _Inst_OtherExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION
		virtual TElAuthorityKeyIdentifierCRLExtension* get_AuthorityKeyIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAuthorityKeyIdentifierCRLExtension*, get_AuthorityKeyIdentifier, TElCRLExtensions, AuthorityKeyIdentifier);
#endif /* SB_USE_CLASS_TELAUTHORITYKEYIDENTIFIERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION
		virtual TElAlternativeNameExtension* get_IssuerAlternativeName();

		SB_DECLARE_PROPERTY_GET(TElAlternativeNameExtension*, get_IssuerAlternativeName, TElCRLExtensions, IssuerAlternativeName);
#endif /* SB_USE_CLASS_TELALTERNATIVENAMEEXTENSION */

#ifdef SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION
		virtual TElCRLNumberCRLExtension* get_CRLNumber();

		SB_DECLARE_PROPERTY_GET(TElCRLNumberCRLExtension*, get_CRLNumber, TElCRLExtensions, CRLNumber);
#endif /* SB_USE_CLASS_TELCRLNUMBERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION
		virtual TElDeltaCRLIndicatorCRLExtension* get_DeltaCRLIndicator();

		SB_DECLARE_PROPERTY_GET(TElDeltaCRLIndicatorCRLExtension*, get_DeltaCRLIndicator, TElCRLExtensions, DeltaCRLIndicator);
#endif /* SB_USE_CLASS_TELDELTACRLINDICATORCRLEXTENSION */

#ifdef SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION
		virtual TElIssuingDistributionPointCRLExtension* get_IssuingDistributionPoint();

		SB_DECLARE_PROPERTY_GET(TElIssuingDistributionPointCRLExtension*, get_IssuingDistributionPoint, TElCRLExtensions, IssuingDistributionPoint);
#endif /* SB_USE_CLASS_TELISSUINGDISTRIBUTIONPOINTCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		virtual TElCustomExtension* get_OtherExtensions(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		virtual int32_t get_OtherCount();

		virtual void set_OtherCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OtherCount, set_OtherCount, TElCRLExtensions, OtherCount);

		virtual TSBCRLExtensions get_Included();

		virtual void set_Included(TSBCRLExtensions Value);

		SB_DECLARE_PROPERTY(TSBCRLExtensions, get_Included, set_Included, TElCRLExtensions, Included);

		virtual bool get_SaveDefaultASN1Tags();

		virtual void set_SaveDefaultASN1Tags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveDefaultASN1Tags, set_SaveDefaultASN1Tags, TElCRLExtensions, SaveDefaultASN1Tags);

		TElCRLExtensions(TElCRLExtensionsHandle handle, TElOwnHandle ownHandle);

		TElCRLExtensions();

		virtual ~TElCRLExtensions();

};
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
class TElCRLEntryExtensions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCRLEntryExtensions)
#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
		TElReasonCodeCRLExtension* _Inst_ReasonCode;
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
		TElHoldInstructionCodeCRLExtension* _Inst_HoldInstructionCode;
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */
#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
		TElInvalidityDateCRLExtension* _Inst_InvalidityDate;
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
		TElCertificateIssuerCRLExtension* _Inst_CertificateIssuer;
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		TElCustomExtension* _Inst_OtherExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELREASONCODECRLEXTENSION
		virtual TElReasonCodeCRLExtension* get_ReasonCode();

		SB_DECLARE_PROPERTY_GET(TElReasonCodeCRLExtension*, get_ReasonCode, TElCRLEntryExtensions, ReasonCode);
#endif /* SB_USE_CLASS_TELREASONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION
		virtual TElHoldInstructionCodeCRLExtension* get_HoldInstructionCode();

		SB_DECLARE_PROPERTY_GET(TElHoldInstructionCodeCRLExtension*, get_HoldInstructionCode, TElCRLEntryExtensions, HoldInstructionCode);
#endif /* SB_USE_CLASS_TELHOLDINSTRUCTIONCODECRLEXTENSION */

#ifdef SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION
		virtual TElInvalidityDateCRLExtension* get_InvalidityDate();

		SB_DECLARE_PROPERTY_GET(TElInvalidityDateCRLExtension*, get_InvalidityDate, TElCRLEntryExtensions, InvalidityDate);
#endif /* SB_USE_CLASS_TELINVALIDITYDATECRLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION
		virtual TElCertificateIssuerCRLExtension* get_CertificateIssuer();

		SB_DECLARE_PROPERTY_GET(TElCertificateIssuerCRLExtension*, get_CertificateIssuer, TElCRLEntryExtensions, CertificateIssuer);
#endif /* SB_USE_CLASS_TELCERTIFICATEISSUERCRLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMEXTENSION
		virtual TElCustomExtension* get_OtherExtensions(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMEXTENSION */

		virtual int32_t get_OtherCount();

		virtual void set_OtherCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OtherCount, set_OtherCount, TElCRLEntryExtensions, OtherCount);

		virtual TSBCRLEntryExtensions get_Included();

		virtual void set_Included(TSBCRLEntryExtensions Value);

		SB_DECLARE_PROPERTY(TSBCRLEntryExtensions, get_Included, set_Included, TElCRLEntryExtensions, Included);

		virtual bool get_SaveDefaultASN1Tags();

		virtual void set_SaveDefaultASN1Tags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveDefaultASN1Tags, set_SaveDefaultASN1Tags, TElCRLEntryExtensions, SaveDefaultASN1Tags);

		TElCRLEntryExtensions(TElCRLEntryExtensionsHandle handle, TElOwnHandle ownHandle);

		TElCRLEntryExtensions();

		virtual ~TElCRLEntryExtensions();

};
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

#ifdef SB_USE_CLASS_TELREVOCATIONITEM
class TElRevocationItem: public TObject
{
	private:
		SB_DISABLE_COPY(TElRevocationItem)
#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
		TElCRLEntryExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

		void initInstances();

	public:
		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual int64_t get_RevocationDate();

		virtual void set_RevocationDate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_RevocationDate, set_RevocationDate, TElRevocationItem, RevocationDate);

#ifdef SB_USE_CLASS_TELCRLENTRYEXTENSIONS
		virtual TElCRLEntryExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCRLEntryExtensions*, get_Extensions, TElRevocationItem, Extensions);
#endif /* SB_USE_CLASS_TELCRLENTRYEXTENSIONS */

		TElRevocationItem(TElRevocationItemHandle handle, TElOwnHandle ownHandle);

		TElRevocationItem();

		virtual ~TElRevocationItem();

};
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */

#ifdef SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST
class TElCertificateRevocationList: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCertificateRevocationList)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Issuer;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_SignatureAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELREVOCATIONITEM
		TElRevocationItem* _Inst_Items;
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */
#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
		TElCRLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

		void initInstances();

	public:
		static TSBCRLFileFormat DetectCRLFileFormat(const std::string &FileName);

		TSBCRLFileFormat DetectCRLFileFormat_Inst(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		static TSBCRLFileFormat DetectCRLFileFormat(TStream &Stream);

		static TSBCRLFileFormat DetectCRLFileFormat(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TSBCRLFileFormat DetectCRLFileFormat_Inst(TStream &Stream);

		TSBCRLFileFormat DetectCRLFileFormat_Inst(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		static TSBCRLFileFormat DetectCRLFileFormat(void * Buffer, int32_t Size);

		TSBCRLFileFormat DetectCRLFileFormat_Inst(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t Add(TElX509Certificate &Certificate);

		int32_t Add(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		int32_t Add(const std::vector<uint8_t> &SerialNumber);

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool Remove(TElX509Certificate &Certificate);

		bool Remove(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		bool Remove(int32_t Index);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool IsPresent(TElX509Certificate &Certificate);

		bool IsPresent(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t IndexOf(TElX509Certificate &Certificate);

		int32_t IndexOf(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void Clear();

		int32_t LoadFromBuffer(void * Buffer, int32_t Size);

		int32_t SaveToBuffer(void * Buffer, int32_t &Size);

		int32_t LoadFromBufferPEM(void * Buffer, int32_t Size, const std::string &Passphrase);

		int32_t SaveToBufferPEM(void * Buffer, int32_t &Size, const std::string &Passphrase);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, int32_t Count);

		int32_t LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStreamPEM(TStream &Stream, const std::string &Passphrase, int32_t Count);

		int32_t LoadFromStreamPEM(TStream *Stream, const std::string &Passphrase, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool SameCRL(TElCertificateRevocationList &CRL, bool CheckUpdateTime);

		bool SameCRL(TElCertificateRevocationList *CRL, bool CheckUpdateTime);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t Validate(TElX509Certificate &Certificate);

		int32_t Validate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void GetCRLHash(int32_t Alg, std::vector<uint8_t> &OutResult);

		virtual void get_Location(std::string &OutResult);

		virtual void set_Location(const std::string &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Issuer();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Issuer, TElCertificateRevocationList, Issuer);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int64_t get_ThisUpdate();

		virtual void set_ThisUpdate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ThisUpdate, set_ThisUpdate, TElCertificateRevocationList, ThisUpdate);

		virtual int64_t get_NextUpdate();

		virtual void set_NextUpdate(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_NextUpdate, set_NextUpdate, TElCertificateRevocationList, NextUpdate);

		virtual int32_t get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureAlgorithm, TElCertificateRevocationList, SignatureAlgorithm);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_SignatureAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_SignatureAlgorithmIdentifier, TElCertificateRevocationList, SignatureAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		virtual void get_Signature(std::vector<uint8_t> &OutResult);

		virtual void get_TBS(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELREVOCATIONITEM
		virtual TElRevocationItem* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELREVOCATIONITEM */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCertificateRevocationList, Count);

#ifdef SB_USE_CLASS_TELCRLEXTENSIONS
		virtual TElCRLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCRLExtensions*, get_Extensions, TElCertificateRevocationList, Extensions);
#endif /* SB_USE_CLASS_TELCRLEXTENSIONS */

		virtual int32_t get_CRLSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_CRLSize, TElCertificateRevocationList, CRLSize);

		TElCertificateRevocationList(TElCertificateRevocationListHandle handle, TElOwnHandle ownHandle);

		explicit TElCertificateRevocationList(TComponent &Owner);

		explicit TElCertificateRevocationList(TComponent *Owner);

		virtual ~TElCertificateRevocationList();

};
#endif /* SB_USE_CLASS_TELCERTIFICATEREVOCATIONLIST */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRL */

