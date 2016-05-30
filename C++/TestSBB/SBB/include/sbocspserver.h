#ifndef __INC_SBOCSPSERVER
#define __INC_SBOCSPSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbencoding.h"
#include "sbpem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbrdn.h"
#include "sbsha.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbocspcommon.h"
#include "sbpublickeycrypto.h"
#include "sbconstants.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElOCSPServerHandle;

typedef TElOCSPServerHandle ElOCSPServerHandle;

typedef uint8_t TSBOCSPServerOptionRaw;

typedef enum
{
	osoIncludeVersion = 0
} TSBOCSPServerOption;

typedef uint32_t TSBOCSPServerOptionsRaw;

typedef enum 
{
	f_osoIncludeVersion = 1
} TSBOCSPServerOptions;

#ifdef SB_USE_CLASS_TELOCSPSERVER
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_ProcessRequest(TElOCSPServerHandle _Handle, const uint8_t pRequest[], int32_t szRequest, uint8_t pReply[], int32_t * szReply, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_ResponderIdType(TElOCSPServerHandle _Handle, TElResponderIDTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_ResponderIdType(TElOCSPServerHandle _Handle, TElResponderIDTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_RequestCertificates(TElOCSPServerHandle _Handle, TElMemoryCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_SignatureAlgorithm(TElOCSPServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_SignatureAlgorithm(TElOCSPServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_ProducedAt(TElOCSPServerHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_ProducedAt(TElOCSPServerHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_SignatureRequired(TElOCSPServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_SignatureRequired(TElOCSPServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_Options(TElOCSPServerHandle _Handle, TSBOCSPServerOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_Options(TElOCSPServerHandle _Handle, TSBOCSPServerOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_IssuerHashAlgorithm(TElOCSPServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_IssuerHashAlgorithm(TElOCSPServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_OnCertificateCheck(TElOCSPServerHandle _Handle, TSBCertificateOCSPCheckEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_OnCertificateCheck(TElOCSPServerHandle _Handle, TSBCertificateOCSPCheckEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_get_OnSignatureValidate(TElOCSPServerHandle _Handle, TSBOCSPSignatureValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_set_OnSignatureValidate(TElOCSPServerHandle _Handle, TSBOCSPSignatureValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElOCSPServer_Create(TComponentHandle Owner, TElOCSPServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELOCSPSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElOCSPServer;
typedef TElOCSPServer ElOCSPServer;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBOCSPServerOptions)

#ifdef SB_USE_CLASS_TELOCSPSERVER
class TElOCSPServer: public TElOCSPClass
{
	private:
		SB_DISABLE_COPY(TElOCSPServer)
#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		TElMemoryCertStorage* _Inst_RequestCertificates;
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

		void initInstances();

	public:
		int32_t ProcessRequest(const std::vector<uint8_t> &Request, std::vector<uint8_t> &Reply);

		virtual TElResponderIDType get_ResponderIdType();

		virtual void set_ResponderIdType(TElResponderIDType Value);

		SB_DECLARE_PROPERTY(TElResponderIDType, get_ResponderIdType, set_ResponderIdType, TElOCSPServer, ResponderIdType);

#ifdef SB_USE_CLASS_TELMEMORYCERTSTORAGE
		virtual TElMemoryCertStorage* get_RequestCertificates();

		SB_DECLARE_PROPERTY_GET(TElMemoryCertStorage*, get_RequestCertificates, TElOCSPServer, RequestCertificates);
#endif /* SB_USE_CLASS_TELMEMORYCERTSTORAGE */

		virtual int32_t get_SignatureAlgorithm();

		virtual void set_SignatureAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SignatureAlgorithm, set_SignatureAlgorithm, TElOCSPServer, SignatureAlgorithm);

		virtual int64_t get_ProducedAt();

		virtual void set_ProducedAt(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_ProducedAt, set_ProducedAt, TElOCSPServer, ProducedAt);

		virtual bool get_SignatureRequired();

		virtual void set_SignatureRequired(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignatureRequired, set_SignatureRequired, TElOCSPServer, SignatureRequired);

		virtual TSBOCSPServerOptions get_Options();

		virtual void set_Options(TSBOCSPServerOptions Value);

		SB_DECLARE_PROPERTY(TSBOCSPServerOptions, get_Options, set_Options, TElOCSPServer, Options);

		virtual int32_t get_IssuerHashAlgorithm();

		virtual void set_IssuerHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_IssuerHashAlgorithm, set_IssuerHashAlgorithm, TElOCSPServer, IssuerHashAlgorithm);

		virtual void get_OnCertificateCheck(TSBCertificateOCSPCheckEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateCheck(TSBCertificateOCSPCheckEvent pMethodValue, void * pDataValue);

		virtual void get_OnSignatureValidate(TSBOCSPSignatureValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSignatureValidate(TSBOCSPSignatureValidateEvent pMethodValue, void * pDataValue);

		TElOCSPServer(TElOCSPServerHandle handle, TElOwnHandle ownHandle);

		explicit TElOCSPServer(TComponent &Owner);

		explicit TElOCSPServer(TComponent *Owner);

		virtual ~TElOCSPServer();

};
#endif /* SB_USE_CLASS_TELOCSPSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBOCSPSERVER */

