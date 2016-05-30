#ifndef __INC_SBFTPSCOMMON
#define __INC_SBFTPSCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

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

#ifdef SB_USE_GLOBAL_PROCS_FTPSCOMMON

bool IsWhitespace(uint8_t b);

void DateTimeToFTPTimeVal(int64_t DateTime, std::string &OutResult);

void UnixPermissionsToStringRwx(uint32_t Permissions, std::string &OutResult);

void UnixPermissionsToStringOct(uint32_t Permissions, std::string &OutResult);

#endif /* SB_USE_GLOBAL_PROCS_FTPSCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_FTPSCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBFTPSCommon_IsWhitespace(uint8_t b, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBFTPSCommon_DateTimeToFTPTimeVal(int64_t DateTime, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBFTPSCommon_UnixPermissionsToStringRwx(uint32_t Permissions, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBFTPSCommon_UnixPermissionsToStringOct(uint32_t Permissions, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_FTPSCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBFTPSCOMMON */

