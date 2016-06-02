#ifndef __INC_SBSSLCOMMON
#define __INC_SBSSLCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbasn1.h"
#include "sbasn1tree.h"
#include "sbalgorithmidentifier.h"
#include "sbrdn.h"
#include "sbsharedresource.h"
#include "sbtimer.h"
#include "sbpublickeycrypto.h"
#include "sbcustomcrypto.h"
#include "sbsslconstants.h"
#include "sbrandom.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_DTLS_WINDOW_SIZE 	64

typedef TElClassHandle TElSSLCertificateTypeHandlerHandle;

typedef TElSSLCertificateTypeHandlerHandle ElSSLCertificateTypeHandlerHandle;

typedef TElClassHandle TElCustomSSLExtensionHandle;

typedef TElCustomSSLExtensionHandle ElCustomSSLExtensionHandle;

typedef TElClassHandle TElSSLClassHandle;

typedef TElSSLClassHandle ElSSLClassHandle;

typedef TElClassHandle TElSSLConnectionInfoHandle;

typedef TElClassHandle TElSSLServerNameHandle;

typedef TElSSLServerNameHandle ElSSLServerNameHandle;

typedef TElClassHandle TElHeartbeatHelloSSLExtensionHandle;

typedef TElHeartbeatHelloSSLExtensionHandle ElHeartbeatHelloSSLExtensionHandle;

typedef TElClassHandle TElServerNameSSLExtensionHandle;

typedef TElServerNameSSLExtensionHandle ElServerNameSSLExtensionHandle;

typedef TElClassHandle TElUserNameSSLExtensionHandle;

typedef TElUserNameSSLExtensionHandle ElUserNameSSLExtensionHandle;

typedef TElClassHandle TElECCurveSSLExtensionHandle;

typedef TElClassHandle TElECPointSSLExtensionHandle;

typedef TElClassHandle TElCertificateTypeResponseHandle;

typedef TElClassHandle TElCertificateTypeRequestHandle;

typedef TElClassHandle TElExtendedMasterSecretExtensionHandle;

typedef TElExtendedMasterSecretExtensionHandle ElExtendedMasterSecretExtensionHandle;

typedef TElClassHandle TElMaxFragmentLengthSSLExtensionHandle;

typedef TElMaxFragmentLengthSSLExtensionHandle ElMaxFragmentLengthSSLExtensionHandle;

typedef TElClassHandle TElSSLCertURLHandle;

typedef TElSSLCertURLHandle ElSSLCertURLHandle;

typedef TElClassHandle TElClientCertURLsSSLExtensionHandle;

typedef TElClientCertURLsSSLExtensionHandle ElClientCertURLsSSLExtensionHandle;

typedef TElClassHandle TElSSLTrustedCAHandle;

typedef TElSSLTrustedCAHandle ElSSLTrustedCAHandle;

typedef TElClassHandle TElTrustedCAsSSLExtensionHandle;

typedef TElTrustedCAsSSLExtensionHandle ElTrustedCAsSSLExtensionHandle;

typedef TElClassHandle TElTruncatedHMACSSLExtensionHandle;

typedef TElTruncatedHMACSSLExtensionHandle ElTruncatedHMACSSLExtensionHandle;

typedef TElClassHandle TElSSLOCSPStatusRequestHandle;

typedef TElSSLOCSPStatusRequestHandle ElSSLOCSPStatusRequestHandle;

typedef TElClassHandle TElCertificateStatusSSLExtensionHandle;

typedef TElCertificateStatusSSLExtensionHandle ElCertificateStatusSSLExtensionHandle;

typedef TElClassHandle TElSessionTicketSSLExtensionHandle;

typedef TElClassHandle TElCertHashTypesSSLExtensionHandle;

typedef TElClassHandle TElRenegotiationInfoSSLExtensionHandle;

typedef TElClassHandle TElSignatureAlgorithmsSSLExtensionHandle;

typedef TElClassHandle TElSRPSSLExtensionHandle;

typedef TElClassHandle TElCustomSSLExtensionsHandle;

typedef TElCustomSSLExtensionsHandle ElCustomSSLExtensionsHandle;

typedef TElClassHandle TElClientSSLExtensionsHandle;

typedef TElClientSSLExtensionsHandle ElClientSSLExtensionsHandle;

typedef TElClassHandle TElServerSSLExtensionsHandle;

typedef TElServerSSLExtensionsHandle ElServerSSLExtensionsHandle;

typedef TElClassHandle TElSSLRetransmissionTimerHandle;

typedef TElClassHandle TElSSLMemoryManagerHandle;

typedef TElClassHandle TElSSLX509CertificateTypeHandlerHandle;

typedef TElSSLX509CertificateTypeHandlerHandle ElSSLX509CertificateTypeHandlerHandle;

typedef TElClassHandle TElSSLRawKeyCertificateTypeHandlerHandle;

typedef TElSSLRawKeyCertificateTypeHandlerHandle ElSSLRawKeyCertificateTypeHandlerHandle;

typedef TElClassHandle TElDTLSFlightItemHandle;

typedef TElClassHandle IElSSLCertificateHandlerContainerHandle;

typedef uint8_t TSBSSLModeRaw;

typedef enum
{
	smImplicit = 0,
	smExplicit = 1,
	smExplicitManual = 2
} TSBSSLMode;

typedef uint8_t TSBCloseReasonRaw;

typedef enum
{
	crError = 0,
	crClose = 1
} TSBCloseReason;

typedef void (SB_CALLBACK *TSBDataEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBReceiveEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t MaxSize, int32_t * Written);

typedef void (SB_CALLBACK *TSBSendEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSBOpenConnectionEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBCloseConnectionEvent)(void * _ObjectData, TObjectHandle Sender, TSBCloseReasonRaw CloseReason);

typedef void (SB_CALLBACK *TSBCertificateValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle X509Certificate, int8_t * Validate);

typedef void (SB_CALLBACK *TSBRawPublicKeyValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElPublicKeyMaterialHandle PublicKey, int8_t * Validate);

typedef void (SB_CALLBACK *TSBRenegotiationStartEvent)(void * _ObjectData, TObjectHandle Sender, int8_t Safe, int8_t * Allow);

typedef void (SB_CALLBACK *TSBRenegotiationRequestEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * Allow);

typedef void (SB_CALLBACK *TSBErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode, int8_t Fatal, int8_t Remote);

typedef uint8_t TSBAlertLevelRaw;

typedef enum
{
	alWarning = 0,
	alFatal = 1
} TSBAlertLevel;

typedef uint8_t TSBAlertDescriptionRaw;

typedef enum
{
	adCloseNotify = 0,
	adUnexpectedMessage = 1,
	adBadRecordMac = 2,
	adDecryptionFailed = 3,
	adRecordOverflow = 4,
	adDecompressionFailure = 5,
	adHandshakeFailure = 6,
	adNoCertificate = 7,
	adBadCertificate = 8,
	adUnsupportedCertificate = 9,
	adCertificateRevoked = 10,
	adCertificateExpired = 11,
	adCertificateUnknown = 12,
	adIllegalParameter = 13,
	adUnknownCa = 14,
	adAccessDenied = 15,
	adDecodeError = 16,
	adDecryptError = 17,
	adExportRestriction = 18,
	adProtocolVersion = 19,
	adInsufficientSecurity = 20,
	adInternalError = 21,
	adUserCanceled = 22,
	adNoRenegotiation = 23,
	adUnsupportedExtension = 24,
	adNoSharedCipher = 25,
	adInappropriateFallback = 26,
	adUnknownPSKIdentity = 27
} TSBAlertDescription;

typedef uint8_t TSBSSLOptionRaw;

typedef enum
{
	ssloExpectShutdownMessage = 0,
	ssloOpenSSLDTLSWorkaround = 1,
	ssloDisableKexLengthAlignment = 2,
	ssloForceUseOfClientCertHashAlg = 3,
	ssloAutoAddServerNameExtension = 4,
	ssloAcceptTrustedSRPPrimesOnly = 5,
	ssloDisableSignatureAlgorithmsExtension = 6,
	ssloIntolerateHigherProtocolVersions = 7
} TSBSSLOption;

typedef uint32_t TSBSSLOptionsRaw;

typedef enum 
{
	f_ssloExpectShutdownMessage = 1,
	f_ssloOpenSSLDTLSWorkaround = 2,
	f_ssloDisableKexLengthAlignment = 4,
	f_ssloForceUseOfClientCertHashAlg = 8,
	f_ssloAutoAddServerNameExtension = 16,
	f_ssloAcceptTrustedSRPPrimesOnly = 32,
	f_ssloDisableSignatureAlgorithmsExtension = 64,
	f_ssloIntolerateHigherProtocolVersions = 128
} TSBSSLOptions;

typedef uint8_t TSBKeyExchangeAlgorithmRaw;

typedef enum
{
	kaNULL = 0,
	kaRSA = 1,
	kaDH = 2,
	kaDHE = 3,
	kaDHanon = 4,
	kaPSK = 5,
	kaDHEPSK = 6,
	kaRSAPSK = 7,
	kaSRP = 8,
	kaECDH_ECDSA = 9,
	kaECDHE_ECDSA = 10,
	kaECDH_RSA = 11,
	kaECDHE_RSA = 12,
	kaECDH_anon = 13,
	kaECDHE_PSK = 14
} TSBKeyExchangeAlgorithm;

typedef uint8_t TSBDigestAlgorithmRaw;

typedef enum
{
	daNULL = 0,
	daMD5 = 1,
	daSHA = 2,
	daSHA256 = 3,
	daSHA384 = 4,
	daSHA512 = 5
} TSBDigestAlgorithm;

typedef uint8_t TSBEncryptAlgorithmRaw;

typedef enum
{
	eaNULL = 0,
	eaRC4 = 1,
	eaRC2 = 2,
	eaDES = 3,
	ea3DES = 4,
	eaIDEA = 5,
	eaAES128 = 6,
	eaAES256 = 7,
	eaCamellia128 = 8,
	eaCamellia256 = 9,
	eaSeed = 10,
	eaAES128GCM = 11,
	eaAES256GCM = 12,
	eaCamellia128GCM = 13,
	eaCamellia256GCM = 14,
	eaChaCha20Poly1305 = 15
} TSBEncryptAlgorithm;

typedef uint8_t TSBSignatureAlgorithmRaw;

typedef enum
{
	saAnonymous = 0,
	saRSA = 1,
	saDSA = 2,
	saECDSA = 3,
	saNull = 4
} TSBSignatureAlgorithm;

typedef uint8_t TSBRenegotiationAttackPreventionModeRaw;

typedef enum
{
	rapmCompatible = 0,
	rapmStrict = 1,
	rapmAuto = 2
} TSBRenegotiationAttackPreventionMode;

typedef uint8_t TSBSSLServerNameTypeRaw;

typedef enum
{
	ntHostName = 0,
	ntUnknown = 1
} TSBSSLServerNameType;

typedef uint8_t TSBSSLFragmentLengthRaw;

typedef enum
{
	fl512 = 0,
	fl1024 = 1,
	fl2048 = 2,
	fl4096 = 3,
	flUnknown = 4
} TSBSSLFragmentLength;

typedef uint8_t TSBCertChainTypeRaw;

typedef enum
{
	cctIndividualCerts = 0,
	cctPKIPath = 1,
	cctUnknown = 2
} TSBCertChainType;

typedef uint8_t TSBCAIdentifierTypeRaw;

typedef enum
{
	itPreAgreed = 0,
	itKeyHash = 1,
	itRDN = 2,
	itCertHash = 3,
	itUnknown = 4
} TSBCAIdentifierType;

typedef uint8_t TSBCertificateStatusTypeRaw;

typedef enum
{
	cstOCSP = 0,
	cstMultiOCSP = 1,
	cstUnknown = 2
} TSBCertificateStatusType;

typedef void (SB_CALLBACK *TSBExtensionsReceivedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSBExtensionsPreparedEvent)(void * _ObjectData, TObjectHandle Sender);

typedef uint8_t TSSL3ContentTypeRaw;

typedef enum
{
	ctChangeCipherSpec = 0,
	ctAlert = 1,
	ctHandshake = 2,
	ctApplicationData = 3,
	ctHeartbeat = 4,
	_ctUnknown = 5
} TSSL3ContentType;

typedef uint8_t TSSL3HandshakeTypeRaw;

typedef enum
{
	htHelloRequest = 0,
	htClientHello = 1,
	htServerHello = 2,
	htCertificate = 3,
	htServerKeyExchange = 4,
	htCertificateRequest = 5,
	htServerHelloDone = 6,
	htCertificateVerify = 7,
	htClientKeyExchange = 8,
	htFinished = 9,
	htCertificateURL = 10,
	htCertificateStatus = 11,
	htNewSessionTicket = 12
} TSSL3HandshakeType;

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetCertificateType(TElSSLCertificateTypeHandlerHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetDataForRemote(TElSSLCertificateTypeHandlerHandle _Handle, int32_t CipherSuite, TSBKeyExchangeAlgorithmRaw KeyExchange, uint8_t pData[], int32_t * szData, int32_t Optional, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_ValidateRemoteCert(TElSSLCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t Optional, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetRemoteKeyMaterial(TElSSLCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t KeyType, int32_t * PKType, int32_t * KeyAlgorithm, TElKeyMaterialHandle * KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetKeyMaterial(TElSSLCertificateTypeHandlerHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetPublicKeySize(TElSSLCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_GetPublicKeyAlgorithm(TElSSLCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_get_KeyIndex(TElSSLCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_set_KeyIndex(TElSSLCertificateTypeHandlerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_get_KeyCount(TElSSLCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_get_SSLClass(TElSSLCertificateTypeHandlerHandle _Handle, IElSSLCertificateHandlerContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_set_SSLClass(TElSSLCertificateTypeHandlerHandle _Handle, IElSSLCertificateHandlerContainerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertificateTypeHandler_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_Assign(TElCustomSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_Clear(TElCustomSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_get_ExtensionType(TElCustomSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_set_ExtensionType(TElCustomSSLExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_get_ExtensionData(TElCustomSSLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_set_ExtensionData(TElCustomSSLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_get_Enabled(TElCustomSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_set_Enabled(TElCustomSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_get_Server(TElCustomSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_set_Server(TElCustomSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtension_Create(TElCustomSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCLASS
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_AddCertTypeHandler(TElSSLClassHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_RemoveCertTypeHandler(TElSSLClassHandle _Handle, TElSSLCertificateTypeHandlerHandle Handler);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_EnterCS(TElSSLClassHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_LeaveCS(TElSSLClassHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_AssignFromTemplate(TElSSLClassHandle _Handle, TElSSLClassHandle Tpl);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_CipherSuites(TElSSLClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_CipherSuites(TElSSLClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_CipherSuitePriorities(TElSSLClassHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_CipherSuitePriorities(TElSSLClassHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_CompressionAlgorithms(TElSSLClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_CompressionAlgorithms(TElSSLClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_Active(TElSSLClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_CurrentVersion(TElSSLClassHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_CompressionAlgorithm(TElSSLClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_TotalBytesSent(TElSSLClassHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_TotalBytesReceived(TElSSLClassHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_ConnectionInfo(TElSSLClassHandle _Handle, TElSSLConnectionInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_Versions(TElSSLClassHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_Versions(TElSSLClassHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_Options(TElSSLClassHandle _Handle, TSBSSLOptionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_Options(TElSSLClassHandle _Handle, TSBSSLOptionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_RenegotiationAttackPreventionMode(TElSSLClassHandle _Handle, TSBRenegotiationAttackPreventionModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_RenegotiationAttackPreventionMode(TElSSLClassHandle _Handle, TSBRenegotiationAttackPreventionModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnSend(TElSSLClassHandle _Handle, TSBSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnSend(TElSSLClassHandle _Handle, TSBSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnReceive(TElSSLClassHandle _Handle, TSBReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnReceive(TElSSLClassHandle _Handle, TSBReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnData(TElSSLClassHandle _Handle, TSBDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnData(TElSSLClassHandle _Handle, TSBDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnOpenConnection(TElSSLClassHandle _Handle, TSBOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnOpenConnection(TElSSLClassHandle _Handle, TSBOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnCertificateValidate(TElSSLClassHandle _Handle, TSBCertificateValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnCertificateValidate(TElSSLClassHandle _Handle, TSBCertificateValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnRawPublicKeyValidate(TElSSLClassHandle _Handle, TSBRawPublicKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnRawPublicKeyValidate(TElSSLClassHandle _Handle, TSBRawPublicKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnCiphersNegotiated(TElSSLClassHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnCiphersNegotiated(TElSSLClassHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnError(TElSSLClassHandle _Handle, TSBErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnError(TElSSLClassHandle _Handle, TSBErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnExtensionsReceived(TElSSLClassHandle _Handle, TSBExtensionsReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnExtensionsReceived(TElSSLClassHandle _Handle, TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnExtensionsPrepared(TElSSLClassHandle _Handle, TSBExtensionsPreparedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnExtensionsPrepared(TElSSLClassHandle _Handle, TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_get_OnKeepAliveResponse(TElSSLClassHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_set_OnKeepAliveResponse(TElSSLClassHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClass_Create(TComponentHandle Owner, TElSSLClassHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_InitializeNonSecure(TElSSLConnectionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_Initialize(TElSSLConnectionInfoHandle _Handle, TSBVersionRaw Version, uint8_t Ciphersuite, TElCustomCertStorageHandle ServerChain, TElCustomCertStorageHandle ClientChain, const uint8_t pSessionID[], int32_t szSessionID, int8_t ResumedSession);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_Reset(TElSSLConnectionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_Ciphersuite(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_CiphersuiteName(TElSSLConnectionInfoHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_EncryptionAlgorithm(TElSSLConnectionInfoHandle _Handle, TSBEncryptAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_KeyExchangeAlgorithm(TElSSLConnectionInfoHandle _Handle, TSBKeyExchangeAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_SignatureAlgorithm(TElSSLConnectionInfoHandle _Handle, TSBSignatureAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_DigestAlgorithm(TElSSLConnectionInfoHandle _Handle, TSBDigestAlgorithmRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_Version(TElSSLConnectionInfoHandle _Handle, TSBVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_Exportable(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_SymmetricKeyBits(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_PublicKeyBits(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_KeyExchangeKeyBits(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_SymmetricBlockSize(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_AEADCipher(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ClientChain(TElSSLConnectionInfoHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ServerChain(TElSSLConnectionInfoHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_SessionID(TElSSLConnectionInfoHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ResumedSession(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ConnectionEstablished(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_PFSCipher(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ClientAuthenticated(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_ServerAuthenticated(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_SecureConnection(TElSSLConnectionInfoHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_get_NamedECCurve(TElSSLConnectionInfoHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLConnectionInfo_Create(TElSSLClassHandle Owner, TElSSLConnectionInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVERNAME
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerName_get_NameType(TElSSLServerNameHandle _Handle, TSBSSLServerNameTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerName_set_NameType(TElSSLServerNameHandle _Handle, TSBSSLServerNameTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerName_get_Name(TElSSLServerNameHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerName_set_Name(TElSSLServerNameHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerName_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElHeartbeatHelloSSLExtension_Assign(TElHeartbeatHelloSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElHeartbeatHelloSSLExtension_get_Mode(TElHeartbeatHelloSSLExtensionHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElHeartbeatHelloSSLExtension_set_Mode(TElHeartbeatHelloSSLExtensionHandle _Handle, uint8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElHeartbeatHelloSSLExtension_Create(TElHeartbeatHelloSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_Assign(TElServerNameSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_Add(TElServerNameSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_Remove(TElServerNameSSLExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_Clear(TElServerNameSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_get_Names(TElServerNameSSLExtensionHandle _Handle, int32_t Index, TElSSLServerNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_get_Count(TElServerNameSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerNameSSLExtension_Create(TElServerNameSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElUserNameSSLExtension_Assign(TElUserNameSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElUserNameSSLExtension_get_Name(TElUserNameSSLExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElUserNameSSLExtension_set_Name(TElUserNameSSLExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElUserNameSSLExtension_Create(TElUserNameSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_Assign(TElECCurveSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_SetCurves(TElECCurveSSLExtensionHandle _Handle, int32_t Curve, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_IsCurveEnabled(TElECCurveSSLExtensionHandle _Handle, int32_t Curve, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_GetCurve(TElECCurveSSLExtensionHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_GetCurveCount(TElECCurveSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECCurveSSLExtension_Create(TElECCurveSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElECPointSSLExtension_Assign(TElECPointSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElECPointSSLExtension_SetPointType(TElECPointSSLExtensionHandle _Handle, uint8_t Point, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElECPointSSLExtension_GetPointType(TElECPointSSLExtensionHandle _Handle, uint8_t Point, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElECPointSSLExtension_Create(TElECPointSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeResponse_Assign(TElCertificateTypeResponseHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeResponse_get_CertType(TElCertificateTypeResponseHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeResponse_set_CertType(TElCertificateTypeResponseHandle _Handle, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeResponse_Create(TElCertificateTypeResponseHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_Assign(TElCertificateTypeRequestHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_AddCertType(TElCertificateTypeRequestHandle _Handle, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_DelCertType(TElCertificateTypeRequestHandle _Handle, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_GetCertTypesCount(TElCertificateTypeRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_ClearCertTypes(TElCertificateTypeRequestHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_CheckCertType(TElCertificateTypeRequestHandle _Handle, TElSSLCertificateTypeRaw Value, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_GetBaseCertType(TElCertificateTypeRequestHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_get_CertTypes(TElCertificateTypeRequestHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_set_CertTypes(TElCertificateTypeRequestHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateTypeRequest_Create(TElCertificateTypeRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElExtendedMasterSecretExtension_Assign(TElExtendedMasterSecretExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElExtendedMasterSecretExtension_Create(TElExtendedMasterSecretExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElMaxFragmentLengthSSLExtension_Assign(TElMaxFragmentLengthSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElMaxFragmentLengthSSLExtension_Clear(TElMaxFragmentLengthSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMaxFragmentLengthSSLExtension_get_MaxLength(TElMaxFragmentLengthSSLExtensionHandle _Handle, TSBSSLFragmentLengthRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMaxFragmentLengthSSLExtension_set_MaxLength(TElMaxFragmentLengthSSLExtensionHandle _Handle, TSBSSLFragmentLengthRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElMaxFragmentLengthSSLExtension_Create(TElCustomSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCERTURL
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_get_URL(TElSSLCertURLHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_set_URL(TElSSLCertURLHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_get_Hash(TElSSLCertURLHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_set_Hash(TElSSLCertURLHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_get_PrivateKey(TElSSLCertURLHandle _Handle, TElPublicKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_set_PrivateKey(TElSSLCertURLHandle _Handle, TElPublicKeyMaterialHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLCertURL_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCERTURL */

#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_Assign(TElClientCertURLsSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_Add(TElClientCertURLsSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_Remove(TElClientCertURLsSSLExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_Clear(TElClientCertURLsSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_get_ChainType(TElClientCertURLsSSLExtensionHandle _Handle, TSBCertChainTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_set_ChainType(TElClientCertURLsSSLExtensionHandle _Handle, TSBCertChainTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_get_URLs(TElClientCertURLsSSLExtensionHandle _Handle, int32_t Index, TElSSLCertURLHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_get_Count(TElClientCertURLsSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientCertURLsSSLExtension_Create(TElClientCertURLsSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_Import(TElSSLTrustedCAHandle _Handle, TElX509CertificateHandle Cert);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_get_IdentifierType(TElSSLTrustedCAHandle _Handle, TSBCAIdentifierTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_set_IdentifierType(TElSSLTrustedCAHandle _Handle, TSBCAIdentifierTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_get_Value(TElSSLTrustedCAHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_set_Value(TElSSLTrustedCAHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_get_RDN(TElSSLTrustedCAHandle _Handle, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLTrustedCA_Create(TElSSLTrustedCAHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_Assign(TElTrustedCAsSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_Add(TElTrustedCAsSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_Remove(TElTrustedCAsSSLExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_Clear(TElTrustedCAsSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_get_TrustedCAs(TElTrustedCAsSSLExtensionHandle _Handle, int32_t Index, TElSSLTrustedCAHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_get_Count(TElTrustedCAsSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTrustedCAsSSLExtension_Create(TElTrustedCAsSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElTruncatedHMACSSLExtension_Assign(TElTruncatedHMACSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElTruncatedHMACSSLExtension_Create(TElCustomSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_get_ResponderIDs(TElSSLOCSPStatusRequestHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_set_ResponderIDs(TElSSLOCSPStatusRequestHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_get_ResponderIDCount(TElSSLOCSPStatusRequestHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_set_ResponderIDCount(TElSSLOCSPStatusRequestHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_get_Extensions(TElSSLOCSPStatusRequestHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_set_Extensions(TElSSLOCSPStatusRequestHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLOCSPStatusRequest_Create(TElSSLOCSPStatusRequestHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_Assign(TElCertificateStatusSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_Clear(TElCertificateStatusSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_AddOCSPStatusRequest(TElCertificateStatusSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_RemoveOCSPStatusRequest(TElCertificateStatusSSLExtensionHandle _Handle, int32_t Index);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_StatusType(TElCertificateStatusSSLExtensionHandle _Handle, TSBCertificateStatusTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_set_StatusType(TElCertificateStatusSSLExtensionHandle _Handle, TSBCertificateStatusTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPStatusRequest(TElCertificateStatusSSLExtensionHandle _Handle, TElSSLOCSPStatusRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPStatusRequests(TElCertificateStatusSSLExtensionHandle _Handle, int32_t Index, TElSSLOCSPStatusRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPStatusRequestCount(TElCertificateStatusSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPResponse(TElCertificateStatusSSLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_set_OCSPResponse(TElCertificateStatusSSLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPResponses(TElCertificateStatusSSLExtensionHandle _Handle, int32_t Index, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_set_OCSPResponses(TElCertificateStatusSSLExtensionHandle _Handle, int32_t Index, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_get_OCSPResponseCount(TElCertificateStatusSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_set_OCSPResponseCount(TElCertificateStatusSSLExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertificateStatusSSLExtension_Create(TElCertificateStatusSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSessionTicketSSLExtension_Assign(TElSessionTicketSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSessionTicketSSLExtension_Clear(TElSessionTicketSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSessionTicketSSLExtension_get_Ticket(TElSessionTicketSSLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionTicketSSLExtension_set_Ticket(TElSessionTicketSSLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSessionTicketSSLExtension_Create(TElCustomSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_Assign(TElCertHashTypesSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_Clear(TElCertHashTypesSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_SwitchAll(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_get_MD5(TElCertHashTypesSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_set_MD5(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_get_SHA1(TElCertHashTypesSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_set_SHA1(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_get_SHA256(TElCertHashTypesSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_set_SHA256(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_get_SHA384(TElCertHashTypesSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_set_SHA384(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_get_SHA512(TElCertHashTypesSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_set_SHA512(TElCertHashTypesSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCertHashTypesSSLExtension_Create(TElCertHashTypesSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */

#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_Assign(TElRenegotiationInfoSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_Clear(TElRenegotiationInfoSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_get_Info(TElRenegotiationInfoSSLExtensionHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_set_Info(TElRenegotiationInfoSSLExtensionHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_get_UseSignalingCipherSuite(TElRenegotiationInfoSSLExtensionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_set_UseSignalingCipherSuite(TElRenegotiationInfoSSLExtensionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRenegotiationInfoSSLExtension_Create(TElRenegotiationInfoSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_Assign(TElSignatureAlgorithmsSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_Clear(TElSignatureAlgorithmsSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_EnableAllSupported(TElSignatureAlgorithmsSSLExtensionHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_get_Count(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_set_Count(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_get_HashAlgorithms(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_set_HashAlgorithms(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_get_SignatureAlgorithms(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_set_SignatureAlgorithms(TElSignatureAlgorithmsSSLExtensionHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSignatureAlgorithmsSSLExtension_Create(TElCustomSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
SB_IMPORT uint32_t SB_APIENTRY TElSRPSSLExtension_Assign(TElSRPSSLExtensionHandle _Handle, TElCustomSSLExtensionHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElSRPSSLExtension_get_Name(TElSRPSSLExtensionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSRPSSLExtension_set_Name(TElSRPSSLExtensionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSRPSSLExtension_Create(TElSRPSSLExtensionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_Assign(TElCustomSSLExtensionsHandle _Handle, TElCustomSSLExtensionsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_Clear(TElCustomSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_DisableAll(TElCustomSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_CertificateStatus(TElCustomSSLExtensionsHandle _Handle, TElCertificateStatusSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_ClientCertURLs(TElCustomSSLExtensionsHandle _Handle, TElClientCertURLsSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_MaxFragmentLength(TElCustomSSLExtensionsHandle _Handle, TElMaxFragmentLengthSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_OtherCount(TElCustomSSLExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_set_OtherCount(TElCustomSSLExtensionsHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_OtherExtensions(TElCustomSSLExtensionsHandle _Handle, int32_t Index, TElCustomSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_ServerName(TElCustomSSLExtensionsHandle _Handle, TElServerNameSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_TruncatedHMAC(TElCustomSSLExtensionsHandle _Handle, TElTruncatedHMACSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_TrustedCAs(TElCustomSSLExtensionsHandle _Handle, TElTrustedCAsSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_UserName(TElCustomSSLExtensionsHandle _Handle, TElUserNameSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_ECCurves(TElCustomSSLExtensionsHandle _Handle, TElECCurveSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_ECPoints(TElCustomSSLExtensionsHandle _Handle, TElECPointSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_StatelessTLS(TElCustomSSLExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_set_StatelessTLS(TElCustomSSLExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_CertHashTypes(TElCustomSSLExtensionsHandle _Handle, TElCertHashTypesSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_RenegotiationInfo(TElCustomSSLExtensionsHandle _Handle, TElRenegotiationInfoSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_set_RenegotiationInfo(TElCustomSSLExtensionsHandle _Handle, TElRenegotiationInfoSSLExtensionHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_Heartbeat(TElCustomSSLExtensionsHandle _Handle, TElHeartbeatHelloSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_SignatureAlgorithms(TElCustomSSLExtensionsHandle _Handle, TElSignatureAlgorithmsSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_SRP(TElCustomSSLExtensionsHandle _Handle, TElSRPSSLExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_get_ExtendedMasterSecret(TElCustomSSLExtensionsHandle _Handle, TElExtendedMasterSecretExtensionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSLExtensions_Create(TElCustomSSLExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_Assign(TElClientSSLExtensionsHandle _Handle, TElCustomSSLExtensionsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_Clear(TElClientSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_DisableAll(TElClientSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_ClearAcceptableCAs(TElClientSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_AddAcceptableCAs(TElClientSSLExtensionsHandle _Handle, TElRelativeDistinguishedNameHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_get_AcceptableCAs(TElClientSSLExtensionsHandle _Handle, int32_t Index, TElRelativeDistinguishedNameHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_get_AcceptableCACount(TElClientSSLExtensionsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_get_FallbackConnection(TElClientSSLExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_set_FallbackConnection(TElClientSSLExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_get_ServerCertificateType(TElClientSSLExtensionsHandle _Handle, TElCertificateTypeRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_get_ClientCertificateType(TElClientSSLExtensionsHandle _Handle, TElCertificateTypeRequestHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLExtensions_Create(TElClientSSLExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_Assign(TElServerSSLExtensionsHandle _Handle, TElCustomSSLExtensionsHandle Source);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_Clear(TElServerSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_DisableAll(TElServerSSLExtensionsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_get_StrictCertRequest(TElServerSSLExtensionsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_set_StrictCertRequest(TElServerSSLExtensionsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_get_PSKIdentityHint(TElServerSSLExtensionsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_set_PSKIdentityHint(TElServerSSLExtensionsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_get_ServerCertificateType(TElServerSSLExtensionsHandle _Handle, TElCertificateTypeResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_get_ClientCertificateType(TElServerSSLExtensionsHandle _Handle, TElCertificateTypeResponseHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLExtensions_Create(TElServerSSLExtensionsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_Start(TElSSLRetransmissionTimerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_Stop(TElSSLRetransmissionTimerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_get_Interval(TElSSLRetransmissionTimerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_set_Interval(TElSSLRetransmissionTimerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_get_Enabled(TElSSLRetransmissionTimerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_get_OnTimer(TElSSLRetransmissionTimerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_set_OnTimer(TElSSLRetransmissionTimerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRetransmissionTimer_Create(TElSSLRetransmissionTimerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER */

#ifdef SB_USE_CLASS_TELSSLMEMORYMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_GetArray(TElSSLMemoryManagerHandle _Handle, int32_t Len, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_ReleaseArray(TElSSLMemoryManagerHandle _Handle, uint8_t pArr[], int32_t * szArr);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_ResizeArray(TElSSLMemoryManagerHandle _Handle, uint8_t pArr[], int32_t * szArr, int32_t NewSize);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_ReleaseAll(TElSSLMemoryManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_get_Enabled(TElSSLMemoryManagerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_set_Enabled(TElSSLMemoryManagerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_get_MaxCount(TElSSLMemoryManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_set_MaxCount(TElSSLMemoryManagerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLMemoryManager_Create(TElSSLMemoryManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLMEMORYMANAGER */

#ifdef SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetCertificateType(TElSSLX509CertificateTypeHandlerHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetDataForRemote(TElSSLX509CertificateTypeHandlerHandle _Handle, int32_t CipherSuite, TSBKeyExchangeAlgorithmRaw KeyExchange, uint8_t pData[], int32_t * szData, int32_t Optional, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_ValidateRemoteCert(TElSSLX509CertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t Optional, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetRemoteKeyMaterial(TElSSLX509CertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t KeyType, int32_t * PKType, int32_t * KeyAlgorithm, TElKeyMaterialHandle * KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetKeyMaterial(TElSSLX509CertificateTypeHandlerHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetPublicKeySize(TElSSLX509CertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_GetPublicKeyAlgorithm(TElSSLX509CertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLX509CertificateTypeHandler_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetCertificateType(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetDataForRemote(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, int32_t CipherSuite, TSBKeyExchangeAlgorithmRaw KeyExchange, uint8_t pData[], int32_t * szData, int32_t Optional, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_ValidateRemoteCert(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t Optional, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetRemoteKeyMaterial(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, const uint8_t pData[], int32_t szData, int32_t KeyType, int32_t * PKType, int32_t * KeyAlgorithm, TElKeyMaterialHandle * KeyMaterial);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetKeyMaterial(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, TElKeyMaterialHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetPublicKeySize(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_GetPublicKeyAlgorithm(TElSSLRawKeyCertificateTypeHandlerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLRawKeyCertificateTypeHandler_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELDTLSFLIGHTITEM
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_Epoch(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_ContentType(TElDTLSFlightItemHandle _Handle, TSSL3ContentTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_Data(TElDTLSFlightItemHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_Length(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_MessageSeq(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_FragmentOffset(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_FragmentLength(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_get_HandshakeType(TElDTLSFlightItemHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_Create(TSSL3ContentTypeRaw ContentType, void * Header, int32_t HeaderLen, void * Data, int32_t DataLen, int32_t Epoch, TElDTLSFlightItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_Create_1(int32_t HandshakeType, int32_t Len, int32_t MessageSeq, int32_t FragmentOffset, int32_t FragmentLength, void * Fragment, TElDTLSFlightItemHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElDTLSFlightItem_CreateChangeCipherSpec(TElDTLSFlightItemHandle * OutResult);
#endif /* SB_USE_CLASS_TELDTLSFLIGHTITEM */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSLCertificateTypeHandler;
typedef TElSSLCertificateTypeHandler ElSSLCertificateTypeHandler;
class TElCustomSSLExtension;
typedef TElCustomSSLExtension ElCustomSSLExtension;
class TElSSLClass;
typedef TElSSLClass ElSSLClass;
class TElSSLConnectionInfo;
class TElSSLServerName;
typedef TElSSLServerName ElSSLServerName;
class TElHeartbeatHelloSSLExtension;
typedef TElHeartbeatHelloSSLExtension ElHeartbeatHelloSSLExtension;
class TElServerNameSSLExtension;
typedef TElServerNameSSLExtension ElServerNameSSLExtension;
class TElUserNameSSLExtension;
typedef TElUserNameSSLExtension ElUserNameSSLExtension;
class TElECCurveSSLExtension;
class TElECPointSSLExtension;
class TElCertificateTypeResponse;
class TElCertificateTypeRequest;
class TElExtendedMasterSecretExtension;
typedef TElExtendedMasterSecretExtension ElExtendedMasterSecretExtension;
class TElMaxFragmentLengthSSLExtension;
typedef TElMaxFragmentLengthSSLExtension ElMaxFragmentLengthSSLExtension;
class TElSSLCertURL;
typedef TElSSLCertURL ElSSLCertURL;
class TElClientCertURLsSSLExtension;
typedef TElClientCertURLsSSLExtension ElClientCertURLsSSLExtension;
class TElSSLTrustedCA;
typedef TElSSLTrustedCA ElSSLTrustedCA;
class TElTrustedCAsSSLExtension;
typedef TElTrustedCAsSSLExtension ElTrustedCAsSSLExtension;
class TElTruncatedHMACSSLExtension;
typedef TElTruncatedHMACSSLExtension ElTruncatedHMACSSLExtension;
class TElSSLOCSPStatusRequest;
typedef TElSSLOCSPStatusRequest ElSSLOCSPStatusRequest;
class TElCertificateStatusSSLExtension;
typedef TElCertificateStatusSSLExtension ElCertificateStatusSSLExtension;
class TElSessionTicketSSLExtension;
class TElCertHashTypesSSLExtension;
class TElRenegotiationInfoSSLExtension;
class TElSignatureAlgorithmsSSLExtension;
class TElSRPSSLExtension;
class TElCustomSSLExtensions;
typedef TElCustomSSLExtensions ElCustomSSLExtensions;
class TElClientSSLExtensions;
typedef TElClientSSLExtensions ElClientSSLExtensions;
class TElServerSSLExtensions;
typedef TElServerSSLExtensions ElServerSSLExtensions;
class TElSSLRetransmissionTimer;
class TElSSLMemoryManager;
class TElSSLX509CertificateTypeHandler;
typedef TElSSLX509CertificateTypeHandler ElSSLX509CertificateTypeHandler;
class TElSSLRawKeyCertificateTypeHandler;
typedef TElSSLRawKeyCertificateTypeHandler ElSSLRawKeyCertificateTypeHandler;
class TElDTLSFlightItem;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSSLOptions)

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
class TElSSLCertificateTypeHandler: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSLCertificateTypeHandler)
	public:
		virtual TElSSLCertificateType GetCertificateType();

		virtual int32_t GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional);

		virtual bool ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual void GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle GetKeyMaterial();
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		virtual int32_t GetPublicKeySize();

		virtual int32_t GetPublicKeyAlgorithm();

		virtual int32_t get_KeyIndex();

		virtual void set_KeyIndex(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_KeyIndex, set_KeyIndex, TElSSLCertificateTypeHandler, KeyIndex);

		virtual int32_t get_KeyCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyCount, TElSSLCertificateTypeHandler, KeyCount);

#ifdef SB_USE_CLASS_IELSSLCERTIFICATEHANDLERCONTAINER
		virtual IElSSLCertificateHandlerContainerHandle get_SSLClass();

		virtual void set_SSLClass(IElSSLCertificateHandlerContainerHandle Value);

		SB_DECLARE_PROPERTY(IElSSLCertificateHandlerContainerHandle, get_SSLClass, set_SSLClass, TElSSLCertificateTypeHandler, SSLClass);
#endif /* SB_USE_CLASS_IELSSLCERTIFICATEHANDLERCONTAINER */

		TElSSLCertificateTypeHandler(TElSSLCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLCertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLCertificateTypeHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
class TElCustomSSLExtension: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		virtual int32_t get_ExtensionType();

		virtual void set_ExtensionType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ExtensionType, set_ExtensionType, TElCustomSSLExtension, ExtensionType);

		virtual void get_ExtensionData(std::vector<uint8_t> &OutResult);

		virtual void set_ExtensionData(const std::vector<uint8_t> &Value);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElCustomSSLExtension, Enabled);

		virtual bool get_Server();

		virtual void set_Server(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Server, set_Server, TElCustomSSLExtension, Server);

		TElCustomSSLExtension(TElCustomSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElCustomSSLExtension();

};
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCLASS
class TElSSLClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSLClass)
#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		TElSSLConnectionInfo* _Inst_ConnectionInfo;
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void AddCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void AddCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER
		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler &Handler);

		void RemoveCertTypeHandler(TElSSLCertificateTypeHandler *Handler);
#endif /* SB_USE_CLASS_TELSSLCERTIFICATETYPEHANDLER */

		void EnterCS();

		void LeaveCS();

		virtual void AssignFromTemplate(TElSSLClass &Tpl);

		virtual void AssignFromTemplate(TElSSLClass *Tpl);

		virtual bool get_CipherSuites(uint8_t Index);

		virtual void set_CipherSuites(uint8_t Index, bool Value);

		virtual int32_t get_CipherSuitePriorities(uint8_t Index);

		virtual void set_CipherSuitePriorities(uint8_t Index, int32_t Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSLClass, Active);

		virtual TSBVersion get_CurrentVersion();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_CurrentVersion, TElSSLClass, CurrentVersion);

		virtual uint8_t get_CompressionAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithm, TElSSLClass, CompressionAlgorithm);

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSSLClass, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSSLClass, TotalBytesReceived);

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
		virtual TElSSLConnectionInfo* get_ConnectionInfo();

		SB_DECLARE_PROPERTY_GET(TElSSLConnectionInfo*, get_ConnectionInfo, TElSSLClass, ConnectionInfo);
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElSSLClass, Versions);

		virtual TSBSSLOptions get_Options();

		virtual void set_Options(TSBSSLOptions Value);

		SB_DECLARE_PROPERTY(TSBSSLOptions, get_Options, set_Options, TElSSLClass, Options);

		virtual TSBRenegotiationAttackPreventionMode get_RenegotiationAttackPreventionMode();

		virtual void set_RenegotiationAttackPreventionMode(TSBRenegotiationAttackPreventionMode Value);

		SB_DECLARE_PROPERTY(TSBRenegotiationAttackPreventionMode, get_RenegotiationAttackPreventionMode, set_RenegotiationAttackPreventionMode, TElSSLClass, RenegotiationAttackPreventionMode);

		virtual void get_OnSend(TSBSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSBReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnData(TSBDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSBDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSBOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSBOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateValidate(TSBCertificateValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateValidate(TSBCertificateValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnRawPublicKeyValidate(TSBRawPublicKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRawPublicKeyValidate(TSBRawPublicKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsReceived(TSBExtensionsReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsReceived(TSBExtensionsReceivedEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtensionsPrepared(TSBExtensionsPreparedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtensionsPrepared(TSBExtensionsPreparedEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeepAliveResponse(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeepAliveResponse(TNotifyEvent pMethodValue, void * pDataValue);

		TElSSLClass(TElSSLClassHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLClass(TComponent &Owner);

		explicit TElSSLClass(TComponent *Owner);

		virtual ~TElSSLClass();

};
#endif /* SB_USE_CLASS_TELSSLCLASS */

#ifdef SB_USE_CLASS_TELSSLCONNECTIONINFO
class TElSSLConnectionInfo: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLConnectionInfo)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientChain;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ServerChain;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		void initInstances();

	public:
		void InitializeNonSecure();

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);

		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void Reset();

		virtual int32_t get_Ciphersuite();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Ciphersuite, TElSSLConnectionInfo, Ciphersuite);

		virtual void get_CiphersuiteName(std::string &OutResult);

		virtual TSBEncryptAlgorithm get_EncryptionAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBEncryptAlgorithm, get_EncryptionAlgorithm, TElSSLConnectionInfo, EncryptionAlgorithm);

		virtual TSBKeyExchangeAlgorithm get_KeyExchangeAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBKeyExchangeAlgorithm, get_KeyExchangeAlgorithm, TElSSLConnectionInfo, KeyExchangeAlgorithm);

		virtual TSBSignatureAlgorithm get_SignatureAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBSignatureAlgorithm, get_SignatureAlgorithm, TElSSLConnectionInfo, SignatureAlgorithm);

		virtual TSBDigestAlgorithm get_DigestAlgorithm();

		SB_DECLARE_PROPERTY_GET(TSBDigestAlgorithm, get_DigestAlgorithm, TElSSLConnectionInfo, DigestAlgorithm);

		virtual TSBVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSBVersion, get_Version, TElSSLConnectionInfo, Version);

		virtual bool get_Exportable();

		SB_DECLARE_PROPERTY_GET(bool, get_Exportable, TElSSLConnectionInfo, Exportable);

		virtual int32_t get_SymmetricKeyBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SymmetricKeyBits, TElSSLConnectionInfo, SymmetricKeyBits);

		virtual int32_t get_PublicKeyBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_PublicKeyBits, TElSSLConnectionInfo, PublicKeyBits);

		virtual int32_t get_KeyExchangeKeyBits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_KeyExchangeKeyBits, TElSSLConnectionInfo, KeyExchangeKeyBits);

		virtual int32_t get_SymmetricBlockSize();

		SB_DECLARE_PROPERTY_GET(int32_t, get_SymmetricBlockSize, TElSSLConnectionInfo, SymmetricBlockSize);

		virtual bool get_AEADCipher();

		SB_DECLARE_PROPERTY_GET(bool, get_AEADCipher, TElSSLConnectionInfo, AEADCipher);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientChain();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_ClientChain, TElSSLConnectionInfo, ClientChain);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ServerChain();

		SB_DECLARE_PROPERTY_GET(TElCustomCertStorage*, get_ServerChain, TElSSLConnectionInfo, ServerChain);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void get_SessionID(std::vector<uint8_t> &OutResult);

		virtual bool get_ResumedSession();

		SB_DECLARE_PROPERTY_GET(bool, get_ResumedSession, TElSSLConnectionInfo, ResumedSession);

		virtual bool get_ConnectionEstablished();

		SB_DECLARE_PROPERTY_GET(bool, get_ConnectionEstablished, TElSSLConnectionInfo, ConnectionEstablished);

		virtual bool get_PFSCipher();

		SB_DECLARE_PROPERTY_GET(bool, get_PFSCipher, TElSSLConnectionInfo, PFSCipher);

		virtual bool get_ClientAuthenticated();

		SB_DECLARE_PROPERTY_GET(bool, get_ClientAuthenticated, TElSSLConnectionInfo, ClientAuthenticated);

		virtual bool get_ServerAuthenticated();

		SB_DECLARE_PROPERTY_GET(bool, get_ServerAuthenticated, TElSSLConnectionInfo, ServerAuthenticated);

		virtual bool get_SecureConnection();

		SB_DECLARE_PROPERTY_GET(bool, get_SecureConnection, TElSSLConnectionInfo, SecureConnection);

		virtual int32_t get_NamedECCurve();

		SB_DECLARE_PROPERTY_GET(int32_t, get_NamedECCurve, TElSSLConnectionInfo, NamedECCurve);

		TElSSLConnectionInfo(TElSSLConnectionInfoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElSSLConnectionInfo(TElSSLClass &Owner);

		explicit TElSSLConnectionInfo(TElSSLClass *Owner);
#endif /* SB_USE_CLASS_TELSSLCLASS */

		virtual ~TElSSLConnectionInfo();

};
#endif /* SB_USE_CLASS_TELSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVERNAME
class TElSSLServerName: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLServerName)
	public:
		virtual TSBSSLServerNameType get_NameType();

		virtual void set_NameType(TSBSSLServerNameType Value);

		SB_DECLARE_PROPERTY(TSBSSLServerNameType, get_NameType, set_NameType, TElSSLServerName, NameType);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		TElSSLServerName(TElSSLServerNameHandle handle, TElOwnHandle ownHandle);

		TElSSLServerName();

};
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
class TElHeartbeatHelloSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElHeartbeatHelloSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual uint8_t get_Mode();

		virtual void set_Mode(uint8_t Value);

		SB_DECLARE_PROPERTY(uint8_t, get_Mode, set_Mode, TElHeartbeatHelloSSLExtension, Mode);

		TElHeartbeatHelloSSLExtension(TElHeartbeatHelloSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElHeartbeatHelloSSLExtension();

};
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
class TElServerNameSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElServerNameSSLExtension)
#ifdef SB_USE_CLASS_TELSSLSERVERNAME
		TElSSLServerName* _Inst_Names;
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		int32_t Add();

		void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSSLSERVERNAME
		virtual TElSSLServerName* get_Names(int32_t Index);
#endif /* SB_USE_CLASS_TELSSLSERVERNAME */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElServerNameSSLExtension, Count);

		TElServerNameSSLExtension(TElServerNameSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElServerNameSSLExtension();

		virtual ~TElServerNameSSLExtension();

};
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
class TElUserNameSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElUserNameSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		TElUserNameSSLExtension(TElUserNameSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElUserNameSSLExtension();

};
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
class TElECCurveSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElECCurveSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		void SetCurves(int32_t Curve, bool Enabled);

		bool IsCurveEnabled(int32_t Curve);

		int32_t GetCurve(int32_t Index);

		int32_t GetCurveCount();

		TElECCurveSSLExtension(TElECCurveSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElECCurveSSLExtension();

};
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
class TElECPointSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElECPointSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		void SetPointType(uint8_t Point, bool Enabled);

		bool GetPointType(uint8_t Point);

		TElECPointSSLExtension(TElECPointSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElECPointSSLExtension();

};
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
class TElCertificateTypeResponse: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElCertificateTypeResponse)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual TElSSLCertificateType get_CertType();

		virtual void set_CertType(TElSSLCertificateType Value);

		SB_DECLARE_PROPERTY(TElSSLCertificateType, get_CertType, set_CertType, TElCertificateTypeResponse, CertType);

		TElCertificateTypeResponse(TElCertificateTypeResponseHandle handle, TElOwnHandle ownHandle);

		TElCertificateTypeResponse();

};
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
class TElCertificateTypeRequest: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElCertificateTypeRequest)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		void AddCertType(TElSSLCertificateType Value);

		void DelCertType(TElSSLCertificateType Value);

		int32_t GetCertTypesCount();

		void ClearCertTypes();

		bool CheckCertType(TElSSLCertificateType Value);

		TElSSLCertificateType GetBaseCertType();

		virtual TElSSLCertificateType get_CertTypes(int32_t Index);

		virtual void set_CertTypes(int32_t Index, TElSSLCertificateType Value);

		TElCertificateTypeRequest(TElCertificateTypeRequestHandle handle, TElOwnHandle ownHandle);

		TElCertificateTypeRequest();

};
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
class TElExtendedMasterSecretExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElExtendedMasterSecretExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		TElExtendedMasterSecretExtension(TElExtendedMasterSecretExtensionHandle handle, TElOwnHandle ownHandle);

		TElExtendedMasterSecretExtension();

};
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
class TElMaxFragmentLengthSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElMaxFragmentLengthSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		virtual TSBSSLFragmentLength get_MaxLength();

		virtual void set_MaxLength(TSBSSLFragmentLength Value);

		SB_DECLARE_PROPERTY(TSBSSLFragmentLength, get_MaxLength, set_MaxLength, TElMaxFragmentLengthSSLExtension, MaxLength);

		TElMaxFragmentLengthSSLExtension(TElMaxFragmentLengthSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElMaxFragmentLengthSSLExtension();

};
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLCERTURL
class TElSSLCertURL: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLCertURL)
#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		TElPublicKeyMaterial* _Inst_PrivateKey;
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		void initInstances();

	public:
		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_Hash(std::vector<uint8_t> &OutResult);

		virtual void set_Hash(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELPUBLICKEYMATERIAL
		virtual TElPublicKeyMaterial* get_PrivateKey();

		virtual void set_PrivateKey(TElPublicKeyMaterial &Value);

		virtual void set_PrivateKey(TElPublicKeyMaterial *Value);

		SB_DECLARE_PROPERTY(TElPublicKeyMaterial*, get_PrivateKey, set_PrivateKey, TElSSLCertURL, PrivateKey);
#endif /* SB_USE_CLASS_TELPUBLICKEYMATERIAL */

		TElSSLCertURL(TElSSLCertURLHandle handle, TElOwnHandle ownHandle);

		TElSSLCertURL();

		virtual ~TElSSLCertURL();

};
#endif /* SB_USE_CLASS_TELSSLCERTURL */

#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
class TElClientCertURLsSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElClientCertURLsSSLExtension)
#ifdef SB_USE_CLASS_TELSSLCERTURL
		TElSSLCertURL* _Inst_URLs;
#endif /* SB_USE_CLASS_TELSSLCERTURL */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		int32_t Add();

		void Remove(int32_t Index);

		virtual void Clear();

		virtual TSBCertChainType get_ChainType();

		virtual void set_ChainType(TSBCertChainType Value);

		SB_DECLARE_PROPERTY(TSBCertChainType, get_ChainType, set_ChainType, TElClientCertURLsSSLExtension, ChainType);

#ifdef SB_USE_CLASS_TELSSLCERTURL
		virtual TElSSLCertURL* get_URLs(int32_t Index);
#endif /* SB_USE_CLASS_TELSSLCERTURL */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElClientCertURLsSSLExtension, Count);

		TElClientCertURLsSSLExtension(TElClientCertURLsSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElClientCertURLsSSLExtension();

		virtual ~TElClientCertURLsSSLExtension();

};
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
class TElSSLTrustedCA: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLTrustedCA)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_RDN;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELX509CERTIFICATE
		void Import(TElX509Certificate &Cert);

		void Import(TElX509Certificate *Cert);
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

		virtual TSBCAIdentifierType get_IdentifierType();

		virtual void set_IdentifierType(TSBCAIdentifierType Value);

		SB_DECLARE_PROPERTY(TSBCAIdentifierType, get_IdentifierType, set_IdentifierType, TElSSLTrustedCA, IdentifierType);

		virtual void get_Value(std::vector<uint8_t> &OutResult);

		virtual void set_Value(const std::vector<uint8_t> &Value);

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_RDN();

		SB_DECLARE_PROPERTY_GET(TElRelativeDistinguishedName*, get_RDN, TElSSLTrustedCA, RDN);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		TElSSLTrustedCA(TElSSLTrustedCAHandle handle, TElOwnHandle ownHandle);

		TElSSLTrustedCA();

		virtual ~TElSSLTrustedCA();

};
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
class TElTrustedCAsSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElTrustedCAsSSLExtension)
#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
		TElSSLTrustedCA* _Inst_TrustedCAs;
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		int32_t Add();

		void Remove(int32_t Index);

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSSLTRUSTEDCA
		virtual TElSSLTrustedCA* get_TrustedCAs(int32_t Index);
#endif /* SB_USE_CLASS_TELSSLTRUSTEDCA */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElTrustedCAsSSLExtension, Count);

		TElTrustedCAsSSLExtension(TElTrustedCAsSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElTrustedCAsSSLExtension();

		virtual ~TElTrustedCAsSSLExtension();

};
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
class TElTruncatedHMACSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElTruncatedHMACSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		TElTruncatedHMACSSLExtension(TElTruncatedHMACSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElTruncatedHMACSSLExtension();

};
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
class TElSSLOCSPStatusRequest: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLOCSPStatusRequest)
	public:
		virtual void get_ResponderIDs(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_ResponderIDs(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_ResponderIDCount();

		virtual void set_ResponderIDCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ResponderIDCount, set_ResponderIDCount, TElSSLOCSPStatusRequest, ResponderIDCount);

		virtual void get_Extensions(std::vector<uint8_t> &OutResult);

		virtual void set_Extensions(const std::vector<uint8_t> &Value);

		TElSSLOCSPStatusRequest(TElSSLOCSPStatusRequestHandle handle, TElOwnHandle ownHandle);

		TElSSLOCSPStatusRequest();

};
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
class TElCertificateStatusSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElCertificateStatusSSLExtension)
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
		TElSSLOCSPStatusRequest* _Inst_OCSPStatusRequest;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */
#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
		TElSSLOCSPStatusRequest* _Inst_OCSPStatusRequests;
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		int32_t AddOCSPStatusRequest();

		void RemoveOCSPStatusRequest(int32_t Index);

		virtual TSBCertificateStatusType get_StatusType();

		virtual void set_StatusType(TSBCertificateStatusType Value);

		SB_DECLARE_PROPERTY(TSBCertificateStatusType, get_StatusType, set_StatusType, TElCertificateStatusSSLExtension, StatusType);

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
		virtual TElSSLOCSPStatusRequest* get_OCSPStatusRequest();

		SB_DECLARE_PROPERTY_GET(TElSSLOCSPStatusRequest*, get_OCSPStatusRequest, TElCertificateStatusSSLExtension, OCSPStatusRequest);
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

#ifdef SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST
		virtual TElSSLOCSPStatusRequest* get_OCSPStatusRequests(int32_t Index);
#endif /* SB_USE_CLASS_TELSSLOCSPSTATUSREQUEST */

		virtual int32_t get_OCSPStatusRequestCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OCSPStatusRequestCount, TElCertificateStatusSSLExtension, OCSPStatusRequestCount);

		virtual void get_OCSPResponse(std::vector<uint8_t> &OutResult);

		virtual void set_OCSPResponse(const std::vector<uint8_t> &Value);

		virtual void get_OCSPResponses(int32_t Index, std::vector<uint8_t> &OutResult);

		virtual void set_OCSPResponses(int32_t Index, const std::vector<uint8_t> &Value);

		virtual int32_t get_OCSPResponseCount();

		virtual void set_OCSPResponseCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OCSPResponseCount, set_OCSPResponseCount, TElCertificateStatusSSLExtension, OCSPResponseCount);

		TElCertificateStatusSSLExtension(TElCertificateStatusSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElCertificateStatusSSLExtension();

		virtual ~TElCertificateStatusSSLExtension();

};
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION
class TElSessionTicketSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElSessionTicketSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		virtual void get_Ticket(std::vector<uint8_t> &OutResult);

		virtual void set_Ticket(const std::vector<uint8_t> &Value);

		TElSessionTicketSSLExtension(TElSessionTicketSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElSessionTicketSSLExtension();

};
#endif /* SB_USE_CLASS_TELSESSIONTICKETSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
class TElCertHashTypesSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElCertHashTypesSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		void SwitchAll(bool Value);

		virtual bool get_MD5();

		virtual void set_MD5(bool Value);

		SB_DECLARE_PROPERTY(bool, get_MD5, set_MD5, TElCertHashTypesSSLExtension, MD5);

		virtual bool get_SHA1();

		virtual void set_SHA1(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SHA1, set_SHA1, TElCertHashTypesSSLExtension, SHA1);

		virtual bool get_SHA256();

		virtual void set_SHA256(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SHA256, set_SHA256, TElCertHashTypesSSLExtension, SHA256);

		virtual bool get_SHA384();

		virtual void set_SHA384(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SHA384, set_SHA384, TElCertHashTypesSSLExtension, SHA384);

		virtual bool get_SHA512();

		virtual void set_SHA512(bool Value);

		SB_DECLARE_PROPERTY(bool, get_SHA512, set_SHA512, TElCertHashTypesSSLExtension, SHA512);

		TElCertHashTypesSSLExtension(TElCertHashTypesSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElCertHashTypesSSLExtension();

};
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */

#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
class TElRenegotiationInfoSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElRenegotiationInfoSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		virtual void get_Info(std::vector<uint8_t> &OutResult);

		virtual void set_Info(const std::vector<uint8_t> &Value);

		virtual bool get_UseSignalingCipherSuite();

		virtual void set_UseSignalingCipherSuite(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseSignalingCipherSuite, set_UseSignalingCipherSuite, TElRenegotiationInfoSSLExtension, UseSignalingCipherSuite);

		TElRenegotiationInfoSSLExtension(TElRenegotiationInfoSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElRenegotiationInfoSSLExtension();

};
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
class TElSignatureAlgorithmsSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElSignatureAlgorithmsSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void Clear();

		void EnableAllSupported();

		virtual int32_t get_Count();

		virtual void set_Count(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Count, set_Count, TElSignatureAlgorithmsSSLExtension, Count);

		virtual int32_t get_HashAlgorithms(int32_t Index);

		virtual void set_HashAlgorithms(int32_t Index, int32_t Value);

		virtual int32_t get_SignatureAlgorithms(int32_t Index);

		virtual void set_SignatureAlgorithms(int32_t Index, int32_t Value);

		TElSignatureAlgorithmsSSLExtension(TElSignatureAlgorithmsSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElSignatureAlgorithmsSSLExtension();

};
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
class TElSRPSSLExtension: public TElCustomSSLExtension
{
	private:
		SB_DISABLE_COPY(TElSRPSSLExtension)
	public:
		virtual void Assign(TElCustomSSLExtension &Source);

		virtual void Assign(TElCustomSSLExtension *Source);

		virtual void get_Name(std::string &OutResult);

		virtual void set_Name(const std::string &Value);

		TElSRPSSLExtension(TElSRPSSLExtensionHandle handle, TElOwnHandle ownHandle);

		TElSRPSSLExtension();

};
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS
class TElCustomSSLExtensions: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSSLExtensions)
#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
		TElCertificateStatusSSLExtension* _Inst_CertificateStatus;
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
		TElClientCertURLsSSLExtension* _Inst_ClientCertURLs;
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
		TElMaxFragmentLengthSSLExtension* _Inst_MaxFragmentLength;
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
		TElCustomSSLExtension* _Inst_OtherExtensions;
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
		TElServerNameSSLExtension* _Inst_ServerName;
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
		TElTruncatedHMACSSLExtension* _Inst_TruncatedHMAC;
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */
#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
		TElTrustedCAsSSLExtension* _Inst_TrustedCAs;
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */
#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
		TElUserNameSSLExtension* _Inst_UserName;
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
		TElECCurveSSLExtension* _Inst_ECCurves;
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */
#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
		TElECPointSSLExtension* _Inst_ECPoints;
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */
#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
		TElCertHashTypesSSLExtension* _Inst_CertHashTypes;
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */
#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
		TElRenegotiationInfoSSLExtension* _Inst_RenegotiationInfo;
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
		TElHeartbeatHelloSSLExtension* _Inst_Heartbeat;
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
		TElSignatureAlgorithmsSSLExtension* _Inst_SignatureAlgorithms;
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */
#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
		TElSRPSSLExtension* _Inst_SRP;
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */
#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
		TElExtendedMasterSecretExtension* _Inst_ExtendedMasterSecret;
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtensions &Source);

		virtual void Assign(TElCustomSSLExtensions *Source);

		virtual void Clear();

		virtual void DisableAll();

#ifdef SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION
		virtual TElCertificateStatusSSLExtension* get_CertificateStatus();

		SB_DECLARE_PROPERTY_GET(TElCertificateStatusSSLExtension*, get_CertificateStatus, TElCustomSSLExtensions, CertificateStatus);
#endif /* SB_USE_CLASS_TELCERTIFICATESTATUSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION
		virtual TElClientCertURLsSSLExtension* get_ClientCertURLs();

		SB_DECLARE_PROPERTY_GET(TElClientCertURLsSSLExtension*, get_ClientCertURLs, TElCustomSSLExtensions, ClientCertURLs);
#endif /* SB_USE_CLASS_TELCLIENTCERTURLSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION
		virtual TElMaxFragmentLengthSSLExtension* get_MaxFragmentLength();

		SB_DECLARE_PROPERTY_GET(TElMaxFragmentLengthSSLExtension*, get_MaxFragmentLength, TElCustomSSLExtensions, MaxFragmentLength);
#endif /* SB_USE_CLASS_TELMAXFRAGMENTLENGTHSSLEXTENSION */

		virtual int32_t get_OtherCount();

		virtual void set_OtherCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_OtherCount, set_OtherCount, TElCustomSSLExtensions, OtherCount);

#ifdef SB_USE_CLASS_TELCUSTOMSSLEXTENSION
		virtual TElCustomSSLExtension* get_OtherExtensions(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSERVERNAMESSLEXTENSION
		virtual TElServerNameSSLExtension* get_ServerName();

		SB_DECLARE_PROPERTY_GET(TElServerNameSSLExtension*, get_ServerName, TElCustomSSLExtensions, ServerName);
#endif /* SB_USE_CLASS_TELSERVERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION
		virtual TElTruncatedHMACSSLExtension* get_TruncatedHMAC();

		SB_DECLARE_PROPERTY_GET(TElTruncatedHMACSSLExtension*, get_TruncatedHMAC, TElCustomSSLExtensions, TruncatedHMAC);
#endif /* SB_USE_CLASS_TELTRUNCATEDHMACSSLEXTENSION */

#ifdef SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION
		virtual TElTrustedCAsSSLExtension* get_TrustedCAs();

		SB_DECLARE_PROPERTY_GET(TElTrustedCAsSSLExtension*, get_TrustedCAs, TElCustomSSLExtensions, TrustedCAs);
#endif /* SB_USE_CLASS_TELTRUSTEDCASSSLEXTENSION */

#ifdef SB_USE_CLASS_TELUSERNAMESSLEXTENSION
		virtual TElUserNameSSLExtension* get_UserName();

		SB_DECLARE_PROPERTY_GET(TElUserNameSSLExtension*, get_UserName, TElCustomSSLExtensions, UserName);
#endif /* SB_USE_CLASS_TELUSERNAMESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECCURVESSLEXTENSION
		virtual TElECCurveSSLExtension* get_ECCurves();

		SB_DECLARE_PROPERTY_GET(TElECCurveSSLExtension*, get_ECCurves, TElCustomSSLExtensions, ECCurves);
#endif /* SB_USE_CLASS_TELECCURVESSLEXTENSION */

#ifdef SB_USE_CLASS_TELECPOINTSSLEXTENSION
		virtual TElECPointSSLExtension* get_ECPoints();

		SB_DECLARE_PROPERTY_GET(TElECPointSSLExtension*, get_ECPoints, TElCustomSSLExtensions, ECPoints);
#endif /* SB_USE_CLASS_TELECPOINTSSLEXTENSION */

		virtual bool get_StatelessTLS();

		virtual void set_StatelessTLS(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StatelessTLS, set_StatelessTLS, TElCustomSSLExtensions, StatelessTLS);

#ifdef SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION
		virtual TElCertHashTypesSSLExtension* get_CertHashTypes();

		SB_DECLARE_PROPERTY_GET(TElCertHashTypesSSLExtension*, get_CertHashTypes, TElCustomSSLExtensions, CertHashTypes);
#endif /* SB_USE_CLASS_TELCERTHASHTYPESSSLEXTENSION */

#ifdef SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION
		virtual TElRenegotiationInfoSSLExtension* get_RenegotiationInfo();

		virtual void set_RenegotiationInfo(TElRenegotiationInfoSSLExtension &Value);

		virtual void set_RenegotiationInfo(TElRenegotiationInfoSSLExtension *Value);

		SB_DECLARE_PROPERTY(TElRenegotiationInfoSSLExtension*, get_RenegotiationInfo, set_RenegotiationInfo, TElCustomSSLExtensions, RenegotiationInfo);
#endif /* SB_USE_CLASS_TELRENEGOTIATIONINFOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION
		virtual TElHeartbeatHelloSSLExtension* get_Heartbeat();

		SB_DECLARE_PROPERTY_GET(TElHeartbeatHelloSSLExtension*, get_Heartbeat, TElCustomSSLExtensions, Heartbeat);
#endif /* SB_USE_CLASS_TELHEARTBEATHELLOSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION
		virtual TElSignatureAlgorithmsSSLExtension* get_SignatureAlgorithms();

		SB_DECLARE_PROPERTY_GET(TElSignatureAlgorithmsSSLExtension*, get_SignatureAlgorithms, TElCustomSSLExtensions, SignatureAlgorithms);
#endif /* SB_USE_CLASS_TELSIGNATUREALGORITHMSSSLEXTENSION */

#ifdef SB_USE_CLASS_TELSRPSSLEXTENSION
		virtual TElSRPSSLExtension* get_SRP();

		SB_DECLARE_PROPERTY_GET(TElSRPSSLExtension*, get_SRP, TElCustomSSLExtensions, SRP);
#endif /* SB_USE_CLASS_TELSRPSSLEXTENSION */

#ifdef SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION
		virtual TElExtendedMasterSecretExtension* get_ExtendedMasterSecret();

		SB_DECLARE_PROPERTY_GET(TElExtendedMasterSecretExtension*, get_ExtendedMasterSecret, TElCustomSSLExtensions, ExtendedMasterSecret);
#endif /* SB_USE_CLASS_TELEXTENDEDMASTERSECRETEXTENSION */

		TElCustomSSLExtensions(TElCustomSSLExtensionsHandle handle, TElOwnHandle ownHandle);

		TElCustomSSLExtensions();

		virtual ~TElCustomSSLExtensions();

};
#endif /* SB_USE_CLASS_TELCUSTOMSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
class TElClientSSLExtensions: public TElCustomSSLExtensions
{
	private:
		SB_DISABLE_COPY(TElClientSSLExtensions)
#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		TElRelativeDistinguishedName* _Inst_AcceptableCAs;
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
		TElCertificateTypeRequest* _Inst_ServerCertificateType;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
		TElCertificateTypeRequest* _Inst_ClientCertificateType;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtensions &Source);

		virtual void Assign(TElCustomSSLExtensions *Source);

		virtual void Clear();

		virtual void DisableAll();

		void ClearAcceptableCAs();

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		void AddAcceptableCAs(TElRelativeDistinguishedName &Value);

		void AddAcceptableCAs(TElRelativeDistinguishedName *Value);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

#ifdef SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME
		virtual TElRelativeDistinguishedName* get_AcceptableCAs(int32_t Index);
#endif /* SB_USE_CLASS_TELRELATIVEDISTINGUISHEDNAME */

		virtual int32_t get_AcceptableCACount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_AcceptableCACount, TElClientSSLExtensions, AcceptableCACount);

		virtual bool get_FallbackConnection();

		virtual void set_FallbackConnection(bool Value);

		SB_DECLARE_PROPERTY(bool, get_FallbackConnection, set_FallbackConnection, TElClientSSLExtensions, FallbackConnection);

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
		virtual TElCertificateTypeRequest* get_ServerCertificateType();

		SB_DECLARE_PROPERTY_GET(TElCertificateTypeRequest*, get_ServerCertificateType, TElClientSSLExtensions, ServerCertificateType);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPEREQUEST
		virtual TElCertificateTypeRequest* get_ClientCertificateType();

		SB_DECLARE_PROPERTY_GET(TElCertificateTypeRequest*, get_ClientCertificateType, TElClientSSLExtensions, ClientCertificateType);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPEREQUEST */

		TElClientSSLExtensions(TElClientSSLExtensionsHandle handle, TElOwnHandle ownHandle);

		TElClientSSLExtensions();

		virtual ~TElClientSSLExtensions();

};
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
class TElServerSSLExtensions: public TElCustomSSLExtensions
{
	private:
		SB_DISABLE_COPY(TElServerSSLExtensions)
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
		TElCertificateTypeResponse* _Inst_ServerCertificateType;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */
#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
		TElCertificateTypeResponse* _Inst_ClientCertificateType;
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

		void initInstances();

	public:
		virtual void Assign(TElCustomSSLExtensions &Source);

		virtual void Assign(TElCustomSSLExtensions *Source);

		virtual void Clear();

		virtual void DisableAll();

		virtual bool get_StrictCertRequest();

		virtual void set_StrictCertRequest(bool Value);

		SB_DECLARE_PROPERTY(bool, get_StrictCertRequest, set_StrictCertRequest, TElServerSSLExtensions, StrictCertRequest);

		virtual void get_PSKIdentityHint(std::string &OutResult);

		virtual void set_PSKIdentityHint(const std::string &Value);

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
		virtual TElCertificateTypeResponse* get_ServerCertificateType();

		SB_DECLARE_PROPERTY_GET(TElCertificateTypeResponse*, get_ServerCertificateType, TElServerSSLExtensions, ServerCertificateType);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

#ifdef SB_USE_CLASS_TELCERTIFICATETYPERESPONSE
		virtual TElCertificateTypeResponse* get_ClientCertificateType();

		SB_DECLARE_PROPERTY_GET(TElCertificateTypeResponse*, get_ClientCertificateType, TElServerSSLExtensions, ClientCertificateType);
#endif /* SB_USE_CLASS_TELCERTIFICATETYPERESPONSE */

		TElServerSSLExtensions(TElServerSSLExtensionsHandle handle, TElOwnHandle ownHandle);

		TElServerSSLExtensions();

		virtual ~TElServerSSLExtensions();

};
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER
class TElSSLRetransmissionTimer: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLRetransmissionTimer)
	public:
		void Start();

		void Stop();

		virtual int32_t get_Interval();

		virtual void set_Interval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Interval, set_Interval, TElSSLRetransmissionTimer, Interval);

		virtual bool get_Enabled();

		SB_DECLARE_PROPERTY_GET(bool, get_Enabled, TElSSLRetransmissionTimer, Enabled);

		virtual void get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue);

		TElSSLRetransmissionTimer(TElSSLRetransmissionTimerHandle handle, TElOwnHandle ownHandle);

		TElSSLRetransmissionTimer();

};
#endif /* SB_USE_CLASS_TELSSLRETRANSMISSIONTIMER */

#ifdef SB_USE_CLASS_TELSSLMEMORYMANAGER
class TElSSLMemoryManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLMemoryManager)
	public:
		void GetArray(int32_t Len, std::vector<uint8_t> &OutResult);

		void ReleaseArray(std::vector<uint8_t> &Arr);

		void ResizeArray(std::vector<uint8_t> &Arr, int32_t NewSize);

		void ReleaseAll();

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSSLMemoryManager, Enabled);

		virtual int32_t get_MaxCount();

		virtual void set_MaxCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCount, set_MaxCount, TElSSLMemoryManager, MaxCount);

		TElSSLMemoryManager(TElSSLMemoryManagerHandle handle, TElOwnHandle ownHandle);

		TElSSLMemoryManager();

};
#endif /* SB_USE_CLASS_TELSSLMEMORYMANAGER */

#ifdef SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER
class TElSSLX509CertificateTypeHandler: public TElSSLCertificateTypeHandler
{
	private:
		SB_DISABLE_COPY(TElSSLX509CertificateTypeHandler)
	public:
		virtual TElSSLCertificateType GetCertificateType();

		virtual int32_t GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional);

		virtual bool ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual void GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle GetKeyMaterial();
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		virtual int32_t GetPublicKeySize();

		virtual int32_t GetPublicKeyAlgorithm();

		TElSSLX509CertificateTypeHandler(TElSSLX509CertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLX509CertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLX509CertificateTypeHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSLX509CERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER
class TElSSLRawKeyCertificateTypeHandler: public TElSSLCertificateTypeHandler
{
	private:
		SB_DISABLE_COPY(TElSSLRawKeyCertificateTypeHandler)
	public:
		virtual TElSSLCertificateType GetCertificateType();

		virtual int32_t GetDataForRemote(int32_t CipherSuite, TSBKeyExchangeAlgorithm KeyExchange, std::vector<uint8_t> &Data, int32_t Optional);

		virtual bool ValidateRemoteCert(const std::vector<uint8_t> &Data, int32_t Optional);

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual void GetRemoteKeyMaterial(const std::vector<uint8_t> &Data, int32_t KeyType, int32_t &PKType, int32_t &KeyAlgorithm, TElKeyMaterial &KeyMaterial);
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

#ifdef SB_USE_CLASS_TELKEYMATERIAL
		virtual TElKeyMaterialHandle GetKeyMaterial();
#endif /* SB_USE_CLASS_TELKEYMATERIAL */

		virtual int32_t GetPublicKeySize();

		virtual int32_t GetPublicKeyAlgorithm();

		TElSSLRawKeyCertificateTypeHandler(TElSSLRawKeyCertificateTypeHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLRawKeyCertificateTypeHandler(TComponent &AOwner);

		explicit TElSSLRawKeyCertificateTypeHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSLRAWKEYCERTIFICATETYPEHANDLER */

#ifdef SB_USE_CLASS_TELDTLSFLIGHTITEM
class TElDTLSFlightItem: public TObject
{
	private:
		SB_DISABLE_COPY(TElDTLSFlightItem)
	public:
		virtual int32_t get_Epoch();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Epoch, TElDTLSFlightItem, Epoch);

		virtual TSSL3ContentType get_ContentType();

		SB_DECLARE_PROPERTY_GET(TSSL3ContentType, get_ContentType, TElDTLSFlightItem, ContentType);

		virtual void get_Data(std::vector<uint8_t> &OutResult);

		virtual int32_t get_Length();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Length, TElDTLSFlightItem, Length);

		virtual int32_t get_MessageSeq();

		SB_DECLARE_PROPERTY_GET(int32_t, get_MessageSeq, TElDTLSFlightItem, MessageSeq);

		virtual int32_t get_FragmentOffset();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FragmentOffset, TElDTLSFlightItem, FragmentOffset);

		virtual int32_t get_FragmentLength();

		SB_DECLARE_PROPERTY_GET(int32_t, get_FragmentLength, TElDTLSFlightItem, FragmentLength);

		virtual int32_t get_HandshakeType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_HandshakeType, TElDTLSFlightItem, HandshakeType);

		TElDTLSFlightItem(TElDTLSFlightItemHandle handle, TElOwnHandle ownHandle);

		TElDTLSFlightItem(TSSL3ContentType ContentType, void * Header, int32_t HeaderLen, void * Data, int32_t DataLen, int32_t Epoch);

		TElDTLSFlightItem(int32_t HandshakeType, int32_t Len, int32_t MessageSeq, int32_t FragmentOffset, int32_t FragmentLength, void * Fragment);

		static TElDTLSFlightItem CreateChangeCipherSpec();

};
#endif /* SB_USE_CLASS_TELDTLSFLIGHTITEM */

#ifdef SB_USE_GLOBAL_PROCS_SSLCOMMON

int32_t ConvertToErrorCode(TSBAlertDescription Desc);

TSBAlertDescription ConvertSSLError(uint8_t AD);

uint32_t GetSecondsCount();

int32_t GetCurveByTlsCurve(int32_t Curve);

int32_t GetTlsCurveByCurve(int32_t Curve);

void ReadLengthPrefixedArray(void * ABuffer, int32_t ASize, int32_t ALenBytes, int32_t &BytesRead, std::vector<uint8_t> &OutResult);

#ifdef SB_USE_CLASS_TELSSLMEMORYMANAGER
TElSSLMemoryManagerHandle SSLMemoryManager();
#endif /* SB_USE_CLASS_TELSSLMEMORYMANAGER */

#endif /* SB_USE_GLOBAL_PROCS_SSLCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSLCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_ConvertToErrorCode(TSBAlertDescriptionRaw Desc, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_ConvertSSLError(uint8_t AD, TSBAlertDescriptionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_GetSecondsCount(uint32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_GetCurveByTlsCurve(int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_GetTlsCurveByCurve(int32_t Curve, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_ReadLengthPrefixedArray(void * ABuffer, int32_t ASize, int32_t ALenBytes, int32_t * BytesRead, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLCommon_SSLMemoryManager(TElSSLMemoryManagerHandle * OutResult);
#endif /* SB_USE_GLOBAL_PROCS_SSLCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSLCOMMON */

