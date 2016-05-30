#ifndef __INC_SBPGPSSH
#define __INC_SBPGPSSH

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbhashfunction.h"
#include "sbsha.h"
#include "sbsshcommon.h"
#include "sbsshconstants.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbpgputils.h"
#include "sbpgpstreams.h"
#include "sbpgpkeys.h"
#include "sbx509.h"
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
typedef TElClassHandle TElSSHPGPKeyHandle;

typedef TElSSHPGPKeyHandle ElSSHPGPKeyHandle;

typedef TElClassHandle TElSSHPGPAuthHandlerHandle;

typedef TElSSHPGPAuthHandlerHandle ElSSHPGPAuthHandlerHandle;

#ifdef SB_USE_CLASS_TELSSHPGPKEY
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_Copy(TElSSHPGPKeyHandle _Handle, TElSSHKeyHandle * Dest);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_Clear(TElSSHPGPKeyHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_Import(TElSSHPGPKeyHandle _Handle, TElPGPPublicKeyHandle PubKey);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_Import_1(TElSSHPGPKeyHandle _Handle, TElPGPSecretKeyHandle SecKey);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_get_PGPPublicKey(TElSSHPGPKeyHandle _Handle, TElPGPPublicKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_get_PGPSecretKey(TElSSHPGPKeyHandle _Handle, TElPGPSecretKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPKey_Create(TElSSHKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPGPKEY */

#ifdef SB_USE_CLASS_TELSSHPGPAUTHHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_GetAlgorithmFromClientKexDHReply(TElSSHPGPAuthHandlerHandle _Handle, const uint8_t pHostAlg[], int32_t szHostAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_ValidateServerSignature(TElSSHPGPAuthHandlerHandle _Handle, int32_t Algorithm, const uint8_t pPubKeyStr[], int32_t szPubKeyStr, const uint8_t pSignature[], int32_t szSignature, const uint8_t pHash[], int32_t szHash, int32_t HashAlg, int32_t * ErrCode, char * pcErrMessage, int32_t * szErrMessage, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_FindKeyByAlgorithm(TElSSHPGPAuthHandlerHandle _Handle, TElSSHCustomKeyStorageHandle Storage, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_GetKeyBlob(TElSSHPGPAuthHandlerHandle _Handle, TElSSHKeyHandle Key, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_KeyBlobToKey(TElSSHPGPAuthHandlerHandle _Handle, const char * pcAlgName, int32_t szAlgName, const uint8_t pBlob[], int32_t szBlob, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_HashAlgFromKey(TElSSHPGPAuthHandlerHandle _Handle, TElSSHKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_CalculateServerSignature(TElSSHPGPAuthHandlerHandle _Handle, TElSSHKeyHandle Key, const uint8_t paHash[], int32_t szaHash, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_ServerValidateClientSignature(TElSSHPGPAuthHandlerHandle _Handle, const uint8_t pAlgName[], int32_t szAlgName, const uint8_t pKeyBlob[], int32_t szKeyBlob, const uint8_t pSignature[], int32_t szSignature, const uint8_t pHash[], int32_t szHash, int8_t * Valid, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPGPAuthHandler_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPGPAUTHHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHPGPKey;
typedef TElSSHPGPKey ElSSHPGPKey;
class TElSSHPGPAuthHandler;
typedef TElSSHPGPAuthHandler ElSSHPGPAuthHandler;

#ifdef SB_USE_CLASS_TELSSHPGPKEY
class TElSSHPGPKey: public TElSSHKey
{
	private:
		SB_DISABLE_COPY(TElSSHPGPKey)
#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		TElPGPPublicKey* _Inst_PGPPublicKey;
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */
#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		TElPGPSecretKey* _Inst_PGPSecretKey;
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		void initInstances();

	public:
		virtual void Copy(TElSSHKey &Dest);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		void Import(TElPGPPublicKey &PubKey);

		void Import(TElPGPPublicKey *PubKey);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		void Import(TElPGPSecretKey &SecKey);

		void Import(TElPGPSecretKey *SecKey);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

#ifdef SB_USE_CLASS_TELPGPPUBLICKEY
		virtual TElPGPPublicKey* get_PGPPublicKey();

		SB_DECLARE_PROPERTY_GET(TElPGPPublicKey*, get_PGPPublicKey, TElSSHPGPKey, PGPPublicKey);
#endif /* SB_USE_CLASS_TELPGPPUBLICKEY */

#ifdef SB_USE_CLASS_TELPGPSECRETKEY
		virtual TElPGPSecretKey* get_PGPSecretKey();

		SB_DECLARE_PROPERTY_GET(TElPGPSecretKey*, get_PGPSecretKey, TElSSHPGPKey, PGPSecretKey);
#endif /* SB_USE_CLASS_TELPGPSECRETKEY */

		TElSSHPGPKey(TElSSHPGPKeyHandle handle, TElOwnHandle ownHandle);

		TElSSHPGPKey();

		virtual ~TElSSHPGPKey();

};
#endif /* SB_USE_CLASS_TELSSHPGPKEY */

#ifdef SB_USE_CLASS_TELSSHPGPAUTHHANDLER
class TElSSHPGPAuthHandler: public TElSSHAuthHandler
{
	private:
		SB_DISABLE_COPY(TElSSHPGPAuthHandler)
	public:
		virtual int32_t GetAlgorithmFromClientKexDHReply(const std::vector<uint8_t> &HostAlg);

		virtual bool ValidateServerSignature(int32_t Algorithm, const std::vector<uint8_t> &PubKeyStr, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, int32_t HashAlg, int32_t &ErrCode, std::string &ErrMessage);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual int32_t FindKeyByAlgorithm(TElSSHCustomKeyStorage &Storage, int32_t Algorithm);

		virtual int32_t FindKeyByAlgorithm(TElSSHCustomKeyStorage *Storage, int32_t Algorithm);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void GetKeyBlob(TElSSHKey &Key, std::vector<uint8_t> &OutResult);

		virtual void GetKeyBlob(TElSSHKey *Key, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKeyHandle KeyBlobToKey(const std::string &AlgName, const std::vector<uint8_t> &Blob);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual int32_t HashAlgFromKey(TElSSHKey &Key);

		virtual int32_t HashAlgFromKey(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void CalculateServerSignature(TElSSHKey &Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult);

		virtual void CalculateServerSignature(TElSSHKey *Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual bool ServerValidateClientSignature(const std::vector<uint8_t> &AlgName, const std::vector<uint8_t> &KeyBlob, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, bool &Valid);

		TElSSHPGPAuthHandler(TElSSHPGPAuthHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHPGPAuthHandler(TComponent &AOwner);

		explicit TElSSHPGPAuthHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHPGPAUTHHANDLER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPGPSSH */

