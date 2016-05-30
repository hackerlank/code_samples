#ifndef __INC_SBCRYPTOPROVUTILS
#define __INC_SBCRYPTOPROVUTILS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcryptoprov.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbrdn.h"

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

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
bool CryptoProvGetBoolParam(TElRelativeDistinguishedName &Params, const std::vector<uint8_t> &Name, bool Default);
bool CryptoProvGetBoolParam(TElRelativeDistinguishedName *Params, const std::vector<uint8_t> &Name, bool Default);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

int32_t GetIntegerPropFromBuffer(const std::vector<uint8_t> &Value, int32_t Default);

int64_t GetInt64PropFromBuffer(const std::vector<uint8_t> &Value, int32_t Default);

void GetBufferFromInteger(int32_t Value, std::vector<uint8_t> &OutResult);

void GetBufferFromInt64(int64_t Value, std::vector<uint8_t> &OutResult);

bool GetBoolFromBuffer(const std::vector<uint8_t> &Value, bool Default);

void GetBufferFromBool(bool Value, std::vector<uint8_t> &OutResult);

void * GetPointerFromBuffer(const std::vector<uint8_t> &Value);

void GetBufferFromPointer(void * Value, std::vector<uint8_t> &OutResult);

bool ExtractSymmetricCipherParams(const std::vector<uint8_t> &AlgOID, const std::vector<uint8_t> &AlgParams, int32_t &KeyLen, std::vector<uint8_t> &IV);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void SerializeParams(TElRelativeDistinguishedName &Params, std::vector<uint8_t> &OutResult);
void SerializeParams(TElRelativeDistinguishedName *Params, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
TElRelativeDistinguishedNameHandle UnserializeParams(void * Buffer, int32_t Size);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

bool IsKeyDrivenOperation(int32_t OpType);

bool IsSecretKeyOperation(int32_t OpType);

bool IsAlgorithmIndependentOperation(int32_t OpType);

#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_CryptoProvGetBoolParam(TElRelativeDistinguishedNameHandle Params, const uint8_t pName[], int32_t szName, int8_t Default, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetIntegerPropFromBuffer(const uint8_t pValue[], int32_t szValue, int32_t Default, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetInt64PropFromBuffer(const uint8_t pValue[], int32_t szValue, int32_t Default, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetBufferFromInteger(int32_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetBufferFromInt64(int64_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetBoolFromBuffer(const uint8_t pValue[], int32_t szValue, int8_t Default, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetBufferFromBool(int8_t Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetPointerFromBuffer(const uint8_t pValue[], int32_t szValue, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_GetBufferFromPointer(void * Value, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_ExtractSymmetricCipherParams(const uint8_t pAlgOID[], int32_t szAlgOID, const uint8_t pAlgParams[], int32_t szAlgParams, int32_t * KeyLen, uint8_t pIV[], int32_t * szIV, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_SerializeParams(TElRelativeDistinguishedNameHandle Params, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_UnserializeParams(void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_IsKeyDrivenOperation(int32_t OpType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_IsSecretKeyOperation(int32_t OpType, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBCryptoProvUtils_IsAlgorithmIndependentOperation(int32_t OpType, int8_t * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_CRYPTOPROVUTILS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVUTILS */

