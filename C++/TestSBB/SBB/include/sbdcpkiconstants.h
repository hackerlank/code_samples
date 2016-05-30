#ifndef __INC_SBDCPKICONSTANTS
#define __INC_SBDCPKICONSTANTS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OID_DC_CERTIFICATE 	"certificate@eldos.com"
#define SB_OID_DC_SIGNING_CERTIFICATE 	"signing-certificate@eldos.com"
#define SB_OID_DC_P7_SIGNING_TIME 	"dcp7signingtime@eldos.com"
#define SB_OID_DC_P7_CONTENT_TYPE 	"dcp7contenttype@eldos.com"
#define SB_OID_DC_P7_INCLUDE_CERTIFICATES 	"dcp7includecerts@eldos.com"
#define SB_OID_DC_P7_INCLUDE_CHAIN 	"dcp7includechain@eldos.com"
#define SB_OID_DC_P7_TIMESTAMP 	"dcp7timestamp@eldos.com"
#define SB_OID_DC_P7_USE_GENERALIZED_TIME_FORMAT 	"dcp7usegentimeformat@eldos.com"
#define SB_OID_DC_P7_USE_UNDEF_SIZE 	"dcp7useundefsize@eldos.com"
#define SB_OID_DC_P7_SIGNED_ATTRIBUTES 	"dcp7signedattrs@eldos.com"
#define SB_OID_DC_P7_UNSIGNED_ATTRIBUTES 	"dcp7unsignedattrs@eldos.com"
#define SB_OID_DC_P7_INSERT_MESSAGE_DIGESTS 	"dcp7insertmd@eldos.com"
#define SB_OID_DC_P7_IGNORE_TIMESTAMP_FAILURE 	"dcp7ignoretsfailure@eldos.com"
#define SB_OID_DC_P7_NO_OUTER_CONTENT_INFO 	"dcp7noouterci@eldos.com"
#define SB_OID_DC_P7_INSERT_SIGNING_TIME 	"dcp7insertsigningtime@eldos.com"
#define SB_OID_DC_P7_INSERT_CONTENT_TYPE 	"dcp7insertct@eldos.com"
#define SB_OID_DC_P7_INSERT_SIGNINGCERT_ATTR 	"dcp7insertsigningcert@eldos.com"
#define SB_OID_DC_P7_FORCE_SIGNINGCERT_V2 	"dcp7forcesigningcertv2@eldos.com"
#define SB_OID_DC_P7_INCLUDE_CRLS 	"dcp7includecrls@eldos.com"
#define SB_OID_DC_P7_INCLUDE_REVINFO_TO_ATTRS 	"dcp7includerevinfotoattrs@eldos.com"
#define SB_OID_DC_P7_USE_IMPLICIT_CONTENT 	"dcp7useimplcontent@eldos.com"
#define SB_OID_DC_P7_TIMESTAMP_SERVICE_ID 	"dcp7tssid@eldos.com"
#define SB_OID_DC_P7_TIMESTAMP_HASH_ALGORITHM 	"dcp7tshashalg@eldos.com"
#define SB_OID_DC_P7_SGNDATA_VERSION 	"dcp7sgndataversion@eldos.com"
#define SB_OID_DC_P7_CUSTOMOP_PFX 	"dcp7customop@eldos.com-"

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCPKICONSTANTS */

