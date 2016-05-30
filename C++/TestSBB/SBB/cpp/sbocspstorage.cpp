#include "sbocspstorage.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELOCSPRESPONSESTORAGE

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElOCSPResponseStorage::Add(TElOCSPResponse &Resp)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_Add(_Handle, Resp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOCSPResponseStorage::Add(TElOCSPResponse *Resp)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_Add(_Handle, (Resp != NULL) ? Resp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE int32_t TElOCSPResponseStorage::Add()
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_Add_1(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElOCSPResponseStorage::Remove(int32_t Index)
{
	SBCheckError(TElOCSPResponseStorage_Remove(_Handle, Index));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
SB_INLINE int32_t TElOCSPResponseStorage::IndexOf(TElOCSPResponse &Resp)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_IndexOf(_Handle, Resp.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElOCSPResponseStorage::IndexOf(TElOCSPResponse *Resp)
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_IndexOf(_Handle, (Resp != NULL) ? Resp->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE void TElOCSPResponseStorage::Clear()
{
	SBCheckError(TElOCSPResponseStorage_Clear(_Handle));
}

SB_INLINE void TElOCSPResponseStorage::ExportTo(TElOCSPResponseStorage &Storage)
{
	SBCheckError(TElOCSPResponseStorage_ExportTo(_Handle, Storage.getHandle()));
}

SB_INLINE void TElOCSPResponseStorage::ExportTo(TElOCSPResponseStorage *Storage)
{
	SBCheckError(TElOCSPResponseStorage_ExportTo(_Handle, (Storage != NULL) ? Storage->getHandle() : SB_NULL_HANDLE));
}

#ifdef SB_USE_CLASS_TELOCSPRESPONSE
TElOCSPResponse* TElOCSPResponseStorage::get_Responses(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElOCSPResponseStorage_get_Responses(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Responses)
		this->_Inst_Responses = new TElOCSPResponse(hOutResult, ohFalse);
	else
		this->_Inst_Responses->updateHandle(hOutResult);
	return this->_Inst_Responses;
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */

SB_INLINE int32_t TElOCSPResponseStorage::get_Count()
{
	int32_t OutResult;
	SBCheckError(TElOCSPResponseStorage_get_Count(_Handle, &OutResult));
	return OutResult;
}

void TElOCSPResponseStorage::initInstances()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}

TElOCSPResponseStorage::TElOCSPResponseStorage(TElOCSPResponseStorageHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElOCSPResponseStorage::TElOCSPResponseStorage() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElOCSPResponseStorage_Create(&_Handle));
}

TElOCSPResponseStorage::~TElOCSPResponseStorage()
{
#ifdef SB_USE_CLASS_TELOCSPRESPONSE
	delete this->_Inst_Responses;
	this->_Inst_Responses = NULL;
#endif /* SB_USE_CLASS_TELOCSPRESPONSE */
}
#endif /* SB_USE_CLASS_TELOCSPRESPONSESTORAGE */

};	/* namespace SecureBlackbox */

