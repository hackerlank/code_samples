#ifndef __INC_SBPADES
#define __INC_SBPADES

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbdc.h"
#include "sbdcdef.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbpkicommon.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbrdn.h"
#include "sbpdf.h"
#include "sbpdfcore.h"
#include "sbpdfsecurity.h"
#include "sbcmsutils.h"
#include "sbcms.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbhashfunction.h"
#include "sbtspcommon.h"
#include "sbtspclient.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbcustomcertstorage.h"
#include "sbcrlstorage.h"
#include "sbocspcommon.h"
#include "sbocspclient.h"
#include "sbcertvalidator.h"
#include "sbpublickeycrypto.h"
#include "sbcrl.h"
#include "sbstreams.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElPDFAdvancedPublicKeySecurityHandlerHandle;

typedef uint8_t TSBPAdESSignatureTypeRaw;

typedef enum
{
	pastBasic = 0,
	pastEnhanced = 1,
	pastDocumentTimestamp = 2
} TSBPAdESSignatureType;

typedef void (SB_CALLBACK *TSBPDFSignEvent)(void * _ObjectData, TObjectHandle Sender, TElSignedCMSMessageHandle CMS);

typedef void (SB_CALLBACK *TSBPDFCertValidatorPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateValidatorHandle * CertValidator, TElX509CertificateHandle Cert);

typedef void (SB_CALLBACK *TSBPDFCertValidatorFinishedEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateValidatorHandle CertValidator, TElX509CertificateHandle Cert, TSBCertificateValidityRaw Validity, TSBCertificateValidityReasonRaw Reason);

typedef void (SB_CALLBACK *TSBPDFRemoteSignEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pHash[], int32_t szHash, uint8_t pSignedHash[], int32_t * szSignedHash);

typedef uint8_t TSBPAdESOptionRaw;

typedef enum
{
	poUseSigningCertificateV2 = 0,
	poIncludeAllRevInfoToDSS = 1,
	poCreateVRIDictionaries = 2,
	poUseUndefBEREncoding = 3,
	poTolerateMissingSigningCertificate = 4,
	poCompressDSS = 5
} TSBPAdESOption;

typedef uint32_t TSBPAdESOptionsRaw;

typedef enum 
{
	f_poUseSigningCertificateV2 = 1,
	f_poIncludeAllRevInfoToDSS = 2,
	f_poCreateVRIDictionaries = 4,
	f_poUseUndefBEREncoding = 8,
	f_poTolerateMissingSigningCertificate = 16,
	f_poCompressDSS = 32
} TSBPAdESOptions;

typedef uint8_t TSBPAdESSignatureSizeEstimationStrategyRaw;

typedef enum
{
	psesBasic = 0,
	psesSmart = 1,
	psesSmartAndTrialTimestamp = 2,
	psesPredefinedSize = 3
} TSBPAdESSignatureSizeEstimationStrategy;

typedef uint8_t TSBPAdESExtensionIdentifierModeRaw;

typedef enum
{
	peimNoExtensionIdentifier = 0,
	peimESIC = 1,
	peimADBE = 2,
	peimADBEIfNotPresent = 3,
	peimBoth = 4
} TSBPAdESExtensionIdentifierMode;

#ifdef SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_GetName(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_GetName_1(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_GetDescription(char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_GetDescription_1(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_GetSignerCertificate(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_Reset(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_DSSRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElPDFPublicKeyRevocationInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_CustomRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElPDFPublicKeyRevocationInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_CMS(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElSignedCMSMessageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ValidationDetails(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBCMSAdvancedSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ValidationMessage(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_DocumentTimestamp(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_PAdESSignatureType(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESSignatureTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_PAdESSignatureType(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESSignatureTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_DeepValidation(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_DeepValidation(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_AutoCollectRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_AutoCollectRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_IgnoreChainValidationErrors(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_IgnoreChainValidationErrors(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ForceCompleteChainValidation(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_ForceCompleteChainValidation(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_IncludeRevocationInfoToAdbeAttribute(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_IncludeRevocationInfoToAdbeAttribute(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ValidationMoment(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_ValidationMoment(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_PAdESOptions(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_PAdESOptions(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_SignatureSizeEstimationStrategy(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESSignatureSizeEstimationStrategyRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_SignatureSizeEstimationStrategy(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESSignatureSizeEstimationStrategyRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_PredefinedSignatureSize(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_PredefinedSignatureSize(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningMode(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_RemoteSigningMode(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningParams(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TElRemoteSigningParamsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_RemoteSigningCertIndex(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_RemoteSigningCertIndex(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ExtensionIdentifierMode(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESExtensionIdentifierModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_ExtensionIdentifierMode(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPAdESExtensionIdentifierModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_ReuseCollectedRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_ReuseCollectedRevocationInfo(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_OnBeforeSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_OnBeforeSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_OnAfterSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_OnAfterSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_OnCertValidatorPrepared(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFCertValidatorPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_OnCertValidatorPrepared(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFCertValidatorPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_OnCertValidatorFinished(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFCertValidatorFinishedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_OnCertValidatorFinished(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFCertValidatorFinishedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_get_OnRemoteSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFRemoteSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_set_OnRemoteSign(TElPDFAdvancedPublicKeySecurityHandlerHandle _Handle, TSBPDFRemoteSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElPDFAdvancedPublicKeySecurityHandler_Create(TComponentHandle Owner, TElPDFSecurityHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPDFAdvancedPublicKeySecurityHandler;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBPAdESOptions)

#ifdef SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER
class TElPDFAdvancedPublicKeySecurityHandler: public TElPDFPublicKeySecurityHandler
{
	private:
		SB_DISABLE_COPY(TElPDFAdvancedPublicKeySecurityHandler)
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		TElPDFPublicKeyRevocationInfo* _Inst_DSSRevocationInfo;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		TElPDFPublicKeyRevocationInfo* _Inst_CustomRevocationInfo;
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */
#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
		TElSignedCMSMessage* _Inst_CMS;
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_DocumentTimestamp;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
		TElRemoteSigningParams* _Inst_RemoteSigningParams;
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

		void initInstances();

	public:
		static void GetName(std::string &OutResult);

		virtual void GetName_Inst(std::string &OutResult);

		static void GetDescription(std::string &OutResult);

		virtual void GetDescription_Inst(std::string &OutResult);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		virtual TElX509CertificateHandle GetSignerCertificate();
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void Reset();

		static TClassHandle ClassType();

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		virtual TElPDFPublicKeyRevocationInfo* get_DSSRevocationInfo();

		SB_DECLARE_PROPERTY_GET(TElPDFPublicKeyRevocationInfo*, get_DSSRevocationInfo, TElPDFAdvancedPublicKeySecurityHandler, DSSRevocationInfo);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO
		virtual TElPDFPublicKeyRevocationInfo* get_CustomRevocationInfo();

		SB_DECLARE_PROPERTY_GET(TElPDFPublicKeyRevocationInfo*, get_CustomRevocationInfo, TElPDFAdvancedPublicKeySecurityHandler, CustomRevocationInfo);
#endif /* SB_USE_CLASS_TELPDFPUBLICKEYREVOCATIONINFO */

#ifdef SB_USE_CLASS_TELSIGNEDCMSMESSAGE
		virtual TElSignedCMSMessage* get_CMS();

		SB_DECLARE_PROPERTY_GET(TElSignedCMSMessage*, get_CMS, TElPDFAdvancedPublicKeySecurityHandler, CMS);
#endif /* SB_USE_CLASS_TELSIGNEDCMSMESSAGE */

		virtual TSBCMSAdvancedSignatureValidity get_ValidationDetails();

		SB_DECLARE_PROPERTY_GET(TSBCMSAdvancedSignatureValidity, get_ValidationDetails, TElPDFAdvancedPublicKeySecurityHandler, ValidationDetails);

		virtual void get_ValidationMessage(std::string &OutResult);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_DocumentTimestamp();

		SB_DECLARE_PROPERTY_GET(TElClientTSPInfo*, get_DocumentTimestamp, TElPDFAdvancedPublicKeySecurityHandler, DocumentTimestamp);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual TSBPAdESSignatureType get_PAdESSignatureType();

		virtual void set_PAdESSignatureType(TSBPAdESSignatureType Value);

		SB_DECLARE_PROPERTY(TSBPAdESSignatureType, get_PAdESSignatureType, set_PAdESSignatureType, TElPDFAdvancedPublicKeySecurityHandler, PAdESSignatureType);

		virtual bool get_DeepValidation();

		virtual void set_DeepValidation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DeepValidation, set_DeepValidation, TElPDFAdvancedPublicKeySecurityHandler, DeepValidation);

		virtual bool get_AutoCollectRevocationInfo();

		virtual void set_AutoCollectRevocationInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoCollectRevocationInfo, set_AutoCollectRevocationInfo, TElPDFAdvancedPublicKeySecurityHandler, AutoCollectRevocationInfo);

		virtual bool get_IgnoreChainValidationErrors();

		virtual void set_IgnoreChainValidationErrors(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreChainValidationErrors, set_IgnoreChainValidationErrors, TElPDFAdvancedPublicKeySecurityHandler, IgnoreChainValidationErrors);

		virtual bool get_ForceCompleteChainValidation();

		virtual void set_ForceCompleteChainValidation(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompleteChainValidation, set_ForceCompleteChainValidation, TElPDFAdvancedPublicKeySecurityHandler, ForceCompleteChainValidation);

		virtual bool get_IncludeRevocationInfoToAdbeAttribute();

		virtual void set_IncludeRevocationInfoToAdbeAttribute(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeRevocationInfoToAdbeAttribute, set_IncludeRevocationInfoToAdbeAttribute, TElPDFAdvancedPublicKeySecurityHandler, IncludeRevocationInfoToAdbeAttribute);

		virtual int64_t get_ValidationMoment();

		virtual void set_ValidationMoment(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ValidationMoment, set_ValidationMoment, TElPDFAdvancedPublicKeySecurityHandler, ValidationMoment);

		virtual TSBPAdESOptions get_PAdESOptions();

		virtual void set_PAdESOptions(TSBPAdESOptions Value);

		SB_DECLARE_PROPERTY(TSBPAdESOptions, get_PAdESOptions, set_PAdESOptions, TElPDFAdvancedPublicKeySecurityHandler, PAdESOptions);

		virtual TSBPAdESSignatureSizeEstimationStrategy get_SignatureSizeEstimationStrategy();

		virtual void set_SignatureSizeEstimationStrategy(TSBPAdESSignatureSizeEstimationStrategy Value);

		SB_DECLARE_PROPERTY(TSBPAdESSignatureSizeEstimationStrategy, get_SignatureSizeEstimationStrategy, set_SignatureSizeEstimationStrategy, TElPDFAdvancedPublicKeySecurityHandler, SignatureSizeEstimationStrategy);

		virtual int32_t get_PredefinedSignatureSize();

		virtual void set_PredefinedSignatureSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PredefinedSignatureSize, set_PredefinedSignatureSize, TElPDFAdvancedPublicKeySecurityHandler, PredefinedSignatureSize);

		virtual bool get_RemoteSigningMode();

		virtual void set_RemoteSigningMode(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RemoteSigningMode, set_RemoteSigningMode, TElPDFAdvancedPublicKeySecurityHandler, RemoteSigningMode);

#ifdef SB_USE_CLASS_TELREMOTESIGNINGPARAMS
		virtual TElRemoteSigningParams* get_RemoteSigningParams();

		SB_DECLARE_PROPERTY_GET(TElRemoteSigningParams*, get_RemoteSigningParams, TElPDFAdvancedPublicKeySecurityHandler, RemoteSigningParams);
#endif /* SB_USE_CLASS_TELREMOTESIGNINGPARAMS */

		virtual int32_t get_RemoteSigningCertIndex();

		virtual void set_RemoteSigningCertIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_RemoteSigningCertIndex, set_RemoteSigningCertIndex, TElPDFAdvancedPublicKeySecurityHandler, RemoteSigningCertIndex);

		virtual TSBPAdESExtensionIdentifierMode get_ExtensionIdentifierMode();

		virtual void set_ExtensionIdentifierMode(TSBPAdESExtensionIdentifierMode Value);

		SB_DECLARE_PROPERTY(TSBPAdESExtensionIdentifierMode, get_ExtensionIdentifierMode, set_ExtensionIdentifierMode, TElPDFAdvancedPublicKeySecurityHandler, ExtensionIdentifierMode);

		virtual bool get_ReuseCollectedRevocationInfo();

		virtual void set_ReuseCollectedRevocationInfo(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReuseCollectedRevocationInfo, set_ReuseCollectedRevocationInfo, TElPDFAdvancedPublicKeySecurityHandler, ReuseCollectedRevocationInfo);

		virtual void get_OnBeforeSign(TSBPDFSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBPDFSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnAfterSign(TSBPDFSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAfterSign(TSBPDFSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertValidatorPrepared(TSBPDFCertValidatorPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertValidatorPrepared(TSBPDFCertValidatorPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertValidatorFinished(TSBPDFCertValidatorFinishedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertValidatorFinished(TSBPDFCertValidatorFinishedEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemoteSign(TSBPDFRemoteSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemoteSign(TSBPDFRemoteSignEvent pMethodValue, void * pDataValue);

		TElPDFAdvancedPublicKeySecurityHandler(TElPDFAdvancedPublicKeySecurityHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElPDFAdvancedPublicKeySecurityHandler(TComponent &Owner);

		explicit TElPDFAdvancedPublicKeySecurityHandler(TComponent *Owner);

		virtual ~TElPDFAdvancedPublicKeySecurityHandler();

};
#endif /* SB_USE_CLASS_TELPDFADVANCEDPUBLICKEYSECURITYHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPADES */

