#include "sbsharedresource.h"

namespace SecureBlackbox {

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSEMAPHORE

SB_INLINE void TElSemaphore::Wait()
{
	SBCheckError(TElSemaphore_Wait(_Handle));
}

SB_INLINE void TElSemaphore::Release(int32_t Count)
{
	SBCheckError(TElSemaphore_Release(_Handle, Count));
}

SB_INLINE int32_t TElSemaphore::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElSemaphore_get_Count(_Handle, &OutResult));
	return OutResult;
}

TElSemaphore::TElSemaphore(TElSemaphoreHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSemaphore::TElSemaphore() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSemaphore_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSEMAPHORE */
#endif

#ifdef SB_USE_CLASS_TELSHAREDRESOURCE

SB_INLINE void TElSharedResource::WaitToRead()
{
	SBCheckError(TElSharedResource_WaitToRead(_Handle));
}

SB_INLINE void TElSharedResource::WaitToWrite()
{
	SBCheckError(TElSharedResource_WaitToWrite(_Handle));
}

SB_INLINE void TElSharedResource::Done()
{
	SBCheckError(TElSharedResource_Done(_Handle));
}

bool TElSharedResource::get_Enabled()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElSharedResource_get_Enabled(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElSharedResource::set_Enabled(bool Value)
{
	SBCheckError(TElSharedResource_set_Enabled(_Handle, (int8_t)Value));
}

TElSharedResource::TElSharedResource(TElSharedResourceHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

TElSharedResource::TElSharedResource() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSharedResource_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELSHAREDRESOURCE */

};	/* namespace SecureBlackbox */
