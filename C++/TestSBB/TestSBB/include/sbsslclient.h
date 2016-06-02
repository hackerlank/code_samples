#ifndef __INC_SBSSLCLIENT
#define __INC_SBSSLCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbasn1tree.h"
#include "sbalgorithmidentifier.h"
#include "sbsslcommon.h"
#include "sbsslconstants.h"
#include "sbrdn.h"
#include "sbocspclient.h"
#include "sbpoly1305.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbsymmetriccrypto.h"
#include "sbhashfunction.h"
#include "sbx509.h"
#include "sbcustomcertstorage.h"
#include "sbzlib.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef WINCE
#define SB_SSLBufferSize 	65536
#define SB_SSLPacketSize 	8192
#define SB_SSLSmallBufferSize 	32768
#define SB_SSLMaxBufferSize 	262144
#else
#define SB_SSLBufferSize 	16384
#define SB_SSLPacketSize 	2048
#define SB_SSLSmallBufferSize 	8192
#define SB_SSLMaxBufferSize 	32768
#endif
#define SB_MIN_SRP_PRIME_LEN 	128

typedef TElClassHandle TElClientSSLConnectionInfoHandle;

typedef TElClassHandle TElSSLClientHandle;

typedef TElSSLClientHandle ElSSLClientHandle;

typedef TElClassHandle TElClientSSLConnectionSettingsHandle;

typedef uint8_t TClientCertificateTypeRaw;

typedef enum
{
	ccRSA = 0,
	ccDSS = 1,
	ccRSADH = 2,
	ccDSSDH = 3,
	ccECDSA = 4,
	ccRSA_ECDH = 5,
	ccECDSA_ECDH = 6
} TClientCertificateType;

typedef void (SB_CALLBACK *TSBChooseCertificateEvent)(void * _ObjectData, TObjectHandle Sender, const TElX509CertificateHandle pCertificates[], int32_t szCertificates, int32_t * CertificateIndex);

typedef void (SB_CALLBACK *TSBCertificateNeededEvent)(void * _ObjectData, TObjectHandle Sender, void * CertificateBuffer, int32_t * CertificateSize, void * PrivateKeyBuffer, int32_t * PrivateKeySize, TClientCertificateTypeRaw CertificateType);

typedef void (SB_CALLBACK *TSBCertificateNeededExEvent)(void * _ObjectData, TObjectHandle Sender, TElX509CertificateHandle * Certificate);

typedef void (SB_CALLBACK *TSBRawPublicKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElPublicKeyMaterialHandle * RawPublicKey);

typedef void (SB_CALLBACK *TSBClientKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcHint, int32_t szHint, char * pcIdentity, int32_t * szIdentity, uint8_t pKey[], int32_t * szKey);

typedef void (SB_CALLBACK *TSBCertificateStatusEvent)(void * _ObjectData, TObjectHandle Sender, TSBCertificateStatusTypeRaw StatusType, TListHandle Data);

typedef uint8_t SBSSLClient_TSBReceiveStateRaw;

typedef enum
{
	_rsRecordHeaderWanted = 0,
	_rsRecordWanted = 1,
	rsOneByteWanted = 2
} SBSSLClient_TSBReceiveState;

typedef uint8_t TSBRoleRaw;

typedef enum
{
	sClient = 0,
	sServer = 1
} TSBRole;

typedef uint8_t TSSL2ContentTypeRaw;

typedef enum
{
	_ctError = 0,
	ctClientHello = 1,
	ctClientMasterKey = 2,
	ctClientFinished = 3,
	ctServerHello = 4,
	ctServerVerify = 5,
	ctServerFinished = 6,
	ctRequestCertificate = 7,
	ctClientCertificate = 8
} TSSL2ContentType;

#pragma pack(4)
typedef struct 
{
	uint8_t Index;
	uint8_t First;
	uint8_t Second;
	uint8_t Third;
	TSBEncryptAlgorithmRaw EncryptAlgorithm;
	int8_t Exportable;
	uint8_t HashSize;
} TSSL2CipherSuite;

typedef uint8_t TSSL2StateRaw;

typedef enum
{
	stAlone = 0,
	stClientHelloSent = 1,
	stServerHelloReceived = 2,
	stClientMasterKeySent = 3,
	stServerVerifyReceived = 4,
	stClientFinishedSent = 5,
	stServerFinishedReceived = 6,
	stEncryptedDataTransfer = 7
} TSSL2State;

typedef uint8_t TSSL2SequenceNumberOwnerRaw;

typedef enum
{
	snServer = 0,
	snClient = 1
} TSSL2SequenceNumberOwner;

typedef uint8_t TSSL3StateRaw;

typedef enum
{
	st3Alone = 0,
	st3ClientHelloSent = 1,
	st3ServerHelloReceived = 2,
	st3CertificateReceived = 3,
	st3ServerKeyExchangeReceived = 4,
	st3CertificateSent = 5,
	st3ClientKeyExchangeSent = 6,
	st3CertificateVerifySent = 7,
	st3ClientChangeCipherSpecSent = 8,
	st3FinishedSent = 9,
	st3ServerChangeCipherSpecReceived = 10,
	st3ServerFinishedReceived = 11,
	st3EncryptedDataTransfer = 12,
	st3ServerHelloDoneReceived = 13,
	_stUnknown = 14
} TSSL3State;

#pragma pack(4)
typedef struct 
{
	uint8_t Index;
	uint8_t First;
	uint8_t Second;
	int8_t Exportable;
	TSBEncryptAlgorithmRaw EncryptAlgorithm;
	TSBDigestAlgorithmRaw DigestAlgorithm;
	TSBKeyExchangeAlgorithmRaw KeyExchangeAlgorithm;
	TSBSignatureAlgorithmRaw SignatureAlgorithm;
	int32_t PRFHashAlgorithm;
	uint8_t HashSize;
	uint8_t RealHashSize;
	uint8_t KeySize;
	uint8_t IVSize;
	uint8_t BlockSize;
	uint8_t PaddingSize;
	int8_t AEADCipher;
} TSSL3CipherSuite;

typedef uint8_t TCloseExplainRaw;

typedef enum
{
	ceNormal = 0,
	ceBadHandshake = 1,
	ceServerClose = 2
} TCloseExplain;

#pragma pack(4)
typedef struct 
{
	TClientCertificateTypeRaw CertificateType;
	int8_t _dummy0;
	int16_t _dummy1;
	void * CertificateData;
	int32_t CertificateSize;
	void * PrivateKeyData;
	int32_t PrivateKeySize;
} TClientCertificate;

typedef uint8_t TSBClientSSLPredefinedConfigurationRaw;

typedef enum
{
	scpcDefault = 0,
	scpcComprehensive = 1,
	scpcHighlySecure = 2,
	scpcOld = 3
} TSBClientSSLPredefinedConfiguration;

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionInfo_Initialize(TElClientSSLConnectionInfoHandle _Handle, TSBVersionRaw Version, uint8_t Ciphersuite, TElCustomCertStorageHandle ServerChain, TElCustomCertStorageHandle ClientChain, const uint8_t pSessionID[], int32_t szSessionID, int8_t ResumedSession);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionInfo_Initialize2(TElClientSSLConnectionInfoHandle _Handle, TSBVersionRaw Version, uint8_t Ciphersuite, TElX509CertificateChainHandle ServerChain, TElCustomCertStorageHandle ClientChain, const uint8_t pSessionID[], int32_t szSessionID, int8_t ResumedSession, int32_t ECCurve);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionInfo_Reset(TElClientSSLConnectionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionInfo_Create(TElSSLClassHandle Owner, TElSSLConnectionInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_Open(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_Close(TElSSLClientHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_DataAvailable(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_SendData(TElSSLClientHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_SendText(TElSSLClientHandle _Handle, const uint8_t pS[], int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_SendKeepAlive(TElSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_InternalValidate(TElSSLClientHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_Resume(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_Join(TElSSLClientHandle _Handle, TElSSLClientHandle ElSecureClient);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_RenegotiateCiphers(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_AddCertificateType(TElSSLClientHandle _Handle, TElSSLCertificateTypeRaw C_Type);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_DelCertificateType(TElSSLClientHandle _Handle, TElSSLCertificateTypeRaw C_Type);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_GetCertTypesCount(TElSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_ClearCertificateType(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_AddClientCertificateType(TElSSLClientHandle _Handle, TElSSLCertificateTypeRaw C_Type);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_DelClientCertificateType(TElSSLClientHandle _Handle, TElSSLCertificateTypeRaw C_Type);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_GetClientCertTypesCount(TElSSLClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_ClearClientCertificateType(TElSSLClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_CipherSuite(TElSSLClientHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_CertTypes(TElSSLClientHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_CertTypes(TElSSLClientHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ClientCertTypes(TElSSLClientHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_ClientCertTypes(TElSSLClientHandle _Handle, int32_t Index, TElSSLCertificateTypeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ECCurves(TElSSLClientHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_ECCurves(TElSSLClientHandle _Handle, int32_t Index, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ECPoints(TElSSLClientHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_ECPoints(TElSSLClientHandle _Handle, int32_t Index, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_CanResume(TElSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ClientState(TElSSLClientHandle _Handle, TSSL3StateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_Enabled(TElSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_Enabled(TElSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_CryptoProviderManager(TElSSLClientHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_CryptoProviderManager(TElSSLClientHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_UsedCertificateTypeExtension(TElSSLClientHandle _Handle, TSBCertificateTypeExtensionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_UsedCertificateTypeExtension(TElSSLClientHandle _Handle, TSBCertificateTypeExtensionRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_UseExtendedMasterSecret(TElSSLClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_UseExtendedMasterSecret(TElSSLClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_CertStorage(TElSSLClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_CertStorage(TElSSLClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ClientCertStorage(TElSSLClientHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_ClientCertStorage(TElSSLClientHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_ClientRawKeyStorage(TElSSLClientHandle _Handle, TElKeyMaterialStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_ClientRawKeyStorage(TElSSLClientHandle _Handle, TElKeyMaterialStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_Extensions(TElSSLClientHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_PeerExtensions(TElSSLClientHandle _Handle, TElServerSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_SRPUsername(TElSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_SRPUsername(TElSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_SRPPassword(TElSSLClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_SRPPassword(TElSSLClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnCloseConnection(TElSSLClientHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnCloseConnection(TElSSLClientHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnCertificateChoose(TElSSLClientHandle _Handle, TSBChooseCertificateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnCertificateChoose(TElSSLClientHandle _Handle, TSBChooseCertificateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnCertificateNeeded(TElSSLClientHandle _Handle, TSBCertificateNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnCertificateNeeded(TElSSLClientHandle _Handle, TSBCertificateNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnCertificateNeededEx(TElSSLClientHandle _Handle, TSBCertificateNeededExEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnCertificateNeededEx(TElSSLClientHandle _Handle, TSBCertificateNeededExEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnCertificateStatus(TElSSLClientHandle _Handle, TSBCertificateStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnCertificateStatus(TElSSLClientHandle _Handle, TSBCertificateStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnKeyNeeded(TElSSLClientHandle _Handle, TSBClientKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnKeyNeeded(TElSSLClientHandle _Handle, TSBClientKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_get_OnRenegotiationRequest(TElSSLClientHandle _Handle, TSBRenegotiationRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_set_OnRenegotiationRequest(TElSSLClientHandle _Handle, TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLClient_Create(TComponentHandle Owner, TElSSLClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLCLIENT */

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_ActivatePredefinedConfiguration(TElClientSSLConnectionSettingsHandle _Handle, TSBClientSSLPredefinedConfigurationRaw Config);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_EnableAllCiphers(TElClientSSLConnectionSettingsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_EnableAllCiphers_1(TElClientSSLConnectionSettingsHandle _Handle, int8_t ExcludeInsecure);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_EnableCiphers(TElClientSSLConnectionSettingsHandle _Handle, int32_t MinLevel, int32_t MaxLevel);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableAllCiphers(TElClientSSLConnectionSettingsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableCiphers(TElClientSSLConnectionSettingsHandle _Handle, int32_t MinLevel, int32_t MaxLevel);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableEncryptionAlgorithm(TElClientSSLConnectionSettingsHandle _Handle, TSBEncryptAlgorithmRaw Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableEncryptionAlgorithm_1(TElClientSSLConnectionSettingsHandle _Handle, TSBEncryptAlgorithmRaw Algorithm, int8_t Inverted);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableKeyExchangeAlgorithm(TElClientSSLConnectionSettingsHandle _Handle, TSBKeyExchangeAlgorithmRaw Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableKeyExchangeAlgorithm_1(TElClientSSLConnectionSettingsHandle _Handle, TSBKeyExchangeAlgorithmRaw Algorithm, int8_t Inverted);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableDigestAlgorithm(TElClientSSLConnectionSettingsHandle _Handle, TSBDigestAlgorithmRaw Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableDigestAlgorithm_1(TElClientSSLConnectionSettingsHandle _Handle, TSBDigestAlgorithmRaw Algorithm, int8_t Inverted);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableSignatureAlgorithm(TElClientSSLConnectionSettingsHandle _Handle, TSBSignatureAlgorithmRaw Algorithm);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_DisableSignatureAlgorithm_1(TElClientSSLConnectionSettingsHandle _Handle, TSBSignatureAlgorithmRaw Algorithm, int8_t Inverted);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_Load(TElClientSSLConnectionSettingsHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_Save(TElClientSSLConnectionSettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_get_Versions(TElClientSSLConnectionSettingsHandle _Handle, TSBVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_set_Versions(TElClientSSLConnectionSettingsHandle _Handle, TSBVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElClientSSLConnectionSettings_Create(TElSSLClientHandle Owner, TElClientSSLConnectionSettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElClientSSLConnectionInfo;
class TElSSLClient;
typedef TElSSLClient ElSSLClient;
class TElClientSSLConnectionSettings;

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO
class TElClientSSLConnectionInfo: public TElSSLConnectionInfo
{
	private:
		SB_DISABLE_COPY(TElClientSSLConnectionInfo)
	public:
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);

		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATECHAIN
		void Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElX509CertificateChain &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve);

		void Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElX509CertificateChain *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve);
#endif /* SB_USE_CLASSES_TELCUSTOMCERTSTORAGE_AND_TELX509CERTIFICATECHAIN */

		virtual void Reset();

		TElClientSSLConnectionInfo(TElClientSSLConnectionInfoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElClientSSLConnectionInfo(TElSSLClass &Owner);

		explicit TElClientSSLConnectionInfo(TElSSLClass *Owner);
#endif /* SB_USE_CLASS_TELSSLCLASS */

};
#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLCLIENT
class TElSSLClient: public TElSSLClass
{
	private:
		SB_DISABLE_COPY(TElSSLClient)
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
		TElKeyMaterialStorage* _Inst_ClientRawKeyStorage;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		TElServerSSLExtensions* _Inst_PeerExtensions;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

		void initInstances();

	public:
		void Open();

		void Close(bool Silent);

		void DataAvailable();

		void SendData(void * Buffer, int32_t Size);

		void SendText(const std::vector<uint8_t> &S);

		bool SendKeepAlive();

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		void Resume();

		void Join(TElSSLClient &ElSecureClient);

		void Join(TElSSLClient *ElSecureClient);

		void RenegotiateCiphers();

		void AddCertificateType(TElSSLCertificateType C_Type);

		void DelCertificateType(TElSSLCertificateType C_Type);

		int32_t GetCertTypesCount();

		void ClearCertificateType();

		void AddClientCertificateType(TElSSLCertificateType C_Type);

		void DelClientCertificateType(TElSSLCertificateType C_Type);

		int32_t GetClientCertTypesCount();

		void ClearClientCertificateType();

		virtual uint8_t get_CipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CipherSuite, TElSSLClient, CipherSuite);

		virtual TElSSLCertificateType get_CertTypes(int32_t Index);

		virtual void set_CertTypes(int32_t Index, TElSSLCertificateType Value);

		virtual TElSSLCertificateType get_ClientCertTypes(int32_t Index);

		virtual void set_ClientCertTypes(int32_t Index, TElSSLCertificateType Value);

		virtual bool get_ECCurves(int32_t Index);

		virtual void set_ECCurves(int32_t Index, bool Enabled);

		virtual bool get_ECPoints(int32_t Index);

		virtual void set_ECPoints(int32_t Index, bool Enabled);

		virtual bool get_CanResume();

		SB_DECLARE_PROPERTY_GET(bool, get_CanResume, TElSSLClient, CanResume);

		virtual TSSL3State get_ClientState();

		SB_DECLARE_PROPERTY_GET(TSSL3State, get_ClientState, TElSSLClient, ClientState);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSSLClient, Enabled);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSSLClient, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual TSBCertificateTypeExtension get_UsedCertificateTypeExtension();

		virtual void set_UsedCertificateTypeExtension(TSBCertificateTypeExtension Value);

		SB_DECLARE_PROPERTY(TSBCertificateTypeExtension, get_UsedCertificateTypeExtension, set_UsedCertificateTypeExtension, TElSSLClient, UsedCertificateTypeExtension);

		virtual bool get_UseExtendedMasterSecret();

		virtual void set_UseExtendedMasterSecret(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseExtendedMasterSecret, set_UseExtendedMasterSecret, TElSSLClient, UseExtendedMasterSecret);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSSLClient, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElSSLClient, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
		virtual TElKeyMaterialStorage* get_ClientRawKeyStorage();

		virtual void set_ClientRawKeyStorage(TElKeyMaterialStorage &Value);

		virtual void set_ClientRawKeyStorage(TElKeyMaterialStorage *Value);

		SB_DECLARE_PROPERTY(TElKeyMaterialStorage*, get_ClientRawKeyStorage, set_ClientRawKeyStorage, TElSSLClient, ClientRawKeyStorage);
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElClientSSLExtensions*, get_Extensions, TElSSLClient, Extensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		virtual TElServerSSLExtensions* get_PeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElServerSSLExtensions*, get_PeerExtensions, TElSSLClient, PeerExtensions);
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

		virtual void get_SRPUsername(std::string &OutResult);

		virtual void set_SRPUsername(const std::string &Value);

		virtual void get_SRPPassword(std::string &OutResult);

		virtual void set_SRPPassword(const std::string &Value);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateChoose(TSBChooseCertificateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateChoose(TSBChooseCertificateEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeeded(TSBCertificateNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeeded(TSBCertificateNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateNeededEx(TSBCertificateNeededExEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateNeededEx(TSBCertificateNeededExEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateStatus(TSBCertificateStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateStatus(TSBCertificateStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBClientKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBClientKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationRequest(TSBRenegotiationRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationRequest(TSBRenegotiationRequestEvent pMethodValue, void * pDataValue);

		TElSSLClient(TElSSLClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLClient(TComponent &Owner);

		explicit TElSSLClient(TComponent *Owner);

		virtual ~TElSSLClient();

};
#endif /* SB_USE_CLASS_TELSSLCLIENT */

#ifdef SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS
class TElClientSSLConnectionSettings: public TObject
{
	private:
		SB_DISABLE_COPY(TElClientSSLConnectionSettings)
	public:
		void ActivatePredefinedConfiguration(TSBClientSSLPredefinedConfiguration Config);

		void EnableAllCiphers();

		void EnableAllCiphers(bool ExcludeInsecure);

		void EnableCiphers(int32_t MinLevel, int32_t MaxLevel);

		void DisableAllCiphers();

		void DisableCiphers(int32_t MinLevel, int32_t MaxLevel);

		void DisableEncryptionAlgorithm(TSBEncryptAlgorithm Algorithm);

		void DisableEncryptionAlgorithm(TSBEncryptAlgorithm Algorithm, bool Inverted);

		void DisableKeyExchangeAlgorithm(TSBKeyExchangeAlgorithm Algorithm);

		void DisableKeyExchangeAlgorithm(TSBKeyExchangeAlgorithm Algorithm, bool Inverted);

		void DisableDigestAlgorithm(TSBDigestAlgorithm Algorithm);

		void DisableDigestAlgorithm(TSBDigestAlgorithm Algorithm, bool Inverted);

		void DisableSignatureAlgorithm(TSBSignatureAlgorithm Algorithm);

		void DisableSignatureAlgorithm(TSBSignatureAlgorithm Algorithm, bool Inverted);

		void Load(const std::string &S);

		void Save(std::string &OutResult);

		virtual TSBVersions get_Versions();

		virtual void set_Versions(TSBVersions Value);

		SB_DECLARE_PROPERTY(TSBVersions, get_Versions, set_Versions, TElClientSSLConnectionSettings, Versions);

		TElClientSSLConnectionSettings(TElClientSSLConnectionSettingsHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSLCLIENT
		explicit TElClientSSLConnectionSettings(TElSSLClient &Owner);

		explicit TElClientSSLConnectionSettings(TElSSLClient *Owner);
#endif /* SB_USE_CLASS_TELSSLCLIENT */

};
#endif /* SB_USE_CLASS_TELCLIENTSSLCONNECTIONSETTINGS */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSLCLIENT */
