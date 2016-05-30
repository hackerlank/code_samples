#ifndef __INC_SBPKICOMMON
#define __INC_SBPKICOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbx509.h"
#include "sbpkcs7utils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef uint8_t TSBCMSSignatureValidityRaw;

typedef enum
{
	csvValid = 0,
	csvInvalid = 1,
	csvSignerNotFound = 2,
	csvGeneralFailure = 3
} TSBCMSSignatureValidity;

typedef uint8_t TSBCMSValidationOptionRaw;

typedef enum
{
	cvoRecursiveValidation = 0,
	cvoValidateChains = 1,
	cvoValidateTimes = 2,
	cvoCheckRevocationStatus = 3,
	cvoRequireTimestamps = 4,
	cvoIgnoreLocalTimestamps = 5,
	cvoValidateTrusts = 6
} TSBCMSValidationOption;

typedef uint32_t TSBCMSValidationOptionsRaw;

typedef enum 
{
	f_cvoRecursiveValidation = 1,
	f_cvoValidateChains = 2,
	f_cvoValidateTimes = 4,
	f_cvoCheckRevocationStatus = 8,
	f_cvoRequireTimestamps = 16,
	f_cvoIgnoreLocalTimestamps = 32,
	f_cvoValidateTrusts = 64
} TSBCMSValidationOptions;

typedef uint8_t TSBCMSAdvancedSignatureValidityRaw;

typedef enum
{
	casvValid = 0,
	casvSignatureCorrupted = 1,
	casvSignerNotFound = 2,
	casvIncompleteChain = 3,
	casvBadCountersignature = 4,
	casvBadTimestamp = 5,
	casvCertificateExpired = 6,
	casvCertificateRevoked = 7,
	casvCertificateCorrupted = 8,
	casvUntrustedCA = 9,
	casvRevInfoNotFound = 10,
	casvTimestampInfoNotFound = 11,
	casvFailure = 12,
	casvCertificateMalformed = 13,
	casvUnknown = 14,
	casvChainValidationFailed = 15
} TSBCMSAdvancedSignatureValidity;

typedef uint8_t TSBPKIStatusRaw;

typedef enum
{
	psGranted = 0,
	psGrantedWithMods = 1,
	psRejection = 2,
	psWaiting = 3,
	psRevocationWarning = 4,
	psRevocationNotification = 5,
	psKeyUpdateWarning = 6
} TSBPKIStatus;

typedef uint8_t TSBPKIFailureInfoRaw;

typedef enum
{
	pfiBadAlg = 0,
	pfiBadMessageCheck = 1,
	pfiBadRequest = 2,
	pfiBadTime = 3,
	pfiBadCertId = 4,
	pfiBadDataFormat = 5,
	pfiWrongAuthority = 6,
	pfiIncorrectData = 7,
	pfiMissingTimeStamp = 8,
	pfiBadPOP = 9
} TSBPKIFailureInfo;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCMSValidationOptions)

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKICOMMON */

