#ifndef __INC_SBCRYPTOPROVBUILTINPKI
#define __INC_SBCRYPTOPROVBUILTINPKI

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstreams.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovutils.h"
#include "sbcryptoprovbuiltin.h"
#include "sbcryptoprovbuiltinhash.h"
#include "sbcryptoprovrs.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbecdsa.h"
#include "sbeccommon.h"
#include "sbecmath.h"
#include "sbgostcommon.h"
#include "sbgost2814789.h"
#include "sbgost341094.h"
#include "sbgost341001.h"
#include "sbelgamal.h"
#include "sbmath.h"
#include "sbpkiasync.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbrdn.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElBuiltInRSACryptoKeyHandle;

typedef TElClassHandle TElBuiltInDSACryptoKeyHandle;

typedef TElClassHandle TElBuiltInElgamalCryptoKeyHandle;

typedef TElClassHandle TElBuiltInDHCryptoKeyHandle;

typedef TElClassHandle TElBuiltInECCryptoKeyHandle;

typedef TElClassHandle TElBuiltInGOST341094CryptoKeyHandle;

typedef TElClassHandle TElBuiltInGOST34102001CryptoKeyHandle;

typedef TElClassHandle TElBuiltInPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInRSAPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInDSAPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInElgamalPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInDHPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInECDSAPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInECDHPublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInGOST94PublicKeyCryptoHandle;

typedef TElClassHandle TElBuiltInGOST2001PublicKeyCryptoHandle;

typedef uint8_t TSBBuiltInRSACryptoKeyFormatRaw;

typedef enum
{
	rsaPKCS1 = 0,
	rsaOAEP = 1,
	rsaPSS = 2
} TSBBuiltInRSACryptoKeyFormat;

typedef uint8_t TSBBuiltInPublicKeyOperationRaw;

typedef enum
{
	pkoEncrypt = 0,
	pkoDecrypt = 1,
	pkoSign = 2,
	pkoSignDetached = 3,
	pkoVerify = 4,
	pkoVerifyDetached = 5
} TSBBuiltInPublicKeyOperation;

typedef TElClassHandle TElBuiltInPublicKeyCryptoClassHandle;

typedef uint8_t TSBBuiltInRSAPublicKeyCryptoTypeRaw;

typedef enum
{
	rsapktPKCS1 = 0,
	rsapktOAEP = 1,
	rsapktPSS = 2,
	rsapktSSL3 = 3
} TSBBuiltInRSAPublicKeyCryptoType;

#ifdef SB_USE_CLASS_TELBUILTINRSACRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_Reset(TElBuiltInRSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_Generate(TElBuiltInRSACryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ImportPublic(TElBuiltInRSACryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ImportSecret(TElBuiltInRSACryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ExportPublic(TElBuiltInRSACryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ExportSecret(TElBuiltInRSACryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_Clone(TElBuiltInRSACryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ClonePublic(TElBuiltInRSACryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ClearPublic(TElBuiltInRSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_ClearSecret(TElBuiltInRSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_GetKeyProp(TElBuiltInRSACryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_SetKeyProp(TElBuiltInRSACryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_Equals(TElBuiltInRSACryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSACryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInRSACryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINRSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDSACRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_Generate(TElBuiltInDSACryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_Reset(TElBuiltInDSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ImportPublic(TElBuiltInDSACryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ImportSecret(TElBuiltInDSACryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ExportPublic(TElBuiltInDSACryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ExportSecret(TElBuiltInDSACryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_Clone(TElBuiltInDSACryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ClonePublic(TElBuiltInDSACryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ClearPublic(TElBuiltInDSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_ClearSecret(TElBuiltInDSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_GetKeyProp(TElBuiltInDSACryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_SetKeyProp(TElBuiltInDSACryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_PrepareForSigning(TElBuiltInDSACryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_CancelPreparation(TElBuiltInDSACryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_AsyncOperationFinished(TElBuiltInDSACryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_Equals(TElBuiltInDSACryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSACryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInDSACryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINDSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_Generate(TElBuiltInElgamalCryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_Reset(TElBuiltInElgamalCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ImportPublic(TElBuiltInElgamalCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ImportSecret(TElBuiltInElgamalCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ExportPublic(TElBuiltInElgamalCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ExportSecret(TElBuiltInElgamalCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_Clone(TElBuiltInElgamalCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ClonePublic(TElBuiltInElgamalCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ClearPublic(TElBuiltInElgamalCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_ClearSecret(TElBuiltInElgamalCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_GetKeyProp(TElBuiltInElgamalCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_SetKeyProp(TElBuiltInElgamalCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_PrepareForEncryption(TElBuiltInElgamalCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_PrepareForSigning(TElBuiltInElgamalCryptoKeyHandle _Handle, int8_t MultiUse);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_CancelPreparation(TElBuiltInElgamalCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_AsyncOperationFinished(TElBuiltInElgamalCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_Equals(TElBuiltInElgamalCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInElgamalCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDHCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_Generate(TElBuiltInDHCryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_Reset(TElBuiltInDHCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ResetPartial(TElBuiltInDHCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ImportPublic(TElBuiltInDHCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ImportSecret(TElBuiltInDHCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ExportPublic(TElBuiltInDHCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ExportSecret(TElBuiltInDHCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_Clone(TElBuiltInDHCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ClonePublic(TElBuiltInDHCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ClearPublic(TElBuiltInDHCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_ClearSecret(TElBuiltInDHCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_GetKeyProp(TElBuiltInDHCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_SetKeyProp(TElBuiltInDHCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_Equals(TElBuiltInDHCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInDHCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINDHCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINECCRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_Reset(TElBuiltInECCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_Generate(TElBuiltInECCryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ImportPublic(TElBuiltInECCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ImportSecret(TElBuiltInECCryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ExportPublic(TElBuiltInECCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ExportSecret(TElBuiltInECCryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_Clone(TElBuiltInECCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ClonePublic(TElBuiltInECCryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ClearPublic(TElBuiltInECCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_ClearSecret(TElBuiltInECCryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_GetKeyProp(TElBuiltInECCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_SetKeyProp(TElBuiltInECCryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_AsyncOperationFinished(TElBuiltInECCryptoKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_Equals(TElBuiltInECCryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECCryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInECCryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINECCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_Generate(TElBuiltInGOST341094CryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_Reset(TElBuiltInGOST341094CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ImportPublic(TElBuiltInGOST341094CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ImportSecret(TElBuiltInGOST341094CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ExportPublic(TElBuiltInGOST341094CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ExportSecret(TElBuiltInGOST341094CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_Clone(TElBuiltInGOST341094CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ClonePublic(TElBuiltInGOST341094CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ClearPublic(TElBuiltInGOST341094CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_ClearSecret(TElBuiltInGOST341094CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_GetKeyProp(TElBuiltInGOST341094CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_SetKeyProp(TElBuiltInGOST341094CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_Equals(TElBuiltInGOST341094CryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST341094CryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInGOST341094CryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_Reset(TElBuiltInGOST34102001CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_Generate(TElBuiltInGOST34102001CryptoKeyHandle _Handle, int32_t Bits, TElRelativeDistinguishedNameHandle Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ImportPublic(TElBuiltInGOST34102001CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ImportSecret(TElBuiltInGOST34102001CryptoKeyHandle _Handle, void * Buffer, int32_t Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ExportPublic(TElBuiltInGOST34102001CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ExportSecret(TElBuiltInGOST34102001CryptoKeyHandle _Handle, void * Buffer, int32_t * Size, TElRelativeDistinguishedNameHandle Params);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_Clone(TElBuiltInGOST34102001CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ClonePublic(TElBuiltInGOST34102001CryptoKeyHandle _Handle, TElRelativeDistinguishedNameHandle Params, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ClearPublic(TElBuiltInGOST34102001CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_ClearSecret(TElBuiltInGOST34102001CryptoKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_Equals(TElBuiltInGOST34102001CryptoKeyHandle _Handle, TElCustomCryptoKeyHandle Source, int8_t PublicOnly, TElRelativeDistinguishedNameHandle Params, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_GetKeyProp(TElBuiltInGOST34102001CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pDefault[], int32_t szDefault, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_SetKeyProp(TElBuiltInGOST34102001CryptoKeyHandle _Handle, const uint8_t pPropID[], int32_t szPropID, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST34102001CryptoKey_Create(TElCustomCryptoProviderHandle CryptoProvider, TElBuiltInGOST34102001CryptoKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_SignInit(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_SignUpdate(TElBuiltInPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_SignFinal(TElBuiltInPublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_EncryptInit(TElBuiltInPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_EncryptUpdate(TElBuiltInPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_EncryptFinal(TElBuiltInPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_DecryptInit(TElBuiltInPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_DecryptUpdate(TElBuiltInPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_DecryptFinal(TElBuiltInPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_VerifyInit(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_VerifyUpdate(TElBuiltInPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_VerifyFinal(TElBuiltInPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Encrypt(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Encrypt_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Decrypt(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Decrypt_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Sign(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Sign_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_SignDetached(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_SignDetached_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Verify(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Verify_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_VerifyDetached(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_VerifyDetached_1(TElBuiltInPublicKeyCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle SigStream, int32_t InCount, int32_t SigCount, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_EstimateOutputSize(TElBuiltInPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_EstimateOutputSize_1(TElBuiltInPublicKeyCryptoHandle _Handle, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_get_KeyMaterial(TElBuiltInPublicKeyCryptoHandle _Handle, TElCustomCryptoKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_set_KeyMaterial(TElBuiltInPublicKeyCryptoHandle _Handle, TElCustomCryptoKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_get_SupportsEncryption(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_get_SupportsSigning(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_get_InputIsHash(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_set_InputIsHash(TElBuiltInPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInPublicKeyCrypto_Create_2(TElBuiltInPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_SignInit(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_SignUpdate(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_SignFinal(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_EncryptInit(TElBuiltInRSAPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_EncryptUpdate(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_EncryptFinal(TElBuiltInRSAPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_DecryptInit(TElBuiltInRSAPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_DecryptUpdate(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_DecryptFinal(TElBuiltInRSAPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_VerifyInit(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_VerifyUpdate(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_VerifyFinal(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_EstimateOutputSize(TElBuiltInRSAPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_CryptoType(TElBuiltInRSAPublicKeyCryptoHandle _Handle, TSBBuiltInRSAPublicKeyCryptoTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_CryptoType(TElBuiltInRSAPublicKeyCryptoHandle _Handle, TSBBuiltInRSAPublicKeyCryptoTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_UseAlgorithmPrefix(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_UseAlgorithmPrefix(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_HashFuncOID(TElBuiltInRSAPublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_HashFuncOID(TElBuiltInRSAPublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_HashAlgorithm(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_HashAlgorithm(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_SaltSize(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_SaltSize(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_MGFAlgorithm(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_MGFAlgorithm(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_TrailerField(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_TrailerField(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_get_AutoVerifyCreatedSignatures(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_set_AutoVerifyCreatedSignatures(TElBuiltInRSAPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInRSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInRSAPublicKeyCrypto_Create_2(TElBuiltInRSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_EncodeSignature(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t * SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_DecodeSignature(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * Sig, int32_t SigSize, void * R, int32_t * RSize, void * S, int32_t * SSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_SignInit(TElBuiltInDSAPublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_SignUpdate(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_SignFinal(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_VerifyInit(TElBuiltInDSAPublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_VerifyUpdate(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_VerifyFinal(TElBuiltInDSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_EstimateOutputSize(TElBuiltInDSAPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDSAPublicKeyCrypto_Create_2(TElBuiltInDSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_SignInit(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_SignUpdate(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_SignFinal(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_EncryptInit(TElBuiltInElgamalPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_EncryptUpdate(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_EncryptFinal(TElBuiltInElgamalPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_DecryptInit(TElBuiltInElgamalPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_DecryptUpdate(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_DecryptFinal(TElBuiltInElgamalPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_VerifyInit(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_VerifyUpdate(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_VerifyFinal(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_EstimateOutputSize(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_get_HashAlgorithm(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_set_HashAlgorithm(TElBuiltInElgamalPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInElgamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInElgamalPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInElgamalPublicKeyCrypto_Create_2(TElBuiltInElgamalPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_EncryptInit(TElBuiltInDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_EncryptUpdate(TElBuiltInDHPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_EncryptFinal(TElBuiltInDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_DecryptInit(TElBuiltInDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_DecryptUpdate(TElBuiltInDHPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_DecryptFinal(TElBuiltInDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_EstimateOutputSize(TElBuiltInDHPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInDHPublicKeyCrypto_Create_2(TElBuiltInDHPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_EncodeSignature(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t * SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_DecodeSignature(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * Sig, int32_t SigSize, void * R, int32_t * RSize, void * S, int32_t * SSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_SignInit(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_SignUpdate(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_SignFinal(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_VerifyInit(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_VerifyUpdate(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_VerifyFinal(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_EstimateOutputSize(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_get_HashAlgorithm(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_set_HashAlgorithm(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_get_PlainECDSA(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_set_PlainECDSA(TElBuiltInECDSAPublicKeyCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInECDSAPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDSAPublicKeyCrypto_Create_2(TElBuiltInECDSAPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_EncryptInit(TElBuiltInECDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_EncryptUpdate(TElBuiltInECDHPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_EncryptFinal(TElBuiltInECDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_DecryptInit(TElBuiltInECDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_DecryptUpdate(TElBuiltInECDHPublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_DecryptFinal(TElBuiltInECDHPublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_EstimateOutputSize(TElBuiltInECDHPublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInECDHPublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInECDHPublicKeyCrypto_Create_2(TElBuiltInECDHPublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_SignInit(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_SignUpdate(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_SignFinal(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_VerifyInit(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_VerifyUpdate(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_VerifyFinal(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_EstimateOutputSize(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_get_HashAlgorithm(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_set_HashAlgorithm(TElBuiltInGOST94PublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInGOST94PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST94PublicKeyCrypto_Create_2(TElBuiltInGOST94PublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_EncryptInit(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_EncryptUpdate(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_EncryptFinal(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_DecryptInit(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_DecryptUpdate(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_DecryptFinal(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_SignInit(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, int8_t Detached);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_SignUpdate(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_SignFinal(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * Buffer, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_VerifyInit(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, int8_t Detached, void * Signature, int32_t SigSize);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_VerifyUpdate(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_VerifyFinal(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_EstimateOutputSize(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperationRaw Operation, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_get_HashAlgorithm(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_set_HashAlgorithm(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_get_UKM(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_set_UKM(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_get_CEKMAC(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_set_CEKMAC(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_get_EphemeralKey(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_set_EphemeralKey(TElBuiltInGOST2001PublicKeyCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_Create(const uint8_t pOID[], int32_t szOID, TElBuiltInGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_Create_1(int32_t Alg, TElBuiltInGOST2001PublicKeyCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElBuiltInGOST2001PublicKeyCrypto_Create_2(TElBuiltInGOST2001PublicKeyCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElBuiltInRSACryptoKey;
class TElBuiltInDSACryptoKey;
class TElBuiltInElgamalCryptoKey;
class TElBuiltInDHCryptoKey;
class TElBuiltInECCryptoKey;
class TElBuiltInGOST341094CryptoKey;
class TElBuiltInGOST34102001CryptoKey;
class TElBuiltInPublicKeyCrypto;
class TElBuiltInRSAPublicKeyCrypto;
class TElBuiltInDSAPublicKeyCrypto;
class TElBuiltInElgamalPublicKeyCrypto;
class TElBuiltInDHPublicKeyCrypto;
class TElBuiltInECDSAPublicKeyCrypto;
class TElBuiltInECDHPublicKeyCrypto;
class TElBuiltInGOST94PublicKeyCrypto;
class TElBuiltInGOST2001PublicKeyCrypto;

#ifdef SB_USE_CLASS_TELBUILTINRSACRYPTOKEY
class TElBuiltInRSACryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInRSACryptoKey)
	public:
		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInRSACryptoKey(TElBuiltInRSACryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInRSACryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInRSACryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINRSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDSACRYPTOKEY
class TElBuiltInDSACryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInDSACryptoKey)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInDSACryptoKey(TElBuiltInDSACryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInDSACryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInDSACryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINDSACRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY
class TElBuiltInElgamalCryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInElgamalCryptoKey)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		virtual void PrepareForEncryption(bool MultiUse);

		virtual void PrepareForSigning(bool MultiUse);

		virtual void CancelPreparation();

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInElgamalCryptoKey(TElBuiltInElgamalCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInElgamalCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInElgamalCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINELGAMALCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINDHCRYPTOKEY
class TElBuiltInDHCryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInDHCryptoKey)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Reset();

		void ResetPartial();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInDHCryptoKey(TElBuiltInDHCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInDHCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInDHCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINDHCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINECCRYPTOKEY
class TElBuiltInECCryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInECCryptoKey)
	public:
		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		virtual bool AsyncOperationFinished();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInECCryptoKey(TElBuiltInECCryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInECCryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInECCryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINECCRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY
class TElBuiltInGOST341094CryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInGOST341094CryptoKey)
	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElBuiltInGOST341094CryptoKey(TElBuiltInGOST341094CryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInGOST341094CryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInGOST341094CryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINGOST341094CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY
class TElBuiltInGOST34102001CryptoKey: public TElBuiltInCryptoKey
{
	private:
		SB_DISABLE_COPY(TElBuiltInGOST34102001CryptoKey)
	public:
		virtual void Reset();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName &Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);

		virtual void Generate(int32_t Bits, TElRelativeDistinguishedName *Params, TSBProgressFunc pMethodProgressFunc, void * pDataProgressFunc, void * ProgressData);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportPublic(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName &Params);

		virtual void ImportSecret(void * Buffer, int32_t Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportPublic(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName &Params);

		virtual void ExportSecret(void * Buffer, int32_t &Size, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle Clone(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName &Params);

		virtual TElCustomCryptoKeyHandle ClonePublic(TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void ClearPublic();

		virtual void ClearSecret();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual bool Equals(TElCustomCryptoKey &Source, bool PublicOnly, TElRelativeDistinguishedName &Params);

		virtual bool Equals(TElCustomCryptoKey *Source, bool PublicOnly, TElRelativeDistinguishedName *Params);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void GetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Default, std::vector<uint8_t> &OutResult);

		virtual void SetKeyProp(const std::vector<uint8_t> &PropID, const std::vector<uint8_t> &Value);

		TElBuiltInGOST34102001CryptoKey(TElBuiltInGOST34102001CryptoKeyHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElBuiltInGOST34102001CryptoKey(TElCustomCryptoProvider &CryptoProvider);

		explicit TElBuiltInGOST34102001CryptoKey(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

};
#endif /* SB_USE_CLASS_TELBUILTINGOST34102001CRYPTOKEY */

#ifdef SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO
class TElBuiltInPublicKeyCrypto: public TObject
{
	private:
		SB_DISABLE_COPY(TElBuiltInPublicKeyCrypto)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		TElCustomCryptoKey* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		void initInstances();

	public:
		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void Encrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Decrypt(TStream &InStream, TStream &OutStream, int32_t Count);

		void Decrypt(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Sign(TStream &InStream, TStream &OutStream, int32_t Count);

		void Sign(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void SignDetached(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void SignDetached(TStream &InStream, TStream &OutStream, int32_t Count);

		void SignDetached(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t Verify(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t Verify(TStream &InStream, TStream &OutStream, int32_t Count);

		int32_t Verify(TStream *InStream, TStream *OutStream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t VerifyDetached(void * InBuffer, int32_t InSize, void * SigBuffer, int32_t SigSize);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t VerifyDetached(TStream &InStream, TStream &SigStream, int32_t InCount, int32_t SigCount);

		int32_t VerifyDetached(TStream *InStream, TStream *SigStream, int32_t InCount, int32_t SigCount);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		virtual int64_t EstimateOutputSize(int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOKEY
		virtual TElCustomCryptoKey* get_KeyMaterial();

		virtual void set_KeyMaterial(TElCustomCryptoKey &Value);

		virtual void set_KeyMaterial(TElCustomCryptoKey *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoKey*, get_KeyMaterial, set_KeyMaterial, TElBuiltInPublicKeyCrypto, KeyMaterial);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOKEY */

		virtual bool get_SupportsEncryption();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsEncryption, TElBuiltInPublicKeyCrypto, SupportsEncryption);

		virtual bool get_SupportsSigning();

		SB_DECLARE_PROPERTY_GET(bool, get_SupportsSigning, TElBuiltInPublicKeyCrypto, SupportsSigning);

		virtual bool get_InputIsHash();

		virtual void set_InputIsHash(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InputIsHash, set_InputIsHash, TElBuiltInPublicKeyCrypto, InputIsHash);

		TElBuiltInPublicKeyCrypto(TElBuiltInPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInPublicKeyCrypto(int32_t Alg);

		TElBuiltInPublicKeyCrypto();

		virtual ~TElBuiltInPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO
class TElBuiltInRSAPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInRSAPublicKeyCrypto)
	public:
		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		virtual TSBBuiltInRSAPublicKeyCryptoType get_CryptoType();

		virtual void set_CryptoType(TSBBuiltInRSAPublicKeyCryptoType Value);

		SB_DECLARE_PROPERTY(TSBBuiltInRSAPublicKeyCryptoType, get_CryptoType, set_CryptoType, TElBuiltInRSAPublicKeyCrypto, CryptoType);

		virtual bool get_UseAlgorithmPrefix();

		virtual void set_UseAlgorithmPrefix(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseAlgorithmPrefix, set_UseAlgorithmPrefix, TElBuiltInRSAPublicKeyCrypto, UseAlgorithmPrefix);

		virtual void get_HashFuncOID(std::vector<uint8_t> &OutResult);

		virtual void set_HashFuncOID(const std::vector<uint8_t> &Value);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElBuiltInRSAPublicKeyCrypto, HashAlgorithm);

		virtual int32_t get_SaltSize();

		virtual void set_SaltSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltSize, set_SaltSize, TElBuiltInRSAPublicKeyCrypto, SaltSize);

		virtual int32_t get_MGFAlgorithm();

		virtual void set_MGFAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MGFAlgorithm, set_MGFAlgorithm, TElBuiltInRSAPublicKeyCrypto, MGFAlgorithm);

		virtual int32_t get_TrailerField();

		virtual void set_TrailerField(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrailerField, set_TrailerField, TElBuiltInRSAPublicKeyCrypto, TrailerField);

		virtual bool get_AutoVerifyCreatedSignatures();

		virtual void set_AutoVerifyCreatedSignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoVerifyCreatedSignatures, set_AutoVerifyCreatedSignatures, TElBuiltInRSAPublicKeyCrypto, AutoVerifyCreatedSignatures);

		TElBuiltInRSAPublicKeyCrypto(TElBuiltInRSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInRSAPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInRSAPublicKeyCrypto(int32_t Alg);

		TElBuiltInRSAPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINRSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO
class TElBuiltInDSAPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInDSAPublicKeyCrypto)
	public:
		void EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize);

		void DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		TElBuiltInDSAPublicKeyCrypto(TElBuiltInDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInDSAPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInDSAPublicKeyCrypto(int32_t Alg);

		TElBuiltInDSAPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO
class TElBuiltInElgamalPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInElgamalPublicKeyCrypto)
	public:
		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElBuiltInElgamalPublicKeyCrypto, HashAlgorithm);

		TElBuiltInElgamalPublicKeyCrypto(TElBuiltInElgamalPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInElgamalPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInElgamalPublicKeyCrypto(int32_t Alg);

		TElBuiltInElgamalPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINELGAMALPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO
class TElBuiltInDHPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInDHPublicKeyCrypto)
	public:
		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		TElBuiltInDHPublicKeyCrypto(TElBuiltInDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInDHPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInDHPublicKeyCrypto(int32_t Alg);

		TElBuiltInDHPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO
class TElBuiltInECDSAPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInECDSAPublicKeyCrypto)
	public:
		void EncodeSignature(void * R, int32_t RSize, void * S, int32_t SSize, void * Sig, int32_t &SigSize);

		void DecodeSignature(void * Sig, int32_t SigSize, void * R, int32_t &RSize, void * S, int32_t &SSize);

		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElBuiltInECDSAPublicKeyCrypto, HashAlgorithm);

		virtual bool get_PlainECDSA();

		virtual void set_PlainECDSA(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PlainECDSA, set_PlainECDSA, TElBuiltInECDSAPublicKeyCrypto, PlainECDSA);

		TElBuiltInECDSAPublicKeyCrypto(TElBuiltInECDSAPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInECDSAPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInECDSAPublicKeyCrypto(int32_t Alg);

		TElBuiltInECDSAPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINECDSAPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO
class TElBuiltInECDHPublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInECDHPublicKeyCrypto)
	public:
		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		TElBuiltInECDHPublicKeyCrypto(TElBuiltInECDHPublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInECDHPublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInECDHPublicKeyCrypto(int32_t Alg);

		TElBuiltInECDHPublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINECDHPUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO
class TElBuiltInGOST94PublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInGOST94PublicKeyCrypto)
	public:
		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElBuiltInGOST94PublicKeyCrypto, HashAlgorithm);

		TElBuiltInGOST94PublicKeyCrypto(TElBuiltInGOST94PublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInGOST94PublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInGOST94PublicKeyCrypto(int32_t Alg);

		TElBuiltInGOST94PublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINGOST94PUBLICKEYCRYPTO */

#ifdef SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO
class TElBuiltInGOST2001PublicKeyCrypto: public TElBuiltInPublicKeyCrypto
{
	private:
		SB_DISABLE_COPY(TElBuiltInGOST2001PublicKeyCrypto)
	public:
		virtual void EncryptInit();

		virtual void EncryptUpdate(void * Buffer, int32_t Size);

		virtual void EncryptFinal();

		virtual void DecryptInit();

		virtual void DecryptUpdate(void * Buffer, int32_t Size);

		virtual void DecryptFinal();

		virtual void SignInit(bool Detached);

		virtual void SignUpdate(void * Buffer, int32_t Size);

		virtual void SignFinal(void * Buffer, int32_t &Size);

		virtual void VerifyInit(bool Detached, void * Signature, int32_t SigSize);

		virtual void VerifyUpdate(void * Buffer, int32_t Size);

		virtual int32_t VerifyFinal();

		virtual int64_t EstimateOutputSize(void * InBuffer, int64_t InSize, TSBBuiltInPublicKeyOperation Operation);

		static TClassHandle ClassType();

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElBuiltInGOST2001PublicKeyCrypto, HashAlgorithm);

		virtual void get_UKM(std::vector<uint8_t> &OutResult);

		virtual void set_UKM(const std::vector<uint8_t> &Value);

		virtual void get_CEKMAC(std::vector<uint8_t> &OutResult);

		virtual void set_CEKMAC(const std::vector<uint8_t> &Value);

		virtual void get_EphemeralKey(std::vector<uint8_t> &OutResult);

		virtual void set_EphemeralKey(const std::vector<uint8_t> &Value);

		TElBuiltInGOST2001PublicKeyCrypto(TElBuiltInGOST2001PublicKeyCryptoHandle handle, TElOwnHandle ownHandle);

		explicit TElBuiltInGOST2001PublicKeyCrypto(const std::vector<uint8_t> &OID);

		explicit TElBuiltInGOST2001PublicKeyCrypto(int32_t Alg);

		TElBuiltInGOST2001PublicKeyCrypto();

};
#endif /* SB_USE_CLASS_TELBUILTINGOST2001PUBLICKEYCRYPTO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBCRYPTOPROVBUILTINPKI */

