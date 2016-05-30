#ifndef __INC_SBTSPCLIENT
#define __INC_SBTSPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbconstants.h"
#include "sbpem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbpkicommon.h"
#include "sbtspcommon.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElClientTSPInfoHandle;

typedef TElClientTSPInfoHandle ElClientTSPInfoHandle;

typedef TElClassHandle TElCustomTSPClientHandle;

typedef TElCustomTSPClientHandle ElCustomTSPClientHandle;

typedef TElClassHandle TElFileTSPClientHandle;

typedef TElFileTSPClientHandle ElFileTSPClientHandle;

typedef uint8_t TSBTSPOptionRaw;

typedef enum
{
	tsoIncludeReqPolicy = 0,
	tsoIgnoreBadSignature = 1,
	tsoIgnoreBadNonce = 2
} TSBTSPOption;

typedef uint32_t TSBTSPOptionsRaw;

typedef enum 
{
	f_tsoIncludeReqPolicy = 1,
	f_tsoIgnoreBadSignature = 2,
	f_tsoIgnoreBadNonce = 4
} TSBTSPOptions;

typedef uint8_t TSBTSPRequestFormatRaw;

typedef enum
{
	tsfRFC3161 = 0,
	tsfCMS = 1
} TSBTSPRequestFormat;

typedef void (SB_CALLBACK *TSBTSPBeforeSignEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle Signer);

typedef void (SB_CALLBACK *TSBTSPErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ResultCode);

