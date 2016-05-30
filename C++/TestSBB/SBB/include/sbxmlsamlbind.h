#ifndef __INC_SBXMLSAMLBIND
#define __INC_SBXMLSAMLBIND

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbxmlcore.h"
#include "sbxmlsig.h"
#include "sbxmlenc.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmldefs.h"
#include "sbstrutils.h"
#include "sbxmlsoap.h"
#include "sbxmlsoapcore.h"
#include "sbxmlsamlcore.h"
#include "sbxmlsamlprotocol.h"
#include "sbconstants.h"
#include "sbstringlist.h"
#include "sbcomprstream.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbutils.h"
#include "sbtypes.h"
#include "sbzcommonunit.h"
#include "sbzuncompressunit.h"
#include "sbzcompressunit.h"
#include "sbpublickeycrypto.h"
#include "sbzlib.h"
#include "sbcrc.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_samlBindingSOAP 	"urn:oasis:names:tc:SAML:2.0:bindings:SOAP"
#define SB_samlBindingPAOS 	"urn:oasis:names:tc:SAML:2.0:bindings:PAOS"
#define SB_samlBindingRedirect 	"urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Redirect"
#define SB_samlBindingPOST 	"urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST"
#define SB_samlBindingHTTPArtifact 	"urn:oasis:names:tc:SAML:2.0:bindings:HTTP-Artifact"
#define SB_samlRedirectBindingEncodingDeflate 	"urn:oasis:names:tc:SAML:2.0:bindings:URL-Encoding:DEFLATE"
#define SB_SCannotParseGZHeader 	"Invalid GZIP header."
#define SB_SCannotInflateCompressedData 	"Cannot inflate compressed data."

typedef TElClassHandle TElSAMLBindingHandle;

typedef TElClassHandle TElSAMLSOAPBindingHandle;

typedef TElClassHandle TElSAMLCompressedProcessorHandle;

typedef TElClassHandle TElSAMLRedirectBindingHandle;

typedef TElClassHandle TElSAMLPOSTBindingHandle;

typedef TElClassHandle TElSAMLArtifactHandle;

typedef uint8_t TSBSAMLBindingTypeRaw;

typedef enum
{
	sbtNone = 0,
	sbtSOAP = 1,
	sbtPAOS = 2,
	sbtRedirect = 3,
	sbtPOST = 4,
	sbtArtifact = 5
} TSBSAMLBindingType;

typedef uint32_t TSBSAMLBindingTypesRaw;

typedef enum 
{
	f_sbtNone = 1,
	f_sbtSOAP = 2,
	f_sbtPAOS = 4,
	f_sbtRedirect = 8,
	f_sbtPOST = 16,
	f_sbtArtifact = 32
} TSBSAMLBindingTypes;

typedef uint8_t TSBSAMLDataTypeRaw;

typedef enum
{
	sdtNone = 0,
	sdtRequest = 1,
	sdtResponse = 2,
	sdtArtifact = 3
} TSBSAMLDataType;

typedef void (SB_CALLBACK *TSBSAMLBeforeSOAPEnvelope)(void * _ObjectData, TObjectHandle Sender, TElXMLSOAPMessageHandle Msg);

typedef void (SB_CALLBACK *TSBSAMLRedirectBinderSign)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcSignatureAlg, int32_t szSignatureAlg, uint8_t pOutResult[], int32_t * szOutResult);

typedef void (SB_CALLBACK *TSBSAMLRedirectBinderVerify)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const char * pcSignatureAlg, int32_t szSignatureAlg, const uint8_t pSignature[], int32_t szSignature, int8_t * OutResult);

typedef void (SB_CALLBACK *TSBSAMLBindingXMLPreparedEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcXML, int32_t szXML);

typedef uint8_t TSAMLGZHeaderSkippedRaw;

typedef enum
{
	_gzNone = 0,
	_gzMagic = 1,
	_gzMethod = 2,
	_gzFlags = 3,
	_gzTimeXFlagsOSCode = 4,
	_gzExtra = 5,
	_gzFileName = 6,
	_gzFileComment = 7,
	_gzCRC = 8,
	_gzAll = 9
} TSAMLGZHeaderSkipped;

typedef uint8_t TSBSAMLPOSTBindingModeRaw;

typedef enum
{
	spmClient = 0,
	spmServer = 1
} TSBSAMLPOSTBindingMode;

typedef void (SB_CALLBACK *TSBSAMLPOSTBindingParseForm)(void * _ObjectData, TObjectHandle Sender, const char * pcHtml, int32_t szHtml, const char * pcBodyName, int32_t szBodyName, char * pcURL, int32_t * szURL, char * pcBody, int32_t * szBody, char * pcRelayState, int32_t * szRelayState);

#ifdef SB_USE_CLASS_TELSAMLBINDING
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_GetName(TElSAMLBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_StrToBinding(const char * pcS, int32_t szS, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_StrToBinding_1(TElSAMLBindingHandle _Handle, const char * pcS, int32_t szS, TSBSAMLBindingTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_BindingToStr(TSBSAMLBindingTypeRaw V, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_BindingToStr_1(TElSAMLBindingHandle _Handle, TSBSAMLBindingTypeRaw V, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_SaveRequest(TElSAMLBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_SaveResponse(TElSAMLBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_SaveArtifact(TElSAMLBindingHandle _Handle, const uint8_t pArtifact[], int32_t szArtifact, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_LoadRequest(TElSAMLBindingHandle _Handle, const char * pcRequest, int32_t szRequest, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_LoadResponse(TElSAMLBindingHandle _Handle, const char * pcResponse, int32_t szResponse, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_LoadArtifact(TElSAMLBindingHandle _Handle, const char * pcArtifact, int32_t szArtifact, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_get_OnXMLPrepared(TElSAMLBindingHandle _Handle, TSBSAMLBindingXMLPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_set_OnXMLPrepared(TElSAMLBindingHandle _Handle, TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLBinding_Create(TElSAMLBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLBINDING */

#ifdef SB_USE_CLASS_TELSAMLSOAPBINDING
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_GetName(TElSAMLSOAPBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_Detect(const char * pcBuf, int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_Detect_1(TElSAMLSOAPBindingHandle _Handle, const char * pcBuf, int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_SaveRequest(TElSAMLSOAPBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_SaveResponse(TElSAMLSOAPBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_LoadRequest(TElSAMLSOAPBindingHandle _Handle, const char * pcRequest, int32_t szRequest, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_LoadResponse(TElSAMLSOAPBindingHandle _Handle, const char * pcResponse, int32_t szResponse, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_get_Version(TElSAMLSOAPBindingHandle _Handle, TSBXMLSOAPVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_set_Version(TElSAMLSOAPBindingHandle _Handle, TSBXMLSOAPVersionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_get_OnBeforeEnvelope(TElSAMLSOAPBindingHandle _Handle, TSBSAMLBeforeSOAPEnvelope * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_set_OnBeforeEnvelope(TElSAMLSOAPBindingHandle _Handle, TSBSAMLBeforeSOAPEnvelope pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSOAPBinding_Create(TElSAMLSOAPBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSOAPBINDING */

#ifdef SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_Initialize(TElSAMLCompressedProcessorHandle _Handle, int8_t AsEncoder);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_Reset(TElSAMLCompressedProcessorHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_DecodeData(TElSAMLCompressedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, int32_t * Processed, int8_t * EndReached, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_EncodeData(TElSAMLCompressedProcessorHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer, int32_t Position, int32_t Size, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_get_BytesEncoded(TElSAMLCompressedProcessorHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_get_Deflated(TElSAMLCompressedProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_set_Deflated(TElSAMLCompressedProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_get_Gzipped(TElSAMLCompressedProcessorHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_set_Gzipped(TElSAMLCompressedProcessorHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_get_CompressionLevel(TElSAMLCompressedProcessorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_set_CompressionLevel(TElSAMLCompressedProcessorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLCompressedProcessor_Create(TElSAMLCompressedProcessorHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELSAMLREDIRECTBINDING
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_Detect(const char * pcBuf, int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_Detect_1(TElSAMLRedirectBindingHandle _Handle, const char * pcBuf, int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_GetName(TElSAMLRedirectBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_SaveRequest(TElSAMLRedirectBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_SaveResponse(TElSAMLRedirectBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_SaveArtifact(TElSAMLRedirectBindingHandle _Handle, const uint8_t pArtifact[], int32_t szArtifact, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_LoadRequest(TElSAMLRedirectBindingHandle _Handle, const char * pcRequest, int32_t szRequest, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_LoadResponse(TElSAMLRedirectBindingHandle _Handle, const char * pcResponse, int32_t szResponse, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_LoadArtifact(TElSAMLRedirectBindingHandle _Handle, const char * pcArtifact, int32_t szArtifact, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_URL(TElSAMLRedirectBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_URL(TElSAMLRedirectBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_Encoding(TElSAMLRedirectBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_Encoding(TElSAMLRedirectBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_RelayState(TElSAMLRedirectBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_RelayState(TElSAMLRedirectBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_SignatureAlg(TElSAMLRedirectBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_SignatureAlg(TElSAMLRedirectBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_ForceSign(TElSAMLRedirectBindingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_ForceSign(TElSAMLRedirectBindingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_KeyMaterial(TElSAMLRedirectBindingHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_KeyMaterial(TElSAMLRedirectBindingHandle _Handle, TElPublicKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_VerifySignatures(TElSAMLRedirectBindingHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_VerifySignatures(TElSAMLRedirectBindingHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_OnRedirectBinderSign(TElSAMLRedirectBindingHandle _Handle, TSBSAMLRedirectBinderSign * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_OnRedirectBinderSign(TElSAMLRedirectBindingHandle _Handle, TSBSAMLRedirectBinderSign pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_get_OnRedirectBinderVerify(TElSAMLRedirectBindingHandle _Handle, TSBSAMLRedirectBinderVerify * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_set_OnRedirectBinderVerify(TElSAMLRedirectBindingHandle _Handle, TSBSAMLRedirectBinderVerify pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLRedirectBinding_Create(TElSAMLRedirectBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLREDIRECTBINDING */

#ifdef SB_USE_CLASS_TELSAMLPOSTBINDING
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_Detect(const uint8_t pBuf[], int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_Detect_1(TElSAMLPOSTBindingHandle _Handle, const uint8_t pBuf[], int32_t szBuf, char * pcProto, int32_t * szProto, TSBSAMLDataTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_GetName(TElSAMLPOSTBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_SaveRequest(TElSAMLPOSTBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_SaveResponse(TElSAMLPOSTBindingHandle _Handle, TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_LoadRequest(TElSAMLPOSTBindingHandle _Handle, const char * pcRequest, int32_t szRequest, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_LoadResponse(TElSAMLPOSTBindingHandle _Handle, const char * pcResponse, int32_t szResponse, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_URL(TElSAMLPOSTBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_URL(TElSAMLPOSTBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_RelayState(TElSAMLPOSTBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_RelayState(TElSAMLPOSTBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_FormTemplate(TElSAMLPOSTBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_FormTemplate(TElSAMLPOSTBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_Body(TElSAMLPOSTBindingHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_Body(TElSAMLPOSTBindingHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_Mode(TElSAMLPOSTBindingHandle _Handle, TSBSAMLPOSTBindingModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_Mode(TElSAMLPOSTBindingHandle _Handle, TSBSAMLPOSTBindingModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_get_OnParseForm(TElSAMLPOSTBindingHandle _Handle, TSBSAMLPOSTBindingParseForm * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_set_OnParseForm(TElSAMLPOSTBindingHandle _Handle, TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLPOSTBinding_Create(TElSAMLPOSTBindingHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLPOSTBINDING */

#ifdef SB_USE_CLASS_TELSAMLARTIFACT
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_SaveToBuffer(TElSAMLArtifactHandle _Handle, uint8_t pBuf[], int32_t * szBuf, int32_t * Size);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_LoadFromBuffer(TElSAMLArtifactHandle _Handle, const uint8_t pBuffer[], int32_t szBuffer);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_Initialize(TElSAMLArtifactHandle _Handle, const char * pcURI, int32_t szURI);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_get_TypeCode(TElSAMLArtifactHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_get_EndPointIndex(TElSAMLArtifactHandle _Handle, uint16_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_set_EndPointIndex(TElSAMLArtifactHandle _Handle, uint16_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_get_RamainingArtifact(TElSAMLArtifactHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_get_SourceID(TElSAMLArtifactHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_set_SourceID(TElSAMLArtifactHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_get_MessageHandle(TElSAMLArtifactHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_set_MessageHandle(TElSAMLArtifactHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLArtifact_Create(TElSAMLArtifactHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLARTIFACT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLBinding;
class TElSAMLSOAPBinding;
class TElSAMLCompressedProcessor;
class TElSAMLRedirectBinding;
class TElSAMLPOSTBinding;
class TElSAMLArtifact;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSAMLBindingTypes)

#ifdef SB_USE_CLASS_TELSAMLBINDING
class TElSAMLBinding: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLBinding)
	public:
		virtual void GetName(std::string &OutResult);

		static TSBSAMLBindingType StrToBinding(const std::string &S);

		TSBSAMLBindingType StrToBinding_Inst(const std::string &S);

		static void BindingToStr(TSBSAMLBindingType V, std::string &OutResult);

		void BindingToStr_Inst(TSBSAMLBindingType V, std::string &OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void SaveArtifact(const std::vector<uint8_t> &Artifact, std::string &OutResult);

		virtual void LoadRequest(const std::string &Request, std::string &OutResult);

		virtual void LoadResponse(const std::string &Response, std::string &OutResult);

		virtual void LoadArtifact(const std::string &Artifact, std::vector<uint8_t> &OutResult);

		virtual void get_OnXMLPrepared(TSBSAMLBindingXMLPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnXMLPrepared(TSBSAMLBindingXMLPreparedEvent pMethodValue, void * pDataValue);

		TElSAMLBinding(TElSAMLBindingHandle handle, TElOwnHandle ownHandle);

		TElSAMLBinding();

};
#endif /* SB_USE_CLASS_TELSAMLBINDING */

#ifdef SB_USE_CLASS_TELSAMLSOAPBINDING
class TElSAMLSOAPBinding: public TElSAMLBinding
{
	private:
		SB_DISABLE_COPY(TElSAMLSOAPBinding)
	public:
		virtual void GetName(std::string &OutResult);

		static TSBSAMLDataType Detect(const std::string &Buf, std::string &Proto);

		TSBSAMLDataType Detect_Inst(const std::string &Buf, std::string &Proto);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void LoadRequest(const std::string &Request, std::string &OutResult);

		virtual void LoadResponse(const std::string &Response, std::string &OutResult);

		virtual TSBXMLSOAPVersion get_Version();

		virtual void set_Version(TSBXMLSOAPVersion Value);

		SB_DECLARE_PROPERTY(TSBXMLSOAPVersion, get_Version, set_Version, TElSAMLSOAPBinding, Version);

		virtual void get_OnBeforeEnvelope(TSBSAMLBeforeSOAPEnvelope &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeEnvelope(TSBSAMLBeforeSOAPEnvelope pMethodValue, void * pDataValue);

		TElSAMLSOAPBinding(TElSAMLSOAPBindingHandle handle, TElOwnHandle ownHandle);

		TElSAMLSOAPBinding();

};
#endif /* SB_USE_CLASS_TELSAMLSOAPBINDING */

#ifdef SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR
class TElSAMLCompressedProcessor: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLCompressedProcessor)
	public:
		void Initialize(bool AsEncoder);

		void Reset();

		void DecodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, int32_t &Processed, bool &EndReached, std::vector<uint8_t> &OutResult);

		void EncodeData(const std::vector<uint8_t> &Buffer, int32_t Position, int32_t Size, std::vector<uint8_t> &OutResult);

		virtual int64_t get_BytesEncoded();

		SB_DECLARE_PROPERTY_GET(int64_t, get_BytesEncoded, TElSAMLCompressedProcessor, BytesEncoded);

		virtual bool get_Deflated();

		virtual void set_Deflated(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Deflated, set_Deflated, TElSAMLCompressedProcessor, Deflated);

		virtual bool get_Gzipped();

		virtual void set_Gzipped(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Gzipped, set_Gzipped, TElSAMLCompressedProcessor, Gzipped);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSAMLCompressedProcessor, CompressionLevel);

		TElSAMLCompressedProcessor(TElSAMLCompressedProcessorHandle handle, TElOwnHandle ownHandle);

		TElSAMLCompressedProcessor();

};
#endif /* SB_USE_CLASS_TELSAMLCOMPRESSEDPROCESSOR */

#ifdef SB_USE_CLASS_TELSAMLREDIRECTBINDING
class TElSAMLRedirectBinding: public TElSAMLBinding
{
	private:
		SB_DISABLE_COPY(TElSAMLRedirectBinding)
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void initInstances();

	public:
		static TSBSAMLDataType Detect(const std::string &Buf, std::string &Proto);

		TSBSAMLDataType Detect_Inst(const std::string &Buf, std::string &Proto);

		virtual void GetName(std::string &OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void SaveArtifact(const std::vector<uint8_t> &Artifact, std::string &OutResult);

		virtual void LoadRequest(const std::string &Request, std::string &OutResult);

		virtual void LoadResponse(const std::string &Response, std::string &OutResult);

		virtual void LoadArtifact(const std::string &Artifact, std::vector<uint8_t> &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_Encoding(std::string &OutResult);

		virtual void set_Encoding(const std::string &Value);

		virtual void get_RelayState(std::string &OutResult);

		virtual void set_RelayState(const std::string &Value);

		virtual void get_SignatureAlg(std::string &OutResult);

		virtual void set_SignatureAlg(const std::string &Value);

		virtual bool get_ForceSign();

		virtual void set_ForceSign(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceSign, set_ForceSign, TElSAMLRedirectBinding, ForceSign);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_KeyMaterial();

		virtual void set_KeyMaterial(TElPublicKeyMaterial &Value);

		virtual void set_KeyMaterial(TElPublicKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElPublicKeyMaterial*, get_KeyMaterial, set_KeyMaterial, TElSAMLRedirectBinding, KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		virtual bool get_VerifySignatures();

		virtual void set_VerifySignatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_VerifySignatures, set_VerifySignatures, TElSAMLRedirectBinding, VerifySignatures);

		virtual void get_OnRedirectBinderSign(TSBSAMLRedirectBinderSign &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRedirectBinderSign(TSBSAMLRedirectBinderSign pMethodValue, void * pDataValue);

		virtual void get_OnRedirectBinderVerify(TSBSAMLRedirectBinderVerify &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRedirectBinderVerify(TSBSAMLRedirectBinderVerify pMethodValue, void * pDataValue);

		TElSAMLRedirectBinding(TElSAMLRedirectBindingHandle handle, TElOwnHandle ownHandle);

		TElSAMLRedirectBinding();

		virtual ~TElSAMLRedirectBinding();

};
#endif /* SB_USE_CLASS_TELSAMLREDIRECTBINDING */

#ifdef SB_USE_CLASS_TELSAMLPOSTBINDING
class TElSAMLPOSTBinding: public TElSAMLBinding
{
	private:
		SB_DISABLE_COPY(TElSAMLPOSTBinding)
	public:
		static TSBSAMLDataType Detect(const std::vector<uint8_t> &Buf, std::string &Proto);

		TSBSAMLDataType Detect_Inst(const std::vector<uint8_t> &Buf, std::string &Proto);

		virtual void GetName(std::string &OutResult);

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveRequest(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveRequest(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
		virtual void SaveResponse(TElXMLDOMDocument &Doc, std::string &OutResult);

		virtual void SaveResponse(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

		virtual void LoadRequest(const std::string &Request, std::string &OutResult);

		virtual void LoadResponse(const std::string &Response, std::string &OutResult);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_RelayState(std::string &OutResult);

		virtual void set_RelayState(const std::string &Value);

		virtual void get_FormTemplate(std::string &OutResult);

		virtual void set_FormTemplate(const std::string &Value);

		virtual void get_Body(std::string &OutResult);

		virtual void set_Body(const std::string &Value);

		virtual TSBSAMLPOSTBindingMode get_Mode();

		virtual void set_Mode(TSBSAMLPOSTBindingMode Value);

		SB_DECLARE_PROPERTY(TSBSAMLPOSTBindingMode, get_Mode, set_Mode, TElSAMLPOSTBinding, Mode);

		virtual void get_OnParseForm(TSBSAMLPOSTBindingParseForm &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnParseForm(TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue);

		TElSAMLPOSTBinding(TElSAMLPOSTBindingHandle handle, TElOwnHandle ownHandle);

		TElSAMLPOSTBinding();

};
#endif /* SB_USE_CLASS_TELSAMLPOSTBINDING */

#ifdef SB_USE_CLASS_TELSAMLARTIFACT
class TElSAMLArtifact: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLArtifact)
	public:
		void SaveToBuffer(std::vector<uint8_t> &Buf, int32_t &Size);

		void LoadFromBuffer(const std::vector<uint8_t> &Buffer);

		void Initialize(const std::string &URI);

		virtual uint16_t get_TypeCode();

		SB_DECLARE_PROPERTY_GET(uint16_t, get_TypeCode, TElSAMLArtifact, TypeCode);

		virtual uint16_t get_EndPointIndex();

		virtual void set_EndPointIndex(uint16_t Value);

		SB_DECLARE_PROPERTY(uint16_t, get_EndPointIndex, set_EndPointIndex, TElSAMLArtifact, EndPointIndex);

		virtual void get_RamainingArtifact(std::vector<uint8_t> &OutResult);

		virtual void get_SourceID(std::vector<uint8_t> &OutResult);

		virtual void set_SourceID(const std::vector<uint8_t> &Value);

		virtual void get_MessageHandle(std::vector<uint8_t> &OutResult);

		virtual void set_MessageHandle(const std::vector<uint8_t> &Value);

		TElSAMLArtifact(TElSAMLArtifactHandle handle, TElOwnHandle ownHandle);

		TElSAMLArtifact();

};
#endif /* SB_USE_CLASS_TELSAMLARTIFACT */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLBIND

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
void ParseHTTPParameters(const std::string &S, TStringList &Output);
void ParseHTTPParameters(const std::string &S, TStringList *Output);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
void ParseHTTPParameters(const std::string &S, TElStringList &Output);
void ParseHTTPParameters(const std::string &S, TElStringList *Output);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLBIND */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLBIND
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLBind_ParseHTTPParameters(const char * pcS, int32_t szS, TStringListHandle Output);
#else
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLBind_ParseHTTPParameters(const char * pcS, int32_t szS, TElStringListHandle Output);
#endif
#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLBIND */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSAMLBIND */
