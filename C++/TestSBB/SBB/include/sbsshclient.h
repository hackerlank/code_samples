#ifndef __INC_SBSSHCLIENT
#define __INC_SBSSHCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbmath.h"
#include "sbcryptoprov.h"
#include "sbsymmetriccrypto.h"
#include "sbcustomcrypto.h"
#include "sbpublickeycrypto.h"
#include "sbhashfunction.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbstrutils.h"
#include "sbstringlist.h"
#include "sbencoding.h"
#include "sbsshterm.h"
#include "sbsharedresource.h"
#include "sbsshconstants.h"
#include "sbsshcommon.h"
#include "sbzlib.h"
#include "sbsshkeystorage.h"
#include "sbsshutils.h"
#include "sbgssapibase.h"
#include "sbgssapi.h"
#ifndef WINCE
#include "sbsshauthagent.h"
#endif
#include "sbconstants.h"
#include "sbecmath.h"
#include "sbpoly1305.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SSH_OPEN_ADMINISTRATIVELY_PROHIBITED 	1

typedef TElClassHandle TElSSHClientHandle;

typedef TElSSHClientHandle ElSSHClientHandle;

typedef TElClassHandle TElSSHClientTunnelListHandle;

typedef TElSSHClientTunnelListHandle ElSSHClientTunnelListHandle;

typedef TElClassHandle TElSSHClientTunnelConnectionHandle;

typedef TElSSHClientTunnelConnectionHandle ElSSHClientTunnelConnectionHandle;

typedef uint8_t TSSHClientStateRaw;

typedef enum
{
	csBefore = 0,
	csIdentificationLineReceived = 1,
	csIdentificationLineSent = 2
} TSSHClientState;

typedef uint8_t TSBSSHCertAuthModeRaw;

typedef enum
{
	camAuto = 0,
	camStandard = 1,
	camTectia = 2,
	camRawPublicKey = 3
} TSBSSHCertAuthMode;

#ifdef SB_USE_CLASS_TELSSHCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_Open(TElSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_Close(TElSSHClientHandle _Handle, int8_t Forced);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_DataAvailable(TElSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_RenegotiateCiphers(TElSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_SendKeepAlive(TElSSHClientHandle _Handle, TElSSHTunnelConnectionHandle Connection);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_SendIgnore(TElSSHClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_SendIgnore_1(TElSSHClientHandle _Handle, const uint8_t pData[], int32_t szData, int32_t StartIndex, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_Version(TElSSHClientHandle _Handle, TSSHVersionRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ServerCloseReason(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ServerSoftwareName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ErrorString(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_KbdIntName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_KbdIntInstruction(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_AuthTypePriorities(TElSSHClientHandle _Handle, int32_t Index, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_AuthTypePriorities(TElSSHClientHandle _Handle, int32_t Index, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ServerKey(TElSSHClientHandle _Handle, TElSSHKeyHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_GSSMechanism(TElSSHClientHandle _Handle, TElGSSBaseMechanismHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_GSSMechanism(TElSSHClientHandle _Handle, TElGSSBaseMechanismHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_GSSHostName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_GSSHostName(TElSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_GSSDelegateCredentials(TElSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_GSSDelegateCredentials(TElSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_SSHAuthOrder(TElSSHClientHandle _Handle, TSBSSHAuthOrderRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_SSHAuthOrder(TElSSHClientHandle _Handle, TSBSSHAuthOrderRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_Versions(TElSSHClientHandle _Handle, TSSHVersionsRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_Versions(TElSSHClientHandle _Handle, TSSHVersionsRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ClientUserName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_ClientUserName(TElSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ClientHostName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_ClientHostName(TElSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_DefaultWindowSize(TElSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_DefaultWindowSize(TElSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_MinWindowSize(TElSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_MinWindowSize(TElSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_MaxSSHPacketSize(TElSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_MaxSSHPacketSize(TElSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_UserName(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_UserName(TElSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_Password(TElSSHClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_Password(TElSSHClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_TunnelList(TElSSHClientHandle _Handle, TElSSHTunnelListHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_TunnelList(TElSSHClientHandle _Handle, TElSSHTunnelListHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_TrustedKeys(TElSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_TrustedKeys(TElSSHClientHandle _Handle, TElSSHCustomKeyStorageHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_ThreadSafe(TElSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_ThreadSafe(TElSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_CertAuthMode(TElSSHClientHandle _Handle, TSBSSHCertAuthModeRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_CertAuthMode(TElSSHClientHandle _Handle, TSBSSHCertAuthModeRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_AutoAdjustCiphers(TElSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_AutoAdjustCiphers(TElSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_RequestPasswordChange(TElSSHClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_RequestPasswordChange(TElSSHClientHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_AuthAttempts(TElSSHClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_AuthAttempts(TElSSHClientHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnKeyValidate(TElSSHClientHandle _Handle, TSSHKeyValidateEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnKeyValidate(TElSSHClientHandle _Handle, TSSHKeyValidateEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnAuthenticationSuccess(TElSSHClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnAuthenticationSuccess(TElSSHClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnAuthenticationFailed(TElSSHClientHandle _Handle, TSSHAuthenticationFailedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnAuthenticationFailed(TElSSHClientHandle _Handle, TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnAuthenticationKeyboard(TElSSHClientHandle _Handle, TSSHAuthenticationKeyboardEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnAuthenticationKeyboard(TElSSHClientHandle _Handle, TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnAuthenticationStart(TElSSHClientHandle _Handle, TSSHAuthenticationStartEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnAuthenticationStart(TElSSHClientHandle _Handle, TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnAuthenticationAttempt(TElSSHClientHandle _Handle, TSSHAuthenticationAttemptEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnAuthenticationAttempt(TElSSHClientHandle _Handle, TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnBanner(TElSSHClientHandle _Handle, TSSHBannerEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnBanner(TElSSHClientHandle _Handle, TSSHBannerEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnPrivateKeyNeeded(TElSSHClientHandle _Handle, TSSHPrivateKeyNeededEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnPrivateKeyNeeded(TElSSHClientHandle _Handle, TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnSendCommandRequest(TElSSHClientHandle _Handle, TSSHCommandExecutionEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnSendCommandRequest(TElSSHClientHandle _Handle, TSSHCommandExecutionEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnPasswordChangeRequest(TElSSHClientHandle _Handle, TSSHPasswordChangeRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnPasswordChangeRequest(TElSSHClientHandle _Handle, TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_get_OnTunnelRequest(TElSSHClientHandle _Handle, TSSHTunnelRequestEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_set_OnTunnelRequest(TElSSHClientHandle _Handle, TSSHTunnelRequestEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClient_Create(TComponentHandle AOwner, TElSSHClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCLIENT */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELLIST
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelList_Create(TComponentHandle AOwner, TElSSHTunnelListHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELLIST */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelConnection_SendData(TElSSHClientTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelConnection_SendExtendedData(TElSSHClientTunnelConnectionHandle _Handle, void * Buffer, int32_t Size);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelConnection_CanSend(TElSSHClientTunnelConnectionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelConnection_get_ExtendedDataType(TElSSHClientTunnelConnectionHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHClientTunnelConnection_Create(TElSSHTunnelConnectionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHClient;
typedef TElSSHClient ElSSHClient;
class TElSSHClientTunnelList;
typedef TElSSHClientTunnelList ElSSHClientTunnelList;
class TElSSHClientTunnelConnection;
typedef TElSSHClientTunnelConnection ElSSHClientTunnelConnection;

#ifdef SB_USE_CLASS_TELSSHCLIENT
class TElSSHClient: public TElSSHClass
{
	private:
		SB_DISABLE_COPY(TElSSHClient)
#ifdef SB_USE_CLASS_TELSSHKEY
		TElSSHKey* _Inst_ServerKey;
#endif /* SB_USE_CLASS_TELSSHKEY */
#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		TElGSSBaseMechanism* _Inst_GSSMechanism;
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */
#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
		TElSSHTunnelList* _Inst_TunnelList;
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */
#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		TElSSHCustomKeyStorage* _Inst_TrustedKeys;
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		void initInstances();

	public:
		void Open();

		virtual void Close(bool Forced);

		void DataAvailable();

		virtual void RenegotiateCiphers();

#ifdef SB_USE_CLASS_TELSSHTUNNELCONNECTION
		void SendKeepAlive(TElSSHTunnelConnection &Connection);

		void SendKeepAlive(TElSSHTunnelConnection *Connection);
#endif /* SB_USE_CLASS_TELSSHTUNNELCONNECTION */

		void SendIgnore();

		void SendIgnore(const std::vector<uint8_t> &Data, int32_t StartIndex, int32_t Count);

		virtual TSSHVersion get_Version();

		SB_DECLARE_PROPERTY_GET(TSSHVersion, get_Version, TElSSHClient, Version);

		virtual void get_ServerCloseReason(std::string &OutResult);

		virtual void get_ServerSoftwareName(std::string &OutResult);

		virtual void get_ErrorString(std::string &OutResult);

		virtual void get_KbdIntName(std::string &OutResult);

		virtual void get_KbdIntInstruction(std::string &OutResult);

		virtual int32_t get_AuthTypePriorities(int32_t Index);

		virtual void set_AuthTypePriorities(int32_t Index, int32_t Value);

#ifdef SB_USE_CLASS_TELSSHKEY
		virtual TElSSHKey* get_ServerKey();

		SB_DECLARE_PROPERTY_GET(TElSSHKey*, get_ServerKey, TElSSHClient, ServerKey);
#endif /* SB_USE_CLASS_TELSSHKEY */

#ifdef SB_USE_CLASS_TELGSSBASEMECHANISM
		virtual TElGSSBaseMechanism* get_GSSMechanism();

		virtual void set_GSSMechanism(TElGSSBaseMechanism &Value);

		virtual void set_GSSMechanism(TElGSSBaseMechanism *Value);

		SB_DECLARE_PROPERTY(TElGSSBaseMechanism*, get_GSSMechanism, set_GSSMechanism, TElSSHClient, GSSMechanism);
#endif /* SB_USE_CLASS_TELGSSBASEMECHANISM */

		virtual void get_GSSHostName(std::string &OutResult);

		virtual void set_GSSHostName(const std::string &Value);

		virtual bool get_GSSDelegateCredentials();

		virtual void set_GSSDelegateCredentials(bool Value);

		SB_DECLARE_PROPERTY(bool, get_GSSDelegateCredentials, set_GSSDelegateCredentials, TElSSHClient, GSSDelegateCredentials);

		virtual TSBSSHAuthOrder get_SSHAuthOrder();

		virtual void set_SSHAuthOrder(TSBSSHAuthOrder Value);

		SB_DECLARE_PROPERTY(TSBSSHAuthOrder, get_SSHAuthOrder, set_SSHAuthOrder, TElSSHClient, SSHAuthOrder);

		virtual TSSHVersions get_Versions();

		virtual void set_Versions(TSSHVersions Value);

		SB_DECLARE_PROPERTY(TSSHVersions, get_Versions, set_Versions, TElSSHClient, Versions);

		virtual void get_ClientUserName(std::string &OutResult);

		virtual void set_ClientUserName(const std::string &Value);

		virtual void get_ClientHostName(std::string &OutResult);

		virtual void set_ClientHostName(const std::string &Value);

		virtual int32_t get_DefaultWindowSize();

		virtual void set_DefaultWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_DefaultWindowSize, set_DefaultWindowSize, TElSSHClient, DefaultWindowSize);

		virtual int32_t get_MinWindowSize();

		virtual void set_MinWindowSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MinWindowSize, set_MinWindowSize, TElSSHClient, MinWindowSize);

		virtual int32_t get_MaxSSHPacketSize();

		virtual void set_MaxSSHPacketSize(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxSSHPacketSize, set_MaxSSHPacketSize, TElSSHClient, MaxSSHPacketSize);

		virtual void get_UserName(std::string &OutResult);

		virtual void set_UserName(const std::string &Value);

		virtual void get_Password(std::string &OutResult);

		virtual void set_Password(const std::string &Value);

#ifdef SB_USE_CLASS_TELSSHTUNNELLIST
		virtual TElSSHTunnelList* get_TunnelList();

		virtual void set_TunnelList(TElSSHTunnelList &Value);

		virtual void set_TunnelList(TElSSHTunnelList *Value);

		SB_DECLARE_PROPERTY(TElSSHTunnelList*, get_TunnelList, set_TunnelList, TElSSHClient, TunnelList);
#endif /* SB_USE_CLASS_TELSSHTUNNELLIST */

#ifdef SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE
		virtual TElSSHCustomKeyStorage* get_TrustedKeys();

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage &Value);

		virtual void set_TrustedKeys(TElSSHCustomKeyStorage *Value);

		SB_DECLARE_PROPERTY(TElSSHCustomKeyStorage*, get_TrustedKeys, set_TrustedKeys, TElSSHClient, TrustedKeys);
#endif /* SB_USE_CLASS_TELSSHCUSTOMKEYSTORAGE */

		virtual bool get_ThreadSafe();

		virtual void set_ThreadSafe(bool Value);

		SB_DECLARE_PROPERTY(bool, get_ThreadSafe, set_ThreadSafe, TElSSHClient, ThreadSafe);

		virtual TSBSSHCertAuthMode get_CertAuthMode();

		virtual void set_CertAuthMode(TSBSSHCertAuthMode Value);

		SB_DECLARE_PROPERTY(TSBSSHCertAuthMode, get_CertAuthMode, set_CertAuthMode, TElSSHClient, CertAuthMode);

		virtual bool get_AutoAdjustCiphers();

		virtual void set_AutoAdjustCiphers(bool Value);

		SB_DECLARE_PROPERTY(bool, get_AutoAdjustCiphers, set_AutoAdjustCiphers, TElSSHClient, AutoAdjustCiphers);

		virtual bool get_RequestPasswordChange();

		virtual void set_RequestPasswordChange(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RequestPasswordChange, set_RequestPasswordChange, TElSSHClient, RequestPasswordChange);

		virtual int32_t get_AuthAttempts();

		virtual void set_AuthAttempts(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_AuthAttempts, set_AuthAttempts, TElSSHClient, AuthAttempts);

		virtual void get_OnKeyValidate(TSSHKeyValidateEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnKeyValidate(TSSHKeyValidateEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationSuccess(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationSuccess(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationFailed(TSSHAuthenticationFailedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationFailed(TSSHAuthenticationFailedEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationKeyboard(TSSHAuthenticationKeyboardEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationStart(TSSHAuthenticationStartEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationStart(TSSHAuthenticationStartEvent pMethodValue, void * pDataValue);

		virtual void get_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAuthenticationAttempt(TSSHAuthenticationAttemptEvent pMethodValue, void * pDataValue);

		virtual void get_OnBanner(TSSHBannerEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnBanner(TSSHBannerEvent pMethodValue, void * pDataValue);

		virtual void get_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPrivateKeyNeeded(TSSHPrivateKeyNeededEvent pMethodValue, void * pDataValue);

		virtual void get_OnSendCommandRequest(TSSHCommandExecutionEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSendCommandRequest(TSSHCommandExecutionEvent pMethodValue, void * pDataValue);

		virtual void get_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPasswordChangeRequest(TSSHPasswordChangeRequestEvent pMethodValue, void * pDataValue);

		virtual void get_OnTunnelRequest(TSSHTunnelRequestEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTunnelRequest(TSSHTunnelRequestEvent pMethodValue, void * pDataValue);

		TElSSHClient(TElSSHClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHClient(TComponent &AOwner);

		explicit TElSSHClient(TComponent *AOwner);

		virtual ~TElSSHClient();

};
#endif /* SB_USE_CLASS_TELSSHCLIENT */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELLIST
class TElSSHClientTunnelList: public TElSSHTunnelList
{
	private:
		SB_DISABLE_COPY(TElSSHClientTunnelList)
	public:
		TElSSHClientTunnelList(TElSSHClientTunnelListHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHClientTunnelList(TComponent &AOwner);

		explicit TElSSHClientTunnelList(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELLIST */

#ifdef SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION
class TElSSHClientTunnelConnection: public TElSSHTunnelConnection
{
	private:
		SB_DISABLE_COPY(TElSSHClientTunnelConnection)
	public:
		virtual void SendData(void * Buffer, int32_t Size);

		virtual void SendExtendedData(void * Buffer, int32_t Size);

		virtual bool CanSend();

		virtual int32_t get_ExtendedDataType();

		SB_DECLARE_PROPERTY_GET(int32_t, get_ExtendedDataType, TElSSHClientTunnelConnection, ExtendedDataType);

		TElSSHClientTunnelConnection(TElSSHClientTunnelConnectionHandle handle, TElOwnHandle ownHandle);

		TElSSHClientTunnelConnection();

};
#endif /* SB_USE_CLASS_TELSSHCLIENTTUNNELCONNECTION */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHCLIENT */
