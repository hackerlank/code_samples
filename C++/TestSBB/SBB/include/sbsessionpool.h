#ifndef __INC_SBSESSIONPOOL
#define __INC_SBSESSIONPOOL

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsharedresource.h"
#include "sbtimer.h"
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
typedef TElClassHandle TElSessionPoolHandle;

typedef TElSessionPoolHandle ElSessionPoolHandle;

#pragma pack(4)
typedef struct 
{
	void * SessionID;
	void * MasterKey;
	int32_t Version;
	uint32_t StartTime;
	int8_t AuthDone;
	int8_t _dummy0;
	int16_t _dummy1;
	TObjectHandle SessionInfo;
	int8_t FreeOnRelease;
} TSBSessionContext, * PSBSessionContext;

typedef void (SB_CALLBACK *TSBSessionCreatedEvent)(void * _ObjectData, TObjectHandle Sender, TObjectHandle Server, const uint8_t pSessionID[], int32_t szSessionID, TObjectHandle * SessionInfo, int8_t * FreeOnRelease);

typedef void (SB_CALLBACK *TSBSessionReleasedEvent)(void * _ObjectData, TObjectHandle Sender, const uint8_t pSessionID[], int32_t szSessionID, TObjectHandle SessionInfo);

#ifdef SB_USE_CLASS_TELSESSIONPOOL
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_Add(TElSessionPoolHandle _Handle, TObjectHandle Server, int32_t Version, const uint8_t pMasterKey[], int32_t szMasterKey, const uint8_t pSessionID[], int32_t szSessionID, int8_t AuthDone, TObjectHandle SessInfo, int8_t FreeOnRelease);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_Remove(TElSessionPoolHandle _Handle, const uint8_t pSessionID[], int32_t szSessionID);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_GetContext(TElSessionPoolHandle _Handle, const uint8_t pSessionID[], int32_t szSessionID, PSBSessionContext * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_Timeout(TElSessionPoolHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_set_Timeout(TElSessionPoolHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_Interval(TElSessionPoolHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_set_Interval(TElSessionPoolHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_MaxCount(TElSessionPoolHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_set_MaxCount(TElSessionPoolHandle _Handle, int32_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_StatelessSymmetricKey(TElSessionPoolHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_StatelessHMACKey(TElSessionPoolHandle _Handle, uint8_t pOutResult[], int32_t * szOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_OnSessionCreated(TElSessionPoolHandle _Handle, TSBSessionCreatedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_set_OnSessionCreated(TElSessionPoolHandle _Handle, TSBSessionCreatedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_get_OnSessionReleased(TElSessionPoolHandle _Handle, TSBSessionReleasedEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_set_OnSessionReleased(TElSessionPoolHandle _Handle, TSBSessionReleasedEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElSessionPool_Create(TComponentHandle Owner, TElSessionPoolHandle * OutResult);
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TElSessionPool;
typedef TElSessionPool ElSessionPool;

#ifdef SB_USE_CLASS_TELSESSIONPOOL
class TElSessionPool: public TComponent
{
	private:
		SB_DISABLE_COPY(TElSessionPool)
	public:
		void Add(TObject &Server, int32_t Version, const std::vector<uint8_t> &MasterKey, const std::vector<uint8_t> &SessionID, bool AuthDone, TObject &SessInfo, bool FreeOnRelease);

		void Add(TObject *Server, int32_t Version, const std::vector<uint8_t> &MasterKey, const std::vector<uint8_t> &SessionID, bool AuthDone, TObject *SessInfo, bool FreeOnRelease);

		void Remove(const std::vector<uint8_t> &SessionID);

		PSBSessionContext GetContext(const std::vector<uint8_t> &SessionID);

		virtual int32_t get_Timeout();

		virtual void set_Timeout(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Timeout, set_Timeout, TElSessionPool, Timeout);

		virtual int32_t get_Interval();

		virtual void set_Interval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Interval, set_Interval, TElSessionPool, Interval);

		virtual int32_t get_MaxCount();

		virtual void set_MaxCount(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_MaxCount, set_MaxCount, TElSessionPool, MaxCount);

		virtual void get_StatelessSymmetricKey(std::vector<uint8_t> &OutResult);

		virtual void get_StatelessHMACKey(std::vector<uint8_t> &OutResult);

		virtual void get_OnSessionCreated(TSBSessionCreatedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionCreated(TSBSessionCreatedEvent pMethodValue, void * pDataValue);

		virtual void get_OnSessionReleased(TSBSessionReleasedEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnSessionReleased(TSBSessionReleasedEvent pMethodValue, void * pDataValue);

		TElSessionPool(TElSessionPoolHandle handle, TElOwnHandle ownHandle);

		explicit TElSessionPool(TComponent &Owner);

		explicit TElSessionPool(TComponent *Owner);

};
#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_GLOBAL_PROCS_SESSIONPOOL

void FreeSessionContext(PSBSessionContext Ctx);

#endif /* SB_USE_GLOBAL_PROCS_SESSIONPOOL */

#endif  /* __cplusplus */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SB_USE_GLOBAL_PROCS_SESSIONPOOL
SB_IMPORT uint32_t SB_APIENTRY SBSessionPool_FreeSessionContext(PSBSessionContext Ctx);
#endif /* SB_USE_GLOBAL_PROCS_SESSIONPOOL */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSESSIONPOOL */

