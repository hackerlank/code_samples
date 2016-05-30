#ifndef __INC_SBPGPTLS
#define __INC_SBPGPTLS

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbpgputils.h"
#include "sbpgpstreams.h"
#include "sbpgpkeys.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbpublickeycrypto.h"
#include "sbcustomcrypto.h"
#include "sbpgpconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSSLPGPCertificateTypeHandlerHandle;

typedef TElClassHandle TElSSLClientPGPCertificateTypeHandlerHandle;

typedef TElClassHandle TElSSLServerPGPCertificateTypeHandlerHandle;

typedef uint8_t TSBPGPKeyDescriptorTypeRaw;

typedef enum
{
	kdtFingerprint = 0,
	kdtKey = 1
} TSBPGPKeyDescriptorType;

typedef uint8_t TSBPGPKeyAlgorithmTypeRaw;

typedef enum
{
	katRSA = 0,
	katDHE_DSS = 1,
	katDHE_RSA = 2
} TSBPGPKeyAlgorithmType;

typedef void (SB_CALLBACK *TElPGPSSLKeyFindEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pKeyFP[], int32_t szKeyFP, TElPGPPublicKeyHandle * Key);

typedef void (SB_CALLBACK *TElPGPSSLKeyValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElPGPPublicKeyHandle Key, TSBPGPSignatureValidityRaw * Validity);

#ifdef SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetCertificateType(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_ValidateRemoteCert(TElSSLPGPCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t Optional, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetRemoteKeyMaterial(TElSSLPGPCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t KeyType, int32_t * PKType, int32_t * KeyAlgorithm, TElKeyMaterialHandle * KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetKeyMaterial(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetPublicKeySize(TElSSLPGPCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetDataForRemote(TElSSLPGPCertificateTypeHandlerHandle _Handle, int32_t CipherSuite, TSBKeyExchangeAlgorithmRaw KeyExchange, uint8_t pData[], int32_t * szData, int32_t Optional, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_GetPublicKeyAlgorithm(TElSSLPGPCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_get_Keyring(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPKeyringHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_set_Keyring(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPKeyringHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_get_OnKeyFind(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPSSLKeyFindEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_set_OnKeyFind(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPSSLKeyFindEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_get_OnKeyValidate(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPSSLKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_set_OnKeyValidate(TElSSLPGPCertificateTypeHandlerHandle _Handle, TElPGPSSLKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLPGPCertificateTypeHandler_Create(TComponentHandle AOwner, TElSSLPGPCertificateTypeHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLClientPGPCertificateTypeHandler_Create(TComponentHandle AOwner, TElSSLPGPCertificateTypeHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerPGPCertificateTypeHandler_get_KeyDescriptorType(TElSSLServerPGPCertificateTypeHandlerHandle _Handle, TSBPGPKeyDescriptorTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerPGPCertificateTypeHandler_set_KeyDescriptorType(TElSSLServerPGPCertificateTypeHandlerHandle _Handle, TSBPGPKeyDescriptorTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerPGPCertificateTypeHandler_Create(TComponentHandle AOwner, TElSSLServerPGPCertificateTypeHandlerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSLPGPCertificateTypeHandler;
class TElSSLClientPGPCertificateTypeHandler;
class TElSSLServerPGPCertificateTypeHandler;

#ifdef SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER
class TElSSLPGPCertificateTypeHandler: public TElSSLCertificateTypeHandler
{
	private:
		SB_DISABLE_COPY(TElSSLPGPCertificateTypeHandler)
#ifdef SB_USE_CLASS_TELPGPKEYRING
		TElPGPKeyring* _Inst_Keyring;
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		void initInstances();

	public:
		virtual TElSSLCertificateType GetCertificateType();

		virtual bool ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual void GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle GetKeyMaterial();
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		virtual int32_t GetPublicKeySize();

		virtual int32_t GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional);

		virtual int32_t GetPublicKeyAlgorithm();

#ifdef SB_USE_CLASS_TELPGPKEYRING
		virtual TElPGPKeyring* get_Keyring();

		virtual void set_Keyring(TElPGPKeyring &Value);

		virtual void set_Keyring(TElPGPKeyring *Value);

		SB_DECLARE_PROPERTY(TElPGPKeyring*, get_Keyring, set_Keyring, TElSSLPGPCertificateTypeHandler, Keyring);
#endif /* SB_USE_CLASS_TELPGPKEYRING */

		virtual void get_OnKeyFind(TElPGPSSLKeyFindEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyFind(TElPGPSSLKeyFindEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyValidate(TElPGPSSLKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TElPGPSSLKeyValidateEvent pMethodValue, void * pDataValue);

		TElSSLPGPCertificateTypeHandler(TElSSLPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLPGPCertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLPGPCertificateTypeHandler(TComponent *AOwner);

		virtual ~TElSSLPGPCertificateTypeHandler();

};
#endif /* SB_USE_CLASS_TELSSLPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER
class TElSSLClientPGPCertificateTypeHandler: public TElSSLPGPCertificateTypeHandler
{
	private:
		SB_DISABLE_COPY(TElSSLClientPGPCertificateTypeHandler)
	public:
		TElSSLClientPGPCertificateTypeHandler(TElSSLClientPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLClientPGPCertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLClientPGPCertificateTypeHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSLCLIENTPGPCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER
class TElSSLServerPGPCertificateTypeHandler: public TElSSLPGPCertificateTypeHandler
{
	private:
		SB_DISABLE_COPY(TElSSLServerPGPCertificateTypeHandler)
	public:
		virtual TSBPGPKeyDescriptorType get_KeyDescriptorType();

		virtual void set_KeyDescriptorType(TSBPGPKeyDescriptorType Value);

		SB_DECLARE_PROPERTY(TSBPGPKeyDescriptorType, get_KeyDescriptorType, set_KeyDescriptorType, TElSSLServerPGPCertificateTypeHandler, KeyDescriptorType);

		TElSSLServerPGPCertificateTypeHandler(TElSSLServerPGPCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLServerPGPCertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLServerPGPCertificateTypeHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSLSERVERPGPCERTIFICATETYPEHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPTLS */

