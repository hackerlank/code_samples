#ifndef __INC_SBTIMER
#define __INC_SBTIMER

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbsharedresource.h"
#include "sbtypes.h"
#include "sbutils.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef TElClassHandle TTimerThreadHandle;

typedef TElClassHandle TElTimerHandle;

#ifdef SB_USE_CLASS_TTIMERTHREAD
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_Execute(TTimerThreadHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_Interval(TTimerThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_Interval(TTimerThreadHandle _Handle, int32_t Value);
#ifdef LINUX
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_TimerStep(TTimerThreadHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_TimerStep(TTimerThreadHandle _Handle, int32_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_TerminateNow(TTimerThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_TerminateNow(TTimerThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_Enabled(TTimerThreadHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_Enabled(TTimerThreadHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_OnTimer(TTimerThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_OnTimer(TTimerThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_get_OnFinish(TTimerThreadHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_set_OnFinish(TTimerThreadHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TTimerThread_Create(TTimerThreadHandle * OutResult);
#endif /* SB_USE_CLASS_TTIMERTHREAD */

#ifdef SB_USE_CLASS_TELTIMER
SB_IMPORT uint32_t SB_APIENTRY TElTimer_get_Interval(TElTimerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_set_Interval(TElTimerHandle _Handle, int32_t Value);
#ifdef LINUX
SB_IMPORT uint32_t SB_APIENTRY TElTimer_get_TimerStep(TElTimerHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_set_TimerStep(TElTimerHandle _Handle, int32_t Value);
#endif
SB_IMPORT uint32_t SB_APIENTRY TElTimer_get_Enabled(TElTimerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_set_Enabled(TElTimerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_get_RecreateThreads(TElTimerHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_set_RecreateThreads(TElTimerHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_get_OnTimer(TElTimerHandle _Handle, TNotifyEvent * pMethodOutResult, void * * pDataOutResult);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_set_OnTimer(TElTimerHandle _Handle, TNotifyEvent pMethodValue, void * pDataValue);
SB_IMPORT uint32_t SB_APIENTRY TElTimer_Create(TComponentHandle AOwner, TElTimerHandle * OutResult);
#endif /* SB_USE_CLASS_TELTIMER */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
class TTimerThread;
class TElTimer;

#ifdef SB_USE_CLASS_TTIMERTHREAD
class TTimerThread: public TThread
{
	private:
		SB_DISABLE_COPY(TTimerThread)
	public:
		virtual void Execute();

		virtual int32_t get_Interval();

		virtual void set_Interval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Interval, set_Interval, TTimerThread, Interval);

#ifdef LINUX
		virtual int32_t get_TimerStep();

		virtual void set_TimerStep(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimerStep, set_TimerStep, TTimerThread, TimerStep);
#endif

		virtual bool get_TerminateNow();

		virtual void set_TerminateNow(bool Value);

		SB_DECLARE_PROPERTY(bool, get_TerminateNow, set_TerminateNow, TTimerThread, TerminateNow);

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TTimerThread, Enabled);

		virtual void get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue);

		virtual void get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue);

		TTimerThread(TTimerThreadHandle handle, TElOwnHandle ownHandle);

		TTimerThread();

};
#endif /* SB_USE_CLASS_TTIMERTHREAD */

#ifdef SB_USE_CLASS_TELTIMER
class TElTimer: public TComponent
{
	private:
		SB_DISABLE_COPY(TElTimer)
	public:
		virtual int32_t get_Interval();

		virtual void set_Interval(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_Interval, set_Interval, TElTimer, Interval);

#ifdef LINUX
		virtual int32_t get_TimerStep();

		virtual void set_TimerStep(int32_t Value);

		SB_DECLARE_PROPERTY(int32_t, get_TimerStep, set_TimerStep, TElTimer, TimerStep);
#endif

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElTimer, Enabled);

		virtual bool get_RecreateThreads();

		virtual void set_RecreateThreads(bool Value);

		SB_DECLARE_PROPERTY(bool, get_RecreateThreads, set_RecreateThreads, TElTimer, RecreateThreads);

		virtual void get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult);

		virtual void set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue);

		TElTimer(TElTimerHandle handle, TElOwnHandle ownHandle);

		explicit TElTimer(TComponent &AOwner);

		explicit TElTimer(TComponent *AOwner);

};
#endif /* SB_USE_CLASS_TELTIMER */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBTIMER */
