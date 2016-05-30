#include "sbbzip2types.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_ESTATE

EState::EState(EStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

EState::EState() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(EState_Create(&_Handle));
}

#endif /* SB_USE_CLASS_ESTATE */

#ifdef SB_USE_CLASS_DSTATE

DState::DState(DStateHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

DState::DState() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(DState_Create(&_Handle));
}

#endif /* SB_USE_CLASS_DSTATE */

#ifdef SB_USE_CLASS_BZ_STREAM

bz_stream::bz_stream(bz_streamHandle handle, TElOwnHandle ownHandle) : TObject(handle, ownHandle)
{
}

bz_stream::bz_stream() : TObject(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(bz_stream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_BZ_STREAM */

};	/* namespace SecureBlackbox */

