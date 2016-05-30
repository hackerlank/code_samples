#ifndef __INC_SBMSKEYBLOB
#define __INC_SBMSKEYBLOB

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbalgorithmidentifier.h"
#include "sbconstants.h"
#include "sbgost2814789.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_MSKEYBLOB_ERROR_UNSUPPORTED_BLOB_TYPE 	8449
#define SB_MSKEYBLOB_ERROR_INVALID_FORMAT 	8450
#define SB_MSKEYBLOB_ERROR_UNSUPPORTED_VERSION 	8451
#define SB_MSKEYBLOB_ERROR_BUFFER_TOO_SMALL 	8452
#define SB_MSKEYBLOB_ERROR_NO_PRIVATE_KEY 	8453
#define SB_MSKEYBLOB_ERROR_UNSUPPORTED_ALGORITHM 	8454
#define SB_KEY_BLOB_RSA 	1
#define SB_KEY_BLOB_DSS 	2

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

#ifdef SB_USE_GLOBAL_PROCS_MSKEYBLOB

bool WriteMSPublicKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, int32_t BlobType);

bool WriteMSDSSPublicKeyBlob(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t &OutSize);

int32_t ParseMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, int32_t &BlobType);

bool WriteMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, uint8_t BlobType);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
bool WriteMSKeyBlobEx(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, TElAlgorithmIdentifier &Algorithm);
bool WriteMSKeyBlobEx(void * Buffer, int32_t Size, void * OutBuffer, int32_t &OutSize, TElAlgorithmIdentifier *Algorithm);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#endif /* SB_USE_GLOBAL_PROCS_MSKEYBLOB */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_MSKEYBLOB
SB_IMPORT uint32_t SB_APIENTRY SBMSKeyBlob_WriteMSPublicKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int32_t BlobType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMSKeyBlob_WriteMSDSSPublicKeyBlob(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMSKeyBlob_ParseMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, int32_t * BlobType, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMSKeyBlob_WriteMSKeyBlob(void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, uint8_t BlobType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBMSKeyBlob_WriteMSKeyBlobEx(void * Buffer, int32_t Size, void * OutBuffer, int32_t * OutSize, TElAlgorithmIdentifierHandle Algorithm, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_MSKEYBLOB */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBMSKEYBLOB */

