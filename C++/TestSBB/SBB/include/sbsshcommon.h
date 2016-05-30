#ifndef __INC_SBSSHCOMMON
#define __INC_SBSSHCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbrandom.h"
#include "sbchsconv.h"
#include "sbchsconvcharsets.h"
#include "sbchscjk.h"
#include "sbsshterm.h"
#include "sbsharedresource.h"
#include "sbsshconstants.h"
#include "sbzlib.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbcryptoprov.h"
#include "sbsymmetriccrypto.h"
#include "sbcryptoprovmanager.h"
#include "sbhashfunction.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_OBFUSCATE_MAGIC_VALUE 	200657534
#define SB_OBFUSCATE_MAX_PADDING 	8192
#define SB_OBFUSCATE_SEED_LENGTH 	16
#define SB_OBFUSCATE_HASH_ITERATIONS 	6000
#define SB_OBFUSCATE_KEY_LENGTH 	16
#define SB_CURVE25519_SIZE 	32
#define SB_SNewPasswordRequest 	"New password needed"
#define SB_SSessionRequestintTunnelsAreOnlyAllowed 	"Session-requesting tunnel objects are only allowed"

typedef TElClassHandle TElSSHClassHandle;

typedef TElSSHClassHandle ElSSHClassHandle;

typedef TElClassHandle TElSSHTunnelListHandle;

typedef TElSSHTunnelListHandle ElSSHTunnelListHandle;

typedef TElClassHandle TElCustomSSHTunnelHandle;

typedef TElCustomSSHTunnelHandle ElCustomSSHTunnelHandle;

typedef TElClassHandle TElSSHTunnelConnectionHandle;

typedef TElSSHTunnelConnectionHandle ElSSHTunnelConnectionHandle;

typedef TElClassHandle TElCustomSSHTunnelParamsHandle;

typedef TElClassHandle TElShellSSHTunnelHandle;

typedef TElShellSSHTunnelHandle ElShellSSHTunnelHandle;

typedef TElClassHandle TElCommandSSHTunnelHandle;

typedef TElCommandSSHTunnelHandle ElCommandSSHTunnelHandle;

typedef TElClassHandle TElSubsystemSSHTunnelHandle;

typedef TElSubsystemSSHTunnelHandle ElSubsystemSSHTunnelHandle;

typedef TElClassHandle TElRemotePortForwardSSHTunnelHandle;

typedef TElRemotePortForwardSSHTunnelHandle ElRemotePortForwardSSHTunnelHandle;

typedef TElClassHandle TElLocalPortForwardSSHTunnelHandle;

typedef TElLocalPortForwardSSHTunnelHandle ElLocalPortForwardSSHTunnelHandle;

typedef TElClassHandle TElLocalPortForwardSSHTunnelParamsHandle;

typedef TElClassHandle TElX11ForwardSSHTunnelHandle;

typedef TElX11ForwardSSHTunnelHandle ElX11ForwardSSHTunnelHandle;

typedef TElClassHandle TElAuthenticationAgentSSHTunnelHandle;

typedef TElAuthenticationAgentSSHTunnelHandle ElAuthenticationAgentSSHTunnelHandle;

typedef TElClassHandle TElSSHAuthHandlerHandle;

typedef uint8_t TSSHTunnelTypeRaw;

typedef enum
{
	ttLocalPortToRemoteAddress = 0,
	ttRemotePortToLocalAddress = 1,
	ttX11 = 2,
	ttAuthenticationAgent = 3,
	ttSubsystem = 4,
	ttCommand = 5,
	ttShell = 6
} TSSHTunnelType;

typedef uint8_t TSSHCloseTypeRaw;

typedef enum
{
	ctReturn = 0,
	ctSignal = 1,
	ctError = 2
} TSSHCloseType;

typedef uint8_t TSBSSHAuthOrderRaw;

typedef enum
{
	aoDefault = 0,
	aoKbdIntLast = 1,
	aoCustom = 2
} TSBSSHAuthOrder;

typedef void (SB_CALLBACK *TSSHSendEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSSHReceiveEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t MaxSize, int32_t * Written);

typedef void (SB_CALLBACK *TSSHDataEvent)(void * _ObjectData, TObjectHandle Sender, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TSSHOpenConnectionEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSSHCloseConnectionEvent)(void * _ObjectData, TObjectHandle Sender);

typedef void (SB_CALLBACK *TSSHChannelCloseEvent)(void * _ObjectData, TObjectHandle Sender, TSSHCloseTypeRaw CloseType);

typedef void (SB_CALLBACK *TSSHErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t ErrorCode);

typedef void (SB_CALLBACK *TSSHPrivateKeyNeededEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHKeyHandle Key, int8_t * Skip);

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSSHKexInitReceivedEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle KexLines);
#else
typedef void (SB_CALLBACK *TSSHKexInitReceivedEvent)(void * _ObjectData, TObjectHandle Sender, TElStringListHandle KexLines);
#endif

typedef void (SB_CALLBACK *TTunnelEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle TunnelConnection);

typedef void (SB_CALLBACK *TTunnelDataEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHTunnelConnectionHandle TunnelConnection, void * Buffer, int32_t Size);

typedef void (SB_CALLBACK *TTunnelErrorEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Error, void * Data);

typedef void (SB_CALLBACK *TSSHAuthenticationFailedEvent)(void * _ObjectData, TObjectHandle Sender, int32_t AuthenticationType);

typedef void (SB_CALLBACK *TSSHAuthenticationKeyboardEvent)(void * _ObjectData, TObjectHandle Sender, TStringListHandle Prompts, TBitsHandle Echo, TStringListHandle Responses);

typedef void (SB_CALLBACK *TSSHAuthenticationStartEvent)(void * _ObjectData, TObjectHandle Sender, int32_t SupportedAuths);

typedef void (SB_CALLBACK *TSSHAuthenticationAttemptEvent)(void * _ObjectData, TObjectHandle Sender, int32_t AuthType, TObjectHandle AuthParam);

typedef void (SB_CALLBACK *TSSHKeyValidateEvent)(void * _ObjectData, TObjectHandle Sender, TElSSHKeyHandle ServerKey, int8_t * Validate);

typedef void (SB_CALLBACK *TSSHBannerEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pText[], int32_t szText, const uint8_t pLanguage[], int32_t szLanguage);

typedef void (SB_CALLBACK *TSSHMessageLoopEvent)(void * _ObjectData, int8_t * OutResult);

typedef void (SB_CALLBACK *TSSHWindowChangedEvent)(void * _ObjectData, TObjectHandle Sender, int32_t Cols, int32_t Rows, int32_t Width, int32_t Height);

typedef void (SB_CALLBACK *TSSHCommandExecutionEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcCommand, int32_t szCommand, int32_t CommandIdx);

typedef void (SB_CALLBACK *TSSHPasswordChangeRequestEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcPrompt, int32_t szPrompt, char * pcNewPassword, int32_t * szNewPassword, int8_t * Cancel);

typedef void (SB_CALLBACK *TSSHTunnelRequestEvent)(void * _ObjectData, TObjectHandle Sender, TElCustomSSHTunnelHandle Tunnel, int8_t * Allow);

typedef void (SB_CALLBACK *TSSHEOFEvent)(void * _ObjectData, TObjectHandle Sender, int8_t * CloseChannel);

typedef uint8_t TSSHReceiveStateRaw;

typedef enum
{
	rsRecordHeaderWanted = 0,
	rsRecordWanted = 1,
	rsMACWanted = 2
} TSSHReceiveState;

typedef uint8_t TSSHVersionRaw;

typedef enum
{
	sbSSH1 = 0,
	sbSSH2 = 1
} TSSHVersion;

typedef uint32_t TSSHVersionsRaw;

typedef enum 
{
	f_sbSSH1 = 1,
	f_sbSSH2 = 2
} TSSHVersions;

typedef uint8_t TSSHStandardAlgorithmPriorityTemplateRaw;

typedef enum
{
	sapDefault = 0,
	sapDefinite = 1,
	sapUniform = 2
} TSSHStandardAlgorithmPriorityTemplate;

typedef uint8_t TSSH1StateRaw;

typedef enum
{
	stNotEncrypted = 0,
	stEncrypted = 1
} TSSH1State;

#pragma pack(4)
typedef struct 
{
	PLInt P;
	PLInt G;
	PLInt Q;
	PLInt X;
	PLInt E;
	PLInt K;
} TDHParams;

#pragma pack(4)
typedef struct 
{
	int32_t CurveID;
	void * D;
	void * QX;
	void * QY;
	void * Q;
	void * K;
} TECDHParams;

#pragma pack(4)
typedef struct 
{
	void * PrivateKey;
	void * PublicKey;
	void * K;
} TC25519Params;

#pragma pack(4)
typedef struct 
{
	PLInt Modulus;
	PLInt PublicExponent;
	PLInt PrivateExponent;
} TRSAParams;

#pragma pack(4)
typedef struct 
{
	void * ClientVersionString;
	void * ServerVersionString;
	void * ClientKexInit;
	void * ServerKexInit;
	void * PubHostKey;
	void * Min;
	void * Max;
	void * N;
	void * P;
	void * G;
	void * E;
	void * F;
} THandshakeParams;

#pragma pack(4)
typedef struct 
{
	int32_t Cipher;
	int32_t Auth;
	uint8_t SessionID[16];
	uint8_t SessionKey[32];
} TSSH1Params;

#pragma pack(4)
typedef struct 
{
	int32_t KexAlgorithm;
	int32_t ServerHostKeyAlgorithm;
	int32_t EncryptionAlgorithmCS;
	int32_t EncryptionAlgorithmSC;
	int32_t EncCSBlockSize;
	int32_t EncSCBlockSize;
	int32_t MacAlgorithmCS;
	int32_t MacAlgorithmSC;
	void * MacKeyCS;
	void * MacKeySC;
	int32_t CompAlgorithmCS;
	int32_t CompAlgorithmSC;
	int32_t LanguageCS;
	int32_t LanguageSC;
	int32_t HashAlgorithm;
	void * SessionID;
} TSSH2Params;

typedef TElClassHandle IElSSHAuthHandlerContainerHandle;

#ifdef SB_USE_CLASS_TELSSHCLASS
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_Close(TElSSHClassHandle _Handle, int8_t Forced);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_RenegotiateCiphers(TElSSHClassHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_AdjustAlgorithmPriorities(TElSSHClassHandle _Handle, TSSHStandardAlgorithmPriorityTemplateRaw Priorities);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_Active(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_EncryptionAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_EncryptionAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CompressionAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_CompressionAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_MacAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_MacAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_KexAlgorithms(TElSSHClassHandle _Handle, int8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_KexAlgorithms(TElSSHClassHandle _Handle, int8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_PublicKeyAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_PublicKeyAlgorithms(TElSSHClassHandle _Handle, uint8_t Index, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_EncryptionAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_EncryptionAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CompressionAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_CompressionAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_MacAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_MacAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_KexAlgorithmPriorities(TElSSHClassHandle _Handle, int8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_KexAlgorithmPriorities(TElSSHClassHandle _Handle, int8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_PublicKeyAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_PublicKeyAlgorithmPriorities(TElSSHClassHandle _Handle, uint8_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_EncryptionAlgorithmServerToClient(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_EncryptionAlgorithmClientToServer(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CompressionAlgorithmServerToClient(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CompressionAlgorithmClientToServer(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_MacAlgorithmServerToClient(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_MacAlgorithmClientToServer(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_KexAlgorithm(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_PublicKeyAlgorithm(TElSSHClassHandle _Handle, uint8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_TotalBytesSent(TElSSHClassHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_TotalBytesReceived(TElSSHClassHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_SoftwareName(TElSSHClassHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_SoftwareName(TElSSHClassHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_KeyStorage(TElSSHClassHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_KeyStorage(TElSSHClassHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_ForceCompression(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_ForceCompression(TElSSHClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CompressionLevel(TElSSHClassHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_CompressionLevel(TElSSHClassHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_AuthenticationTypes(TElSSHClassHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_AuthenticationTypes(TElSSHClassHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CloseIfNoActiveTunnels(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_CloseIfNoActiveTunnels(TElSSHClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_UseUTF8(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_UseUTF8(TElSSHClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_CryptoProviderManager(TElSSHClassHandle _Handle, TElCustomCryptoProviderManagerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_CryptoProviderManager(TElSSHClassHandle _Handle, TElCustomCryptoProviderManagerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_NoCharacterEncoding(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_NoCharacterEncoding(TElSSHClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_LocalCharset(TElSSHClassHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_LocalCharset(TElSSHClassHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_RemoteCharset(TElSSHClassHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_RemoteCharset(TElSSHClassHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_ObfuscateHandshake(TElSSHClassHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_ObfuscateHandshake(TElSSHClassHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_ObfuscationPassword(TElSSHClassHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_ObfuscationPassword(TElSSHClassHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnSend(TElSSHClassHandle _Handle, TSSHSendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnSend(TElSSHClassHandle _Handle, TSSHSendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnReceive(TElSSHClassHandle _Handle, TSSHReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnReceive(TElSSHClassHandle _Handle, TSSHReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnOpenConnection(TElSSHClassHandle _Handle, TSSHOpenConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnOpenConnection(TElSSHClassHandle _Handle, TSSHOpenConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnCloseConnection(TElSSHClassHandle _Handle, TSSHCloseConnectionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnCloseConnection(TElSSHClassHandle _Handle, TSSHCloseConnectionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnDebugData(TElSSHClassHandle _Handle, TSSHDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnDebugData(TElSSHClassHandle _Handle, TSSHDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnError(TElSSHClassHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnError(TElSSHClassHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnCiphersNegotiated(TElSSHClassHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnCiphersNegotiated(TElSSHClassHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_get_OnKexInitReceived(TElSSHClassHandle _Handle, TSSHKexInitReceivedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_set_OnKexInitReceived(TElSSHClassHandle _Handle, TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClass_Create(TComponentHandle AOwner, TElSSHClassHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCLASS */

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelList_FindTunnel(TElSSHTunnelListHandle _Handle, const char * pcSubSystemType, int32_t szSubSystemType, const char * pcSubSystemName, int32_t szSubSystemName, TElCustomSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelList_get_SSHClass(TElSSHTunnelListHandle _Handle, TElSSHClassHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelList_get_Tunnels(TElSSHTunnelListHandle _Handle, int32_t Index, TElCustomSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelList_get_Count(TElSSHTunnelListHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelList_Create(TComponentHandle AOwner, TElSSHTunnelListHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_DoOpen(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelConnectionHandle Connection);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_DoClose(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelConnectionHandle Connection);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_DoError(TElCustomSSHTunnelHandle _Handle, int32_t Error, void * Data);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_AddConnection(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelConnectionHandle Conn);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_RemoveConnection(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelConnectionHandle Conn);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_Open(TElCustomSSHTunnelHandle _Handle, void * Data);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_Connections(TElCustomSSHTunnelHandle _Handle, int32_t Index, TElSSHTunnelConnectionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_ConnectionCount(TElCustomSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_ConnectionsList(TElCustomSSHTunnelHandle _Handle, TListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_AutoOpen(TElCustomSSHTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_set_AutoOpen(TElCustomSSHTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_TunnelList(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_set_TunnelList(TElCustomSSHTunnelHandle _Handle, TElSSHTunnelListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_OnOpen(TElCustomSSHTunnelHandle _Handle, TTunnelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_set_OnOpen(TElCustomSSHTunnelHandle _Handle, TTunnelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_OnClose(TElCustomSSHTunnelHandle _Handle, TTunnelEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_set_OnClose(TElCustomSSHTunnelHandle _Handle, TTunnelEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_get_OnError(TElCustomSSHTunnelHandle _Handle, TTunnelErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_set_OnError(TElCustomSSHTunnelHandle _Handle, TTunnelErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnel_Create(TComponentHandle AOwner, TElCustomSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_SendData(TElSSHTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_SendExtendedData(TElSSHTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_SendSignal(TElSSHTunnelConnectionHandle _Handle, const uint8_t pSignal[], int32_t szSignal);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_SendText(TElSSHTunnelConnectionHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_SendExtendedText(TElSSHTunnelConnectionHandle _Handle, const char * pcS, int32_t szS);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_Close(TElSSHTunnelConnectionHandle _Handle, int8_t FlushCachedData);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_Close_1(TElSSHTunnelConnectionHandle _Handle, int32_t ExitStatus, int8_t FlushCachedData);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_Close_2(TElSSHTunnelConnectionHandle _Handle, const char * pcExitSignal, int32_t szExitSignal, const char * pcExitMessage, int32_t szExitMessage, int8_t FlushCachedData);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_CloseLocal(TElSSHTunnelConnectionHandle _Handle, int8_t FlushCachedData);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_CanSend(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_Tunnel(TElSSHTunnelConnectionHandle _Handle, TElCustomSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_Tunnel(TElSSHTunnelConnectionHandle _Handle, TElCustomSSHTunnelHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_Data(TElSSHTunnelConnectionHandle _Handle, void * * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_Data(TElSSHTunnelConnectionHandle _Handle, void * Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_UseUTF8(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_UseUTF8(TElSSHTunnelConnectionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_HasUnsentData(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_EOFSent(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_ExitStatus(TElSSHTunnelConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_ExitSignal(TElSSHTunnelConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_ExitMessage(TElSSHTunnelConnectionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_ReturnExitStatus(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_ReturnExitStatus(TElSSHTunnelConnectionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_ReturnExitSignal(TElSSHTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_ReturnExitSignal(TElSSHTunnelConnectionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnData(TElSSHTunnelConnectionHandle _Handle, TSSHDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnData(TElSSHTunnelConnectionHandle _Handle, TSSHDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnExtendedData(TElSSHTunnelConnectionHandle _Handle, TSSHDataEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnExtendedData(TElSSHTunnelConnectionHandle _Handle, TSSHDataEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnError(TElSSHTunnelConnectionHandle _Handle, TSSHErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnError(TElSSHTunnelConnectionHandle _Handle, TSSHErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnClose(TElSSHTunnelConnectionHandle _Handle, TSSHChannelCloseEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnClose(TElSSHTunnelConnectionHandle _Handle, TSSHChannelCloseEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnWindowChanged(TElSSHTunnelConnectionHandle _Handle, TSSHWindowChangedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnWindowChanged(TElSSHTunnelConnectionHandle _Handle, TSSHWindowChangedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_get_OnEOF(TElSSHTunnelConnectionHandle _Handle, TSSHEOFEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_set_OnEOF(TElSSHTunnelConnectionHandle _Handle, TSSHEOFEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHTunnelConnection_Create(TElSSHTunnelConnectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElCustomSSHTunnelParams_Create(TObjectHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELSHELLSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_get_TerminalInfo(TElShellSSHTunnelHandle _Handle, TElTerminalInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_set_TerminalInfo(TElShellSSHTunnelHandle _Handle, TElTerminalInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_get_Environment(TElShellSSHTunnelHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_get_RequestTerminal(TElShellSSHTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_set_RequestTerminal(TElShellSSHTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElShellSSHTunnel_Create(TComponentHandle AOwner, TElShellSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELSHELLSSHTUNNEL */

#ifdef SB_USE_CLASS_TELCOMMANDSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_Command(TElCommandSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_set_Command(TElCommandSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
#ifdef SB_WINDOWS
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_Commands(TElCommandSSHTunnelHandle _Handle, TStringListHandle * OutResult);
#else
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_Commands(TElCommandSSHTunnelHandle _Handle, TElStringListHandle * OutResult);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_ActiveCommand(TElCommandSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_set_ActiveCommand(TElCommandSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_Environment(TElCommandSSHTunnelHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_TerminalInfo(TElCommandSSHTunnelHandle _Handle, TElTerminalInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_set_TerminalInfo(TElCommandSSHTunnelHandle _Handle, TElTerminalInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_get_RequestTerminal(TElCommandSSHTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_set_RequestTerminal(TElCommandSSHTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElCommandSSHTunnel_Create(TComponentHandle AOwner, TElCommandSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELCOMMANDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElSubsystemSSHTunnel_get_Subsystem(TElSubsystemSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubsystemSSHTunnel_set_Subsystem(TElSubsystemSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSubsystemSSHTunnel_get_Environment(TElSubsystemSSHTunnelHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSubsystemSSHTunnel_Create(TComponentHandle AOwner, TElSubsystemSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_DoSetupSucceeded(TElRemotePortForwardSSHTunnelHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_DoSetupFailed(TElRemotePortForwardSSHTunnelHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_GetToHost(TElRemotePortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_SetToHost(TElRemotePortForwardSSHTunnelHandle _Handle, const char * pcAValue, int32_t szAValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_Close(TElRemotePortForwardSSHTunnelHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_Host(TElRemotePortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_Host(TElRemotePortForwardSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_Port(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_Port(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_ToHost(TElRemotePortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_ToHost(TElRemotePortForwardSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_ToPort(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_ToPort(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_BoundPort(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_BoundPort(TElRemotePortForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_UseDefaultBindAddress(TElRemotePortForwardSSHTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_UseDefaultBindAddress(TElRemotePortForwardSSHTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_OnSetupSucceeded(TElRemotePortForwardSSHTunnelHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_OnSetupSucceeded(TElRemotePortForwardSSHTunnelHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_get_OnSetupFailed(TElRemotePortForwardSSHTunnelHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_set_OnSetupFailed(TElRemotePortForwardSSHTunnelHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElRemotePortForwardSSHTunnel_Create(TComponentHandle AOwner, TElRemotePortForwardSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_GetToHost(TElLocalPortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_SetToHost(TElLocalPortForwardSSHTunnelHandle _Handle, const char * pcAValue, int32_t szAValue);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_Open(TElLocalPortForwardSSHTunnelHandle _Handle, void * Data, const char * pcOrigHost, int32_t szOrigHost, int32_t OrigPort);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_get_Port(TElLocalPortForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_set_Port(TElLocalPortForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_get_Host(TElLocalPortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_set_Host(TElLocalPortForwardSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_get_ToHost(TElLocalPortForwardSSHTunnelHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_set_ToHost(TElLocalPortForwardSSHTunnelHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_get_ToPort(TElLocalPortForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_set_ToPort(TElLocalPortForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnel_Create(TComponentHandle AOwner, TElLocalPortForwardSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnelParams_get_OrigHost(TElLocalPortForwardSSHTunnelParamsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnelParams_get_OrigPort(TElLocalPortForwardSSHTunnelParamsHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElLocalPortForwardSSHTunnelParams_Create(const char * pcOrigHost, int32_t szOrigHost, int32_t OrigPort, TElLocalPortForwardSSHTunnelParamsHandle * OutResult);
#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELX11FORWARDSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_AuthenticationProtocol(TElX11ForwardSSHTunnelHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_set_AuthenticationProtocol(TElX11ForwardSSHTunnelHandle _Handle, const uint8_t pValue[], int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_ScreenNumber(TElX11ForwardSSHTunnelHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_set_ScreenNumber(TElX11ForwardSSHTunnelHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_TerminalInfo(TElX11ForwardSSHTunnelHandle _Handle, TElTerminalInfoHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_set_TerminalInfo(TElX11ForwardSSHTunnelHandle _Handle, TElTerminalInfoHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_Environment(TElX11ForwardSSHTunnelHandle _Handle, TStringListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_RequestTerminal(TElX11ForwardSSHTunnelHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_set_RequestTerminal(TElX11ForwardSSHTunnelHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_get_Target(TElX11ForwardSSHTunnelHandle _Handle, TElCustomSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_set_Target(TElX11ForwardSSHTunnelHandle _Handle, TElCustomSSHTunnelHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElX11ForwardSSHTunnel_Create(TComponentHandle AOwner, TElX11ForwardSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELX11FORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL
SB_IMPORT uint32_t SB_APIENTRY TElAuthenticationAgentSSHTunnel_Create(TComponentHandle AOwner, TElCustomSSHTunnelHandle * OutResult);
#endif /* SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHAUTHHANDLER
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_GetAlgorithmFromClientKexDHReply(TElSSHAuthHandlerHandle _Handle, const uint8_t pHostAlg[], int32_t szHostAlg, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_ValidateServerSignature(TElSSHAuthHandlerHandle _Handle, int32_t Algorithm, const uint8_t pPubKeyStr[], int32_t szPubKeyStr, const uint8_t pSignature[], int32_t szSignature, const uint8_t pHash[], int32_t szHash, int32_t HashAlg, int32_t * ErrCode, char * pcErrMessage, int32_t * szErrMessage, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_FindKeyByAlgorithm(TElSSHAuthHandlerHandle _Handle, TElSSHCustomKeyStorageHandle Storage, int32_t Algorithm, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_GetKeyBlob(TElSSHAuthHandlerHandle _Handle, TElSSHKeyHandle Key, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_KeyBlobToKey(TElSSHAuthHandlerHandle _Handle, const char * pcAlgName, int32_t szAlgName, const uint8_t pBlob[], int32_t szBlob, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_HashAlgFromKey(TElSSHAuthHandlerHandle _Handle, TElSSHKeyHandle Key, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_CalculateServerSignature(TElSSHAuthHandlerHandle _Handle, TElSSHKeyHandle Key, const uint8_t paHash[], int32_t szaHash, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_ServerValidateClientSignature(TElSSHAuthHandlerHandle _Handle, const uint8_t pAlgName[], int32_t szAlgName, const uint8_t pKeyBlob[], int32_t szKeyBlob, const uint8_t pSignature[], int32_t szSignature, const uint8_t pHash[], int32_t szHash, int8_t * Valid, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_get_SSHClass(TElSSHAuthHandlerHandle _Handle, IElSSHAuthHandlerContainerHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_set_SSHClass(TElSSHAuthHandlerHandle _Handle, IElSSHAuthHandlerContainerHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHAuthHandler_Create(TComponentHandle AOwner, TComponentHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHAUTHHANDLER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHClass;
typedef TElSSHClass ElSSHClass;
class TElSSHTunnelList;
typedef TElSSHTunnelList ElSSHTunnelList;
class TElCustomSSHTunnel;
typedef TElCustomSSHTunnel ElCustomSSHTunnel;
class TElSSHTunnelConnection;
typedef TElSSHTunnelConnection ElSSHTunnelConnection;
class TElCustomSSHTunnelParams;
class TElShellSSHTunnel;
typedef TElShellSSHTunnel ElShellSSHTunnel;
class TElCommandSSHTunnel;
typedef TElCommandSSHTunnel ElCommandSSHTunnel;
class TElSubsystemSSHTunnel;
typedef TElSubsystemSSHTunnel ElSubsystemSSHTunnel;
class TElRemotePortForwardSSHTunnel;
typedef TElRemotePortForwardSSHTunnel ElRemotePortForwardSSHTunnel;
class TElLocalPortForwardSSHTunnel;
typedef TElLocalPortForwardSSHTunnel ElLocalPortForwardSSHTunnel;
class TElLocalPortForwardSSHTunnelParams;
class TElX11ForwardSSHTunnel;
typedef TElX11ForwardSSHTunnel ElX11ForwardSSHTunnel;
class TElAuthenticationAgentSSHTunnel;
typedef TElAuthenticationAgentSSHTunnel ElAuthenticationAgentSSHTunnel;
class TElSSHAuthHandler;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSSHVersions)

#ifdef SB_USE_CLASS_TELSSHCLASS
class TElSSHClass: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHClass)
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_KeyStorage;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */
#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		TElCustomCryptoProviderManager* _Inst_CryptoProviderManager;
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		void initInstances();

	public:
		virtual void Close(bool Forced);

		virtual void RenegotiateCiphers();

		virtual void AdjustAlgorithmPriorities(TSSHStandardAlgorithmPriorityTemplate Priorities);

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSHClass, Active);

		virtual bool get_EncryptionAlgorithms(uint8_t Index);

		virtual void set_EncryptionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_CompressionAlgorithms(uint8_t Index);

		virtual void set_CompressionAlgorithms(uint8_t Index, bool Value);

		virtual bool get_MacAlgorithms(uint8_t Index);

		virtual void set_MacAlgorithms(uint8_t Index, bool Value);

		virtual bool get_KexAlgorithms(int8_t Index);

		virtual void set_KexAlgorithms(int8_t Index, bool Value);

		virtual bool get_PublicKeyAlgorithms(uint8_t Index);

		virtual void set_PublicKeyAlgorithms(uint8_t Index, bool Value);

		virtual int32_t get_EncryptionAlgorithmPriorities(uint8_t Index);

		virtual void set_EncryptionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_CompressionAlgorithmPriorities(uint8_t Index);

		virtual void set_CompressionAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_MacAlgorithmPriorities(uint8_t Index);

		virtual void set_MacAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual int32_t get_KexAlgorithmPriorities(int8_t Index);

		virtual void set_KexAlgorithmPriorities(int8_t Index, int32_t Value);

		virtual int32_t get_PublicKeyAlgorithmPriorities(uint8_t Index);

		virtual void set_PublicKeyAlgorithmPriorities(uint8_t Index, int32_t Value);

		virtual uint8_t get_EncryptionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmServerToClient, TElSSHClass, EncryptionAlgorithmServerToClient);

		virtual uint8_t get_EncryptionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_EncryptionAlgorithmClientToServer, TElSSHClass, EncryptionAlgorithmClientToServer);

		virtual uint8_t get_CompressionAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmServerToClient, TElSSHClass, CompressionAlgorithmServerToClient);

		virtual uint8_t get_CompressionAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_CompressionAlgorithmClientToServer, TElSSHClass, CompressionAlgorithmClientToServer);

		virtual uint8_t get_MacAlgorithmServerToClient();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmServerToClient, TElSSHClass, MacAlgorithmServerToClient);

		virtual uint8_t get_MacAlgorithmClientToServer();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_MacAlgorithmClientToServer, TElSSHClass, MacAlgorithmClientToServer);

		virtual int8_t get_KexAlgorithm();

		SB_DECLARE_PROPERTY_GET(int8_t, get_KexAlgorithm, TElSSHClass, KexAlgorithm);

		virtual uint8_t get_PublicKeyAlgorithm();

		SB_DECLARE_PROPERTY_GET(uint8_t, get_PublicKeyAlgorithm, TElSSHClass, PublicKeyAlgorithm);

		virtual int64_t get_TotalBytesSent();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesSent, TElSSHClass, TotalBytesSent);

		virtual int64_t get_TotalBytesReceived();

		SB_DECLARE_PROPERTY_GET(int64_t, get_TotalBytesReceived, TElSSHClass, TotalBytesReceived);

		virtual void get_SoftwareName(std::string &OutResult);

		virtual void set_SoftwareName(const std::string &Value);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_KeyStorage();

		virtual void set_KeyStorage(TElSSHCustomKeyStorage &Value);

		virtual void set_KeyStorage(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_KeyStorage, set_KeyStorage, TElSSHClass, KeyStorage);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual bool get_ForceCompression();

		virtual void set_ForceCompression(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ForceCompression, set_ForceCompression, TElSSHClass, ForceCompression);

		virtual int32_t get_CompressionLevel();

		virtual void set_CompressionLevel(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_CompressionLevel, set_CompressionLevel, TElSSHClass, CompressionLevel);

		virtual int32_t get_AuthenticationTypes();

		virtual void set_AuthenticationTypes(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthenticationTypes, set_AuthenticationTypes, TElSSHClass, AuthenticationTypes);

		virtual bool get_CloseIfNoActiveTunnels();

		virtual void set_CloseIfNoActiveTunnels(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CloseIfNoActiveTunnels, set_CloseIfNoActiveTunnels, TElSSHClass, CloseIfNoActiveTunnels);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSSHClass, UseUTF8);

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
		virtual TElCustomCryptoProviderManager* get_CryptoProviderManager();

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager &Value);

		virtual void set_CryptoProviderManager(TElCustomCryptoProviderManager *Value);

		SB_DECLARE_PROPERTY(TElCustomCryptoProviderManager*, get_CryptoProviderManager, set_CryptoProviderManager, TElSSHClass, CryptoProviderManager);
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

		virtual bool get_NoCharacterEncoding();

		virtual void set_NoCharacterEncoding(bool Value);

		SB_DECLARE_PROPERTY(bool, get_NoCharacterEncoding, set_NoCharacterEncoding, TElSSHClass, NoCharacterEncoding);

		virtual void get_LocalCharset(std::string &OutResult);

		virtual void set_LocalCharset(const std::string &Value);

		virtual void get_RemoteCharset(std::string &OutResult);

		virtual void set_RemoteCharset(const std::string &Value);

		virtual bool get_ObfuscateHandshake();

		virtual void set_ObfuscateHandshake(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ObfuscateHandshake, set_ObfuscateHandshake, TElSSHClass, ObfuscateHandshake);

		virtual void get_ObfuscationPassword(std::string &OutResult);

		virtual void set_ObfuscationPassword(const std::string &Value);

		virtual void get_OnSend(TSSHSendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSSHSendEvent pMethodValue, void * pDataValue);

		virtual void get_OnReceive(TSSHReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSSHReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpenConnection(TSSHOpenConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TSSHOpenConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TSSHCloseConnectionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TSSHCloseConnectionEvent pMethodValue, void * pDataValue);

		virtual void get_OnDebugData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnDebugData(TSSHDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnCiphersNegotiated(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCiphersNegotiated(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnKexInitReceived(TSSHKexInitReceivedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKexInitReceived(TSSHKexInitReceivedEvent pMethodValue, void * pDataValue);

		TElSSHClass(TElSSHClassHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHClass(TComponent &AOwner);

		explicit TElSSHClass(TComponent *AOwner);

		virtual ~TElSSHClass();

};
#endif /* SB_USE_CLASS_TELSSHCLASS */

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
class TElSSHTunnelList: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHTunnelList)
#ifdef SB_USE_CLASS_TELSSHCLASS
		TElSSHClass* _Inst_SSHClass;
#endif /* SB_USE_CLASS_TELSSHCLASS */
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		TElCustomSSHTunnel* _Inst_Tunnels;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		TElCustomSSHTunnelHandle FindTunnel(const std::string &SubSystemType, const std::string &SubSystemName);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHCLASS
		virtual TElSSHClass* get_SSHClass();

		SB_DECLARE_PROPERTY_GET(TElSSHClass*, get_SSHClass, TElSSHTunnelList, SSHClass);
#endif /* SB_USE_CLASS_TELSSHCLASS */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		virtual TElCustomSSHTunnel* get_Tunnels(int32_t Index);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSSHTunnelList, Count);

		TElSSHTunnelList(TElSSHTunnelListHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHTunnelList(TComponent &AOwner);

		explicit TElSSHTunnelList(TComponent *AOwner);

		virtual ~TElSSHTunnelList();

};
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
class TElCustomSSHTunnel: public TComponent
{
	private:
		SB_DISABLE_COPY(TElCustomSSHTunnel)
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		TElSSHTunnelConnection* _Inst_Connections;
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */
#ifdef SB_USE_CLASS_TLIST
		TList* _Inst_ConnectionsList;
#endif /* SB_USE_CLASS_TLIST */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
		TElSSHTunnelList* _Inst_TunnelList;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		void DoOpen(TElSSHTunnelConnection &Connection);

		void DoOpen(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		void DoClose(TElSSHTunnelConnection &Connection);

		void DoClose(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		void DoError(int32_t Error, void * Data);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		void AddConnection(TElSSHTunnelConnection &Conn);

		void AddConnection(TElSSHTunnelConnection *Conn);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		void RemoveConnection(TElSSHTunnelConnection &Conn);

		void RemoveConnection(TElSSHTunnelConnection *Conn);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		void Open(void * Data);

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		virtual TElSSHTunnelConnection* get_Connections(int32_t Index);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		virtual int32_t get_ConnectionCount();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ConnectionCount, TElCustomSSHTunnel, ConnectionCount);

#ifdef SB_USE_CLASS_TLIST
		virtual TList* get_ConnectionsList();

		SB_DECLARE_PROPERTY_GET(TList*, get_ConnectionsList, TElCustomSSHTunnel, ConnectionsList);
#endif /* SB_USE_CLASS_TLIST */

		virtual bool get_AutoOpen();

		virtual void set_AutoOpen(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoOpen, set_AutoOpen, TElCustomSSHTunnel, AutoOpen);

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
		virtual TElSSHTunnelList* get_TunnelList();

		virtual void set_TunnelList(TElSSHTunnelList &Value);

		virtual void set_TunnelList(TElSSHTunnelList *Value);

		SB_DECLARE_PROPERTY(TElSSHTunnelList*, get_TunnelList, set_TunnelList, TElCustomSSHTunnel, TunnelList);
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

		virtual void get_OnOpen(TTunnelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpen(TTunnelEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TTunnelEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TTunnelEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TTunnelErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TTunnelErrorEvent pMethodValue, void * pDataValue);

		TElCustomSSHTunnel(TElCustomSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElCustomSSHTunnel(TComponent &AOwner);

		explicit TElCustomSSHTunnel(TComponent *AOwner);

		virtual ~TElCustomSSHTunnel();

};
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
class TElSSHTunnelConnection: public TObject
{
	private:
		SB_DISABLE_COPY(TElSSHTunnelConnection)
#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		TElCustomSSHTunnel* _Inst_Tunnel;
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

		void initInstances();

	public:
		virtual void SendData(void * Buffer, int32_t Size);

		virtual void SendExtendedData(void * Buffer, int32_t Size);

		void SendSignal(const std::vector<uint8_t> &Signal);

		void SendText(const std::string &S);

		void SendExtendedText(const std::string &S);

		void Close(bool FlushCachedData);

		void Close(int32_t ExitStatus, bool FlushCachedData);

		void Close(const std::string &ExitSignal, const std::string &ExitMessage, bool FlushCachedData);

		void CloseLocal(bool FlushCachedData);

		virtual bool CanSend();

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNEL
		virtual TElCustomSSHTunnel* get_Tunnel();

		virtual void set_Tunnel(TElCustomSSHTunnel &Value);

		virtual void set_Tunnel(TElCustomSSHTunnel *Value);

		SB_DECLARE_PROPERTY(TElCustomSSHTunnel*, get_Tunnel, set_Tunnel, TElSSHTunnelConnection, Tunnel);
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNEL */

		virtual void * get_Data();

		virtual void set_Data(void * Value);

		SB_DECLARE_PROPERTY(void *, get_Data, set_Data, TElSSHTunnelConnection, Data);

		virtual bool get_UseUTF8();

		virtual void set_UseUTF8(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseUTF8, set_UseUTF8, TElSSHTunnelConnection, UseUTF8);

		virtual bool get_HasUnsentData();

		SB_DECLARE_PROPERTY_GET(bool, get_HasUnsentData, TElSSHTunnelConnection, HasUnsentData);

		virtual bool get_EOFSent();

		SB_DECLARE_PROPERTY_GET(bool, get_EOFSent, TElSSHTunnelConnection, EOFSent);

		virtual int32_t get_ExitStatus();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExitStatus, TElSSHTunnelConnection, ExitStatus);

		virtual void get_ExitSignal(std::string &OutResult);

		virtual void get_ExitMessage(std::string &OutResult);

		virtual bool get_ReturnExitStatus();

		virtual void set_ReturnExitStatus(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReturnExitStatus, set_ReturnExitStatus, TElSSHTunnelConnection, ReturnExitStatus);

		virtual bool get_ReturnExitSignal();

		virtual void set_ReturnExitSignal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ReturnExitSignal, set_ReturnExitSignal, TElSSHTunnelConnection, ReturnExitSignal);

		virtual void get_OnData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnData(TSSHDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnExtendedData(TSSHDataEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnExtendedData(TSSHDataEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSSHErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSSHErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TSSHChannelCloseEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TSSHChannelCloseEvent pMethodValue, void * pDataValue);

		virtual void get_OnWindowChanged(TSSHWindowChangedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnWindowChanged(TSSHWindowChangedEvent pMethodValue, void * pDataValue);

		virtual void get_OnEOF(TSSHEOFEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnEOF(TSSHEOFEvent pMethodValue, void * pDataValue);

		TElSSHTunnelConnection(TElSSHTunnelConnectionHandle handle, TElOwnHandle ownHandle);

		TElSSHTunnelConnection();

		virtual ~TElSSHTunnelConnection();

};
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

#ifdef SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS
class TElCustomSSHTunnelParams: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSSHTunnelParams)
	public:
		TElCustomSSHTunnelParams(TElCustomSSHTunnelParamsHandle handle, TElOwnHandle ownHandle);

		TElCustomSSHTunnelParams();

};
#endif /* SB_USE_CLASS_TELCUSTOMSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELSHELLSSHTUNNEL
class TElShellSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElShellSSHTunnel)
#ifdef SB_USE_CLASS_TELTERMINALINFO
		TElTerminalInfo* _Inst_TerminalInfo;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELTERMINALINFO
		virtual TElTerminalInfo* get_TerminalInfo();

		virtual void set_TerminalInfo(TElTerminalInfo &Value);

		virtual void set_TerminalInfo(TElTerminalInfo *Value);

		SB_DECLARE_PROPERTY(TElTerminalInfo*, get_TerminalInfo, set_TerminalInfo, TElShellSSHTunnel, TerminalInfo);
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Environment();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Environment, TElShellSSHTunnel, Environment);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual bool get_RequestTerminal();

		virtual void set_RequestTerminal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestTerminal, set_RequestTerminal, TElShellSSHTunnel, RequestTerminal);

		TElShellSSHTunnel(TElShellSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElShellSSHTunnel(TComponent &AOwner);

		explicit TElShellSSHTunnel(TComponent *AOwner);

		virtual ~TElShellSSHTunnel();

};
#endif /* SB_USE_CLASS_TELSHELLSSHTUNNEL */

#ifdef SB_USE_CLASS_TELCOMMANDSSHTUNNEL
class TElCommandSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElCommandSSHTunnel)
#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSTRINGLIST
		TElStringList* _Inst_Commands;
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Commands;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */
#endif
#ifdef SB_USE_CLASS_TELTERMINALINFO
		TElTerminalInfo* _Inst_TerminalInfo;
#endif /* SB_USE_CLASS_TELTERMINALINFO */

		void initInstances();

	public:
		virtual void get_Command(std::string &OutResult);

		virtual void set_Command(const std::string &Value);

#ifdef SB_WINDOWS
#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Commands();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Commands, TElCommandSSHTunnel, Commands);
#endif /* SB_USE_CLASS_TSTRINGLIST */
#else
#ifdef SB_USE_CLASS_TELSTRINGLIST
		virtual TElStringList* get_Commands();

		SB_DECLARE_PROPERTY_GET(TElStringList*, get_Commands, TElCommandSSHTunnel, Commands);
#endif /* SB_USE_CLASS_TELSTRINGLIST */
#endif

		virtual int32_t get_ActiveCommand();

		virtual void set_ActiveCommand(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ActiveCommand, set_ActiveCommand, TElCommandSSHTunnel, ActiveCommand);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Environment();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Environment, TElCommandSSHTunnel, Environment);
#endif /* SB_USE_CLASS_TSTRINGLIST */

#ifdef SB_USE_CLASS_TELTERMINALINFO
		virtual TElTerminalInfo* get_TerminalInfo();

		virtual void set_TerminalInfo(TElTerminalInfo &Value);

		virtual void set_TerminalInfo(TElTerminalInfo *Value);

		SB_DECLARE_PROPERTY(TElTerminalInfo*, get_TerminalInfo, set_TerminalInfo, TElCommandSSHTunnel, TerminalInfo);
#endif /* SB_USE_CLASS_TELTERMINALINFO */

		virtual bool get_RequestTerminal();

		virtual void set_RequestTerminal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestTerminal, set_RequestTerminal, TElCommandSSHTunnel, RequestTerminal);

		TElCommandSSHTunnel(TElCommandSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElCommandSSHTunnel(TComponent &AOwner);

		explicit TElCommandSSHTunnel(TComponent *AOwner);

		virtual ~TElCommandSSHTunnel();

};
#endif /* SB_USE_CLASS_TELCOMMANDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
class TElSubsystemSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElSubsystemSSHTunnel)
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */

		void initInstances();

	public:
		virtual void get_Subsystem(std::string &OutResult);

		virtual void set_Subsystem(const std::string &Value);

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Environment();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Environment, TElSubsystemSSHTunnel, Environment);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		TElSubsystemSSHTunnel(TElSubsystemSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElSubsystemSSHTunnel(TComponent &AOwner);

		explicit TElSubsystemSSHTunnel(TComponent *AOwner);

		virtual ~TElSubsystemSSHTunnel();

};
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

#ifdef SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL
class TElRemotePortForwardSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElRemotePortForwardSSHTunnel)
	public:
		void DoSetupSucceeded();

		void DoSetupFailed();

		void GetToHost(std::string &OutResult);

		void SetToHost(const std::string &AValue);

		void Close();

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElRemotePortForwardSSHTunnel, Port);

		virtual void get_ToHost(std::string &OutResult);

		virtual void set_ToHost(const std::string &Value);

		virtual int32_t get_ToPort();

		virtual void set_ToPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ToPort, set_ToPort, TElRemotePortForwardSSHTunnel, ToPort);

		virtual int32_t get_BoundPort();

		virtual void set_BoundPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_BoundPort, set_BoundPort, TElRemotePortForwardSSHTunnel, BoundPort);

		virtual bool get_UseDefaultBindAddress();

		virtual void set_UseDefaultBindAddress(bool Value);

		SB_DECLARE_PROPERTY(bool, get_UseDefaultBindAddress, set_UseDefaultBindAddress, TElRemotePortForwardSSHTunnel, UseDefaultBindAddress);

		virtual void get_OnSetupSucceeded(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetupSucceeded(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnSetupFailed(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSetupFailed(TNotifyEvent pMethodValue, void * pDataValue);

		TElRemotePortForwardSSHTunnel(TElRemotePortForwardSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElRemotePortForwardSSHTunnel(TComponent &AOwner);

		explicit TElRemotePortForwardSSHTunnel(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELREMOTEPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL
class TElLocalPortForwardSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElLocalPortForwardSSHTunnel)
	public:
		void GetToHost(std::string &OutResult);

		void SetToHost(const std::string &AValue);

		void Open(void * Data, const std::string &OrigHost, int32_t OrigPort);

		virtual int32_t get_Port();

		virtual void set_Port(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Port, set_Port, TElLocalPortForwardSSHTunnel, Port);

		virtual void get_Host(std::string &OutResult);

		virtual void set_Host(const std::string &Value);

		virtual void get_ToHost(std::string &OutResult);

		virtual void set_ToHost(const std::string &Value);

		virtual int32_t get_ToPort();

		virtual void set_ToPort(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ToPort, set_ToPort, TElLocalPortForwardSSHTunnel, ToPort);

		TElLocalPortForwardSSHTunnel(TElLocalPortForwardSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElLocalPortForwardSSHTunnel(TComponent &AOwner);

		explicit TElLocalPortForwardSSHTunnel(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS
class TElLocalPortForwardSSHTunnelParams: public TElCustomSSHTunnelParams
{
	private:
		SB_DISABLE_COPY(TElLocalPortForwardSSHTunnelParams)
	public:
		virtual void get_OrigHost(std::string &OutResult);

		virtual int32_t get_OrigPort();

		SB_DECLARE_PROPERTY_GET(int32_t, get_OrigPort, TElLocalPortForwardSSHTunnelParams, OrigPort);

		TElLocalPortForwardSSHTunnelParams(TElLocalPortForwardSSHTunnelParamsHandle handle, TElOwnHandle ownHandle);

		TElLocalPortForwardSSHTunnelParams(const std::string &OrigHost, int32_t OrigPort);

};
#endif /* SB_USE_CLASS_TELLOCALPORTFORWARDSSHTUNNELPARAMS */

#ifdef SB_USE_CLASS_TELX11FORWARDSSHTUNNEL
class TElX11ForwardSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElX11ForwardSSHTunnel)
#ifdef SB_USE_CLASS_TELTERMINALINFO
		TElTerminalInfo* _Inst_TerminalInfo;
#endif /* SB_USE_CLASS_TELTERMINALINFO */
#ifdef SB_USE_CLASS_TSTRINGLIST
		TStringList* _Inst_Environment;
#endif /* SB_USE_CLASS_TSTRINGLIST */
		TElCustomSSHTunnel* _Inst_Target;

		void initInstances();

	public:
		virtual void get_AuthenticationProtocol(std::vector<uint8_t> &OutResult);

		virtual void set_AuthenticationProtocol(const std::vector<uint8_t> &Value);

		virtual int32_t get_ScreenNumber();

		virtual void set_ScreenNumber(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_ScreenNumber, set_ScreenNumber, TElX11ForwardSSHTunnel, ScreenNumber);

#ifdef SB_USE_CLASS_TELTERMINALINFO
		virtual TElTerminalInfo* get_TerminalInfo();

		virtual void set_TerminalInfo(TElTerminalInfo &Value);

		virtual void set_TerminalInfo(TElTerminalInfo *Value);

		SB_DECLARE_PROPERTY(TElTerminalInfo*, get_TerminalInfo, set_TerminalInfo, TElX11ForwardSSHTunnel, TerminalInfo);
#endif /* SB_USE_CLASS_TELTERMINALINFO */

#ifdef SB_USE_CLASS_TSTRINGLIST
		virtual TStringList* get_Environment();

		SB_DECLARE_PROPERTY_GET(TStringList*, get_Environment, TElX11ForwardSSHTunnel, Environment);
#endif /* SB_USE_CLASS_TSTRINGLIST */

		virtual bool get_RequestTerminal();

		virtual void set_RequestTerminal(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestTerminal, set_RequestTerminal, TElX11ForwardSSHTunnel, RequestTerminal);

		virtual TElCustomSSHTunnel* get_Target();

		virtual void set_Target(TElCustomSSHTunnel &Value);

		virtual void set_Target(TElCustomSSHTunnel *Value);

		SB_DECLARE_PROPERTY(TElCustomSSHTunnel*, get_Target, set_Target, TElX11ForwardSSHTunnel, Target);

		TElX11ForwardSSHTunnel(TElX11ForwardSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElX11ForwardSSHTunnel(TComponent &AOwner);

		explicit TElX11ForwardSSHTunnel(TComponent *AOwner);

		virtual ~TElX11ForwardSSHTunnel();

};
#endif /* SB_USE_CLASS_TELX11FORWARDSSHTUNNEL */

#ifdef SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL
class TElAuthenticationAgentSSHTunnel: public TElCustomSSHTunnel
{
	private:
		SB_DISABLE_COPY(TElAuthenticationAgentSSHTunnel)
	public:
		TElAuthenticationAgentSSHTunnel(TElAuthenticationAgentSSHTunnelHandle handle, TElOwnHandle ownHandle);

		explicit TElAuthenticationAgentSSHTunnel(TComponent &AOwner);

		explicit TElAuthenticationAgentSSHTunnel(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELAUTHENTICATIONAGENTSSHTUNNEL */

#ifdef SB_USE_CLASS_TELSSHAUTHHANDLER
class TElSSHAuthHandler: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHAuthHandler)
	public:
		virtual int32_t GetAlgorithmFromClientKexDHReply(const std::vector<uint8_t> &HostAlg);

		virtual bool ValidateServerSignature(int32_t Algorithm, const std::vector<uint8_t> &PubKeyStr, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, int32_t HashAlg, int32_t &ErrCode, std::string &ErrMessage);

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual int32_t FindKeyByAlgorithm(TElSSHCustomKeyStorage &Storage, int32_t Algorithm);

		virtual int32_t FindKeyByAlgorithm(TElSSHCustomKeyStorage *Storage, int32_t Algorithm);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void GetKeyBlob(TElSSHKey &Key, std::vector<uint8_t> &OutResult);

		virtual void GetKeyBlob(TElSSHKey *Key, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKeyHandle KeyBlobToKey(const std::string &AlgName, const std::vector<uint8_t> &Blob);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual int32_t HashAlgFromKey(TElSSHKey &Key);

		virtual int32_t HashAlgFromKey(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual void CalculateServerSignature(TElSSHKey &Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult);

		virtual void CalculateServerSignature(TElSSHKey *Key, const std::vector<uint8_t> &aHash, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TELSSHKEY */

		virtual bool ServerValidateClientSignature(const std::vector<uint8_t> &AlgName, const std::vector<uint8_t> &KeyBlob, const std::vector<uint8_t> &Signature, const std::vector<uint8_t> &Hash, bool &Valid);

#ifdef SB_USE_CLASS_IELSSHAUTHHANDLERCONTAINER
		virtual IElSSHAuthHandlerContainerHandle get_SSHClass();

		virtual void set_SSHClass(IElSSHAuthHandlerContainerHandle Value);

		SB_DECLARE_PROPERTY(IElSSHAuthHandlerContainerHandle, get_SSHClass, set_SSHClass, TElSSHAuthHandler, SSHClass);
#endif /* SB_USE_CLASS_IELSSHAUTHHANDLERCONTAINER */

		TElSSHAuthHandler(TElSSHAuthHandlerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHAuthHandler(TComponent &AOwner);

		explicit TElSSHAuthHandler(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHAUTHHANDLER */

#ifdef SB_USE_GLOBAL_PROCS_SSHCOMMON

#ifdef SB_USE_CLASS_TPLCONVERTER
void SSHEncodeString(const std::string &S, bool UseUTF8, bool NoTranslation, TPlConverter &Converter, std::vector<uint8_t> &OutResult);
void SSHEncodeString(const std::string &S, bool UseUTF8, bool NoTranslation, TPlConverter *Converter, std::vector<uint8_t> &OutResult);
#endif /* SB_USE_CLASS_TPLCONVERTER */

#ifdef SB_USE_CLASS_TPLCONVERTER
void SSHDecodeString(const std::vector<uint8_t> &Buf, bool UseUTF8, bool NoTranslation, TPlConverter &Converter, std::string &OutResult);
void SSHDecodeString(const std::vector<uint8_t> &Buf, bool UseUTF8, bool NoTranslation, TPlConverter *Converter, std::string &OutResult);
#endif /* SB_USE_CLASS_TPLCONVERTER */

#endif /* SB_USE_GLOBAL_PROCS_SSHCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SSHCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBSSHCommon_SSHEncodeString(const char * pcS, int32_t szS, int8_t UseUTF8, int8_t NoTranslation, TPlConverterHandle Converter, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBSSHCommon_SSHDecodeString(const uint8_t pBuf[], int32_t szBuf, int8_t UseUTF8, int8_t NoTranslation, TPlConverterHandle Converter, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_SSHCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHCOMMON */
