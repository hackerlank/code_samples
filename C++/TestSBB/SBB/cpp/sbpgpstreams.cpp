#include "sbpgpstreams.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELPGPSTREAM

SB_INLINE void TElPGPStream::DataAvailable()
{
	SBCheckError(TElPGPStream_DataAvailable(_Handle));
}

SB_INLINE void TElPGPStream::Process(void * AReadUserData, void * AWriteUserData)
{
	SBCheckError(TElPGPStream_Process(_Handle, AReadUserData, AWriteUserData));
}

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE void TElPGPStream::ProcessStream(TStream &AInputStream, TStream &AOutputStream, int32_t Count)
{
	SBCheckError(TElPGPStream_ProcessStream(_Handle, AInputStream.getHandle(), AOutputStream.getHandle(), Count));
}

SB_INLINE void TElPGPStream::ProcessStream(TStream *AInputStream, TStream *AOutputStream, int32_t Count)
{
	SBCheckError(TElPGPStream_ProcessStream(_Handle, (AInputStream != NULL) ? AInputStream->getHandle() : SB_NULL_HANDLE, (AOutputStream != NULL) ? AOutputStream->getHandle() : SB_NULL_HANDLE, Count));
}
#endif /* SB_USE_CLASS_TSTREAM */

SB_INLINE TClassHandle TElPGPStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPStream_ClassType(&OutResult));
	return OutResult;
}

TElPGPStream* TElPGPStream::get_PassTo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPStream_get_PassTo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_PassTo)
		this->_Inst_PassTo = new TElPGPStream(hOutResult, ohFalse);
	else
		this->_Inst_PassTo->updateHandle(hOutResult);
	return this->_Inst_PassTo;
}

SB_INLINE void TElPGPStream::set_PassTo(TElPGPStream &Value)
{
	SBCheckError(TElPGPStream_set_PassTo(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPStream::set_PassTo(TElPGPStream *Value)
{
	SBCheckError(TElPGPStream_set_PassTo(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}

bool TElPGPStream::get_UseOldPackets()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPStream_get_UseOldPackets(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPStream::set_UseOldPackets(bool Value)
{
	SBCheckError(TElPGPStream_set_UseOldPackets(_Handle, (int8_t)Value));
}

SB_INLINE int64_t TElPGPStream::get_ProcessedLength()
{
	int64_t OutResult;
	SBCheckError(TElPGPStream_get_ProcessedLength(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPStream::get_IgnoreDataPacketLengthTag()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPStream_get_IgnoreDataPacketLengthTag(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPStream::set_IgnoreDataPacketLengthTag(bool Value)
{
	SBCheckError(TElPGPStream_set_IgnoreDataPacketLengthTag(_Handle, (int8_t)Value));
}

SB_INLINE void TElPGPStream::get_OnRead(TSBPGPReadEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStream_get_OnRead(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStream::set_OnRead(TSBPGPReadEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStream_set_OnRead(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStream::get_OnWrite(TSBPGPWriteEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStream_get_OnWrite(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStream::set_OnWrite(TSBPGPWriteEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStream_set_OnWrite(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStream::get_OnFinish(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStream_get_OnFinish(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStream::set_OnFinish(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStream_set_OnFinish(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPStream::get_OnTemporaryStream(TSBPGPTemporaryStreamEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPStream_get_OnTemporaryStream(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPStream::set_OnTemporaryStream(TSBPGPTemporaryStreamEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPStream_set_OnTemporaryStream(_Handle, pMethodValue, pDataValue));
}

void TElPGPStream::initInstances()
{
	this->_Inst_PassTo = NULL;
}

TElPGPStream::TElPGPStream(TElPGPStreamHandle handle, TElOwnHandle ownHandle) : TPersistent(handle, ownHandle)
{
	initInstances();
}

TElPGPStream::TElPGPStream() : TPersistent(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPStream_Create(&_Handle));
}

TElPGPStream::~TElPGPStream()
{
	delete this->_Inst_PassTo;
	this->_Inst_PassTo = NULL;
}
#endif /* SB_USE_CLASS_TELPGPSTREAM */

#ifdef SB_USE_CLASS_TELPGPARMORINGSTREAM

SB_INLINE void TElPGPArmoringStream::DataAvailable()
{
	SBCheckError(TElPGPArmoringStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPArmoringStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPArmoringStream_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPArmoringStream::get_LineLength()
{
	int32_t OutResult;
	SBCheckError(TElPGPArmoringStream_get_LineLength(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPArmoringStream::set_LineLength(int32_t Value)
{
	SBCheckError(TElPGPArmoringStream_set_LineLength(_Handle, Value));
}

void TElPGPArmoringStream::get_Boundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPArmoringStream_get_Boundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(822015759, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPArmoringStream::set_Boundary(const std::string &Value)
{
	SBCheckError(TElPGPArmoringStream_set_Boundary(_Handle, Value.data(), (int32_t)Value.length()));
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPArmoringStream::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPArmoringStream_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

void TElPGPArmoringStream::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElPGPArmoringStream::TElPGPArmoringStream(TElPGPArmoringStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPArmoringStream::TElPGPArmoringStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPArmoringStream_Create(&_Handle));
}

TElPGPArmoringStream::~TElPGPArmoringStream()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELPGPARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDEARMORINGSTREAM

SB_INLINE void TElPGPDearmoringStream::DataAvailable()
{
	SBCheckError(TElPGPDearmoringStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPDearmoringStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPDearmoringStream_ClassType(&OutResult));
	return OutResult;
}

void TElPGPDearmoringStream::get_Boundary(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPDearmoringStream_get_Boundary(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1047222395, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPDearmoringStream::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPDearmoringStream_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElPGPDearmoringStream::get_MultiPart()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPDearmoringStream_get_MultiPart(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPDearmoringStream::set_MultiPart(bool Value)
{
	SBCheckError(TElPGPDearmoringStream_set_MultiPart(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPGPDearmoringStream::get_InputEncoding()
{
	int32_t OutResult;
	SBCheckError(TElPGPDearmoringStream_get_InputEncoding(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPDearmoringStream::set_InputEncoding(int32_t Value)
{
	SBCheckError(TElPGPDearmoringStream_set_InputEncoding(_Handle, Value));
}

SB_INLINE void TElPGPDearmoringStream::get_OnInfo(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDearmoringStream_get_OnInfo(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDearmoringStream::set_OnInfo(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDearmoringStream_set_OnInfo(_Handle, pMethodValue, pDataValue));
}

void TElPGPDearmoringStream::initInstances()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElPGPDearmoringStream::TElPGPDearmoringStream(TElPGPDearmoringStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPDearmoringStream::TElPGPDearmoringStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPDearmoringStream_Create(&_Handle));
}

TElPGPDearmoringStream::~TElPGPDearmoringStream()
{
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELPGPDEARMORINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENVELOPINGSTREAM

SB_INLINE void TElPGPEnvelopingStream::DataAvailable()
{
	SBCheckError(TElPGPEnvelopingStream_DataAvailable(_Handle));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
SB_INLINE int32_t TElPGPEnvelopingStream::AddSignature(TElPGPSignature &Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPEnvelopingStream_AddSignature(_Handle, Signature.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPEnvelopingStream::AddSignature(TElPGPSignature *Signature)
{
	int32_t OutResult;
	SBCheckError(TElPGPEnvelopingStream_AddSignature(_Handle, (Signature != NULL) ? Signature->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE void TElPGPEnvelopingStream::RemoveSignature(int32_t Index)
{
	SBCheckError(TElPGPEnvelopingStream_RemoveSignature(_Handle, Index));
}

SB_INLINE void TElPGPEnvelopingStream::ClearSignatures()
{
	SBCheckError(TElPGPEnvelopingStream_ClearSignatures(_Handle));
}

SB_INLINE TClassHandle TElPGPEnvelopingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPEnvelopingStream_ClassType(&OutResult));
	return OutResult;
}

void TElPGPEnvelopingStream::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPEnvelopingStream_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(-431682611, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElPGPEnvelopingStream::set_Filename(const std::string &Value)
{
	SBCheckError(TElPGPEnvelopingStream_set_Filename(_Handle, Value.data(), (int32_t)Value.length()));
}

SB_INLINE int64_t TElPGPEnvelopingStream::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPEnvelopingStream_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPEnvelopingStream::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPEnvelopingStream_set_Timestamp(_Handle, Value));
}

bool TElPGPEnvelopingStream::get_TextMode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEnvelopingStream_get_TextMode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEnvelopingStream::set_TextMode(bool Value)
{
	SBCheckError(TElPGPEnvelopingStream_set_TextMode(_Handle, (int8_t)Value));
}

#ifdef SB_USE_CLASS_TELPGPSIGNATURE
TElPGPSignature* TElPGPEnvelopingStream::get_Signatures(int32_t Index)
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPEnvelopingStream_get_Signatures(_Handle, Index, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Signatures)
		this->_Inst_Signatures = new TElPGPSignature(hOutResult, ohFalse);
	else
		this->_Inst_Signatures->updateHandle(hOutResult);
	return this->_Inst_Signatures;
}
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */

SB_INLINE int32_t TElPGPEnvelopingStream::get_SignatureCount()
{
	int32_t OutResult;
	SBCheckError(TElPGPEnvelopingStream_get_SignatureCount(_Handle, &OutResult));
	return OutResult;
}

bool TElPGPEnvelopingStream::get_UseOnePassSignatures()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEnvelopingStream_get_UseOnePassSignatures(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEnvelopingStream::set_UseOnePassSignatures(bool Value)
{
	SBCheckError(TElPGPEnvelopingStream_set_UseOnePassSignatures(_Handle, (int8_t)Value));
}

void TElPGPEnvelopingStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}

TElPGPEnvelopingStream::TElPGPEnvelopingStream(TElPGPEnvelopingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPEnvelopingStream::TElPGPEnvelopingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPEnvelopingStream_Create(&_Handle));
}

TElPGPEnvelopingStream::~TElPGPEnvelopingStream()
{
#ifdef SB_USE_CLASS_TELPGPSIGNATURE
	delete this->_Inst_Signatures;
	this->_Inst_Signatures = NULL;
#endif /* SB_USE_CLASS_TELPGPSIGNATURE */
}
#endif /* SB_USE_CLASS_TELPGPENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM

SB_INLINE void TElPGPUnenvelopingStream::DataAvailable()
{
	SBCheckError(TElPGPUnenvelopingStream_DataAvailable(_Handle));
}

bool TElPGPUnenvelopingStream::DataCompleted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPUnenvelopingStream_DataCompleted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE TClassHandle TElPGPUnenvelopingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPUnenvelopingStream_ClassType(&OutResult));
	return OutResult;
}

void TElPGPUnenvelopingStream::get_Filename(std::string &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.length();
	uint32_t _err = TElPGPUnenvelopingStream_get_Filename(_Handle, (char *)OutResult.data(), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnStringA(1999722763, 1, (char *)OutResult.data(), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int64_t TElPGPUnenvelopingStream::get_Timestamp()
{
	int64_t OutResult;
	SBCheckError(TElPGPUnenvelopingStream_get_Timestamp(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPUnenvelopingStream::set_Timestamp(int64_t Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_Timestamp(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
TElPGPHashingPool* TElPGPUnenvelopingStream::get_HashingPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUnenvelopingStream_get_HashingPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_HashingPool)
		this->_Inst_HashingPool = new TElPGPHashingPool(hOutResult, ohFalse);
	else
		this->_Inst_HashingPool->updateHandle(hOutResult);
	return this->_Inst_HashingPool;
}

SB_INLINE void TElPGPUnenvelopingStream::set_HashingPool(TElPGPHashingPool &Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_HashingPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPUnenvelopingStream::set_HashingPool(TElPGPHashingPool *Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_HashingPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
TElPGPHashingPool* TElPGPUnenvelopingStream::get_TextHashingPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUnenvelopingStream_get_TextHashingPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TextHashingPool)
		this->_Inst_TextHashingPool = new TElPGPHashingPool(hOutResult, ohFalse);
	else
		this->_Inst_TextHashingPool->updateHandle(hOutResult);
	return this->_Inst_TextHashingPool;
}

SB_INLINE void TElPGPUnenvelopingStream::set_TextHashingPool(TElPGPHashingPool &Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_TextHashingPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPUnenvelopingStream::set_TextHashingPool(TElPGPHashingPool *Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_TextHashingPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
TElPGPHashingPool* TElPGPUnenvelopingStream::get_BuggyTextHashingPool()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPUnenvelopingStream_get_BuggyTextHashingPool(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_BuggyTextHashingPool)
		this->_Inst_BuggyTextHashingPool = new TElPGPHashingPool(hOutResult, ohFalse);
	else
		this->_Inst_BuggyTextHashingPool->updateHandle(hOutResult);
	return this->_Inst_BuggyTextHashingPool;
}

SB_INLINE void TElPGPUnenvelopingStream::set_BuggyTextHashingPool(TElPGPHashingPool &Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_BuggyTextHashingPool(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPUnenvelopingStream::set_BuggyTextHashingPool(TElPGPHashingPool *Value)
{
	SBCheckError(TElPGPUnenvelopingStream_set_BuggyTextHashingPool(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */

SB_INLINE void TElPGPUnenvelopingStream::get_OnInfo(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPUnenvelopingStream_get_OnInfo(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPUnenvelopingStream::set_OnInfo(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPUnenvelopingStream_set_OnInfo(_Handle, pMethodValue, pDataValue));
}

void TElPGPUnenvelopingStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	this->_Inst_HashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	this->_Inst_TextHashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	this->_Inst_BuggyTextHashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
}

TElPGPUnenvelopingStream::TElPGPUnenvelopingStream(TElPGPUnenvelopingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPUnenvelopingStream::TElPGPUnenvelopingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPUnenvelopingStream_Create(&_Handle));
}

TElPGPUnenvelopingStream::~TElPGPUnenvelopingStream()
{
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	delete this->_Inst_HashingPool;
	this->_Inst_HashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	delete this->_Inst_TextHashingPool;
	this->_Inst_TextHashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
#ifdef SB_USE_CLASS_TELPGPHASHINGPOOL
	delete this->_Inst_BuggyTextHashingPool;
	this->_Inst_BuggyTextHashingPool = NULL;
#endif /* SB_USE_CLASS_TELPGPHASHINGPOOL */
}
#endif /* SB_USE_CLASS_TELPGPUNENVELOPINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENCRYPTINGSTREAM

SB_INLINE void TElPGPEncryptingStream::DataAvailable()
{
	SBCheckError(TElPGPEncryptingStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPEncryptingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPEncryptingStream_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPEncryptingStream::get_Keyring()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPEncryptingStream_get_Keyring(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keyring)
		this->_Inst_Keyring = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keyring->updateHandle(hOutResult);
	return this->_Inst_Keyring;
}

SB_INLINE void TElPGPEncryptingStream::set_Keyring(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPEncryptingStream_set_Keyring(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPEncryptingStream::set_Keyring(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPEncryptingStream_set_Keyring(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPEncryptingStream::get_Passphrases()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPEncryptingStream_get_Passphrases(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Passphrases)
		this->_Inst_Passphrases = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Passphrases->updateHandle(hOutResult);
	return this->_Inst_Passphrases;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

bool TElPGPEncryptingStream::get_IntegrityProtected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPEncryptingStream_get_IntegrityProtected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPEncryptingStream::set_IntegrityProtected(bool Value)
{
	SBCheckError(TElPGPEncryptingStream_set_IntegrityProtected(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElPGPEncryptingStream::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPEncryptingStream_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPEncryptingStream::set_Algorithm(int32_t Value)
{
	SBCheckError(TElPGPEncryptingStream_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPEncryptingStream::get_PassphraseAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPEncryptingStream_get_PassphraseAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPEncryptingStream::set_PassphraseAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPEncryptingStream_set_PassphraseAlgorithm(_Handle, Value));
}

TSBPGPProtectionType TElPGPEncryptingStream::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPEncryptingStream_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

SB_INLINE void TElPGPEncryptingStream::set_Protection(TSBPGPProtectionType Value)
{
	SBCheckError(TElPGPEncryptingStream_set_Protection(_Handle, (TSBPGPProtectionTypeRaw)Value));
}

void TElPGPEncryptingStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElPGPEncryptingStream::TElPGPEncryptingStream(TElPGPEncryptingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPEncryptingStream::TElPGPEncryptingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPEncryptingStream_Create(&_Handle));
}

TElPGPEncryptingStream::~TElPGPEncryptingStream()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keyring;
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Passphrases;
	this->_Inst_Passphrases = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELPGPENCRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECRYPTINGSTREAM

SB_INLINE void TElPGPDecryptingStream::DataAvailable()
{
	SBCheckError(TElPGPDecryptingStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPDecryptingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPDecryptingStream_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPDecryptingStream::get_Keyring()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPDecryptingStream_get_Keyring(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keyring)
		this->_Inst_Keyring = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keyring->updateHandle(hOutResult);
	return this->_Inst_Keyring;
}

SB_INLINE void TElPGPDecryptingStream::set_Keyring(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPDecryptingStream_set_Keyring(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPDecryptingStream::set_Keyring(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPDecryptingStream_set_Keyring(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

bool TElPGPDecryptingStream::get_IntegrityProtected()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPDecryptingStream_get_IntegrityProtected(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE int32_t TElPGPDecryptingStream::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPDecryptingStream_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

TSBPGPProtectionType TElPGPDecryptingStream::get_Protection()
{
	TSBPGPProtectionTypeRaw OutResultRaw = 0;
	SBCheckError(TElPGPDecryptingStream_get_Protection(_Handle, &OutResultRaw));
	return (TSBPGPProtectionType)OutResultRaw;
}

bool TElPGPDecryptingStream::get_SymmetricallyEncrypted()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElPGPDecryptingStream_get_SymmetricallyEncrypted(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElPGPDecryptingStream::get_OnPassphrase(TSBPGPPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDecryptingStream_get_OnPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDecryptingStream::set_OnPassphrase(TSBPGPPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDecryptingStream_set_OnPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPDecryptingStream::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDecryptingStream_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDecryptingStream::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDecryptingStream_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPDecryptingStream::get_OnKeyIDs(TSBPGPKeyIDsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDecryptingStream_get_OnKeyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDecryptingStream::set_OnKeyIDs(TSBPGPKeyIDsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDecryptingStream_set_OnKeyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPDecryptingStream::get_OnDecryptionStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDecryptingStream_get_OnDecryptionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDecryptingStream::set_OnDecryptionStart(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDecryptingStream_set_OnDecryptionStart(_Handle, pMethodValue, pDataValue));
}

void TElPGPDecryptingStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}

TElPGPDecryptingStream::TElPGPDecryptingStream(TElPGPDecryptingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPDecryptingStream::TElPGPDecryptingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPDecryptingStream_Create(&_Handle));
}

TElPGPDecryptingStream::~TElPGPDecryptingStream()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keyring;
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}
#endif /* SB_USE_CLASS_TELPGPDECRYPTINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM

SB_INLINE void TElPGPCompressingStream::DataAvailable()
{
	SBCheckError(TElPGPCompressingStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPCompressingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPCompressingStream_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPCompressingStream::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPCompressingStream_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCompressingStream::set_Algorithm(int32_t Value)
{
	SBCheckError(TElPGPCompressingStream_set_Algorithm(_Handle, Value));
}

SB_INLINE int32_t TElPGPCompressingStream::get_CompressionLevel()
{
	int32_t OutResult;
	SBCheckError(TElPGPCompressingStream_get_CompressionLevel(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPCompressingStream::set_CompressionLevel(int32_t Value)
{
	SBCheckError(TElPGPCompressingStream_set_CompressionLevel(_Handle, Value));
}

TElPGPCompressingStream::TElPGPCompressingStream(TElPGPCompressingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
}

TElPGPCompressingStream::TElPGPCompressingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPCompressingStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPCOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM

SB_INLINE void TElPGPDecompressingStream::DataAvailable()
{
	SBCheckError(TElPGPDecompressingStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPDecompressingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPDecompressingStream_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPDecompressingStream::get_Algorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPDecompressingStream_get_Algorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPDecompressingStream::get_OnDecompressionStart(TNotifyEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPDecompressingStream_get_OnDecompressionStart(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPDecompressingStream::set_OnDecompressionStart(TNotifyEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPDecompressingStream_set_OnDecompressionStart(_Handle, pMethodValue, pDataValue));
}

TElPGPDecompressingStream::TElPGPDecompressingStream(TElPGPDecompressingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
}

TElPGPDecompressingStream::TElPGPDecompressingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElPGPDecompressingStream_Create(&_Handle));
}

#endif /* SB_USE_CLASS_TELPGPDECOMPRESSINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPSIGNINGSTREAM

SB_INLINE void TElPGPSigningStream::DataAvailable()
{
	SBCheckError(TElPGPSigningStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPSigningStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPSigningStream_ClassType(&OutResult));
	return OutResult;
}

SB_INLINE int32_t TElPGPSigningStream::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElPGPSigningStream_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPSigningStream::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElPGPSigningStream_set_HashAlgorithm(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPSigningStream::get_Keyring()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSigningStream_get_Keyring(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keyring)
		this->_Inst_Keyring = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keyring->updateHandle(hOutResult);
	return this->_Inst_Keyring;
}

SB_INLINE void TElPGPSigningStream::set_Keyring(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPSigningStream_set_Keyring(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPSigningStream::set_Keyring(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPSigningStream_set_Keyring(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

#ifdef SB_USE_CLASS_TSTRINGLIST
TStringList* TElPGPSigningStream::get_Headers()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPSigningStream_get_Headers(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Headers)
		this->_Inst_Headers = new TStringList(hOutResult, ohFalse);
	else
		this->_Inst_Headers->updateHandle(hOutResult);
	return this->_Inst_Headers;
}
#endif /* SB_USE_CLASS_TSTRINGLIST */

SB_INLINE void TElPGPSigningStream::get_OnKeyPassphrase(TSBPGPKeyPassphraseEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPSigningStream_get_OnKeyPassphrase(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPSigningStream::set_OnKeyPassphrase(TSBPGPKeyPassphraseEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPSigningStream_set_OnKeyPassphrase(_Handle, pMethodValue, pDataValue));
}

void TElPGPSigningStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}

TElPGPSigningStream::TElPGPSigningStream(TElPGPSigningStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPSigningStream::TElPGPSigningStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPSigningStream_Create(&_Handle));
}

TElPGPSigningStream::~TElPGPSigningStream()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keyring;
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
#ifdef SB_USE_CLASS_TSTRINGLIST
	delete this->_Inst_Headers;
	this->_Inst_Headers = NULL;
#endif /* SB_USE_CLASS_TSTRINGLIST */
}
#endif /* SB_USE_CLASS_TELPGPSIGNINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM

SB_INLINE void TElPGPClearTextVerifyingStream::DataAvailable()
{
	SBCheckError(TElPGPClearTextVerifyingStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPClearTextVerifyingStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPClearTextVerifyingStream_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPKEYRING
TElPGPKeyring* TElPGPClearTextVerifyingStream::get_Keyring()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPClearTextVerifyingStream_get_Keyring(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Keyring)
		this->_Inst_Keyring = new TElPGPKeyring(hOutResult, ohFalse);
	else
		this->_Inst_Keyring->updateHandle(hOutResult);
	return this->_Inst_Keyring;
}

SB_INLINE void TElPGPClearTextVerifyingStream::set_Keyring(TElPGPKeyring &Value)
{
	SBCheckError(TElPGPClearTextVerifyingStream_set_Keyring(_Handle, Value.getHandle()));
}

SB_INLINE void TElPGPClearTextVerifyingStream::set_Keyring(TElPGPKeyring *Value)
{
	SBCheckError(TElPGPClearTextVerifyingStream_set_Keyring(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELPGPKEYRING */

SB_INLINE int32_t TElPGPClearTextVerifyingStream::get_InputEncoding()
{
	int32_t OutResult;
	SBCheckError(TElPGPClearTextVerifyingStream_get_InputEncoding(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElPGPClearTextVerifyingStream::set_InputEncoding(int32_t Value)
{
	SBCheckError(TElPGPClearTextVerifyingStream_set_InputEncoding(_Handle, Value));
}

SB_INLINE void TElPGPClearTextVerifyingStream::get_OnKeyIDs(TSBPGPKeyIDsEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPClearTextVerifyingStream_get_OnKeyIDs(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPClearTextVerifyingStream::set_OnKeyIDs(TSBPGPKeyIDsEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPClearTextVerifyingStream_set_OnKeyIDs(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElPGPClearTextVerifyingStream::get_OnSignatures(TSBPGPSignaturesEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElPGPClearTextVerifyingStream_get_OnSignatures(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElPGPClearTextVerifyingStream::set_OnSignatures(TSBPGPSignaturesEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElPGPClearTextVerifyingStream_set_OnSignatures(_Handle, pMethodValue, pDataValue));
}

void TElPGPClearTextVerifyingStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}

TElPGPClearTextVerifyingStream::TElPGPClearTextVerifyingStream(TElPGPClearTextVerifyingStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPClearTextVerifyingStream::TElPGPClearTextVerifyingStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPClearTextVerifyingStream_Create(&_Handle));
}

TElPGPClearTextVerifyingStream::~TElPGPClearTextVerifyingStream()
{
#ifdef SB_USE_CLASS_TELPGPKEYRING
	delete this->_Inst_Keyring;
	this->_Inst_Keyring = NULL;
#endif /* SB_USE_CLASS_TELPGPKEYRING */
}
#endif /* SB_USE_CLASS_TELPGPCLEARTEXTVERIFYINGSTREAM */

#ifdef SB_USE_CLASS_TELPGPENTITYSTREAM

SB_INLINE void TElPGPEntityStream::DataAvailable()
{
	SBCheckError(TElPGPEntityStream_DataAvailable(_Handle));
}

SB_INLINE TClassHandle TElPGPEntityStream::ClassType()
{
	TClassHandle OutResult;
	SBCheckError(TElPGPEntityStream_ClassType(&OutResult));
	return OutResult;
}

#ifdef SB_USE_CLASS_TELPGPENTITY
TElPGPEntity* TElPGPEntityStream::get_Entity()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElPGPEntityStream_get_Entity(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Entity)
		this->_Inst_Entity = new TElPGPEntity(hOutResult, ohFalse);
	else
		this->_Inst_Entity->updateHandle(hOutResult);
	return this->_Inst_Entity;
}
#endif /* SB_USE_CLASS_TELPGPENTITY */

void TElPGPEntityStream::initInstances()
{
#ifdef SB_USE_CLASS_TELPGPENTITY
	this->_Inst_Entity = NULL;
#endif /* SB_USE_CLASS_TELPGPENTITY */
}

TElPGPEntityStream::TElPGPEntityStream(TElPGPEntityStreamHandle handle, TElOwnHandle ownHandle) : TElPGPStream(handle, ownHandle)
{
	initInstances();
}

TElPGPEntityStream::TElPGPEntityStream() : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPEntityStream_Create(&_Handle));
}

TElPGPEntityStream::TElPGPEntityStream(uint8_t PktType) : TElPGPStream(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElPGPEntityStream_Create_1(PktType, &_Handle));
}

TElPGPEntityStream::~TElPGPEntityStream()
{
#ifdef SB_USE_CLASS_TELPGPENTITY
	delete this->_Inst_Entity;
	this->_Inst_Entity = NULL;
#endif /* SB_USE_CLASS_TELPGPENTITY */
}
#endif /* SB_USE_CLASS_TELPGPENTITYSTREAM */

};	/* namespace SecureBlackbox */

