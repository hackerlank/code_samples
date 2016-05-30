#ifndef __INC_SBSHAREDRESOURCE
#define __INC_SBSHAREDRESOURCE

#if _MSC_VER > 1000
#  pragma once
#endif // _MSC_VER > 1000

#include "sbdefs.h"
#include "sbcore.h"
#include "sbsystem.h"
#include "sbutils.h"
#include "sbtypes.h"
#include "sbrandom.h"
#include "sbconstants.h"

#pragma pack(push, 1)

#ifdef __cplusplus
namespace SecureBlackbox {
#endif

#ifdef __cplusplus
extern "C" {
#endif
#ifndef SB_WINDOWS
typedef TElClassHandle TElSemaphoreHandle;
#endif

typedef TElClassHandle TElSharedResourceHandle;

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSEMAPHORE
SB_IMPORT uint32_t SB_APIENTRY TElSemaphore_Wait(TElSemaphoreHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSemaphore_Release(TElSemaphoreHandle _Handle, int32_t Count);
SB_IMPORT uint32_t SB_APIENTRY TElSemaphore_get_Count(TElSemaphoreHandle _Handle, int32_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSemaphore_Create(TElSemaphoreHandle * OutResult);
#endif /* SB_USE_CLASS_TELSEMAPHORE */
#endif

#ifdef SB_USE_CLASS_TELSHAREDRESOURCE
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_WaitToRead(TElSharedResourceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_WaitToWrite(TElSharedResourceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_Done(TElSharedResourceHandle _Handle);
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_get_Enabled(TElSharedResourceHandle _Handle, int8_t * OutResult);
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_set_Enabled(TElSharedResourceHandle _Handle, int8_t Value);
SB_IMPORT uint32_t SB_APIENTRY TElSharedResource_Create(TElSharedResourceHandle * OutResult);
#endif /* SB_USE_CLASS_TELSHAREDRESOURCE */

#ifdef __cplusplus
};	/* extern "C" */
#endif

#ifdef __cplusplus

// Class forward declaration
#ifndef SB_WINDOWS
class TElSemaphore;
#endif
class TElSharedResource;

#ifndef SB_WINDOWS
#ifdef SB_USE_CLASS_TELSEMAPHORE
class TElSemaphore: public TObject
{
	private:
		SB_DISABLE_COPY(TElSemaphore)
	public:
		void Wait();

		void Release(int32_t Count);

		virtual int32_t get_Count();

		SB_DECLARE_PROPERTY_GET(int32_t, get_Count, TElSemaphore, Count);

		TElSemaphore(TElSemaphoreHandle handle, TElOwnHandle ownHandle);

		TElSemaphore();

};
#endif /* SB_USE_CLASS_TELSEMAPHORE */
#endif

#ifdef SB_USE_CLASS_TELSHAREDRESOURCE
class TElSharedResource: public TObject
{
	private:
		SB_DISABLE_COPY(TElSharedResource)
	public:
		void WaitToRead();

		void WaitToWrite();

		void Done();

		virtual bool get_Enabled();

		virtual void set_Enabled(bool Value);

		SB_DECLARE_PROPERTY(bool, get_Enabled, set_Enabled, TElSharedResource, Enabled);

		TElSharedResource(TElSharedResourceHandle handle, TElOwnHandle ownHandle);

		TElSharedResource();

};
#endif /* SB_USE_CLASS_TELSHAREDRESOURCE */

#endif  /* __cplusplus */

#ifdef __cplusplus
};	/* namespace SecureBlackbox */
#endif

#pragma pack(pop)

#endif  /* __INC_SBSHAREDRESOURCE */
