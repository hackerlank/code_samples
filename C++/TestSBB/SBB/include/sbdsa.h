#ifndef __INC_SBDSA
#define __INC_SBDSA

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbconstants.h"
#include "sbhashfunction.h"
#include "sbtypes.h"
#include "sbstrutils.h"
#include "sbutils.h"

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

#ifdef SB_USE_GLOBAL_PROCS_DSA

bool ValidateSignature(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * R, int32_t RSize, void * S, int32_t SSize);

bool Generate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize);

bool Generate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool ExternalGenerate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize);

bool ExternalGenerate(int32_t Bits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, void * PrivateKeyBlob, int32_t &PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool GenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool ExternalGenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool Sign(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool SignEx(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool DecodePrivateKey(void * Buffer, int32_t Size, void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize, void * X, int32_t &XSize);

bool EncodePrivateKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize);

bool EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize);

bool DecodeSignature(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool IsValidKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, bool Secret, bool StrictMode);

bool ExternalGenerationSupported();

#endif /* SB_USE_GLOBAL_PROCS_DSA */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DSA
SB_IMPORT uint32_t SB_APIENTRY SBDSA_ValidateSignature(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * R, int32_t RSize, void * S, int32_t SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_Generate(int32_t Bits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_Generate_1(int32_t Bits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, void * PrivateKeyBlob, int32_t * PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_ExternalGenerate(int32_t Bits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_ExternalGenerate_1(int32_t Bits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, void * PrivateKeyBlob, int32_t * PrivateKeyBlobSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_GenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_ExternalGenerateEx(int32_t PBits, int32_t QBits, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_Sign(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_SignEx(void * Hash, int32_t HashSize, void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * X, int32_t XSize, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_DecodePrivateKey(void * Buffer, int32_t Size, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, void * X, int32_t * XSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_EncodePrivateKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t * BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_DecodeSignature(void * Blob, int32_t Size, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_IsValidKey(void * P, int32_t PSize, void * Q, int32_t QSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * X, int32_t XSize, int8_t Secret, int8_t StrictMode, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBDSA_ExternalGenerationSupported(int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DSA */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDSA */

