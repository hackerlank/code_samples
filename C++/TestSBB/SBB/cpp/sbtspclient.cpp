#include "sbtspclient.h"

namespace SecureBlackbox {

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO

SB_INLINE int32_t TElClientTSPInfo::ParseCMS(const std::vector<uint8_t> &CMSData)
{
	int32_t OutResult;
	SBCheckError(TElClientTSPInfo_ParseCMS(_Handle, SB_STD_VECTOR_FRONT_ADR(CMSData), (int32_t)CMSData.size(), &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElClientTSPInfo::ParseCMS(const std::vector<uint8_t> &CMSData, bool NoOuterInfo)
{
	int32_t OutResult;
	SBCheckError(TElClientTSPInfo_ParseCMS_1(_Handle, SB_STD_VECTOR_FRONT_ADR(CMSData), (int32_t)CMSData.size(), (int8_t)NoOuterInfo, &OutResult));
	return OutResult;
}

SB_INLINE void TElClientTSPInfo::Reset()
{
	SBCheckError(TElClientTSPInfo_Reset(_Handle));
}

#ifdef SB_USE_CLASS_TELX509CERTIFICATE
SB_INLINE TElX509CertificateHandle TElClientTSPInfo::GetSignerCertificate()
{
	TElX509CertificateHandle OutResult;
	SBCheckError(TElClientTSPInfo_GetSignerCertificate(_Handle, &OutResult));
	return OutResult;
}
#endif /* SB_USE_CLASS_TELX509CERTIFICATE */

void TElClientTSPInfo::get_Nonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElClientTSPInfo_get_Nonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1541056161, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElClientTSPInfo::set_Nonce(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElClientTSPInfo_set_Nonce(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElClientTSPInfo::get_Certificates()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElClientTSPInfo_get_Certificates(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_Certificates)
		this->_Inst_Certificates = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_Certificates->updateHandle(hOutResult);
	return this->_Inst_Certificates;
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

void TElClientTSPInfo::get_MessageImprint(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElClientTSPInfo_get_MessageImprint(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1659237072, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElClientTSPInfo::get_ResponseNonce(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElClientTSPInfo_get_ResponseNonce(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-439516650, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElClientTSPInfo::get_CMS(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElClientTSPInfo_get_CMS(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1098527977, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

bool TElClientTSPInfo::get_IgnoreBadSignature()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElClientTSPInfo_get_IgnoreBadSignature(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElClientTSPInfo::set_IgnoreBadSignature(bool Value)
{
	SBCheckError(TElClientTSPInfo_set_IgnoreBadSignature(_Handle, (int8_t)Value));
}

SB_INLINE int32_t TElClientTSPInfo::get_LastValidationResult()
{
	int32_t OutResult;
	SBCheckError(TElClientTSPInfo_get_LastValidationResult(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE int32_t TElClientTSPInfo::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElClientTSPInfo_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

void TElClientTSPInfo::get_HashedData(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElClientTSPInfo_get_HashedData(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(-1728484147, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

void TElClientTSPInfo::initInstances()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElClientTSPInfo::TElClientTSPInfo(TElClientTSPInfoHandle handle, TElOwnHandle ownHandle) : TElTSPInfo(handle, ownHandle)
{
	initInstances();
}

TElClientTSPInfo::TElClientTSPInfo() : TElTSPInfo(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElClientTSPInfo_Create(&_Handle));
}

TElClientTSPInfo::~TElClientTSPInfo()
{
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_Certificates;
	this->_Inst_Certificates = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

#ifdef SB_USE_CLASS_TELCUSTOMTSPCLIENT

int32_t TElCustomTSPClient::Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS)
{
	int32_t OutResult;
	TSBPKIStatusRaw ServerResultRaw = (TSBPKIStatusRaw)ServerResult;
	int32_t szReplyCMS = (int32_t)ReplyCMS.size();
	uint32_t _err = TElCustomTSPClient_Timestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), &ServerResultRaw, &FailureInfo, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ReplyCMS.resize(szReplyCMS);
		SBCheckError(SBGetLastReturnBuffer(629492182, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS));
	}
	else
		SBCheckError(_err);

	ServerResult = (TSBPKIStatus)ServerResultRaw;
	ReplyCMS.resize(szReplyCMS);
	return OutResult;
}

#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
TElClientTSPInfo* TElCustomTSPClient::get_TSPInfo()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomTSPClient_get_TSPInfo(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_TSPInfo)
		this->_Inst_TSPInfo = new TElClientTSPInfo(hOutResult, ohFalse);
	else
		this->_Inst_TSPInfo->updateHandle(hOutResult);
	return this->_Inst_TSPInfo;
}
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */

void TElCustomTSPClient::get_ReqPolicy(std::vector<uint8_t> &OutResult)
{
	int32_t szOutResult = (int32_t)OutResult.size();
	uint32_t _err = TElCustomTSPClient_get_ReqPolicy(_Handle, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		OutResult.resize(szOutResult);
		SBCheckError(SBGetLastReturnBuffer(259378677, 1, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(OutResult), &szOutResult));
	}
	else
		SBCheckError(_err);

	OutResult.resize(szOutResult);
}

SB_INLINE void TElCustomTSPClient::set_ReqPolicy(const std::vector<uint8_t> &Value)
{
	SBCheckError(TElCustomTSPClient_set_ReqPolicy(_Handle, SB_STD_VECTOR_FRONT_ADR(Value), (int32_t)Value.size()));
}

SB_INLINE int32_t TElCustomTSPClient::get_HashAlgorithm()
{
	int32_t OutResult;
	SBCheckError(TElCustomTSPClient_get_HashAlgorithm(_Handle, &OutResult));
	return OutResult;
}

SB_INLINE void TElCustomTSPClient::set_HashAlgorithm(int32_t Value)
{
	SBCheckError(TElCustomTSPClient_set_HashAlgorithm(_Handle, Value));
}

bool TElCustomTSPClient::get_IncludeCertificates()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElCustomTSPClient_get_IncludeCertificates(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElCustomTSPClient::set_IncludeCertificates(bool Value)
{
	SBCheckError(TElCustomTSPClient_set_IncludeCertificates(_Handle, (int8_t)Value));
}

TSBTSPOptions TElCustomTSPClient::get_Options()
{
	TSBTSPOptionsRaw OutResultRaw = 0;
	SBCheckError(TElCustomTSPClient_get_Options(_Handle, &OutResultRaw));
	return (TSBTSPOptions)OutResultRaw;
}

SB_INLINE void TElCustomTSPClient::set_Options(TSBTSPOptions Value)
{
	SBCheckError(TElCustomTSPClient_set_Options(_Handle, (TSBTSPOptionsRaw)Value));
}

TSBTSPRequestFormat TElCustomTSPClient::get_RequestFormat()
{
	TSBTSPRequestFormatRaw OutResultRaw = 0;
	SBCheckError(TElCustomTSPClient_get_RequestFormat(_Handle, &OutResultRaw));
	return (TSBTSPRequestFormat)OutResultRaw;
}

SB_INLINE void TElCustomTSPClient::set_RequestFormat(TSBTSPRequestFormat Value)
{
	SBCheckError(TElCustomTSPClient_set_RequestFormat(_Handle, (TSBTSPRequestFormatRaw)Value));
}

#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
TElCustomCertStorage* TElCustomTSPClient::get_CertStorage()
{
	TElClassHandle hOutResult = SB_NULL_HANDLE;
	SBCheckError(TElCustomTSPClient_get_CertStorage(_Handle, &hOutResult));
	if (SB_NULL_HANDLE == hOutResult)
		return NULL;
	if (NULL == this->_Inst_CertStorage)
		this->_Inst_CertStorage = new TElCustomCertStorage(hOutResult, ohFalse);
	else
		this->_Inst_CertStorage->updateHandle(hOutResult);
	return this->_Inst_CertStorage;
}

SB_INLINE void TElCustomTSPClient::set_CertStorage(TElCustomCertStorage &Value)
{
	SBCheckError(TElCustomTSPClient_set_CertStorage(_Handle, Value.getHandle()));
}

SB_INLINE void TElCustomTSPClient::set_CertStorage(TElCustomCertStorage *Value)
{
	SBCheckError(TElCustomTSPClient_set_CertStorage(_Handle, (Value != NULL) ? Value->getHandle() : SB_NULL_HANDLE));
}
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */

SB_INLINE void TElCustomTSPClient::get_OnCertificateValidate(TSBCertificateValidationEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomTSPClient_get_OnCertificateValidate(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomTSPClient::set_OnCertificateValidate(TSBCertificateValidationEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomTSPClient_set_OnCertificateValidate(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomTSPClient::get_OnBeforeSign(TSBTSPBeforeSignEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomTSPClient_get_OnBeforeSign(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomTSPClient::set_OnBeforeSign(TSBTSPBeforeSignEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomTSPClient_set_OnBeforeSign(_Handle, pMethodValue, pDataValue));
}

SB_INLINE void TElCustomTSPClient::get_OnTSPError(TSBTSPErrorEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElCustomTSPClient_get_OnTSPError(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElCustomTSPClient::set_OnTSPError(TSBTSPErrorEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElCustomTSPClient_set_OnTSPError(_Handle, pMethodValue, pDataValue));
}

void TElCustomTSPClient::initInstances()
{
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	this->_Inst_TSPInfo = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}

TElCustomTSPClient::TElCustomTSPClient(TElCustomTSPClientHandle handle, TElOwnHandle ownHandle) : TElTSPClass(handle, ownHandle)
{
	initInstances();
}

TElCustomTSPClient::TElCustomTSPClient(TComponent &Owner) : TElTSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomTSPClient_Create(Owner.getHandle(), &_Handle));
}

TElCustomTSPClient::TElCustomTSPClient(TComponent *Owner) : TElTSPClass(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	initInstances();
	SBCheckError(TElCustomTSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

TElCustomTSPClient::~TElCustomTSPClient()
{
#ifdef SB_USE_CLASS_TELCLIENTTSPINFO
	delete this->_Inst_TSPInfo;
	this->_Inst_TSPInfo = NULL;
#endif /* SB_USE_CLASS_TELCLIENTTSPINFO */
#ifdef SB_USE_CLASS_TELCUSTOMCERTSTORAGE
	delete this->_Inst_CertStorage;
	this->_Inst_CertStorage = NULL;
#endif /* SB_USE_CLASS_TELCUSTOMCERTSTORAGE */
}
#endif /* SB_USE_CLASS_TELCUSTOMTSPCLIENT */

#ifdef SB_USE_CLASS_TELFILETSPCLIENT

int32_t TElFileTSPClient::Timestamp(const std::vector<uint8_t> &HashedData, TSBPKIStatus &ServerResult, int32_t &FailureInfo, std::vector<uint8_t> &ReplyCMS)
{
	int32_t OutResult;
	TSBPKIStatusRaw ServerResultRaw = (TSBPKIStatusRaw)ServerResult;
	int32_t szReplyCMS = (int32_t)ReplyCMS.size();
	uint32_t _err = TElFileTSPClient_Timestamp(_Handle, SB_STD_VECTOR_FRONT_ADR(HashedData), (int32_t)HashedData.size(), &ServerResultRaw, &FailureInfo, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS, &OutResult);
	if (SB_ERROR_INSUFFICIENT_BUFFER_SIZE == _err)
	{
		ReplyCMS.resize(szReplyCMS);
		SBCheckError(SBGetLastReturnBuffer(-770732630, 4, (uint8_t *)SB_STD_VECTOR_FRONT_ADR(ReplyCMS), &szReplyCMS));
	}
	else
		SBCheckError(_err);

	ServerResult = (TSBPKIStatus)ServerResultRaw;
	ReplyCMS.resize(szReplyCMS);
	return OutResult;
}

bool TElFileTSPClient::get_HashOnlyNeeded()
{
	int8_t OutResultRaw = 0;
	SBCheckError(TElFileTSPClient_get_HashOnlyNeeded(_Handle, &OutResultRaw));
	return (OutResultRaw != 0);
}

SB_INLINE void TElFileTSPClient::set_HashOnlyNeeded(bool Value)
{
	SBCheckError(TElFileTSPClient_set_HashOnlyNeeded(_Handle, (int8_t)Value));
}

SB_INLINE void TElFileTSPClient::get_OnTimestampNeeded(TSBTimestampNeededEvent &pMethodOutResult, void * &pDataOutResult)
{
	SBCheckError(TElFileTSPClient_get_OnTimestampNeeded(_Handle, &pMethodOutResult, &pDataOutResult));
}

SB_INLINE void TElFileTSPClient::set_OnTimestampNeeded(TSBTimestampNeededEvent pMethodValue, void * pDataValue)
{
	SBCheckError(TElFileTSPClient_set_OnTimestampNeeded(_Handle, pMethodValue, pDataValue));
}

TElFileTSPClient::TElFileTSPClient(TElFileTSPClientHandle handle, TElOwnHandle ownHandle) : TElCustomTSPClient(handle, ownHandle)
{
}

TElFileTSPClient::TElFileTSPClient(TComponent &Owner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileTSPClient_Create(Owner.getHandle(), &_Handle));
}

TElFileTSPClient::TElFileTSPClient(TComponent *Owner) : TElCustomTSPClient(SB_NULL_HANDLE, SB_OWN_HANDLE)
{
	SBCheckError(TElFileTSPClient_Create((Owner != NULL) ? Owner->getHandle() : SB_NULL_HANDLE, &_Handle));
}

#endif /* SB_USE_CLASS_TELFILETSPCLIENT */

};	/* namespace SecureBlackbox */

