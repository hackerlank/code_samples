#ifndef __INC_SBSMIMECORE
#define __INC_SBSMIMECORE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmimestream.h"
#include "sbmime.h"
#include "sbcryptoprov.h"
#include "sbmessages.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbx509ext.h"
#include "sbstringlist.h"
#ifdef SB_WINDOWS
#include "sbwincertstorage.h"
#endif
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbchsunicode.h"
#include "sbstrutils.h"
#include "sbstreams.h"
#include "sbsha.h"
#include "sbmd.h"
#include "sbpkcs7.h"
#include "sbsimplemime.h"
#include "sbsmimesignatures.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SMIME_STR_ALG_MD5 	"md5"
#define SB_SMIME_STR_ALG_SHA1 	"sha1"
#define SB_SMIME_STR_ALG_SHA256 	"sha256"
#define SB_SMIME_STR_ALG_SHA384 	"sha384"
#define SB_SMIME_STR_ALG_SHA512 	"sha512"
#define SB_SMIME_ERROR_BASE 	81920
#define SB_SMIME_ERROR_NO_SIGNING_CERTIFICATE_STORAGE 	81921
#define SB_SMIME_ERROR_NO_SIGNING_CERTIFICATE 	81922
#define SB_SMIME_ERROR_HEADER_ASSEMBLING_FAILED 	81923
#define SB_SMIME_ERROR_NO_ENCRYPTION_CERTIFICATE_STORAGE 	81924
#define SB_SMIME_ERROR_NO_ENCRYPTION_CERTIFICATE 	81925
#define SB_SMIME_ERROR_ENCRYPTION_FAILED 	81926
#define SB_SMIME_ERROR_UNKNOWN_DIGEST_ALGORITHM 	81927
#define SB_SMIME_ERROR_SIGNING_FAILED 	81928
#define SB_CEnvelopedHeader 	"Content-Type: application/pkcs7-mime; smime-type=enveloped-data;\r\n\tname=smime.p7m; charset=\"%s\"\r\nContent-Transfer-Encoding: base64\r\nContent-Disposition: attachment; filename=smime.p7m\r\n"
#define SB_CSignedHeader 	"Content-Type: application/pkcs7-mime; smime-type=signed-data;\r\n\tname=smime.p7m; charset=\"%s\"\r\nContent-Transfer-Encoding: base64\r\nContent-Disposition: attachment; filename=smime.p7m\r\n"
#define SB_CSignatureHeader 	"Content-Type: application/pkcs7-signature; name=smime.p7s\r\nContent-Transfer-Encoding: base64\r\nContent-Disposition: attachment; filename=smime.p7s\r\n"
#define SB_SDefaultMIMEPrefix 	"This is a multi-part message in MIME format"
#define SB_SNoSigningCertificateStorage 	"No signing certificate storage"
#define SB_SNoSigningCertificate 	"No signing certificate with private key available in the storage"
#define SB_SFailedToAssembleOriginalPartHeader 	"Failed to assemble the original part header"
#define SB_SNoEncryptionCertificateStorage 	"No encryption certificate storage"
#define SB_SNoEncryptionCertificate 	"No encryption certificate available in the storage"
#ifndef SB_SEncryptionFailed
#define SB_SEncryptionFailed 	"Failed to encrypt data"
#endif
#ifndef SB_SSigningFailed
#define SB_SSigningFailed 	"Failed to sign data"
#endif
#define SB_SUnknownDigestAlgorithm 	"Unknown digest algorithm specified: %s"

typedef TElClassHandle TElMessagePartHandlerSMimeHandle;

typedef TElClassHandle TElSimpleSMIMEMessageHandle;

typedef TElClassHandle TElSimpleSMIMEOptionsHandle;

typedef TElMessagePartHandlerSMimeHandle ElMessagePartHandlerSMimeHandle;

typedef TElSimpleSMIMEOptionsHandle ElSimpleSMIMEOptionsHandle;

typedef TElSimpleSMIMEMessageHandle ElSimpleSMIMEMessageHandle;

typedef uint8_t TElSMimeBoolStateRaw;

typedef enum
{
	smbsNull = 0,
	smbsFalse = 1,
	smbsTrue = 2
} TElSMimeBoolState;

typedef uint8_t TElSMimeTypeRaw;

typedef enum
{
	smtUnknown = 0,
	smtSignOnly = 1,
	smtCryptOnly = 2,
	smtSignAndCrypt = 3
} TElSMimeType;

typedef uint8_t TElSMimeErrorRaw;

typedef enum
{
	smeUnknown = 0,
	smeSignaturePartNotFound = 1,
	smeBodyPartNotFound = 2,
	smeInvalidSignature = 3,
	smeSigningCertificateMismatch = 4,
	smeEncryptingCertificateMismatch = 5,
	smeNoData = 6,
	smeInvalidMessageDigest = 7,
	smeOmittedMessageDigest = 8
} TElSMimeError;

typedef uint32_t TElSMimeErrorsRaw;

typedef enum 
{
	f_smeUnknown = 1,
	f_smeSignaturePartNotFound = 2,
	f_smeBodyPartNotFound = 4,
	f_smeInvalidSignature = 8,
	f_smeSigningCertificateMismatch = 16,
	f_smeEncryptingCertificateMismatch = 32,
	f_smeNoData = 64,
	f_smeInvalidMessageDigest = 128,
	f_smeOmittedMessageDigest = 256
} TElSMimeErrors;

typedef TElSMimeBoolState ElSMimeBoolState;

typedef TElSMimeType ElSMimeType;

typedef TElSMimeError ElSMimeError;

typedef TElSMimeErrors ElSMimeErrors;

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_GetDescription(sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_GetDescription_1(TElMessagePartHandlerSMimeHandle _Handle, sb_char16_t * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_DecoderIsSignedOnly(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_DecoderIsSigned(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_DecoderIsCrypted(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_ClassType(TClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_UseSystemCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_UseSystemCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_CertificatesStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_CertificatesStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_CryptoProviderManager(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_CryptoProviderManager(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_Errors(TElMessagePartHandlerSMimeHandle _Handle, TElSMimeErrorsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_DecoderSignIsCorrectly(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_DecoderSignCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_DecoderCryptCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_DecoderIncludeIssuerCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_DecoderIncludeIssuerCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderCrypted(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderCrypted(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSignBeforeCrypt(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSignBeforeCrypt(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSigned(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSigned(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSignOnlyClearFormat(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSignOnlyClearFormat(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderMicalg(TElMessagePartHandlerSMimeHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderMicalg(TElMessagePartHandlerSMimeHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderCryptAlgorithm(TElMessagePartHandlerSMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderCryptAlgorithm(TElMessagePartHandlerSMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderCryptBitsInKey(TElMessagePartHandlerSMimeHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderCryptBitsInKey(TElMessagePartHandlerSMimeHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderIncludeIssuerCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderIncludeIssuerCertificates(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSignRootHeader(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSignRootHeader(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSignTime(TElMessagePartHandlerSMimeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSignTime(TElMessagePartHandlerSMimeHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_DecoderSignTime(TElMessagePartHandlerSMimeHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderAlignEncryptedKey(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderAlignEncryptedKey(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderCryptCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderCryptCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderSignCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderSignCertStorage(TElMessagePartHandlerSMimeHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_get_EncoderIgnoreCertAddress(TElMessagePartHandlerSMimeHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_set_EncoderIgnoreCertAddress(TElMessagePartHandlerSMimeHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElMessagePartHandlerSMime_Create(TObjectHandle aParams, TElMessagePartHandlerSMimeHandle * OutResult);
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_get_SMIMEOptions(TElSimpleSMIMEMessageHandle _Handle, TElSimpleSMIMEOptionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_set_SMIMEOptions(TElSimpleSMIMEMessageHandle _Handle, TElSimpleSMIMEOptionsHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_get_EncryptCertStorage(TElSimpleSMIMEMessageHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_set_EncryptCertStorage(TElSimpleSMIMEMessageHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_get_SignCertStorage(TElSimpleSMIMEMessageHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_set_SignCertStorage(TElSimpleSMIMEMessageHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEMessage_Create(TComponentHandle AOwner, TElSimpleSMIMEMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESMIMEMESSAGE */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_Assign(TElSimpleSMIMEOptionsHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_CryptoProviderManager(TElSimpleSMIMEOptionsHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_CryptoProviderManager(TElSimpleSMIMEOptionsHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_EncryptMessage(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_EncryptMessage(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_SignMessage(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_SignMessage(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_SignBeforeCrypt(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_SignBeforeCrypt(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_SignOnlyClearFormat(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_SignOnlyClearFormat(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_MicAlg(TElSimpleSMIMEOptionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_MicAlg(TElSimpleSMIMEOptionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_EncryptAlgorithm(TElSimpleSMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_EncryptAlgorithm(TElSimpleSMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_EnryptBitsInKey(TElSimpleSMIMEOptionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_EnryptBitsInKey(TElSimpleSMIMEOptionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_IncludeIssuerCertificates(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_IncludeIssuerCertificates(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_SignRootHeader(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_SignRootHeader(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_SignTime(TElSimpleSMIMEOptionsHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_SignTime(TElSimpleSMIMEOptionsHandle _Handle, int64_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_AlignEncryptedKey(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_AlignEncryptedKey(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_get_IgnoreCertAddress(TElSimpleSMIMEOptionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_set_IgnoreCertAddress(TElSimpleSMIMEOptionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSimpleSMIMEOptions_Create(TElSimpleSMIMEOptionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElMessagePartHandlerSMime;
class TElSimpleSMIMEMessage;
class TElSimpleSMIMEOptions;
typedef TElMessagePartHandlerSMime ElMessagePartHandlerSMime;
typedef TElSimpleSMIMEOptions ElSimpleSMIMEOptions;
typedef TElSimpleSMIMEMessage ElSimpleSMIMEMessage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TElSMimeErrors)

#ifdef SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME
class TElMessagePartHandlerSMime: public TElMessagePartHandler
{
	private:
		SB_DISABLE_COPY(TElMessagePartHandlerSMime)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertificatesStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_DecoderSignCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_DecoderCryptCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncoderCryptCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncoderSignCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		static void GetDescription(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		static void GetDescription(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		virtual void GetDescription_Inst(sb_u16string &OutResult);
#ifdef SB_U16STRING_USED
		virtual void GetDescription_Inst(std::wstring &OutResult);
#endif /* SB_U16STRING_USED */

		bool DecoderIsSignedOnly();

		bool DecoderIsSigned();

		bool DecoderIsCrypted();

		static TClassHandle ClassType();

		virtual bool get_UseSystemCertificates();

		virtual void set_UseSystemCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSystemCertificates, set_UseSystemCertificates, TElMessagePartHandlerSMime, UseSystemCertificates);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertificatesStorage();

		virtual void set_CertificatesStorage(TElCustomCertStorage &Value);

		virtual void set_CertificatesStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertificatesStorage, set_CertificatesStorage, TElMessagePartHandlerSMime, CertificatesStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElMessagePartHandlerSMime, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual TElSMimeErrors get_Errors();

		SB_DECLARE_PROPERTY_GET(TElSMimeErrors, get_Errors, TElMessagePartHandlerSMime, Errors);

		virtual bool get_DecoderSignIsCorrectly();

		SB_DECLARE_PROPERTY_GET(bool, get_DecoderSignIsCorrectly, TElMessagePartHandlerSMime, DecoderSignIsCorrectly);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_DecoderSignCertStorage();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_DecoderSignCertStorage, TElMessagePartHandlerSMime, DecoderSignCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_DecoderCryptCertStorage();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_DecoderCryptCertStorage, TElMessagePartHandlerSMime, DecoderCryptCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_DecoderIncludeIssuerCertificates();

		virtual void set_DecoderIncludeIssuerCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_DecoderIncludeIssuerCertificates, set_DecoderIncludeIssuerCertificates, TElMessagePartHandlerSMime, DecoderIncludeIssuerCertificates);

		virtual bool get_EncoderCrypted();

		virtual void set_EncoderCrypted(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderCrypted, set_EncoderCrypted, TElMessagePartHandlerSMime, EncoderCrypted);

		virtual bool get_EncoderSignBeforeCrypt();

		virtual void set_EncoderSignBeforeCrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderSignBeforeCrypt, set_EncoderSignBeforeCrypt, TElMessagePartHandlerSMime, EncoderSignBeforeCrypt);

		virtual bool get_EncoderSigned();

		virtual void set_EncoderSigned(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderSigned, set_EncoderSigned, TElMessagePartHandlerSMime, EncoderSigned);

		virtual bool get_EncoderSignOnlyClearFormat();

		virtual void set_EncoderSignOnlyClearFormat(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderSignOnlyClearFormat, set_EncoderSignOnlyClearFormat, TElMessagePartHandlerSMime, EncoderSignOnlyClearFormat);

		virtual void get_EncoderMicalg(std::string &OutResult);

		virtual void set_EncoderMicalg(const std::string &Value);

		virtual int32_t get_EncoderCryptAlgorithm();

		virtual void set_EncoderCryptAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_EncoderCryptAlgorithm, set_EncoderCryptAlgorithm, TElMessagePartHandlerSMime, EncoderCryptAlgorithm);

		virtual int32_t get_EncoderCryptBitsInKey();

		virtual void set_EncoderCryptBitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_EncoderCryptBitsInKey, set_EncoderCryptBitsInKey, TElMessagePartHandlerSMime, EncoderCryptBitsInKey);

		virtual bool get_EncoderIncludeIssuerCertificates();

		virtual void set_EncoderIncludeIssuerCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderIncludeIssuerCertificates, set_EncoderIncludeIssuerCertificates, TElMessagePartHandlerSMime, EncoderIncludeIssuerCertificates);

		virtual bool get_EncoderSignRootHeader();

		virtual void set_EncoderSignRootHeader(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderSignRootHeader, set_EncoderSignRootHeader, TElMessagePartHandlerSMime, EncoderSignRootHeader);

		virtual int64_t get_EncoderSignTime();

		virtual void set_EncoderSignTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_EncoderSignTime, set_EncoderSignTime, TElMessagePartHandlerSMime, EncoderSignTime);

		virtual int64_t get_DecoderSignTime();

		SB_DECLARE_PROPERTY_GET(int64_t, get_DecoderSignTime, TElMessagePartHandlerSMime, DecoderSignTime);

		virtual bool get_EncoderAlignEncryptedKey();

		virtual void set_EncoderAlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderAlignEncryptedKey, set_EncoderAlignEncryptedKey, TElMessagePartHandlerSMime, EncoderAlignEncryptedKey);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncoderCryptCertStorage();

		virtual void set_EncoderCryptCertStorage(TElCustomCertStorage &Value);

		virtual void set_EncoderCryptCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_EncoderCryptCertStorage, set_EncoderCryptCertStorage, TElMessagePartHandlerSMime, EncoderCryptCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncoderSignCertStorage();

		virtual void set_EncoderSignCertStorage(TElCustomCertStorage &Value);

		virtual void set_EncoderSignCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_EncoderSignCertStorage, set_EncoderSignCertStorage, TElMessagePartHandlerSMime, EncoderSignCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual bool get_EncoderIgnoreCertAddress();

		virtual void set_EncoderIgnoreCertAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncoderIgnoreCertAddress, set_EncoderIgnoreCertAddress, TElMessagePartHandlerSMime, EncoderIgnoreCertAddress);

		TElMessagePartHandlerSMime(TElMessagePartHandlerSMimeHandle handle, TElOwnHandle ownHandle);

		explicit TElMessagePartHandlerSMime(TObject &aParams);

		explicit TElMessagePartHandlerSMime(TObject *aParams);

		virtual ~TElMessagePartHandlerSMime();

};
#endif /* SB_USE_CLASS_TELMESSAGEPARTHANDLERSMIME */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEMESSAGE
class TElSimpleSMIMEMessage: public TElSimpleMIMEMessage
{
	private:
		SB_DISABLE_COPY(TElSimpleSMIMEMessage)
#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
		TElSimpleSMIMEOptions* _Inst_SMIMEOptions;
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_EncryptCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_SignCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
		virtual TElSimpleSMIMEOptions* get_SMIMEOptions();

		virtual void set_SMIMEOptions(TElSimpleSMIMEOptions &Value);

		virtual void set_SMIMEOptions(TElSimpleSMIMEOptions *Value);

		SB_DECLARE_PROPERTY(TElSimpleSMIMEOptions*, get_SMIMEOptions, set_SMIMEOptions, TElSimpleSMIMEMessage, SMIMEOptions);
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_EncryptCertStorage();

		virtual void set_EncryptCertStorage(TElCustomCertStorage &Value);

		virtual void set_EncryptCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_EncryptCertStorage, set_EncryptCertStorage, TElSimpleSMIMEMessage, EncryptCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_SignCertStorage();

		virtual void set_SignCertStorage(TElCustomCertStorage &Value);

		virtual void set_SignCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_SignCertStorage, set_SignCertStorage, TElSimpleSMIMEMessage, SignCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		TElSimpleSMIMEMessage(TElSimpleSMIMEMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElSimpleSMIMEMessage(TComponent &AOwner);

		explicit TElSimpleSMIMEMessage(TComponent *AOwner);

		virtual ~TElSimpleSMIMEMessage();

};
#endif /* SB_USE_CLASS_TELSIMPLESMIMEMESSAGE */

#ifdef SB_USE_CLASS_TELSIMPLESMIMEOPTIONS
class TElSimpleSMIMEOptions: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElSimpleSMIMEOptions)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSimpleSMIMEOptions, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_EncryptMessage();

		virtual void set_EncryptMessage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_EncryptMessage, set_EncryptMessage, TElSimpleSMIMEOptions, EncryptMessage);

		virtual bool get_SignMessage();

		virtual void set_SignMessage(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignMessage, set_SignMessage, TElSimpleSMIMEOptions, SignMessage);

		virtual bool get_SignBeforeCrypt();

		virtual void set_SignBeforeCrypt(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignBeforeCrypt, set_SignBeforeCrypt, TElSimpleSMIMEOptions, SignBeforeCrypt);

		virtual bool get_SignOnlyClearFormat();

		virtual void set_SignOnlyClearFormat(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignOnlyClearFormat, set_SignOnlyClearFormat, TElSimpleSMIMEOptions, SignOnlyClearFormat);

		virtual void get_MicAlg(std::string &OutResult);

		virtual void set_MicAlg(const std::string &Value);

		virtual int32_t get_EncryptAlgorithm();

		virtual void set_EncryptAlgorithm(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_EncryptAlgorithm, set_EncryptAlgorithm, TElSimpleSMIMEOptions, EncryptAlgorithm);

		virtual int32_t get_EnryptBitsInKey();

		virtual void set_EnryptBitsInKey(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_EnryptBitsInKey, set_EnryptBitsInKey, TElSimpleSMIMEOptions, EnryptBitsInKey);

		virtual bool get_IncludeIssuerCertificates();

		virtual void set_IncludeIssuerCertificates(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IncludeIssuerCertificates, set_IncludeIssuerCertificates, TElSimpleSMIMEOptions, IncludeIssuerCertificates);

		virtual bool get_SignRootHeader();

		virtual void set_SignRootHeader(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SignRootHeader, set_SignRootHeader, TElSimpleSMIMEOptions, SignRootHeader);

		virtual int64_t get_SignTime();

		virtual void set_SignTime(int64_t Value);

		SB_DECLARE_PROPERTY(int64_t, get_SignTime, set_SignTime, TElSimpleSMIMEOptions, SignTime);

		virtual bool get_AlignEncryptedKey();

		virtual void set_AlignEncryptedKey(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AlignEncryptedKey, set_AlignEncryptedKey, TElSimpleSMIMEOptions, AlignEncryptedKey);

		virtual bool get_IgnoreCertAddress();

		virtual void set_IgnoreCertAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_IgnoreCertAddress, set_IgnoreCertAddress, TElSimpleSMIMEOptions, IgnoreCertAddress);

		TElSimpleSMIMEOptions(TElSimpleSMIMEOptionsHandle handle, TElOwnHandle ownHandle);

		TElSimpleSMIMEOptions();

		virtual ~TElSimpleSMIMEOptions();

};
#endif /* SB_USE_CLASS_TELSIMPLESMIMEOPTIONS */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SMIMECORE
SB_IMPORT uint32_t SB_APIENTRY SBSMIMECore_Initialize(void);
#endif /* SB_USE_GLOBAL_PROCS_SMIMECORE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSMIMECORE */
