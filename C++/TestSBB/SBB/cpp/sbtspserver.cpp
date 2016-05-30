#include "sbtspserver.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELSERVERTSPINFO

void TElServerTSPInfo::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElServerTSPInfo_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1902527279, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE int32_t TElServerTSPInfo::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElServerTSPInfo_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int64_t TElServerTSPInfo::get_Time()
{
	int64_t OutResult;
	SBCheckError(TElServerTSPInfo_get_Time(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElServerTSPInfo::set_Time(int64_t Value)
{
	SBCheckError(TElServerTSPInfo_set_Time(_Handle, Value));
}

SB_INLINE int32_t TElServerTSPInfo::get_AccuracySec()
{
	int32_t OutResult;
	SBCheckError(TElServerTSPInfo_get_AccuracySec(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElServerTSPInfo::set_AccuracySec(int32_t Value)
{
	SBCheckError(TElServerTSPInfo_set_AccuracySec(_Handle, Value));
}

SB_INLINE int32_t TElServerTSPInfo::get_AccuracyMilli()
{
	int32_t OutResult;
	SBCheckError(TElServerTSPInfo_get_AccuracyMilli(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElServerTSPInfo::set_AccuracyMilli(int32_t Value)
{
	SBCheckError(TElServerTSPInfo_set_AccuracyMilli(_Handle, Value));
}

SB_INLINE int32_t TElServerTSPInfo::get_AccuracyMicro()
{
	int32_t OutResult;
	SBCheckError(TElServerTSPInfo_get_AccuracyMicro(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElServerTSPInfo::set_AccuracyMicro(int32_t Value)
{
	SBCheckError(TElServerTSPInfo_set_AccuracyMicro(_Handle, Value));
}

#ifdef SB_USE_CLASS_TELGENERALNAME
TElGeneralName* TElServerTSPInfo::get_TSAName()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElServerTSPInfo_get_TSAName(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSAName)
		this->_Inst_TSAName = new TElGeneralName(hOutResult, ohFalse);
	else
		this->_Inst_TSAName->updateHandle(hOutResult);
	return this->_Inst_TSAName;
}
#endif /* SB_USE_CLASS_TELGENERALNAME */

void TElServerTSPInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	this->_Inst_TSAName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}

TElServerTSPInfo::TElServerTSPInfo(TElServerTSPInfoHandle handle, TElOwnHandle ownHandle) : TElTSPInfo(handle, ownHandle)
{
	initInstances();
}

TElServerTSPInfo::TElServerTSPInfo() : TElTSPInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElServerTSPInfo_Create(&_Handle));
}

TElServerTSPInfo::~TElServerTSPInfo()
{
#ifdef SB_USE_CLASS_TELGENERALNAME
	delete this->_Inst_TSAName;
	this->_Inst_TSAName = NULL;
#endif /* SB_USE_CLASS_TELGENERALNAME */
}
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPSERVER

#ifdef SB_USE_CLASS_TELSERVERTSPINFO
TElServerTSPInfo* TElCustomTSPServer::get_TSPInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomTSPServer_get_TSPInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPInfo)
		this->_Inst_TSPInfo = new TElServerTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_TSPInfo->updateHandle(hOutResult);
	return this->_Inst_TSPInfo;
}
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */

void TElCustomTSPServer::get_DefaultPolicy(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomTSPServer_get_DefaultPolicy(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1225166978, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomTSPServer::set_DefaultPolicy(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomTSPServer_set_DefaultPolicy(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

bool TElCustomTSPServer::get_IsAuthenticode()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomTSPServer_get_IsAuthenticode(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCustomTSPServer::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomTSPServer_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}

SB_INLINE void TElCustomTSPServer::set_Certificates(TElCustomCertStorage &Value)
{
	SBCheckError(TElCustomTSPServer_set_Certificates(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomTSPServer::set_Certificates(TElCustomCertStorage *Value)
{
	SBCheckError(TElCustomTSPServer_set_Certificates(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElCustomTSPServer::initInstances()
{
#ifdef SB_USE_CLASS_TELSERVERTSPINFO
	this->_Inst_TSPInfo = NULL;
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElCustomTSPServer::TElCustomTSPServer(TElCustomTSPServerHandle handle, TElOwnHandle ownHandle) : TElTSPClass(handle, ownHandle)
{
	initInstances();
}

TElCustomTSPServer::TElCustomTSPServer(TComponent &Owner) : TElTSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomTSPServer_Create(Owner.getHandle(), &_Handle));
}

TElCustomTSPServer::TElCustomTSPServer(TComponent *Owner) : TElTSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomTSPServer_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomTSPServer::~TElCustomTSPServer()
{
#ifdef SB_USE_CLASS_TELSERVERTSPINFO
	delete this->_Inst_TSPInfo;
	this->_Inst_TSPInfo = NULL;
#endif /* SB_USE_CLASS_TELSERVERTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPSERVER */

#ifdef SB_USE_CLASS_TELFILETSPSERVER

#ifdef SB_USE_CLASS_TSTREAM
bool TElFileTSPServer::SaveReplyToStream(TSBPKIStatus ServerResult, int32_t FailureInfo, TStream &Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileTSPServer_SaveReplyToStream(_Handle, (TSBPKIStatusRaw)ServerResult, FailureInfo, Stream.getHandle(), &OutResultRaw));
	return (OutResultRaw != 0);
}

bool TElFileTSPServer::SaveReplyToStream(TSBPKIStatus ServerResult, int32_t FailureInfo, TStream *Stream)
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileTSPServer_SaveReplyToStream(_Handle, (TSBPKIStatusRaw)ServerResult, FailureInfo, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResultRaw));
	return (OutResultRaw != 0);
}
#endif /* SB_USE_CLASS_TSTREAM */

#ifdef SB_USE_CLASS_TSTREAM
SB_INLINE int32_t TElFileTSPServer::LoadRequestFromStream(TStream &Stream)
{
	int32_t OutResult;
	SBCheckError(TElFileTSPServer_LoadRequestFromStream(_Handle, Stream.getHandle(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElFileTSPServer::LoadRequestFromStream(TStream *Stream)
{
	int32_t OutResult;
	SBCheckError(TElFileTSPServer_LoadRequestFromStream(_Handle, (Stream != NULL) ? Stream->getHandle() : SB_NULL_HANDLE, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TSTREAM */

TElFileTSPServer::TElFileTSPServer(TElFileTSPServerHandle handle, TElOwnHandle ownHandle) : TElCustomTSPServer(handle, ownHandle)
{
}

TElFileTSPServer::TElFileTSPServer(TComponent &Owner) : TElCustomTSPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileTSPServer_Create(Owner.getHandle(), &_Handle));
}

TElFileTSPServer::TElFileTSPServer(TComponent *Owner) : TElCustomTSPServer(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileTSPServer_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILETSPSERVER */

};	/* namespace SecureBlackbox */