typedef void (SB_CALLBACK *TSBTimestampNeededEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle RequestStream, TStreamHandle ReplyStream, int8_t * Succeeded);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_ParseCMS(TElClientTSPInfoHandle _Handle, const uint8_t pCMSData[], int32_t szCMSData, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_ParseCMS_1(TElClientTSPInfoHandle _Handle, const uint8_t pCMSData[], int32_t szCMSData, int8_t NoOuterInfo, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_Reset(TElClientTSPInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_GetSignerCertificate(TElClientTSPInfoHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_Nonce(TElClientTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_set_Nonce(TElClientTSPInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_Certificates(TElClientTSPInfoHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_MessageImprint(TElClientTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_ResponseNonce(TElClientTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_CMS(TElClientTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_IgnoreBadSignature(TElClientTSPInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_set_IgnoreBadSignature(TElClientTSPInfoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_LastValidationResult(TElClientTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_HashAlgorithm(TElClientTSPInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_get_HashedData(TElClientTSPInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientTSPInfo_Create(TElClientTSPInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_Timestamp(TElCustomTSPClientHandle _Handle, const uint8_t pHashedData[], int32_t szHashedData, TSBPKIStatusRaw * ServerResult, int32_t * FailureInfo, uint8_t pReplyCMS[], int32_t * szReplyCMS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_TSPInfo(TElCustomTSPClientHandle _Handle, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_ReqPolicy(TElCustomTSPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_ReqPolicy(TElCustomTSPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_HashAlgorithm(TElCustomTSPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_HashAlgorithm(TElCustomTSPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_IncludeCertificates(TElCustomTSPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_IncludeCertificates(TElCustomTSPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_Options(TElCustomTSPClientHandle _Handle, TSBTSPOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_Options(TElCustomTSPClientHandle _Handle, TSBTSPOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_RequestFormat(TElCustomTSPClientHandle _Handle, TSBTSPRequestFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_RequestFormat(TElCustomTSPClientHandle _Handle, TSBTSPRequestFormatRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_CertStorage(TElCustomTSPClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_CertStorage(TElCustomTSPClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_OnCertificateValidate(TElCustomTSPClientHandle _Handle, TSBCertificateValidationEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_OnCertificateValidate(TElCustomTSPClientHandle _Handle, TSBCertificateValidationEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_OnBeforeSign(TElCustomTSPClientHandle _Handle, TSBTSPBeforeSignEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_OnBeforeSign(TElCustomTSPClientHandle _Handle, TSBTSPBeforeSignEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_get_OnTSPError(TElCustomTSPClientHandle _Handle, TSBTSPErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_set_OnTSPError(TElCustomTSPClientHandle _Handle, TSBTSPErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomTSPClient_Create(TComponentHandle Owner, TElCustomTSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELFILETSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_Timestamp(TElFileTSPClientHandle _Handle, const uint8_t pHashedData[], int32_t szHashedData, TSBPKIStatusRaw * ServerResult, int32_t * FailureInfo, uint8_t pReplyCMS[], int32_t * szReplyCMS, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_get_HashOnlyNeeded(TElFileTSPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_set_HashOnlyNeeded(TElFileTSPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_get_OnTimestampNeeded(TElFileTSPClientHandle _Handle, TSBTimestampNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_set_OnTimestampNeeded(TElFileTSPClientHandle _Handle, TSBTimestampNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileTSPClient_Create(TComponentHandle Owner, TElCustomTSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILETSPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElClientTSPInfo;
typedef TElClientTSPInfo ElClientTSPInfo;
class TElCustomTSPClient;
typedef TElCustomTSPClient ElCustomTSPClient;
class TElFileTSPClient;
typedef TElFileTSPClient ElFileTSPClient;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBTSPOptions)

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
class TElClientTSPInfo: public TElTSPInfo
{
	private:
		SB_DISABLE_COPY(TElClientTSPInfo)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		int32_t ParseCMS(const std::vector<uint8_t> &CMSData);

		int32_t ParseCMS(const std::vector<uint8_t> &CMSData, bool NoOuterInfo);

		virtual void Reset();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle GetSignerCertificate();
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_Certificates, TElClientTSPInfo, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_MessageImprint(std::vector<uint8_t> &OutResult);

		virtual void get_ResponseNonce(std::vector<uint8_t> &OutResult);

		virtual void get_CMS(std::vector<uint8_t> &OutResult);

		virtual bool get_IgnoreBadSignature();

		virtual void set_IgnoreBadSignature(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreBadSignature, set_IgnoreBadSignature, TElClientTSPInfo, IgnoreBadSignature);

		virtual int32_t get_LastValidationResult();

		SB_DECLARE_PROPERTY_GET(int32_t, get_LastValidationResult, TElClientTSPInfo, LastValidationResult);

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElClientTSPInfo, HashAlgorithm);

		virtual void get_HashedData(std::vector<uint8_t> &OutResult);

		TElClientTSPInfo(TElClientTSPInfoHandle handle, TElOwnHandle ownHandle);

		TElClientTSPInfo();

		virtual ~TElClientTSPInfo();

};
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT
class TElCustomTSPClient: public TElTSPClass
{
	private:
		SB_DISABLE_COPY(TElCustomTSPClient)
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_TSPInfo;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		virtual int32_t Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_TSPInfo();

		SB_DECLARE_PROPERTY_GET(TElClientTSPInfo*, get_TSPInfo, TElCustomTSPClient, TSPInfo);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		virtual void get_ReqPolicy(std::vector<uint8_t> &OutResult);

		virtual void set_ReqPolicy(const std::vector<uint8_t> &Value);

		virtual int32_t get_HashAlgorithm();

		virtual void set_HashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_HashAlgorithm, set_HashAlgorithm, TElCustomTSPClient, HashAlgorithm);

		virtual bool get_IncludeCertificates();

		virtual void set_IncludeCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeCertificates, set_IncludeCertificates, TElCustomTSPClient, IncludeCertificates);

		virtual TSBTSPOptions get_Options();

		virtual void set_Options(TSBTSPOptions Value);

		SB_DECLARE_PROPERTY(TSBTSPOptions, get_Options, set_Options, TElCustomTSPClient, Options);

		virtual TSBTSPRequestFormat get_RequestFormat();

		virtual void set_RequestFormat(TSBTSPRequestFormat Value);

		SB_DECLARE_PROPERTY(TSBTSPRequestFormat, get_RequestFormat, set_RequestFormat, TElCustomTSPClient, RequestFormat);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElCustomTSPClient, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_OnCertificateValidate(TSBCertificateValidationEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidationEvent pMethodValue, void * pDataValue);

		virtual void get_OnBeforeSign(TSBTSPBeforeSignEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBeforeSign(TSBTSPBeforeSignEvent pMethodValue, void * pDataValue);

		virtual void get_OnTSPError(TSBTSPErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTSPError(TSBTSPErrorEvent pMethodValue, void * pDataValue);

		TElCustomTSPClient(TElCustomTSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomTSPClient(TComponent &Owner);

		explicit TElCustomTSPClient(TComponent *Owner);

		virtual ~TElCustomTSPClient();

};
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELFILETSPCLIENT
class TElFileTSPClient: public TElCustomTSPClient
{
	private:
		SB_DISABLE_COPY(TElFileTSPClient)
	public:
		virtual int32_t Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS);

		virtual bool get_HashOnlyNeeded();

		virtual void set_HashOnlyNeeded(bool Value);

		SB_DECLARE_PROPERTY(bool, get_HashOnlyNeeded, set_HashOnlyNeeded, TElFileTSPClient, HashOnlyNeeded);

		virtual void get_OnTimestampNeeded(TSBTimestampNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimestampNeeded(TSBTimestampNeededEvent pMethodValue, void * pDataValue);

		TElFileTSPClient(TElFileTSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElFileTSPClient(TComponent &Owner);

		explicit TElFileTSPClient(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELFILETSPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTSPCLIENT */

