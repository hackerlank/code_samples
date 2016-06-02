#ifndef __INC_SBSSLSERVER
#define __INC_SBSSLSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbx509.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbhmac.h"
#include "sbrsa.h"
#include "sbdsa.h"
#include "sbsslconstants.h"
#include "sbsslcommon.h"
#include "sbalgorithmidentifier.h"
#include "sbeccommon.h"
#include "sbcryptoprov.h"
#include "sbcryptoprovmanager.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbsymmetriccrypto.h"
#include "sbhashfunction.h"
#include "sbasn1tree.h"
#include "sbcustomcertstorage.h"
#include "sbsharedresource.h"
#include "sbzlib.h"
#include "sbsessionpool.h"
#include "sbsrp.h"
#include "sbconstants.h"
#include "sbpoly1305.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_CLOSE_CONNECTION_OK 	0
#define SB_CLOSE_CONNECTION_ERROR 	1
#define SB_CLOSE_CONNECTION_NEGOTIATION_FAILED 	2
#ifndef SB_BUFFER_SIZE
#define SB_BUFFER_SIZE 	16384
#endif

typedef TElClassHandle TElServerSSLConnectionInfoHandle;

typedef TElClassHandle TElSSLServerHandle;

typedef TElSSLServerHandle ElSSLServerHandle;

typedef TElClassHandle TElSSLServerEnvironmentHandle;

typedef void (SB_CALLBACK *TSBServerKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcIdentity, int32_t szIdentity, uint8_t pKey[], int32_t * szKey);

typedef void (SB_CALLBACK *TSBCertificateURLsEvent)(void * _ObjectData, TObjectHandle Sender, TElClientCertURLsSSLExtensionHandle URLs, TElMemoryCertStorageHandle Certificates);

typedef void (SB_CALLBACK *TSBServerSrpDbNeededEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcUserName, int32_t szUserName, uint8_t pN[], int32_t * szN, uint8_t pG[], int32_t * szG, uint8_t pS[], int32_t * szS, uint8_t pV[], int32_t * szV, int8_t * OutResult);

typedef void (SB_CALLBACK *TSBServerSessionCreatedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pSessionID[], int32_t szSessionID, TObjectHandle * SessionInfo, int8_t * FreeOnRelease);

typedef void (SB_CALLBACK *TSBServerSessionReusedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pSessionID[], int32_t szSessionID, TObjectHandle SessionInfo);

typedef uint8_t SBSSLServer_TSBReceiveStateRaw;

typedef enum
{
	__rsRecordHeaderWanted = 0,
	__rsRecordWanted = 1,
	_rsOneByteWanted = 2
} SBSSLServer_TSBReceiveState;

typedef uint8_t TSBServerStateRaw;

typedef enum
{
	ssBeforeNegotiation = 0,
	ssClientHelloReceived = 1,
	ssServerHelloSent = 2,
	ssServerCertificateSent = 3,
	ssServerKeyExchangeSent = 4,
	ssServerHelloDoneSent = 5,
	ssClientKeyExchangeReceived = 6,
	ssClientChangeCipherSpecReceived = 7,
	ssClientFinishedReceived = 8,
	ssApplicationDataTransfer = 9,
	ssClientMasterKeyReceived = 10
} TSBServerState;

typedef uint8_t TSBEndPointRaw;

typedef enum
{
	epClient = 0,
	epServer = 1
} TSBEndPoint;

#pragma pack(4)
typedef struct 
{
	uint8_t Index;
	uint8_t first;
	uint8_t second;
	uint8_t third;
	int8_t Exportable;
	TSBEncryptAlgorithmRaw EncryptAlgorithm;
	TSBDigestAlgorithmRaw DigestAlgorithm;
	TSBKeyExchangeAlgorithmRaw KeyExchangeAlgorithm;
	TSBSignatureAlgorithmRaw SignatureAlgorithm;
	int8_t _dummy0;
	int16_t _dummy1;
	int32_t PRFHashAlgorithm;
	uint8_t HashSize;
	uint8_t RealHashSize;
	uint8_t KeySize;
	uint8_t IVSize;
	uint8_t BlockSize;
	uint8_t PaddingSize;
	int8_t AEADCipher;
} TSSLCipherSuite;

#pragma pack(4)
typedef struct 
{
	void * SessionID;
	void * Challenge;
	void * ConnectionID;
	TSSLCipherSuite CipherSuite;
	void * MasterKey;
	void * ClientWriteMACSecret;
	void * ServerWriteMACSecret;
	void * ClientWriteKey;
	void * ServerWriteKey;
	void * ClientWriteIV;
	void * ServerWriteIV;
	void * CertificateChallenge;
} TSSL2SecureParams;

#pragma pack(4)
typedef struct 
{
	uint8_t ClientRandom[32];
	uint8_t ServerRandom[32];
	void * SessionID;
	TSSLCipherSuite PrevCipherSuite;
	TSSLCipherSuite CipherSuite;
	uint8_t MasterSecret[48];
	void * ClientWriteMACSecret;
	void * ServerWriteMACSecret;
	void * PrevClientWriteMACSecret;
	void * PrevServerWriteMACSecret;
	void * ClientWriteKey;
	void * ServerWriteKey;
	void * ClientWriteIV;
	void * ServerWriteIV;
} TSSL3SecureParams;

typedef uint8_t TSBAuthenticationLevelRaw;

typedef enum
{
	alRequestCert = 0,
	alRequireCert = 1
} TSBAuthenticationLevel;

typedef uint8_t TSBServerSSLPredefinedConfigurationRaw;

typedef enum
{
	sspcDefault = 0,
	sspcCompatible = 1,
	sspcComprehensiveInsecure = 2,
	sspcHighlySecure = 3
} TSBServerSSLPredefinedConfiguration;

#ifdef SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLConnectionInfo_Initialize(TElServerSSLConnectionInfoHandle _Handle, TSBVersionRaw Version, uint8_t Ciphersuite, TElCustomCertStorageHandle ServerChain, TElCustomCertStorageHandle ClientChain, const uint8_t pSessionID[], int32_t szSessionID, int8_t ResumedSession);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLConnectionInfo_Initialize2(TElServerSSLConnectionInfoHandle _Handle, TSBVersionRaw Version, uint8_t Ciphersuite, TElCustomCertStorageHandle ServerChain, TElCustomCertStorageHandle ClientChain, const uint8_t pSessionID[], int32_t szSessionID, int8_t ResumedSession, int32_t ECCurve);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLConnectionInfo_Reset(TElServerSSLConnectionInfoHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElServerSSLConnectionInfo_Create(TElSSLClassHandle Owner, TElSSLConnectionInfoHandle * OutResult);
#endif /* SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_Configure(TElSSLServerHandle _Handle, TSBServerSSLPredefinedConfigurationRaw Configuration);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_Open(TElSSLServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_Close(TElSSLServerHandle _Handle, int8_t Silent);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_SendData(TElSSLServerHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_SendText(TElSSLServerHandle _Handle, const uint8_t pS[], int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_SendKeepAlive(TElSSLServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_DataAvailable(TElSSLServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_InternalValidate(TElSSLServerHandle _Handle, TSBCertificateValidityRaw * Validity, TSBCertificateValidityReasonRaw * Reason);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_RenegotiateCiphers(TElSSLServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_AssignFromTemplate(TElSSLServerHandle _Handle, TElSSLClassHandle Tpl);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_CipherSuite(TElSSLServerHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ECCurves(TElSSLServerHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ECCurves(TElSSLServerHandle _Handle, int32_t Index, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ECPoints(TElSSLServerHandle _Handle, int32_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ECPoints(TElSSLServerHandle _Handle, int32_t Index, int8_t Enabled);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ECCurveType(TElSSLServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ECCurveType(TElSSLServerHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_SessionID(TElSSLServerHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ServerState(TElSSLServerHandle _Handle, TSBServerStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_Enabled(TElSSLServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_Enabled(TElSSLServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ClientAuthentication(TElSSLServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ClientAuthentication(TElSSLServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_AuthenticationLevel(TElSSLServerHandle _Handle, TSBAuthenticationLevelRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_AuthenticationLevel(TElSSLServerHandle _Handle, TSBAuthenticationLevelRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ForceCertificateChain(TElSSLServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ForceCertificateChain(TElSSLServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_CertStorage(TElSSLServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_CertStorage(TElSSLServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_KeyStorage(TElSSLServerHandle _Handle, TElKeyMaterialStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_KeyStorage(TElSSLServerHandle _Handle, TElKeyMaterialStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_SessionPool(TElSSLServerHandle _Handle, TElSessionPoolHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_SessionPool(TElSSLServerHandle _Handle, TElSessionPoolHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_ClientCertStorage(TElSSLServerHandle _Handle, TElCustomCertStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_ClientCertStorage(TElSSLServerHandle _Handle, TElCustomCertStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_Extensions(TElSSLServerHandle _Handle, TElServerSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_PeerExtensions(TElSSLServerHandle _Handle, TElClientSSLExtensionsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnlyWithExtendedMasterSecret(TElSSLServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnlyWithExtendedMasterSecret(TElSSLServerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_SRPCredentialStore(TElSSLServerHandle _Handle, TElSRPCredentialStoreHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_SRPCredentialStore(TElSSLServerHandle _Handle, TElSRPCredentialStoreHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnGetSrpDb(TElSSLServerHandle _Handle, TSBServerSrpDbNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnGetSrpDb(TElSSLServerHandle _Handle, TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnKeyNeeded(TElSSLServerHandle _Handle, TSBServerKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnKeyNeeded(TElSSLServerHandle _Handle, TSBServerKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnCloseConnection(TElSSLServerHandle _Handle, TSBCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnCloseConnection(TElSSLServerHandle _Handle, TSBCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnRenegotiationStart(TElSSLServerHandle _Handle, TSBRenegotiationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnRenegotiationStart(TElSSLServerHandle _Handle, TSBRenegotiationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnCertificateURLs(TElSSLServerHandle _Handle, TSBCertificateURLsEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnCertificateURLs(TElSSLServerHandle _Handle, TSBCertificateURLsEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnSessionReused(TElSSLServerHandle _Handle, TSBServerSessionReusedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnSessionReused(TElSSLServerHandle _Handle, TSBServerSessionReusedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_get_OnSessionCreated(TElSSLServerHandle _Handle, TSBServerSessionCreatedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_set_OnSessionCreated(TElSSLServerHandle _Handle, TSBServerSessionCreatedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServer_Create(TComponentHandle Owner, TElSSLServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLSERVER */

#ifdef SB_USE_CLASS_TELSSLSERVERENVIRONMENT
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_RegenerateDH(TElSSLServerEnvironmentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_RegenerateDH_1(TElSSLServerEnvironmentHandle _Handle, int32_t Bits, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_get_Bits(TElSSLServerEnvironmentHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_get_UseUniqueDHKeys(TElSSLServerEnvironmentHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_set_UseUniqueDHKeys(TElSSLServerEnvironmentHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSLServerEnvironment_Create(TElSSLServerEnvironmentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSLSERVERENVIRONMENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElServerSSLConnectionInfo;
class TElSSLServer;
typedef TElSSLServer ElSSLServer;
class TElSSLServerEnvironment;

#ifdef SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO
class TElServerSSLConnectionInfo: public TElSSLConnectionInfo
{
	private:
		SB_DISABLE_COPY(TElServerSSLConnectionInfo)
	public:
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);

		virtual void Initialize(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		void Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage &ServerChain, TElCustomCertStorage &ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve);

		void Initialize2(TSBVersion Version, uint8_t Ciphersuite, TElCustomCertStorage *ServerChain, TElCustomCertStorage *ClientChain, const std::vector<uint8_t> &SessionID, bool ResumedSession, int32_t ECCurve);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

		virtual void Reset();

		TElServerSSLConnectionInfo(TElServerSSLConnectionInfoHandle handle, TElOwnHandle ownHandle);

#ifdef SB_USE_CLASS_TELSSLCLASS
		explicit TElServerSSLConnectionInfo(TElSSLClass &Owner);

		explicit TElServerSSLConnectionInfo(TElSSLClass *Owner);
#endif /* SB_USE_CLASS_TELSSLCLASS */

};
#endif /* SB_USE_CLASS_TELSERVERSSLCONNECTIONINFO */

#ifdef SB_USE_CLASS_TELSSLSERVER
class TElSSLServer: public TElSSLClass
{
	private:
		SB_DISABLE_COPY(TElSSLServer)
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_CertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
		TElKeyMaterialStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */
#ifdef SB_USE_CLASS_TELSESSIONPOOL
		TElSessionPool* _Inst_SessionPool;
#endif /* SB_USE_CLASS_TELSESSIONPOOL */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		TElCustomCertStorage* _Inst_ClientCertStorage;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		TElServerSSLExtensions* _Inst_Extensions;
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		TElClientSSLExtensions* _Inst_PeerExtensions;
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */
#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		TElSRPCredentialStore* _Inst_SRPCredentialStore;
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

		void initInstances();

	public:
		void Configure(TSBServerSSLPredefinedConfiguration Configuration);

		void Open();

		void Close(bool Silent);

		void SendData(void * Buffer, int32_t Size);

		void SendText(const std::vector<uint8_t> &S);

		bool SendKeepAlive();

		void DataAvailable();

		void InternalValidate(TSBCertificateValidity &Validity, TSBCertificateValidityReason &Reason);

		void RenegotiateCiphers();

		virtual void AssignFromTemplate(TElSSLClass &Tpl);

		virtual void AssignFromTemplate(TElSSLClass *Tpl);

		virtual uint8_t get_CipherSuite();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CipherSuite, TElSSLServer, CipherSuite);

		virtual bool get_ECCurves(int32_t Index);

		virtual void set_ECCurves(int32_t Index, bool Enabled);

		virtual bool get_ECPoints(int32_t Index);

		virtual void set_ECPoints(int32_t Index, bool Enabled);

		virtual int32_t get_ECCurveType();

		virtual void set_ECCurveType(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ECCurveType, set_ECCurveType, TElSSLServer, ECCurveType);

		virtual void get_SessionID(std::vector<uint8_t> &OutResult);

		virtual TSBServerState get_ServerState();

		SB_DECLARE_PROPERTY_GET(TSBServerState, get_ServerState, TElSSLServer, ServerState);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSSLServer, Enabled);

		virtual bool get_ClientAuthentication();

		virtual void set_ClientAuthentication(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ClientAuthentication, set_ClientAuthentication, TElSSLServer, ClientAuthentication);

		virtual TSBAuthenticationLevel get_AuthenticationLevel();

		virtual void set_AuthenticationLevel(TSBAuthenticationLevel Value);

		SB_DECLARE_PROPERTY(TSBAuthenticationLevel, get_AuthenticationLevel, set_AuthenticationLevel, TElSSLServer, AuthenticationLevel);

		virtual bool get_ForceCertificateChain();

		virtual void set_ForceCertificateChain(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCertificateChain, set_ForceCertificateChain, TElSSLServer, ForceCertificateChain);

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_CertStorage();

		virtual void set_CertStorage(TElCustomCertStorage &Value);

		virtual void set_CertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_CertStorage, set_CertStorage, TElSSLServer, CertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELKEYMATERIALSTORAGE
		virtual TElKeyMaterialStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElKeyMaterialStorage &Value);

		virtual void set_KeyStorage(TElKeyMaterialStorage *Value);

		SB_DECLARE_PROPERTY(TElKeyMaterialStorage*, get_KeyStorage, set_KeyStorage, TElSSLServer, KeyStorage);
#endif /* SB_USE_CLASS_TELKEYMATERIALSTORAGE */

#ifdef SB_USE_CLASS_TELSESSIONPOOL
		virtual TElSessionPool* get_SessionPool();

		virtual void set_SessionPool(TElSessionPool &Value);

		virtual void set_SessionPool(TElSessionPool *Value);

		SB_DECLARE_PROPERTY(TElSessionPool*, get_SessionPool, set_SessionPool, TElSSLServer, SessionPool);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
		virtual TElCustomCertStorage* get_ClientCertStorage();

		virtual void set_ClientCertStorage(TElCustomCertStorage &Value);

		virtual void set_ClientCertStorage(TElCustomCertStorage *Value);

		SB_DECLARE_PROPERTY(TElCustomCertStorage*, get_ClientCertStorage, set_ClientCertStorage, TElSSLServer, ClientCertStorage);
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

#ifdef SB_USE_CLASS_TELSERVERSSLEXTENSIONS
		virtual TElServerSSLExtensions* get_Extensions();

		SB_DECLARE_PROPERTY_GET(TElServerSSLExtensions*, get_Extensions, TElSSLServer, Extensions);
#endif /* SB_USE_CLASS_TELSERVERSSLEXTENSIONS */

#ifdef SB_USE_CLASS_TELCLIENTSSLEXTENSIONS
		virtual TElClientSSLExtensions* get_PeerExtensions();

		SB_DECLARE_PROPERTY_GET(TElClientSSLExtensions*, get_PeerExtensions, TElSSLServer, PeerExtensions);
#endif /* SB_USE_CLASS_TELCLIENTSSLEXTENSIONS */

		virtual bool get_OnlyWithExtendedMasterSecret();

		virtual void set_OnlyWithExtendedMasterSecret(bool Value);

		SB_DECLARE_PROPERTY(bool, get_OnlyWithExtendedMasterSecret, set_OnlyWithExtendedMasterSecret, TElSSLServer, OnlyWithExtendedMasterSecret);

#ifdef SB_USE_CLASS_TELSRPCREDENTIALSTORE
		virtual TElSRPCredentialStore* get_SRPCredentialStore();

		virtual void set_SRPCredentialStore(TElSRPCredentialStore &Value);

		virtual void set_SRPCredentialStore(TElSRPCredentialStore *Value);

		SB_DECLARE_PROPERTY(TElSRPCredentialStore*, get_SRPCredentialStore, set_SRPCredentialStore, TElSSLServer, SRPCredentialStore);
#endif /* SB_USE_CLASS_TELSRPCREDENTIALSTORE */

		virtual void get_OnGetSrpDb(TSBServerSrpDbNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnGetSrpDb(TSBServerSrpDbNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnKeyNeeded(TSBServerKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyNeeded(TSBServerKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSBCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSBCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnRenegotiationStart(TSBRenegotiationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRenegotiationStart(TSBRenegotiationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnCertificateURLs(TSBCertificateURLsEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCertificateURLs(TSBCertificateURLsEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionReused(TSBServerSessionReusedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionReused(TSBServerSessionReusedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionCreated(TSBServerSessionCreatedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionCreated(TSBServerSessionCreatedEvent pMethodValue, void * pDataValue);

		TElSSLServer(TElSSLServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSLServer(TComponent &Owner);

		explicit TElSSLServer(TComponent *Owner);

		virtual ~TElSSLServer();

};
#endif /* SB_USE_CLASS_TELSSLSERVER */

#ifdef SB_USE_CLASS_TELSSLSERVERENVIRONMENT
class TElSSLServerEnvironment: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSLServerEnvironment)
	public:
		bool RegenerateDH();

		bool RegenerateDH(int32_t Bits);

		virtual int32_t get_Bits();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Bits, TElSSLServerEnvironment, Bits);

		virtual bool get_UseUniqueDHKeys();

		virtual void set_UseUniqueDHKeys(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUniqueDHKeys, set_UseUniqueDHKeys, TElSSLServerEnvironment, UseUniqueDHKeys);

		TElSSLServerEnvironment(TElSSLServerEnvironmentHandle handle, TElOwnHandle ownHandle);

		TElSSLServerEnvironment();

};
#endif /* SB_USE_CLASS_TELSSLSERVERENVIRONMENT */

#ifdef SB_USE_GLOBAL_PROCS_SSLSERVER

#ifdef SB_USE_CLASS_TELSSLSERVER
TElSSLServerHandle CreateSSLServerTemplate(TSBServerSSLPredefinedConfiguration Config);
#endif /* SB_USE_CLASS_TELSSLSERVER */

bool GetTLSCipherSuiteByCode(uint8_t B1, uint8_t B2, uint8_t &CipherSuite);

void PrepareSSLServerEnvironment();

int32_t GetSSLDHKeyLength();

void SetSSLDHKeyLength(int32_t Value);

#endif /* SB_USE_GLOBAL_PROCS_SSLSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSLSERVER
SB_IMPORT uint32_t SB_APIENTRY SBSSLServer_CreateSSLServerTemplate(TSBServerSSLPredefinedConfigurationRaw Config, TElSSLServerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLServer_GetTLSCipherSuiteByCode(uint8_t B1, uint8_t B2, uint8_t * CipherSuite, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLServer_PrepareSSLServerEnvironment(void);
SB_IMPORT uint32_t SB_APIENTRY SBSSLServer_GetSSLDHKeyLength(int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSLServer_SetSSLDHKeyLength(int32_t Value);
#endif /* SB_USE_GLOBAL_PROCS_SSLSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSLSERVER */

