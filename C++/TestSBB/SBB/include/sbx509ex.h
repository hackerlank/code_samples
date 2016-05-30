#ifndef __INC_SBX509EX
#define __INC_SBX509EX

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbrdn.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbpkcs10.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbpkiasync.h"
#include "sbalgorithmidentifier.h"
#include "sbhashfunction.h"
#include "sbconstants.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElX509CertificateExHandle;

#ifdef SB_USE_CLASS_TELX509CERTIFICATEEX
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_WriteIssuer(TElX509CertificateExHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_WriteSubject(TElX509CertificateExHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetIssuer(TElX509CertificateExHandle _Handle, const TName * Issuer);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetSubject(TElX509CertificateExHandle _Handle, const TName * Subject);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetLongSerialNumber(TElX509CertificateExHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate(TElX509CertificateExHandle _Handle, int32_t Algorithm, int32_t DWordsInEncryptKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate_1(TElX509CertificateExHandle _Handle, TElCertificateRequestHandle Request, TElX509CertificateExHandle Certificate);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate_2(TElX509CertificateExHandle _Handle, TElCertificateRequestHandle Request, TElX509CertificateExHandle Certificate, TElAlgorithmIdentifierHandle SignatureAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate_3(TElX509CertificateExHandle _Handle, TElX509CertificateHandle Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate_4(TElX509CertificateExHandle _Handle, TElAlgorithmIdentifierHandle KeyAlgorithm, TElAlgorithmIdentifierHandle SignatureAlgorithm, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Generate_5(TElX509CertificateExHandle _Handle, TElX509CertificateHandle Parent, TElAlgorithmIdentifierHandle KeyAlgorithm, TElAlgorithmIdentifierHandle SignatureAlgorithm, int32_t Bits);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_CAGenerate(TElX509CertificateExHandle _Handle, int32_t Algorithm, int32_t DWordsInEncryptKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_BeginGenerate(TElX509CertificateExHandle _Handle, int32_t Algorithm, int32_t DWordsInEncryptKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_BeginGenerate_1(TElX509CertificateExHandle _Handle, TElX509CertificateHandle Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_EndGenerate(TElX509CertificateExHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_CancelGeneration(TElX509CertificateExHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_AsyncOperationFinished(TElX509CertificateExHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetCACertificate(TElX509CertificateExHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetCACertificate_1(TElX509CertificateExHandle _Handle, TElX509CertificateHandle Cert);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_SetCAPrivateKey(TElX509CertificateExHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Sign(TElX509CertificateExHandle _Handle, void * InBuffer, int32_t InSize, void * OutBuffer, int32_t * OutSize, int8_t Detached, int8_t IncludeCertificates, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Verify(TElX509CertificateExHandle _Handle, void * InBuffer, int32_t InSize, void * Signature, int32_t SignatureSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_get_PreserveKeyMaterial(TElX509CertificateExHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_set_PreserveKeyMaterial(TElX509CertificateExHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_get_AltKeyID(TElX509CertificateExHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_set_AltKeyID(TElX509CertificateExHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_get_PreferredHashAlgorithm(TElX509CertificateExHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_set_PreferredHashAlgorithm(TElX509CertificateExHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_get_SaveDefaultASN1Tags(TElX509CertificateExHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_set_SaveDefaultASN1Tags(TElX509CertificateExHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX509CertificateEx_Create(TComponentHandle Owner, TElX509CertificateExHandle * OutResult);
#endif /* SB_USE_CLASS_TELX509CERTIFICATEEX */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElX509CertificateEx;

#ifdef SB_USE_CLASS_TELX509CERTIFICATEEX
class TElX509CertificateEx: public TElX509Certificate
{
	private:
		SB_DISABLE_COPY(TElX509CertificateEx)
	public:
		virtual void WriteIssuer(std::vector<uint8_t> &OutResult);

		virtual void WriteSubject(std::vector<uint8_t> &OutResult);

		void SetIssuer(const TName &Issuer);

		void SetSubject(const TName &Subject);

		void SetLongSerialNumber(const std::vector<uint8_t> &Value);

		void Generate(int32_t Algorithm, int32_t DWordsInEncryptKey);

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
		void Generate(TElCertificateRequest &Request, TElX509CertificateEx &Certificate);

		void Generate(TElCertificateRequest *Request, TElX509CertificateEx *Certificate);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef SB_USE_CLASSES_TELALGORITHMIDENTIFIER_AND_TELCERTIFICATEREQUEST
		void Generate(TElCertificateRequest &Request, TElX509CertificateEx &Certificate, TElAlgorithmIdentifier &SignatureAlgorithm);

		void Generate(TElCertificateRequest *Request, TElX509CertificateEx *Certificate, TElAlgorithmIdentifier *SignatureAlgorithm);
#endif /* SB_USE_CLASSES_TELALGORITHMIDENTIFIER_AND_TELCERTIFICATEREQUEST */

		void Generate(TElX509Certificate &Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);

		void Generate(TElX509Certificate *Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		void Generate(TElAlgorithmIdentifier &KeyAlgorithm, TElAlgorithmIdentifier &SignatureAlgorithm, int32_t Bits);

		void Generate(TElAlgorithmIdentifier *KeyAlgorithm, TElAlgorithmIdentifier *SignatureAlgorithm, int32_t Bits);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		void Generate(TElX509Certificate &Parent, TElAlgorithmIdentifier &KeyAlgorithm, TElAlgorithmIdentifier &SignatureAlgorithm, int32_t Bits);

		void Generate(TElX509Certificate *Parent, TElAlgorithmIdentifier *KeyAlgorithm, TElAlgorithmIdentifier *SignatureAlgorithm, int32_t Bits);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

		void CAGenerate(int32_t Algorithm, int32_t DWordsInEncryptKey);

		void BeginGenerate(int32_t Algorithm, int32_t DWordsInEncryptKey);

		void BeginGenerate(TElX509Certificate &Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);

		void BeginGenerate(TElX509Certificate *Parent, int32_t Algorithm, int32_t DWordsInEncryptKey);

		void EndGenerate();

		void CancelGeneration();

		bool AsyncOperationFinished();

		void SetCACertificate(void * Buffer, int32_t Size);

		void SetCACertificate(TElX509Certificate &Cert);

		void SetCACertificate(TElX509Certificate *Cert);

		void SetCAPrivateKey(void * Buffer, int32_t Size);

		bool Sign(void * InBuffer, int32_t InSize, void * OutBuffer, int32_t &OutSize, bool Detached, bool IncludeCertificates);

		bool Verify(void * InBuffer, int32_t InSize, void * Signature, int32_t SignatureSize);

		static TClassHandle ClassType();

		virtual bool get_PreserveKeyMaterial();

		virtual void set_PreserveKeyMaterial(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveKeyMaterial, set_PreserveKeyMaterial, TElX509CertificateEx, PreserveKeyMaterial);

		virtual void get_AltKeyID(std::vector<uint8_t> &OutResult);

		virtual void set_AltKeyID(const std::vector<uint8_t> &Value);

		virtual int32_t get_PreferredHashAlgorithm();

		virtual void set_PreferredHashAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_PreferredHashAlgorithm, set_PreferredHashAlgorithm, TElX509CertificateEx, PreferredHashAlgorithm);

		virtual bool get_SaveDefaultASN1Tags();

		virtual void set_SaveDefaultASN1Tags(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SaveDefaultASN1Tags, set_SaveDefaultASN1Tags, TElX509CertificateEx, SaveDefaultASN1Tags);

		TElX509CertificateEx(TElX509CertificateExHandle handle, TElOwnHandle ownHandle);

		explicit TElX509CertificateEx(TComponent &Owner);

		explicit TElX509CertificateEx(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELX509CERTIFICATEEX */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBX509EX */

