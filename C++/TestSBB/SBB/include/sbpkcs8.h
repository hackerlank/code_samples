#ifndef __INC_SBPKCS8
#define __INC_SBPKCS8

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbpkcs5.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbpem.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_ERROR_FACILITY_PKCS8 	8960
#define SB_PKCS8_ERROR_OK 	0
#define SB_PKCS8_ERROR_INVALID_ASN_DATA 	8961
#define SB_PKCS8_ERROR_INVALID_FORMAT 	8962
#define SB_PKCS8_ERROR_UNSUPPORTED_ALGORITHM 	8963
#define SB_PKCS8_ERROR_INVALID_PASSWORD 	8964
#define SB_PKCS8_ERROR_INVALID_VERSION 	8965
#define SB_PKCS8_ERROR_INVALID_PARAMETER 	8966
#define SB_PKCS8_ERROR_UNKNOWN 	8967
#define SB_PKCS8_ERROR_BUFFER_TOO_SMALL 	8968
#define SB_PKCS8_ERROR_NO_PRIVATE_KEY 	8969

typedef TElClassHandle TElPKCS8EncryptedPrivateKeyInfoHandle;

typedef TElClassHandle TElPKCS8PrivateKeyInfoHandle;

typedef TElClassHandle TElPKCS8PrivateKeyHandle;

#ifdef SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_LoadFromBuffer(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_SaveToBuffer(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_LoadFromStream(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_SaveToStream(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_LoadFromTag(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, TElASN1ConstrainedTagHandle Tag, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_SaveToTag(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, TElASN1ConstrainedTagHandle Tag, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_get_EncryptionAlgorithm(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_set_EncryptionAlgorithm(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_get_EncryptionAlgorithmParams(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_set_EncryptionAlgorithmParams(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_get_EncryptedData(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_set_EncryptedData(TElPKCS8EncryptedPrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8EncryptedPrivateKeyInfo_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_LoadFromBuffer(TElPKCS8PrivateKeyInfoHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_SaveToBuffer(TElPKCS8PrivateKeyInfoHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_LoadFromStream(TElPKCS8PrivateKeyInfoHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_SaveToStream(TElPKCS8PrivateKeyInfoHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_get_PrivateKeyAlgorithm(TElPKCS8PrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_set_PrivateKeyAlgorithm(TElPKCS8PrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_get_PrivateKeyAlgorithmParams(TElPKCS8PrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_set_PrivateKeyAlgorithmParams(TElPKCS8PrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_get_PrivateKey(TElPKCS8PrivateKeyInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_set_PrivateKey(TElPKCS8PrivateKeyInfoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKeyInfo_Create(TElPKCS8PrivateKeyInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEY
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_LoadFromBuffer(TElPKCS8PrivateKeyHandle _Handle, void * Buffer, int32_t Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_SaveToBuffer(TElPKCS8PrivateKeyHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassphrase, int32_t szPassphrase, int8_t UsePEMEnvelope, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_LoadFromStream(TElPKCS8PrivateKeyHandle _Handle, TStreamHandle Stream, const char * pcPassphrase, int32_t szPassphrase, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_SaveToStream(TElPKCS8PrivateKeyHandle _Handle, TStreamHandle Stream, const char * pcPassphrase, int32_t szPassphrase, int8_t UsePEMEnvelope, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_get_SymmetricAlgorithm(TElPKCS8PrivateKeyHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_set_SymmetricAlgorithm(TElPKCS8PrivateKeyHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_get_UseNewFeatures(TElPKCS8PrivateKeyHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_set_UseNewFeatures(TElPKCS8PrivateKeyHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_get_KeyMaterial(TElPKCS8PrivateKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_set_KeyMaterial(TElPKCS8PrivateKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_get_KeyAlgorithm(TElPKCS8PrivateKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_set_KeyAlgorithm(TElPKCS8PrivateKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_get_KeyAlgorithmParams(TElPKCS8PrivateKeyHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_set_KeyAlgorithmParams(TElPKCS8PrivateKeyHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElPKCS8PrivateKey_Create(TElPKCS8PrivateKeyHandle * OutResult);
#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEY */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElPKCS8EncryptedPrivateKeyInfo;
class TElPKCS8PrivateKeyInfo;
class TElPKCS8PrivateKey;

#ifdef SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO
class TElPKCS8EncryptedPrivateKeyInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS8EncryptedPrivateKeyInfo)
	public:
		int32_t LoadFromBuffer(void * Buffer, int32_t Size);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, int32_t Count);

		int32_t LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStream(TStream &Stream);

		bool SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		int32_t LoadFromTag(TElASN1ConstrainedTag &Tag);

		int32_t LoadFromTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

#ifdef SB_USE_CLASS_TELASN1CONSTRAINEDTAG
		bool SaveToTag(TElASN1ConstrainedTag &Tag);

		bool SaveToTag(TElASN1ConstrainedTag *Tag);
#endif /* SB_USE_CLASS_TELASN1CONSTRAINEDTAG */

		virtual void get_EncryptionAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptionAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_EncryptionAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptionAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_EncryptedData(std::vector<uint8_t> &OutResult);

		virtual void set_EncryptedData(const std::vector<uint8_t> &Value);

		TElPKCS8EncryptedPrivateKeyInfo(TElPKCS8EncryptedPrivateKeyInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS8EncryptedPrivateKeyInfo();

};
#endif /* SB_USE_CLASS_TELPKCS8ENCRYPTEDPRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO
class TElPKCS8PrivateKeyInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS8PrivateKeyInfo)
	public:
		int32_t LoadFromBuffer(void * Buffer, int32_t Size);

		bool SaveToBuffer(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, int32_t Count);

		int32_t LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool SaveToStream(TStream &Stream);

		bool SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void get_PrivateKeyAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_PrivateKeyAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_PrivateKeyAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_PrivateKeyAlgorithmParams(const std::vector<uint8_t> &Value);

		virtual void get_PrivateKey(std::vector<uint8_t> &OutResult);

		virtual void set_PrivateKey(const std::vector<uint8_t> &Value);

		TElPKCS8PrivateKeyInfo(TElPKCS8PrivateKeyInfoHandle handle, TElOwnHandle ownHandle);

		TElPKCS8PrivateKeyInfo();

};
#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEYINFO */

#ifdef SB_USE_CLASS_TELPKCS8PRIVATEKEY
class TElPKCS8PrivateKey: public TObject
{
	private:
		SB_DISABLE_COPY(TElPKCS8PrivateKey)
	public:
		int32_t LoadFromBuffer(void * Buffer, int32_t Size, const std::string &Passphrase);

		int32_t SaveToBuffer(void * Buffer, int32_t &Size, const std::string &Passphrase, bool UsePEMEnvelope);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadFromStream(TStream &Stream, const std::string &Passphrase, int32_t Count);

		int32_t LoadFromStream(TStream *Stream, const std::string &Passphrase, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveToStream(TStream &Stream, const std::string &Passphrase, bool UsePEMEnvelope);

		int32_t SaveToStream(TStream *Stream, const std::string &Passphrase, bool UsePEMEnvelope);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual int32_t get_SymmetricAlgorithm();

		virtual void set_SymmetricAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_SymmetricAlgorithm, set_SymmetricAlgorithm, TElPKCS8PrivateKey, SymmetricAlgorithm);

		virtual bool get_UseNewFeatures();

		virtual void set_UseNewFeatures(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseNewFeatures, set_UseNewFeatures, TElPKCS8PrivateKey, UseNewFeatures);

		virtual void get_KeyMaterial(std::vector<uint8_t> &OutResult);

		virtual void set_KeyMaterial(const std::vector<uint8_t> &Value);

		virtual void get_KeyAlgorithm(std::vector<uint8_t> &OutResult);

		virtual void set_KeyAlgorithm(const std::vector<uint8_t> &Value);

		virtual void get_KeyAlgorithmParams(std::vector<uint8_t> &OutResult);

		virtual void set_KeyAlgorithmParams(const std::vector<uint8_t> &Value);

		TElPKCS8PrivateKey(TElPKCS8PrivateKeyHandle handle, TElOwnHandle ownHandle);

		TElPKCS8PrivateKey();

};
#endif /* SB_USE_CLASS_TELPKCS8PRIVATEKEY */

#ifdef SB_USE_GLOBAL_PROCS_PKCS8

void RaisePKCS8Error(int32_t ErrorCode);

#endif /* SB_USE_GLOBAL_PROCS_PKCS8 */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_PKCS8
SB_IMPORT uint32_t SB_APIENTRY SBPKCS8_RaisePKCS8Error(int32_t ErrorCode);
#endif /* SB_USE_GLOBAL_PROCS_PKCS8 */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS8 */

