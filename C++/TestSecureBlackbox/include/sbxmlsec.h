#ifndef __INC_SBXMLSEC
#define __INC_SBXMLSEC

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbpgpkeys.h"
#include "sbpgputils.h"
#include "sbcryptoprov.h"
#include "sbcustomcertstorage.h"
#include "sbhashfunction.h"
#include "sbpublickeycrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbstreams.h"
#include "sbrandom.h"
#include "sbxmldefs.h"
#include "sbxmlcore.h"
#include "sbxmltransform.h"
#include "sbxmlutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SXMLReferenceNoContext 	"Reference requires a context"
#define SB_SXMLUnsupportedECFieldType 	"Unsupported EC field type"

typedef TElClassHandle TElXMLKeyInfoHandle;

typedef TElXMLKeyInfoHandle ElXMLKeyInfoHandle;

typedef TElClassHandle TElXMLAlgorithmParametersHandle;

typedef TElXMLAlgorithmParametersHandle ElXMLAlgorithmParametersHandle;

typedef TElClassHandle TElXMLReferenceHandle;

typedef TElXMLReferenceHandle ElXMLReferenceHandle;

typedef TElClassHandle TElXMLReferenceListHandle;

typedef TElXMLReferenceListHandle ElXMLReferenceListHandle;

typedef TElClassHandle TElXMLGOSTR3411ParametersHandle;

typedef TElClassHandle TElXMLRSAPSSParametersHandle;

typedef TElClassHandle TElXMLKeyInfoItemHandle;

typedef TElXMLKeyInfoItemHandle ElXMLKeyInfoItemHandle;

typedef TElClassHandle TElXMLKeyInfoDataHandle;

typedef TElXMLKeyInfoDataHandle ElXMLKeyInfoDataHandle;

typedef TElClassHandle TElXMLKeyInfoHMACDataHandle;

typedef TElXMLKeyInfoHMACDataHandle ElXMLKeyInfoHMACDataHandle;

typedef TElClassHandle TElXMLKeyInfoSymmetricDataHandle;

typedef TElXMLKeyInfoSymmetricDataHandle ElXMLKeyInfoSymmetricDataHandle;

typedef TElClassHandle TElXMLKeyInfoAsymmetricDataHandle;

typedef TElXMLKeyInfoAsymmetricDataHandle ElXMLKeyInfoAsymmetricDataHandle;

typedef TElClassHandle TElXMLKeyInfoRSADataHandle;

typedef TElXMLKeyInfoRSADataHandle ElXMLKeyInfoRSADataHandle;

typedef TElClassHandle TElXMLKeyInfoDSADataHandle;

typedef TElXMLKeyInfoDSADataHandle ElXMLKeyInfoDSADataHandle;

typedef TElClassHandle TElXMLKeyInfoDHDataHandle;

typedef TElXMLKeyInfoDHDataHandle ElXMLKeyInfoDHDataHandle;

typedef TElClassHandle TElXMLKeyInfoGOST2001DataHandle;

typedef TElClassHandle TElXMLKeyInfoPGPDataHandle;

typedef TElXMLKeyInfoPGPDataHandle ElXMLKeyInfoPGPDataHandle;

typedef TElClassHandle TElXMLKeyInfoECDataHandle;

typedef TElClassHandle TElXMLIssuerSerialHandle;

typedef TElXMLIssuerSerialHandle ElXMLIssuerSerialHandle;

typedef TElClassHandle TElXMLKeyInfoX509DataHandle;

typedef TElXMLKeyInfoX509DataHandle ElXMLKeyInfoX509DataHandle;

typedef TElClassHandle TElXMLKeyInfoNodeHandle;

typedef TElXMLKeyInfoNodeHandle ElXMLKeyInfoNodeHandle;

typedef TElClassHandle TElXMLKeyInfoRetrievalMethodHandle;

typedef TElXMLKeyInfoRetrievalMethodHandle ElXMLKeyInfoRetrievalMethodHandle;

typedef TElClassHandle TElXMLKeyInfoAgreementMethodHandle;

typedef TElXMLKeyInfoAgreementMethodHandle ElXMLKeyInfoAgreementMethodHandle;

typedef TElClassHandle TElXMLPropertyHandle;

typedef TElXMLPropertyHandle ElXMLPropertyHandle;

typedef TElClassHandle TElXMLPropertiesHandle;

typedef TElXMLPropertiesHandle ElXMLPropertiesHandle;

typedef TElClassHandle TElXMLProcessorHandle;

typedef TElXMLProcessorHandle ElXMLProcessorHandle;

typedef TElClassHandle TElXMLFormatterHandle;

typedef TElXMLFormatterHandle ElXMLFormatterHandle;

typedef TElClassHandle TElXMLDescriptorMapHandle;

typedef uint8_t TElXMLSignatureTypeRaw;

typedef enum
{
	xstDetached = 0,
	xstEnveloping = 1,
	xstEnveloped = 2
} TElXMLSignatureType;

typedef uint32_t TElXMLSignatureTypesRaw;

typedef enum 
{
	f_xstDetached = 1,
	f_xstEnveloping = 2,
	f_xstEnveloped = 4
} TElXMLSignatureTypes;

typedef uint8_t TElXMLSignatureComplianceRaw;

typedef enum
{
	xscDSIG = 0,
	xscEBICS = 1
} TElXMLSignatureCompliance;

typedef uint8_t TElXMLSigMethodTypeRaw;

typedef enum
{
	xmtSig = 0,
	xmtMAC = 1
} TElXMLSigMethodType;

typedef uint8_t TElXMLDigestMethodRaw;

typedef enum
{
	xdmMD5 = 0,
	xdmSHA1 = 1,
	xdmSHA224 = 2,
	xdmSHA256 = 3,
	xdmSHA384 = 4,
	xdmSHA512 = 5,
	xdmRIPEMD160 = 6,
	xdmGOST = 7,
	xdmWhirlpool = 8
} TElXMLDigestMethod;

typedef uint8_t TElXMLMACMethodRaw;

typedef enum
{
	xmmHMAC_MD5 = 0,
	xmmHMAC_SHA1 = 1,
	xmmHMAC_SHA224 = 2,
	xmmHMAC_SHA256 = 3,
	xmmHMAC_SHA384 = 4,
	xmmHMAC_SHA512 = 5,
	xmmHMAC_RIPEMD160 = 6
} TElXMLMACMethod;

typedef uint8_t TElXMLSignatureMethodRaw;

typedef enum
{
	xsmDSS = 0,
	xsmRSA_MD5 = 1,
	xsmRSA_SHA1 = 2,
	xsmRSA_SHA256 = 3,
	xsmRSA_SHA384 = 4,
	xsmRSA_SHA512 = 5,
	xsmRSA_RIPEMD160 = 6,
	xsmECDSA_SHA1 = 7,
	xsmGOST1994 = 8,
	xsmGOST2001 = 9,
	xsmRSA_SHA224 = 10,
	xsmRSA_Whirlpool = 11,
	xsmDSA_SHA256 = 12,
	xsmECDSA_SHA224 = 13,
	xsmECDSA_SHA256 = 14,
	xsmECDSA_SHA384 = 15,
	xsmECDSA_SHA512 = 16,
	xsmECDSA_RIPEMD160 = 17,
	xsmECDSA_Whirlpool = 18,
	xsmRSA_PSS = 19,
	xsmRSA_PSS_MD5_MGF1 = 20,
	xsmRSA_PSS_SHA1_MGF1 = 21,
	xsmRSA_PSS_SHA224_MGF1 = 22,
	xsmRSA_PSS_SHA256_MGF1 = 23,
	xsmRSA_PSS_SHA384_MGF1 = 24,
	xsmRSA_PSS_SHA512_MGF1 = 25,
	xsmRSA_PSS_RIPEMD160_MGF1 = 26,
	xsmRSA_PSS_Whirlpool_MGF1 = 27
} TElXMLSignatureMethod;

typedef uint8_t TElXMLKeyInfoX509DataParamRaw;

typedef enum
{
	xkidX509IssuerSerial = 0,
	xkidX509SKI = 1,
	xkidX509SubjectName = 2,
	xkidX509Certificate = 3,
	xkidX509CRL = 4
} TElXMLKeyInfoX509DataParam;

typedef uint32_t TElXMLKeyInfoX509DataParamsRaw;

typedef enum 
{
	f_xkidX509IssuerSerial = 1,
	f_xkidX509SKI = 2,
	f_xkidX509SubjectName = 4,
	f_xkidX509Certificate = 8,
	f_xkidX509CRL = 16
} TElXMLKeyInfoX509DataParams;

typedef uint8_t TElXMLKeyInfoPGPDataParamRaw;

typedef enum
{
	xkidPGPKeyID = 0,
	xkidPGPKeyPacket = 1
} TElXMLKeyInfoPGPDataParam;

typedef uint8_t TElXMLEncryptedDataTypeRaw;

typedef enum
{
	xedtElement = 0,
	xedtContent = 1,
	xedtExternal = 2
} TElXMLEncryptedDataType;

typedef uint8_t TElXMLEncryptionMethodRaw;

typedef enum
{
	xem3DES = 0,
	xemAES = 1,
	xemCamellia = 2,
	xemDES = 3,
	xemRC4 = 4,
	xemSEED = 5,
	xemAES_GCM = 6
} TElXMLEncryptionMethod;

typedef uint8_t TElXMLKeyEncryptionTypeRaw;

typedef enum
{
	xetKeyTransport = 0,
	xetKeyWrap = 1
} TElXMLKeyEncryptionType;

typedef uint8_t TElXMLKeyTransportMethodRaw;

typedef enum
{
	xktRSA15 = 0,
	xktRSAOAEP = 1
} TElXMLKeyTransportMethod;

typedef uint8_t TElXMLKeyWrapMethodRaw;

typedef enum
{
	xwm3DES = 0,
	xwmAES128 = 1,
	xwmAES192 = 2,
	xwmAES256 = 3,
	xwmCamellia128 = 4,
	xwmCamellia192 = 5,
	xwmCamellia256 = 6,
	xwmSEED = 7
} TElXMLKeyWrapMethod;

typedef uint8_t TSBXMLECKeyValueFormatRaw;

typedef enum
{
	xekfRFC4050 = 0,
	xekfDSIG11 = 1
} TSBXMLECKeyValueFormat;

typedef uint8_t TSBXMLECPrimeNumberTypeRaw;

typedef enum
{
	xeptInteger = 0,
	xeptHex = 1
} TSBXMLECPrimeNumberType;

typedef void (SB_CALLBACK *TSBXMLFormatElementEvent)(void * _ObjectData, TObjectHandle Sender, TElXMLDOMElementHandle Element, int32_t Level, const sb_char16_t * pcPath, int32_t szPath, sb_char16_t * pcStartTagWhitespace, int32_t * szStartTagWhitespace, sb_char16_t * pcEndTagWhitespace, int32_t * szEndTagWhitespace);

typedef void (SB_CALLBACK *TSBXMLFormatTextEvent)(void * _ObjectData, TObjectHandle Sender, sb_char16_t * pcText, int32_t * szText, TElXMLTextTypeRaw TextType, int32_t Level, const sb_char16_t * pcPath, int32_t szPath);

typedef uint8_t TElXMLRDNCompatibilityModeRaw;

typedef enum
{
	cmRFC = 0,
	cmDotNET = 1,
	cmCustom = 2
} TElXMLRDNCompatibilityMode;

#ifdef SB_USE_CLASS_TELXMLKEYINFO
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Add(TElXMLKeyInfoHandle _Handle, TElXMLKeyInfoItemHandle Item, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Insert(TElXMLKeyInfoHandle _Handle, int32_t Index, TElXMLKeyInfoItemHandle Item);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Delete(TElXMLKeyInfoHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Clear(TElXMLKeyInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_IsEmpty(TElXMLKeyInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_LoadFromXML(TElXMLKeyInfoHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_SaveToXML(TElXMLKeyInfoHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_ExtractAllCertificates(TElXMLKeyInfoHandle _Handle, TElCustomCertStorageHandle Storage);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_SetKeyData(TElXMLKeyInfoHandle _Handle, const TElXMLKeyInfoDataHandle KeyData);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_get_Count(TElXMLKeyInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_get_Items(TElXMLKeyInfoHandle _Handle, int32_t Index, TElXMLKeyInfoItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_get_CryptoProviderManager(TElXMLKeyInfoHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_set_CryptoProviderManager(TElXMLKeyInfoHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_get_KeyName(TElXMLKeyInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_set_KeyName(TElXMLKeyInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_get_ID(TElXMLKeyInfoHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_set_ID(TElXMLKeyInfoHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Create(TElXMLKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfo_Create_1(const sb_char16_t * pcAKeyName, int32_t szAKeyName, TElXMLKeyInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
SB_IMPORT uint32_t SB_APIENTRY TElXMLAlgorithmParameters_Clone(TElXMLAlgorithmParametersHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAlgorithmParameters_GetCryptoProviderParameters(TElXMLAlgorithmParametersHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLAlgorithmParameters_Create(TElXMLCustomElementHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_UpdateDigestValue(TElXMLReferenceHandle _Handle, int32_t Mode);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_UpdateDigestValue_1(TElXMLReferenceHandle _Handle, int32_t Mode, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_UpdateDigestValue_2(TElXMLReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_UpdateDigestValue_3(TElXMLReferenceHandle _Handle, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_Clone(TElXMLReferenceHandle _Handle, TElXMLReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_Clear(TElXMLReferenceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_LoadFromXML(TElXMLReferenceHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_SaveToXML(TElXMLReferenceHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_IsURIResolved(TElXMLReferenceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_ProcessData(TElXMLReferenceHandle _Handle, TElHashFunctionHandle HashFunc);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_ProcessData_1(TElXMLReferenceHandle _Handle, TElHashFunctionHandle HashFunc, TElXMLCanonicalizationMethodRaw CanonicalizationMethod);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_TransformChain(TElXMLReferenceHandle _Handle, TElXMLTransformChainHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_DigestMethod(TElXMLReferenceHandle _Handle, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_DigestMethod(TElXMLReferenceHandle _Handle, TElXMLDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_DigestValue(TElXMLReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_DigestValue(TElXMLReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_DigestMethodParameters(TElXMLReferenceHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_ID(TElXMLReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_ID(TElXMLReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URI(TElXMLReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URI(TElXMLReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_RefType(TElXMLReferenceHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_RefType(TElXMLReferenceHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_HasURI(TElXMLReferenceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_HasURI(TElXMLReferenceHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URIData(TElXMLReferenceHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URIData(TElXMLReferenceHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URINode(TElXMLReferenceHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URINode(TElXMLReferenceHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URINodes(TElXMLReferenceHandle _Handle, TElXMLNodeSetHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URINodes(TElXMLReferenceHandle _Handle, TElXMLNodeSetHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URIStream(TElXMLReferenceHandle _Handle, TStreamHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URIStream(TElXMLReferenceHandle _Handle, TStreamHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URIStreamOffset(TElXMLReferenceHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URIStreamOffset(TElXMLReferenceHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_get_URIStreamCount(TElXMLReferenceHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_set_URIStreamCount(TElXMLReferenceHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReference_Create(TElXMLReferenceHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Add(TElXMLReferenceListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Add_1(TElXMLReferenceListHandle _Handle, TElXMLReferenceHandle AReference, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Insert(TElXMLReferenceListHandle _Handle, int32_t Index, TElXMLReferenceHandle AReference);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Delete(TElXMLReferenceListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Clear(TElXMLReferenceListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_IndexOf(TElXMLReferenceListHandle _Handle, TElXMLReferenceHandle AReference, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_get_Count(TElXMLReferenceListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_get_Reference(TElXMLReferenceListHandle _Handle, int32_t Index, TElXMLReferenceHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLReferenceList_Create(TElXMLReferenceListHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_Clear(TElXMLGOSTR3411ParametersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_Clone(TElXMLGOSTR3411ParametersHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_LoadFromXML(TElXMLGOSTR3411ParametersHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_SaveToXML(TElXMLGOSTR3411ParametersHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_GetCryptoProviderParameters(TElXMLGOSTR3411ParametersHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_get_DigestParameter(TElXMLGOSTR3411ParametersHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_set_DigestParameter(TElXMLGOSTR3411ParametersHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLGOSTR3411Parameters_Create(TElXMLGOSTR3411ParametersHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS */

#ifdef SB_USE_CLASS_TELXMLRSAPSSPARAMETERS
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_Clear(TElXMLRSAPSSParametersHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_Clone(TElXMLRSAPSSParametersHandle _Handle, TElXMLAlgorithmParametersHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_LoadFromXML(TElXMLRSAPSSParametersHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_SaveToXML(TElXMLRSAPSSParametersHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_GetCryptoProviderParameters(TElXMLRSAPSSParametersHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_get_DigestMethod(TElXMLRSAPSSParametersHandle _Handle, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_set_DigestMethod(TElXMLRSAPSSParametersHandle _Handle, TElXMLDigestMethodRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_get_MaskGenerationFunction(TElXMLRSAPSSParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_set_MaskGenerationFunction(TElXMLRSAPSSParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_get_SaltLength(TElXMLRSAPSSParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_set_SaltLength(TElXMLRSAPSSParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_get_TrailerField(TElXMLRSAPSSParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_set_TrailerField(TElXMLRSAPSSParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLRSAPSSParameters_Create(TElXMLRSAPSSParametersHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLRSAPSSPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoItem_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoData_get_OwnResources(TElXMLKeyInfoDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoData_set_OwnResources(TElXMLKeyInfoDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoData_Create(TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoData_Create_1(int8_t AOwnResources, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoData_Create_2(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoHMACData_get_Key(TElXMLKeyInfoHMACDataHandle _Handle, TElHMACKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoHMACData_set_Key(TElXMLKeyInfoHMACDataHandle _Handle, TElHMACKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoHMACData_Create(int8_t OwnResources, TElXMLKeyInfoHMACDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoHMACData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoHMACDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoSymmetricData_get_Key(TElXMLKeyInfoSymmetricDataHandle _Handle, TElSymmetricKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoSymmetricData_set_Key(TElXMLKeyInfoSymmetricDataHandle _Handle, TElSymmetricKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoSymmetricData_Create(int8_t OwnResources, TElXMLKeyInfoSymmetricDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoSymmetricData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoSymmetricDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAsymmetricData_Create(TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAsymmetricData_Create_1(int8_t AOwnResources, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAsymmetricData_Create_2(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFORSADATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_Update(TElXMLKeyInfoRSADataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_get_RSAKeyMaterial(TElXMLKeyInfoRSADataHandle _Handle, TElRSAKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_get_Exponent(TElXMLKeyInfoRSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_get_Modulus(TElXMLKeyInfoRSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_Create(int8_t OwnResources, TElXMLKeyInfoRSADataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRSAData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoRSADataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFORSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODSADATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_Update(TElXMLKeyInfoDSADataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_DSAKeyMaterial(TElXMLKeyInfoDSADataHandle _Handle, TElDSAKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_P(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_Q(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_G(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_Y(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_J(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_Seed(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_get_PgenCounter(TElXMLKeyInfoDSADataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_Create(int8_t OwnResources, TElXMLKeyInfoDSADataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDSAData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoDSADataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFODSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODHDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_P(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_Q(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_Generator(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_PublicKey(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_Seed(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_get_PgenCounter(TElXMLKeyInfoDHDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_Create(int8_t OwnResources, TElXMLKeyInfoDHDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoDHData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoDHDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFODHDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_Update(TElXMLKeyInfoGOST2001DataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_get_GOST2001KeyMaterial(TElXMLKeyInfoGOST2001DataHandle _Handle, TElGOST2001KeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_get_PublicKey(TElXMLKeyInfoGOST2001DataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_get_PublicKeyParamSet(TElXMLKeyInfoGOST2001DataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_get_DigestParamSet(TElXMLKeyInfoGOST2001DataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_get_EncryptionParamSet(TElXMLKeyInfoGOST2001DataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_Create(int8_t OwnResources, TElXMLKeyInfoGOST2001DataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoGOST2001Data_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoGOST2001DataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOPGPDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_Update(TElXMLKeyInfoPGPDataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_IncludeDataParam(TElXMLKeyInfoPGPDataHandle _Handle, TElXMLKeyInfoPGPDataParamRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_set_IncludeDataParam(TElXMLKeyInfoPGPDataHandle _Handle, TElXMLKeyInfoPGPDataParamRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_IncludeKeyValue(TElXMLKeyInfoPGPDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_set_IncludeKeyValue(TElXMLKeyInfoPGPDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_PublicKey(TElXMLKeyInfoPGPDataHandle _Handle, TElPGPCustomPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_set_PublicKey(TElXMLKeyInfoPGPDataHandle _Handle, TElPGPCustomPublicKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_SecretKey(TElXMLKeyInfoPGPDataHandle _Handle, TElPGPCustomSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_set_SecretKey(TElXMLKeyInfoPGPDataHandle _Handle, TElPGPCustomSecretKeyHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_Passphrase(TElXMLKeyInfoPGPDataHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_set_Passphrase(TElXMLKeyInfoPGPDataHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_KeyID(TElXMLKeyInfoPGPDataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_KeyPacketCount(TElXMLKeyInfoPGPDataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_get_KeyPackets(TElXMLKeyInfoPGPDataHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_Create(int8_t OwnResources, TElXMLKeyInfoPGPDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoPGPData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoPGPDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOPGPDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOECDATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_ECKeyMaterial(TElXMLKeyInfoECDataHandle _Handle, TElECKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_KeyValueFormat(TElXMLKeyInfoECDataHandle _Handle, TSBXMLECKeyValueFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_KeyValueFormat(TElXMLKeyInfoECDataHandle _Handle, TSBXMLECKeyValueFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_PrimeNumberType(TElXMLKeyInfoECDataHandle _Handle, TSBXMLECPrimeNumberTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_PrimeNumberType(TElXMLKeyInfoECDataHandle _Handle, TSBXMLECPrimeNumberTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_IncludeDomainParameters(TElXMLKeyInfoECDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_IncludeDomainParameters(TElXMLKeyInfoECDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_UseExplicitParameters(TElXMLKeyInfoECDataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_UseExplicitParameters(TElXMLKeyInfoECDataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_ECDSAPrefix(TElXMLKeyInfoECDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_ECDSAPrefix(TElXMLKeyInfoECDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_get_DSIG11Prefix(TElXMLKeyInfoECDataHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_set_DSIG11Prefix(TElXMLKeyInfoECDataHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_Create(int8_t AOwnResources, TElXMLKeyInfoECDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoECData_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle AManager, TElCustomCryptoProviderHandle AProvider, TElXMLKeyInfoECDataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOECDATA */

#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_Clear(TElXMLIssuerSerialHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_IsEmpty(TElXMLIssuerSerialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_LoadFromXML(TElXMLIssuerSerialHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_SaveToXML(TElXMLIssuerSerialHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_get_IssuerRDN(TElXMLIssuerSerialHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_get_SerialNumber(TElXMLIssuerSerialHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_set_SerialNumber(TElXMLIssuerSerialHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_get_HexSerialNumber(TElXMLIssuerSerialHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_set_HexSerialNumber(TElXMLIssuerSerialHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_Create(TElXMLIssuerSerialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLIssuerSerial_Create_1(const sb_char16_t * pcAName, int32_t szAName, const sb_char16_t * pcANamespaceURI, int32_t szANamespaceURI, const sb_char16_t * pcAPrefix, int32_t szAPrefix, TElXMLIssuerSerialHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

#ifdef SB_USE_CLASS_TELXMLKEYINFOX509DATA
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_Update(TElXMLKeyInfoX509DataHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_IncludeDataParams(TElXMLKeyInfoX509DataHandle _Handle, TElXMLKeyInfoX509DataParamsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_set_IncludeDataParams(TElXMLKeyInfoX509DataHandle _Handle, TElXMLKeyInfoX509DataParamsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_IncludeKeyValue(TElXMLKeyInfoX509DataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_set_IncludeKeyValue(TElXMLKeyInfoX509DataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_Certificate(TElXMLKeyInfoX509DataHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_set_Certificate(TElXMLKeyInfoX509DataHandle _Handle, TElX509CertificateHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_CertStorage(TElXMLKeyInfoX509DataHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_set_CertStorage(TElXMLKeyInfoX509DataHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_HexSerialNumber(TElXMLKeyInfoX509DataHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_set_HexSerialNumber(TElXMLKeyInfoX509DataHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_IssuerSerialCount(TElXMLKeyInfoX509DataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_SubjectRDNCount(TElXMLKeyInfoX509DataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_SKICount(TElXMLKeyInfoX509DataHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_IssuerRDNs(TElXMLKeyInfoX509DataHandle _Handle, int32_t Index, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_SerialNumbers(TElXMLKeyInfoX509DataHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_SubjectRDNs(TElXMLKeyInfoX509DataHandle _Handle, int32_t Index, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_SKIs(TElXMLKeyInfoX509DataHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_CRLData(TElXMLKeyInfoX509DataHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_get_GeneratedKeyValue(TElXMLKeyInfoX509DataHandle _Handle, TElXMLKeyInfoDataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_Create(int8_t OwnResources, TElXMLKeyInfoX509DataHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoX509Data_Create_1(int8_t AOwnResources, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, TElXMLKeyInfoX509DataHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOX509DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFONODE
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_get_OwnNode(TElXMLKeyInfoNodeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_set_OwnNode(TElXMLKeyInfoNodeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_get_Value(TElXMLKeyInfoNodeHandle _Handle, TElXMLDOMNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_set_Value(TElXMLKeyInfoNodeHandle _Handle, TElXMLDOMNodeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_Create(TElXMLKeyInfoNodeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoNode_Create_1(int8_t AOwnNode, TElXMLKeyInfoNodeHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFONODE */

#ifdef SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRetrievalMethod_get_DataType(TElXMLKeyInfoRetrievalMethodHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRetrievalMethod_set_DataType(TElXMLKeyInfoRetrievalMethodHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRetrievalMethod_get_URI(TElXMLKeyInfoRetrievalMethodHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRetrievalMethod_set_URI(TElXMLKeyInfoRetrievalMethodHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoRetrievalMethod_Create(TElXMLKeyInfoRetrievalMethodHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD */

#ifdef SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_Algorithm(TElXMLKeyInfoAgreementMethodHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_Algorithm(TElXMLKeyInfoAgreementMethodHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_DigestMethod(TElXMLKeyInfoAgreementMethodHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_DigestMethod(TElXMLKeyInfoAgreementMethodHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_KANonce(TElXMLKeyInfoAgreementMethodHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_KANonce(TElXMLKeyInfoAgreementMethodHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_CryptoProviderManager(TElXMLKeyInfoAgreementMethodHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_CryptoProviderManager(TElXMLKeyInfoAgreementMethodHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_OriginatorKeyInfo(TElXMLKeyInfoAgreementMethodHandle _Handle, TElXMLKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_OriginatorKeyInfo(TElXMLKeyInfoAgreementMethodHandle _Handle, TElXMLKeyInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_get_RecipientKeyInfo(TElXMLKeyInfoAgreementMethodHandle _Handle, TElXMLKeyInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_set_RecipientKeyInfo(TElXMLKeyInfoAgreementMethodHandle _Handle, TElXMLKeyInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLKeyInfoAgreementMethod_Create(TElXMLKeyInfoAgreementMethodHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_get_ID(TElXMLPropertyHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_set_ID(TElXMLPropertyHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_get_Target(TElXMLPropertyHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_set_Target(TElXMLPropertyHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_get_PropertyNode(TElXMLPropertyHandle _Handle, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_set_PropertyNode(TElXMLPropertyHandle _Handle, TElXMLDOMElementHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_get_OwnPropertyNode(TElXMLPropertyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_set_OwnPropertyNode(TElXMLPropertyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperty_Create(TElXMLPropertyHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

#ifdef SB_USE_CLASS_TELXMLPROPERTIES
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_IsEmpty(TElXMLPropertiesHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_LoadFromXML(TElXMLPropertiesHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_SaveToXML(TElXMLPropertiesHandle _Handle, TElXMLDOMDocumentHandle Document, TElXMLCustomFormatterHandle Formatter, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_Add(TElXMLPropertiesHandle _Handle, TElXMLPropertyHandle AProperty, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_Insert(TElXMLPropertiesHandle _Handle, int32_t Index, TElXMLPropertyHandle AProperty);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_Delete(TElXMLPropertiesHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_Clear(TElXMLPropertiesHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_get_Count(TElXMLPropertiesHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_get_ID(TElXMLPropertiesHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_set_ID(TElXMLPropertiesHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_get_Properties(TElXMLPropertiesHandle _Handle, int32_t Index, TElXMLPropertyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProperties_Create(TElXMLPropertiesHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElXMLProcessor_get_CryptoProviderManager(TElXMLProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProcessor_set_CryptoProviderManager(TElXMLProcessorHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLProcessor_Create(TComponentHandle AOwner, TElXMLProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLFORMATTER
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_AppendElement(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMElementHandle Child);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_AppendElement_1(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLCustomElementHandle Child, TElXMLDOMDocumentHandle Document, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_AppendElementWithText(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMElementHandle Child, const sb_char16_t * pcChildText, int32_t szChildText, TElXMLTextTypeRaw ChildTextType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_AppendText(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Parent, const sb_char16_t * pcText, int32_t szText, TElXMLTextTypeRaw TextType);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_InsertBefore(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Parent, TElXMLDOMNodeHandle ChildRef, TElXMLCustomElementHandle Child, TElXMLDOMDocumentHandle Document);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_Clear(TElXMLFormatterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_Push(TElXMLFormatterHandle _Handle, TElXMLDOMElementHandle Element);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_Pop(TElXMLFormatterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_get_Level(TElXMLFormatterHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_set_Level(TElXMLFormatterHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_get_Path(TElXMLFormatterHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_set_Path(TElXMLFormatterHandle _Handle, const sb_char16_t * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_get_OnFormatElement(TElXMLFormatterHandle _Handle, TSBXMLFormatElementEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_set_OnFormatElement(TElXMLFormatterHandle _Handle, TSBXMLFormatElementEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_get_OnFormatText(TElXMLFormatterHandle _Handle, TSBXMLFormatTextEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_set_OnFormatText(TElXMLFormatterHandle _Handle, TSBXMLFormatTextEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLFormatter_Create(TElXMLFormatterHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLFORMATTER */

#ifdef SB_USE_CLASS_TELXMLDESCRIPTORMAP
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_Add(TElXMLDescriptorMapHandle _Handle, const uint8_t pOID[], int32_t szOID, const sb_char16_t * pcDescriptor, int32_t szDescriptor);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_ClearOID(TElXMLDescriptorMapHandle _Handle, const uint8_t pOID[], int32_t szOID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_RemoveAt(TElXMLDescriptorMapHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_FindDescriptor(TElXMLDescriptorMapHandle _Handle, const uint8_t pOID[], int32_t szOID, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_FindOID(TElXMLDescriptorMapHandle _Handle, const sb_char16_t * pcDescriptor, int32_t szDescriptor, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_ClearOIDs(TElXMLDescriptorMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_ClearOrders(TElXMLDescriptorMapHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_GetOrder(TElXMLDescriptorMapHandle _Handle, const uint8_t pOID[], int32_t szOID, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_SetOrder(TElXMLDescriptorMapHandle _Handle, int32_t Index, const uint8_t pOID[], int32_t szOID);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_CompatibilityMode(TElXMLDescriptorMapHandle _Handle, TElXMLRDNCompatibilityModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_set_CompatibilityMode(TElXMLDescriptorMapHandle _Handle, TElXMLRDNCompatibilityModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_ReverseOrder(TElXMLDescriptorMapHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_set_ReverseOrder(TElXMLDescriptorMapHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_Separator(TElXMLDescriptorMapHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_set_Separator(TElXMLDescriptorMapHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_Count(TElXMLDescriptorMapHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_OID(TElXMLDescriptorMapHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_get_Descriptor(TElXMLDescriptorMapHandle _Handle, int32_t Index, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElXMLDescriptorMap_Create(TElXMLDescriptorMapHandle * OutResult);
#endif /* SB_USE_CLASS_TELXMLDESCRIPTORMAP */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElXMLKeyInfo;
typedef TElXMLKeyInfo ElXMLKeyInfo;
class TElXMLAlgorithmParameters;
typedef TElXMLAlgorithmParameters ElXMLAlgorithmParameters;
class TElXMLReference;
typedef TElXMLReference ElXMLReference;
class TElXMLReferenceList;
typedef TElXMLReferenceList ElXMLReferenceList;
class TElXMLGOSTR3411Parameters;
class TElXMLRSAPSSParameters;
class TElXMLKeyInfoItem;
typedef TElXMLKeyInfoItem ElXMLKeyInfoItem;
class TElXMLKeyInfoData;
typedef TElXMLKeyInfoData ElXMLKeyInfoData;
class TElXMLKeyInfoHMACData;
typedef TElXMLKeyInfoHMACData ElXMLKeyInfoHMACData;
class TElXMLKeyInfoSymmetricData;
typedef TElXMLKeyInfoSymmetricData ElXMLKeyInfoSymmetricData;
class TElXMLKeyInfoAsymmetricData;
typedef TElXMLKeyInfoAsymmetricData ElXMLKeyInfoAsymmetricData;
class TElXMLKeyInfoRSAData;
typedef TElXMLKeyInfoRSAData ElXMLKeyInfoRSAData;
class TElXMLKeyInfoDSAData;
typedef TElXMLKeyInfoDSAData ElXMLKeyInfoDSAData;
class TElXMLKeyInfoDHData;
typedef TElXMLKeyInfoDHData ElXMLKeyInfoDHData;
class TElXMLKeyInfoGOST2001Data;
class TElXMLKeyInfoPGPData;
typedef TElXMLKeyInfoPGPData ElXMLKeyInfoPGPData;
class TElXMLKeyInfoECData;
class TElXMLIssuerSerial;
typedef TElXMLIssuerSerial ElXMLIssuerSerial;
class TElXMLKeyInfoX509Data;
typedef TElXMLKeyInfoX509Data ElXMLKeyInfoX509Data;
class TElXMLKeyInfoNode;
typedef TElXMLKeyInfoNode ElXMLKeyInfoNode;
class TElXMLKeyInfoRetrievalMethod;
typedef TElXMLKeyInfoRetrievalMethod ElXMLKeyInfoRetrievalMethod;
class TElXMLKeyInfoAgreementMethod;
typedef TElXMLKeyInfoAgreementMethod ElXMLKeyInfoAgreementMethod;
class TElXMLProperty;
typedef TElXMLProperty ElXMLProperty;
class TElXMLProperties;
typedef TElXMLProperties ElXMLProperties;
class TElXMLProcessor;
typedef TElXMLProcessor ElXMLProcessor;
class TElXMLFormatter;
typedef TElXMLFormatter ElXMLFormatter;
class TElXMLDescriptorMap;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElXMLSignatureTypes)

SB_DEFINE_ENUM_FLAG_OPERATORS(TElXMLKeyInfoX509DataParams)

#ifdef SB_USE_CLASS_TELXMLKEYINFO
class TElXMLKeyInfo: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfo)
#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
		TElXMLKeyInfoItem* _Inst_Items;
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
		int32_t Add(TElXMLKeyInfoItem &Item);

		int32_t Add(TElXMLKeyInfoItem *Item);
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
		void Insert(int32_t Index, TElXMLKeyInfoItem &Item);

		void Insert(int32_t Index, TElXMLKeyInfoItem *Item);
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

		void Delete(int32_t Index);

		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void ExtractAllCertificates(TElCustomCertStorage &Storage);

		void ExtractAllCertificates(TElCustomCertStorage *Storage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
		void SetKeyData(const TElXMLKeyInfoData &KeyData);

		void SetKeyData(const TElXMLKeyInfoData *KeyData);
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLKeyInfo, Count);

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
		virtual TElXMLKeyInfoItem* get_Items(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLKeyInfo, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual void get_KeyName(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_KeyName(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_KeyName(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_KeyName(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLKeyInfo(TElXMLKeyInfoHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfo();

		explicit TElXMLKeyInfo(const sb_u16string &AKeyName);

#ifdef SB_U16STRING_USED
		explicit TElXMLKeyInfo(const std::wstring &AKeyName);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLKeyInfo();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
class TElXMLAlgorithmParameters: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLAlgorithmParameters)
	public:
		virtual TElXMLAlgorithmParametersHandle Clone();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedNameHandle GetCryptoProviderParameters();
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElXMLAlgorithmParameters(TElXMLAlgorithmParametersHandle handle, TElOwnHandle ownHandle);

		TElXMLAlgorithmParameters();

};
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
class TElXMLReference: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLReference)
#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		TElXMLTransformChain* _Inst_TransformChain;
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */
#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		TElXMLAlgorithmParameters* _Inst_DigestMethodParameters;
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_URINode;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */
#ifdef SB_USE_CLASS_TELXMLNODESET
		TElXMLNodeSet* _Inst_URINodes;
#endif /* SB_USE_CLASS_TELXMLNODESET */
#ifdef SB_USE_CLASS_TSTREAM
		TStream* _Inst_URIStream;
#endif /* SB_USE_CLASS_TSTREAM */

		void initInstances();

	public:
		void UpdateDigestValue(int32_t Mode);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		void UpdateDigestValue(int32_t Mode, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		void UpdateDigestValue(int32_t Mode, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void UpdateDigestValue();

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		void UpdateDigestValue(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		void UpdateDigestValue(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElXMLReferenceHandle Clone();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

		bool IsURIResolved();

#ifdef SB_USE_CLASS_TELHASHFUNCTION
		void ProcessData(TElHashFunction &HashFunc);

		void ProcessData(TElHashFunction *HashFunc);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#ifdef SB_USE_CLASS_TELHASHFUNCTION
		void ProcessData(TElHashFunction &HashFunc, TElXMLCanonicalizationMethod CanonicalizationMethod);

		void ProcessData(TElHashFunction *HashFunc, TElXMLCanonicalizationMethod CanonicalizationMethod);
#endif /* SB_USE_CLASS_TELHASHFUNCTION */

#ifdef SB_USE_CLASS_TELXMLTRANSFORMCHAIN
		virtual TElXMLTransformChain* get_TransformChain();

		SB_DECLARE_PROPERTY_GET(TElXMLTransformChain*, get_TransformChain, TElXMLReference, TransformChain);
#endif /* SB_USE_CLASS_TELXMLTRANSFORMCHAIN */

		virtual TElXMLDigestMethod get_DigestMethod();

		virtual void set_DigestMethod(TElXMLDigestMethod Value);

		SB_DECLARE_PROPERTY(TElXMLDigestMethod, get_DigestMethod, set_DigestMethod, TElXMLReference, DigestMethod);

		virtual void get_DigestValue(std::vector<uint8_t> &OutResult);

		virtual void set_DigestValue(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLALGORITHMPARAMETERS
		virtual TElXMLAlgorithmParameters* get_DigestMethodParameters();

		SB_DECLARE_PROPERTY_GET(TElXMLAlgorithmParameters*, get_DigestMethodParameters, TElXMLReference, DigestMethodParameters);
#endif /* SB_USE_CLASS_TELXMLALGORITHMPARAMETERS */

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_RefType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_RefType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_RefType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_RefType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual bool get_HasURI();

		virtual void set_HasURI(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HasURI, set_HasURI, TElXMLReference, HasURI);

		virtual void get_URIData(std::vector<uint8_t> &OutResult);

		virtual void set_URIData(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_URINode();

		virtual void set_URINode(TElXMLDOMNode &Value);

		virtual void set_URINode(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_URINode, set_URINode, TElXMLReference, URINode);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

#ifdef SB_USE_CLASS_TELXMLNODESET
		virtual TElXMLNodeSet* get_URINodes();

		virtual void set_URINodes(TElXMLNodeSet &Value);

		virtual void set_URINodes(TElXMLNodeSet *Value);

		SB_DECLARE_PROPERTY(TElXMLNodeSet*, get_URINodes, set_URINodes, TElXMLReference, URINodes);
#endif /* SB_USE_CLASS_TELXMLNODESET */

#ifdef SB_USE_CLASS_TSTREAM
		virtual TStream* get_URIStream();

		virtual void set_URIStream(TStream &Value);

		virtual void set_URIStream(TStream *Value);

		SB_DECLARE_PROPERTY(TStream*, get_URIStream, set_URIStream, TElXMLReference, URIStream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int64_t get_URIStreamOffset();

		virtual void set_URIStreamOffset(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_URIStreamOffset, set_URIStreamOffset, TElXMLReference, URIStreamOffset);

		virtual int64_t get_URIStreamCount();

		virtual void set_URIStreamCount(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_URIStreamCount, set_URIStreamCount, TElXMLReference, URIStreamCount);

		TElXMLReference(TElXMLReferenceHandle handle, TElOwnHandle ownHandle);

		TElXMLReference();

		virtual ~TElXMLReference();

};
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELXMLREFERENCELIST
class TElXMLReferenceList: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLReferenceList)
#ifdef SB_USE_CLASS_TELXMLREFERENCE
		TElXMLReference* _Inst_Reference;
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		void initInstances();

	public:
		int32_t Add();

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		int32_t Add(TElXMLReference &AReference);

		int32_t Add(TElXMLReference *AReference);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		void Insert(int32_t Index, TElXMLReference &AReference);

		void Insert(int32_t Index, TElXMLReference *AReference);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		void Delete(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		int32_t IndexOf(TElXMLReference &AReference);

		int32_t IndexOf(TElXMLReference *AReference);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLReferenceList, Count);

#ifdef SB_USE_CLASS_TELXMLREFERENCE
		virtual TElXMLReference* get_Reference(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLREFERENCE */

		TElXMLReferenceList(TElXMLReferenceListHandle handle, TElOwnHandle ownHandle);

		TElXMLReferenceList();

		virtual ~TElXMLReferenceList();

};
#endif /* SB_USE_CLASS_TELXMLREFERENCELIST */

#ifdef SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS
class TElXMLGOSTR3411Parameters: public TElXMLAlgorithmParameters
{
	private:
		SB_DISABLE_COPY(TElXMLGOSTR3411Parameters)
	public:
		virtual void Clear();

		virtual TElXMLAlgorithmParametersHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedNameHandle GetCryptoProviderParameters();
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_DigestParameter(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DigestParameter(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DigestParameter(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DigestParameter(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLGOSTR3411Parameters(TElXMLGOSTR3411ParametersHandle handle, TElOwnHandle ownHandle);

		TElXMLGOSTR3411Parameters();

};
#endif /* SB_USE_CLASS_TELXMLGOSTR3411PARAMETERS */

#ifdef SB_USE_CLASS_TELXMLRSAPSSPARAMETERS
class TElXMLRSAPSSParameters: public TElXMLAlgorithmParameters
{
	private:
		SB_DISABLE_COPY(TElXMLRSAPSSParameters)
	public:
		virtual void Clear();

		virtual TElXMLAlgorithmParametersHandle Clone();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedNameHandle GetCryptoProviderParameters();
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual TElXMLDigestMethod get_DigestMethod();

		virtual void set_DigestMethod(TElXMLDigestMethod Value);

		SB_DECLARE_PROPERTY(TElXMLDigestMethod, get_DigestMethod, set_DigestMethod, TElXMLRSAPSSParameters, DigestMethod);

		virtual int32_t get_MaskGenerationFunction();

		virtual void set_MaskGenerationFunction(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaskGenerationFunction, set_MaskGenerationFunction, TElXMLRSAPSSParameters, MaskGenerationFunction);

		virtual int32_t get_SaltLength();

		virtual void set_SaltLength(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SaltLength, set_SaltLength, TElXMLRSAPSSParameters, SaltLength);

		virtual int32_t get_TrailerField();

		virtual void set_TrailerField(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TrailerField, set_TrailerField, TElXMLRSAPSSParameters, TrailerField);

		TElXMLRSAPSSParameters(TElXMLRSAPSSParametersHandle handle, TElOwnHandle ownHandle);

		TElXMLRSAPSSParameters();

};
#endif /* SB_USE_CLASS_TELXMLRSAPSSPARAMETERS */

#ifdef SB_USE_CLASS_TELXMLKEYINFOITEM
class TElXMLKeyInfoItem: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoItem)
	public:
		TElXMLKeyInfoItem(TElXMLKeyInfoItemHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoItem();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOITEM */

#ifdef SB_USE_CLASS_TELXMLKEYINFODATA
class TElXMLKeyInfoData: public TElXMLKeyInfoItem
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoData)
	public:
		virtual bool get_OwnResources();

		virtual void set_OwnResources(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnResources, set_OwnResources, TElXMLKeyInfoData, OwnResources);

		TElXMLKeyInfoData(TElXMLKeyInfoDataHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoData();

		explicit TElXMLKeyInfoData(bool AOwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELXMLKEYINFODATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOHMACDATA
class TElXMLKeyInfoHMACData: public TElXMLKeyInfoData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoHMACData)
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		TElHMACKeyMaterial* _Inst_Key;
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELHMACKEYMATERIAL
		virtual TElHMACKeyMaterial* get_Key();

		virtual void set_Key(TElHMACKeyMaterial &Value);

		virtual void set_Key(TElHMACKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElHMACKeyMaterial*, get_Key, set_Key, TElXMLKeyInfoHMACData, Key);
#endif /* SB_USE_CLASS_TELHMACKEYMATERIAL */

		TElXMLKeyInfoHMACData(TElXMLKeyInfoHMACDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoHMACData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoHMACData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoHMACData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoHMACData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOHMACDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA
class TElXMLKeyInfoSymmetricData: public TElXMLKeyInfoData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoSymmetricData)
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
		TElSymmetricKeyMaterial* _Inst_Key;
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSYMMETRICKEYMATERIAL
		virtual TElSymmetricKeyMaterial* get_Key();

		virtual void set_Key(TElSymmetricKeyMaterial &Value);

		virtual void set_Key(TElSymmetricKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElSymmetricKeyMaterial*, get_Key, set_Key, TElXMLKeyInfoSymmetricData, Key);
#endif /* SB_USE_CLASS_TELSYMMETRICKEYMATERIAL */

		TElXMLKeyInfoSymmetricData(TElXMLKeyInfoSymmetricDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoSymmetricData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoSymmetricData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoSymmetricData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoSymmetricData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOSYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA
class TElXMLKeyInfoAsymmetricData: public TElXMLKeyInfoData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoAsymmetricData)
	public:
		TElXMLKeyInfoAsymmetricData(TElXMLKeyInfoAsymmetricDataHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoAsymmetricData();

		explicit TElXMLKeyInfoAsymmetricData(bool AOwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoAsymmetricData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoAsymmetricData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOASYMMETRICDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFORSADATA
class TElXMLKeyInfoRSAData: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoRSAData)
#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
		TElRSAKeyMaterial* _Inst_RSAKeyMaterial;
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

		void initInstances();

	public:
		void Update();

#ifdef SB_USE_CLASS_TELRSAKEYMATERIAL
		virtual TElRSAKeyMaterial* get_RSAKeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElRSAKeyMaterial*, get_RSAKeyMaterial, TElXMLKeyInfoRSAData, RSAKeyMaterial);
#endif /* SB_USE_CLASS_TELRSAKEYMATERIAL */

		virtual void get_Exponent(std::vector<uint8_t> &OutResult);

		virtual void get_Modulus(std::vector<uint8_t> &OutResult);

		TElXMLKeyInfoRSAData(TElXMLKeyInfoRSADataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoRSAData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoRSAData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoRSAData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoRSAData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFORSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODSADATA
class TElXMLKeyInfoDSAData: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoDSAData)
#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
		TElDSAKeyMaterial* _Inst_DSAKeyMaterial;
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

		void initInstances();

	public:
		void Update();

#ifdef SB_USE_CLASS_TELDSAKEYMATERIAL
		virtual TElDSAKeyMaterial* get_DSAKeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElDSAKeyMaterial*, get_DSAKeyMaterial, TElXMLKeyInfoDSAData, DSAKeyMaterial);
#endif /* SB_USE_CLASS_TELDSAKEYMATERIAL */

		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void get_G(std::vector<uint8_t> &OutResult);

		virtual void get_Y(std::vector<uint8_t> &OutResult);

		virtual void get_J(std::vector<uint8_t> &OutResult);

		virtual void get_Seed(std::vector<uint8_t> &OutResult);

		virtual void get_PgenCounter(std::vector<uint8_t> &OutResult);

		TElXMLKeyInfoDSAData(TElXMLKeyInfoDSADataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoDSAData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoDSAData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoDSAData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoDSAData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFODSADATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFODHDATA
class TElXMLKeyInfoDHData: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoDHData)
	public:
		virtual void get_P(std::vector<uint8_t> &OutResult);

		virtual void get_Q(std::vector<uint8_t> &OutResult);

		virtual void get_Generator(std::vector<uint8_t> &OutResult);

		virtual void get_PublicKey(std::vector<uint8_t> &OutResult);

		virtual void get_Seed(std::vector<uint8_t> &OutResult);

		virtual void get_PgenCounter(std::vector<uint8_t> &OutResult);

		TElXMLKeyInfoDHData(TElXMLKeyInfoDHDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoDHData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoDHData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoDHData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

};
#endif /* SB_USE_CLASS_TELXMLKEYINFODHDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA
class TElXMLKeyInfoGOST2001Data: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoGOST2001Data)
#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
		TElGOST2001KeyMaterial* _Inst_GOST2001KeyMaterial;
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

		void initInstances();

	public:
		void Update();

#ifdef SB_USE_CLASS_TELGOST2001KEYMATERIAL
		virtual TElGOST2001KeyMaterial* get_GOST2001KeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElGOST2001KeyMaterial*, get_GOST2001KeyMaterial, TElXMLKeyInfoGOST2001Data, GOST2001KeyMaterial);
#endif /* SB_USE_CLASS_TELGOST2001KEYMATERIAL */

		virtual void get_PublicKey(std::vector<uint8_t> &OutResult);

		virtual void get_PublicKeyParamSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_PublicKeyParamSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_DigestParamSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DigestParamSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void get_EncryptionParamSet(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_EncryptionParamSet(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLKeyInfoGOST2001Data(TElXMLKeyInfoGOST2001DataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoGOST2001Data(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoGOST2001Data(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoGOST2001Data(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoGOST2001Data();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOGOST2001DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOPGPDATA
class TElXMLKeyInfoPGPData: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoPGPData)
#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		TElPGPCustomPublicKey* _Inst_PublicKey;
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		TElPGPCustomSecretKey* _Inst_SecretKey;
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

		void initInstances();

	public:
		void Update();

		virtual TElXMLKeyInfoPGPDataParam get_IncludeDataParam();

		virtual void set_IncludeDataParam(TElXMLKeyInfoPGPDataParam Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoPGPDataParam, get_IncludeDataParam, set_IncludeDataParam, TElXMLKeyInfoPGPData, IncludeDataParam);

		virtual bool get_IncludeKeyValue();

		virtual void set_IncludeKeyValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeKeyValue, set_IncludeKeyValue, TElXMLKeyInfoPGPData, IncludeKeyValue);

#ifdef SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY
		virtual TElPGPCustomPublicKey* get_PublicKey();

		virtual void set_PublicKey(TElPGPCustomPublicKey &Value);

		virtual void set_PublicKey(TElPGPCustomPublicKey *Value);

		SB_DECLARE_PROPERTY(TElPGPCustomPublicKey*, get_PublicKey, set_PublicKey, TElXMLKeyInfoPGPData, PublicKey);
#endif /* SB_USE_CLASS_TELPGPCUSTOMPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPCUSTOMSECRETKEY
		virtual TElPGPCustomSecretKey* get_SecretKey();

		virtual void set_SecretKey(TElPGPCustomSecretKey &Value);

		virtual void set_SecretKey(TElPGPCustomSecretKey *Value);

		SB_DECLARE_PROPERTY(TElPGPCustomSecretKey*, get_SecretKey, set_SecretKey, TElXMLKeyInfoPGPData, SecretKey);
#endif /* SB_USE_CLASS_TELPGPCUSTOMSECRETKEY */

		virtual void get_Passphrase(std::string &OutResult);

		virtual void set_Passphrase(const std::string &Value);

		virtual void get_KeyID(std::vector<uint8_t> &OutResult);

		virtual int32_t get_KeyPacketCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyPacketCount, TElXMLKeyInfoPGPData, KeyPacketCount);

		virtual void get_KeyPackets(int32_t Index, std::vector<uint8_t> &OutResult);

		TElXMLKeyInfoPGPData(TElXMLKeyInfoPGPDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoPGPData(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoPGPData(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoPGPData(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoPGPData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOPGPDATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFOECDATA
class TElXMLKeyInfoECData: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoECData)
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
		TElECKeyMaterial* _Inst_ECKeyMaterial;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
		virtual TElECKeyMaterial* get_ECKeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElECKeyMaterial*, get_ECKeyMaterial, TElXMLKeyInfoECData, ECKeyMaterial);
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

		virtual TSBXMLECKeyValueFormat get_KeyValueFormat();

		virtual void set_KeyValueFormat(TSBXMLECKeyValueFormat Value);

		SB_DECLARE_PROPERTY(TSBXMLECKeyValueFormat, get_KeyValueFormat, set_KeyValueFormat, TElXMLKeyInfoECData, KeyValueFormat);

		virtual TSBXMLECPrimeNumberType get_PrimeNumberType();

		virtual void set_PrimeNumberType(TSBXMLECPrimeNumberType Value);

		SB_DECLARE_PROPERTY(TSBXMLECPrimeNumberType, get_PrimeNumberType, set_PrimeNumberType, TElXMLKeyInfoECData, PrimeNumberType);

		virtual bool get_IncludeDomainParameters();

		virtual void set_IncludeDomainParameters(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeDomainParameters, set_IncludeDomainParameters, TElXMLKeyInfoECData, IncludeDomainParameters);

		virtual bool get_UseExplicitParameters();

		virtual void set_UseExplicitParameters(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseExplicitParameters, set_UseExplicitParameters, TElXMLKeyInfoECData, UseExplicitParameters);

		virtual void get_ECDSAPrefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ECDSAPrefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ECDSAPrefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ECDSAPrefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DSIG11Prefix(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DSIG11Prefix(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DSIG11Prefix(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DSIG11Prefix(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLKeyInfoECData(TElXMLKeyInfoECDataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoECData(bool AOwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoECData(bool AOwnResources, TElCustomCryptoProviderManager &AManager, TElCustomCryptoProvider &AProvider);

		TElXMLKeyInfoECData(bool AOwnResources, TElCustomCryptoProviderManager *AManager, TElCustomCryptoProvider *AProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoECData();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOECDATA */

#ifdef SB_USE_CLASS_TELXMLISSUERSERIAL
class TElXMLIssuerSerial: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLIssuerSerial)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerRDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		virtual void Clear();

		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerRDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_IssuerRDN, TElXMLIssuerSerial, IssuerRDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual void set_SerialNumber(const std::vector<uint8_t> &Value);

		virtual bool get_HexSerialNumber();

		virtual void set_HexSerialNumber(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HexSerialNumber, set_HexSerialNumber, TElXMLIssuerSerial, HexSerialNumber);

		TElXMLIssuerSerial(TElXMLIssuerSerialHandle handle, TElOwnHandle ownHandle);

		TElXMLIssuerSerial();

		TElXMLIssuerSerial(const sb_u16string &AName, const sb_u16string &ANamespaceURI, const sb_u16string &APrefix);

#ifdef SB_U16STRING_USED
		TElXMLIssuerSerial(const std::wstring &AName, const std::wstring &ANamespaceURI, const std::wstring &APrefix);

#endif /* SB_U16STRING_USED */
		virtual ~TElXMLIssuerSerial();

};
#endif /* SB_USE_CLASS_TELXMLISSUERSERIAL */

#ifdef SB_USE_CLASS_TELXMLKEYINFOX509DATA
class TElXMLKeyInfoX509Data: public TElXMLKeyInfoAsymmetricData
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoX509Data)
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509Certificate* _Inst_Certificate;
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_IssuerRDNs;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_SubjectRDNs;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
		TElXMLKeyInfoData* _Inst_GeneratedKeyValue;

		void initInstances();

	public:
		void Update();

		virtual TElXMLKeyInfoX509DataParams get_IncludeDataParams();

		virtual void set_IncludeDataParams(TElXMLKeyInfoX509DataParams Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfoX509DataParams, get_IncludeDataParams, set_IncludeDataParams, TElXMLKeyInfoX509Data, IncludeDataParams);

		virtual bool get_IncludeKeyValue();

		virtual void set_IncludeKeyValue(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeKeyValue, set_IncludeKeyValue, TElXMLKeyInfoX509Data, IncludeKeyValue);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509Certificate* get_Certificate();

		virtual void set_Certificate(TElX509Certificate &Value);

		virtual void set_Certificate(TElX509Certificate *Value);

		SB_DECLARE_PROPERTY(TElX509Certificate*, get_Certificate, set_Certificate, TElXMLKeyInfoX509Data, Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElXMLKeyInfoX509Data, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_HexSerialNumber();

		virtual void set_HexSerialNumber(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HexSerialNumber, set_HexSerialNumber, TElXMLKeyInfoX509Data, HexSerialNumber);

		virtual int32_t get_IssuerSerialCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_IssuerSerialCount, TElXMLKeyInfoX509Data, IssuerSerialCount);

		virtual int32_t get_SubjectRDNCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SubjectRDNCount, TElXMLKeyInfoX509Data, SubjectRDNCount);

		virtual int32_t get_SKICount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SKICount, TElXMLKeyInfoX509Data, SKICount);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_IssuerRDNs(int32_t Index);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SerialNumbers(int32_t Index, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_SubjectRDNs(int32_t Index);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SKIs(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void get_CRLData(std::vector<uint8_t> &OutResult);

		virtual TElXMLKeyInfoData* get_GeneratedKeyValue();

		SB_DECLARE_PROPERTY_GET(TElXMLKeyInfoData*, get_GeneratedKeyValue, TElXMLKeyInfoX509Data, GeneratedKeyValue);

		TElXMLKeyInfoX509Data(TElXMLKeyInfoX509DataHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLKeyInfoX509Data(bool OwnResources);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElXMLKeyInfoX509Data(bool AOwnResources, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov);

		TElXMLKeyInfoX509Data(bool AOwnResources, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElXMLKeyInfoX509Data();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOX509DATA */

#ifdef SB_USE_CLASS_TELXMLKEYINFONODE
class TElXMLKeyInfoNode: public TElXMLKeyInfoItem
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoNode)
#ifdef SB_USE_CLASS_TELXMLDOMNODE
		TElXMLDOMNode* _Inst_Value;
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		void initInstances();

	public:
		virtual bool get_OwnNode();

		virtual void set_OwnNode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnNode, set_OwnNode, TElXMLKeyInfoNode, OwnNode);

#ifdef SB_USE_CLASS_TELXMLDOMNODE
		virtual TElXMLDOMNode* get_Value();

		virtual void set_Value(TElXMLDOMNode &Value);

		virtual void set_Value(TElXMLDOMNode *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMNode*, get_Value, set_Value, TElXMLKeyInfoNode, Value);
#endif /* SB_USE_CLASS_TELXMLDOMNODE */

		TElXMLKeyInfoNode(TElXMLKeyInfoNodeHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoNode();

		explicit TElXMLKeyInfoNode(bool AOwnNode);

		virtual ~TElXMLKeyInfoNode();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFONODE */

#ifdef SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD
class TElXMLKeyInfoRetrievalMethod: public TElXMLKeyInfoItem
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoRetrievalMethod)
	public:
		virtual void get_DataType(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DataType(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DataType(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DataType(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_URI(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_URI(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_URI(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_URI(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		TElXMLKeyInfoRetrievalMethod(TElXMLKeyInfoRetrievalMethodHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoRetrievalMethod();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFORETRIEVALMETHOD */

#ifdef SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD
class TElXMLKeyInfoAgreementMethod: public TElXMLKeyInfoItem
{
	private:
		SB_DISABLE_COPY(TElXMLKeyInfoAgreementMethod)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
		TElXMLKeyInfo* _Inst_OriginatorKeyInfo;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */
#ifdef SB_USE_CLASS_TELXMLKEYINFO
		TElXMLKeyInfo* _Inst_RecipientKeyInfo;
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

		void initInstances();

	public:
		virtual void get_Algorithm(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Algorithm(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Algorithm(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Algorithm(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_DigestMethod(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_DigestMethod(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_DigestMethod(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_DigestMethod(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_KANonce(std::vector<uint8_t> &OutResult);

		virtual void set_KANonce(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLKeyInfoAgreementMethod, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
		virtual TElXMLKeyInfo* get_OriginatorKeyInfo();

		virtual void set_OriginatorKeyInfo(TElXMLKeyInfo &Value);

		virtual void set_OriginatorKeyInfo(TElXMLKeyInfo *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfo*, get_OriginatorKeyInfo, set_OriginatorKeyInfo, TElXMLKeyInfoAgreementMethod, OriginatorKeyInfo);
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

#ifdef SB_USE_CLASS_TELXMLKEYINFO
		virtual TElXMLKeyInfo* get_RecipientKeyInfo();

		virtual void set_RecipientKeyInfo(TElXMLKeyInfo &Value);

		virtual void set_RecipientKeyInfo(TElXMLKeyInfo *Value);

		SB_DECLARE_PROPERTY(TElXMLKeyInfo*, get_RecipientKeyInfo, set_RecipientKeyInfo, TElXMLKeyInfoAgreementMethod, RecipientKeyInfo);
#endif /* SB_USE_CLASS_TELXMLKEYINFO */

		TElXMLKeyInfoAgreementMethod(TElXMLKeyInfoAgreementMethodHandle handle, TElOwnHandle ownHandle);

		TElXMLKeyInfoAgreementMethod();

		virtual ~TElXMLKeyInfoAgreementMethod();

};
#endif /* SB_USE_CLASS_TELXMLKEYINFOAGREEMENTMETHOD */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
class TElXMLProperty: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLProperty)
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		TElXMLDOMElement* _Inst_PropertyNode;
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		void initInstances();

	public:
		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_Target(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Target(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Target(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Target(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual TElXMLDOMElement* get_PropertyNode();

		virtual void set_PropertyNode(TElXMLDOMElement &Value);

		virtual void set_PropertyNode(TElXMLDOMElement *Value);

		SB_DECLARE_PROPERTY(TElXMLDOMElement*, get_PropertyNode, set_PropertyNode, TElXMLProperty, PropertyNode);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual bool get_OwnPropertyNode();

		virtual void set_OwnPropertyNode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OwnPropertyNode, set_OwnPropertyNode, TElXMLProperty, OwnPropertyNode);

		TElXMLProperty(TElXMLPropertyHandle handle, TElOwnHandle ownHandle);

		TElXMLProperty();

		virtual ~TElXMLProperty();

};
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

#ifdef SB_USE_CLASS_TELXMLPROPERTIES
class TElXMLProperties: public TElXMLCustomElement
{
	private:
		SB_DISABLE_COPY(TElXMLProperties)
#ifdef SB_USE_CLASS_TELXMLPROPERTY
		TElXMLProperty* _Inst_Properties;
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

		void initInstances();

	public:
		bool IsEmpty();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void LoadFromXML(TElXMLDOMElement &Element);

		virtual void LoadFromXML(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument &Document, TElXMLCustomFormatter &Formatter);

		virtual TElXMLDOMElementHandle SaveToXML(TElXMLDOMDocument *Document, TElXMLCustomFormatter *Formatter);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMFORMATTER_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
		int32_t Add(TElXMLProperty &AProperty);

		int32_t Add(TElXMLProperty *AProperty);
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

#ifdef SB_USE_CLASS_TELXMLPROPERTY
		void Insert(int32_t Index, TElXMLProperty &AProperty);

		void Insert(int32_t Index, TElXMLProperty *AProperty);
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

		void Delete(int32_t Index);

		virtual void Clear();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLProperties, Count);

		virtual void get_ID(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_ID(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_ID(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_ID(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
#ifdef SB_USE_CLASS_TELXMLPROPERTY
		virtual TElXMLProperty* get_Properties(int32_t Index);
#endif /* SB_USE_CLASS_TELXMLPROPERTY */

		TElXMLProperties(TElXMLPropertiesHandle handle, TElOwnHandle ownHandle);

		TElXMLProperties();

		virtual ~TElXMLProperties();

};
#endif /* SB_USE_CLASS_TELXMLPROPERTIES */

#ifdef SB_USE_CLASS_TELXMLPROCESSOR
class TElXMLProcessor: public TComponent
{
	private:
		SB_DISABLE_COPY(TElXMLProcessor)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElXMLProcessor, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		TElXMLProcessor(TElXMLProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElXMLProcessor(TComponent &AOwner);

		explicit TElXMLProcessor(TComponent *AOwner);

		virtual ~TElXMLProcessor();

};
#endif /* SB_USE_CLASS_TELXMLPROCESSOR */

#ifdef SB_USE_CLASS_TELXMLFORMATTER
class TElXMLFormatter: public TElXMLCustomFormatter
{
	private:
		SB_DISABLE_COPY(TElXMLFormatter)
	public:
#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendElement(TElXMLDOMElement &Parent, TElXMLDOMElement &Child);

		virtual void AppendElement(TElXMLDOMElement *Parent, TElXMLDOMElement *Child);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT
		virtual TElXMLDOMElementHandle AppendElement(TElXMLDOMElement &Parent, TElXMLCustomElement &Child, TElXMLDOMDocument &Document);

		virtual TElXMLDOMElementHandle AppendElement(TElXMLDOMElement *Parent, TElXMLCustomElement *Child, TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType);

		virtual void AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const sb_u16string &ChildText, TElXMLTextType ChildTextType);
#ifdef SB_U16STRING_USED
		virtual void AppendElementWithText(TElXMLDOMElement &Parent, TElXMLDOMElement &Child, const std::wstring &ChildText, TElXMLTextType ChildTextType);

		virtual void AppendElementWithText(TElXMLDOMElement *Parent, TElXMLDOMElement *Child, const std::wstring &ChildText, TElXMLTextType ChildTextType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void AppendText(TElXMLDOMElement &Parent, const sb_u16string &Text, TElXMLTextType TextType);

		virtual void AppendText(TElXMLDOMElement *Parent, const sb_u16string &Text, TElXMLTextType TextType);
#ifdef SB_U16STRING_USED
		virtual void AppendText(TElXMLDOMElement &Parent, const std::wstring &Text, TElXMLTextType TextType);

		virtual void AppendText(TElXMLDOMElement *Parent, const std::wstring &Text, TElXMLTextType TextType);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE
		virtual void InsertBefore(TElXMLDOMElement &Parent, TElXMLDOMNode &ChildRef, TElXMLCustomElement &Child, TElXMLDOMDocument &Document);

		virtual void InsertBefore(TElXMLDOMElement *Parent, TElXMLDOMNode *ChildRef, TElXMLCustomElement *Child, TElXMLDOMDocument *Document);
#endif /* SB_USE_CLASSES_TELXMLCUSTOMELEMENT_AND_TELXMLDOMDOCUMENT_AND_TELXMLDOMELEMENT_AND_TELXMLDOMNODE */

		virtual void Clear();

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
		virtual void Push(TElXMLDOMElement &Element);

		virtual void Push(TElXMLDOMElement *Element);
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

		virtual void Pop();

		virtual int32_t get_Level();

		virtual void set_Level(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Level, set_Level, TElXMLFormatter, Level);

		virtual void get_Path(sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Path(std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		virtual void set_Path(const sb_u16string &Value);

#ifdef SB_U16STRING_USED
		virtual void set_Path(const std::wstring &Value);

#endif /* SB_U16STRING_USED */
		virtual void get_OnFormatElement(TSBXMLFormatElementEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatElement(TSBXMLFormatElementEvent pMethodValue, void * pDataValue);

		virtual void get_OnFormatText(TSBXMLFormatTextEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFormatText(TSBXMLFormatTextEvent pMethodValue, void * pDataValue);

		TElXMLFormatter(TElXMLFormatterHandle handle, TElOwnHandle ownHandle);

		TElXMLFormatter();

};
#endif /* SB_USE_CLASS_TELXMLFORMATTER */

#ifdef SB_USE_CLASS_TELXMLDESCRIPTORMAP
class TElXMLDescriptorMap: public TObject
{
	private:
		SB_DISABLE_COPY(TElXMLDescriptorMap)
	public:
		void Add(const std::vector<uint8_t> &OID, const sb_u16string &Descriptor);
#ifdef SB_U16STRING_USED
		void Add(const std::vector<uint8_t> &OID, const std::wstring &Descriptor);
#endif /* SB_U16STRING_USED */

		void ClearOID(const std::vector<uint8_t> &OID);

		void RemoveAt(int32_t Index);

		void FindDescriptor(const std::vector<uint8_t> &OID, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		void FindDescriptor(const std::vector<uint8_t> &OID, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		void FindOID(const sb_u16string &Descriptor, std::vector<uint8_t> &OutResult);
#ifdef SB_U16STRING_USED
		void FindOID(const std::wstring &Descriptor, std::vector<uint8_t> &OutResult);
#endif /* SB_U16STRING_USED */

		void ClearOIDs();

		void ClearOrders();

		int32_t GetOrder(const std::vector<uint8_t> &OID);

		void SetOrder(int32_t Index, const std::vector<uint8_t> &OID);

		virtual TElXMLRDNCompatibilityMode get_CompatibilityMode();

		virtual void set_CompatibilityMode(TElXMLRDNCompatibilityMode Value);

		SB_DECLARE_PROPERTY(TElXMLRDNCompatibilityMode, get_CompatibilityMode, set_CompatibilityMode, TElXMLDescriptorMap, CompatibilityMode);

		virtual bool get_ReverseOrder();

		virtual void set_ReverseOrder(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReverseOrder, set_ReverseOrder, TElXMLDescriptorMap, ReverseOrder);

		virtual void get_Separator(std::string &OutResult);

		virtual void set_Separator(const std::string &Value);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElXMLDescriptorMap, Count);

		virtual void get_OID(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void get_Descriptor(int32_t Index, sb_u16string &OutResult);

#ifdef SB_U16STRING_USED
		virtual void get_Descriptor(int32_t Index, std::wstring &OutResult);

#endif /* SB_U16STRING_USED */
		TElXMLDescriptorMap(TElXMLDescriptorMapHandle handle, TElOwnHandle ownHandle);

		TElXMLDescriptorMap();

};
#endif /* SB_USE_CLASS_TELXMLDESCRIPTORMAP */

#ifdef SB_USE_GLOBAL_PROCS_XMLSEC

void ToCryptoBinary(const std::vector<uint8_t> &Buf, std::vector<uint8_t> &OutResult);

void ToCryptoBinary(const std::vector<uint8_t> &Buf, bool KeepTrailingZero, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement &Element, const sb_u16string &Name);
TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement *Element, const sb_u16string &Name);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement &Element, const std::wstring &Name);
TElXMLDOMElementHandle FindChildElementEnc(const TElXMLDOMElement *Element, const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement &Element, const sb_u16string &Name);
TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement *Element, const sb_u16string &Name);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement &Element, const std::wstring &Name);
TElXMLDOMElementHandle FindChildElementSig(const TElXMLDOMElement *Element, const std::wstring &Name);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

#ifdef SB_USE_CLASS_TELXMLDOMELEMENT
TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement &Element, const sb_u16string &Name, const sb_u16string &NamespaceURI);
TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement *Element, const sb_u16string &Name, const sb_u16string &NamespaceURI);
#ifdef SB_U16STRING_USED
TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement &Element, const std::wstring &Name, const std::wstring &NamespaceURI);
TElXMLDOMElementHandle FindChildElementXAdES(const TElXMLDOMElement *Element, const std::wstring &Name, const std::wstring &NamespaceURI);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELXMLDOMELEMENT */

void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult);
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELXMLALGORITHMPARAMETERS
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElXMLAlgorithmParameters &Parameters, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult);
void CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethod aMethod, TElXMLAlgorithmParameters *Parameters, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TELXMLALGORITHMPARAMETERS */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TSTREAM
void CalculateDigestStream(TStream &Stream, int64_t Count, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &Prov, std::vector<uint8_t> &OutResult);
void CalculateDigestStream(TStream *Stream, int64_t Count, TElXMLDigestMethod aMethod, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *Prov, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER_AND_TSTREAM */

int32_t DigestMethodToHashAlgorithm(TElXMLDigestMethod DigestMethod);

void DigestMethodToURI(TElXMLDigestMethod DigestMethod, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void DigestMethodToURI(TElXMLDigestMethod DigestMethod, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

TElXMLDigestMethod URIToDigestMethod(const sb_u16string &DigestMethod);
#ifdef SB_U16STRING_USED
TElXMLDigestMethod URIToDigestMethod(const std::wstring &DigestMethod);
#endif /* SB_U16STRING_USED */

TElXMLDigestMethod GetDigestMethodFromSignatureMethod(TElXMLSignatureMethod SignatureMethod);

TElXMLDigestMethod HashAlgorithmToDigestMethod(int32_t HashAlgorithm);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void FormatRDN(const TElRelativeDistinguishedName &RDN, sb_u16string &OutResult);
void FormatRDN(const TElRelativeDistinguishedName *RDN, sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
void FormatRDN(const TElRelativeDistinguishedName &RDN, std::wstring &OutResult);
void FormatRDN(const TElRelativeDistinguishedName *RDN, std::wstring &OutResult);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
void ExtractRDN(const sb_u16string &Data, TElRelativeDistinguishedName &RDN);
void ExtractRDN(const sb_u16string &Data, TElRelativeDistinguishedName *RDN);
#ifdef SB_U16STRING_USED
void ExtractRDN(const std::wstring &Data, TElRelativeDistinguishedName &RDN);
void ExtractRDN(const std::wstring &Data, TElRelativeDistinguishedName *RDN);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELXMLDESCRIPTORMAP
TElXMLDescriptorMapHandle RDNDescriptorMap();
#endif /* SB_USE_CLASS_TELXMLDESCRIPTORMAP */

#endif /* SB_USE_GLOBAL_PROCS_XMLSEC */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSEC
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_ToCryptoBinary(const uint8_t pBuf[], int32_t szBuf, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_ToCryptoBinary_1(const uint8_t pBuf[], int32_t szBuf, int8_t KeepTrailingZero, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_FindChildElementEnc(const TElXMLDOMElementHandle Element, const sb_char16_t * pcName, int32_t szName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_FindChildElementSig(const TElXMLDOMElementHandle Element, const sb_char16_t * pcName, int32_t szName, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_FindChildElementXAdES(const TElXMLDOMElementHandle Element, const sb_char16_t * pcName, int32_t szName, const sb_char16_t * pcNamespaceURI, int32_t szNamespaceURI, TElXMLDOMElementHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_CalculateDigest(void * Buf, int32_t Size, TElXMLDigestMethodRaw aMethod, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_CalculateDigest_1(void * Buf, int32_t Size, TElXMLDigestMethodRaw aMethod, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_CalculateDigest_2(void * Buf, int32_t Size, TElXMLDigestMethodRaw aMethod, TElXMLAlgorithmParametersHandle Parameters, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_CalculateDigestStream(TStreamHandle Stream, int64_t Count, TElXMLDigestMethodRaw aMethod, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle Prov, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_DigestMethodToHashAlgorithm(TElXMLDigestMethodRaw DigestMethod, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_DigestMethodToURI(TElXMLDigestMethodRaw DigestMethod, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_URIToDigestMethod(const sb_char16_t * pcDigestMethod, int32_t szDigestMethod, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_GetDigestMethodFromSignatureMethod(TElXMLSignatureMethodRaw SignatureMethod, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_HashAlgorithmToDigestMethod(int32_t HashAlgorithm, TElXMLDigestMethodRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_FormatRDN(const TElRelativeDistinguishedNameHandle RDN, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_ExtractRDN(const sb_char16_t * pcData, int32_t szData, TElRelativeDistinguishedNameHandle RDN);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSec_RDNDescriptorMap(TElXMLDescriptorMapHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLSEC */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSEC */

