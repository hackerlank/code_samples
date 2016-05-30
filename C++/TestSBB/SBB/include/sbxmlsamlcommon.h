#ifndef __INC_SBXMLSAMLCOMMON
#define __INC_SBXMLSAMLCOMMON

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbstringlist.h"
#include "sbstreams.h"
#include "sbconstants.h"
#include "sbdictionary.h"
#include "sbxmlcore.h"
#include "sbxmlsig.h"
#include "sbxmlenc.h"
#include "sbxmlsec.h"
#include "sbxmlutils.h"
#include "sbxmldefs.h"
#include "sbstrutils.h"
#include "sbxmlsamlmetadata.h"
#include "sbxmlsamlprotocol.h"
#include "sbxmlsamlcore.h"
#include "sbxmlsamlbind.h"
#include "sbhttpscommon.h"
#include "sbsharedresource.h"
#include "sbcustomcertstorage.h"
#include "sbx509.h"
#include "sbutils.h"
#include "sbtypes.h"
#include "sbrandom.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define SB_SFailedToDownloadMetadata 	"Failed to download metadata: "
#define SB_SWrongEntityID 	"Wrong entityID attribute: "
#define SB_SWrongKeyDescriptor 	"Metadata: wrong KeyDescriptor element"
#define SB_SMetadataIncomplete 	"Metadata is incomplete"
#define SB_SMetadataExpired 	"Matadata expired"
#define SB_SMetadataMultipleDescriptorsAvailable 	"Multiple descriptors are stored in metadata file. Please assign OnChooseMetadataIDPDescriptor event handler to choose the one to use."
#ifndef SB_SDecryptionError
#define SB_SDecryptionError 	"Failed to decrypt encrypted XML element"
#endif
#define SB_SUnsupportedMetadataURI 	"Unsupported metadata URI"

typedef TElClassHandle TElSAMLClientSettingsHandle;

typedef TElClassHandle TElSAMLSessionHandle;

typedef TElClassHandle TElCustomSessionManagerHandle;

typedef TElClassHandle TElMemorySessionManagerHandle;

typedef TElClassHandle SBXMLSAMLCommon_TElStringValueHandle;

typedef TElClassHandle TElCustomArtifactStorageHandle;

typedef TElClassHandle TElMemoryArtifactStorageHandle;

typedef TElClassHandle TElSAMLAdapterHandle;

typedef uint8_t TSBSAMLClientProfileRaw;

typedef enum
{
	scpWebSSO = 0
} TSBSAMLClientProfile;

typedef uint32_t TSBSAMLClientProfilesRaw;

typedef enum 
{
	f_scpWebSSO = 1
} TSBSAMLClientProfiles;

typedef uint8_t TSBSAMLClientStateRaw;

typedef enum
{
	scsStart = 0,
	scsSAMLRequestRecv = 1,
	scsSAMLRequestSent = 2,
	scsIdentRecv = 3,
	scsIdentSent = 4,
	scsResponseRecv = 5,
	scsResponseSent = 6
} TSBSAMLClientState;

typedef void (SB_CALLBACK *TSBSAMLResourceOpenEvent)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, void * (* Handle));

typedef void (SB_CALLBACK *TSBSAMLResourceReadEvent)(void * _ObjectData, TObjectHandle Sender, void * Handle, uint8_t pBuf[], int32_t * szBuf, int32_t * Size);

typedef void (SB_CALLBACK *TSBSAMLResourceCloseEvent)(void * _ObjectData, TObjectHandle Sender, void * Handle);

typedef void (SB_CALLBACK *TSBSAMLMetadataPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLMetadataHandle Metadata);

typedef void (SB_CALLBACK *TSBSAMLBeforeBindingUseEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLBindingHandle Binding);

typedef void (SB_CALLBACK *SBXMLSAMLCommon_TSBSAMLBeforeHTTPSServerUseEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle HTTPSServer);

typedef void (SB_CALLBACK *TSBSAMLBeforeHTTPSClientUseEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle HTTPSClient);

typedef void (SB_CALLBACK *TSBSAMLResponderErrorEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLStatusElementHandle Status, int32_t * StatusCode, char * pcRedirectLocation, int32_t * szRedirectLocation);

typedef void (SB_CALLBACK *TSBSAMLResponseStatusCodeEvent)(void * _ObjectData, TObjectHandle Sender, int32_t * StatusCode, char * pcErrorMessage, int32_t * szErrorMessage, int8_t * DestroySession);

typedef void (SB_CALLBACK *TSBSAMLRequestPreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLRequestAbstractTypeHandle Request);

typedef void (SB_CALLBACK *TSBSAMLResponsePreparedEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLStatusResponseTypeHandle Request);

typedef void (SB_CALLBACK *TSBSAMLResponseReceivedEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLStatusResponseTypeHandle Response, int8_t * Accept);

typedef void (SB_CALLBACK *TSBSAMLRequestReceivedEvent)(void * _ObjectData, TObjectHandle Sender, TElSAMLRequestAbstractTypeHandle Request, int8_t * Accept);

typedef void (SB_CALLBACK *TSBHTTPSAMLStateChanged)(void * _ObjectData, TObjectHandle Sender, TSBSAMLClientStateRaw State);

#ifdef SB_WINDOWS
typedef void (SB_CALLBACK *TSBHTTPSAMLCredentialsChallenge)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const uint8_t pBody[], int32_t szBody, char * pcTargetURL, int32_t * szTargetURL, TStringListHandle Fields);
#else
typedef void (SB_CALLBACK *TSBHTTPSAMLCredentialsChallenge)(void * _ObjectData, TObjectHandle Sender, const char * pcURL, int32_t szURL, const uint8_t pBody[], int32_t szBody, char * pcTargetURL, int32_t * szTargetURL, TElStringListHandle Fields);
#endif

#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_Reset(TElSAMLClientSettingsHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_Enabled(TElSAMLClientSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_set_Enabled(TElSAMLClientSettingsHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_Profiles(TElSAMLClientSettingsHandle _Handle, TSBSAMLClientProfilesRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_set_Profiles(TElSAMLClientSettingsHandle _Handle, TSBSAMLClientProfilesRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_State(TElSAMLClientSettingsHandle _Handle, TSBSAMLClientStateRaw * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_set_State(TElSAMLClientSettingsHandle _Handle, TSBSAMLClientStateRaw Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_Proto(TElSAMLClientSettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_set_Proto(TElSAMLClientSettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_IdPURL(TElSAMLClientSettingsHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_set_IdPURL(TElSAMLClientSettingsHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_get_WebSSOEnabled(TElSAMLClientSettingsHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLClientSettings_Create(TElSAMLClientSettingsHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

#ifdef SB_USE_CLASS_TELSAMLSESSION
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_Generate(TElSAMLSessionHandle _Handle, int32_t TTL);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_URL(TElSAMLSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_set_URL(TElSAMLSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_Session(TElSAMLSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_set_Session(TElSAMLSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_CookieSet(TElSAMLSessionHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_set_CookieSet(TElSAMLSessionHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_RelayState(TElSAMLSessionHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_set_RelayState(TElSAMLSessionHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_Request(TElSAMLSessionHandle _Handle, TElSAMLRequestAbstractTypeHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_set_Request(TElSAMLSessionHandle _Handle, TElSAMLRequestAbstractTypeHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_get_Expires(TElSAMLSessionHandle _Handle, int64_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLSession_Create(TElSAMLSessionHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Lock(TElCustomSessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Unlock(TElCustomSessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Clear(TElCustomSessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Add(TElCustomSessionManagerHandle _Handle, TElSAMLSessionHandle Session, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Remove(TElCustomSessionManagerHandle _Handle, int32_t Index, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Remove_1(TElCustomSessionManagerHandle _Handle, const char * pcSession, int32_t szSession, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Find(TElCustomSessionManagerHandle _Handle, const char * pcSession, int32_t szSession, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_get_Count(TElCustomSessionManagerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_get_Sessions(TElCustomSessionManagerHandle _Handle, int32_t Index, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomSessionManager_Create(TElCustomSessionManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELMEMORYSESSIONMANAGER
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Lock(TElMemorySessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Unlock(TElMemorySessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Clear(TElMemorySessionManagerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Add(TElMemorySessionManagerHandle _Handle, TElSAMLSessionHandle Session, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Remove(TElMemorySessionManagerHandle _Handle, int32_t Index, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Remove_1(TElMemorySessionManagerHandle _Handle, const char * pcSession, int32_t szSession, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Find(TElMemorySessionManagerHandle _Handle, const char * pcSession, int32_t szSession, TElSAMLSessionHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemorySessionManager_Create(TElMemorySessionManagerHandle * OutResult);
#endif /* SB_USE_CLASS_TELMEMORYSESSIONMANAGER */

#ifdef SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCommon_TElStringValue_get_Value(SBXMLSAMLCommon_TElStringValueHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCommon_TElStringValue_set_Value(SBXMLSAMLCommon_TElStringValueHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCommon_TElStringValue_Create(const char * pcValue, int32_t szValue, SBXMLSAMLCommon_TElStringValueHandle * OutResult);
#endif /* SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE */

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElCustomArtifactStorage_Clear(TElCustomArtifactStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElCustomArtifactStorage_Add(TElCustomArtifactStorageHandle _Handle, const uint8_t pHandle[], int32_t szHandle, const char * pcBody, int32_t szBody, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomArtifactStorage_Get(TElCustomArtifactStorageHandle _Handle, const uint8_t pHandle[], int32_t szHandle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElCustomArtifactStorage_Create(TElCustomArtifactStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE
SB_IMPORT uint32_t SB_APIENTRY TElMemoryArtifactStorage_Clear(TElMemoryArtifactStorageHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryArtifactStorage_Add(TElMemoryArtifactStorageHandle _Handle, const uint8_t pHandle[], int32_t szHandle, const char * pcBody, int32_t szBody, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryArtifactStorage_Get(TElMemoryArtifactStorageHandle _Handle, const uint8_t pHandle[], int32_t szHandle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElMemoryArtifactStorage_Create(TElMemoryArtifactStorageHandle * OutResult);
#endif /* SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELSAMLADAPTER
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_HandleDocumentEnd(TElSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_Reset(TElSAMLAdapterHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_HandlePerformExchange(TElSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_HandleRedirection(TElSAMLAdapterHandle _Handle, TElHTTPSClientParamsHandle Param);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_HandleReadyData(TElSAMLAdapterHandle _Handle, const uint8_t pBuf[], int32_t szBuf);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_get_SAMLSettings(TElSAMLAdapterHandle _Handle, TElSAMLClientSettingsHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_get_OnSAMLStateChanged(TElSAMLAdapterHandle _Handle, TSBHTTPSAMLStateChanged * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_set_OnSAMLStateChanged(TElSAMLAdapterHandle _Handle, TSBHTTPSAMLStateChanged pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_get_OnSAMLParseForm(TElSAMLAdapterHandle _Handle, TSBSAMLPOSTBindingParseForm * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_set_OnSAMLParseForm(TElSAMLAdapterHandle _Handle, TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_get_OnSAMLCredentialsChallenge(TElSAMLAdapterHandle _Handle, TSBHTTPSAMLCredentialsChallenge * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_set_OnSAMLCredentialsChallenge(TElSAMLAdapterHandle _Handle, TSBHTTPSAMLCredentialsChallenge pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSAMLAdapter_Create(TElSAMLAdapterHandle * OutResult);
#endif /* SB_USE_CLASS_TELSAMLADAPTER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSAMLClientSettings;
class TElSAMLSession;
class TElCustomSessionManager;
class TElMemorySessionManager;
class SBXMLSAMLCommon_TElStringValue;
class TElCustomArtifactStorage;
class TElMemoryArtifactStorage;
class TElSAMLAdapter;

SB_DEFINE_ENUM_FLAG_OPERATORS(TSBSAMLClientProfiles)

#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
class TElSAMLClientSettings: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLClientSettings)
	public:
		void Reset();

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSAMLClientSettings, Enabled);

		virtual TSBSAMLClientProfiles get_Profiles();

		virtual void set_Profiles(TSBSAMLClientProfiles Value);

		SB_DECLARE_PROPERTY(TSBSAMLClientProfiles, get_Profiles, set_Profiles, TElSAMLClientSettings, Profiles);

		virtual TSBSAMLClientState get_State();

		virtual void set_State(TSBSAMLClientState Value);

		SB_DECLARE_PROPERTY(TSBSAMLClientState, get_State, set_State, TElSAMLClientSettings, State);

		virtual void get_Proto(std::string &OutResult);

		virtual void set_Proto(const std::string &Value);

		virtual void get_IdPURL(std::string &OutResult);

		virtual void set_IdPURL(const std::string &Value);

		virtual bool get_WebSSOEnabled();

		SB_DECLARE_PROPERTY_GET(bool, get_WebSSOEnabled, TElSAMLClientSettings, WebSSOEnabled);

		TElSAMLClientSettings(TElSAMLClientSettingsHandle handle, TElOwnHandle ownHandle);

		TElSAMLClientSettings();

};
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

#ifdef SB_USE_CLASS_TELSAMLSESSION
class TElSAMLSession: public TObject
{
	private:
		SB_DISABLE_COPY(TElSAMLSession)
#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
		TElSAMLRequestAbstractType* _Inst_Request;
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

		void initInstances();

	public:
		virtual void Generate(int32_t TTL);

		virtual void get_URL(std::string &OutResult);

		virtual void set_URL(const std::string &Value);

		virtual void get_Session(std::string &OutResult);

		virtual void set_Session(const std::string &Value);

		virtual bool get_CookieSet();

		virtual void set_CookieSet(bool Value);

		SB_DECLARE_PROPERTY(bool, get_CookieSet, set_CookieSet, TElSAMLSession, CookieSet);

		virtual void get_RelayState(std::string &OutResult);

		virtual void set_RelayState(const std::string &Value);

#ifdef SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE
		virtual TElSAMLRequestAbstractType* get_Request();

		virtual void set_Request(TElSAMLRequestAbstractType &Value);

		virtual void set_Request(TElSAMLRequestAbstractType *Value);

		SB_DECLARE_PROPERTY(TElSAMLRequestAbstractType*, get_Request, set_Request, TElSAMLSession, Request);
#endif /* SB_USE_CLASS_TELSAMLREQUESTABSTRACTTYPE */

		virtual int64_t get_Expires();

		SB_DECLARE_PROPERTY_GET(int64_t, get_Expires, TElSAMLSession, Expires);

		TElSAMLSession(TElSAMLSessionHandle handle, TElOwnHandle ownHandle);

		TElSAMLSession();

		virtual ~TElSAMLSession();

};
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELCUSTOMSESSIONMANAGER
class TElCustomSessionManager: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomSessionManager)
#ifdef SB_USE_CLASS_TELSAMLSESSION
		TElSAMLSession* _Inst_Sessions;
#endif /* SB_USE_CLASS_TELSAMLSESSION */

		void initInstances();

	public:
		virtual void Lock();

		virtual void Unlock();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual int32_t Add(TElSAMLSession &Session);

		virtual int32_t Add(TElSAMLSession *Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Remove(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Remove(const std::string &Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Find(const std::string &Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElCustomSessionManager, Count);

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSession* get_Sessions(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

		TElCustomSessionManager(TElCustomSessionManagerHandle handle, TElOwnHandle ownHandle);

		TElCustomSessionManager();

		virtual ~TElCustomSessionManager();

};
#endif /* SB_USE_CLASS_TELCUSTOMSESSIONMANAGER */

#ifdef SB_USE_CLASS_TELMEMORYSESSIONMANAGER
class TElMemorySessionManager: public TElCustomSessionManager
{
	private:
		SB_DISABLE_COPY(TElMemorySessionManager)
	public:
		virtual void Lock();

		virtual void Unlock();

		virtual void Clear();

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual int32_t Add(TElSAMLSession &Session);

		virtual int32_t Add(TElSAMLSession *Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Remove(int32_t Index);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Remove(const std::string &Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

#ifdef SB_USE_CLASS_TELSAMLSESSION
		virtual TElSAMLSessionHandle Find(const std::string &Session);
#endif /* SB_USE_CLASS_TELSAMLSESSION */

		TElMemorySessionManager(TElMemorySessionManagerHandle handle, TElOwnHandle ownHandle);

		TElMemorySessionManager();

};
#endif /* SB_USE_CLASS_TELMEMORYSESSIONMANAGER */

#ifdef SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE
class SBXMLSAMLCommon_TElStringValue: public TObject
{
	private:
		SB_DISABLE_COPY(SBXMLSAMLCommon_TElStringValue)
	public:
		virtual void get_Value(std::string &OutResult);

		virtual void set_Value(const std::string &Value);

		SBXMLSAMLCommon_TElStringValue(SBXMLSAMLCommon_TElStringValueHandle handle, TElOwnHandle ownHandle);

		explicit SBXMLSAMLCommon_TElStringValue(const std::string &Value);

};
#endif /* SB_USE_CLASS_SBXMLSAMLCOMMON_TELSTRINGVALUE */

#ifdef SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE
class TElCustomArtifactStorage: public TObject
{
	private:
		SB_DISABLE_COPY(TElCustomArtifactStorage)
	public:
		virtual void Clear();

		virtual bool Add(const std::vector<uint8_t> &Handle, const std::string &Body);

		virtual void Get(const std::vector<uint8_t> &Handle, std::string &OutResult);

		TElCustomArtifactStorage(TElCustomArtifactStorageHandle handle, TElOwnHandle ownHandle);

		TElCustomArtifactStorage();

};
#endif /* SB_USE_CLASS_TELCUSTOMARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE
class TElMemoryArtifactStorage: public TElCustomArtifactStorage
{
	private:
		SB_DISABLE_COPY(TElMemoryArtifactStorage)
	public:
		virtual void Clear();

		virtual bool Add(const std::vector<uint8_t> &Handle, const std::string &Body);

		virtual void Get(const std::vector<uint8_t> &Handle, std::string &OutResult);

		TElMemoryArtifactStorage(TElMemoryArtifactStorageHandle handle, TElOwnHandle ownHandle);

		TElMemoryArtifactStorage();

};
#endif /* SB_USE_CLASS_TELMEMORYARTIFACTSTORAGE */

#ifdef SB_USE_CLASS_TELSAMLADAPTER
class TElSAMLAdapter: public TElCustomSAMLAdapter
{
	private:
		SB_DISABLE_COPY(TElSAMLAdapter)
#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
		TElSAMLClientSettings* _Inst_SAMLSettings;
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

		void initInstances();

	public:
#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandleDocumentEnd(TElHTTPSClientParams &Param);

		virtual void HandleDocumentEnd(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

		virtual void Reset();

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandlePerformExchange(TElHTTPSClientParams &Param);

		virtual void HandlePerformExchange(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

#ifdef SB_USE_CLASS_TELHTTPSCLIENTPARAMS
		virtual void HandleRedirection(TElHTTPSClientParams &Param);

		virtual void HandleRedirection(TElHTTPSClientParams *Param);
#endif /* SB_USE_CLASS_TELHTTPSCLIENTPARAMS */

		virtual void HandleReadyData(const std::vector<uint8_t> &Buf);

#ifdef SB_USE_CLASS_TELSAMLCLIENTSETTINGS
		virtual TElSAMLClientSettings* get_SAMLSettings();

		SB_DECLARE_PROPERTY_GET(TElSAMLClientSettings*, get_SAMLSettings, TElSAMLAdapter, SAMLSettings);
#endif /* SB_USE_CLASS_TELSAMLCLIENTSETTINGS */

		virtual void get_OnSAMLStateChanged(TSBHTTPSAMLStateChanged &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSAMLStateChanged(TSBHTTPSAMLStateChanged pMethodValue, void * pDataValue);

		virtual void get_OnSAMLParseForm(TSBSAMLPOSTBindingParseForm &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSAMLParseForm(TSBSAMLPOSTBindingParseForm pMethodValue, void * pDataValue);

		virtual void get_OnSAMLCredentialsChallenge(TSBHTTPSAMLCredentialsChallenge &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSAMLCredentialsChallenge(TSBHTTPSAMLCredentialsChallenge pMethodValue, void * pDataValue);

		TElSAMLAdapter(TElSAMLAdapterHandle handle, TElOwnHandle ownHandle);

		TElSAMLAdapter();

		virtual ~TElSAMLAdapter();

};
#endif /* SB_USE_CLASS_TELSAMLADAPTER */

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON

#ifdef SB_USE_CLASS_TELXMLDOMDOCUMENT
void XMLDocToStr(TElXMLDOMDocument &Doc, std::string &OutResult);
void XMLDocToStr(TElXMLDOMDocument *Doc, std::string &OutResult);
#endif /* SB_USE_CLASS_TELXMLDOMDOCUMENT */

#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON
SB_IMPORT uint32_t SB_APIENTRY SBXMLSAMLCommon_XMLDocToStr(TElXMLDOMDocumentHandle Doc, char * pcOutResult, int32_t * szOutResult);
#endif /* SB_USE_GLOBAL_PROCS_XMLSAMLCOMMON */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBXMLSAMLCOMMON */
