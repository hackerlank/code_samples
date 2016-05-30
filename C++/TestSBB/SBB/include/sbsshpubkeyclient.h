#ifndef __INC_SBSSHPUBKEYCLIENT
#define __INC_SBSSHPUBKEYCLIENT

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsshclient.h"
#include "sbsshcommon.h"
#include "sbsshconstants.h"
#include "sbsshkeystorage.h"
#include "sbsshpubkeycommon.h"
#include "sbtypes.h"
#include "sbutils.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TElSSHPublicKeyClientHandle;

typedef TElSSHPublicKeyClientHandle ElSSHPublicKeyClientHandle;

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYCLIENT
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_Add(TElSSHPublicKeyClientHandle _Handle, TElSSHKeyHandle Key, TElSSHPublicKeyAttributesHandle Attributes, int8_t Overwrite);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_Remove(TElSSHPublicKeyClientHandle _Handle, TElSSHKeyHandle Key);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_List(TElSSHPublicKeyClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_ListAttributes(TElSSHPublicKeyClientHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_Active(TElSSHPublicKeyClientHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_RemoteVersion(TElSSHPublicKeyClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_Version(TElSSHPublicKeyClientHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_Tunnel(TElSSHPublicKeyClientHandle _Handle, TElSubsystemSSHTunnelHandle * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_Tunnel(TElSSHPublicKeyClientHandle _Handle, TElSubsystemSSHTunnelHandle Value);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_Subsystem(TElSSHPublicKeyClientHandle _Handle, char * pcOutResult, int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_Subsystem(TElSSHPublicKeyClientHandle _Handle, const char * pcValue, int32_t szValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnOpenConnection(TElSSHPublicKeyClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnOpenConnection(TElSSHPublicKeyClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnCloseConnection(TElSSHPublicKeyClientHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnCloseConnection(TElSSHPublicKeyClientHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnError(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyErrorEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnError(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnStatus(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyStatusEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnStatus(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnPublicKey(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyPublicKeyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnPublicKey(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyPublicKeyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_get_OnAttribute(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyAttributeEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_set_OnAttribute(TElSSHPublicKeyClientHandle _Handle, TSBSSHPublicKeyAttributeEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSSHPublicKeyClient_Create(TComponentHandle AOwner, TElSSHPublicKeyClientHandle * OutResult);
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYCLIENT */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSSHPublicKeyClient;
typedef TElSSHPublicKeyClient ElSSHPublicKeyClient;

#ifdef SB_USE_CLASS_TELSSHPUBLICKEYCLIENT
class TElSSHPublicKeyClient: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSSHPublicKeyClient)
#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
		TElSubsystemSSHTunnel* _Inst_Tunnel;
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

		void initInstances();

	public:
#ifdef SB_USE_CLASSES_TELSSHKEY_AND_TELSSHPUBLICKEYATTRIBUTES
		void Add(TElSSHKey &Key, TElSSHPublicKeyAttributes &Attributes, bool Overwrite);

		void Add(TElSSHKey *Key, TElSSHPublicKeyAttributes *Attributes, bool Overwrite);
#endif /* SB_USE_CLASSES_TELSSHKEY_AND_TELSSHPUBLICKEYATTRIBUTES */

#ifdef SB_USE_CLASS_TELSSHKEY
		void Remove(TElSSHKey &Key);

		void Remove(TElSSHKey *Key);
#endif /* SB_USE_CLASS_TELSSHKEY */

		void List();

		void ListAttributes();

		virtual bool get_Active();

		SB_DECLARE_PROPERTY_GET(bool, get_Active, TElSSHPublicKeyClient, Active);

		virtual int32_t get_RemoteVersion();

		SB_DECLARE_PROPERTY_GET(int32_t, get_RemoteVersion, TElSSHPublicKeyClient, RemoteVersion);

		virtual int32_t get_Version();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Version, TElSSHPublicKeyClient, Version);

#ifdef SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL
		virtual TElSubsystemSSHTunnel* get_Tunnel();

		virtual void set_Tunnel(TElSubsystemSSHTunnel &Value);

		virtual void set_Tunnel(TElSubsystemSSHTunnel *Value);

		SB_DECLARE_PROPERTY(TElSubsystemSSHTunnel*, get_Tunnel, set_Tunnel, TElSSHPublicKeyClient, Tunnel);
#endif /* SB_USE_CLASS_TELSUBSYSTEMSSHTUNNEL */

		virtual void get_Subsystem(std::string &OutResult);

		virtual void set_Subsystem(const std::string &Value);

		virtual void get_OnOpenConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnOpenConnection(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnCloseConnection(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnCloseConnection(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnError(TSBSSHPublicKeyErrorEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnError(TSBSSHPublicKeyErrorEvent pMethodValue, void * pDataValue);

		virtual void get_OnStatus(TSBSSHPublicKeyStatusEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnStatus(TSBSSHPublicKeyStatusEvent pMethodValue, void * pDataValue);

		virtual void get_OnPublicKey(TSBSSHPublicKeyPublicKeyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnPublicKey(TSBSSHPublicKeyPublicKeyEvent pMethodValue, void * pDataValue);

		virtual void get_OnAttribute(TSBSSHPublicKeyAttributeEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnAttribute(TSBSSHPublicKeyAttributeEvent pMethodValue, void * pDataValue);

		TElSSHPublicKeyClient(TElSSHPublicKeyClientHandle handle, TElOwnHandle ownHandle);

		explicit TElSSHPublicKeyClient(TComponent &AOwner);

		explicit TElSSHPublicKeyClient(TComponent *AOwner);

		virtual ~TElSSHPublicKeyClient();

};
#endif /* SB_USE_CLASS_TELSSHPUBLICKEYCLIENT */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSSHPUBKEYCLIENT */

