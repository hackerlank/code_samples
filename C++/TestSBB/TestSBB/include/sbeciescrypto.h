#ifndef __INC_SBECIESCRYPTO
#define __INC_SBECIESCRYPTO

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstrutils.h"
#include "sbcustomcrypto.h"
#include "sbmath.h"
#include "sbecmath.h"
#include "sbeccommon.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbcryptoprovrs.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbsymmetriccrypto.h"
#include "sbpublickeycrypto.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElECIESCryptoHandle;

typedef TElECIESCryptoHandle ElECIESCryptoHandle;

typedef uint8_t TSBECIESKATypeRaw;

typedef enum
{
	katPoint = 0,
	katCoordinate = 1,
	katHashPoint = 2,
	katHashCoordinate = 3
} TSBECIESKAType;

typedef uint8_t TSBECIESKDFTypeRaw;

typedef enum
{
	ktKDF1 = 0,
	ktKDF2 = 1
} TSBECIESKDFType;

typedef uint8_t TSBECIESKDFInterpretationRaw;

typedef enum
{
	kiEncMac = 0,
	kiMacEnc = 1
} TSBECIESKDFInterpretation;

typedef TElClassHandle TElECIESCryptoClassHandle;

typedef TElECIESCryptoClassHandle ElECIESCryptoClassHandle;

#ifdef SB_USE_CLASS_TELECIESCRYPTO
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsEncAlgorithmSupported(int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsEncAlgorithmSupported_1(TElECIESCryptoHandle _Handle, int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsHashAlgorithmSupported(int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsHashAlgorithmSupported_1(TElECIESCryptoHandle _Handle, int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsMACAlgorithmSupported(int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_IsMACAlgorithmSupported_1(TElECIESCryptoHandle _Handle, int32_t AlgID, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_InitializeEncryption(TElECIESCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Encrypt(TElECIESCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Encrypt_1(TElECIESCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_EncryptUpdate(TElECIESCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_FinalizeEncryption(TElECIESCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_InitializeDecryption(TElECIESCryptoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Decrypt(TElECIESCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Decrypt_1(TElECIESCryptoHandle _Handle, TStreamHandle InStream, TStreamHandle OutStream, int32_t InCount, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_DecryptUpdate(TElECIESCryptoHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_FinalizeDecryption(TElECIESCryptoHandle _Handle, void * OutBuffer, int32_t * OutSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_EncryptionAlgorithm(TElECIESCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_HashAlgorithm(TElECIESCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_MACAlgorithm(TElECIESCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_TagSize(TElECIESCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_Padding(TElECIESCryptoHandle _Handle, TSBSymmetricCipherPaddingRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_Padding(TElECIESCryptoHandle _Handle, TSBSymmetricCipherPaddingRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_MACKeySize(TElECIESCryptoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_MACKeySize(TElECIESCryptoHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_KeyAgreementType(TElECIESCryptoHandle _Handle, TSBECIESKATypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_KeyAgreementType(TElECIESCryptoHandle _Handle, TSBECIESKATypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_KDFType(TElECIESCryptoHandle _Handle, TSBECIESKDFTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_KDFType(TElECIESCryptoHandle _Handle, TSBECIESKDFTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_KDFInterpretation(TElECIESCryptoHandle _Handle, TSBECIESKDFInterpretationRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_KDFInterpretation(TElECIESCryptoHandle _Handle, TSBECIESKDFInterpretationRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_KDFOptionalInfo(TElECIESCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_KDFOptionalInfo(TElECIESCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_MACOptionalInfo(TElECIESCryptoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_MACOptionalInfo(TElECIESCryptoHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_KeyMaterial(TElECIESCryptoHandle _Handle, TElECKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_KeyMaterial(TElECIESCryptoHandle _Handle, TElECKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_CryptoProvider(TElECIESCryptoHandle _Handle, TElCustomCryptoProviderHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_CryptoProvider(TElECIESCryptoHandle _Handle, TElCustomCryptoProviderHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_CryptoProviderManager(TElECIESCryptoHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_CryptoProviderManager(TElECIESCryptoHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_UseCofactor(TElECIESCryptoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_UseCofactor(TElECIESCryptoHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_get_OnProgress(TElECIESCryptoHandle _Handle, TSBProgressEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_set_OnProgress(TElECIESCryptoHandle _Handle, TSBProgressEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_1(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_2(int32_t EncAlgID, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_3(TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_4(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_5(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_6(int32_t EncAlgID, TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECIESCrypto_Create_7(TElCustomCryptoProviderManagerHandle Manager, TElCustomCryptoProviderHandle CryptoProvider, TElECIESCryptoHandle * OutResult);
#endif /* SB_USE_CLASS_TELECIESCRYPTO */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElECIESCrypto;
typedef TElECIESCrypto ElECIESCrypto;

#ifdef SB_USE_CLASS_TELECIESCRYPTO
class TElECIESCrypto: public TElCustomCrypto
{
	private:
		SB_DISABLE_COPY(TElECIESCrypto)
#ifdef SB_USE_CLASS_TELECKEYMATERIAL
		TElECKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElCustomCryptoProvider* _Inst_CryptoProvider;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		static bool IsEncAlgorithmSupported(int32_t AlgID);

		bool IsEncAlgorithmSupported_Inst(int32_t AlgID);

		static bool IsHashAlgorithmSupported(int32_t AlgID);

		bool IsHashAlgorithmSupported_Inst(int32_t AlgID);

		static bool IsMACAlgorithmSupported(int32_t AlgID);

		bool IsMACAlgorithmSupported_Inst(int32_t AlgID);

		void InitializeEncryption();

		void Encrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		void Encrypt(TStream &InStream, TStream &OutStream);

		void Encrypt(TStream *InStream, TStream *OutStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void EncryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		void FinalizeEncryption(void * OutBuffer, int32_t &OutSize);

		void InitializeDecryption();

		bool Decrypt(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

#ifdef SB_USE_CLASS_TSTREAM
		bool Decrypt(TStream &InStream, TStream &OutStream, int32_t InCount);

		bool Decrypt(TStream *InStream, TStream *OutStream, int32_t InCount);
#endif /* SB_USE_CLASS_TSTREAM */

		void DecryptUpdate(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize);

		bool FinalizeDecryption(void * OutBuffer, int32_t &OutSize);

		static TClassHandle ClassType();

		virtual int32_t get_EncryptionAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_EncryptionAlgorithm, TElECIESCrypto, EncryptionAlgorithm);

		virtual int32_t get_HashAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HashAlgorithm, TElECIESCrypto, HashAlgorithm);

		virtual int32_t get_MACAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MACAlgorithm, TElECIESCrypto, MACAlgorithm);

		virtual int32_t get_TagSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_TagSize, TElECIESCrypto, TagSize);

		virtual TSBSymmetricCipherPadding get_Padding();

		virtual void set_Padding(TSBSymmetricCipherPadding Value);

		SB_DECLARE_PROPERTY(TSBSymmetricCipherPadding, get_Padding, set_Padding, TElECIESCrypto, Padding);

		virtual int32_t get_MACKeySize();

		virtual void set_MACKeySize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MACKeySize, set_MACKeySize, TElECIESCrypto, MACKeySize);

		virtual TSBECIESKAType get_KeyAgreementType();

		virtual void set_KeyAgreementType(TSBECIESKAType Value);

		SB_DECLARE_PROPERTY(TSBECIESKAType, get_KeyAgreementType, set_KeyAgreementType, TElECIESCrypto, KeyAgreementType);

		virtual TSBECIESKDFType get_KDFType();

		virtual void set_KDFType(TSBECIESKDFType Value);

		SB_DECLARE_PROPERTY(TSBECIESKDFType, get_KDFType, set_KDFType, TElECIESCrypto, KDFType);

		virtual TSBECIESKDFInterpretation get_KDFInterpretation();

		virtual void set_KDFInterpretation(TSBECIESKDFInterpretation Value);

		SB_DECLARE_PROPERTY(TSBECIESKDFInterpretation, get_KDFInterpretation, set_KDFInterpretation, TElECIESCrypto, KDFInterpretation);

		virtual void get_KDFOptionalInfo(std::vector<uint8_t> &OutResult);

		virtual void set_KDFOptionalInfo(const std::vector<uint8_t> &Value);

		virtual void get_MACOptionalInfo(std::vector<uint8_t> &OutResult);

		virtual void set_MACOptionalInfo(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELECKEYMATERIAL
		virtual TElECKeyMaterial* get_KeyMaterial();

		virtual void set_KeyMaterial(TElECKeyMaterial &Value);

		virtual void set_KeyMaterial(TElECKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElECKeyMaterial*, get_KeyMaterial, set_KeyMaterial, TElECIESCrypto, KeyMaterial);
#endif /* SB_USE_CLASS_TELECKEYMATERIAL */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		virtual TElCustomCryptoProvider* get_CryptoProvider();

		virtual void set_CryptoProvider(TElCustomCryptoProvider &Value);

		virtual void set_CryptoProvider(TElCustomCryptoProvider *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProvider*, get_CryptoProvider, set_CryptoProvider, TElECIESCrypto, CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElECIESCrypto, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_UseCofactor();

		virtual void set_UseCofactor(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseCofactor, set_UseCofactor, TElECIESCrypto, UseCofactor);

		virtual void get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue);

		TElECIESCrypto(TElECIESCryptoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER
		explicit TElECIESCrypto(TElCustomCryptoProvider &CryptoProvider);

		explicit TElECIESCrypto(TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, int32_t MACAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, int32_t HashAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(int32_t EncAlgID, TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElECIESCrypto(TElCustomCryptoProviderManager &Manager, TElCustomCryptoProvider &CryptoProvider);

		TElECIESCrypto(TElCustomCryptoProviderManager *Manager, TElCustomCryptoProvider *CryptoProvider);
#endif /* SB_USE_CLASSES_TELCUSTOMCRYPTOPROVIDER_AND_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual ~TElECIESCrypto();

};
#endif /* SB_USE_CLASS_TELECIESCRYPTO */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBECIESCRYPTO */

