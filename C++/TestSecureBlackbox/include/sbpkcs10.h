#ifndef __INC_SBPKCS10
#define __INC_SBPKCS10

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbalgorithmidentifier.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbsymmetriccrypto.h"
#include "sbencoding.h"
#include "sbconstants.h"
#include "sbrdn.h"
#include "sbpkcs7utils.h"
#include "sbstreams.h"
#include "sbx509ext.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElCertificateRequestHandle;

typedef TElCertificateRequestHandle ElCertificateRequestHandle;

typedef uint8_t TSBCertReqFileFormatRaw;

typedef enum
{
	crfUnknown = 0,
	crfDER = 1,
	crfPEM = 2
} TSBCertReqFileFormat;

typedef uint8_t TSBCertificateRequestOptionRaw;

typedef enum
{
	croGenerateKeyIdentifier = 0,
	croUseMSExtensionIdentifier = 1,
	croAutoAdjustTagTypes = 2
} TSBCertificateRequestOption;

typedef uint32_t TSBCertificateRequestOptionsRaw;

typedef enum 
{
	f_croGenerateKeyIdentifier = 1,
	f_croUseMSExtensionIdentifier = 2,
	f_croAutoAdjustTagTypes = 4
} TSBCertificateRequestOptions;

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_DetectCertReqFileFormat(const char * pcFileName, int32_t szFileName, TSBCertReqFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_DetectCertReqFileFormat_1(TElCertificateRequestHandle _Handle, const char * pcFileName, int32_t szFileName, TSBCertReqFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_DetectCertReqFileFormat_2(TStreamHandle Stream, TSBCertReqFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_DetectCertReqFileFormat_3(TElCertificateRequestHandle _Handle, TStreamHandle Stream, TSBCertReqFileFormatRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadFromBuffer(TElCertificateRequestHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadFromBufferPEM(TElCertificateRequestHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadFromStream(TElCertificateRequestHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadFromStreamPEM(TElCertificateRequestHandle _Handle, TStreamHandle Stream, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_Generate(TElCertificateRequestHandle _Handle, int32_t PublicKeyAlgorithm, int32_t Bits, int32_t SignatureAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_Generate_1(TElCertificateRequestHandle _Handle, TElAlgorithmIdentifierHandle PublicKeyAlgorithm, int32_t Bits, TElAlgorithmIdentifierHandle SignatureAlgorithm);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveToStream(TElCertificateRequestHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToStream(TElCertificateRequestHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveToBuffer(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveToBufferPEM(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveToStreamPEM(TElCertificateRequestHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToStreamPEM(TElCertificateRequestHandle _Handle, TStreamHandle Stream, const char * pcPassphrase, int32_t szPassphrase);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToStreamPEM_1(TElCertificateRequestHandle _Handle, TStreamHandle Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, const char * pcPassphrase, int32_t szPassphrase);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToBufferPEM(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassphrase, int32_t szPassphrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToBufferPEM_1(TElCertificateRequestHandle _Handle, void * Buffer, int32_t EncryptionAlgorithm, TSBSymmetricCryptoModeRaw EncryptionMode, int32_t * Size, const char * pcPassphrase, int32_t szPassphrase, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToBufferPVK(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, const char * pcPassword, int32_t szPassword, int8_t UseStrongEncryption, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToStreamPVK(TElCertificateRequestHandle _Handle, TStreamHandle Stream, const char * pcPassword, int32_t szPassword, int8_t UseStrongEncryption, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadKeyFromBuffer(TElCertificateRequestHandle _Handle, void * Buffer, int32_t Size, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadKeyFromBufferPEM(TElCertificateRequestHandle _Handle, void * Buffer, int32_t Size, const char * pcPassphrase, int32_t szPassphrase, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadKeyFromStream(TElCertificateRequestHandle _Handle, TStreamHandle Stream, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_LoadKeyFromStreamPEM(TElCertificateRequestHandle _Handle, TStreamHandle Stream, const char * pcPassphrase, int32_t szPassphrase, int32_t Count, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_ValidateSignature(TElCertificateRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_GetRSAParams(TElCertificateRequestHandle _Handle, void * PublicModulus, int32_t * PublicModulusSize, void * PublicExponent, int32_t * PublicExponentSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_GetDSAParams(TElCertificateRequestHandle _Handle, void * P, int32_t * PSize, void * Q, int32_t * QSize, void * G, int32_t * GSize, void * Y, int32_t * YSize, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SaveKeyToBuffer(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_GetPrivateKey(TElCertificateRequestHandle _Handle, void * Buffer, int32_t * Size, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_SetKeyMaterial(TElCertificateRequestHandle _Handle, TElPublicKeyMaterialHandle KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_Subject(TElCertificateRequestHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_Attributes(TElCertificateRequestHandle _Handle, TElPKCS7AttributesHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_Version(TElCertificateRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_set_Version(TElCertificateRequestHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_PublicKeyAlgorithm(TElCertificateRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_SignatureAlgorithm(TElCertificateRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_PublicKeyAlgorithmIdentifier(TElCertificateRequestHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_SignatureAlgorithmIdentifier(TElCertificateRequestHandle _Handle, TElAlgorithmIdentifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_Extensions(TElCertificateRequestHandle _Handle, TElCertificateExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_PublicKeySize(TElCertificateRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_Options(TElCertificateRequestHandle _Handle, TSBCertificateRequestOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_set_Options(TElCertificateRequestHandle _Handle, TSBCertificateRequestOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_PreserveKeyMaterial(TElCertificateRequestHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_set_PreserveKeyMaterial(TElCertificateRequestHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_get_KeyMaterial(TElCertificateRequestHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateRequest_Create(TComponentHandle Owner, TElCertificateRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElCertificateRequest;
typedef TElCertificateRequest ElCertificateRequest;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBCertificateRequestOptions)

#ifdef SB_USE_CLASS_TELCERTIFICATEREQUEST
class TElCertificateRequest: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCertificateRequest)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_Subject;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		TElPKCS7Attributes* _Inst_Attributes;
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_PublicKeyAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		TElAlgorithmIdentifier* _Inst_SignatureAlgorithmIdentifier;
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */
#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		TElCertificateExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_KeyMaterial;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void initInstances();

	public:
		static TSBCertReqFileFormat DetectCertReqFileFormat(const std::string &FileName);

		TSBCertReqFileFormat DetectCertReqFileFormat_Inst(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		static TSBCertReqFileFormat DetectCertReqFileFormat(TStream &Stream);

		static TSBCertReqFileFormat DetectCertReqFileFormat(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		TSBCertReqFileFormat DetectCertReqFileFormat_Inst(TStream &Stream);

		TSBCertReqFileFormat DetectCertReqFileFormat_Inst(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		void LoadFromBuffer(void * Buffer, int32_t Size);

		void LoadFromBufferPEM(void * Buffer, int32_t Size);

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStream(TStream &Stream, int32_t Count);

		void LoadFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void LoadFromStreamPEM(TStream &Stream, int32_t Count);

		void LoadFromStreamPEM(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		void Generate(int32_t PublicKeyAlgorithm, int32_t Bits, int32_t SignatureAlgorithm);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		void Generate(TElAlgorithmIdentifier &PublicKeyAlgorithm, int32_t Bits, TElAlgorithmIdentifier &SignatureAlgorithm);

		void Generate(TElAlgorithmIdentifier *PublicKeyAlgorithm, int32_t Bits, TElAlgorithmIdentifier *SignatureAlgorithm);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStream(TStream &Stream);

		void SaveToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStream(TStream &Stream);

		void SaveKeyToStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		bool SaveToBuffer(void * Buffer, int32_t &Size);

		bool SaveToBufferPEM(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TSTREAM
		void SaveToStreamPEM(TStream &Stream);

		void SaveToStreamPEM(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStreamPEM(TStream &Stream, const std::string &Passphrase);

		void SaveKeyToStreamPEM(TStream *Stream, const std::string &Passphrase);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void SaveKeyToStreamPEM(TStream &Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &Passphrase);

		void SaveKeyToStreamPEM(TStream *Stream, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, const std::string &Passphrase);
#endif /* SB_USE_CLASS_TSTREAM */

		bool SaveKeyToBufferPEM(void * Buffer, int32_t &Size, const std::string &Passphrase);

		bool SaveKeyToBufferPEM(void * Buffer, int32_t EncryptionAlgorithm, TSBSymmetricCryptoMode EncryptionMode, int32_t &Size, const std::string &Passphrase);

		int32_t SaveKeyToBufferPVK(void * Buffer, int32_t &Size, const std::string &Password, bool UseStrongEncryption);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t SaveKeyToStreamPVK(TStream &Stream, const std::string &Password, bool UseStrongEncryption);

		int32_t SaveKeyToStreamPVK(TStream *Stream, const std::string &Password, bool UseStrongEncryption);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t LoadKeyFromBuffer(void * Buffer, int32_t Size);

		int32_t LoadKeyFromBufferPEM(void * Buffer, int32_t Size, const std::string &Passphrase);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStream(TStream &Stream, int32_t Count);

		int32_t LoadKeyFromStream(TStream *Stream, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		int32_t LoadKeyFromStreamPEM(TStream &Stream, const std::string &Passphrase, int32_t Count);

		int32_t LoadKeyFromStreamPEM(TStream *Stream, const std::string &Passphrase, int32_t Count);
#endif /* SB_USE_CLASS_TSTREAM */

		bool ValidateSignature();

		bool GetRSAParams(void * PublicModulus, int32_t &PublicModulusSize, void * PublicExponent, int32_t &PublicExponentSize);

		bool GetDSAParams(void * P, int32_t &PSize, void * Q, int32_t &QSize, void * G, int32_t &GSize, void * Y, int32_t &YSize);

		bool SaveKeyToBuffer(void * Buffer, int32_t &Size);

		bool GetPrivateKey(void * Buffer, int32_t &Size);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		void SetKeyMaterial(TElPublicKeyMaterial &KeyMaterial);

		void SetKeyMaterial(TElPublicKeyMaterial *KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_Subject();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_Subject, TElCertificateRequest, Subject);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELPKCS7ATTRIBUTES
		virtual TElPKCS7Attributes* get_Attributes();

		SB_DECLARE_PROPERTY_GET(TElPKCS7Attributes*, get_Attributes, TElCertificateRequest, Attributes);
#endif /* SB_USE_CLASS_TELPKCS7ATTRIBUTES */

		virtual int32_t get_Version();

		virtual void set_Version(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Version, set_Version, TElCertificateRequest, Version);

		virtual int32_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyAlgorithm, TElCertificateRequest, PublicKeyAlgorithm);

		virtual int32_t get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureAlgorithm, TElCertificateRequest, SignatureAlgorithm);

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_PublicKeyAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_PublicKeyAlgorithmIdentifier, TElCertificateRequest, PublicKeyAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELALGORITHMIDENTIFIER
		virtual TElAlgorithmIdentifier* get_SignatureAlgorithmIdentifier();

		SB_DECLARE_PROPERTY_GET(TElAlgorithmIdentifier*, get_SignatureAlgorithmIdentifier, TElCertificateRequest, SignatureAlgorithmIdentifier);
#endif /* SB_USE_CLASS_TELALGORITHMIDENTIFIER */

#ifdef SB_USE_CLASS_TELCERTIFICATEEXTENSIONS
		virtual TElCertificateExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElCertificateExtensions*, get_Extensions, TElCertificateRequest, Extensions);
#endif /* SB_USE_CLASS_TELCERTIFICATEEXTENSIONS */

		virtual int32_t get_PublicKeySize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeySize, TElCertificateRequest, PublicKeySize);

		virtual TSBCertificateRequestOptions get_Options();

		virtual void set_Options(TSBCertificateRequestOptions Value);

		SB_DECLARE_PROPERTY(TSBCertificateRequestOptions, get_Options, set_Options, TElCertificateRequest, Options);

		virtual bool get_PreserveKeyMaterial();

		virtual void set_PreserveKeyMaterial(bool Value);

		SB_DECLARE_PROPERTY(bool, get_PreserveKeyMaterial, set_PreserveKeyMaterial, TElCertificateRequest, PreserveKeyMaterial);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_KeyMaterial();

		SB_DECLARE_PROPERTY_GET(TElPublicKeyMaterial*, get_KeyMaterial, TElCertificateRequest, KeyMaterial);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		TElCertificateRequest(TElCertificateRequestHandle handle, TElOwnHandle ownHandle);

		explicit TElCertificateRequest(TComponent &Owner);

		explicit TElCertificateRequest(TComponent *Owner);

		virtual ~TElCertificateRequest();

};
#endif /* SB_USE_CLASS_TELCERTIFICATEREQUEST */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBPKCS10 */

