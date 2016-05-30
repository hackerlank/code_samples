#ifndef __INC_SBALGORITHMIDENTIFIER
#define __INC_SBALGORITHMIDENTIFIER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
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
typedef TElClassHandle TElAlgorithmIdentifierHandle;

typedef TElClassHandle TElRSAAlgorithmIdentifierHandle;

typedef TElClassHandle TElRSAPSSAlgorithmIdentifierHandle;

typedef TElClassHandle TElRSAOAEPAlgorithmIdentifierHandle;

typedef TElClassHandle TElDSAAlgorithmIdentifierHandle;

typedef TElClassHandle TElDHAlgorithmIdentifierHandle;

typedef TElClassHandle TElECAlgorithmIdentifierHandle;

typedef TElClassHandle TElECDSAAlgorithmIdentifierHandle;

typedef TElClassHandle TElGOST3411AlgorithmIdentifierHandle;

typedef TElClassHandle TElGOST3410AlgorithmIdentifierHandle;

typedef TElClassHandle TElGOST3411WithGOST3410AlgorithmIdentifierHandle;

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_Assign(TElAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_Clone(TElAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_Equals(TElAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateFromBuffer(void * Buffer, int32_t Size, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateFromBuffer_1(TElAlgorithmIdentifierHandle _Handle, void * Buffer, int32_t Size, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateFromTag(TElASN1ConstrainedTagHandle Tag, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateFromTag_1(TElAlgorithmIdentifierHandle _Handle, TElASN1ConstrainedTagHandle Tag, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateByAlgorithm(int32_t Algorithm, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateByAlgorithm_1(TElAlgorithmIdentifierHandle _Handle, int32_t Algorithm, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateByAlgorithmOID(const uint8_t pOID[], int32_t szOID, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_CreateByAlgorithmOID_1(TElAlgorithmIdentifierHandle _Handle, const uint8_t pOID[], int32_t szOID, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_IsAlgorithmSupported(TElAlgorithmIdentifierHandle _Handle, int32_t Algorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_LoadFromBuffer(TElAlgorithmIdentifierHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_SaveToBuffer(TElAlgorithmIdentifierHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_LoadFromTag(TElAlgorithmIdentifierHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_SaveToTag(TElAlgorithmIdentifierHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_WriteParameters(TElAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_AlgorithmOID(TElAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_set_AlgorithmOID(TElAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_Algorithm(TElAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_set_Algorithm(TElAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_SignatureHashAlgorithm(TElAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_IsSignatureAlgorithm(TElAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_IsPublicKeyAlgorithm(TElAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_IsEncryptionAlgorithm(TElAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_get_IsHashAlgorithm(TElAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAlgorithmIdentifier_Create(TElAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElRSAAlgorithmIdentifier_Assign(TElRSAAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAlgorithmIdentifier_get_HashAlgorithm(TElRSAAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAlgorithmIdentifier_set_HashAlgorithm(TElRSAAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAAlgorithmIdentifier_Create(TElRSAAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_Assign(TElRSAPSSAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_get_HashAlgorithm(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_set_HashAlgorithm(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_get_SaltSize(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_set_SaltSize(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_get_TrailerField(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_set_TrailerField(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_get_MGF(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_set_MGF(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_get_MGFHashAlgorithm(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_set_MGFHashAlgorithm(TElRSAPSSAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAPSSAlgorithmIdentifier_Create(TElRSAPSSAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_Assign(TElRSAOAEPAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_get_HashAlgorithm(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_set_HashAlgorithm(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_get_MGF(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_set_MGF(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_get_MGFHashAlgorithm(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_set_MGFHashAlgorithm(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_get_StrLabel(TElRSAOAEPAlgorithmIdentifierHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_set_StrLabel(TElRSAOAEPAlgorithmIdentifierHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_get_WriteDefaults(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_set_WriteDefaults(TElRSAOAEPAlgorithmIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRSAOAEPAlgorithmIdentifier_Create(TElRSAOAEPAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_Assign(TElDSAAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_get_P(TElDSAAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_set_P(TElDSAAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_get_Q(TElDSAAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_set_Q(TElDSAAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_get_G(TElDSAAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_set_G(TElDSAAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDSAAlgorithmIdentifier_Create(TElDSAAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDHALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_Assign(TElDHAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_get_P(TElDHAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_set_P(TElDHAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_get_Q(TElDHAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_set_Q(TElDHAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_get_G(TElDHAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_set_G(TElDHAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDHAlgorithmIdentifier_Create(TElDHAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELDHALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_Assign(TElECAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Version(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Version(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Curve(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Curve(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_FieldID(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_FieldID(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_FieldType(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_FieldType(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Basis(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Basis(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_M(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_M(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_K1(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_K1(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_K2(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_K2(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_K3(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_K3(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_HashAlgorithm(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_HashAlgorithm(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_SpecifiedCurve(TElECAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_SpecifiedCurve(TElECAlgorithmIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_CompressPoints(TElECAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_CompressPoints(TElECAlgorithmIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_HybridPoints(TElECAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_HybridPoints(TElECAlgorithmIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_ImplicitCurve(TElECAlgorithmIdentifierHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_ImplicitCurve(TElECAlgorithmIdentifierHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Seed(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Seed(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_P(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_P(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_N(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_N(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_H(TElECAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_H(TElECAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_A(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_A(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_B(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_B(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_X(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_X(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Y(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Y(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_get_Base(TElECAlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_set_Base(TElECAlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECAlgorithmIdentifier_Create(TElECAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELECALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElECDSAAlgorithmIdentifier_Assign(TElECDSAAlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAAlgorithmIdentifier_get_HashAlgorithm(TElECDSAAlgorithmIdentifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAAlgorithmIdentifier_set_HashAlgorithm(TElECDSAAlgorithmIdentifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECDSAAlgorithmIdentifier_Create(TElECDSAAlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElGOST3411AlgorithmIdentifier_Assign(TElGOST3411AlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3411AlgorithmIdentifier_Create(TElGOST3411AlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_Assign(TElGOST3410AlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_get_PublicKeyParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_set_PublicKeyParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_get_DigestParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_set_DigestParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_get_EncryptionParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_set_EncryptionParamSet(TElGOST3410AlgorithmIdentifierHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3410AlgorithmIdentifier_Create(TElGOST3410AlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER
SB_IMPORT uint32_t SB_APIENTRY TElGOST3411WithGOST3410AlgorithmIdentifier_Assign(TElGOST3411WithGOST3410AlgorithmIdentifierHandle _Handle, TElAlgorithmIdentifierHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElGOST3411WithGOST3410AlgorithmIdentifier_Create(TElGOST3411WithGOST3410AlgorithmIdentifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAlgorithmIdentifier;
class TElRSAAlgorithmIdentifier;
class TElRSAPSSAlgorithmIdentifier;
class TElRSAOAEPAlgorithmIdentifier;
class TElDSAAlgorithmIdentifier;
class TElDHAlgorithmIdentifier;
class TElECAlgorithmIdentifier;
class TElECDSAAlgorithmIdentifier;
class TElGOST3411AlgorithmIdentifier;
class TElGOST3410AlgorithmIdentifier;
class TElGOST3411WithGOST3410AlgorithmIdentifier;

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
class TElAlgorithmIdentifier: public TObject
{
	private:
		SB_DISABLE_COPY(TElAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual TElAlgorithmIdentifierHandle Clone();

		virtual bool Equals(TElAlgorithmIdentifier &Algorithm);

		virtual bool Equals(TElAlgorithmIdentifier *Algorithm);

		static TElAlgorithmIdentifierHandle CreateFromBuffer(void * Buffer, int32_t Size);

		TElAlgorithmIdentifierHandle CreateFromBuffer_Inst(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		static TElAlgorithmIdentifierHandle CreateFromTag(TElASN1ConstrainedTag &Tag);

		static TElAlgorithmIdentifierHandle CreateFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		TElAlgorithmIdentifierHandle CreateFromTag_Inst(TElASN1ConstrainedTag &Tag);

		TElAlgorithmIdentifierHandle CreateFromTag_Inst(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		static TElAlgorithmIdentifierHandle CreateByAlgorithm(int32_t Algorithm);

		TElAlgorithmIdentifierHandle CreateByAlgorithm_Inst(int32_t Algorithm);

		static TElAlgorithmIdentifierHandle CreateByAlgorithmOID(const std::vector<uint8_t> &OID);

		TElAlgorithmIdentifierHandle CreateByAlgorithmOID_Inst(const std::vector<uint8_t> &OID);

		virtual bool IsAlgorithmSupported(int32_t Algorithm);

		virtual void LoadFromBuffer(void * Buffer, int32_t Size);

		virtual void SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		virtual void LoadFromTag(TElASN1ConstrainedTag &Tag);

		virtual void LoadFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		virtual void SaveToTag(TElASN1ConstrainedTag &Tag);

		virtual void SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual void WriteParameters(std::vector<uint8_t> &OutResult);

		virtual void get_AlgorithmOID(std::vector<uint8_t> &OutResult);

		virtual void set_AlgorithmOID(const std::vector<uint8_t> &Value);

		virtual int32_t get_Algorithm();

		virtual void set_Algorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Algorithm, set_Algorithm, TElAlgorithmIdentifier, Algorithm);

		virtual int32_t get_SignatureHashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureHashAlgorithm, TElAlgorithmIdentifier, SignatureHashAlgorithm);

		virtual bool get_IsSignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(bool, get_IsSignatureAlgorithm, TElAlgorithmIdentifier, IsSignatureAlgorithm);

		virtual bool get_IsPublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(bool, get_IsPublicKeyAlgorithm, TElAlgorithmIdentifier, IsPublicKeyAlgorithm);

		virtual bool get_IsEncryptionAlgorithm();

		SB_DECLARE_PROPERTY_GET(bool, get_IsEncryptionAlgorithm, TElAlgorithmIdentifier, IsEncryptionAlgorithm);

		virtual bool get_IsHashAlgorithm();

		SB_DECLARE_PROPERTY_GET(bool, get_IsHashAlgorithm, TElAlgorithmIdentifier, IsHashAlgorithm);

		TElAlgorithmIdentifier(TElAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER
class TElRSAAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElRSAAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElRSAAlgorithmIdentifier, HashAlgorithm);

		TElRSAAlgorithmIdentifier(TElRSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElRSAAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELRSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER
class TElRSAPSSAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElRSAPSSAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElRSAPSSAlgorithmIdentifier, HashAlgorithm);

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElRSAPSSAlgorithmIdentifier, SaltSize);

		virtual int32_t get_TrailerField();

		virtual void set_TrailerField(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrailerField, set_TrailerField, TElRSAPSSAlgorithmIdentifier, TrailerField);

		virtual int32_t get_MGF();

		virtual void set_MGF(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGF, set_MGF, TElRSAPSSAlgorithmIdentifier, MGF);

		virtual int32_t get_MGFHashAlgorithm();

		virtual void set_MGFHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGFHashAlgorithm, set_MGFHashAlgorithm, TElRSAPSSAlgorithmIdentifier, MGFHashAlgorithm);

		TElRSAPSSAlgorithmIdentifier(TElRSAPSSAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElRSAPSSAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELRSAPSSALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER
class TElRSAOAEPAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElRSAOAEPAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElRSAOAEPAlgorithmIdentifier, HashAlgorithm);

		virtual int32_t get_MGF();

		virtual void set_MGF(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGF, set_MGF, TElRSAOAEPAlgorithmIdentifier, MGF);

		virtual int32_t get_MGFHashAlgorithm();

		virtual void set_MGFHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGFHashAlgorithm, set_MGFHashAlgorithm, TElRSAOAEPAlgorithmIdentifier, MGFHashAlgorithm);

		virtual void get_StrLabel(std::string &OutResult);

		virtual void set_StrLabel(const std::string &Value);

		virtual bool get_WriteDefaults();

		virtual void set_WriteDefaults(bool Value);

		SB_DECLARE_PROPERTY(bool, get_WriteDefaults, set_WriteDefaults, TElRSAOAEPAlgorithmIdentifier, WriteDefaults);

		TElRSAOAEPAlgorithmIdentifier(TElRSAOAEPAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElRSAOAEPAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELRSAOAEPALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER
class TElDSAAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElDSAAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void set_Q(const std::vector<uint8_t> &Value);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void set_G(const std::vector<uint8_t> &Value);

		TElDSAAlgorithmIdentifier(TElDSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElDSAAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELDHALGORITHMIDENTIFIER
class TElDHAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElDHAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void set_Q(const std::vector<uint8_t> &Value);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void set_G(const std::vector<uint8_t> &Value);

		TElDHAlgorithmIdentifier(TElDHAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElDHAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELDHALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECALGORITHMIDENTIFIER
class TElECAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElECAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElECAlgorithmIdentifier, Version);

		virtual void get_Curve(std::vector<uint8_t> &OutResult);

		virtual void set_Curve(const std::vector<uint8_t> &Value);

		virtual void get_FieldID(std::vector<uint8_t> &OutResult);

		virtual void set_FieldID(const std::vector<uint8_t> &Value);

		virtual int32_t get_FieldType();

		virtual void set_FieldType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_FieldType, set_FieldType, TElECAlgorithmIdentifier, FieldType);

		virtual void get_Basis(std::vector<uint8_t> &OutResult);

		virtual void set_Basis(const std::vector<uint8_t> &Value);

		virtual int32_t get_M();

		virtual void set_M(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_M, set_M, TElECAlgorithmIdentifier, M);

		virtual int32_t get_K1();

		virtual void set_K1(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K1, set_K1, TElECAlgorithmIdentifier, K1);

		virtual int32_t get_K2();

		virtual void set_K2(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K2, set_K2, TElECAlgorithmIdentifier, K2);

		virtual int32_t get_K3();

		virtual void set_K3(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_K3, set_K3, TElECAlgorithmIdentifier, K3);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElECAlgorithmIdentifier, HashAlgorithm);

		virtual bool get_SpecifiedCurve();

		virtual void set_SpecifiedCurve(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SpecifiedCurve, set_SpecifiedCurve, TElECAlgorithmIdentifier, SpecifiedCurve);

		virtual bool get_CompressPoints();

		virtual void set_CompressPoints(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CompressPoints, set_CompressPoints, TElECAlgorithmIdentifier, CompressPoints);

		virtual bool get_HybridPoints();

		virtual void set_HybridPoints(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HybridPoints, set_HybridPoints, TElECAlgorithmIdentifier, HybridPoints);

		virtual bool get_ImplicitCurve();

		virtual void set_ImplicitCurve(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ImplicitCurve, set_ImplicitCurve, TElECAlgorithmIdentifier, ImplicitCurve);

		virtual void get_Seed(std::vector<uint8_t> &OutResult);

		virtual void set_Seed(const std::vector<uint8_t> &Value);

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void set_P(const std::vector<uint8_t> &Value);

		virtual void get_N(std::vector<uint8_t> &OutResult);

		virtual void set_N(const std::vector<uint8_t> &Value);

		virtual int32_t get_H();

		virtual void set_H(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_H, set_H, TElECAlgorithmIdentifier, H);

		virtual void get_A(std::vector<uint8_t> &OutResult);

		virtual void set_A(const std::vector<uint8_t> &Value);

		virtual void get_B(std::vector<uint8_t> &OutResult);

		virtual void set_B(const std::vector<uint8_t> &Value);

		virtual void get_X(std::vector<uint8_t> &OutResult);

		virtual void set_X(const std::vector<uint8_t> &Value);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void set_Y(const std::vector<uint8_t> &Value);

		virtual void get_Base(std::vector<uint8_t> &OutResult);

		virtual void set_Base(const std::vector<uint8_t> &Value);

		TElECAlgorithmIdentifier(TElECAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElECAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELECALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER
class TElECDSAAlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElECDSAAlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElECDSAAlgorithmIdentifier, HashAlgorithm);

		TElECDSAAlgorithmIdentifier(TElECDSAAlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElECDSAAlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELECDSAALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER
class TElGOST3411AlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElGOST3411AlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		TElGOST3411AlgorithmIdentifier(TElGOST3411AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElGOST3411AlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELGOST3411ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER
class TElGOST3410AlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElGOST3410AlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		virtual void get_PublicKeyParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_PublicKeyParamSet(const std::vector<uint8_t> &Value);

		virtual void get_DigestParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_DigestParamSet(const std::vector<uint8_t> &Value);

		virtual void get_EncryptionParamSet(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptionParamSet(const std::vector<uint8_t> &Value);

		TElGOST3410AlgorithmIdentifier(TElGOST3410AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElGOST3410AlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELGOST3410ALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER
class TElGOST3411WithGOST3410AlgorithmIdentifier: public TElAlgorithmIdentifier
{
	private:
		SB_DISABLE_COPY(TElGOST3411WithGOST3410AlgorithmIdentifier)
	public:
		virtual void Assign(TElAlgorithmIdentifier &Source);

		virtual void Assign(TElAlgorithmIdentifier *Source);

		TElGOST3411WithGOST3410AlgorithmIdentifier(TElGOST3411WithGOST3410AlgorithmIdentifierHandle handle, TElOwnHandle ownHandle);

		TElGOST3411WithGOST3410AlgorithmIdentifier();

};
#endif /* SB_USE_CLASS_TELGOST3411WITHGOST3410ALGORITHMIDENTIFIER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBALGORITHMIDENTIFIER */

