#ifndef __INC_SBDCDEF
#define __INC_SBDCDEF

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbpkcs7utils.h"
#include "sbstrutils.h"
#include "sbrdn.h"
#include "sbdcpkiconstants.h"
#include "sbdc.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElDCPKCS7SignParametersHandle;

typedef TElClassHandle TElDCDefaultRequestFactoryHandle;

#ifdef SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_SaveToRDN(TElDCPKCS7SignParametersHandle _Handle, TElRelativeDistinguishedNameHandle Rdn);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_LoadFromRDN(TElDCPKCS7SignParametersHandle _Handle, TElRelativeDistinguishedNameHandle Rdn);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_ContentType(TElDCPKCS7SignParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_ContentType(TElDCPKCS7SignParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_SgnDataVersion(TElDCPKCS7SignParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_SgnDataVersion(TElDCPKCS7SignParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_SigningTime(TElDCPKCS7SignParametersHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_SigningTime(TElDCPKCS7SignParametersHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_Timestamp(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_Timestamp(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_TimestampServiceID(TElDCPKCS7SignParametersHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_TimestampServiceID(TElDCPKCS7SignParametersHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_TimestampHashAlgorithm(TElDCPKCS7SignParametersHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_TimestampHashAlgorithm(TElDCPKCS7SignParametersHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_IncludeCertsToSgnData(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_IncludeCertsToSgnData(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_IncludeCRLsToSgnData(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_IncludeCRLsToSgnData(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_IncludeRevInfoToAttributes(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_IncludeRevInfoToAttributes(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_IncludeCertChain(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_IncludeCertChain(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_InsertMessageDigests(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_InsertMessageDigests(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_InsertSigningTime(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_InsertSigningTime(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_InsertContentType(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_InsertContentType(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_InsertSigningCertificateAttr(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_InsertSigningCertificateAttr(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_IgnoreTimestampFailure(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_IgnoreTimestampFailure(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_UseGeneralizedTimeFormat(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_UseGeneralizedTimeFormat(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_ForceSigningCertificateV2Usage(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_ForceSigningCertificateV2Usage(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_UseUndefSize(TElDCPKCS7SignParametersHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_set_UseUndefSize(TElDCPKCS7SignParametersHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_CustomSignedAttributes(TElDCPKCS7SignParametersHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_CustomUnsignedAttributes(TElDCPKCS7SignParametersHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_get_CustomOptions(TElDCPKCS7SignParametersHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCPKCS7SignParameters_Create(TElDCPKCS7SignParametersHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS */

#ifdef SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElDCDefaultRequestFactory_CreatePKCS1SignRequest(TElDCDefaultRequestFactoryHandle _Handle, const char * pcOpName, int32_t szOpName, const uint8_t pSource[], int32_t szSource, int32_t HashAlgorithm, int8_t IncludeKeysInResponse, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCDefaultRequestFactory_CreatePKCS7SignRequest(TElDCDefaultRequestFactoryHandle _Handle, const char * pcOpName, int32_t szOpName, const uint8_t pSource[], int32_t szSource, int32_t HashAlgorithm, TElDCPKCS7SignParametersHandle Pars, TElDCAsyncStateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDCDefaultRequestFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElDCPKCS7SignParameters;
class TElDCDefaultRequestFactory;

#ifdef SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS
class TElDCPKCS7SignParameters: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCPKCS7SignParameters)
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_CustomSignedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_CustomUnsignedAttributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_CustomOptions;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void SaveToRDN(TElRelativeDistinguishedName &Rdn);

		void SaveToRDN(TElRelativeDistinguishedName *Rdn);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void LoadFromRDN(TElRelativeDistinguishedName &Rdn);

		void LoadFromRDN(TElRelativeDistinguishedName *Rdn);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_ContentType(std::vector<uint8_t> &OutResult);

		virtual void set_ContentType(const std::vector<uint8_t> &Value);

		virtual int32_t get_SgnDataVersion();

		virtual void set_SgnDataVersion(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SgnDataVersion, set_SgnDataVersion, TElDCPKCS7SignParameters, SgnDataVersion);

		virtual int64_t get_SigningTime();

		virtual void set_SigningTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SigningTime, set_SigningTime, TElDCPKCS7SignParameters, SigningTime);

		virtual bool get_Timestamp();

		virtual void set_Timestamp(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Timestamp, set_Timestamp, TElDCPKCS7SignParameters, Timestamp);

		virtual void get_TimestampServiceID(std::vector<uint8_t> &OutResult);

		virtual void set_TimestampServiceID(const std::vector<uint8_t> &Value);

		virtual int32_t get_TimestampHashAlgorithm();

		virtual void set_TimestampHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimestampHashAlgorithm, set_TimestampHashAlgorithm, TElDCPKCS7SignParameters, TimestampHashAlgorithm);

		virtual bool get_IncludeCertsToSgnData();

		virtual void set_IncludeCertsToSgnData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCertsToSgnData, set_IncludeCertsToSgnData, TElDCPKCS7SignParameters, IncludeCertsToSgnData);

		virtual bool get_IncludeCRLsToSgnData();

		virtual void set_IncludeCRLsToSgnData(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCRLsToSgnData, set_IncludeCRLsToSgnData, TElDCPKCS7SignParameters, IncludeCRLsToSgnData);

		virtual bool get_IncludeRevInfoToAttributes();

		virtual void set_IncludeRevInfoToAttributes(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeRevInfoToAttributes, set_IncludeRevInfoToAttributes, TElDCPKCS7SignParameters, IncludeRevInfoToAttributes);

		virtual bool get_IncludeCertChain();

		virtual void set_IncludeCertChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCertChain, set_IncludeCertChain, TElDCPKCS7SignParameters, IncludeCertChain);

		virtual bool get_InsertMessageDigests();

		virtual void set_InsertMessageDigests(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InsertMessageDigests, set_InsertMessageDigests, TElDCPKCS7SignParameters, InsertMessageDigests);

		virtual bool get_InsertSigningTime();

		virtual void set_InsertSigningTime(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InsertSigningTime, set_InsertSigningTime, TElDCPKCS7SignParameters, InsertSigningTime);

		virtual bool get_InsertContentType();

		virtual void set_InsertContentType(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InsertContentType, set_InsertContentType, TElDCPKCS7SignParameters, InsertContentType);

		virtual bool get_InsertSigningCertificateAttr();

		virtual void set_InsertSigningCertificateAttr(bool Value);

		SB_DECLARE_PROPERTY(bool, get_InsertSigningCertificateAttr, set_InsertSigningCertificateAttr, TElDCPKCS7SignParameters, InsertSigningCertificateAttr);

		virtual bool get_IgnoreTimestampFailure();

		virtual void set_IgnoreTimestampFailure(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreTimestampFailure, set_IgnoreTimestampFailure, TElDCPKCS7SignParameters, IgnoreTimestampFailure);

		virtual bool get_UseGeneralizedTimeFormat();

		virtual void set_UseGeneralizedTimeFormat(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseGeneralizedTimeFormat, set_UseGeneralizedTimeFormat, TElDCPKCS7SignParameters, UseGeneralizedTimeFormat);

		virtual bool get_ForceSigningCertificateV2Usage();

		virtual void set_ForceSigningCertificateV2Usage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceSigningCertificateV2Usage, set_ForceSigningCertificateV2Usage, TElDCPKCS7SignParameters, ForceSigningCertificateV2Usage);

		virtual bool get_UseUndefSize();

		virtual void set_UseUndefSize(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUndefSize, set_UseUndefSize, TElDCPKCS7SignParameters, UseUndefSize);

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_CustomSignedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_CustomSignedAttributes, TElDCPKCS7SignParameters, CustomSignedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_CustomUnsignedAttributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_CustomUnsignedAttributes, TElDCPKCS7SignParameters, CustomUnsignedAttributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_CustomOptions();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_CustomOptions, TElDCPKCS7SignParameters, CustomOptions);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElDCPKCS7SignParameters(TElDCPKCS7SignParametersHandle handle, TElOwnHandle ownHandle);

		TElDCPKCS7SignParameters();

		virtual ~TElDCPKCS7SignParameters();

};
#endif /* SB_USE_CLASS_TELDCPKCS7SIGNPARAMETERS */

#ifdef SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY
class TElDCDefaultRequestFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElDCDefaultRequestFactory)
	public:
#ifdef SB_USE_CLASS_TELDCASYNCSTATE
		TElDCAsyncStateHandle CreatePKCS1SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, bool IncludeKeysInResponse);
#endif /* SB_USE_CLASS_TELDCASYNCSTATE */

#ifdef SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELDCPKCS7SIGNPARAMETERS
		TElDCAsyncStateHandle CreatePKCS7SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, TElDCPKCS7SignParameters &Pars);

		TElDCAsyncStateHandle CreatePKCS7SignRequest(const std::string &OpName, const std::vector<uint8_t> &Source, int32_t HashAlgorithm, TElDCPKCS7SignParameters *Pars);
#endif /* SB_USE_CLASSES_TELDCASYNCSTATE_AND_TELDCPKCS7SIGNPARAMETERS */

		TElDCDefaultRequestFactory(TElDCDefaultRequestFactoryHandle handle, TElOwnHandle ownHandle);

		TElDCDefaultRequestFactory();

};
#endif /* SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY */

#ifdef SB_USE_GLOBAL_PROCS_DCDEF

#ifdef SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY
TElDCDefaultRequestFactoryHandle DefaultDCRequestFactory();
#endif /* SB_USE_CLASS_TELDCDEFAULTREQUESTFACTORY */

#endif /* SB_USE_GLOBAL_PROCS_DCDEF */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_DCDEF
SB_IMPORT uint32_t SB_APIENTRY SBDCDef_DefaultDCRequestFactory(TElDCDefaultRequestFactoryHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_DCDEF */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBDCDEF */

