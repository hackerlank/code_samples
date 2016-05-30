#include "sbtimer.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TTIMERTHREAD

SB_INLINE void TTimerThread::Execute()
{
	SBCheckError(TTimerThread_Execute(_Handle));
}

SB_INLINE int32_t TTimerThread::get_Interval()
{
	int32_t OutResult;
	SBCheckError(TTimerThread_get_Interval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TTimerThread::set_Interval(int32_t Value)
{
	SBCheckError(TTimerThread_set_Interval(_Handle, Value));
}

#ifdef LINUX
SB_INLINE int32_t TTimerThread::get_TimerStep()
{
	int32_t OutResult;
	SBCheckError(TTimerThread_get_TimerStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TTimerThread::set_TimerStep(int32_t Value)
{
	SBCheckError(TTimerThread_set_TimerStep(_Handle, Value));
}
#endif

bool TTimerThread::get_TerminateNow()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TTimerThread_get_TerminateNow(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TTimerThread::set_TerminateNow(bool Value)
{
	SBCheckError(TTimerThread_set_TerminateNow(_Handle, (int8_t)Value));
}

bool TTimerThread::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TTimerThread_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TTimerThread::set_Enabled(bool Value)
{
	SBCheckError(TTimerThread_set_Enabled(_Handle, (int8_t)Value));
}

SB_INLINE void TTimerThread::get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TTimerThread_get_OnTimer(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TTimerThread::set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TTimerThread_set_OnTimer(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TTimerThread::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TTimerThread_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TTimerThread::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TTimerThread_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

TTimerThread::TTimerThread(TTimerThreadHandle handle, TElOwnHandle ownHandle) : TThread(handle, ownHandle)
{
}

TTimerThread::TTimerThread() : TThread(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TTimerThread_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TTIMERTHREAD */

#ifdef SB_USE_CLASS_TELTIMER

SB_INLINE int32_t TElTimer::get_Interval()
{
	int32_t OutResult;
	SBCheckError(TElTimer_get_Interval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTimer::set_Interval(int32_t Value)
{
	SBCheckError(TElTimer_set_Interval(_Handle, Value));
#ifdef LINUX
}

SB_INLINE int32_t TElTimer::get_TimerStep()
{
	int32_t OutResult;
	SBCheckError(TElTimer_get_TimerStep(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElTimer::set_TimerStep(int32_t Value)
{
	SBCheckError(TElTimer_set_TimerStep(_Handle, Value));
#endif
}

bool TElTimer::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTimer_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTimer::set_Enabled(bool Value)
{
	SBCheckError(TElTimer_set_Enabled(_Handle, (int8_t)Value));
}

bool TElTimer::get_RecreateThreads()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElTimer_get_RecreateThreads(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElTimer::set_RecreateThreads(bool Value)
{
	SBCheckError(TElTimer_set_RecreateThreads(_Handle, (int8_t)Value));
}

SB_INLINE void TElTimer::get_OnTimer(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElTimer_get_OnTimer(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElTimer::set_OnTimer(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElTimer_set_OnTimer(_Handle, pMethodValue, pDataValue));
}

TElTimer::TElTimer(TElTimerHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElTimer::TElTimer(TComponent &AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTimer_Create(AOwner.getHandle(), &_Handle));
}

TElTimer::TElTimer(TComponent *AOwner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElTimer_Create((AOwner != NULL) ? AOwner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELTIMER */

};	/* namespace SecureBlackbox */
