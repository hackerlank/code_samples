#ifndef __INC_SBELGAMAL
#define __INC_SBELGAMAL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
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

#ifdef SB_USE_GLOBAL_PROCS_ELGAMAL

bool Generate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool ExternalGenerate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data);

bool SBElgamal_ExternalGenerationSupported();

bool Encrypt(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B);

bool Decrypt(PLInt P, PLInt G, PLInt X, PLInt A, PLInt B, PLInt Dest);

bool Sign(PLInt Src, PLInt P, PLInt G, PLInt X, PLInt A, PLInt B);

bool Verify(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B);

bool EncodeResult(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t &BlobSize);

bool DecodeResult(void * Blob, int32_t Size, void * R, int32_t &RSize, void * S, int32_t &SSize);

bool EncodePublicKey(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t &OutSize);

bool SBElgamal_EncodePrivateKey(void * P, int32_t PSize, void * G, int32_t GSize, void * X, int32_t XSize, void * OutBuffer, int32_t &OutSize);

#endif /* SB_USE_GLOBAL_PROCS_ELGAMAL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_ELGAMAL
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_Generate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_ExternalGenerate(int32_t Bits, PLInt P, PLInt G, PLInt X, PLInt Y, TSBMathProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_ExternalGenerationSupported(int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_Encrypt(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_Decrypt(PLInt P, PLInt G, PLInt X, PLInt A, PLInt B, PLInt Dest, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_Sign(PLInt Src, PLInt P, PLInt G, PLInt X, PLInt A, PLInt B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_Verify(PLInt Src, PLInt P, PLInt G, PLInt Y, PLInt A, PLInt B, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_EncodeResult(void * R, int32_t RSize, void * S, int32_t SSize, void * Blob, int32_t * BlobSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_DecodeResult(void * Blob, int32_t Size, void * R, int32_t * RSize, void * S, int32_t * SSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_EncodePublicKey(void * P, int32_t PSize, void * G, int32_t GSize, void * Y, int32_t YSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBElgamal_EncodePrivateKey(void * P, int32_t PSize, void * G, int32_t GSize, void * X, int32_t XSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_ELGAMAL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBELGAMAL */

