#include "sbencstream.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM

SB_INLINE int32_t TElChunkedEncryptingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElChunkedEncryptingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedEncryptingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElChunkedEncryptingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedEncryptingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElChunkedEncryptingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElChunkedEncryptingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElChunkedEncryptingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedEncryptingStream::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElChunkedEncryptingStream_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElChunkedEncryptingStream::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElChunkedEncryptingStream_set_HashAlgorithm(_Handle, Value));
}

void TElChunkedEncryptingStream::get_HashResult(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElChunkedEncryptingStream_get_HashResult(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(1577905369, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

TStream* TElChunkedEncryptingStream::get_SourceStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElChunkedEncryptingStream_get_SourceStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_SourceStream)
		this->_Inst_SourceStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_SourceStream->updateHandle(hOutResult);
	return this->_Inst_SourceStream;
}

bool TElChunkedEncryptingStream::get_Finalized()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElChunkedEncryptingStream_get_Finalized(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElChunkedEncryptingStream::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElChunkedEncryptingStream_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElChunkedEncryptingStream::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElChunkedEncryptingStream_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElChunkedEncryptingStream::get_OnHashResultAvailable(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElChunkedEncryptingStream_get_OnHashResultAvailable(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElChunkedEncryptingStream::set_OnHashResultAvailable(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElChunkedEncryptingStream_set_OnHashResultAvailable(_Handle, pMethodValue, pDataValue));
}

void TElChunkedEncryptingStream::initInstances()
{
	this->_Inst_SourceStream = NULL;
}

TElChunkedEncryptingStream::TElChunkedEncryptingStream(TElChunkedEncryptingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create(SourceStream.getHandle(), Algorithm, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, Manager.getHandle(), (int8_t)ReleaseSourceStream, &_Handle));
}

TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Algorithm, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseSourceStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create_1(SourceStream.getHandle(), Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, Manager.getHandle(), (int8_t)ReleaseSourceStream, &_Handle));
}

TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create_1((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseSourceStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream &SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create_2(SourceStream.getHandle(), Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Offset, Count, Manager.getHandle(), (int8_t)ReleaseSourceStream, &_Handle));
}

TElChunkedEncryptingStream::TElChunkedEncryptingStream(TStream *SourceStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseSourceStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedEncryptingStream_Create_2((SourceStream != NULL) ? SourceStream->getHandle() : SB_NULL_HANDLE, Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Offset, Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseSourceStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElChunkedEncryptingStream::~TElChunkedEncryptingStream()
{
	delete this->_Inst_SourceStream;
	this->_Inst_SourceStream = NULL;
}
#endif /* SB_USE_CLASS_TELCHUNKEDENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM

SB_INLINE void TElChunkedDecryptingStream::FinalizeOutput()
{
	SBCheckError(TElChunkedDecryptingStream_FinalizeOutput(_Handle));
}

SB_INLINE int32_t TElChunkedDecryptingStream::Read(void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElChunkedDecryptingStream_Read(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedDecryptingStream::Write(const void * Buffer, int32_t Count)
{
	int32_t OutResult;
	SBCheckError(TElChunkedDecryptingStream_Write(_Handle, Buffer, Count, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedDecryptingStream::Seek(int32_t Offset, uint16_t Origin)
{
	int32_t OutResult;
	SBCheckError(TElChunkedDecryptingStream_Seek(_Handle, Offset, Origin, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElChunkedDecryptingStream::Seek(int64_t Offset, TSeekOrigin Origin)
{
	int64_t OutResult;
	SBCheckError(TElChunkedDecryptingStream_Seek_1(_Handle, Offset, (TSeekOriginRaw)Origin, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElChunkedDecryptingStream::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElChunkedDecryptingStream_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElChunkedDecryptingStream::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElChunkedDecryptingStream_set_HashAlgorithm(_Handle, Value));
}

void TElChunkedDecryptingStream::get_HashResult(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElChunkedDecryptingStream_get_HashResult(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(742145809, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElChunkedDecryptingStream::get_ExpectFinalize()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElChunkedDecryptingStream_get_ExpectFinalize(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElChunkedDecryptingStream::set_ExpectFinalize(bool Value)
{
	SBCheckError(TElChunkedDecryptingStream_set_ExpectFinalize(_Handle, (int8_t)Value));
}

TStream* TElChunkedDecryptingStream::get_DestStream()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElChunkedDecryptingStream_get_DestStream(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_DestStream)
		this->_Inst_DestStream = new TStream(hOutResult, ohFalse);
	else
		this->_Inst_DestStream->updateHandle(hOutResult);
	return this->_Inst_DestStream;
}

SB_INLINE void TElChunkedDecryptingStream::get_OnProgress(TSBProgressEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElChunkedDecryptingStream_get_OnProgress(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElChunkedDecryptingStream::set_OnProgress(TSBProgressEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElChunkedDecryptingStream_set_OnProgress(_Handle, pMethodValue, pDataValue));
}

void TElChunkedDecryptingStream::initInstances()
{
	this->_Inst_DestStream = NULL;
}

TElChunkedDecryptingStream::TElChunkedDecryptingStream(TElChunkedDecryptingStreamHandle handle, TElOwnHandle ownHandle) : TStream(handle, ownHandle)
{
	initInstances();
}

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create(DestStream.getHandle(), Algorithm, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, Manager.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Algorithm, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create_1(DestStream.getHandle(), Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, Manager.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create_1((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

#ifdef SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER
TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream &DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager &Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create_2(DestStream.getHandle(), Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Offset, Count, Manager.getHandle(), (int8_t)ReleaseDestStream, &_Handle));
}

TElChunkedDecryptingStream::TElChunkedDecryptingStream(TStream *DestStream, int32_t Algorithm, TSBSymmetricCryptoMode Mode, const std::vector<uint8_t> &Key, const std::vector<uint8_t> &IV, int64_t Offset, int64_t Count, TElCustomCryptoProviderManager *Manager, bool ReleaseDestStream) : TStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElChunkedDecryptingStream_Create_2((DestStream != NULL) ? DestStream->getHandle() : SB_NULL_HANDLE, Algorithm, (TSBSymmetricCryptoModeRaw)Mode, SB_STD_VECTOR_FRONT_ADR(Key), (int32_t)Key.size(), SB_STD_VECTOR_FRONT_ADR(IV), (int32_t)IV.size(), Offset, Count, (Manager != NULL) ? Manager->getHandle() : SB_NULL_HANDLE, (int8_t)ReleaseDestStream, &_Handle));
}
#endif /* SB_USE_CLASS_TELCUSTOMCRYPTOPROVIDERMANAGER */

TElChunkedDecryptingStream::~TElChunkedDecryptingStream()
{
	delete this->_Inst_DestStream;
	this->_Inst_DestStream = NULL;
}
#endif /* SB_USE_CLASS_TELCHUNKEDDECRYPTINGSTREAM */

};	/* namespace SecureBlackbox */

