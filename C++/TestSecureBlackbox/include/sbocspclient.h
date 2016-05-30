#ifndef __INC_SBOCSPCLIENT
#define __INC_SBOCSPCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbpem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbsha.h"
#include "sbrdn.h"
#include "sbocspcommon.h"
#include "sbpublickeycrypto.h"
#include "sbpkcs7utils.h"
#include "sbpkicommon.h"
#include "sbcmsutils.h"
#include "sbhashfunction.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOCSPClientHandle;

typedef TElOCSPClientHandle ElOCSPClientHandle;

typedef TElClassHandle TElOCSPResponderIDHandle;

typedef TElClassHandle TElOCSPSingleResponseHandle;

typedef TElClassHandle TElOCSPResponseHandle;

typedef TElClassHandle TElFileOCSPClientHandle;

typedef TElFileOCSPClientHandle ElFileOCSPClientHandle;

typedef TElClassHandle TElCustomOCSPClientFactoryHandle;

typedef TElCustomOCSPClientFactoryHandle ElCustomOCSPClientFactoryHandle;

typedef TElClassHandle TElOCSPClientManagerHandle;

typedef TElOCSPClientManagerHandle ElOCSPClientManagerHandle;

typedef uint8_t TSBOCSPClientOptionRaw;

typedef enum
{
	ocoIncludeVersion = 0,
	ocoIncludeSupportedResponseTypes = 1
} TSBOCSPClientOption;

typedef uint32_t TSBOCSPClientOptionsRaw;

typedef enum 
{
	f_ocoIncludeVersion = 1,
	f_ocoIncludeSupportedResponseTypes = 2
} TSBOCSPClientOptions;

typedef void (SB_CALLBACK *TSBOCSPValidationNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, TStreamHandle RequestStream, TStreamHandle ReplyStream, int8_t * Succeeded);

#ifdef SB_USE_CLASS_TELOCSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_CreateRequest(TElOCSPClientHandle _Handle, uint8_t pRequest[], int32_t * szRequest, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_ProcessReply(TElOCSPClientHandle _Handle, const uint8_t pReply[], int32_t szReply, TElOCSPServerErrorRaw * ServerResult, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_PerformRequest(TElOCSPClientHandle _Handle, TElOCSPServerErrorRaw * ServerResult, uint8_t pReply[], int32_t * szReply, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_SupportsLocation(TElOCSPClientHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ReplyProducedAt(TElOCSPClientHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ReplyNonce(TElOCSPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ReplyCertificates(TElOCSPClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ServerName(TElOCSPClientHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ServerCertKeyHash(TElOCSPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_ServerCertKeyHash(TElOCSPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_CertStatus(TElOCSPClientHandle _Handle, int32_t Index, TElOCSPCertificateStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_RevocationTime(TElOCSPClientHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_RevocationReason(TElOCSPClientHandle _Handle, int32_t Index, TSBCRLReasonFlagRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_ThisUpdate(TElOCSPClientHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_NextUpdate(TElOCSPClientHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_Response(TElOCSPClientHandle _Handle, TElOCSPResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_Nonce(TElOCSPClientHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_Nonce(TElOCSPClientHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_CertStorage(TElOCSPClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_CertStorage(TElOCSPClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_IssuerCertStorage(TElOCSPClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_IssuerCertStorage(TElOCSPClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_IncludeSignature(TElOCSPClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_IncludeSignature(TElOCSPClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_SignatureAlgorithm(TElOCSPClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_SignatureAlgorithm(TElOCSPClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_Options(TElOCSPClientHandle _Handle, TSBOCSPClientOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_Options(TElOCSPClientHandle _Handle, TSBOCSPClientOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_get_URL(TElOCSPClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_set_URL(TElOCSPClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClient_Create(TComponentHandle Owner, TElOCSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponderID_Clear(TElOCSPResponderIDHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponderID_get_Name(TElOCSPResponderIDHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponderID_get_SHA1KeyHash(TElOCSPResponderIDHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponderID_set_SHA1KeyHash(TElOCSPResponderIDHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponderID_Create(TElOCSPResponderIDHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_LoadFromTag(TElOCSPSingleResponseHandle _Handle, TElASN1ConstrainedTagHandle Tag);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_CertMatches(TElOCSPSingleResponseHandle _Handle, TElX509CertificateHandle Cert, TElX509CertificateHandle Issuer, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_SignerMatches(TElOCSPSingleResponseHandle _Handle, TElPKCS7IssuerHandle Signer, TElX509CertificateHandle Issuer, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_HashAlgorithm(TElOCSPSingleResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_IssuerNameHash(TElOCSPSingleResponseHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_IssuerKeyHash(TElOCSPSingleResponseHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_SerialNumber(TElOCSPSingleResponseHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_CertStatus(TElOCSPSingleResponseHandle _Handle, TElOCSPCertificateStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_ThisUpdate(TElOCSPSingleResponseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_NextUpdate(TElOCSPSingleResponseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_RevocationTime(TElOCSPSingleResponseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_get_RevocationReasons(TElOCSPSingleResponseHandle _Handle, TSBCRLReasonFlagsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPSingleResponse_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Clear(TElOCSPResponseHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Assign(TElOCSPResponseHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Load(TElOCSPResponseHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Save(TElOCSPResponseHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_SaveBasic(TElOCSPResponseHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_SaveFull(TElOCSPResponseHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_EqualsTo(TElOCSPResponseHandle _Handle, TElOCSPResponseHandle OtherResponse, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_FindResponse(TElOCSPResponseHandle _Handle, TElX509CertificateHandle Cert, TElX509CertificateHandle Issuer, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_FindResponse_1(TElOCSPResponseHandle _Handle, TElPKCS7IssuerHandle Signer, TElX509CertificateHandle Issuer, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_GetSignerCertificate(TElOCSPResponseHandle _Handle, TElX509CertificateHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_IsSignerCertificate(TElOCSPResponseHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Validate(TElOCSPResponseHandle _Handle, TSBCMSSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Validate_1(TElOCSPResponseHandle _Handle, TElX509CertificateHandle CACertificate, TSBCMSSignatureValidityRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_GetOCSPResponseHash(TElOCSPResponseHandle _Handle, int32_t Alg, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_SignatureAlgorithm(TElOCSPResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_Certificates(TElOCSPResponseHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_ResponderID(TElOCSPResponseHandle _Handle, TElOCSPResponderIDHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_ProducedAt(TElOCSPResponseHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_Responses(TElOCSPResponseHandle _Handle, int32_t Index, TElOCSPSingleResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_ResponseCount(TElOCSPResponseHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_get_OnCertificateNeeded(TElOCSPResponseHandle _Handle, TSBCMSCertificateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_set_OnCertificateNeeded(TElOCSPResponseHandle _Handle, TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPResponse_Create(TElOCSPResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELFILEOCSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElFileOCSPClient_SupportsLocation(TElFileOCSPClientHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileOCSPClient_PerformRequest(TElFileOCSPClientHandle _Handle, TElOCSPServerErrorRaw * ServerResult, uint8_t pReply[], int32_t * szReply, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileOCSPClient_get_OnOCSPValidationNeeded(TElFileOCSPClientHandle _Handle, TSBOCSPValidationNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElFileOCSPClient_set_OnOCSPValidationNeeded(TElFileOCSPClientHandle _Handle, TSBOCSPValidationNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElFileOCSPClient_Create(TComponentHandle Owner, TElOCSPClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELFILEOCSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
SB_IMPORT uint32_t SB_APIENTRY TElCustomOCSPClientFactory_SupportsLocation(TElCustomOCSPClientFactoryHandle _Handle, const char * pcURI, int32_t szURI, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomOCSPClientFactory_GetClientInstance(TElCustomOCSPClientFactoryHandle _Handle, TObjectHandle Validator, TElOCSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomOCSPClientFactory_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

#ifdef SB_USE_CLASS_TELOCSPCLIENTMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClientManager_FindOCSPClientByLocation(TElOCSPClientManagerHandle _Handle, const char * pcLocation, int32_t szLocation, TObjectHandle Validator, TElOCSPClientHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClientManager_RegisterOCSPClientFactory(TElOCSPClientManagerHandle _Handle, TElCustomOCSPClientFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClientManager_UnregisterOCSPClientFactory(TElOCSPClientManagerHandle _Handle, TElCustomOCSPClientFactoryHandle Factory);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPClientManager_Create(TElOCSPClientManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPCLIENTMANAGER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOCSPClient;
typedef TElOCSPClient ElOCSPClient;
class TElOCSPResponderID;
class TElOCSPSingleResponse;
class TElOCSPResponse;
class TElFileOCSPClient;
typedef TElFileOCSPClient ElFileOCSPClient;
class TElCustomOCSPClientFactory;
typedef TElCustomOCSPClientFactory ElCustomOCSPClientFactory;
class TElOCSPClientManager;
typedef TElOCSPClientManager ElOCSPClientManager;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBOCSPClientOptions)

#ifdef SB_USE_CLASS_TELOCSPCLIENT
class TElOCSPClient: public TElOCSPClass
{
	private:
		SB_DISABLE_COPY(TElOCSPClient)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ReplyCertificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_ServerName;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		TElOCSPResponse* _Inst_Response;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_IssuerCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		int32_t CreateRequest(std::vector<uint8_t> &Request);

		int32_t ProcessReply(const std::vector<uint8_t> &Reply, TElOCSPServerError &ServerResult);

		virtual int32_t PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply);

		virtual bool SupportsLocation(const std::string &URI);

		virtual int64_t get_ReplyProducedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ReplyProducedAt, TElOCSPClient, ReplyProducedAt);

		virtual void get_ReplyNonce(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ReplyCertificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_ReplyCertificates, TElOCSPClient, ReplyCertificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_ServerName();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_ServerName, TElOCSPClient, ServerName);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_ServerCertKeyHash(std::vector<uint8_t> &OutResult);

		virtual void set_ServerCertKeyHash(const std::vector<uint8_t> &Value);

		virtual TElOCSPCertificateStatus get_CertStatus(int32_t Index);

		virtual int64_t get_RevocationTime(int32_t Index);

		virtual TSBCRLReasonFlag get_RevocationReason(int32_t Index);

		virtual int64_t get_ThisUpdate(int32_t Index);

		virtual int64_t get_NextUpdate(int32_t Index);

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
		virtual TElOCSPResponse* get_Response();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponse*, get_Response, TElOCSPClient, Response);
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

		virtual void get_Nonce(std::vector<uint8_t> &OutResult);

		virtual void set_Nonce(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElOCSPClient, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_IssuerCertStorage();

		virtual void set_IssuerCertStorage(TElCustomCertStorage &Value);

		virtual void set_IssuerCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_IssuerCertStorage, set_IssuerCertStorage, TElOCSPClient, IssuerCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_IncludeSignature();

		virtual void set_IncludeSignature(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeSignature, set_IncludeSignature, TElOCSPClient, IncludeSignature);

		virtual int32_t get_SignatureAlgorithm();

		virtual void set_SignatureAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SignatureAlgorithm, set_SignatureAlgorithm, TElOCSPClient, SignatureAlgorithm);

		virtual TSBOCSPClientOptions get_Options();

		virtual void set_Options(TSBOCSPClientOptions Value);

		SB_DECLARE_PROPERTY(TSBOCSPClientOptions, get_Options, set_Options, TElOCSPClient, Options);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		TElOCSPClient(TElOCSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElOCSPClient(TComponent &Owner);

		explicit TElOCSPClient(TComponent *Owner);

		virtual ~TElOCSPClient();

};
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
class TElOCSPResponderID: public TObject
{
	private:
		SB_DISABLE_COPY(TElOCSPResponderID)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Name;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
		void Clear();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Name();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Name, TElOCSPResponderID, Name);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual void get_SHA1KeyHash(std::vector<uint8_t> &OutResult);

		virtual void set_SHA1KeyHash(const std::vector<uint8_t> &Value);

		TElOCSPResponderID(TElOCSPResponderIDHandle handle, TElOwnHandle ownHandle);

		TElOCSPResponderID();

		virtual ~TElOCSPResponderID();

};
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
class TElOCSPSingleResponse: public TObject
{
	private:
		SB_DISABLE_COPY(TElOCSPSingleResponse)
	public:
#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		void LoadFromTag(TElASN1ConstrainedTag &Tag);

		void LoadFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool CertMatches(TElX509Certificate &Cert, TElX509Certificate &Issuer);

		bool CertMatches(TElX509Certificate *Cert, TElX509Certificate *Issuer);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
		bool SignerMatches(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer);

		bool SignerMatches(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer);
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElOCSPSingleResponse, HashAlgorithm);

		virtual void get_IssuerNameHash(std::vector<uint8_t> &OutResult);

		virtual void get_IssuerKeyHash(std::vector<uint8_t> &OutResult);

		virtual void get_SerialNumber(std::vector<uint8_t> &OutResult);

		virtual TElOCSPCertificateStatus get_CertStatus();

		SB_DECLARE_PROPERTY_GET(TElOCSPCertificateStatus, get_CertStatus, TElOCSPSingleResponse, CertStatus);

		virtual int64_t get_ThisUpdate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ThisUpdate, TElOCSPSingleResponse, ThisUpdate);

		virtual int64_t get_NextUpdate();

		SB_DECLARE_PROPERTY_GET(int64_t, get_NextUpdate, TElOCSPSingleResponse, NextUpdate);

		virtual int64_t get_RevocationTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_RevocationTime, TElOCSPSingleResponse, RevocationTime);

		virtual TSBCRLReasonFlags get_RevocationReasons();

		SB_DECLARE_PROPERTY_GET(TSBCRLReasonFlags, get_RevocationReasons, TElOCSPSingleResponse, RevocationReasons);

		TElOCSPSingleResponse(TElOCSPSingleResponseHandle handle, TElOwnHandle ownHandle);

		TElOCSPSingleResponse();

};
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
class TElOCSPResponse: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElOCSPResponse)
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */
#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
		TElOCSPResponderID* _Inst_ResponderID;
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */
#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
		TElOCSPSingleResponse* _Inst_Responses;
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

		void initInstances();

	public:
		void Clear();

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Load(void * Buffer, int32_t Size);

		bool Save(void * Buffer, int32_t &Size);

		bool SaveBasic(void * Buffer, int32_t &Size);

		bool SaveFull(void * Buffer, int32_t &Size);

		bool EqualsTo(TElOCSPResponse &OtherResponse);

		bool EqualsTo(TElOCSPResponse *OtherResponse);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t FindResponse(TElX509Certificate &Cert, TElX509Certificate &Issuer);

		int32_t FindResponse(TElX509Certificate *Cert, TElX509Certificate *Issuer);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
		int32_t FindResponse(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer);

		int32_t FindResponse(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer);
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TElX509CertificateHandle GetSignerCertificate();
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool IsSignerCertificate(TElX509Certificate &Certificate);

		bool IsSignerCertificate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		TSBCMSSignatureValidity Validate();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		TSBCMSSignatureValidity Validate(TElX509Certificate &CACertificate);

		TSBCMSSignatureValidity Validate(TElX509Certificate *CACertificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void GetOCSPResponseHash(int32_t Alg, std::vector<uint8_t> &OutResult);

		virtual int32_t get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureAlgorithm, TElOCSPResponse, SignatureAlgorithm);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_Certificates, TElOCSPResponse, Certificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

#ifdef SB_USE_CLASS_TELOCSPRESPONDERID
		virtual TElOCSPResponderID* get_ResponderID();

		SB_DECLARE_PROPERTY_GET(TElOCSPResponderID*, get_ResponderID, TElOCSPResponse, ResponderID);
#endif /* SB_USE_CLASS_TELOCSPRESPONDERID */

		virtual int64_t get_ProducedAt();

		SB_DECLARE_PROPERTY_GET(int64_t, get_ProducedAt, TElOCSPResponse, ProducedAt);

#ifdef SB_USE_CLASS_TELOCSPSINGLERESPONSE
		virtual TElOCSPSingleResponse* get_Responses(int32_t Index);
#endif /* SB_USE_CLASS_TELOCSPSINGLERESPONSE */

		virtual int32_t get_ResponseCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ResponseCount, TElOCSPResponse, ResponseCount);

		virtual void get_OnCertificateNeeded(TSBCMSCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBCMSCertificateNeededEvent pMethodValue, void * pDataValue);

		TElOCSPResponse(TElOCSPResponseHandle handle, TElOwnHandle ownHandle);

		TElOCSPResponse();

		virtual ~TElOCSPResponse();

};
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

#ifdef SB_USE_CLASS_TELFILEOCSPCLIENT
class TElFileOCSPClient: public TElOCSPClient
{
	private:
		SB_DISABLE_COPY(TElFileOCSPClient)
	public:
		virtual bool SupportsLocation(const std::string &URI);

		virtual int32_t PerformRequest(TElOCSPServerError &ServerResult, std::vector<uint8_t> &Reply);

		virtual void get_OnOCSPValidationNeeded(TSBOCSPValidationNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOCSPValidationNeeded(TSBOCSPValidationNeededEvent pMethodValue, void * pDataValue);

		TElFileOCSPClient(TElFileOCSPClientHandle handle, TElOwnHandle ownHandle);

		explicit TElFileOCSPClient(TComponent &Owner);

		explicit TElFileOCSPClient(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELFILEOCSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
class TElCustomOCSPClientFactory: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomOCSPClientFactory)
	public:
		virtual bool SupportsLocation(const std::string &URI);

#ifdef SB_USE_CLASS_TELOCSPCLIENT
		virtual TElOCSPClientHandle GetClientInstance(TObject &Validator);

		virtual TElOCSPClientHandle GetClientInstance(TObject *Validator);
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

		TElCustomOCSPClientFactory(TElCustomOCSPClientFactoryHandle handle, TElOwnHandle ownHandle);

		TElCustomOCSPClientFactory();

};
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

#ifdef SB_USE_CLASS_TELOCSPCLIENTMANAGER
class TElOCSPClientManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElOCSPClientManager)
	public:
#ifdef SB_USE_CLASS_TELOCSPCLIENT
		TElOCSPClientHandle FindOCSPClientByLocation(const std::string &Location, TObject &Validator);

		TElOCSPClientHandle FindOCSPClientByLocation(const std::string &Location, TObject *Validator);
#endif /* SB_USE_CLASS_TELOCSPCLIENT */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
		void RegisterOCSPClientFactory(TElCustomOCSPClientFactory &Factory);

		void RegisterOCSPClientFactory(TElCustomOCSPClientFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

#ifdef SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY
		void UnregisterOCSPClientFactory(TElCustomOCSPClientFactory &Factory);

		void UnregisterOCSPClientFactory(TElCustomOCSPClientFactory *Factory);
#endif /* SB_USE_CLASS_TELCUSTOMOCSPCLIENTFACTORY */

		TElOCSPClientManager(TElOCSPClientManagerHandle handle, TElOwnHandle ownHandle);

		TElOCSPClientManager();

};
#endif /* SB_USE_CLASS_TELOCSPCLIENTMANAGER */

#ifdef SB_USE_GLOBAL_PROCS_OCSPCLIENT

#ifdef SB_USE_CLASS_TELOCSPCLIENTMANAGER
TElOCSPClientManagerHandle OCSPClientManagerAddRef();
#endif /* SB_USE_CLASS_TELOCSPCLIENTMANAGER */

void OCSPClientManagerRelease();

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
void GetOCSPCertID(TElX509Certificate &Cert, TElX509Certificate &Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash);
void GetOCSPCertID(TElX509Certificate *Cert, TElX509Certificate *Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

#ifdef SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE
void GetOCSPCertID(TElPKCS7Issuer &Signer, TElX509Certificate &Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash);
void GetOCSPCertID(TElPKCS7Issuer *Signer, TElX509Certificate *Issuer, int32_t DigestAlg, std::vector<uint8_t> &aIssuerNameHash, std::vector<uint8_t> &IssuerKeyHash);
#endif /* SB_USE_CLASSES_TELPKCS7ISSUER_AND_TELX509CERTIFICATE */

#endif /* SB_USE_GLOBAL_PROCS_OCSPCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_OCSPCLIENT
SB_IMPORT uint32_t SB_APIENTRY SBOCSPClient_OCSPClientManagerAddRef(TElOCSPClientManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBOCSPClient_OCSPClientManagerRelease(void);
SB_IMPORT uint32_t SB_APIENTRY SBOCSPClient_GetOCSPCertID(TElX509CertificateHandle Cert, TElX509CertificateHandle Issuer, int32_t DigestAlg, uint8_t paIssuerNameHash[], int32_t * szaIssuerNameHash, uint8_t pIssuerKeyHash[], int32_t * szIssuerKeyHash);
SB_IMPORT uint32_t SB_APIENTRY SBOCSPClient_GetOCSPCertID_1(TElPKCS7IssuerHandle Signer, TElX509CertificateHandle Issuer, int32_t DigestAlg, uint8_t paIssuerNameHash[], int32_t * szaIssuerNameHash, uint8_t pIssuerKeyHash[], int32_t * szIssuerKeyHash);
#endif /* SB_USE_GLOBAL_PROCS_OCSPCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOCSPCLIENT */

