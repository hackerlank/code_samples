#include "sbauthdatastream.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM

SB_INLINE int32_t TElAuthenticatedDataWriteStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataWriteStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticatedDataWriteStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataWriteStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticatedDataWriteStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataWriteStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElAuthenticatedDataWriteStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElAuthenticatedDataWriteStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElAuthenticatedDataWriteStream::get_CachedDigests()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticatedDataWriteStream_get_CachedDigests(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CachedDigests)
		this->_Inst_CachedDigests = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_CachedDigests->updateHandle(hOutResult);
	return this->_Inst_CachedDigests;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

SB_INLINE void TElAuthenticatedDataWriteStream::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAuthenticatedDataWriteStream_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAuthenticatedDataWriteStream::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAuthenticatedDataWriteStream_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElAuthenticatedDataWriteStream::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_CachedDigests = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElAuthenticatedDataWriteStream::TElAuthenticatedDataWriteStream(TElAuthenticatedDataWriteStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAuthenticatedDataWriteStream::TElAuthenticatedDataWriteStream(TStream &SourceStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, int64_t Count, TElCustomCryptoProviderManager &Manager) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticatedDataWriteStream_Create(SourceStream.getHandle(), Algorithm, BlockSize, DigestSize, (TSBAuthenticatedDataDigestsLocationRaw)DigestsLocation, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), StartBlockNumber, Count, Manager.getHandle(), &_Handle));
}

TElAuthenticatedDataWriteStream::TElAuthenticatedDataWriteStream(TStream *SourceStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, int64_t Count, TElCustomCryptoProviderManager *Manager) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticatedDataWriteStream_Create((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Algorithm, BlockSize, DigestSize, (TSBAuthenticatedDataDigestsLocationRaw)DigestsLocation, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), StartBlockNumber, Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElAuthenticatedDataWriteStream::~TElAuthenticatedDataWriteStream()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_CachedDigests;
	this->_Inst_CachedDigests = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAWRITESTREAM */

#ifdef SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM

SB_INLINE void TElAuthenticatedDataReadStream::FinalizeOutput()
{
	SBCheckError(TElAuthenticatedDataReadStream_FinalizeOutput(_Handle));
}

SB_INLINE int32_t TElAuthenticatedDataReadStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataReadStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticatedDataReadStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataReadStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElAuthenticatedDataReadStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElAuthenticatedDataReadStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElAuthenticatedDataReadStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElAuthenticatedDataReadStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

bool TElAuthenticatedDataReadStream::get_ExpectFinalize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElAuthenticatedDataReadStream_get_ExpectFinalize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElAuthenticatedDataReadStream::set_ExpectFinalize(bool Value)
{
	SBCheckError(TElAuthenticatedDataReadStream_set_ExpectFinalize(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
TElByteArrayList* TElAuthenticatedDataReadStream::get_CachedDigests()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElAuthenticatedDataReadStream_get_CachedDigests(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CachedDigests)
		this->_Inst_CachedDigests = new TElByteArrayList(hOutResult, ohFalse);
	else
		this->_Inst_CachedDigests->updateHandle(hOutResult);
	return this->_Inst_CachedDigests;
}
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */

SB_INLINE void TElAuthenticatedDataReadStream::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElAuthenticatedDataReadStream_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElAuthenticatedDataReadStream::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElAuthenticatedDataReadStream_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElAuthenticatedDataReadStream::initInstances()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	this->_Inst_CachedDigests = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}

TElAuthenticatedDataReadStream::TElAuthenticatedDataReadStream(TElAuthenticatedDataReadStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElAuthenticatedDataReadStream::TElAuthenticatedDataReadStream(TStream &DestStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, TElCustomCryptoProviderManager &Manager) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticatedDataReadStream_Create(DestStream.getHandle(), Algorithm, BlockSize, DigestSize, (TSBAuthenticatedDataDigestsLocationRaw)DigestsLocation, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), StartBlockNumber, Manager.getHandle(), &_Handle));
}

TElAuthenticatedDataReadStream::TElAuthenticatedDataReadStream(TStream *DestStream, int32_t Algorithm, int64_t BlockSize, int32_t DigestSize, TSBAuthenticatedDataDigestsLocation DigestsLocation, const std::vector<uint8_t> &Key, int64_t StartBlockNumber, TElCustomCryptoProviderManager *Manager) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElAuthenticatedDataReadStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Algorithm, BlockSize, DigestSize, (TSBAuthenticatedDataDigestsLocationRaw)DigestsLocation, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), StartBlockNumber, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElAuthenticatedDataReadStream::~TElAuthenticatedDataReadStream()
{
#ifdef SB_USE_CLASS_TELBYTEARRAYLIST
	delete this->_Inst_CachedDigests;
	this->_Inst_CachedDigests = NULL;
#endif /* SB_USE_CLASS_TELBYTEARRAYLIST */
}
#endif /* SB_USE_CLASS_TELAUTHENTICATEDDATAREADSTREAM */

};	/* namespace SecureBlackbox */

