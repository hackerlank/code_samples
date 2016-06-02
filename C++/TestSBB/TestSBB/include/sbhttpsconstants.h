#ifndef __INC_SBHTTPSCONSTANTS
#define __INC_SBHTTPSCONSTANTS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbconstants.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_HTTP_REQUEST_CUSTOM 	0
#define SB_HTTP_REQUEST_FIRST 	1
#define SB_HTTP_REQUEST_GET 	1
#define SB_HTTP_REQUEST_POST 	2
#define SB_HTTP_REQUEST_HEAD 	3
#define SB_HTTP_REQUEST_OPTIONS 	4
#define SB_HTTP_REQUEST_DELETE 	5
#define SB_HTTP_REQUEST_TRACE 	6
#define SB_HTTP_REQUEST_PUT 	7
#define SB_HTTP_REQUEST_CONNECT 	8
#define SB_HTTP_REQUEST_LAST 	8
#define SB_SInvalidDateTime 	"Invalid date/time parameter"
#define SB_sfIndexOutOfBounds 	"Index out of bounds (%d)."

typedef uint8_t TSBHTTPVersionRaw;

typedef enum
{
	hvHTTP10 = 0,
	hvHTTP11 = 1
} TSBHTTPVersion;

typedef uint8_t SBHTTPSConstants_TSBHTTPChunkStateRaw;

typedef enum
{
	chSize = 0,
	chLineFeed = 1,
	chData = 2,
	chHeader = 3
} SBHTTPSConstants_TSBHTTPChunkState;

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBHTTPSCONSTANTS */

