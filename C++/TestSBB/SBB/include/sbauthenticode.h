#ifndef __INC_SBAUTHENTICODE
#define __INC_SBAUTHENTICODE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbpkicommon.h"
#include "sbcms.h"
#include "sbpkcs7.h"
#include "sbpkcs7utils.h"
#include "sbhashfunction.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"
#include "sbencoding.h"
#include "sbx509.h"
#include "sbtspclient.h"
#include "sbcustomcertstorage.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_AUTHENTICODE_ERROR_BASE 	9216
#define SB_AUTHENTICODE_ERROR_SUCCESS 	0
#define SB_AUTHENTICODE_ERROR_UNKNOWN 	9217
#define SB_AUTHENTICODE_ERROR_CANNOT_OPEN_FILE 	9218
#define SB_AUTHENTICODE_ERROR_FILE_TOO_SMALL 	9219
#define SB_AUTHENTICODE_ERROR_CANNOT_READ_FILE 	9220
#define SB_AUTHENTICODE_ERROR_CANNOT_WRITE_FILE 	9221
#define SB_AUTHENTICODE_ERROR_INVALID_EXECUTABLE 	9222
#define SB_AUTHENTICODE_ERROR_INVALID_PE_FORMAT 	9223
#define SB_AUTHENTICODE_ERROR_FILE_NOT_SIGNED 	9224
#define SB_AUTHENTICODE_ERROR_SIGNATURE_CORRUPTED 	9225
#define SB_AUTHENTICODE_ERROR_INVALID_ALGORITHM 	9226
#define SB_AUTHENTICODE_ERROR_INVALID_DIGEST_SIZE 	9227
#define SB_AUTHENTICODE_ERROR_INVALID_INDEX 	9228
#define SB_AUTHENTICODE_ERROR_NO_SIGNER_CERTIFICATE 	9229
#define SB_AUTHENTICODE_ERROR_INVALID_SIGNATURE 	9230
#define SB_AUTHENTICODE_ERROR_INVALID_CERTIFICATE 	9231
#define SB_AUTHENTICODE_ERROR_FILE_ALREADY_SIGNED 	9232
#define SB_AUTHENTICODE_ERROR_INVALID_ARGUMENT 	9233
#define SB_AUTHENTICODE_ERROR_INVALID_DATA 	9234
#define SB_AUTHENTICODE_ERROR_NO_SIGNATURES 	9235
#define SB_AUTHENTICODE_ERROR_NO_COUNTERSIGNATURES 	9236
#define SB_AUTHENTICODE_ERROR_FILE_NOT_OPEN 	9237
#define SB_AUTHENTICODE_ERROR_SIGNATURE_NOT_LAST 	9238
#define SB_AUTHENTICODE_ERROR_INVALID_AUTHENTICODE 	9239
#define SB_AUTHENTICODE_ERROR_NO_TIMESTAMP 	9240

typedef TElClassHandle TElAuthenticodeProcessorHandle;

typedef TElAuthenticodeProcessorHandle ElAuthenticodeProcessorHandle;

typedef TElClassHandle TElAuthenticodeSignerHandle;

typedef TElAuthenticodeSignerHandle ElAuthenticodeSignerHandle;

typedef TElClassHandle TElAuthenticodeVerifierHandle;

typedef TElAuthenticodeVerifierHandle ElAuthenticodeVerifierHandle;

#pragma pack(4)
typedef struct 
{
	uint32_t Current;
	uint16_t Buffer;
	int8_t BufferInUse;
} TChecksumContext, * PChecksumContext;

typedef uint8_t TSBAuthenticodeDigestAlgorithmRaw;

typedef enum
{
	acMD5 = 0,
	acSHA1 = 1,
	acSHA224 = 2,
	acSHA256 = 3,
	acSHA384 = 4,
	acSHA512 = 5
} TSBAuthenticodeDigestAlgorithm;

typedef uint8_t TSBAuthenticodeDigestEncryptionAlgorithmRaw;

typedef enum
{
	acRSA = 0,
	acDSA = 1
} TSBAuthenticodeDigestEncryptionAlgorithm;

typedef uint8_t TSBAuthenticodeStatementTypeRaw;

typedef enum
{
	acPrivate = 0,
	acCommercial = 1
} TSBAuthenticodeStatementType;

typedef void (SB_CALLBACK *TSBAuthenticodeTimestampNeeded)(void * _ObjectData, TObjectHandle Sender, const uint8_t pRequest[], int32_t szRequest, uint8_t pReply[], int32_t * szReply, int8_t * Succeeded);

#ifdef SB_USE_CLASS_TELAUTHENTICODEPROCESSOR
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeProcessor_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICODEPROCESSOR */

#ifdef SB_USE_CLASS_TELAUTHENTICODESIGNER
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_AddCertificate(TElAuthenticodeSignerHandle _Handle, TElX509CertificateHandle Certificate, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_AddAuthenticode(TElAuthenticodeSignerHandle _Handle, TSBAuthenticodeDigestAlgorithmRaw DigestAlgorithm, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_AddSignature(TElAuthenticodeSignerHandle _Handle, const sb_char16_t * pcDescription, int32_t szDescription, const char * pcURL, int32_t szURL, TSBAuthenticodeDigestAlgorithmRaw Algorithm, TElX509CertificateHandle Signer, int8_t AddSigner, int8_t AddTimestamp, int8_t TrustedTimestamp, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_Clear(TElAuthenticodeSignerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_CloseFile(TElAuthenticodeSignerHandle _Handle, int8_t Apply, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_OpenFile(TElAuthenticodeSignerHandle _Handle, const char * pcFileName, int32_t szFileName, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_OpenStream(TElAuthenticodeSignerHandle _Handle, TStreamHandle Stream, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_get_StatementType(TElAuthenticodeSignerHandle _Handle, TSBAuthenticodeStatementTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_set_StatementType(TElAuthenticodeSignerHandle _Handle, TSBAuthenticodeStatementTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_get_OnTimestampNeeded(TElAuthenticodeSignerHandle _Handle, TSBAuthenticodeTimestampNeeded * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_set_OnTimestampNeeded(TElAuthenticodeSignerHandle _Handle, TSBAuthenticodeTimestampNeeded pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeSigner_Create(TComponentHandle AOwner, TElAuthenticodeSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICODESIGNER */

#ifdef SB_USE_CLASS_TELAUTHENTICODEVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_CloseFile(TElAuthenticodeVerifierHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_GetSignatureInfo(TElAuthenticodeVerifierHandle _Handle, int32_t Index, sb_char16_t * pcDescription, int32_t * szDescription, char * pcURL, int32_t * szURL, int64_t * TimeStamp, TElClientTSPInfoHandle * TrustedTimeStamp, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_OpenFile(TElAuthenticodeVerifierHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t OpenReadOnly, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_OpenStream(TElAuthenticodeVerifierHandle _Handle, TStreamHandle Stream, int8_t OpenReadOnly, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_RemoveAuthenticode(TElAuthenticodeVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_VerifySignature(TElAuthenticodeVerifierHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_ActualChecksum(TElAuthenticodeVerifierHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_ActualDigest(TElAuthenticodeVerifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_Certificates(TElAuthenticodeVerifierHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_Checksum(TElAuthenticodeVerifierHandle _Handle, uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_Digest(TElAuthenticodeVerifierHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_DigestAlgorithm(TElAuthenticodeVerifierHandle _Handle, TSBAuthenticodeDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_SignatureCount(TElAuthenticodeVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_Signatures(TElAuthenticodeVerifierHandle _Handle, int32_t Index, TElPKCS7SignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_Timestamps(TElAuthenticodeVerifierHandle _Handle, int32_t Index, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_TrustedTimestamps(TElAuthenticodeVerifierHandle _Handle, int32_t Index, TElClientTSPInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_get_CertStorage(TElAuthenticodeVerifierHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_set_CertStorage(TElAuthenticodeVerifierHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticodeVerifier_Create(TComponentHandle AOwner, TElAuthenticodeVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICODEVERIFIER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElAuthenticodeProcessor;
typedef TElAuthenticodeProcessor ElAuthenticodeProcessor;
class TElAuthenticodeSigner;
typedef TElAuthenticodeSigner ElAuthenticodeSigner;
class TElAuthenticodeVerifier;
typedef TElAuthenticodeVerifier ElAuthenticodeVerifier;

#ifdef SB_USE_CLASS_TELAUTHENTICODEPROCESSOR
class TElAuthenticodeProcessor: public TComponent
{
	private:
		SB_DISABLE_COPY(TElAuthenticodeProcessor)
	public:
		TElAuthenticodeProcessor(TElAuthenticodeProcessorHandle handle, TElOwnHandle ownHandle);

		explicit TElAuthenticodeProcessor(TComponent &AOwner);

		explicit TElAuthenticodeProcessor(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELAUTHENTICODEPROCESSOR */

#ifdef SB_USE_CLASS_TELAUTHENTICODESIGNER
class TElAuthenticodeSigner: public TElAuthenticodeProcessor
{
	private:
		SB_DISABLE_COPY(TElAuthenticodeSigner)
	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		bool AddCertificate(TElX509Certificate &Certificate);

		bool AddCertificate(TElX509Certificate *Certificate);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		bool AddAuthenticode(TSBAuthenticodeDigestAlgorithm DigestAlgorithm);

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		int32_t AddSignature(const sb_u16string &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate &Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp);

		int32_t AddSignature(const sb_u16string &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate *Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp);
#ifdef SB_U16STRING_USED
		int32_t AddSignature(const std::wstring &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate &Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp);

		int32_t AddSignature(const std::wstring &Description, const std::string &URL, TSBAuthenticodeDigestAlgorithm Algorithm, TElX509Certificate *Signer, bool AddSigner, bool AddTimestamp, bool TrustedTimestamp);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		void Clear();

		int32_t CloseFile(bool Apply);

		int32_t OpenFile(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t OpenStream(TStream &Stream);

		int32_t OpenStream(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual TSBAuthenticodeStatementType get_StatementType();

		virtual void set_StatementType(TSBAuthenticodeStatementType Value);

		SB_DECLARE_PROPERTY(TSBAuthenticodeStatementType, get_StatementType, set_StatementType, TElAuthenticodeSigner, StatementType);

		virtual void get_OnTimestampNeeded(TSBAuthenticodeTimestampNeeded &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimestampNeeded(TSBAuthenticodeTimestampNeeded pMethodValue, void * pDataValue);

		TElAuthenticodeSigner(TElAuthenticodeSignerHandle handle, TElOwnHandle ownHandle);

		explicit TElAuthenticodeSigner(TComponent &AOwner);

		explicit TElAuthenticodeSigner(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELAUTHENTICODESIGNER */

#ifdef SB_USE_CLASS_TELAUTHENTICODEVERIFIER
class TElAuthenticodeVerifier: public TElAuthenticodeProcessor
{
	private:
		SB_DISABLE_COPY(TElAuthenticodeVerifier)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_Certificates;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		TElPKCS7Signer* _Inst_Signatures;
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		TElClientTSPInfo* _Inst_TrustedTimestamps;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		void CloseFile();

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		bool GetSignatureInfo(int32_t Index, sb_u16string &Description, std::string &URL, int64_t &TimeStamp, TElClientTSPInfo &TrustedTimeStamp);
#ifdef SB_U16STRING_USED
		bool GetSignatureInfo(int32_t Index, std::wstring &Description, std::string &URL, int64_t &TimeStamp, TElClientTSPInfo &TrustedTimeStamp);
#endif /* SB_U16STRING_USED */
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

		int32_t OpenFile(const std::string &FileName, bool OpenReadOnly);

#ifdef SB_USE_CLASS_TSTREAM
		int32_t OpenStream(TStream &Stream, bool OpenReadOnly);

		int32_t OpenStream(TStream *Stream, bool OpenReadOnly);
#endif /* SB_USE_CLASS_TSTREAM */

		int32_t RemoveAuthenticode();

		int32_t VerifySignature(int32_t Index);

		virtual uint32_t get_ActualChecksum();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_ActualChecksum, TElAuthenticodeVerifier, ActualChecksum);

		virtual void get_ActualDigest(std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_Certificates();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_Certificates, TElAuthenticodeVerifier, Certificates);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual uint32_t get_Checksum();

		SB_DECLARE_PROPERTY_GET(uint32_t, get_Checksum, TElAuthenticodeVerifier, Checksum);

		virtual void get_Digest(std::vector<uint8_t> &OutResult);

		virtual TSBAuthenticodeDigestAlgorithm get_DigestAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBAuthenticodeDigestAlgorithm, get_DigestAlgorithm, TElAuthenticodeVerifier, DigestAlgorithm);

		virtual int32_t get_SignatureCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SignatureCount, TElAuthenticodeVerifier, SignatureCount);

#ifdef SB_USE_CLASS_TELPKCS7SIGNER
		virtual TElPKCS7Signer* get_Signatures(int32_t Index);
#endif /* SB_USE_CLASS_TELPKCS7SIGNER */

		virtual int64_t get_Timestamps(int32_t Index);

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
		virtual TElClientTSPInfo* get_TrustedTimestamps(int32_t Index);
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElAuthenticodeVerifier, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		TElAuthenticodeVerifier(TElAuthenticodeVerifierHandle handle, TElOwnHandle ownHandle);

		explicit TElAuthenticodeVerifier(TComponent &AOwner);

		explicit TElAuthenticodeVerifier(TComponent *AOwner);

		virtual ~TElAuthenticodeVerifier();

};
#endif /* SB_USE_CLASS_TELAUTHENTICODEVERIFIER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBAUTHENTICODE */

