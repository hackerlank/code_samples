#ifndef __INC_SBSSHPUBKEYSERVER
#define __INC_SBSSHPUBKEYSERVER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"
#include "sbsshcommon.h"
#include "sbsshconstants.h"
#include "sbsshutils.h"
#include "sbsshhandlers.h"
#include "sbsshkeystorage.h"
#include "sbsshpubkeycommon.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSSHPublicKeyServerHandle;

typedef TElSSHPublicKeyServerHandle ElSSHPublicKeyServerHandle;

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_Close(TElSSHPublicKeyServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_DataAvailable(TElSSHPublicKeyServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_Open(TElSSHPublicKeyServerHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_Active(TElSSHPublicKeyServerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_RemoteVersion(TElSSHPublicKeyServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_Version(TElSSHPublicKeyServerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnReceive(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyReceiveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnReceive(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnSend(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeySendEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnSend(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnClose(TElSSHPublicKeyServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnClose(TElSSHPublicKeyServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnError(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnError(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnOpen(TElSSHPublicKeyServerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnOpen(TElSSHPublicKeyServerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnStatus(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnStatus(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnAdd(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyAddEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnAdd(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnRemove(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyRemoveEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnRemove(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnList(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyListEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnList(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnListAttributes(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyListAttributesEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnListAttributes(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_get_OnAttributeSupported(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyAttrubuteSupportedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_set_OnAttributeSupported(TElSSHPublicKeyServerHandle _Handle, TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyServer_Create(TComponentHandle AOwner, TElSSHPublicKeyServerHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHPublicKeyServer;
typedef TElSSHPublicKeyServer ElSSHPublicKeyServer;

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYSERVER
class TElSSHPublicKeyServer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHPublicKeyServer)
	public:
		void Close();

		void DataAvailable();

		void Open();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSHPublicKeyServer, Active);

		virtual int32_t get_RemoteVersion();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RemoteVersion, TElSSHPublicKeyServer, RemoteVersion);

		virtual int32_t get_Version();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Version, TElSSHPublicKeyServer, Version);

		virtual void get_OnReceive(TSBSSHPublicKeyReceiveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnReceive(TSBSSHPublicKeyReceiveEvent pMethodValue, void * pDataValue);

		virtual void get_OnSend(TSBSSHPublicKeySendEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSend(TSBSSHPublicKeySendEvent pMethodValue, void * pDataValue);

		virtual void get_OnClose(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnClose(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnOpen(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpen(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnAdd(TSBSSHPublicKeyAddEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAdd(TSBSSHPublicKeyAddEvent pMethodValue, void * pDataValue);

		virtual void get_OnRemove(TSBSSHPublicKeyRemoveEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnRemove(TSBSSHPublicKeyRemoveEvent pMethodValue, void * pDataValue);

		virtual void get_OnList(TSBSSHPublicKeyListEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnList(TSBSSHPublicKeyListEvent pMethodValue, void * pDataValue);

		virtual void get_OnListAttributes(TSBSSHPublicKeyListAttributesEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnListAttributes(TSBSSHPublicKeyListAttributesEvent pMethodValue, void * pDataValue);

		virtual void get_OnAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAttributeSupported(TSBSSHPublicKeyAttrubuteSupportedEvent pMethodValue, void * pDataValue);

		TElSSHPublicKeyServer(TElSSHPublicKeyServerHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHPublicKeyServer(TComponent &AOwner);

		explicit TElSSHPublicKeyServer(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYSERVER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHPUBKEYSERVER */

