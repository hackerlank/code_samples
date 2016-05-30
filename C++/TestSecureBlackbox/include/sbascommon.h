#ifndef __INC_SBASCOMMON
#define __INC_SBASCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbconstants.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstringlist.h"
#include "sbencoding.h"
#include "sbstreams.h"
#include "sbcustomcertstorage.h"
#include "sbmessages.h"
#include "sbmime.h"
#include "sbsmimesignatures.h"
#include "sbhttpscommon.h"
#include "sbhttpsclient.h"
#include "sbasutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElASReceiptRequestHandle;

typedef TElClassHandle TElASMessageDecryptorHandle;

typedef TElClassHandle TElASMessageEncryptorHandle;

typedef TElClassHandle TElASEncryptionHandle;

typedef TElClassHandle TElASSMIMEMessageDecryptorHandle;

typedef TElClassHandle TElASSMIMEMessageEncryptorHandle;

typedef TElClassHandle TElASSMIMEEncryptionHandle;

typedef TElClassHandle TElASMessageSignerHandle;

typedef TElClassHandle TElASMessageVerifierHandle;

typedef TElClassHandle TElASSignatureHandle;

typedef TElClassHandle TElASSMIMEMessageSignerHandle;

typedef TElClassHandle TElASSMIMEMessageVerifierHandle;

typedef TElClassHandle TElASSMIMESignatureHandle;

typedef TElClassHandle TElASCompressionHandle;

typedef TElClassHandle TElASSMIMECompressionHandle;

typedef TElClassHandle TElASMessageErrorHandle;

typedef TElClassHandle TElASMessageErrorListHandle;

typedef TElClassHandle TElASMessageContentDigestsHandle;

typedef TElClassHandle TElASReceiptHandle;

typedef TElClassHandle TElASMessageHandle;

typedef uint8_t TSBASSignatureDigestAlgorithmRaw;

typedef enum
{
	sdaSHA1 = 0,
	sdaMD5 = 1,
	sdaSHA224 = 2,
	sdaSHA256 = 3,
	sdaSHA384 = 4,
	sdaSHA512 = 5
} TSBASSignatureDigestAlgorithm;

typedef uint8_t TSBASCharsetModeRaw;

typedef enum
{
	cmMessageDefined = 0,
	cmUserDefined = 1
} TSBASCharsetMode;

typedef uint8_t TSBASHeaderTransferEncodingRaw;

typedef enum
{
	hteAuto = 0,
	hte7Bit = 1,
	hte8Bit = 2,
	hteBase64 = 3,
	hteQuotedPrintable = 4
} TSBASHeaderTransferEncoding;

typedef uint8_t TSBASDataTransferEncodingRaw;

typedef enum
{
	dteAuto = 0,
	dte7Bit = 1,
	dte8Bit = 2,
	dteBinary = 3,
	dteBase64 = 4
} TSBASDataTransferEncoding;

typedef uint8_t TSBASEncryptionTransferEncodingRaw;

typedef enum
{
	_dteBinary = 3,
	_dteBase64 = 4
} TSBASEncryptionTransferEncoding;

typedef uint8_t TSBASSignatureTransferEncodingRaw;

typedef enum
{
	__dteBinary = 3,
	__dteBase64 = 4
} TSBASSignatureTransferEncoding;

typedef uint8_t TSBASCompressionTransferEncodingRaw;

typedef enum
{
	___dteBinary = 3,
	___dteBase64 = 4
} TSBASCompressionTransferEncoding;

typedef uint8_t TSBASDispositionActionModeRaw;

typedef enum
{
	damManual = 0,
	damAutomatic = 1
} TSBASDispositionActionMode;

typedef uint8_t TSBASDispositionSendingModeRaw;

typedef enum
{
	dsmSentManually = 0,
	dsmSentAutomatically = 1
} TSBASDispositionSendingMode;

typedef uint8_t TSBASDispositionStatusRaw;

typedef enum
{
	dsProcessed = 0,
	dsFailed = 1
} TSBASDispositionStatus;

typedef uint8_t TSBASDispositionModifierRaw;

typedef enum
{
	dmWarning = 0,
	dmError = 1,
	dmFailure = 2
} TSBASDispositionModifier;

typedef uint8_t TSBASMessageProcessingStepRaw;

typedef enum
{
	mpsEncoding = 0,
	mpsSigning = 1,
	mpsEncrypting = 2,
	mpsDecodingEncrypted = 3,
	mpsDecrypting = 4,
	mpsDecodingSignature = 5,
	mpsDecodingData = 6,
	mpsVerifying = 7,
	mpsCompressing = 8,
	mpsDecodingCompressed = 9,
	mpsDecompressing = 10
} TSBASMessageProcessingStep;

typedef uint8_t TSBASHeaderScopeRaw;

typedef enum
{
	hsMessage = 0,
	hsEncryption = 1,
	hsEncrypted = 2,
	hsSignature = 3,
	hsSigned = 4,
	hsData = 5,
	hsReceipt = 6,
	hsText = 7,
	hsDisposition = 8,
	hsSignatureData = 9,
	hsCompression = 10,
	hsCompressed = 11
} TSBASHeaderScope;

typedef uint32_t TSBASHeaderScopesRaw;

typedef enum 
{
	f_hsMessage = 1,
	f_hsEncryption = 2,
	f_hsEncrypted = 4,
	f_hsSignature = 8,
	f_hsSigned = 16,
	f_hsData = 32,
	f_hsReceipt = 64,
	f_hsText = 128,
	f_hsDisposition = 256,
	f_hsSignatureData = 512,
	f_hsCompression = 1024,
	f_hsCompressed = 2048
} TSBASHeaderScopes;

typedef uint8_t TSBASSMIMEVerificationOptionRaw;

typedef enum
{
	_voUseEmbeddedCerts = 0,
	_voUseLocalCerts = 1,
	_voVerifyMessageDigests = 2,
	_voVerifyTimestamps = 3,
	_voNoOuterContentInfo = 4,
	_voLiberalMode = 5
} TSBASSMIMEVerificationOption;

typedef uint32_t TSBASSMIMEVerificationOptionsRaw;

typedef enum 
{
	_f_voUseEmbeddedCerts = 1,
	_f_voUseLocalCerts = 2,
	_f_voVerifyMessageDigests = 4,
	_f_voVerifyTimestamps = 8,
	_f_voNoOuterContentInfo = 16,
	_f_voLiberalMode = 32
} TSBASSMIMEVerificationOptions;

typedef void (SB_CALLBACK *TSBASErrorNotifyEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Code, const char * pcDescription, int32_t szDescription, int8_t Critical, TSBASDispositionModifierRaw Modifier);

typedef void (SB_CALLBACK *TSBASMessageDecryptEvent)(void * _ObjectData, TObjectHandle Sender, TElASMessageDecryptorHandle Decryptor);

typedef void (SB_CALLBACK *TSBASMessageEncryptEvent)(void * _ObjectData, TObjectHandle Sender, TElASMessageEncryptorHandle Encryptor);

typedef void (SB_CALLBACK *TSBASMessageSignEvent)(void * _ObjectData, TObjectHandle Sender, TElASMessageSignerHandle Signer);

typedef void (SB_CALLBACK *TSBASMessageVerifyEvent)(void * _ObjectData, TObjectHandle Sender, TElASMessageVerifierHandle Verifier);

typedef void (SB_CALLBACK *TSBASHeaderEvent)(void * _ObjectData, TObjectHandle Sender, TElMessageHeaderHandle Header, TSBASHeaderScopesRaw Scopes);

typedef void (SB_CALLBACK *TSBASStreamRequestEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle * Stream, int8_t * FreeOnFinish);

typedef void (SB_CALLBACK *TSBASStreamReleaseEvent)(void * _ObjectData, TObjectHandle Sender, TStreamHandle Stream);

typedef void (SB_CALLBACK *TSBASMessageErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Code, const char * pcDescription, int32_t szDescription, int8_t Critical, TSBASDispositionModifierRaw * Modifier, char * pcReportTag, int32_t * szReportTag, int8_t * Ignore);

typedef void (SB_CALLBACK *TSBASProcessingStepStart)(void * _ObjectData, TObjectHandle Sender, TSBASMessageProcessingStepRaw Step, int8_t ProgressAvailable);

typedef void (SB_CALLBACK *TSBASReceiptErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Code, const char * pcMessage, int32_t szMessage, int8_t Critical, int8_t * Ignore);

#ifdef SB_USE_CLASS_TELASRECEIPTREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElASReceiptRequest_Assign(TElASReceiptRequestHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASReceiptRequest_GetDigestAlgorithmPriority(TElASReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASReceiptRequest_SetDigestAlgorithmPriority(TElASReceiptRequestHandle _Handle, TSBASSignatureDigestAlgorithmRaw Algorithm, int32_t Priority);
SB_IMPORT uint32_t SB_APIENTRY TElASReceiptRequest_Create(TElASReceiptRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELASRECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELASMESSAGEDECRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElASMessageDecryptor_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASMESSAGEENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElASMessageEncryptor_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASENCRYPTION
SB_IMPORT uint32_t SB_APIENTRY TElASEncryption_Assign(TElASEncryptionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASEncryption_Clear(TElASEncryptionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASEncryption_Create(TComponentHandle AOwner, TElASEncryptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELASENCRYPTION */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageDecryptor_get_Decryptor(TElASSMIMEMessageDecryptorHandle _Handle, TElMessageDecryptorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageDecryptor_Create(TElMessageDecryptorHandle ADecryptor, TElASSMIMEMessageDecryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageEncryptor_get_Encryptor(TElASSMIMEMessageEncryptorHandle _Handle, TElMessageEncryptorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageEncryptor_Create(TElMessageEncryptorHandle AEncryptor, TElASSMIMEMessageEncryptorHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEENCRYPTION
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEEncryption_Assign(TElASSMIMEEncryptionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEEncryption_Create(TComponentHandle AOwner, TElASSMIMEEncryptionHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMEENCRYPTION */

#ifdef SB_USE_CLASS_TELASMESSAGESIGNER
SB_IMPORT uint32_t SB_APIENTRY TElASMessageSigner_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASMESSAGEVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElASMessageVerifier_get_Result(TElASMessageVerifierHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageVerifier_set_Result(TElASMessageVerifierHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageVerifier_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElASSignature_Assign(TElASSignatureHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASSignature_Clear(TElASSignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASSignature_Create(TComponentHandle AOwner, TElASSignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSIGNATURE */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGESIGNER
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageSigner_get_Signer(TElASSMIMEMessageSignerHandle _Handle, TElMessageSignerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageSigner_Create(TElMessageSignerHandle ASigner, TElASSMIMEMessageSignerHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageVerifier_get_Verifier(TElASSMIMEMessageVerifierHandle _Handle, TElMessageVerifierHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMEMessageVerifier_Create(int32_t AResult, TElMessageVerifierHandle AVerifier, TElASSMIMEMessageVerifierHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSMIMESIGNATURE
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMESignature_Assign(TElASSMIMESignatureHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMESignature_Clear(TElASSMIMESignatureHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMESignature_Create(TComponentHandle AOwner, TElASSMIMESignatureHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMESIGNATURE */

#ifdef SB_USE_CLASS_TELASCOMPRESSION
SB_IMPORT uint32_t SB_APIENTRY TElASCompression_Assign(TElASCompressionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASCompression_Clear(TElASCompressionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASCompression_Create(TComponentHandle AOwner, TElASCompressionHandle * OutResult);
#endif /* SB_USE_CLASS_TELASCOMPRESSION */

#ifdef SB_USE_CLASS_TELASSMIMECOMPRESSION
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMECompression_Assign(TElASSMIMECompressionHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASSMIMECompression_Create(TComponentHandle AOwner, TElASSMIMECompressionHandle * OutResult);
#endif /* SB_USE_CLASS_TELASSMIMECOMPRESSION */

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_Assign(TElASMessageErrorHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_get_Code(TElASMessageErrorHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_set_Code(TElASMessageErrorHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_get_Description(TElASMessageErrorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_set_Description(TElASMessageErrorHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_get_Modifier(TElASMessageErrorHandle _Handle, TSBASDispositionModifierRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_get_Summary(TElASMessageErrorHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_Create(TElASMessageErrorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageError_Create_1(int32_t ACode, const char * pcASummary, int32_t szASummary, const char * pcADescription, int32_t szADescription, TSBASDispositionModifierRaw AModifier, TElASMessageErrorHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Add(TElASMessageErrorListHandle _Handle, int32_t ACode, const char * pcASummary, int32_t szASummary, const char * pcADescription, int32_t szADescription, TSBASDispositionModifierRaw AModifier, int8_t Adjust, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Assign(TElASMessageErrorListHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Clear(TElASMessageErrorListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Delete(TElASMessageErrorListHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_First(TElASMessageErrorListHandle _Handle, TElASMessageErrorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_IndexOf(TElASMessageErrorListHandle _Handle, TElASMessageErrorHandle Error, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_IndexOf_1(TElASMessageErrorListHandle _Handle, int32_t Code, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Last(TElASMessageErrorListHandle _Handle, TElASMessageErrorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Sort(TElASMessageErrorListHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_get_Count(TElASMessageErrorListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_get_Items(TElASMessageErrorListHandle _Handle, int32_t Index, TElASMessageErrorHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_set_Items(TElASMessageErrorListHandle _Handle, int32_t Index, const TElASMessageErrorHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_get_Modifier(TElASMessageErrorListHandle _Handle, TSBASDispositionModifierRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_set_Modifier(TElASMessageErrorListHandle _Handle, TSBASDispositionModifierRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_get_Status(TElASMessageErrorListHandle _Handle, TSBASDispositionStatusRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_set_Status(TElASMessageErrorListHandle _Handle, TSBASDispositionStatusRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageErrorList_Create(TElASMessageErrorListHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Assign(TElASMessageContentDigestsHandle _Handle, TElASMessageContentDigestsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Clear(TElASMessageContentDigestsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Finish(TElASMessageContentDigestsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Init(TElASMessageContentDigestsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Update(TElASMessageContentDigestsHandle _Handle, const void * Buffer, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_get_Value(TElASMessageContentDigestsHandle _Handle, TSBASSignatureDigestAlgorithmRaw Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessageContentDigests_Create(TElASMessageContentDigestsHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS */

#ifdef SB_USE_CLASS_TELASRECEIPT
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Assign(TElASReceiptHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Clear(TElASReceiptHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Load(TElASReceiptHandle _Handle, TStreamHandle Stream, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Load_1(TElASReceiptHandle _Handle, TStreamHandle ReceiptHeaders, TStreamHandle ReceiptBody, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Load_2(TElASReceiptHandle _Handle, const char * pcFileName, int32_t szFileName, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Save(TElASReceiptHandle _Handle, TStreamHandle Stream);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Save_1(TElASReceiptHandle _Handle, TStreamHandle HeadersStream, TStreamHandle BodyStream);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Save_2(TElASReceiptHandle _Handle, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElASReceipt_Create(TComponentHandle AOwner, TElASReceiptHandle * OutResult);
#endif /* SB_USE_CLASS_TELASRECEIPT */

#ifdef SB_USE_CLASS_TELASMESSAGE
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_GetContentDigest(TElASMessageHandle _Handle, TSBASSignatureDigestAlgorithmRaw Algorithm, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Assign(TElASMessageHandle _Handle, TPersistentHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Clear(TElASMessageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_GetFileOptions(TElASMessageHandle _Handle, const char * pcFilePath, int32_t szFilePath);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_SetFileOptions(TElASMessageHandle _Handle, const char * pcFilePath, int32_t szFilePath);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Load(TElASMessageHandle _Handle, const char * pcFileName, int32_t szFileName, const char * pcDataFile, int32_t szDataFile, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Load_1(TElASMessageHandle _Handle, TStreamHandle Source, TStreamHandle Data, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Save(TElASMessageHandle _Handle, const char * pcDataFile, int32_t szDataFile, const char * pcFileName, int32_t szFileName);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Save_1(TElASMessageHandle _Handle, TStreamHandle Data, TStreamHandle Dest);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Save_2(TElASMessageHandle _Handle, TStreamHandle Data, TStreamHandle DestHeaders, TStreamHandle DestBody);
SB_IMPORT uint32_t SB_APIENTRY TElASMessage_Create(TComponentHandle AOwner, TElASMessageHandle * OutResult);
#endif /* SB_USE_CLASS_TELASMESSAGE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElASReceiptRequest;
class TElASMessageDecryptor;
class TElASMessageEncryptor;
class TElASEncryption;
class TElASSMIMEMessageDecryptor;
class TElASSMIMEMessageEncryptor;
class TElASSMIMEEncryption;
class TElASMessageSigner;
class TElASMessageVerifier;
class TElASSignature;
class TElASSMIMEMessageSigner;
class TElASSMIMEMessageVerifier;
class TElASSMIMESignature;
class TElASCompression;
class TElASSMIMECompression;
class TElASMessageError;
class TElASMessageErrorList;
class TElASMessageContentDigests;
class TElASReceipt;
class TElASMessage;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBASHeaderScopes)

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBASSMIMEVerificationOptions)

#ifdef SB_USE_CLASS_TELASRECEIPTREQUEST
class TElASReceiptRequest: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASReceiptRequest)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		int32_t GetDigestAlgorithmPriority(TSBASSignatureDigestAlgorithm Algorithm);

		void SetDigestAlgorithmPriority(TSBASSignatureDigestAlgorithm Algorithm, int32_t Priority);

		TElASReceiptRequest(TElASReceiptRequestHandle handle, TElOwnHandle ownHandle);

		TElASReceiptRequest();

};
#endif /* SB_USE_CLASS_TELASRECEIPTREQUEST */

#ifdef SB_USE_CLASS_TELASMESSAGEDECRYPTOR
class TElASMessageDecryptor: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageDecryptor)
	public:
		TElASMessageDecryptor(TElASMessageDecryptorHandle handle, TElOwnHandle ownHandle);

		TElASMessageDecryptor();

};
#endif /* SB_USE_CLASS_TELASMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASMESSAGEENCRYPTOR
class TElASMessageEncryptor: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageEncryptor)
	public:
		TElASMessageEncryptor(TElASMessageEncryptorHandle handle, TElOwnHandle ownHandle);

		TElASMessageEncryptor();

};
#endif /* SB_USE_CLASS_TELASMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASENCRYPTION
class TElASEncryption: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASEncryption)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		TElASEncryption(TElASEncryptionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASEncryption(TComponent &AOwner);

		explicit TElASEncryption(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASENCRYPTION */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR
class TElASSMIMEMessageDecryptor: public TElASMessageDecryptor
{
	private:
		SB_DISABLE_COPY(TElASSMIMEMessageDecryptor)
#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
		TElMessageDecryptor* _Inst_Decryptor;
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
		virtual TElMessageDecryptor* get_Decryptor();

		SB_DECLARE_PROPERTY_GET(TElMessageDecryptor*, get_Decryptor, TElASSMIMEMessageDecryptor, Decryptor);
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

		TElASSMIMEMessageDecryptor(TElASSMIMEMessageDecryptorHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELMESSAGEDECRYPTOR
		explicit TElASSMIMEMessageDecryptor(TElMessageDecryptor &ADecryptor);

		explicit TElASSMIMEMessageDecryptor(TElMessageDecryptor *ADecryptor);
#endif /* SB_USE_CLASS_TELMESSAGEDECRYPTOR */

		virtual ~TElASSMIMEMessageDecryptor();

};
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEDECRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR
class TElASSMIMEMessageEncryptor: public TElASMessageEncryptor
{
	private:
		SB_DISABLE_COPY(TElASSMIMEMessageEncryptor)
#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
		TElMessageEncryptor* _Inst_Encryptor;
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
		virtual TElMessageEncryptor* get_Encryptor();

		SB_DECLARE_PROPERTY_GET(TElMessageEncryptor*, get_Encryptor, TElASSMIMEMessageEncryptor, Encryptor);
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

		TElASSMIMEMessageEncryptor(TElASSMIMEMessageEncryptorHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELMESSAGEENCRYPTOR
		explicit TElASSMIMEMessageEncryptor(TElMessageEncryptor &AEncryptor);

		explicit TElASSMIMEMessageEncryptor(TElMessageEncryptor *AEncryptor);
#endif /* SB_USE_CLASS_TELMESSAGEENCRYPTOR */

		virtual ~TElASSMIMEMessageEncryptor();

};
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEENCRYPTOR */

#ifdef SB_USE_CLASS_TELASSMIMEENCRYPTION
class TElASSMIMEEncryption: public TElASEncryption
{
	private:
		SB_DISABLE_COPY(TElASSMIMEEncryption)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		TElASSMIMEEncryption(TElASSMIMEEncryptionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASSMIMEEncryption(TComponent &AOwner);

		explicit TElASSMIMEEncryption(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASSMIMEENCRYPTION */

#ifdef SB_USE_CLASS_TELASMESSAGESIGNER
class TElASMessageSigner: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageSigner)
	public:
		TElASMessageSigner(TElASMessageSignerHandle handle, TElOwnHandle ownHandle);

		TElASMessageSigner();

};
#endif /* SB_USE_CLASS_TELASMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASMESSAGEVERIFIER
class TElASMessageVerifier: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageVerifier)
	public:
		virtual int32_t get_Result();

		virtual void set_Result(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Result, set_Result, TElASMessageVerifier, Result);

		TElASMessageVerifier(TElASMessageVerifierHandle handle, TElOwnHandle ownHandle);

		TElASMessageVerifier();

};
#endif /* SB_USE_CLASS_TELASMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSIGNATURE
class TElASSignature: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASSignature)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		TElASSignature(TElASSignatureHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASSignature(TComponent &AOwner);

		explicit TElASSignature(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASSIGNATURE */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGESIGNER
class TElASSMIMEMessageSigner: public TElASMessageSigner
{
	private:
		SB_DISABLE_COPY(TElASSMIMEMessageSigner)
#ifdef SB_USE_CLASS_TELMESSAGESIGNER
		TElMessageSigner* _Inst_Signer;
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMESSAGESIGNER
		virtual TElMessageSigner* get_Signer();

		SB_DECLARE_PROPERTY_GET(TElMessageSigner*, get_Signer, TElASSMIMEMessageSigner, Signer);
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

		TElASSMIMEMessageSigner(TElASSMIMEMessageSignerHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELMESSAGESIGNER
		explicit TElASSMIMEMessageSigner(TElMessageSigner &ASigner);

		explicit TElASSMIMEMessageSigner(TElMessageSigner *ASigner);
#endif /* SB_USE_CLASS_TELMESSAGESIGNER */

		virtual ~TElASSMIMEMessageSigner();

};
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGESIGNER */

#ifdef SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER
class TElASSMIMEMessageVerifier: public TElASMessageVerifier
{
	private:
		SB_DISABLE_COPY(TElASSMIMEMessageVerifier)
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
		TElMessageVerifier* _Inst_Verifier;
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
		virtual TElMessageVerifier* get_Verifier();

		SB_DECLARE_PROPERTY_GET(TElMessageVerifier*, get_Verifier, TElASSMIMEMessageVerifier, Verifier);
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

		TElASSMIMEMessageVerifier(TElASSMIMEMessageVerifierHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELMESSAGEVERIFIER
		TElASSMIMEMessageVerifier(int32_t AResult, TElMessageVerifier &AVerifier);

		TElASSMIMEMessageVerifier(int32_t AResult, TElMessageVerifier *AVerifier);
#endif /* SB_USE_CLASS_TELMESSAGEVERIFIER */

		virtual ~TElASSMIMEMessageVerifier();

};
#endif /* SB_USE_CLASS_TELASSMIMEMESSAGEVERIFIER */

#ifdef SB_USE_CLASS_TELASSMIMESIGNATURE
class TElASSMIMESignature: public TElASSignature
{
	private:
		SB_DISABLE_COPY(TElASSMIMESignature)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		TElASSMIMESignature(TElASSMIMESignatureHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASSMIMESignature(TComponent &AOwner);

		explicit TElASSMIMESignature(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASSMIMESIGNATURE */

#ifdef SB_USE_CLASS_TELASCOMPRESSION
class TElASCompression: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASCompression)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		TElASCompression(TElASCompressionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASCompression(TComponent &AOwner);

		explicit TElASCompression(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASCOMPRESSION */

#ifdef SB_USE_CLASS_TELASSMIMECOMPRESSION
class TElASSMIMECompression: public TElASCompression
{
	private:
		SB_DISABLE_COPY(TElASSMIMECompression)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		TElASSMIMECompression(TElASSMIMECompressionHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TCOMPONENT
		explicit TElASSMIMECompression(TComponent &AOwner);

		explicit TElASSMIMECompression(TComponent *AOwner);
#endif /* SB_USE_CLASS_TCOMPONENT */

};
#endif /* SB_USE_CLASS_TELASSMIMECOMPRESSION */

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
class TElASMessageError: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageError)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual int32_t get_Code();

		virtual void set_Code(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Code, set_Code, TElASMessageError, Code);

		virtual void get_Description(std::string &OutResult);

		virtual void set_Description(const std::string &Value);

		virtual TSBASDispositionModifier get_Modifier();

		SB_DECLARE_PROPERTY_GET(TSBASDispositionModifier, get_Modifier, TElASMessageError, Modifier);

		virtual void get_Summary(std::string &OutResult);

		TElASMessageError(TElASMessageErrorHandle handle, TElOwnHandle ownHandle);

		TElASMessageError();

		TElASMessageError(int32_t ACode, const std::string &ASummary, const std::string &ADescription, TSBASDispositionModifier AModifier);

};
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

#ifdef SB_USE_CLASS_TELASMESSAGEERRORLIST
class TElASMessageErrorList: public TPersistent
{
	private:
		SB_DISABLE_COPY(TElASMessageErrorList)
#ifdef SB_USE_CLASS_TELASMESSAGEERROR
		TElASMessageError* _Inst_Items;
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

		void initInstances();

	public:
		int32_t Add(int32_t ACode, const std::string &ASummary, const std::string &ADescription, TSBASDispositionModifier AModifier, bool Adjust);

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		void Clear();

		void Delete(int32_t Index);

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
		TElASMessageErrorHandle First();
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
		int32_t IndexOf(TElASMessageError &Error);

		int32_t IndexOf(TElASMessageError *Error);
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

		int32_t IndexOf(int32_t Code);

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
		TElASMessageErrorHandle Last();
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

		void Sort();

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElASMessageErrorList, Count);

#ifdef SB_USE_CLASS_TELASMESSAGEERROR
		virtual TElASMessageError* get_Items(int32_t Index);

		virtual void set_Items(int32_t Index, const TElASMessageError &Value);

		virtual void set_Items(int32_t Index, const TElASMessageError *Value);
#endif /* SB_USE_CLASS_TELASMESSAGEERROR */

		virtual TSBASDispositionModifier get_Modifier();

		virtual void set_Modifier(TSBASDispositionModifier Value);

		SB_DECLARE_PROPERTY(TSBASDispositionModifier, get_Modifier, set_Modifier, TElASMessageErrorList, Modifier);

		virtual TSBASDispositionStatus get_Status();

		virtual void set_Status(TSBASDispositionStatus Value);

		SB_DECLARE_PROPERTY(TSBASDispositionStatus, get_Status, set_Status, TElASMessageErrorList, Status);

		TElASMessageErrorList(TElASMessageErrorListHandle handle, TElOwnHandle ownHandle);

		TElASMessageErrorList();

		virtual ~TElASMessageErrorList();

};
#endif /* SB_USE_CLASS_TELASMESSAGEERRORLIST */

#ifdef SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS
class TElASMessageContentDigests: public TObject
{
	private:
		SB_DISABLE_COPY(TElASMessageContentDigests)
	public:
		void Assign(TElASMessageContentDigests &Source);

		void Assign(TElASMessageContentDigests *Source);

		void Clear();

		void Finish();

		void Init();

		void Update(const void * Buffer, int32_t Count);

		virtual void get_Value(TSBASSignatureDigestAlgorithm Algorithm, std::vector<uint8_t> &OutResult);

		TElASMessageContentDigests(TElASMessageContentDigestsHandle handle, TElOwnHandle ownHandle);

		TElASMessageContentDigests();

};
#endif /* SB_USE_CLASS_TELASMESSAGECONTENTDIGESTS */

#ifdef SB_USE_CLASS_TELASRECEIPT
class TElASReceipt: public TComponent
{
	private:
		SB_DISABLE_COPY(TElASReceipt)
	public:
		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

#ifdef SB_USE_CLASS_TSTREAM
		bool Load(TStream &Stream);

		bool Load(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		bool Load(TStream &ReceiptHeaders, TStream &ReceiptBody);

		bool Load(TStream *ReceiptHeaders, TStream *ReceiptBody);
#endif /* SB_USE_CLASS_TSTREAM */

		bool Load(const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		void Save(TStream &Stream);

		void Save(TStream *Stream);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		void Save(TStream &HeadersStream, TStream &BodyStream);

		void Save(TStream *HeadersStream, TStream *BodyStream);
#endif /* SB_USE_CLASS_TSTREAM */

		void Save(const std::string &FileName);

		TElASReceipt(TElASReceiptHandle handle, TElOwnHandle ownHandle);

		explicit TElASReceipt(TComponent &AOwner);

		explicit TElASReceipt(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELASRECEIPT */

#ifdef SB_USE_CLASS_TELASMESSAGE
class TElASMessage: public TComponent
{
	private:
		SB_DISABLE_COPY(TElASMessage)
	public:
		void GetContentDigest(TSBASSignatureDigestAlgorithm Algorithm, std::vector<uint8_t> &OutResult);

		virtual void Assign(TPersistent &Source);

		virtual void Assign(TPersistent *Source);

		virtual void Clear();

		virtual void GetFileOptions(const std::string &FilePath);

		virtual void SetFileOptions(const std::string &FilePath);

		bool Load(const std::string &FileName, const std::string &DataFile);

#ifdef SB_USE_CLASS_TSTREAM
		bool Load(TStream &Source, TStream &Data);

		bool Load(TStream *Source, TStream *Data);
#endif /* SB_USE_CLASS_TSTREAM */

		virtual void Save(const std::string &DataFile, const std::string &FileName);

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Save(TStream &Data, TStream &Dest);

		virtual void Save(TStream *Data, TStream *Dest);
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
		virtual void Save(TStream &Data, TStream &DestHeaders, TStream &DestBody);

		virtual void Save(TStream *Data, TStream *DestHeaders, TStream *DestBody);
#endif /* SB_USE_CLASS_TSTREAM */

		TElASMessage(TElASMessageHandle handle, TElOwnHandle ownHandle);

		explicit TElASMessage(TComponent &AOwner);

		explicit TElASMessage(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELASMESSAGE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBASCOMMON */

