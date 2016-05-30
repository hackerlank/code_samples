#include "sbsessionpool.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSESSIONPOOL

SB_INLINE void TElSessionPool::Add(TObject &Server, int32_t Version, const std::vector<uint8_t> &MasterKey, const std::vector<uint8_t> &SessionID, bool AuthDone, TObject &SessInfo, bool FreeOnRelease)
{
	SBCheckError(TElSessionPool_Add(_Handle, Server.getHandle(), Version, SB_STD_VECTOR_FRONT_ADR(MasterKey), (int32_t)MasterKey.size(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)AuthDone, SessInfo.getHandle(), (int8_t)FreeOnRelease));
}

SB_INLINE void TElSessionPool::Add(TObject *Server, int32_t Version, const std::vector<uint8_t> &MasterKey, const std::vector<uint8_t> &SessionID, bool AuthDone, TObject *SessInfo, bool FreeOnRelease)
{
	SBCheckError(TElSessionPool_Add(_Handle, (Server != NULL) ? Server->getHandle() : SB_NULL_HANDLE, Version, SB_STD_VECTOR_FRONT_ADR(MasterKey), (int32_t)MasterKey.size(), SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), (int8_t)AuthDone, (SessInfo != NULL) ? SessInfo->getHandle() : SB_NULL_HANDLE, (int8_t)FreeOnRelease));
}

SB_INLINE void TElSessionPool::Remove(const std::vector<uint8_t> &SessionID)
{
	SBCheckError(TElSessionPool_Remove(_Handle, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size()));
}

SB_INLINE PSBSessionContext TElSessionPool::GetContext(const std::vector<uint8_t> &SessionID)
{
	PSBSessionContext OutResult;
	SBCheckError(TElSessionPool_GetContext(_Handle, SB_STD_VECTOR_FRONT_ADR(SessionID), (int32_t)SessionID.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElSessionPool::get_Timeout()
{
	int32_t OutResult;
	SBCheckError(TElSessionPool_get_Timeout(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSessionPool::set_Timeout(int32_t Value)
{
	SBCheckError(TElSessionPool_set_Timeout(_Handle, Value));
}

SB_INLINE int32_t TElSessionPool::get_Interval()
{
	int32_t OutResult;
	SBCheckError(TElSessionPool_get_Interval(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSessionPool::set_Interval(int32_t Value)
{
	SBCheckError(TElSessionPool_set_Interval(_Handle, Value));
}

SB_INLINE int32_t TElSessionPool::get_MaxCount()
{
	int32_t OutResult;
	SBCheckError(TElSessionPool_get_MaxCount(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElSessionPool::set_MaxCount(int32_t Value)
{
	SBCheckError(TElSessionPool_set_MaxCount(_Handle, Value));
}

void TElSessionPool::get_StatelessSymmetricKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSessionPool_get_StatelessSymmetricKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-967800637, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElSessionPool::get_StatelessHMACKey(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElSessionPool_get_StatelessHMACKey(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1020709448, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElSessionPool::get_OnSessionCreated(TSBSessionCreatedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSessionPool_get_OnSessionCreated(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSessionPool::set_OnSessionCreated(TSBSessionCreatedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSessionPool_set_OnSessionCreated(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElSessionPool::get_OnSessionReleased(TSBSessionReleasedEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElSessionPool_get_OnSessionReleased(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElSessionPool::set_OnSessionReleased(TSBSessionReleasedEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElSessionPool_set_OnSessionReleased(_Handle, pMethodValue, pDataValue));
}

TElSessionPool::TElSessionPool(TElSessionPoolHandle handle, TElOwnHandle ownHandle) : TComponent(handle, ownHandle)
{
}

TElSessionPool::TElSessionPool(TComponent &Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSessionPool_Create(Owner.getHandle(), &_Handle));
}

TElSessionPool::TElSessionPool(TComponent *Owner) : TComponent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElSessionPool_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELSESSIONPOOL */

#ifdef SB_USE_GLOBAL_PROCS_SESSIONPOOL

SB_INLINE void FreeSessionContext(PSBSessionContext Ctx)
{
	SBCheckError(SBSessionPool_FreeSessionContext(Ctx));
}

#endif /* SB_USE_GLOBAL_PROCS_SESSIONPOOL */

};	/* namespace SecureBlackbox */

